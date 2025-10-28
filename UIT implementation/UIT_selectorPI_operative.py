#!/usr/bin/env python
# coding: utf-8
'''
### Biomethane production Optimal Control with the 'Selector-PI' feedback online controller (Biogoals.Select tool)
**Authors:** Davide Carecci  
**Created:** February 2024  
**Last Modified:** October 28, 2025  
**Version:** 1.1  
**Institution:** Politecnico di Milano  
#### Revision History

| Date       | Version | Author(s)              | Description                                                                       |
|------------|---------|------------------------|-----------------------------------------------------------------------------------|
| 2024-01-31 | 1.0     | D. Carecci             | Initial implementation for experimental validation over the UIT machine           |
| 2025-10-28 | 1.1     | D. Carecci             | Code and folder cleaning and documentation for handle over a copy to A2A S.p.A    |
'''
# In[1]: IMPORT STANDARD LIBRARIES
import pandas as pd
import os
from datetime import datetime, timedelta
import matplotlib.pyplot as plt
import numpy as np
import sys

# In[2]: IMPORT CUSTOM LIBRARIES
from general_utils.extract_nearest_row import extract_nearest_row
from general_utils.old_uit_functions import *
sys.path.insert(0, 'C:\\Users\\lenovo\\OneDrive - Politecnico di Milano\\Work_cloud\\DOTTORATO\\Sperimentazione UIT\\SelectorPI controller') #Add to PATH the path of the SelectorPI_controller.py file
from SelectorPI_controller import PIController_uit, HysteresisComparator_uit

# In[3]: FIND THE 'num_recent_files'-MOST RECENT DAYS OF DATA FILES AND READ THEM
num_recent_files = 2
reactor_number = 2 # Specify reactor number (1 or 2)
reactor = f'R{reactor_number}'
directory_path = f'C:\\Users\\lenovo\\OneDrive - Politecnico di Milano\\Work_cloud\\DOTTORATO\\Sperimentazione UIT\\Software\\{reactor}'
recent_csv_files, success_find_data, warning_find_data = find_csv_file_paths(directory_path, num_recent_files)
# Define current date for logging
log_date = datetime.now().strftime('%Y-%m-%d')

# Concatenate the two dataframes into one, called 'combined_dataframe'
try:
    today, success_read_data = read(recent_csv_files[0])
    yesterday, success_read_data = read(recent_csv_files[1])
    combined_dataframe = pd.concat([yesterday,today], ignore_index=True)
    # Calculate mean and standard deviation of dataset (not strictly necessary)
    mean_R2 = combined_dataframe['gas_rate_out_ma'].mean()
    stdev_R2 = combined_dataframe['gas_rate_out_ma'].std()
    print(f"""dataset_gas_rate_mean = {mean_R2}, dataset_gas_rate_mean = {stdev_R2}""")
    error_read_data = 'No'
except Exception as e:
    print(e)
    error_read_data = e

