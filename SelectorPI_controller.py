######################################## UIT IMPLEMENTATION ###############################################################
# CLASS TO DEFINE THE PI CONTROLLER BLOCK
import pandas as pd
from datetime import datetime, timedelta
import logging
import pandas as pd
from datetime import datetime, timedelta
import os
import sys
class PIController_uit:
    '''PI Controller with saturation and anti wind-up.
    Attributes:
        name (str): Name of the controller.
        kp (float): Proportional gain.
        ki (float): Integral gain.
        current_timestamp (str): Timestamp in "YYYY-MM-DD" format when the controller is initialized.
        saturation_low (float, optional): Lower saturation limit. Defaults to None.
        saturation_high (float, optional): Upper saturation limit. Defaults to None.
        saturate_integral (bool, optional): Whether to apply saturation to the integral term. Defaults to True.
        log_df (pd.DataFrame, optional): DataFrame to log controller data. Defaults to an empty DataFrame with specified columns.
    '''

    def __init__(self, name, kp, ki, saturation_low=None, saturation_high=None, saturate_integral=True):
        '''Initialize the PIController with given parameters.'''
        self.name = name
        self.timestamp: str = field(default_factory=lambda: datetime.now().strftime("%Y-%m-%d"))
        self.kp = kp
        self.ki = ki
        self.saturation_low = saturation_low
        self.saturation_high = saturation_high
        self.saturate_integral = saturate_integral
        self.log_df = pd.DataFrame(columns=['timestamp', 'error', 'integral','integral_past','u_p','u_i','u_i_past','control_signal','saturation','selection'])

    # COMPUTE CONTROL SIGNAL FROM ERROR AND PAST INTEGRAL TERM
    def compute(self, error, dt, selection):
        """Compute the control signal based on the error and past integral term.
        Args:
            error (float): The current error value.
            dt (float): The time interval since the last control computation.
            selection (str): The current selection state (just for logging purposes).
        Returns:
            float: The computed control signal."""
        integral_past = self.log_df['integral'].iloc[-1] if not self.log_df.empty else 0 # Extract past integral term from last row of log_df. Default starting value is 0.
        integral = integral_past + error * dt # Update integral term

        # Apply saturation to the integral term if specified
        if self.saturate_integral:
            if self.saturation_low is not None and integral < self.saturation_low: 
                integral = self.saturation_low
            elif self.saturation_high is not None and integral > self.saturation_high:
                integral = self.saturation_high

        # Calculate the control action
        u_p = self.kp * error # Proportional action
        u_i_past = self.ki * integral_past # Just for checking purposes. Must always be 'control_signal - u_p' at the previous iteration
        u_i = self.ki * integral # Integral action
        control_signal = u_p + u_i # Total control signal. Comment the "+ u_i" part for a P controller!

        # Apply saturation to the control signal
        if self.saturation_low is not None and control_signal < self.saturation_low:
            control_signal = self.saturation_low
        elif self.saturation_high is not None and control_signal > self.saturation_high:
            control_signal = self.saturation_high

        # If 'control_signal' is in saturation, apply anti-windup
        if control_signal <= self.saturation_low:
            saturation = 'Low'
            integral = (control_signal - u_p) / self.ki
        elif control_signal >= self.saturation_high:
            saturation = 'High'
            integral = (control_signal - u_p) / self.ki
        else:
            saturation = 'No'
        # Log the quantities of interest to the dataframe 'log_df'
        self.log_df = self.log_df.append({'timestamp': self.timestamp, 'error': error, 'integral': integral,'integral_past': integral_past,'u_p':u_p,'u_i':u_i,'u_i_past':u_i_past,
                                          'control_signal':control_signal,'saturation':saturation,'selection': selection}, ignore_index=True)
        return control_signal

    def load_state(self, log_date, filename=None):
        """Load the integral state from a file.
        Args:
            log_date (str): The date string in "YYYY-MM-DD" format to identify the log file.
            filename (str, optional): The filename to load the state from. If None, a default filename is used. Defaults to None.
        It does not return anything, but updates the log_df attribute of the controller.
        Must be called before compute() to ensure the correct past integral state is used.
            """
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"

        # Load the log_df DataFrame from a file
        try:
            self.log_df = pd.read_csv(filename)
            print(f"Loaded integral state from {filename}")
            
        except FileNotFoundError:
            previous_date = (datetime.now() - timedelta(days=1)).strftime("%Y-%m-%d")
            file_path_previous = f"{self.name}_{previous_date}_state.csv"
            try:
                self.log_df = pd.read_csv(file_path_previous).iloc[[-1]]
                print(f"Loaded integral state for {self.name} from {file_path_previous}")
                
            except FileNotFoundError:
                print(f"No integral state file found for {self.name} from the current or previous day. Initializing from default state.")
                
    def reset_state(self, desired_value):
        """Reset the previous integral state to a desired value i.e. override capability of the controller.
        Args:
            desired_value (float): The desired value to reset the integral term to.
            It does not return anything, but appends a new row to the log_df attribute of the controller.
            Must be called after load_state() and before compute() to ensure the correct integral state is used.
        """
        new_row = {'timestamp': self.timestamp, 'error': '-', 'integral': desired_value,'control_signal':'-','selection': str('reselected')}
        self.log_df = self.log_df.append(new_row, ignore_index=True)
        
    def save_state(self, log_date, filename=None):
        """Save the current state to a file.
        Args:
            log_date (str): The date string in "YYYY-MM-DD" format to identify the log file.
            filename (str, optional): The filename to save the state to. If None, a default filename is used. Defaults to None.
        Saves the log_df DataFrame to a CSV file.
        It does not return anything, but writes the log_df to a file.
        Must be called after compute() to ensure the current state is saved.
        """
        # If filename is not provided, use a default filename based on the controller's name
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"
        
        # Save the log_df DataFrame to a file
        self.log_df.to_csv(filename, index=False)

