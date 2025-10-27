#!/usr/bin/env python
# coding: utf-8

# SPECIFY UNITS OF MEASUREMENTS!!!!!!!!!!!!!!!!!!!!!!!!!! (tipo dt in seconds, flowrate in mL/day, etc)
# 21.03.2025 TO DO:
# 1. Change data variable names (taking from raw_data.csv)?
# 2. Change setpoint variable names (taking from setpoint.csv)?
# 3. Change the parameter of the controller after Modelica optimization
# 4. Change conversion from flow-rate of tomato to PWM
# 5. Change the path of the output plots and csv files
# In[1]: IMPORT STANDARD LIBRARIES
import pandas as pd
import configparser
import pylab as pl
import os
from datetime import datetime, timedelta
import shutil
import matplotlib.pyplot as plt
import numpy as np
from scipy.signal import convolve
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
    testname = ''  # If there is a specific test subfolder name of the <directory>, specify it here (e.g., '/Selector_test')
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
    y_df_on_path = os.path.join(directory, testname, f'y_df_data_on_alt_R{modelname}.csv') # Path of the CSV file with measurements data
    y_df_data_on = pd.read_csv(y_df_on_path, sep=',', header=0, parse_dates=['Timestamp'])
    # Keep only some columns in y_df_data_on
    y_df_data_on = y_df_data_on[['Timestamp', 'gas_rate_out_ma', 'xM_gb_out', 'xC_gb_out']]

    # Extract the last TOT days of data from y_df_data_on
    y_df_data_on['Timestamp'] = pd.to_datetime(y_df_data_on['Timestamp'])
    start_timestamp = now - timedelta(days=3, minutes=5) # Window of past data to be read and used for plotting. Must be greater than the moving average window in the preprocessing of measurements 
    end_timestamp = now
    combined_dataframe = y_df_data_on[(y_df_data_on['Timestamp'] >= start_timestamp) & (y_df_data_on['Timestamp'] <= end_timestamp)] # Just to preserve old name of UIT selector

    # Calculate mean and standard deviation of dataset (not strictly necessary)
    mean_R2 = combined_dataframe['gas_rate_out_ma'].mean()
    stdev_R2 = combined_dataframe['gas_rate_out_ma'].std()
    logger.info(f"""dataset_gas_rate_mean = {mean_R2}, dataset_gas_rate_mean = {stdev_R2}""")

    # Calculate methane flowrate ('ch4_rate') and gas ratio ('ratio') as ch4/co2
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
    # In[18]: LOAD THE INPUT DATA FILES FROM CSV (SETPOINTS)
    # Read setpoints from CSV file for the current control step (nearest row with respect to 'current_time')
    try:
        y_ref = read_and_split_txt(os.path.join(directory, testname, 'Output_setpoints.txt'), log=True)
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
    setpoint2 = setpoints_row['co2ch4_ref'] # -------------------------------------------- CONSTANT VALUES OR NOT?
    threshold_low = setpoints_row['TresholdLow'] # -------------------------------------------- CONSTANT VALUES OR NOT?
    threshold_high = setpoints_row['TresholdHigh'] # -------------------------------------------- CONSTANT VALUES OR NOT?
    if threshold_low > threshold_high:
        logger.warning('Uncorrect relation between setpoint2 and tresholds')

    # Log for "boundary" conditions of the controller computations for the current evaluation
    data_filepath = os.path.join(directory, testname, f'Buondary_calc_conditions.csv') # Add 'log_date' to filename if desired to create a new file for each day
    new_row_data = {'Timestamp_setpoints':setpoints_row['Timestamp'],'Timestamp_measures':current_time,
                    'ch4_setpoint':setpoint1, 'ch4_measure':measure1,
                    'co2/ch4_setpoint':setpoint2, 'co2/ch4_measure':measure2,
                    'threshold_low':threshold_low,'threshold_high':threshold_high}
    new_row_data_df = pd.DataFrame([new_row_data])
    new_row_data_df.insert(0, 'Timestamp', now) # Add the current timestamp to the DataFrame
    save_df_with_check(new_row_data_df, data_filepath, log=True)

    # ------------------------------------------------------------------------------------------------------------------- #
    # In[20]: COMPUTE ERRORS, INSTANTIATE CONTROLLERS AND LOAD PAST CONTROLLER STATE
    # Compute the control errors
    error1 = setpoint1 - measure1
    error2 = setpoint2 - measure2
    dt = 3*3600 # Specify control interval (in seconds). Must be consistent with the frequency of code execution
    # Define controller parameters
    saturation_high = 300/1e6 # Control action flow rate (in mL/day converted to m3/s)
    saturation_low = -99/1e6 # Control action flow rate (in mL/day converted to m3/s)
    kp1 = 0.00068 # Note: divided by 2 with respect to UIT implementation after re-tuning on 11.05.2025
    kp2 = 0.004574 
    Ti1 = 144644 
    Ti2 = 94283

    #Initialize the PI controllers controllers from the 'PIController' class (defined in SelectorPI_controller.py)
    controller1 = PIController(name = "Header", kp = kp1, ki = kp1/Ti1, current_timestamp=now,
                                saturation_low =saturation_low, saturation_high = saturation_high, saturate_integral=False, logger=logger)
    controller2 = PIController(name = "Follower", kp = kp2, ki = kp2/Ti2, current_timestamp=now,
                                saturation_low = saturation_low, saturation_high = saturation_high, saturate_integral=False, logger=logger)

    # Load the state from the previous run (last saved state)
    controller1.load_state(log_date, filename=os.path.join(directory, testname, 'Selector',f'State_header_{log_date}.csv'))
    controller2.load_state(log_date, filename=os.path.join(directory, testname, 'Selector',f'State_follower_{log_date}.csv'))

    # ------------------------------------------------------------------------------------------------------------------- #

    # In[22]: SELECTION OF THE ACTIVE CONTROLLER (and eventual override)
    # Defines a boolean 'condition' as the state of the hysteresis comparator function
    # When 'edge' of 'condition', REINIT is triggered
    if not controller2.log_df.empty:
        controller2.log_df.loc[controller2.log_df.index[-1],'selection'] = controller2.log_df.at[controller2.log_df.index[-1],'selection'] == 'True'
    prev_condition = controller2.log_df.iloc[-1]['selection'] if not controller2.log_df.empty else False # Initialize the 'prev_condition'
    # Reset the state of controller1 using the last state of controller2 if the condition holds
    # It adds a row in the log.
    # QUESTION: Alternative: Dovrei cambiare struttura e, se condizione, non far leggere ultimo stato da file ma specificarlo direttamente
    derired_value_controller1 = (float(controller2.log_df.iloc[-1]['control_signal'])-controller1.kp*error1)/controller1.ki if not controller2.log_df.empty else 0
    derired_value_controller2 = (float(controller1.log_df.iloc[-1]['control_signal'])-controller2.kp*error2)/controller2.ki if not controller1.log_df.empty else 0

    #condition = True if measure2 > threshold else False
    hysteresis_comp = HysteresisComparator(threshold_low=threshold_low, threshold_high=threshold_high, logger=logger)
    condition = hysteresis_comp.update(measure2)

    # Check for the edge condition change
    if condition != prev_condition and prev_condition == False:
        # Reinitialize the state of controllers based on the edge condition
        controller2.reset_state(derired_value_controller2)
    if condition != prev_condition and prev_condition == True:
        controller1.reset_state(derired_value_controller1)

    # In[23]:
    # COMPUTATION OF THE CONTROL ACTION FOR BOTH CONTROLLERS
    # SWITCH SELECTION OF THE CONTROL ACTION BASED ON WHICH CONTROLLER IS ACTIVE (based on 'condition' defined above)
    # Calculate the control output
    nominal_u = 100 # mL/day (nominal flowrate of tomato souce)
    control_output1 = controller1.compute(error1, dt, not condition)
    control_output2 = controller2.compute(error2, dt, condition)

    # Save the state of controllers for the next run
    controller1.save_state(log_date, filename=os.path.join(directory, testname,'Selector',f'State_header_{log_date}.csv'))
    controller2.save_state(log_date, filename=os.path.join(directory, testname, 'Selector',f'State_follower_{log_date}.csv'))
    save_df_with_check(controller1.log_df, os.path.join(directory, testname, 'Selector',f'State_header.csv'), log=True)
    save_df_with_check(controller2.log_df, os.path.join(directory, testname, 'Selector',f'State_follower.csv'), log=True)

    #SWITCH
    # Choose between the two control signals based on the condition
    final_control_signal = control_output2 if condition else control_output1
    selector_error = 'No'
    u_current = final_control_signal*1e6 + nominal_u # Control action in mL/day

    #print(controller1.log_df)
    #print(controller2.log_df)

    # In[24]:

    # CONVERT FLOAT (DISCRETE) CONTROL ACTION
    # Move from tomato souce daily load (mL/day) to on/off interval duration of peristaltic pumps control
    # QUESTION: center the control around the initial equilibrium and control action (10 ml/control interval) or around the optimal feeding strategy?
    # If the second is persued, 'saturationLow' and 'on_minutes_nominal' must be varied in time 
    # CONVERT CONTROL ACTION TO ON/OFF TIMES FOR THE RASPBERRY PI RELAY
    u_max = saturation_high*1e6
    dt = dt
    pump_dose_per_minute = 20 #mL/min (add it to integrator_parameters?)
    period = 20 #secc
    tuple_seconds_ini, on_periods_tot, conversion_error = convert_u_to_pwm(u_current, u_max, dt, pump_dose_per_minute, period)
    rounded_dosage = period*on_periods_tot*pump_dose_per_minute/60*24/dt*3600 #mL/day
    pwm_star_dict = dict(zip(['on_sec', 'off_sec', 'tot_on_periods', 'rounded_dosage'],
                    np.array([tuple_seconds_ini[0], tuple_seconds_ini[1], on_periods_tot, rounded_dosage])))
    pwm_star_df = pd.DataFrame([pwm_star_dict]) #duplicate last element
    pwm_star_df.insert(0, 'Timestamp', now)
    save_df_with_check(pwm_star_df, os.path.join(directory, testname, "Input", f'SELECTOR_pwm_actual.csv'), log=True) #save with date_string?
    # -------------------------------------------------------------------------------------------------------------------
    # END OF CONTROL COMPUTATION FOR THE CURRENT CONTROL EVALUATION

    #QUESTION: Alternative: Run the controller computation in case everything has been saved together as a python function
    # What is better for running .bat with scheduler?
    #success = selector()

    # SUMMARY LOG TO CSV FILE for main outputs of the controller computation run
    output_filepath = os.path.join(directory, testname,'Selector',f'Output_selector_{log_date}.csv')
    active_controller_name = controller2.name if condition else controller1.name
    new_row_output = {'active':active_controller_name, 'ch4_error': error1, 'co2/ch4_error': error2, 
                    'c2/ch4-Trlow': measure2 - threshold_low, 'co2/ch4_TrHigh':measure2 - threshold_high, 
                    'final_control_signal':u_current, 'tot_on_periods':on_periods_tot,
                    'on_seconds_ini':tuple_seconds_ini[0],'off_seconds_ini':tuple_seconds_ini[1]
                    }
    #append_row_to_csv(output_filepath, new_row_output)
    new_row_output_df = pd.DataFrame([new_row_output])
    new_row_output_df.insert(0, 'Timestamp', now) # Add the current timestamp to the DataFrame
    #timestamp = now #datetime.now() #????????????????????
    save_df_with_check(new_row_output_df, output_filepath, log=True)
    output_filepath = os.path.join(directory, testname, 'Selector',f'Output_selector.csv')
    save_df_with_check(new_row_output_df, output_filepath, log=True)
    
    # CONTROL ACTION (only for simulation test and to track EKF offline for R2)
    u_star_df = pd.DataFrame({'Timestamp': [now], 'Uk': [np.round(u_current, 1)]})
    save_df_with_check(u_star_df, os.path.join(directory, testname, "Input", f'NMPC_R{modelname}_u_actual_ANCILLARY_real.csv'), log=True)
    # ------------------------------------------------------------------------------------------------------------------- #

    # In[25]:
    # PLOT THE RESULTS (and past results)
    # PLOT VS DATA
    # Create an instance of FlexiblePlotter
    plotter = FlexiblePlotter(default_figsize = (12, 12), logger=logger)
    #df_boundary = read_csv_file(os.path.join(directory, testname, f'Selector_test\\Buondary_calc_conditions.csv'), log=True)
    df_output = read_csv_file(os.path.join(directory, testname, 'Selector',f'Output_selector.csv'), log=True)
    # Map Header / Follower strings in the 'active' column as numeric 1 or 2
    df_output['active'] = df_output['active'].map({'Header': 100, 'Follower': 200})
    #df_output['active'] = df_output['active'].astype(int)  # Convert to integer type
    # Interpolate
    df_output['Timestamp'] = pd.to_datetime(df_output['Timestamp'])
    df_output.set_index('Timestamp', inplace=True)
    # Create a new index with 1-hour intervals
    df_output = df_output.reindex(pd.date_range(start=df_output.index.min(), end=df_output.index.max(), freq='1H'))
    # Interpolate the missing values
    df_output = df_output.fillna(method='pad')
    df_output.reset_index(inplace=True)
    df_output.rename(columns={'index': 'Timestamp'}, inplace=True)
    df_output.reset_index(inplace=True)
    #
    df_state_header = read_csv_file(os.path.join(directory, testname, 'Selector',f'State_header.csv'), log=True)
    df_state_follower = read_csv_file(os.path.join(directory, testname, 'Selector',f'State_follower.csv'), log=True)
    #
    combined_dataframe['ch4_rate'] = udm_gas_conversion(combined_dataframe['ch4_rate'], (42+273.15), 1.035, 12, 'Lh')
    y_ref['Qch4_ref'] = udm_gas_conversion(y_ref['Qch4_ref'], (42+273.15), 1.035, 12, 'Lh')
    #
    data = {"data_on": combined_dataframe,
            #"boundaries": df_boundary,
            "control_outputs": df_output, #there is u here! Interpolate it!
            "follower":df_state_follower, #remove log_date!!
            "header":df_state_header,
            "setpoint": y_ref,
            }
    # Define the variables to be plotted
    variable_groups = [
        [("data_on", "ch4_rate"), ("setpoint", "Qch4_ref")],  # Second subplot
        [("data_on", "co2ch4"), ("setpoint", "co2ch4_ref"),("setpoint", "TresholdLow"), ("setpoint", "TresholdHigh")],  # Second subplot
        [("control_outputs", "final_control_signal"), ("control_outputs", "active")],  # Third subplot
        [("header", "u_p"), ("header", "u_i"), ("header", "control_signal")],  # Third subplot
        [("follower", "u_p"), ("follower", "u_i"), ("follower", "control_signal")],  # Third subplot
    ]

    # Calculate the x_limits
    end_time = end_timestamp
    start_time = start_timestamp
    x_limits = [(start_time, end_time) for _ in range(len(variable_groups))]
    date_string = f'{start_time.strftime("%d%m%H")}-{end_time.strftime("%d%m%H")}'

    # Use the FlexiblePlotter to create the plot
    plotter.plot_grouped_variables_across_dfs(
        data=data,
        variable_groups=variable_groups,
        x_axis_format="datetime",
        x_limits=x_limits,
        x_axis_ticks_format="%d-%m %H",
        tick_rotation=90,
        interval=1, #hours of tick interval x
        grid=True,
        show_plot=False,
        y_labels=[None for _ in range(len(variable_groups))],  # No y-axis labels for subplots
        legend_param={"loc": "upper left"},
        # vertical_lines=[model.integrator_parameters['start_timestamp'] for _ in range(len(variable_groups))],
        colors={"setpoint":["violet" for _ in range(len(variable_groups[1]))], 
                "df_model_past":["orange"]},
        alphas={"setpoint":[1, 1, 0.5, 0.5], "contol_outputs": [1, 2, 1, 1]},
        # markers={
        #     "data_on": [None, None, None, None],  # Markers for variables from "data_on"
        #     "AM2HN": [None, None, None, None]    # Markers for variables from "AM2HN"
        # },
        # y_ticks = [4,4,4,4],
        linestyles={'setpoint': ['--' for _ in range(len(variable_groups[1]))],},
        y_limits=[(10, 70), (0.5, 1.5), (saturation_low*1e6+nominal_u-1, saturation_high*1e6+nominal_u+1), 
                    (df_state_header[['u_p','u_i','control_signal']].min().min()*0.9, df_state_header[['u_p','u_i','control_signal']].max().max()*1.1), 
                    (df_state_follower[['u_p','u_i','control_signal']].min().min()*0.9, df_state_follower[['u_p','u_i','control_signal']].max().max()*1.1),
                ],
    )
    output_path = os.path.join(directory, testname, 'Selector',f'plots')

    # Create the output directory if it does not exist
    os.makedirs(os.path.dirname(output_path), exist_ok=True)

    # Save the figure
    plt.savefig(os.path.join(output_path, f"R{modelname}_{date_string}_selector.png"), bbox_inches='tight', dpi=300)
    # Log the output path
    logger.info(f"Plot saved to {output_path}")
    # ------------------------------------------------------------------------------------------------------------------- #
    logger.info('############################################### END SELECTOR MAIN ###############################################')

if __name__ == "__main__":
    # Allow the script to be executed from the terminal with command-line arguments
    parser = argparse.ArgumentParser(description="Run SelectorPI_controller_operative.")
    parser.add_argument("modelname", type=str, help="Model name (e.g., '1' or '2').")
    parser.add_argument(
        "--now", type=str, default=None, 
        help="Optional datetime in the format 'YYYY-MM-DD HH:MM:SS'. Defaults to the current time."
    )
    args = parser.parse_args()

    modelname = args.modelname
    now = datetime.strptime(args.now, "%Y-%m-%d %H:%M:%S") if args.now else datetime.now()
    main(modelname, now)