# ------------------------------------------------------------------------------------------------------------------- #
# In[4]: CODE FOR OUTLIER DETECTION AND REPLACEMENT
# It finds the data points with Z-score > threshold
# Substitutes those data point with a linear interpolation between the previous and the next 'non-outlier' data points
threshold = 6  # Define your threshold for Z-score (recommended from 3 to 6; higher if discontinuous mixing of the reactor)
try:
    rate = f'{reactor_number}F1.1 [L/h]' # Gas rate (L/h)
    ch4 = f'{reactor_number}X11Q3 [V% CH4]' # Methane percentage in gas (V%)
    co2 = f'{reactor_number}X11Q2 [V% CO2]' # Carbon dioxide percentage in gas (V%)
    # Compute Z-score
    combined_dataframe['Z-score_rate'] = np.abs((combined_dataframe[rate] - combined_dataframe[rate].mean()) / combined_dataframe[rate].std())
    combined_dataframe['Z-score_ch4'] = np.abs((combined_dataframe[ch4] - combined_dataframe[ch4].mean()) / combined_dataframe[ch4].std())
    combined_dataframe['Z-score_co2'] = np.abs((combined_dataframe[co2] - combined_dataframe[co2].mean()) / combined_dataframe[co2].std())
    # Find indices of outliers
    outlier_indices_rate = np.where(combined_dataframe['Z-score_rate'] > threshold)[0]
    outlier_indices_ch4 = np.where(combined_dataframe['Z-score_ch4'] > threshold)[0]
    outlier_indices_co2 = np.where(combined_dataframe['Z-score_co2'] > threshold)[0]
    # Create a new column 'interpolated_data' with the original data
    combined_dataframe[f'{reactor_number}F1.1 [L/h]_out'] = combined_dataframe[rate]
    combined_dataframe[f'{reactor_number}X11Q3 [V% CH4]_out'] = combined_dataframe[ch4]
    combined_dataframe[f'{reactor_number}X11Q2 [V% CO2]_out'] = combined_dataframe[co2]
    # Replace outliers with linear interpolation
    interpolated_values_list_rate = []
    interpolated_values_list_ch4 = []
    interpolated_values_list_co2 = []
    # Loop over each outlier index for gas rate
    for idx in outlier_indices_rate:
        prev_idx = idx-1
        while prev_idx in outlier_indices_rate:
            prev_idx = prev_idx-1
        next_idx = idx+1
        while next_idx in outlier_indices_rate:
            next_idx = next_idx+1
        interpolated_value = combined_dataframe.at[prev_idx, f'{reactor_number}F1.1 [L/h]_out'] + ((idx - prev_idx) * (combined_dataframe.at[next_idx, f'{reactor_number}F1.1 [L/h]_out'] - combined_dataframe.at[prev_idx, f'{reactor_number}F1.1 [L/h]_out'])) / (next_idx - prev_idx)
        interpolated_values_list_rate.append(prev_idx)
        combined_dataframe.at[idx, f'{reactor_number}F1.1 [L/h]_out'] = interpolated_value
    # Loop over each outlier index for ch4 percentage
    for idx in outlier_indices_ch4:
        prev_idx = idx-1
        while prev_idx in outlier_indices_ch4:
            prev_idx = prev_idx-1
        next_idx = idx+1
        while next_idx in outlier_indices_ch4:
            next_idx = next_idx+1
        interpolated_value = combined_dataframe.at[prev_idx, f'{reactor_number}X11Q3 [V% CH4]_out'] + ((idx - prev_idx) * (combined_dataframe.at[next_idx, f'{reactor_number}X11Q3 [V% CH4]_out'] - combined_dataframe.at[prev_idx, f'{reactor_number}X11Q3 [V% CH4]_out'])) / (next_idx - prev_idx)
        interpolated_values_list_ch4.append(prev_idx)
        combined_dataframe.at[idx, f'{reactor_number}X11Q3 [V% CH4]_out'] = interpolated_value
    # Loop over each outlier index for co2 percentage
    for idx in outlier_indices_co2:
        prev_idx = idx-1
        while prev_idx in outlier_indices_co2:
            prev_idx = prev_idx-1
        next_idx = idx+1
        while next_idx in outlier_indices_co2:
            next_idx = next_idx+1
        interpolated_value = combined_dataframe.at[prev_idx, f'{reactor_number}X11Q2 [V% CO2]_out'] + ((idx - prev_idx) * (combined_dataframe.at[next_idx, f'{reactor_number}X11Q2 [V% CO2]_out'] - combined_dataframe.at[prev_idx, f'{reactor_number}X11Q2 [V% CO2]_out'])) / (next_idx - prev_idx)
        interpolated_values_list_co2.append(prev_idx)
        combined_dataframe.at[idx, f'{reactor_number}X11Q2 [V% CO2]_out'] = interpolated_value
    # Updated time series data with outliers replaced by interpolated values
    updated_time_series_rate = combined_dataframe[f'{reactor_number}F1.1 [L/h]_out']
    updated_time_series_ch4 = combined_dataframe[f'{reactor_number}X11Q3 [V% CH4]_out']
    updated_time_series_co2 = combined_dataframe[f'{reactor_number}X11Q2 [V% CO2]_out']
    error_outlier = 'No'
except Exception as e:
    error_outlier = e
    print(e)
    # Return columns that are recalled later in the script equal to the original signal
    combined_dataframe[f'{reactor_number}F1.1 [L/h]_out'] = combined_dataframe[rate]
    combined_dataframe[f'{reactor_number}X11Q3 [V% CH4]_out'] = combined_dataframe[ch4]
    combined_dataframe[f'{reactor_number}X11Q2 [V% CO2]_out'] = combined_dataframe[co2]