# CLASS TO DEFINE HYSTERESIS COMPARATOR
class HysteresisComparator_uit:
    """A hysteresis comparator to manage state transitions based on input values and defined thresholds.
    To compare a measurement point with its safety threshold to trigger control switches
    Boolean state depending on the measurement value, if laying below threshold low (False) or above threshold high (True)
    If the measurement point lays within the two thresholds, this function doesn't change its state
    Attributes:
        threshold_low (float): The lower threshold for state transition.
        threshold_high (float): The upper threshold for state transition.
        state (bool): The current state of the comparator. Defaults to False.
        """
    
    def __init__(self, threshold_low, threshold_high):
        self.threshold_low = threshold_low
        self.threshold_high = threshold_high
        self.state = False  # Initial state

    def update(self, value):
        """
        Update the comparator state based on the input value.
        Args:
            value (float): The input value to compare against the thresholds.
        If the value is below the low threshold, the state is set to False.
        If the value is above the high threshold, the state is set to True.
        If the value is between the thresholds, the state remains unchanged.
        """
        if value < self.threshold_low:
            self.state = False
        elif value > self.threshold_high:
            self.state = True

        return self.state

    def get_state_as_string(self):
        """
        Return the current state as a string.
        """
        return str(self.state)
# ------------------------------------------------------------------------------------------------------------------- #

######################################## RPI IMPLEMENTATION ###############################################################
# CLASS TO DEFINE THE PI CONTROLLER BLOCK
from dataclasses import dataclass, field
import pandas as pd
from datetime import datetime, timedelta
import logging
import pandas as pd
from datetime import datetime, timedelta
import os
import sys
from general_utils.save_df import save_df_with_check

