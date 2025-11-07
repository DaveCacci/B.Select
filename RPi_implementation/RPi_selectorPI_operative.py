#!/usr/bin/env python
# coding: utf-8
'''
### Biomethane production Optimal Control with the 'Selector-PI' feedback online controller (Biogoals.Select tool)
**Authors:** Davide Carecci  
**Created:** May 2025  
**Last Modified:** October 28, 2025  
**Version:** 1.1  
**Institution:** Politecnico di Milano  
#### Revision History

| Date       | Version | Author(s)              | Description                                                                                                    |
|------------|---------|------------------------|----------------------------------------------------------------------------------------------------------------|
| 2025-05-01 | 1.0     | D. Carecci             | Initial implementation for experimental validation over the reactors in the BioTA lab (USM, Valparaiso, Chile) |
| 2025-10-28 | 1.1     | D. Carecci             | Code and folder cleaning and documentation for handle over a copy to A2A S.p.A                                 |
'''
# In[1]: IMPORT STANDARD LIBRARIES
import pandas as pd
import os
from datetime import datetime, timedelta
import matplotlib.pyplot as plt
import numpy as np
import sys
import argparse

# In[2]: IMPORT CUSTOM LIBRARIES
from general_utils.read_file import*
from general_utils.save_df import*
from general_utils.udm_gas_conversion import udm_gas_conversion
from general_utils.create_dataframe import create_dataframe
from general_utils.convert_u_to_pwm import*
from general_utils.FlexiblePlotter import*
from general_utils.extract_nearest_row import extract_nearest_row
sys.path.insert(0, 'C:\\Users\\lenovo\\OneDrive - Politecnico di Milano\\Work_cloud\\DOTTORATO\\Sperimentazione UIT\\SelectorPI controller') #Add to PATH the path of the SelectorPI_controller.py file
from SelectorPI_controller import PIController, HysteresisComparator