# ------------------------------------------------------------------------------------------------------------------- #
# In[5]: CALCULATE METHANE FLOW RATE AND GAS RATIO. EXTRACT DATA AT THE CURRENT TIMESTAMP OF RUN 
# Calculate methane flowrate ('ch4_rate') and gas ratio ('ratio') as ch4/co2
try:
    rate = f'{reactor_number}F1.1 [L/h]_out' # Gas rate (without outliers)
    ch4 = f'{reactor_number}X11Q3 [V% CH4]_out' # Methane percentage in gas (without outliers)
    co2 = f'{reactor_number}X11Q2 [V% CO2]_out' # Carbon dioxide percentage in gas (without outliers)
    combined_dataframe['ch4_rate'] = combined_dataframe[rate]*combined_dataframe[ch4]/100
    # If there are values with co2% = 0, return 0 for that time instant. Identify rows where 'co2' column is 0
    zero_value_rows = combined_dataframe[combined_dataframe[co2] == 0]
    null_values_msg = 'Yes' if combined_dataframe[co2].any() == 0 else 'No'
    print("Timestamps corresponding to rows with 'co2' = 0:") # Print the corresponding 'timestamp' values
    print(zero_value_rows['Timestamp'].tolist())
    combined_dataframe['gas_ratio'] = np.where(combined_dataframe[co2] == 0, 0, combined_dataframe[ch4]/combined_dataframe[co2])
    error_calc = 'No'
except Exception as e:
    error_calc = e
    print(e)

# Extract data point for the current control step (last row of the read CSV files)
try:
    last_row = combined_dataframe.iloc[-1]
    current_time = last_row['Timestamp']
    measure1 = last_row['filtered_ch4_rate']
    measure2 = 1/last_row['filtered_ratio'] if last_row['filtered_ratio'] != 0 else 0.842 # Value taken from "optim_ss" simulation of 26.01.2024
    meas_error = 'No error in reading meas from dataframe'
except Exception  as e:
    print(e)
    meas_error = e

# ------------------------------------------------------------------------------------------------------------------- #
# In[6]: MOVING AVERAGE OF DATA (TO BUFFER THE DISCONTINUOUS MIXING-'pulsed' BEHAVIOUR)
window_size = 30 # minutes (Suggestion: must contains at least two consequent mixing cycles).
combined_dataframe['filtered_gasrateoriginal'],filter_error = moving_average_filter(combined_dataframe[f'{reactor_number}F1.1 [L/h]'], window_size)
combined_dataframe['filtered_gas_rate'], filter_error = moving_average_filter(combined_dataframe[f'{reactor_number}F1.1 [L/h]_out'], window_size)
combined_dataframe['filtered_ch4_rate'],filter_error = moving_average_filter(combined_dataframe['ch4_rate'], window_size)
# combined_dataframe['filtered_ratio'],filter_error = moving_average_filter(combined_dataframe['gas_ratio'], window_size) # Better to avoid filtering ratio since it is a discrete signal due to gasbag presence

# In[7]: PLOT THE RESULTS (and past results)
# Plotting the results: GAS RATE
save_directory = os.path.join(os.getcwd(), 'Figures')
try:
    fig,ax = plt.subplots(figsize=(10, 5))
    plt.plot(combined_dataframe['Timestamp'],combined_dataframe[f'{reactor_number}F1.1 [L/h]'], label='Original gas rate signal')
    plt.plot(combined_dataframe['Timestamp'],combined_dataframe[f'{reactor_number}F1.1 [L/h]_out'], label=f'Gas rate without outliers')
    plt.plot(combined_dataframe['Timestamp'],combined_dataframe['filtered_gas_rate'], label=f'Gas rate moving average (window_size={window_size})')
    ax = plt.gca()
    plt.xticks(rotation=90)
    plt.legend()
    plt.show()
    plot_file_name = f"gas_rate_{datetime.now().strftime('%Y%m%d_%H%M%S')}.png"
    fig.savefig(f"{save_directory}\\{plot_file_name}")
    plt.close(fig)  # Close the plot to free up resources
except Exception as e:
    print(e)
