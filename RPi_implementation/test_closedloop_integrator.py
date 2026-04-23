'''
Test test_closedloop_integrator.py and RPi_selectorPI_operative.py in 'test_closedloop.ipynb' >> store everthing inside the 'testname' folder.
Here modify manually: 
    1. the path to the files to be loaded and for saving the results
    2. 'modelname', 'testname', 'save_out', 'final_challange' and 'path_to_agriacodm' variables
    3. the inorganic carbon concentration inside the feedstocks ('sic') (set this equal to the values computed by the Modelica model).
    4. the level of noise added to the integrator outputs before saving them as measurements
'''
# In[1]: IMPORT STANDARD LIBRARIES
import numpy as np
import logging
import os
import pandas as pd
from datetime import datetime, timedelta
import ast
import sys

#------------------------------------------------------------------------------------------------------------#
# In[2]: IMPORT CUSTOM LIBRARIES
# Common functions from the 'NMPC' library
from general_utils.read_file import*
from general_utils.save_df import*
from general_utils.sample_and_create_df import sample_df
from general_utils.udm_gas_conversion import udm_gas_conversion
from general_utils.modelica_integrator import modelica_integrator
from general_utils.save_combi import save_combi
from general_utils.process_parameters import update_parameters
#Add to PATH the path of the model_input.py and model_read_file.py files (where the B.Twin library was installed, see test_closedloop.ipynb)
path_to_twin_library = 'C:\\Users\\lenovo\\OneDrive - Politecnico di Milano\\Work_cloud\\DOTTORATO\\Sperimentazione MPC\\NMPC'
sys.path.insert(0, path_to_twin_library)
from model_input import prepare_model_inputs
from model_read_file import read_all