# In[3]: DECLARE THE MAIN FUNCTION (ALLOW TO CALL IT FROM OTHER SCRIPTS) AND SETUP LOGGER
def main(modelname, now: datetime = datetime.now()):
    '''MAIN FUNCTION TO RUN THE SELECTOR PI CONTROLLER ON RASPBERRY PI
    INPUTS: modelname (str): The name of the model to use (e.g. '1' or '2').
            now (datetime): The current datetime for the control evaluation.
    OUTPUTS: Saves the control action and logs to specified files.'''

    # modelname = '1' #or '2' # If the desire is to run the present code stand alone, delete main function and unindent the code below. Then uncomment this line,
    directory = os.getcwd() # Modify if this code from another directory with respect to where the input and output files are stored and willing to be saved
    testname = ''  # If there is a specific test subfolder name of the <directory>, specify it here (e.g., '/Test_closedloop')
    # ------------------------------------------------------------------------------------------------------------------- #
    # DECLARE AND CONFIGURE LOGGER
    log_directory = os.path.join(directory, testname, "logs") # A subfolder 'logs' is created inside the test folder
    os.makedirs(log_directory, exist_ok=True)
    log_file = os.path.join(log_directory, 'selector_logging.log') # Specify the log file name
    logger = logging.getLogger()
    # Clean up any existing handlers for this logger
    for handler in logger.handlers[:]:
        logger.removeHandler(handler)
        handler.close()
    # File handler for writing logs to a file
    file_handler = logging.FileHandler(log_file, mode='a')
    file_handler.setLevel(logging.INFO)
    file_formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')
    file_handler.setFormatter(file_formatter)
    # Add handlers to the logger
    logger.addHandler(file_handler)
    if not logger.handlers:  # Avoid duplicate handlers
        # Console handler for displaying logs in the terminal
        console_handler = logging.StreamHandler()
        console_handler.setLevel(logging.INFO)
        console_formatter = logging.Formatter('%(levelname)s - %(message)s')
        console_handler.setFormatter(console_formatter)
        # Add handlers to the logger
        logger.addHandler(console_handler)
    logger.setLevel(logging.INFO)
    logger.info('############################################### START SELECTOR MAIN ###############################################')

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[4]: LOAD THE INPUT DATA FILES FROM CSV (MEASUREMENTS)
    # Round to the nearest hour (modified on 28.03.2025): needed only if this program is run together with another time-sensitive process (e.g. preprocessing of measurements each hour during last experimentation campaign).
    now = now.replace(minute=0, second=0, microsecond=0) + timedelta(hours=1 if now.minute >= 30 else 0) # datetime(2025,5,1,4,0) #datetime.now() # For testing purposes, fix a date here
    # Define current date for logging
    log_date = now.strftime('%Y-%m-%d')

    # Read past measurements data from CSV file
    y_df_on_path = os.path.join(directory, testname, 'Input', f'y_df_data_on_alt_R{modelname}.csv') # Path of the CSV file with measurements data
    y_df_data_on = pd.read_csv(y_df_on_path, sep=',', header=0, parse_dates=['Timestamp'])
    # Keep only some columns in y_df_data_on
    y_df_data_on = y_df_data_on[['Timestamp', 'gas_rate_out_ma', 'xM_gb_out', 'xC_gb_out']]

    # Extract the last TOT days of data from y_df_data_on
    y_df_data_on['Timestamp'] = pd.to_datetime(y_df_data_on['Timestamp'])
    start_timestamp = now - timedelta(days=3, minutes=5) # Window of past data to be read and used for plotting. Must be greater than the moving average window in the preprocessing of measurements 
    end_timestamp = now
    combined_dataframe = y_df_data_on[(y_df_data_on['Timestamp'] >= start_timestamp) & (y_df_data_on['Timestamp'] <= end_timestamp)] # Just to preserve old name of UIT selector

    # Calculate mean and standard deviation of dataset (not strictly necessary)
    mean = combined_dataframe['gas_rate_out_ma'].mean()
    stdev = combined_dataframe['gas_rate_out_ma'].std()
    logger.info(f"""dataset_gas_rate_mean = {mean}, dataset_gas_rate_mean = {stdev}""")

    # Calculate methane flowrate ('ch4_rate'), carbom dioxide flowrate ('co2_rate') and gas ratio ('ratio') as ch4/co2
    rate = f'gas_rate_out_ma' # Gas rate. Must be in (L/h). If not, convert above with 'udm_gas_conversion' (but then re-design the controller parameters accordingly)
    ch4 = f'xM_gb_out' # Methane percentage in gas. Must be a fraction (0-1).
    co2 = f'xC_gb_out' # Carbon dioxide percentage in gas. Must be a fraction (0-1).
    combined_dataframe['ch4_rate'] = combined_dataframe[rate]*combined_dataframe[ch4]
    combined_dataframe['co2_rate'] = combined_dataframe[rate]*combined_dataframe[co2]
    # If there are values with co2% = 0, return 0 for that time instant. Identify rows where 'co2' column is 0
    zero_value_rows = combined_dataframe[combined_dataframe[co2] == 0]
    logger.info("Timestamps corresponding to rows with 'co2' = 0:")
    logger.info(zero_value_rows['Timestamp'].tolist())
    combined_dataframe['co2ch4'] = np.where(combined_dataframe[co2] == 0, 0, combined_dataframe[co2]/combined_dataframe[ch4])

    # Extract data point for the current control step (last row of the read CSV files)
    last_row = combined_dataframe.iloc[-1]
    current_time = last_row['Timestamp']
    measure1 = last_row['ch4_rate']
    measure2 = last_row['co2ch4'] if last_row['co2ch4'] != 0 else 0.842 # Value taken from "optim_ss" simulation of 26.01.2024

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[5]: LOAD THE INPUT DATA FILES FROM TXT (SETPOINTS)
    # Read setpoints from TXT file for the current control step (nearest row with respect to 'current_time')
    try:
        y_ref = read_and_split_txt(os.path.join(directory, testname, 'Input', 'Output_setpoints.txt'), log=True)
        y_ref = create_dataframe(['Qch4_ref', 'co2ch4_ref'], [pd.Series(y_ref[1]), pd.Series(y_ref[2])], datetime(2025,4,30,10,0))
        y_ref['co2ch4_ref'] = 0.85 # Replace with "y_ref['Setpoint2']" if time-varying setpoint is desired
        y_ref['TresholdLow'] = y_ref['co2ch4_ref'] + 0.05 # Replace with "y_ref['TresholdLow']" if time-varying setpoint is desired
        y_ref['TresholdHigh'] = y_ref['co2ch4_ref'] + 0.1 # Replace with "y_ref['TresholdHigh']" if time-varying setpoint is desired
        y_ref['Timestamp'] = pd.to_datetime(y_ref['Timestamp'], format="%Y-%m-%d %H:%M:%S")
        logger.info("Setpoints loaded")
        # Extract row nearer to the current running time or last timestamp of the data files
        setpoints_row = extract_nearest_row(y_ref, current_time) # The 'Timestamp' column is rounded to one point for each hour (HH:00:00).
    except Exception  as e:
        logger.error(e)
    setpoint1 = setpoints_row['Qch4_ref']
    setpoint2 = setpoints_row['co2ch4_ref']
    threshold_low = setpoints_row['TresholdLow']
    threshold_high = setpoints_row['TresholdHigh']
    if threshold_low > threshold_high:
        logger.warning('Uncorrect relation between setpoint2 and tresholds')

    # Log for "boundary" conditions of the controller computations for the current evaluation
    data_filepath = os.path.join(directory, testname, 'Output', f'Boundary_calc_conditions.csv') # Add 'log_date' to filename if desired to create a new file for each day
    new_row_data = {'Timestamp_setpoints':setpoints_row['Timestamp'],'Timestamp_measures':current_time,
                    'ch4_setpoint':setpoint1, 'ch4_measure':measure1,
                    'co2/ch4_setpoint':setpoint2, 'co2/ch4_measure':measure2,
                    'threshold_low':threshold_low,'threshold_high':threshold_high}
    new_row_data_df = pd.DataFrame([new_row_data])
    new_row_data_df.insert(0, 'Timestamp', now) # Add the current timestamp to the DataFrame
    save_df_with_check(new_row_data_df, data_filepath, log=True)

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[6]: COMPUTE ERRORS, INSTANTIATE CONTROLLERS AND LOAD PAST CONTROLLER STATE
    # Compute the control errors
    error1 = setpoint1 - measure1
    error2 = setpoint2 - measure2
    dt = 3*3600 # Specify control interval (in seconds). Must be consistent with the frequency of code execution. Must be a multiple of 3600 seconds in this code version (27.10.2025)
    # Define controller parameters
    saturation_high = 300/1e6 # Control action flow rate (in mL/day converted to m^3/s)
    saturation_low = -99/1e6 # Control action flow rate (in mL/day converted to m^3/s)
    kp1 = 0.00068 # Note: divided by 2 with respect to UIT implementation after re-tuning on 11.05.2025
    kp2 = 0.004574 
    Ti1 = 144644 # In seconds
    Ti2 = 94283 # In seconds

    #Initialize the PI controllers controllers from the 'PIController' class (defined in SelectorPI_controller.py)
    header = PIController(name = "Header", kp = kp1, ki = kp1/Ti1, current_timestamp=now,
                                saturation_low =saturation_low, saturation_high = saturation_high, saturate_integral=False, logger=logger)
    follower = PIController(name = "Follower", kp = kp2, ki = kp2/Ti2, current_timestamp=now,
                                saturation_low = saturation_low, saturation_high = saturation_high, saturate_integral=False, logger=logger)

    # Set filenames for saving/loading controller states
    output_filename_header = 'State_header'
    output_filename_follower = 'State_follower'
    # Load the state from the previous run (last saved state)
    header.load_state(log_date, filename=os.path.join(directory, testname, 'Output', f"{output_filename_header}_{log_date}.csv"))
    follower.load_state(log_date, filename=os.path.join(directory, testname, 'Output', f"{output_filename_follower}_{log_date}.csv"))

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[7]: SELECTION OF THE ACTIVE CONTROLLER (and eventual override)
    # Defines a boolean 'condition' = state of the hysteresis comparator function. When 'edge' of 'condition', override is triggered
    # Extract previous condition from the last log entry
    if not follower.log_df.empty:
        follower.log_df.loc[follower.log_df.index[-1],'selection'] = follower.log_df.at[follower.log_df.index[-1],'selection'] == 'True'
    prev_condition = follower.log_df.iloc[-1]['selection'] if not follower.log_df.empty else False # At control initialization (k=0), set 'prev_condition' to False

    # Update the hysteresis comparator state with the current measurement2 ('co2/ch4 ratio')
    hysteresis_comp = HysteresisComparator(threshold_low=threshold_low, threshold_high=threshold_high, logger=logger)
    condition = hysteresis_comp.update(measure2) # Note: 'condition' is True if measured 'co2/ch4 ratio' reached dangerous values, else False

    # Check for the edge condition change: if so and False->True, override and activate follower; if True->False, override and activate header
    if condition != prev_condition and prev_condition == False:
        # Compute the desired value for the override of the integrator in case of edge condition change
        desired_value_follower = (float(header.log_df.iloc[-1]['control_signal'])-follower.kp*error2)/follower.ki if not header.log_df.empty else 0
        # Override the state of the inactive->active controller to be consistent with the current control action
        follower.reset_state(desired_value_follower)
    if condition != prev_condition and prev_condition == True:
        # Compute the desired value for the override of the integrator in case of edge condition change
        desired_value_header = (float(follower.log_df.iloc[-1]['control_signal'])-header.kp*error1)/header.ki if not follower.log_df.empty else 0
        # Override the state of the inactive->active controller to be consistent with the current control action
        header.reset_state(desired_value_header)

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[8]: COMPUTATION OF THE CONTROL ACTION (FOR BOTH CONTROLLERS) AND SELECTION OF THE FINAL CONTROL ACTION
    # Calculate the control signal for both controllers
    control_output1 = header.compute(error1, dt, not condition) # In m^3/s
    control_output2 = follower.compute(error2, dt, condition) # In m^3/s

    # Save the state of controllers for the next run
    header.save_state(log_date, filename=os.path.join(directory, testname, 'Output', f'{output_filename_header}_{log_date}.csv'))
    follower.save_state(log_date, filename=os.path.join(directory, testname, 'Output', f'{output_filename_follower}_{log_date}.csv'))
    save_df_with_check(header.log_df, os.path.join(directory, testname, 'Output', f'{output_filename_header}.csv'), log=True) # Just for plotting and compactness purposes
    save_df_with_check(follower.log_df, os.path.join(directory, testname, 'Output', f'{output_filename_follower}.csv'), log=True) # Just for plotting and compactness purposes

    # Switch: choose between the two control signals based on the condition
    active_controller_name = follower.name if condition else header.name # If condition, the 'co2/ch4 ratio' controller is active and its control signal is selected
    final_control_signal = control_output2 if condition else control_output1 # If condition, the 'co2/ch4 ratio' controller is active and its control signal is selected
    nominal_u = 100 # Nominal/initial control action (in mL/day)
    u_current = final_control_signal*1e6 + nominal_u # Final control action (in mL/day)

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[9]: CONVERT CONTROL ACTION TO ON/OFF TIMES FOR THE RASPBERRY PI RELAY, AND SAVE RESULTS TO CSV FILES
    # Define the parameters to describe the characteristics of the pump and conversion from flow-rate to PWM
    u_max = saturation_high*1e6
    pump_dose_per_minute = 20 # Flow rate of the peristaltic pump (in mL/min)
    period = 20 # On-period of the PWM (in seconds)

    # Convert
    tuple_seconds, on_periods_tot, conversion_error = convert_u_to_pwm(u_current, u_max, dt, pump_dose_per_minute, period)
    rounded_dosage = period*on_periods_tot*pump_dose_per_minute/60*24/dt*3600 # Just for checking purposes (in mL/day)

    # Save the computed PWM values to a CSV file
    pwm_star_dict = dict(zip(['on_sec', 'off_sec', 'tot_on_periods', 'rounded_dosage'],
                    np.array([tuple_seconds[0], tuple_seconds[1], on_periods_tot, rounded_dosage])))
    pwm_star_df = pd.DataFrame([pwm_star_dict])
    pwm_star_df.insert(0, 'Timestamp', now)
    save_df_with_check(pwm_star_df, os.path.join(directory, testname, "Input", f'SELECTOR_pwm_actual.csv'), log=True)
    
    # Summary log to CSV file for main outputs of this run
    new_row_output = {'active':active_controller_name, 'ch4_error': error1, 'co2/ch4_error': error2, 
                    'c2/ch4-Trlow': measure2 - threshold_low, 'co2/ch4_TrHigh':measure2 - threshold_high, 
                    'final_control_signal':u_current, 'tot_on_periods':on_periods_tot,
                    'on_seconds':tuple_seconds[0],'off_seconds':tuple_seconds[1]
                    }
    new_row_output_df = pd.DataFrame([new_row_output])
    new_row_output_df.insert(0, 'Timestamp', now) # Add the current timestamp to the DataFrame
    save_df_with_check(new_row_output_df, os.path.join(directory, testname,'Output', f'Output_selector_{log_date}.csv'), log=True)
    save_df_with_check(new_row_output_df, os.path.join(directory, testname, 'Output', f'Output_selector.csv'), log=True)
    
    # Save the control action also in daily load (only for simulation tests e.g. EKF for the R2 reactor in Chile experimental campaign)
    # u_star_df = pd.DataFrame({'Timestamp': [now], 'Uk': [np.round(u_current, 1)]})
    # save_df_with_check(u_star_df, os.path.join(directory, testname, "Input", f'{modelname}_u_actual.csv'), log=True)

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[10]: PLOT THE RESULTS (on the past days from start_timestamp to now)
    # Create an instance of FlexiblePlotter
    plotter = FlexiblePlotter(default_figsize = (12, 12), logger=logger)
    df_output = read_csv_file(os.path.join(directory, testname, 'Selector',f'Output_selector.csv'), log=True)
    # Define a map to show which controller is active (from "Header"/"Follower" strings in the 'active' column to integers "100"/"200")
    df_output['active'] = df_output['active'].map({'Header': 100, 'Follower': 200})
    # Interpolate to have values at each hour (fill missing timestamps with previous value)
    df_output['Timestamp'] = pd.to_datetime(df_output['Timestamp'])
    df_output.set_index('Timestamp', inplace=True)
    df_output = df_output.reindex(pd.date_range(start=df_output.index.min(), end=df_output.index.max(), freq='1H'))
    df_output = df_output.fillna(method='pad')
    df_output.reset_index(inplace=True)
    df_output.rename(columns={'index': 'Timestamp'}, inplace=True)
    df_output.reset_index(inplace=True)

    # Read the state data of both controllers
    df_state_header = read_csv_file(os.path.join(directory, testname, 'Output', f'{output_filename_header}.csv'), log=True)
    df_state_follower = read_csv_file(os.path.join(directory, testname, 'Output', f'{output_filename_follower}.csv'), log=True)
    # Convert units of measure for plotting (if needed)
    combined_dataframe['ch4_rate'] = udm_gas_conversion(combined_dataframe['ch4_rate'], (42+273.15), 1.035, 12, 'Lh')
    y_ref['Qch4_ref'] = udm_gas_conversion(y_ref['Qch4_ref'], (42+273.15), 1.035, 12, 'Lh')
    
    # Prepare data dictionary for plotting
    data = {"data_on": combined_dataframe,
            "control_outputs": df_output,
            "follower":df_state_follower,
            "header":df_state_header,
            "setpoint": y_ref,
            }
    # Define the variables to be plotted (grouped in subplots)
    variable_groups = [[("data_on", "ch4_rate"), ("setpoint", "Qch4_ref")], # Methane flowrate vs setpoint
        [("data_on", "co2ch4"), ("setpoint", "co2ch4_ref"),("setpoint", "TresholdLow"), ("setpoint", "TresholdHigh")], # CO2/CH4 ratio vs setpoints
        [("control_outputs", "final_control_signal"), ("control_outputs", "active")], # Final control action and active controller
        [("header", "u_p"), ("header", "u_i"), ("header", "control_signal")], # Header controller states (proportional and integral actions, control signal)
        [("follower", "u_p"), ("follower", "u_i"), ("follower", "control_signal")]] # Follower controller states (proportional and integral actions, control signal)
    # Calculate the x_limits in datetime format
    end_time = end_timestamp
    start_time = start_timestamp
    x_limits = [(start_time, end_time) for _ in range(len(variable_groups))]
    date_string = f'{start_time.strftime("%d%m%H")}-{end_time.strftime("%d%m%H")}'
    # Use the FlexiblePlotter to create the plot
    plotter.plot_grouped_variables_across_dfs(data = data,
        variable_groups = variable_groups,
        x_axis_format = "datetime",
        x_limits = x_limits,
        x_axis_ticks_format = "%d-%m %H",
        tick_rotation = 90,
        interval = 1,
        grid = True,
        show_plot = False,
        y_labels=[None for _ in range(len(variable_groups))],
        legend_param={"loc": "upper left"},
        colors={"setpoint":["violet" for _ in range(len(variable_groups[1]))], 
                "df_model_past":["orange"]},
        alphas={"setpoint":[1, 1, 0.5, 0.5], "control_outputs": [1, 2, 1, 1]},
        linestyles={'setpoint': ['--' for _ in range(len(variable_groups[1]))],},
        y_limits=[(10, 70), (0.5, 1.5), (saturation_low*1e6+nominal_u-1, saturation_high*1e6+nominal_u+1), 
                    (df_state_header[['u_p','u_i','control_signal']].min().min()*0.9, df_state_header[['u_p','u_i','control_signal']].max().max()*1.1), 
                    (df_state_follower[['u_p','u_i','control_signal']].min().min()*0.9, df_state_follower[['u_p','u_i','control_signal']].max().max()*1.1)])
    output_path = os.path.join(directory, testname, 'Plots')
    os.makedirs(os.path.dirname(output_path), exist_ok=True) # Ensure the output directory exists
    plt.savefig(os.path.join(output_path, f"R{modelname}_{date_string}_selector.png"), bbox_inches='tight', dpi=300) # Save the figure
    logger.info(f"Plot saved to {output_path}")
    logger.info('############################################### END SELECTOR MAIN ###############################################')

# ------------------------------------------------------------------------------------------------------------------- #
# In[11]: ALLOW THE SCRIPT TO BE EXECUTED FROM THE TERMINAL WITH COMMAND-LINE ARGUMENTS
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Run SelectorPI_controller_operative.")
    parser.add_argument("modelname", type=str, help="Model name (e.g., '1' or '2').")
    parser.add_argument("--now", type=str, default=None, help="Optional datetime in the format 'YYYY-MM-DD HH:MM:SS'. Defaults to the current time.")
    args = parser.parse_args()
    modelname = args.modelname
    now = datetime.strptime(args.now, "%Y-%m-%d %H:%M:%S") if args.now else datetime.now()
    main(modelname, now)