# Plotting the results: CH4 RATE
try:
    fig,ax = plt.subplots(figsize=(10, 5))
    plt.plot(combined_dataframe['Timestamp'],combined_dataframe['ch4_rate'], label=f'Computed methane rate')
    plt.plot(combined_dataframe['Timestamp'],combined_dataframe['filtered_ch4_rate'], label=f'Methane rate moving average (window_size={window_size})')
    plt.xticks(rotation=90)
    plt.legend()
    plt.show()
    plot_file_name = f"ch4_rate_{datetime.now().strftime('%Y%m%d_%H%M%S')}.png"
    fig.savefig(f"{save_directory}\\{plot_file_name}")
    plt.close(fig)  # Close the plot to free up resources
except Exception as e:
    print(e)
# Plotting the results: RATIO co2/ch4
try:
    fig,ax = plt.subplots(figsize=(10, 5))
    plt.plot(combined_dataframe['Timestamp'],1/combined_dataframe['gas_ratio'], label=f'Computed gas ratio')
    plt.plot(combined_dataframe['Timestamp'],1/combined_dataframe['filtered_ratio'], label='Gas ratio moving average (window_size={window_size})')
    ax = plt.gca()
    plt.xticks(rotation=90)
    plt.legend()
    plt.show()
    plot_file_name = f"gas_ratio_{datetime.now().strftime('%Y%m%d_%H%M%S')}.png"
    fig.savefig(f"{save_directory}\\{plot_file_name}")
    plt.close(fig)  # Close the plot to free up resources
except Exception as e:
    print(e)

# ------------------------------------------------------------------------------------------------------------------- #
# In[8]: LOAD THE INPUT DATA FILES FROM CSV (SETPOINTS)
# Read setpoints from CSV file for the current control step (nearest row with respect to 'current_time')
setpoints_file_path = os.path.join(os.getcwd(), 'setpoint_31.01.2024.csv')
try:
    setpoints = read_csv_with_column_names(setpoints_file_path)
    setpoints['Timestamp'] = pd.to_datetime(setpoints['Timestamp'], format="%Y-%m-%d %H:%M:%S")
    print("Setpoints loaded")
    # Extract row nearer to the current running time or last timestamp of the data files
    setpoints_row = extract_nearest_row(setpoints, current_time)
    setpoint_error = 'No'
except Exception  as e:
    print(e)
    setpoint_error = e
    setpoint_row = {'Setpoint1':measure1,'Setpoint2':measure2, # Replace with a float if constant setpoint is desired
                    'TresholdLow':measure2+0.05,'TresholdHigh':measure2+0.1}
setpoint1 = setpoints_row['Setpoint1']
setpoint2 = setpoints_row['Setpoint2'] 
threshold_low = setpoints_row['TresholdLow'] 
threshold_high = setpoints_row['TresholdHigh']
if setpoint2 > threshold_low or threshold_low > threshold_high:
    print('Uncorrect relation between setpoint2 and tresholds')

# Log for "boundary" conditions of the controller computations for the current evaluation
data_filepath = os.path.join(os.getcwd(), 'Output', f'Boundary_calc_conditions_{log_date}.csv') # Remove 'log_date' to filename if desired to create a unique file instead of one for each day
new_row_data = {'Timestamp_setpoints':setpoints_row['Timestamp'],'Timestamp_measures':current_time,
                'ch4_setpoint':setpoint1, 'ch4_measure':measure1,
                'co2/ch4_setpoint':setpoint2, 'co2/ch4_measure':measure2,
                'threshold_low':threshold_low,'threshold_high':threshold_high}
append_row_to_csv(data_filepath, new_row_data)

# ------------------------------------------------------------------------------------------------------------------- #
# In[9]: COMPUTE ERRORS, INSTANTIATE CONTROLLERS AND LOAD PAST CONTROLLER STATE
# Compute the control errors
error1 = setpoint1 - measure1
error2 = setpoint2 - measure2
dt = 2.5*3600  # Specify control interval (in seconds). Must be consistent with the frequency of code execution.
# Define controller parameters
saturation_high = 300/1e6 # Control action flow rate (in mL/day converted to m^3/s)
saturation_low = -95/1e6 # Control action flow rate (in mL/day converted to m^3/s)
kp1 = 0.00136
kp2 = 0.004574
Ti1 = 144644 # In seconds
Ti2 = 92283 # In seconds