#------------------------------------------------------------------------------------------------------------#
# In[3]: DECLARE THE MAIN FUNCTION (ALLOW TO CALL IT FROM OTHER SCRIPTS) AND SETUP LOGGER
def main():
    ''' Main function to run the ADM1 integrator in closed loop with the SelectorPI controller.
    Wrapped in a main() function to allow calling from other scripts (e.g., test_closedloop.ipynb).
    '''
    # DECLARE SIMULATION META-OPTIONS
    save_out = False # If True, saves some additional load and feedstock characterization data in some files in 'directory/testname' for checking purposes
    final_challange = True # If True, reads the trapezoid reduction from 'fake_theta_reduction.csv' and applies it to the integrator inputs (see IEEE CDC 2025 paper).
    modelname = '1' # Must be the same as in the test_closedloop.ipynb for the main function call of RPi_selectorPI_operative.py
    directory = os.getcwd() # Modify if this code from another directory with respect to where the input and output files are stored and willing to be saved
    testname = 'Test_closedloop' # If there is a specific test subfolder name of the <directory>, specify it here (e.g., '/Test_closedloop')
    path_to_agriacodm = 'C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Modelling/Pilot_plant/' # Path to the B.Agri_AcoDM library
    
    #------------------------------------------------------------------------------------------------------------#
    # DECLARE LOGGER
    # Configure logging
    log_directory = os.path.join(directory, testname, "logs") # A subfolder 'logs' is created inside the test folder
    os.makedirs(log_directory, exist_ok=True)
    log_file = os.path.join(log_directory, 'integrator_logging.log') # Specify the log file name
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
    # if not logger.handlers:  # Avoid duplicate handlers
    # Console handler for displaying logs in the terminal
    # console_handler = logging.StreamHandler()
    # console_handler.setLevel(logging.INFO)
    # console_formatter = logging.Formatter('%(levelname)s - %(message)s')
    # console_handler.setFormatter(console_formatter)
    # # Add handlers to the logger
    # logger.addHandler(console_handler)
    logger.setLevel(logging.INFO)
    logger.info('############################################### START INTEGRATOR MAIN ###############################################')

    #------------------------------------------------------------------------------------------------------------#
    # READ ALL INPUTS
    modelica_states_storage_filename = 'States_agriAcoDM_real' # File where the ADM1 integrator states are stored for next initialization. Needed to set initial states in the Modelica integrator.
    maize, cowslurry, tomatosauce, d_flow, u_flow, init_integrator, theta= read_all(os.path.join(directory, testname), # Set directory from now on
                                [], # Add path to PATH if needed
                                os.path.join(directory, testname, 'Input\\'), # Input path (where the most of the filenames below are located)
                                ['parameters_update.json', 'integrator.json'], # parameters_update.json is actually not needed, the file can be empty. integrator.json is important
                                [f'Manual_flowrates_real_R1.csv', f'{modelname}_u_actual.csv', # Needed to set current loads in the Modelica integrator
                                'MaizeSilage_comp_raw.csv','CowSlurry_comp_raw.csv', 'TomatoSauce_comp_raw.csv', # Read just to make prepare_model_inputs work
                                f'{modelica_states_storage_filename}.csv']) # Needed to set initial states in the Modelica integrator
    integrator_parameters = theta['integrator_parameters']
    integrator_parameters['model']['start_timestamp'] = datetime.strptime(integrator_parameters['model']['start_timestamp'], "%Y-%m-%d %H:%M:%S")
    integrator_parameters['model']['end_timestamp'] = datetime.strptime(integrator_parameters['model']['end_timestamp'], "%Y-%m-%d %H:%M:%S")

    #------------------------------------------------------------------------------------------------------------#
    # READ TRAPEZOID REDUCTION (if there is a time-varying fake parameter disturbance e.g. the once described in the IEEE CDC 2025 paper)
    if final_challange:
        trapezoid_df_all = read_csv_file(os.path.join(directory, testname, 'Input', 'fake_theta_reduction.csv'), log = True)

    #------------------------------------------------------------------------------------------------------------#
    # PREPARE INPUTS FOR THE MODELICA INTEGRATOR
    integrator_inputs = prepare_model_inputs(modelname, maize, cowslurry, tomatosauce, d_flow, u_flow, init_integrator['x_model'], integrator_parameters['model'], 
                                        mult_factors = [86400/300, 86400/300, 1], fill_option=['first_row','first_row','first_row'],
                                        save_to_csv=save_out, sic=[0,125,0], output_path = os.path.join(directory, testname))
    flowrates_interval = np.vstack([integrator_inputs[4][:,:-1], integrator_inputs[4][-1,:-1]])
    flowrates_interval = flowrates_interval/86400*(3600/integrator_parameters['model']['mesh_finesse'])
    u_interval = np.vstack([integrator_inputs[4][:,-1:], integrator_inputs[4][-1,-1:]]) # Actually not used by Modelica when there is override of u by u_flow in closed-loop!! u_dict['controlaction'] is read instead.
    time_interval = np.reshape(integrator_inputs[2]*86400, (integrator_inputs[2].shape[0],1)) # In seconds
    disturbance_interval = np.hstack((time_interval, flowrates_interval, u_interval)) # Must have time (first column) in seconds and flowrates in gFM/day !! (not impulsive, pulsed inside the Modelica model).
    # Save to CombiTimeTable for OpenModelica to read it
    disturbance_path = os.path.join(path_to_agriacodm, 'CombiTimeTables', 'disturbance_interval.txt')
    save_combi(disturbance_path, disturbance_interval, ["%.7f","%.7f","%.7f","%.7f"], log=True)
    # Do the same for feedstocks' characteristics
    cowslurry = filter_and_convert_to_time(file_path='/cowslurry', df = cowslurry,
                                start_timestamp=integrator_inputs[1][0], end_timestamp=integrator_inputs[1][-1],
                                fill_option="first_row", log = True)
    maize = filter_and_convert_to_time(file_path='/maize', df = maize,
                                start_timestamp=integrator_inputs[1][0], end_timestamp=integrator_inputs[1][-1],
                                fill_option="first_row", log = True)
    tomatosauce = filter_and_convert_to_time(file_path='/tomatosauce', df = tomatosauce,
                                start_timestamp=integrator_inputs[1][0], end_timestamp=integrator_inputs[1][-1],
                                fill_option="first_row", log = True)
    save_combi(os.path.join(path_to_agriacodm, 'CombiTimeTables', 'Chile', 'disturbance_cowslurry.txt'), cowslurry[1], ["%.7f"] * cowslurry[1].shape[1])
    save_combi(os.path.join(path_to_agriacodm, 'CombiTimeTables', 'Chile', 'disturbance_maize.txt'), maize[1], ["%.7f"] * maize[1].shape[1])
    save_combi(os.path.join(path_to_agriacodm, 'CombiTimeTables', 'Chile', 'disturbance_tomatosauce.txt'), tomatosauce[1], ["%.7f"] * tomatosauce[1].shape[1])

    #------------------------------------------------------------------------------------------------------------#
    # If in open-loop, must modify the reading of 'controlaction' in the Modelica model! Disable it and read directly tomato from combi. 
    # Prepare inputs for ADM1 integrator (closed-loop, the u_dict['controlaction'] is read inside the Modelica model).
    u_dict = {'controlaction':None, 'fake_theta_reduction':0, 'kLa':115/4}
    u_scale_dict = {'controlaction':1, 'fake_theta_reduction':1, 'kLa':1}
    u = u_flow[u_flow['Timestamp']==integrator_parameters['model']['start_timestamp']]['Uk'].iloc[0]
    u_dict['controlaction'] = u
    if final_challange:
        u_dict['fake_theta_reduction'] = trapezoid_df_all[trapezoid_df_all['Timestamp'] == integrator_parameters['model']['start_timestamp']]['fake_theta_reduction'].iloc[0]/1.5
    df = init_integrator['x_model'].applymap(lambda x: None if pd.isna(x) else x) # Does not work when more than one line in dataframe? Alternative: init_integrator['x_model'].replace({np.nan: None})
    x0_adm1_dict = df[df['Timestamp']==integrator_parameters['model']['start_timestamp']].drop(columns=['Timestamp']).to_dict('records')[0]
    x0_extract_names = [f'digester.x[{i}]' for i in range(1, 44+1)] + ['limPID.I.y','gasbag.S_gas_ch4', 'gasbag.S_gas_co2', 'gasbag.S_gas_nh3', 'gasbag.S_gas_h2', 'gasbag.S_gas_n2']    
    output_extract_names = [f'y_gas_noisy[{i}]' for i in range(1, 3+1)] + ['digester.VS_bd_x','digester.acidogens','digester.methanogens',
                                                        'digester.COD_s', 'digester.TVFA', 'digester.Alk',
                                                        'digester.S_ic', 'y_gas[2]', 'digester.VS', 'digester.COD_tot',
                                                        'digester.TAN','digester.pH']
    
    #------------------------------------------------------------------------------------------------------------#
    # CALL MODELICA MODEL (ADM1 INTEGRATOR)
    y_df, x0_adm1_dict = modelica_integrator(os.path.join(path_to_agriacodm, "agriAcoDM.mo"),
                                                        "ADM1_P.Chile_OL_MPC", 
                                                        modelname, 
                                                        u_dict, 
                                                        u_scale_dict, 
                                                        x0_adm1_dict,
                                                        int(3600/integrator_parameters['model']['mesh_finesse']),
                                                        np.round(integrator_inputs[2][0]*86400,2), #seconds
                                                        np.round(integrator_inputs[2][-1]*86400,2), #seconds
                                                        1e-5,
                                                        results_sample_interval = int(3600/integrator_parameters['model']['mesh_finesse']), 
                                                        timestamp_start = integrator_parameters['model']['start_timestamp'],
                                                        x0_extract_names = x0_extract_names,
                                                        path_to_x0_extract = ['Chile'] * len(x0_adm1_dict.keys()),
                                                        path_to_outputs_extract=['','',''] + ['Chile'] * len(output_extract_names[3:]),
                                                        outputs_extract_names = output_extract_names,
                                                        round_params=2)
    # Divide between x_df_adm1 and y_df_adm1 the outputs of the integrator. And rename columns to be consistent with the header of the files used to store data
    y_df_adm1 = y_df[['Timestamp'] + output_extract_names[:3]].copy()
    x_df_adm1 = y_df[['Timestamp'] + output_extract_names[3:]].copy()
    y_df_adm1.columns = ['Timestamp', 'gas_rate', 'xch4_interp', 'xco2_interp'] # The Modelica model gives gas_rate in L/h!!
    x_df_adm1.columns = ['Timestamp', 'VS_bd_x', 'acidog', 'methanog', 'COD_s', 'TVFA', 'Alk', 'Sic', 'xch4', 'VS', 'COD_tot', 'ammonium', 'pH']
    if x_df_adm1['Timestamp'].iloc[-1] != integrator_parameters['model']['end_timestamp']:
        logger.warning('End timestamp of EKF is different from last timestamp from ADM1 integrator. There is some issue with the ADM1 integrator.')
    # Perform some computation of x_df_adm1 if x_adm1 and x_names_adm1 are provided
    x_df_adm1.loc[:, 'Alk-Sic'] = x_df_adm1['Alk']*2/100 - x_df_adm1['Sic']*1000
    x_df_adm1.loc[:, 'TVFA'] = x_df_adm1['TVFA']/60
    x_df_adm1.loc[:, 'COD_tot'] = x_df_adm1['COD_tot']*1000

    #------------------------------------------------------------------------------------------------------------#
    # Save ADM1 states for next run initialization
    x0_adm1_df = pd.DataFrame([x0_adm1_dict])
    x0_adm1_df.insert(0, 'Timestamp', integrator_parameters['model']['end_timestamp']) # Must be equivalent to x_df_adm1['Timestamp'].iloc[-1]
    save_df_with_check(x0_adm1_df,os.path.join(os.getcwd(), "Input", f"{modelica_states_storage_filename}.csv"), log=True)

    #------------------------------------------------------------------------------------------------------------#
    # READ PAST MEASUREMENTS DATA
    y_df_on_path = os.path.join(os.getcwd(), f'{modelname}_y_df_on.txt')
    y_df_off_path = os.path.join(os.getcwd(), f'{modelname}_y_df_off.txt')
    y_df_data_on = pd.read_csv(y_df_on_path, sep=',', header=0, parse_dates=['Timestamp'])
    y_df_data_off = pd.read_csv(y_df_off_path, sep=',', header=0, parse_dates=['Timestamp'])

    # SAVE UPDATED MEASUREMENTS DATA
    # Add noise to ADM1 outputs (5,1,1)% std deviation in this example.
    noise = np.array([np.random.multivariate_normal(mean=np.zeros(3), 
                      cov=(np.array([0.05,0.01,0.01])*np.diag(np.array([64.05209595/78,  0.53790512,  0.46209488])))**2) 
                      for i in range(y_df_adm1.shape[0])])
    y_df_adm1.iloc[:, 1:] = y_df_adm1.iloc[:, 1:].values + noise
    # Avoid override of old meas becouse of new noise to ensure coherence between EKF and stored data: don't take first y (*)
    y_df_adm1.loc[:, 'gas_rate'] = udm_gas_conversion(y_df_adm1['gas_rate'], theta['parameters_other']['T'], theta['parameters_other']['Pt'], theta['parameters_other']['V'], 'Lh') # ADM1 outputs meas in L/h!!!!!!!!!! y of real plant
    y_df_adm1_save = sample_df(y_df_adm1, 1) # Every 1 hour
    x_df_adm1_save = sample_df(x_df_adm1, 1) # Every 1 hour
    save_df(y_df_data_on, y_df_adm1_save.iloc[1:,:], y_df_on_path, log=True) # (*) Don't copy first point
    save_df(y_df_data_off, x_df_adm1_save.iloc[1:, :],
            y_df_off_path, log=True) # (*) Don't copy first point

    #------------------------------------------------------------------------------------------------------------#
    # UPDATE START/END TIMESTAMPS AND SAVE TO INTEGRATOR.JSON 
    integrator_parameters['model']['start_timestamp'] = integrator_parameters['model']['end_timestamp']
    integrator_parameters['model']['end_timestamp'] = integrator_parameters['model']['start_timestamp'] + timedelta(hours=integrator_parameters['controller']['control_interval'])
    update_parameters('integrator.json', integrator_parameters['model'],'model', log=True)
    logger.info('############################################### END INTEGRATOR MAIN ###############################################')

    #------------------------------------------------------------------------------------------------------------#
if __name__ == "__main__":
    # Allow the script to be executed from the terminal
    if len(sys.argv) != 1:
        print("Usage: python test_closedloop_integrator.py <>")
        sys.exit(1)
    main()