@dataclass
class PIController:
    '''PI Controller with saturation and anti wind-up.
    Attributes:
        name (str): Name of the controller.
        kp (float): Proportional gain.
        ki (float): Integral gain.
        current_timestamp (str): Timestamp in "YYYY-MM-DD" format when the controller is initialized.
        saturation_low (float, optional): Lower saturation limit. Defaults to None.
        saturation_high (float, optional): Upper saturation limit. Defaults to None.
        saturate_integral (bool, optional): Whether to apply saturation to the integral term. Defaults to True.
        logger (logging.Logger, optional): Logger for the controller. Defaults to a new logger.
        log_df (pd.DataFrame, optional): DataFrame to log controller data. Defaults to an empty DataFrame with specified columns.
    '''
    name: str
    kp: float
    ki: float
    current_timestamp: str = field(default_factory=lambda: datetime.now().strftime("%Y-%m-%d"))
    saturation_low: float = None
    saturation_high: float = None
    saturate_integral: bool = True
    logger: logging.Logger = field(default_factory=logging.getLogger)
    log_df: pd.DataFrame = field(default_factory=lambda: pd.DataFrame(columns=[
        'Timestamp', 'error', 'integral', 'integral_past', 'u_p', 'u_i', 'u_i_past', 
        'control_signal', 'saturation', 'selection'
    ]))

    def __post_init__(self):
        """Initialize the logger."""
        self.logger.info(f"Initialized PIController: {self.name}")

    def compute(self, error: float, dt: float, selection: str) -> float:
        """Compute the control signal based on the error and past integral term.
        Args:
            error (float): The current error value.
            dt (float): The time interval since the last control computation.
            selection (str): The current selection state (just for logging purposes).
        Returns:
            float: The computed control signal."""
        integral_past = self.log_df['integral'].iloc[-1] if not self.log_df.empty else 0 # Extract past integral term from last row of log_df. Default starting value is 0.
        integral = integral_past + error * dt # Update integral term

        # Apply saturation to the integral term if specified
        if self.saturate_integral:
            if self.saturation_low is not None and integral < self.saturation_low: 
                integral = self.saturation_low
            elif self.saturation_high is not None and integral > self.saturation_high:
                integral = self.saturation_high

        # Calculate the control action
        u_p = self.kp * error # Proportional action
        u_i_past = self.ki * integral_past # Just for checking purposes. Must always be 'control_signal - u_p' at the previous iteration
        u_i = self.ki * integral # Integral action
        control_signal = u_p + u_i # Total control signal. Comment the "+ u_i" part for a P controller!

        # Apply saturation to the control signal
        if self.saturation_low is not None and control_signal < self.saturation_low:
            control_signal = self.saturation_low
        elif self.saturation_high is not None and control_signal > self.saturation_high:
            control_signal = self.saturation_high

        # If 'control_signal' is in saturation, apply anti-windup
        if control_signal <= self.saturation_low:
            saturation = 'Low'
            integral = (control_signal - u_p) / self.ki
        elif control_signal >= self.saturation_high:
            saturation = 'High'
            integral = (control_signal - u_p) / self.ki
        else:
            saturation = 'No'

        # Log the quantities of interest to the dataframe 'log_df'
        self.log_df = self.log_df.append({
            'Timestamp': self.current_timestamp, 'error': error, 'integral': integral, 'integral_past': integral_past,
            'u_p': u_p, 'u_i': u_i, 'u_i_past': u_i_past, 'control_signal': control_signal,
            'saturation': saturation, 'selection': selection
        }, ignore_index=True)
        # Log the computed control signal and saturation status
        self.logger.info(f"Computed control signal of {self.name}: {control_signal}, saturation: {saturation}")
        return control_signal

    def load_state(self, log_date: str, filename: str = None):
        """Load the integral state from a file.
        Args:
            log_date (str): The date string in "YYYY-MM-DD" format to identify the log file.
            filename (str, optional): The filename to load the state from. If None, a default filename is used. Defaults to None.
        It does not return anything, but updates the log_df attribute of the controller.
        Must be called before compute() to ensure the correct past integral state is used.
            """
        # If filename is not provided, use a default filename based on the controller's name
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"

        # Load the log_df DataFrame from a file
        try:
            self.log_df = pd.read_csv(filename)
            self.logger.info(f"Loaded integral state from {filename}")
        except FileNotFoundError:
            previous_date = (datetime.strptime(log_date, "%Y-%m-%d") - timedelta(days=1)).strftime("%Y-%m-%d")
            file_path_previous = f"{self.name}_{previous_date}_state.csv"
            try:
                self.log_df = pd.read_csv(file_path_previous).iloc[[-1]]
                self.logger.info(f"Loaded integral state for {self.name} from {file_path_previous}")
            except FileNotFoundError:
                self.logger.warning(f"No integral state file found for {self.name}. Initializing from default state.")

    def reset_state(self, desired_value: float):
        """Reset the previous integral state to a desired value i.e. override capability of the controller.
        Args:
            desired_value (float): The desired value to reset the integral term to.
            It does not return anything, but appends a new row to the log_df attribute of the controller.
            Must be called after load_state() and before compute() to ensure the correct integral state is used.
        """
        new_row = {
            'Timestamp': self.current_timestamp, 'error': '-', 'integral': desired_value,
            'control_signal': '-', 'selection': 'reselected'
        }
        self.log_df = self.log_df.append(new_row, ignore_index=True)
        self.logger.info(f"Reset state to desired value: {desired_value}")

    def save_state(self, log_date: str, filename: str = None):
        """Save the current state to a file.
        Args:
            log_date (str): The date string in "YYYY-MM-DD" format to identify the log file.
            filename (str, optional): The filename to save the state to. If None, a default filename is used. Defaults to None.
        Saves the log_df DataFrame to a CSV file.
        It does not return anything, but writes the log_df to a file.
        Must be called after compute() to ensure the current state is saved.
        """
        # If filename is not provided, use a default filename based on the controller's name
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"

        # Save the log_df DataFrame to a file
        self.log_df['Timestamp'] = pd.to_datetime(self.log_df['Timestamp'])
        save_df_with_check(self.log_df, filename, log=True)
        # self.log_df.to_csv(filename, index=False) # Uncomment if you want a simpler way to save without 'save_df_with_check' (checking for overwriting already existing 'Timestamp' entries)
        self.logger.info(f"Saved state to {filename}")