# Set filenames for saving/loading controller states
output_filename_header = 'State_header'
output_filename_follower = 'State_follower'
try:
    #Initialize the PI controllers controllers from the 'PIController' class (defined in SelectorPI_controller.py)
    controller1 = PIController_uit(name = "Header", kp = kp1, ki = kp1/Ti1, saturation_low =saturation_low, saturation_high = saturation_high, saturate_integral=False)
    controller2 = PIController_uit(name = "Follower", kp = kp2, ki = kp2/Ti2, saturation_low = saturation_low, saturation_high = saturation_high, saturate_integral=False)
    # Load the state from the previous run (last saved state)
    controller1.load_state(log_date, filename=os.path.join(os.getcwd(), 'Output', f"{output_filename_header}_{log_date}.csv"))
    controller2.load_state(log_date, filename=os.path.join(os.getcwd(), 'Output', f"{output_filename_header}_{log_date}.csv"))
    controller_error = 'No'
except Exception as e:
    print(e)
    controller_error = e

# ------------------------------------------------------------------------------------------------------------------- #
# In[10]: SELECTION OF THE ACTIVE CONTROLLER (and eventual override)
# Defines a boolean 'condition' = state of the hysteresis comparator function. When 'edge' of 'condition', override is triggered
# Extract previous condition from the last log entry
try:
    if not controller2.log_df.empty:
     controller2.log_df.loc[controller2.log_df.index[-1],'selection'] = controller2.log_df.at[controller2.log_df.index[-1],'selection'] == 'True'
    prev_condition = controller2.log_df.iloc[-1]['selection'] if not controller2.log_df.empty else False # At control initialization (k=0), set 'prev_condition' to False

    # Update the hysteresis comparator state with the current measurement2 ('co2/ch4 ratio')
    hysteresis_comp = HysteresisComparator_uit(threshold_low=threshold_low, threshold_high=threshold_high)
    condition = hysteresis_comp.update(measure2)

    # Check for the edge condition change: if so and False->True, override and activate controller2; if True->False, override and activate controller1
    if condition != prev_condition and prev_condition == False:
        # Compute the desired value for the override of the integrator in case of edge condition change
        desired_value_controller2 = (float(controller1.log_df.iloc[-1]['control_signal'])-controller2.kp*error2)/controller2.ki if not controller1.log_df.empty else 0
        # Override the state of the inactive->active controller to be consistent with the current control action
        controller2.reset_state(desired_value_controller2)
    if condition != prev_condition and prev_condition == True:
        # Compute the desired value for the override of the integrator in case of edge condition change
        desired_value_controller1 = (float(controller2.log_df.iloc[-1]['control_signal'])-controller1.kp*error1)/controller1.ki if not controller2.log_df.empty else 0
        # Override the state of the inactive->active controller to be consistent with the current control action
        controller1.reset_state(desired_value_controller1)
    reinit_error = 'No'
except Exception as e:
    print(e)
    reinit_error = e

# ------------------------------------------------------------------------------------------------------------------- #
# In[11]: COMPUTATION OF THE CONTROL ACTION (FOR BOTH CONTROLLERS) AND SELECTION OF THE FINAL CONTROL ACTION
# Calculate the control signal for both controllers
try:
    control_output1 = controller1.compute(error1, dt, not condition) # In m^3/s
    control_output2 = controller2.compute(error2, dt, condition) # In m^3/s

    # Save the state of controllers for the next run
    controller1.save_state(log_date, filename=os.path.join(os.getcwd(), 'Output', f"{output_filename_header}_{log_date}.csv"))
    controller2.save_state(log_date, filename=os.path.join(os.getcwd(), 'Output', f"{output_filename_header}_{log_date}.csv"))

    # Switch: choose between the two control signals based on the condition
    final_control_signal = control_output2 if condition else control_output1 # If condition, the 'co2/ch4 ratio' controller is active and its control signal is selected
    selector_error = 'No'
except Exception as e:
    selector_error = e
    print(e)

