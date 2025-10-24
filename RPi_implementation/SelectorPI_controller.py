# FUNCTION TO DEFINE PI controller with saturation and anti wind-up
# Choice to saturate the integral term or not
# Logs quantities of interest in a dataframe 'log_df'
# class PIController:
#     # INIT
#     def __init__(self, name, kp, ki, saturation_low=None, saturation_high=None, saturate_integral=True):
#         self.name = name
#         self.kp = kp
#         self.ki = ki
#         self.saturation_low = saturation_low
#         self.saturation_high = saturation_high
#         self.saturate_integral = saturate_integral
#         self.log_df = pd.DataFrame(columns=['timestamp', 'error', 'integral','integral_past','u_p','u_i','u_i_past','control_signal','saturation','selection'])

#     # -------------------------------------------------------------------------------------------------------------------
#     # COMPUTE CONTROL SIGNAL FROM ERROR AND PAST INTEGRAL TERM
#     def compute(self, error, dt, selection):
#         # Past integral term loaded from the last row of dataframe 'log_df'
#         integral_past = self.log_df['integral'].iloc[-1] if not self.log_df.empty else 0 #Default starting value
#         # Integral 
#         integral = integral_past + error * dt #dt = control interval

#         # Apply saturation to the integral term if specified
#         if self.saturate_integral:
#             if self.saturation_low is not None and integral < self.saturation_low:
#                 integral = self.saturation_low
#             elif self.saturation_high is not None and integral > self.saturation_high:
#                 integral = self.saturation_high

#         # Calculate the control action
#         u_p = self.kp * error # Proportional action
#         u_i_past = self.ki*integral_past #Just for checking purposes. Must always be 'control_signal - u_p' at the previous iteration
#         u_i = self.ki * integral # Integral action
#         control_signal = u_p + u_i

#         # Apply saturation to the control signal
#         if self.saturation_low is not None and control_signal < self.saturation_low:
#             control_signal = self.saturation_low
#         elif self.saturation_high is not None and control_signal > self.saturation_high:
#             control_signal = self.saturation_high
            
#         # If 'control_signal' is in saturation, apply anti-windup
#         if control_signal <= self.saturation_low:
#             saturation = 'Low'
#             integral = (control_signal - u_p)/self.ki
#         elif control_signal >= self.saturation_high:
#             saturation = 'High'
#             integral = (control_signal - u_p)/self.ki
#         else:
#             saturation = 'No'

#         # Log the quantities of interest
#         timestamp = datetime.now()
#         self.log_df = self.log_df.append({'timestamp': timestamp, 'error': error, 'integral': integral,'integral_past': integral_past,'u_p':u_p,'u_i':u_i,'u_i_past':u_i_past,
#                                           'control_signal':control_signal,'saturation':saturation,'selection': selection}, ignore_index=True)
        
#         return control_signal
    
#     # -------------------------------------------------------------------------------------------------------------------
#     # FUNCTION TO LOAD 'integral_past' FROM PREVIOUS CONTROL EVALUATIONS
#     # Checks current date log. If not, takes the log file of the previous date
#     # If there are no current and previous date log files, 'integral_past' restart from default value (0).
#     def load_state(self, filename=None):
#         # If filename is not provided, use a default filename based on the controller's name
#         if filename is None:
#             filename = f"{self.name}_{log_date}_state.csv"
        
#         # Load the log_df DataFrame from a file
#         try:
#             self.log_df = pd.read_csv(filename)
#             print(f"Loaded integral state from {filename}")
            
#         except FileNotFoundError:
#             previous_date = (datetime.now() - timedelta(days=1)).strftime("%Y-%m-%d")
#             file_path_previous = f"{self.name}_{previous_date}_state.csv"
#             try:
#                 self.log_df = pd.read_csv(file_path_previous).iloc[[-1]]
#                 print(f"Loaded integral state for {self.name} from {file_path_previous}")
                
#             except FileNotFoundError:
#                 print(f"No integral state file found for {self.name} from the current or previous day. Initializing from default state.")
                
#     # -------------------------------------------------------------------------------------------------------------------
#     # REINIT FUNCTION 
#     # ADD a line to the log of the controller whose state must be reinitialized at the current control evaluation
#     # With a desired value to allow for coherence between the states of the two controllers
#     # To be run before control computation, so that 'desired_value' is laoded as the last row of 'integral'
#     def reset_state(self, desired_value):
#         timestamp = datetime.now()
#         new_row = {'timestamp': timestamp, 'error': '-', 'integral': desired_value,'control_signal':'-','selection': str('reselected')}
#         self.log_df = self.log_df.append(new_row, ignore_index=True)
        