# CLASS TO DEFINE HYSTERESIS COMPARATOR
@dataclass
class HysteresisComparator:
    """A hysteresis comparator to manage state transitions based on input values and defined thresholds.
    To compare a measurement point with its safety threshold to trigger control switches
    Boolean state depending on the measurement value, if laying below threshold low (False) or above threshold high (True)
    If the measurement point lays within the two thresholds, this function doesn't change its state
    Attributes:
        threshold_low (float): The lower threshold for state transition.
        threshold_high (float): The upper threshold for state transition.
        state (bool): The current state of the comparator. Defaults to False.
        logger (logging.Logger): Logger for the comparator. Defaults to a new logger.
        """
    threshold_low: float
    threshold_high: float
    state: bool = False  # Initial state
    logger: logging.Logger = field(default_factory=logging.getLogger)

    def __post_init__(self):
        """Initialize the logger."""
        self.logger.info(f"Initialized HysteresisComparator with thresholds: low={self.threshold_low}, high={self.threshold_high}")

    def update(self, value: float) -> bool:
        """
        Update the comparator state based on the input value.
        Args:
            value (float): The input value to compare against the thresholds.
        If the value is below the low threshold, the state is set to False.
        If the value is above the high threshold, the state is set to True.
        If the value is between the thresholds, the state remains unchanged.
        """
        previous_state = self.state
        if value < self.threshold_low:
            self.state = False
        elif value > self.threshold_high:
            self.state = True

        # Log the state change if it occurred
        if self.state != previous_state:
            self.logger.info(f"HysteresisComparator state changed to {self.state} for value: {value}")

        return self.state

    def get_state_as_string(self) -> str:
        """
        Return the current state as a string.
        """
        return str(self.state)