# ------------------------------------------------------------------------------------------------------------------- #
# In[12]: CONVERT FLOAT CONTROL ACTION TO ON/OFF INTERVAL DURATION FOR THE PERISTALTIC PUMPS
# Move from daily load (mL/day) to on/off interval duration of peristaltic pumps control
on_minutes_nominal = 1 # Nominal control action load (in min/control interval)
pump_dose_per_minute = 10 # Flow rate of the peristaltic pump (in mL/min)
try:
    required_volume = final_control_signal*1e6/(24*60*60)*dt # Difference of control action from the initial/nominal load (in mL/day)
    max_on_minutes_delta = int(saturation_high*1e6/(24*60*60)*dt/pump_dose_per_minute) # Only for precaution/safety purposes as a double-check
    on_minutes_delta = max(-1, min(int(required_volume / pump_dose_per_minute), max_on_minutes_delta)) # Difference of 'on' minutes from the nominal load (in min/control interval)
    on_minutes_tot = on_minutes_delta + on_minutes_nominal # Total amount of 'on' minutes within the control interval
    minutes_in_dt = dt/60 # Amount of minutes within the control time interval ('dt' in seconds)
    if on_minutes_tot > 0:
        dosing_interval = int(minutes_in_dt/on_minutes_tot) # Divide control interval in equal 'on_minutes_tot' fractions
        on_minutes_ini = 1 # Turn on the pump for one minute/control interval fraction
        off_minutes_ini = dosing_interval - 1
    else:
        dosing_interval = minutes_in_dt # If 'saturationLow', don't turn on pumps for any minute in the control interval
        on_minutes_ini = 0
        off_minutes_ini = dosing_interval

    # Compute values to be placed in .ini file (range 0...86400 seconds)
    on_seconds_ini = max(0, min(on_minutes_ini*60,86400))
    off_seconds_ini = max(0, min(off_minutes_ini*60,86400))
    on_seconds_actual = 60 if on_seconds_ini > 60 else on_seconds_ini
    off_seconds_actual = 9000 if off_seconds_ini > 9000 else off_seconds_ini
    conversion_error = 'No'
except Exception as e:
    conversion_error = e
    print(e)

# Summary log to CSV file for main outputs of this run
output_filepath = os.path.join(os.getcwd(), 'Output', f'Output_selector_{log_date}.csv')
active_controller_name = controller2.name if condition else controller1.name
new_row_output = {'active':active_controller_name, 'ch4_error': error1, 'co2/ch4_error': error2, 
                  'c2/ch4-Trlow': measure2 - threshold_low, 'co2/ch4_TrHigh':measure2 - threshold_high, 
                  'final_control_signal':final_control_signal, 'on_minutes_tot':on_minutes_tot,
                  'on_seconds_ini':on_seconds_ini,'off_seconds_ini':off_seconds_ini
                 }
append_row_to_csv(output_filepath, new_row_output)

# ------------------------------------------------------------------------------------------------------------------- #
# In[13]: FIND THE LAST AVAILABLE CONFIGURATION ".INI" FILE AND UPDATE IT
input_directory = os.path.join(os.getcwd(), 'Bioreactor') # Find it in...
output_directory =  os.path.join(os.getcwd(), 'Bioreactor') # Update it and save to...
copy_directory = os.path.join(os.getcwd(), 'Output') # And a copy to... 
# Update the .ini file with the new 'on' and 'off' seconds for the peristaltic pumps
try:
    input_config_file_path, success_find_ini, warning_find_ini = load_closest_ini_file(input_directory)
    write_success_update = update_ini_file(input_config_file_path, copy_directory, output_directory, on_seconds_actual, off_seconds_actual)
except Exception as e:
    write_success_update = 'No update of .ini files becouse error in updating'
print(write_success_update)

# ------------------------------------------------------------------------------------------------------------------- #
# In[14]: SUMMARY LOG OF WARNING, ERRORS AND SUCCESS MESSAGES
# Creates a txt in append mode for the current log_date. Logs the messages along with the current timestamp to a text file
log_file_path = os.path.join(os.getcwd(), 'Output', f"log_{datetime.now().strftime('%Y-%m-%d')}.txt")
log_message = f""" \n --------------------------------------------------------------------------------------------------------------------------------------- \n
{datetime.now()} \n
1 - {warning_find_data}. \n
1 - {success_find_data}. \n
2 - {success_read_data}. If failed, returning empty dataframe. \n
2 - {error_read_data}. \n
3 - {error_outlier}. If 'Yes', returning original data. \n
4 - {error_calc}. \n
5 - {filter_error}. \n
6 - {meas_error}. \n
7 - {setpoint_error}. \n
8 - {controller_error}. \n
9 - {reinit_error}. \n
10 - {selector_error}. \n
11 - {conversion_error}. \n
12 - {success_find_ini}. \n
12 - {warning_find_ini}. \n
13 - {write_success_update}."""
with open(log_file_path, 'a') as log_file:
    log_file.write(log_message)