#     # -------------------------------------------------------------------------------------------------------------------
#     # FUNCTION TO SAVE QUANTITIES OF INTEREST TO CSV AT THE CURRENT CONTROLLER EVALUATION
#     # Usefull for the control evaluation at the next control instant 
#     def save_state(self, filename=None):
#         # If filename is not provided, use a default filename based on the controller's name
#         if filename is None:
#             filename = f"{self.name}_{log_date}_state.csv"
        
#         # Save the log_df DataFrame to a file
#         self.log_df.to_csv(filename, index=False)

from dataclasses import dataclass, field
import pandas as pd
from datetime import datetime, timedelta
import logging
import pandas as pd
from datetime import datetime, timedelta
import os
import sys
sys.path.append("C:\\Users\\lenovo\\OneDrive - Politecnico di Milano\\Work_cloud\\DOTTORATO\\Sperimentazione MPC\\NMPC")
from general_utils.save_df import save_df_with_check

@dataclass
class PIController:
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
        """Compute the control signal based on the error and past integral term."""
        integral_past = self.log_df['integral'].iloc[-1] if not self.log_df.empty else 0
        integral = integral_past + error * dt

        if self.saturate_integral:
            if self.saturation_low is not None and integral < self.saturation_low:
                integral = self.saturation_low
            elif self.saturation_high is not None and integral > self.saturation_high:
                integral = self.saturation_high

        u_p = self.kp * error
        u_i_past = self.ki * integral_past
        u_i = self.ki * integral
        control_signal = u_p #+ u_i

        if self.saturation_low is not None and control_signal < self.saturation_low:
            control_signal = self.saturation_low
        elif self.saturation_high is not None and control_signal > self.saturation_high:
            control_signal = self.saturation_high

        if control_signal <= self.saturation_low:
            saturation = 'Low'
            integral = (control_signal - u_p) / self.ki
        elif control_signal >= self.saturation_high:
            saturation = 'High'
            integral = (control_signal - u_p) / self.ki
        else:
            saturation = 'No'

        #timestamp = datetime.now()
        self.log_df = self.log_df.append({
            'Timestamp': self.current_timestamp, 'error': error, 'integral': integral, 'integral_past': integral_past,
            'u_p': u_p, 'u_i': u_i, 'u_i_past': u_i_past, 'control_signal': control_signal,
            'saturation': saturation, 'selection': selection
        }, ignore_index=True)

        self.logger.info(f"Computed control signal of {self.name}: {control_signal}, saturation: {saturation}")
        return control_signal

    def load_state(self, log_date: str, filename: str = None):
        """Load the integral state from a file."""
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"
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
        """Reset the integral state to a desired value."""
        #timestamp = datetime.now() #????????????????????
        new_row = {
            'Timestamp': self.current_timestamp, 'error': '-', 'integral': desired_value,
            'control_signal': '-', 'selection': 'reselected'
        }
        self.log_df = self.log_df.append(new_row, ignore_index=True)
        self.logger.info(f"Reset state to desired value: {desired_value}")

    def save_state(self, log_date: str, filename: str = None):
        """Save the current state to a file."""
        if filename is None:
            filename = f"{self.name}_{log_date}_state.csv"

        #self.log_df.to_csv(filename, index=False)
        # Ensure the 'Timestamp' column is in the correct format before saving
        self.log_df['Timestamp'] = pd.to_datetime(self.log_df['Timestamp'])
        save_df_with_check(self.log_df, filename, log=True)
        self.logger.info(f"Saved state to {filename}")


# FUNCTION TO DEFINE HYSTERESIS COMPARATOR
# To compare 'co2/ch4' measurement point with its safety threshold to trigger control switches
# 'co2/ch4' setpoint < treshold low > treshold high 
# Boolean state depending on 'co2/ch4' measurement laying below treshold low (False) or above treshold high (True)
# If 'co2/ch4' lays within the two tresholds, this function doesn't change its state
# class HysteresisComparator:
#     # INIT
#     def __init__(self, threshold_low, threshold_high):
#         self.threshold_low = threshold_low
#         self.threshold_high = threshold_high
#         self.state = False  # Initial state
#     # -------------------------------------------------------------------------------------------------------------------
#     # UPDATE COMPARATOR STATE
#     def update(self, value):
#         if value < self.threshold_low:
#             self.state = False
#         elif value > self.threshold_high:
#             self.state = True
#         # If the value is between the thresholds, maintain the current state
#         #What if threshold_high<threshold_low ?

#         return self.state
#     # -------------------------------------------------------------------------------------------------------------------
#     # FUNCTION TO MOVE FROM STATE TO STRING (needed for later code usage)
#     def get_state_as_string(self):
#         return str(self.state)
@dataclass
class HysteresisComparator:
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