/* Main Simulation File */

#if defined(__cplusplus)
extern "C" {
#endif

#include "ADM1_P.Chile_OL_MPC_model.h"
#include "simulation/solver/events.h"

/* FIXME these defines are ugly and hard to read, why not use direct function pointers instead? */
#define prefixedName_performSimulation ADM1_P_Chile_OL_MPC_performSimulation
#define prefixedName_updateContinuousSystem ADM1_P_Chile_OL_MPC_updateContinuousSystem
#include <simulation/solver/perform_simulation.c.inc>

#define prefixedName_performQSSSimulation ADM1_P_Chile_OL_MPC_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c.inc>


/* dummy VARINFO and FILEINFO */
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;

int ADM1_P_Chile_OL_MPC_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_data_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_dataReconciliationInputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_dataReconciliationUnmeasuredVariables(DATA *data, char ** names)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_setc_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_setb_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/*
equation index: 2603
type: SIMPLE_ASSIGN
Chile.tomatosouce.MW[13] = 141.0572488444253
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2603(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2603};
  (data->localData[0]->realVars[1127] /* Chile.tomatosouce.MW[13] variable */) = 141.0572488444253;
  TRACE_POP
}
/*
equation index: 2604
type: SIMPLE_ASSIGN
Chile.slurry.MW[13] = 141.0572488444253
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2604(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2604};
  (data->localData[0]->realVars[949] /* Chile.slurry.MW[13] variable */) = 141.0572488444253;
  TRACE_POP
}
/*
equation index: 2605
type: SIMPLE_ASSIGN
Chile.maize.MW[13] = 141.0572488444253
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2605(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2605};
  (data->localData[0]->realVars[763] /* Chile.maize.MW[13] variable */) = 141.0572488444253;
  TRACE_POP
}
/*
equation index: 2606
type: SIMPLE_ASSIGN
$whenCondition9 = time >= pre(Manual_flowrates.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2606(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2606};
  modelica_boolean tmp0;
  relationhysteresis(data, &tmp0, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1260] /* Manual_flowrates.nextTimeEvent DISCRETE */), 0, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[8] /* $whenCondition9 DISCRETE */) = tmp0;
  TRACE_POP
}
/*
equation index: 2607
type: SIMPLE_ASSIGN
Manual_flowrates.timeScaled = 1.157407407407407e-05 * time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2607(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2607};
  (data->localData[0]->realVars[1237] /* Manual_flowrates.timeScaled variable */) = (1.157407407407407e-05) * (data->localData[0]->timeValue);
  TRACE_POP
}
/*
equation index: 2608
type: WHEN

when {$whenCondition9} then
  Manual_flowrates.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Manual_flowrates.tableID, Manual_flowrates.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2608(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2608};
  if(((data->localData[0]->booleanVars[8] /* $whenCondition9 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[8] /* $whenCondition9 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[4]), (data->localData[0]->realVars[1237] /* Manual_flowrates.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 2609
type: SIMPLE_ASSIGN
Manual_flowrates.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates.tableID, 1, Manual_flowrates.timeScaled, Manual_flowrates.nextTimeEventScaled, pre(Manual_flowrates.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2609(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2609};
  (data->localData[0]->realVars[1238] /* Manual_flowrates.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[4]), ((modelica_integer) 1), (data->localData[0]->realVars[1237] /* Manual_flowrates.timeScaled variable */), (data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2610
type: SIMPLE_ASSIGN
Manual_flowrates.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates.tableID, 2, Manual_flowrates.timeScaled, Manual_flowrates.nextTimeEventScaled, pre(Manual_flowrates.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2610(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2610};
  (data->localData[0]->realVars[1239] /* Manual_flowrates.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[4]), ((modelica_integer) 2), (data->localData[0]->realVars[1237] /* Manual_flowrates.timeScaled variable */), (data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2611
type: SIMPLE_ASSIGN
Manual_flowrates.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates.tableID, 3, Manual_flowrates.timeScaled, Manual_flowrates.nextTimeEventScaled, pre(Manual_flowrates.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2611(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2611};
  (data->localData[0]->realVars[1240] /* Manual_flowrates.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[4]), ((modelica_integer) 3), (data->localData[0]->realVars[1237] /* Manual_flowrates.timeScaled variable */), (data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2612
type: WHEN

when {$whenCondition9} then
  Manual_flowrates.nextTimeEvent = if Manual_flowrates.nextTimeEventScaled < 9.999999999999999e+59 then Manual_flowrates.nextTimeEventScaled * 86400.0 else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2612(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2612};
  modelica_boolean tmp1;
  if(((data->localData[0]->booleanVars[8] /* $whenCondition9 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[8] /* $whenCondition9 DISCRETE */) /* edge */))
  {
    tmp1 = Less((data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1260] /* Manual_flowrates.nextTimeEvent DISCRETE */) = (tmp1?((data->localData[0]->realVars[1261] /* Manual_flowrates.nextTimeEventScaled DISCRETE */)) * (86400.0):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 2613
type: SIMPLE_ASSIGN
Chile.atmosphere.x_nh3 = 0.083145 * Chile.atmosphere.S_gas_nh3 * Chile.atmosphere.T_op_mean / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2613(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2613};
  (data->localData[0]->realVars[184] /* Chile.atmosphere.x_nh3 variable */) = (0.083145) * (((data->localData[0]->realVars[4] /* Chile.atmosphere.S_gas_nh3 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2614
type: SIMPLE_ASSIGN
$DER.Chile.atmosphere.S_gas_nh3 = 1.157407407407407e-17 - Chile.atmosphere.S_gas_nh3 / 86400000000.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2614(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2614};
  (data->localData[0]->realVars[77] /* der(Chile.atmosphere.S_gas_nh3) STATE_DER */) = 1.157407407407407e-17 - (DIVISION_SIM((data->localData[0]->realVars[4] /* Chile.atmosphere.S_gas_nh3 STATE(1) */),86400000000.0,"86400000000.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2615
type: SIMPLE_ASSIGN
Chile.gasbag.p_gas_h2_in = 0.083145 * Chile.digester.S_gas_h2 * Chile.digester.T_op / 16.0388
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2615(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2615};
  (data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */) = (0.083145) * (((data->localData[0]->realVars[27] /* Chile.digester.S_gas_h2 STATE(1) */)) * (DIVISION_SIM((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */),16.0388,"16.0388",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2616
type: SIMPLE_ASSIGN
Chile.digester.rt8 = Chile.digester.kla_h2 * (Chile.digester.S_h2 + (-16.0) * Chile.digester.KH_h2 * Chile.gasbag.p_gas_h2_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2616(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2616};
  (data->localData[0]->realVars[623] /* Chile.digester.rt8 variable */) = ((data->localData[0]->realVars[579] /* Chile.digester.kla_h2 variable */)) * ((data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */) + (-16.0) * (((data->localData[0]->realVars[365] /* Chile.digester.KH_h2 variable */)) * ((data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */))));
  TRACE_POP
}
/*
equation index: 2617
type: SIMPLE_ASSIGN
Chile.gasbag.S_gas_h2_in = 16.0388 * Chile.gasbag.p_gas_h2_in / (0.083145 * Chile.gasbag.T_op_mean)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2617(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2617};
  (data->localData[0]->realVars[652] /* Chile.gasbag.S_gas_h2_in variable */) = (16.0388) * (DIVISION_SIM((data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */),(0.083145) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),"0.083145 * Chile.gasbag.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2618
type: SIMPLE_ASSIGN
Chile.gasbag.p_gas_ch4_in = 0.083145 * Chile.digester.S_gas_ch4 * Chile.digester.T_op / 63.9996
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2618(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2618};
  (data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */) = (0.083145) * (((data->localData[0]->realVars[25] /* Chile.digester.S_gas_ch4 STATE(1) */)) * (DIVISION_SIM((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */),63.9996,"63.9996",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2619
type: SIMPLE_ASSIGN
Chile.digester.rt9 = Chile.digester.kla_ch4 * (Chile.digester.S_ch4 + (-64.0) * Chile.digester.KH_ch4 * Chile.gasbag.p_gas_ch4_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2619(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2619};
  (data->localData[0]->realVars[624] /* Chile.digester.rt9 variable */) = ((data->localData[0]->realVars[577] /* Chile.digester.kla_ch4 variable */)) * ((data->localData[0]->realVars[23] /* Chile.digester.S_ch4 STATE(1) */) + (-64.0) * (((data->localData[0]->realVars[363] /* Chile.digester.KH_ch4 variable */)) * ((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */))));
  TRACE_POP
}
/*
equation index: 2620
type: SIMPLE_ASSIGN
Chile.gasbag.S_gas_ch4_in = 63.9996 * Chile.gasbag.p_gas_ch4_in / (0.083145 * Chile.gasbag.T_op_mean)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2620(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2620};
  (data->localData[0]->realVars[650] /* Chile.gasbag.S_gas_ch4_in variable */) = (63.9996) * (DIVISION_SIM((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */),(0.083145) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),"0.083145 * Chile.gasbag.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2621
type: SIMPLE_ASSIGN
Chile.gasbag.p_gas_co2_in = 0.083145 * Chile.digester.S_gas_co2 * Chile.digester.T_op
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2621(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2621};
  (data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */) = (0.083145) * (((data->localData[0]->realVars[26] /* Chile.digester.S_gas_co2 STATE(1) */)) * ((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */)));
  TRACE_POP
}
/*
equation index: 2622
type: SIMPLE_ASSIGN
Chile.gasbag.S_gas_co2_in = 12.02718143003187 * Chile.gasbag.p_gas_co2_in / Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2622(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2622};
  (data->localData[0]->realVars[651] /* Chile.gasbag.S_gas_co2_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */),(data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),"Chile.gasbag.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2623
type: SIMPLE_ASSIGN
Chile.gasbag.p_gas_nh3_in = 0.083145 * Chile.digester.S_gas_nh3 * Chile.digester.T_op
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2623(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2623};
  (data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */) = (0.083145) * (((data->localData[0]->realVars[29] /* Chile.digester.S_gas_nh3 STATE(1) */)) * ((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */)));
  TRACE_POP
}
/*
equation index: 2624
type: SIMPLE_ASSIGN
Chile.gasbag.S_gas_nh3_in = 12.02718143003187 * Chile.gasbag.p_gas_nh3_in / Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2624(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2624};
  (data->localData[0]->realVars[654] /* Chile.gasbag.S_gas_nh3_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */),(data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),"Chile.gasbag.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2625
type: SIMPLE_ASSIGN
Chile.gasbag.p_gas_n2_in = 0.083145 * Chile.digester.S_gas_n2 * Chile.digester.T_op
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2625(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2625};
  (data->localData[0]->realVars[668] /* Chile.gasbag.p_gas_n2_in variable */) = (0.083145) * (((data->localData[0]->realVars[28] /* Chile.digester.S_gas_n2 STATE(1) */)) * ((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */)));
  TRACE_POP
}
/*
equation index: 2626
type: SIMPLE_ASSIGN
Chile.gasbag.S_gas_n2_in = 12.02718143003187 * Chile.gasbag.p_gas_n2_in / Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2626(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2626};
  (data->localData[0]->realVars[653] /* Chile.gasbag.S_gas_n2_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[668] /* Chile.gasbag.p_gas_n2_in variable */),(data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),"Chile.gasbag.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2627
type: SIMPLE_ASSIGN
Chile.digester.P_gas = Chile.gasbag.p_gas_h2_in + Chile.gasbag.p_gas_ch4_in + Chile.gasbag.p_gas_co2_in + Chile.gasbag.p_gas_h2o + Chile.gasbag.p_gas_nh3_in + Chile.gasbag.p_gas_n2_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2627(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2627};
  (data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */) = (data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */) + (data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */) + (data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */) + (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */) + (data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */) + (data->localData[0]->realVars[668] /* Chile.gasbag.p_gas_n2_in variable */);
  TRACE_POP
}
/*
equation index: 2628
type: SIMPLE_ASSIGN
Chile.limPID.addP.y = Chile.limPID.addP.k1 * Chile.digester.P_gas + Chile.limPID.addP.k2 * Chile.P_ref.k
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2628(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2628};
  (data->localData[0]->realVars[681] /* Chile.limPID.addP.y variable */) = ((data->simulationInfo->realParameter[506] /* Chile.limPID.addP.k1 PARAM */)) * ((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */)) + ((data->simulationInfo->realParameter[507] /* Chile.limPID.addP.k2 PARAM */)) * ((data->simulationInfo->realParameter[1] /* Chile.P_ref.k PARAM */));
  TRACE_POP
}
/*
equation index: 2629
type: SIMPLE_ASSIGN
Chile.limPID.P.y = Chile.limPID.P.k * Chile.limPID.addP.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2629(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2629};
  (data->localData[0]->realVars[679] /* Chile.limPID.P.y variable */) = ((data->simulationInfo->realParameter[496] /* Chile.limPID.P.k PARAM */)) * ((data->localData[0]->realVars[681] /* Chile.limPID.addP.y variable */));
  TRACE_POP
}
/*
equation index: 2630
type: SIMPLE_ASSIGN
Chile.limPID.addPID.y = Chile.limPID.addPID.k1 * Chile.limPID.P.y + Chile.limPID.addPID.k2 * Chile.limPID.Dzero.k + Chile.limPID.addPID.k3 * Chile.limPID.I.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2630(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2630};
  (data->localData[0]->realVars[682] /* Chile.limPID.addPID.y variable */) = ((data->simulationInfo->realParameter[509] /* Chile.limPID.addPID.k1 PARAM */)) * ((data->localData[0]->realVars[679] /* Chile.limPID.P.y variable */)) + ((data->simulationInfo->realParameter[510] /* Chile.limPID.addPID.k2 PARAM */)) * ((data->simulationInfo->realParameter[488] /* Chile.limPID.Dzero.k PARAM */)) + ((data->simulationInfo->realParameter[511] /* Chile.limPID.addPID.k3 PARAM */)) * ((data->localData[0]->realVars[72] /* Chile.limPID.I.y STATE(1) */));
  TRACE_POP
}
/*
equation index: 2631
type: SIMPLE_ASSIGN
Chile.limPID.gainPID.y = Chile.limPID.gainPID.k * Chile.limPID.addPID.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2631(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2631};
  (data->localData[0]->realVars[685] /* Chile.limPID.gainPID.y variable */) = ((data->simulationInfo->realParameter[515] /* Chile.limPID.gainPID.k PARAM */)) * ((data->localData[0]->realVars[682] /* Chile.limPID.addPID.y variable */));
  TRACE_POP
}
/*
equation index: 2632
type: SIMPLE_ASSIGN
Chile.limPID.limiter.u = Chile.limPID.addFF.k1 * Chile.limPID.gainPID.y + Chile.limPID.addFF.k2 * Chile.limPID.FFzero.k
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2632(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2632};
  (data->localData[0]->realVars[687] /* Chile.limPID.limiter.u variable */) = ((data->simulationInfo->realParameter[499] /* Chile.limPID.addFF.k1 PARAM */)) * ((data->localData[0]->realVars[685] /* Chile.limPID.gainPID.y variable */)) + ((data->simulationInfo->realParameter[500] /* Chile.limPID.addFF.k2 PARAM */)) * ((data->simulationInfo->realParameter[490] /* Chile.limPID.FFzero.k PARAM */));
  TRACE_POP
}
/*
equation index: 2633
type: SIMPLE_ASSIGN
Chile.digester.Q_gas = smooth(0, if Chile.limPID.limiter.u > Chile.limPID.limiter.uMax then Chile.limPID.limiter.uMax else if Chile.limPID.limiter.u < Chile.limPID.limiter.uMin then Chile.limPID.limiter.uMin else Chile.limPID.limiter.u)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2633(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2633};
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_real tmp5;
  tmp2 = Greater((data->localData[0]->realVars[687] /* Chile.limPID.limiter.u variable */),(data->simulationInfo->realParameter[519] /* Chile.limPID.limiter.uMax PARAM */));
  tmp4 = (modelica_boolean)tmp2;
  if(tmp4)
  {
    tmp5 = (data->simulationInfo->realParameter[519] /* Chile.limPID.limiter.uMax PARAM */);
  }
  else
  {
    tmp3 = Less((data->localData[0]->realVars[687] /* Chile.limPID.limiter.u variable */),(data->simulationInfo->realParameter[520] /* Chile.limPID.limiter.uMin PARAM */));
    tmp5 = (tmp3?(data->simulationInfo->realParameter[520] /* Chile.limPID.limiter.uMin PARAM */):(data->localData[0]->realVars[687] /* Chile.limPID.limiter.u variable */));
  }
  (data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */) = tmp5;
  TRACE_POP
}
/*
equation index: 2634
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_gas_ch4 = 4.629629629629631e-05 * Chile.digester.rt9 + 0.003858024691358026 * (-Chile.digester.S_gas_ch4) * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2634(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2634};
  (data->localData[0]->realVars[98] /* der(Chile.digester.S_gas_ch4) STATE_DER */) = (4.629629629629631e-05) * ((data->localData[0]->realVars[624] /* Chile.digester.rt9 variable */)) + (0.003858024691358026) * (((-(data->localData[0]->realVars[25] /* Chile.digester.S_gas_ch4 STATE(1) */))) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)));
  TRACE_POP
}
/*
equation index: 2635
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_gas_n2 = 0.003858024691358026 * (-Chile.digester.S_gas_n2) * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2635(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2635};
  (data->localData[0]->realVars[101] /* der(Chile.digester.S_gas_n2) STATE_DER */) = (0.003858024691358026) * (((-(data->localData[0]->realVars[28] /* Chile.digester.S_gas_n2 STATE(1) */))) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)));
  TRACE_POP
}
/*
equation index: 2636
type: SIMPLE_ASSIGN
y_gas_noisy[1] = 41.66666666666666 * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2636(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2636};
  (data->localData[0]->realVars[1248] /* y_gas_noisy[1] variable */) = (41.66666666666666) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */));
  TRACE_POP
}
/*
equation index: 2637
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_gas_h2 = 4.629629629629631e-05 * Chile.digester.rt8 + 0.003858024691358026 * (-Chile.digester.S_gas_h2) * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2637(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2637};
  (data->localData[0]->realVars[100] /* der(Chile.digester.S_gas_h2) STATE_DER */) = (4.629629629629631e-05) * ((data->localData[0]->realVars[623] /* Chile.digester.rt8 variable */)) + (0.003858024691358026) * (((-(data->localData[0]->realVars[27] /* Chile.digester.S_gas_h2 STATE(1) */))) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)));
  TRACE_POP
}
/*
equation index: 2638
type: SIMPLE_ASSIGN
Chile.limPID.addSat.y = Chile.limPID.addSat.k1 * Chile.digester.Q_gas + Chile.limPID.addSat.k2 * Chile.limPID.limiter.u
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2638(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2638};
  (data->localData[0]->realVars[683] /* Chile.limPID.addSat.y variable */) = ((data->simulationInfo->realParameter[513] /* Chile.limPID.addSat.k1 PARAM */)) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)) + ((data->simulationInfo->realParameter[514] /* Chile.limPID.addSat.k2 PARAM */)) * ((data->localData[0]->realVars[687] /* Chile.limPID.limiter.u variable */));
  TRACE_POP
}
/*
equation index: 2639
type: SIMPLE_ASSIGN
Chile.limPID.gainTrack.y = Chile.limPID.gainTrack.k * Chile.limPID.addSat.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2639(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2639};
  (data->localData[0]->realVars[686] /* Chile.limPID.gainTrack.y variable */) = ((data->simulationInfo->realParameter[516] /* Chile.limPID.gainTrack.k PARAM */)) * ((data->localData[0]->realVars[683] /* Chile.limPID.addSat.y variable */));
  TRACE_POP
}
/*
equation index: 2640
type: SIMPLE_ASSIGN
Chile.atmosphere.y[1] = 273.15 * Chile.digester.Q_gas * Chile.digester.P_gas / (Chile.digester.T_op * Chile.digester.P_atm)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2640};
  (data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */) = (273.15) * (((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)) * (DIVISION_SIM((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */),((data->localData[0]->realVars[463] /* Chile.digester.T_op variable */)) * ((data->simulationInfo->realParameter[241] /* Chile.digester.P_atm PARAM */)),"Chile.digester.T_op * Chile.digester.P_atm",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2641
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.S_gas_ch4 = (Chile.gasbag.S_gas_ch4_in - Chile.gasbag.S_gas_ch4) * Chile.atmosphere.y[1] / (86400.0 * Chile.gasbag.V_gasbag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2641};
  (data->localData[0]->realVars[139] /* der(Chile.gasbag.S_gas_ch4) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[650] /* Chile.gasbag.S_gas_ch4_in variable */) - (data->localData[0]->realVars[66] /* Chile.gasbag.S_gas_ch4 STATE(1) */)) * ((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)),(86400.0) * ((data->localData[0]->realVars[71] /* Chile.gasbag.V_gasbag STATE(1) */)),"86400.0 * Chile.gasbag.V_gasbag",equationIndexes);
  TRACE_POP
}
/*
equation index: 2642
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.S_gas_co2 = (Chile.gasbag.S_gas_co2_in - Chile.gasbag.S_gas_co2) * Chile.atmosphere.y[1] / (86400.0 * Chile.gasbag.V_gasbag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2642(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2642};
  (data->localData[0]->realVars[140] /* der(Chile.gasbag.S_gas_co2) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[651] /* Chile.gasbag.S_gas_co2_in variable */) - (data->localData[0]->realVars[67] /* Chile.gasbag.S_gas_co2 STATE(1) */)) * ((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)),(86400.0) * ((data->localData[0]->realVars[71] /* Chile.gasbag.V_gasbag STATE(1) */)),"86400.0 * Chile.gasbag.V_gasbag",equationIndexes);
  TRACE_POP
}
/*
equation index: 2643
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.S_gas_nh3 = (Chile.gasbag.S_gas_nh3_in - Chile.gasbag.S_gas_nh3) * Chile.atmosphere.y[1] / (86400.0 * Chile.gasbag.V_gasbag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2643(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2643};
  (data->localData[0]->realVars[143] /* der(Chile.gasbag.S_gas_nh3) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[654] /* Chile.gasbag.S_gas_nh3_in variable */) - (data->localData[0]->realVars[70] /* Chile.gasbag.S_gas_nh3 STATE(1) */)) * ((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)),(86400.0) * ((data->localData[0]->realVars[71] /* Chile.gasbag.V_gasbag STATE(1) */)),"86400.0 * Chile.gasbag.V_gasbag",equationIndexes);
  TRACE_POP
}
/*
equation index: 2644
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.S_gas_n2 = (Chile.gasbag.S_gas_n2_in - Chile.gasbag.S_gas_n2) * Chile.atmosphere.y[1] / (86400.0 * Chile.gasbag.V_gasbag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2644(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2644};
  (data->localData[0]->realVars[142] /* der(Chile.gasbag.S_gas_n2) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[653] /* Chile.gasbag.S_gas_n2_in variable */) - (data->localData[0]->realVars[69] /* Chile.gasbag.S_gas_n2 STATE(1) */)) * ((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)),(86400.0) * ((data->localData[0]->realVars[71] /* Chile.gasbag.V_gasbag STATE(1) */)),"86400.0 * Chile.gasbag.V_gasbag",equationIndexes);
  TRACE_POP
}
/*
equation index: 2645
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.S_gas_h2 = (Chile.gasbag.S_gas_h2_in - Chile.gasbag.S_gas_h2) * Chile.atmosphere.y[1] / (86400.0 * Chile.gasbag.V_gasbag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2645(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2645};
  (data->localData[0]->realVars[141] /* der(Chile.gasbag.S_gas_h2) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[652] /* Chile.gasbag.S_gas_h2_in variable */) - (data->localData[0]->realVars[68] /* Chile.gasbag.S_gas_h2 STATE(1) */)) * ((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)),(86400.0) * ((data->localData[0]->realVars[71] /* Chile.gasbag.V_gasbag STATE(1) */)),"86400.0 * Chile.gasbag.V_gasbag",equationIndexes);
  TRACE_POP
}
/*
equation index: 2646
type: SIMPLE_ASSIGN
Chile.digester.IC_balance_gas = (-Chile.atmosphere.y[1]) * (0.0156 * Chile.gasbag.p_gas_ch4_in / (Chile.digester.P_gas * 0.350219848723168) + Chile.gasbag.p_gas_co2_in / (22.71105675 * Chile.digester.P_gas) * 1.01325)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2646(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2646};
  (data->localData[0]->realVars[338] /* Chile.digester.IC_balance_gas variable */) = ((-(data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */))) * (DIVISION_SIM((0.0156) * ((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */)),((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */)) * (0.350219848723168),"Chile.digester.P_gas * 0.350219848723168",equationIndexes) + (DIVISION_SIM((data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */),(22.71105675) * ((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */)),"22.71105675 * Chile.digester.P_gas",equationIndexes)) * (1.01325));
  TRACE_POP
}
/*
equation index: 2647
type: SIMPLE_ASSIGN
$DER.Chile.digester.IC_balance_gas_cum = Chile.digester.IC_balance_gas / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2647(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2647};
  (data->localData[0]->realVars[82] /* der(Chile.digester.IC_balance_gas_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[338] /* Chile.digester.IC_balance_gas variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2648
type: SIMPLE_ASSIGN
Chile.digester.IN_balance_gas = (-Chile.atmosphere.y[1]) * Chile.gasbag.p_gas_nh3_in / (22.71105675 * Chile.digester.P_gas) * 1.01325
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2648(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2648};
  (data->localData[0]->realVars[341] /* Chile.digester.IN_balance_gas variable */) = ((-(data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */))) * ((DIVISION_SIM((data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */),(22.71105675) * ((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */)),"22.71105675 * Chile.digester.P_gas",equationIndexes)) * (1.01325));
  TRACE_POP
}
/*
equation index: 2649
type: SIMPLE_ASSIGN
$DER.Chile.digester.IN_balance_gas_cum = Chile.digester.IN_balance_gas / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2649(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2649};
  (data->localData[0]->realVars[85] /* der(Chile.digester.IN_balance_gas_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[341] /* Chile.digester.IN_balance_gas variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2650
type: SIMPLE_ASSIGN
$DER.Chile.digester.Vcum_ch4 = Chile.atmosphere.y[1] * Chile.gasbag.p_gas_ch4_in / Chile.digester.P_gas / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2650(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2650};
  (data->localData[0]->realVars[114] /* der(Chile.digester.Vcum_ch4) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */),(data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */),"Chile.digester.P_gas",equationIndexes)),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2651
type: SIMPLE_ASSIGN
Chile.limPID.addI.y = Chile.limPID.addI.k1 * Chile.digester.P_gas + Chile.limPID.addI.k2 * Chile.P_ref.k + Chile.limPID.addI.k3 * Chile.limPID.gainTrack.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2651(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2651};
  (data->localData[0]->realVars[680] /* Chile.limPID.addI.y variable */) = ((data->simulationInfo->realParameter[502] /* Chile.limPID.addI.k1 PARAM */)) * ((data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */)) + ((data->simulationInfo->realParameter[503] /* Chile.limPID.addI.k2 PARAM */)) * ((data->simulationInfo->realParameter[1] /* Chile.P_ref.k PARAM */)) + ((data->simulationInfo->realParameter[504] /* Chile.limPID.addI.k3 PARAM */)) * ((data->localData[0]->realVars[686] /* Chile.limPID.gainTrack.y variable */));
  TRACE_POP
}
/*
equation index: 2652
type: SIMPLE_ASSIGN
$DER.Chile.limPID.I.y = Chile.limPID.I.k * Chile.limPID.addI.y
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2652(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2652};
  (data->localData[0]->realVars[145] /* der(Chile.limPID.I.y) STATE_DER */) = ((data->simulationInfo->realParameter[492] /* Chile.limPID.I.k PARAM */)) * ((data->localData[0]->realVars[680] /* Chile.limPID.addI.y variable */));
  TRACE_POP
}
/*
equation index: 2653
type: SIMPLE_ASSIGN
Chile.limPID.controlError = Chile.digester.P_gas - Chile.P_ref.k
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2653(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2653};
  (data->localData[0]->realVars[684] /* Chile.limPID.controlError variable */) = (data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */) - (data->simulationInfo->realParameter[1] /* Chile.P_ref.k PARAM */);
  TRACE_POP
}
/*
equation index: 2654
type: SIMPLE_ASSIGN
Chile.digester.COD_balance_gas = (-Chile.atmosphere.y[1]) * (2.855349300291806 * Chile.gasbag.p_gas_ch4_in / Chile.digester.P_gas + 0.7138373250729516 * Chile.gasbag.p_gas_h2_in / Chile.digester.P_gas)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2654(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2654};
  (data->localData[0]->realVars[327] /* Chile.digester.COD_balance_gas variable */) = ((-(data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */))) * ((2.855349300291806) * (DIVISION_SIM((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */),(data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */),"Chile.digester.P_gas",equationIndexes)) + (0.7138373250729516) * (DIVISION_SIM((data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */),(data->localData[0]->realVars[422] /* Chile.digester.P_gas variable */),"Chile.digester.P_gas",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2655
type: SIMPLE_ASSIGN
$DER.Chile.digester.COD_balance_gas_cum = Chile.digester.COD_balance_gas / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2655(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2655};
  (data->localData[0]->realVars[79] /* der(Chile.digester.COD_balance_gas_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[327] /* Chile.digester.COD_balance_gas variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2656
type: SIMPLE_ASSIGN
Chile.gasbag.inlet.P_gas = Chile.gasbag.p_gas_h2o + Chile.gasbag.p_gas_h2_in + Chile.gasbag.p_gas_ch4_in + Chile.gasbag.p_gas_co2_in + Chile.gasbag.p_gas_nh3_in + Chile.gasbag.p_gas_n2_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2656(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2656};
  (data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) = (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */) + (data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */) + (data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */) + (data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */) + (data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */) + (data->localData[0]->realVars[668] /* Chile.gasbag.p_gas_n2_in variable */);
  TRACE_POP
}
/*
equation index: 2657
type: SIMPLE_ASSIGN
Chile.gasbag.x_ch4_in = Chile.gasbag.p_gas_ch4_in / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2657(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2657};
  (data->localData[0]->realVars[670] /* Chile.gasbag.x_ch4_in variable */) = DIVISION_SIM((data->localData[0]->realVars[664] /* Chile.gasbag.p_gas_ch4_in variable */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2658
type: SIMPLE_ASSIGN
Chile.gasbag.x_co2_in = Chile.gasbag.p_gas_co2_in / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2658(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2658};
  (data->localData[0]->realVars[671] /* Chile.gasbag.x_co2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2659
type: SIMPLE_ASSIGN
Chile.gasbag.x_nh3_in = Chile.gasbag.p_gas_nh3_in / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2659(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2659};
  (data->localData[0]->realVars[677] /* Chile.gasbag.x_nh3_in variable */) = DIVISION_SIM((data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2660
type: SIMPLE_ASSIGN
Chile.gasbag.x_h2 = Chile.gasbag.S_gas_h2 * 0.083145 * Chile.gasbag.T_op_mean / (16.0388 * (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2660(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2660};
  (data->localData[0]->realVars[672] /* Chile.gasbag.x_h2 variable */) = DIVISION_SIM((((data->localData[0]->realVars[68] /* Chile.gasbag.S_gas_h2 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),(16.0388) * ((data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */)),"16.0388 * (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2661
type: SIMPLE_ASSIGN
Chile.gasbag.Q_h2_N = 1000.0 * Chile.atmosphere.y[1] * Chile.gasbag.x_h2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2661(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2661};
  (data->localData[0]->realVars[648] /* Chile.gasbag.Q_h2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[672] /* Chile.gasbag.x_h2 variable */)));
  TRACE_POP
}
/*
equation index: 2662
type: SIMPLE_ASSIGN
y_gas_noisy[2] = Chile.gasbag.S_gas_ch4 * 0.083145 * Chile.gasbag.T_op_mean / (63.9996 * (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2662(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2662};
  (data->localData[0]->realVars[1249] /* y_gas_noisy[2] variable */) = DIVISION_SIM((((data->localData[0]->realVars[66] /* Chile.gasbag.S_gas_ch4 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),(63.9996) * ((data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */)),"63.9996 * (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2663
type: SIMPLE_ASSIGN
Chile.gasbag.Q_ch4_N = 1000.0 * Chile.atmosphere.y[1] * y_gas_noisy[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2663(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2663};
  (data->localData[0]->realVars[646] /* Chile.gasbag.Q_ch4_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[1249] /* y_gas_noisy[2] variable */)));
  TRACE_POP
}
/*
equation index: 2664
type: SIMPLE_ASSIGN
Chile.y_gas[4] = 41.66666666666666 * Chile.digester.Q_gas * y_gas_noisy[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2664(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2664};
  (data->localData[0]->realVars[1236] /* Chile.y_gas[4] variable */) = (41.66666666666666) * (((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)) * ((data->localData[0]->realVars[1249] /* y_gas_noisy[2] variable */)));
  TRACE_POP
}
/*
equation index: 2665
type: SIMPLE_ASSIGN
y_gas_noisy[3] = 0.083145 * Chile.gasbag.S_gas_co2 * Chile.gasbag.T_op_mean / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2665(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2665};
  (data->localData[0]->realVars[1250] /* y_gas_noisy[3] variable */) = (0.083145) * (((data->localData[0]->realVars[67] /* Chile.gasbag.S_gas_co2 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2666
type: SIMPLE_ASSIGN
Chile.gasbag.Q_co2_N = 1000.0 * Chile.atmosphere.y[1] * y_gas_noisy[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2666(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2666};
  (data->localData[0]->realVars[647] /* Chile.gasbag.Q_co2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[1250] /* y_gas_noisy[3] variable */)));
  TRACE_POP
}
/*
equation index: 2667
type: SIMPLE_ASSIGN
Chile.gasbag.x_nh3 = 0.083145 * Chile.gasbag.S_gas_nh3 * Chile.gasbag.T_op_mean / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2667(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2667};
  (data->localData[0]->realVars[676] /* Chile.gasbag.x_nh3 variable */) = (0.083145) * (((data->localData[0]->realVars[70] /* Chile.gasbag.S_gas_nh3 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2668
type: SIMPLE_ASSIGN
Chile.gasbag.x_n2 = 0.083145 * Chile.gasbag.S_gas_n2 * Chile.gasbag.T_op_mean / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2668(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2668};
  (data->localData[0]->realVars[674] /* Chile.gasbag.x_n2 variable */) = (0.083145) * (((data->localData[0]->realVars[69] /* Chile.gasbag.S_gas_n2 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2669
type: SIMPLE_ASSIGN
Chile.gasbag.Q_n2_N = 1000.0 * Chile.atmosphere.y[1] * Chile.gasbag.x_n2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2669(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2669};
  (data->localData[0]->realVars[649] /* Chile.gasbag.Q_n2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[674] /* Chile.gasbag.x_n2 variable */)));
  TRACE_POP
}
/*
equation index: 2670
type: SIMPLE_ASSIGN
Chile.gasbag.x_h2_in = Chile.gasbag.p_gas_h2_in / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2670(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2670};
  (data->localData[0]->realVars[673] /* Chile.gasbag.x_h2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[666] /* Chile.gasbag.p_gas_h2_in variable */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2671
type: SIMPLE_ASSIGN
Chile.gasbag.x_n2_in = Chile.gasbag.p_gas_n2_in / (Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2671(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2671};
  (data->localData[0]->realVars[675] /* Chile.gasbag.x_n2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[668] /* Chile.gasbag.p_gas_n2_in variable */),(data->localData[0]->realVars[658] /* Chile.gasbag.inlet.P_gas variable */) - (data->localData[0]->realVars[667] /* Chile.gasbag.p_gas_h2o variable */),"Chile.gasbag.inlet.P_gas - Chile.gasbag.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2672
type: SIMPLE_ASSIGN
Chile.digester.COD_sol = Chile.digester.S_aa + Chile.digester.S_ac + Chile.digester.S_bu + Chile.digester.S_ch4 + Chile.digester.S_fa + Chile.digester.S_h2 + Chile.digester.S_i + Chile.digester.S_pro + Chile.digester.S_su + Chile.digester.S_va
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2672(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2672};
  (data->localData[0]->realVars[332] /* Chile.digester.COD_sol variable */) = (data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */) + (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */) + (data->localData[0]->realVars[23] /* Chile.digester.S_ch4 STATE(1) */) + (data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */) + (data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */) + (data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */) + (data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */) + (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */);
  TRACE_POP
}
/*
equation index: 2673
type: SIMPLE_ASSIGN
Chile.digester.COD_X = Chile.digester.X_p + Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c4 + Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3] + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_i + Chile.digester.X_li + Chile.digester.X_pr[1] + Chile.digester.X_pr[2] + Chile.digester.X_pro + Chile.digester.X_su + Chile.digester.X_c + Chile.digester.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2673(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2673};
  (data->localData[0]->realVars[326] /* Chile.digester.COD_X variable */) = (data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */) + (data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */) + (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */) + (data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */);
  TRACE_POP
}
void ADM1_P_Chile_OL_MPC_eqFunction_2674(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2675(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2676(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2677(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2678(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2679(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2680(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2681(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2682(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2683(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2684(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2685(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2686(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2687(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2688(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2689(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2690(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2691(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2692(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2693(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2694(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2695(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2696(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2697(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2698(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2699(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2700(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2701(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2703(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2702(DATA*, threadData_t*);
/*
equation index: 2734
indexNonlinear: 8
type: NONLINEAR

vars: {Chile.digester.a_h, Chile.digester.z}
eqns: {2674, 2675, 2676, 2677, 2678, 2679, 2680, 2681, 2682, 2683, 2684, 2685, 2686, 2687, 2688, 2689, 2690, 2691, 2692, 2693, 2694, 2695, 2696, 2697, 2698, 2699, 2700, 2701, 2703, 2702}
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2734(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2734};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 2734 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[0] = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  data->simulationInfo->nonlinearSystemData[8].nlsxOld[1] = (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
  retValue = solve_nonlinear_system(data, threadData, 8);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,2734};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 2734 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */) = data->simulationInfo->nonlinearSystemData[8].nlsx[0];
  (data->localData[0]->realVars[645] /* Chile.digester.z variable */) = data->simulationInfo->nonlinearSystemData[8].nlsx[1];
  TRACE_POP
}
/*
equation index: 2735
type: SIMPLE_ASSIGN
Chile.digester.S_h3po4 = Chile.digester.S_ip + (-Chile.digester.S_po4) - Chile.digester.S_h2po4 - Chile.digester.S_hpo4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2735(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2735};
  (data->localData[0]->realVars[443] /* Chile.digester.S_h3po4 variable */) = (data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */) + (-(data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */)) - (data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */) - (data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */);
  TRACE_POP
}
/*
equation index: 2736
type: SIMPLE_ASSIGN
Chile.digester.S_nh3 = Chile.digester.S_in - Chile.digester.S_nh4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2736(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2736};
  (data->localData[0]->realVars[454] /* Chile.digester.S_nh3 variable */) = (data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */) - (data->localData[0]->realVars[455] /* Chile.digester.S_nh4 variable */);
  TRACE_POP
}
/*
equation index: 2737
type: SIMPLE_ASSIGN
Chile.digester.I_nh3 = 1.0 / (1.0 + Chile.digester.S_nh3 / Chile.digester.Ki_nh3_ac)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2737(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2737};
  (data->localData[0]->realVars[359] /* Chile.digester.I_nh3 variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->localData[0]->realVars[454] /* Chile.digester.S_nh3 variable */),(data->simulationInfo->realParameter[215] /* Chile.digester.Ki_nh3_ac PARAM */),"Chile.digester.Ki_nh3_ac",equationIndexes),"1.0 + Chile.digester.S_nh3 / Chile.digester.Ki_nh3_ac",equationIndexes);
  TRACE_POP
}
/*
equation index: 2738
type: SIMPLE_ASSIGN
Chile.digester.rt12 = Chile.digester.kla_nh3 * (Chile.digester.S_nh3 + (-61.0) * Chile.gasbag.p_gas_nh3_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2738(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2738};
  (data->localData[0]->realVars[622] /* Chile.digester.rt12 variable */) = ((data->localData[0]->realVars[580] /* Chile.digester.kla_nh3 variable */)) * ((data->localData[0]->realVars[454] /* Chile.digester.S_nh3 variable */) + (-61.0) * ((data->localData[0]->realVars[669] /* Chile.gasbag.p_gas_nh3_in variable */)));
  TRACE_POP
}
/*
equation index: 2739
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_gas_nh3 = 4.629629629629631e-05 * Chile.digester.rt12 + 0.003858024691358026 * (-Chile.digester.S_gas_nh3) * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2739(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2739};
  (data->localData[0]->realVars[102] /* der(Chile.digester.S_gas_nh3) STATE_DER */) = (4.629629629629631e-05) * ((data->localData[0]->realVars[622] /* Chile.digester.rt12 variable */)) + (0.003858024691358026) * (((-(data->localData[0]->realVars[29] /* Chile.digester.S_gas_nh3 STATE(1) */))) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)));
  TRACE_POP
}
void ADM1_P_Chile_OL_MPC_eqFunction_2740(DATA*, threadData_t*);
/*
equation index: 2741
indexNonlinear: 9
type: NONLINEAR

vars: {Chile.y_dig[1]}
eqns: {2740}
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2741(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2741};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 2741 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[9].nlsxOld[0] = (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */);
  retValue = solve_nonlinear_system(data, threadData, 9);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,2741};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 2741 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) = data->simulationInfo->nonlinearSystemData[9].nlsx[0];
  TRACE_POP
}
/*
equation index: 2742
type: SIMPLE_ASSIGN
Chile.digester.I_pH_aa = if noEvent(Chile.y_dig[1] < Chile.digester.pH_UL_aa) then exp((-3.0) * ((Chile.y_dig[1] - Chile.digester.pH_UL_aa) / (Chile.digester.pH_UL_aa - Chile.digester.pH_LL_aa)) ^ 2.0) else 1.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2742(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2742};
  modelica_boolean tmp0;
  modelica_real tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp0 = Less((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */),(data->simulationInfo->realParameter[398] /* Chile.digester.pH_UL_aa PARAM */));
  tmp2 = (modelica_boolean)tmp0;
  if(tmp2)
  {
    tmp1 = DIVISION_SIM((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) - (data->simulationInfo->realParameter[398] /* Chile.digester.pH_UL_aa PARAM */),(data->simulationInfo->realParameter[398] /* Chile.digester.pH_UL_aa PARAM */) - (data->simulationInfo->realParameter[395] /* Chile.digester.pH_LL_aa PARAM */),"Chile.digester.pH_UL_aa - Chile.digester.pH_LL_aa",equationIndexes);
    tmp3 = exp((-3.0) * ((tmp1 * tmp1)));
  }
  else
  {
    tmp3 = 1.0;
  }
  (data->localData[0]->realVars[360] /* Chile.digester.I_pH_aa variable */) = tmp3;
  TRACE_POP
}
/*
equation index: 2743
type: SIMPLE_ASSIGN
Chile.digester.I_pH_ac = if noEvent(Chile.y_dig[1] < Chile.digester.pH_UL_ac) then exp((-3.0) * ((Chile.y_dig[1] - Chile.digester.pH_UL_ac) / (Chile.digester.pH_UL_ac - Chile.digester.pH_LL_ac)) ^ 2.0) else 1.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2743(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2743};
  modelica_boolean tmp4;
  modelica_real tmp5;
  modelica_boolean tmp6;
  modelica_real tmp7;
  tmp4 = Less((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */),(data->simulationInfo->realParameter[399] /* Chile.digester.pH_UL_ac PARAM */));
  tmp6 = (modelica_boolean)tmp4;
  if(tmp6)
  {
    tmp5 = DIVISION_SIM((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) - (data->simulationInfo->realParameter[399] /* Chile.digester.pH_UL_ac PARAM */),(data->simulationInfo->realParameter[399] /* Chile.digester.pH_UL_ac PARAM */) - (data->simulationInfo->realParameter[396] /* Chile.digester.pH_LL_ac PARAM */),"Chile.digester.pH_UL_ac - Chile.digester.pH_LL_ac",equationIndexes);
    tmp7 = exp((-3.0) * ((tmp5 * tmp5)));
  }
  else
  {
    tmp7 = 1.0;
  }
  (data->localData[0]->realVars[361] /* Chile.digester.I_pH_ac variable */) = tmp7;
  TRACE_POP
}
/*
equation index: 2744
type: SIMPLE_ASSIGN
Chile.digester.I_pH_h2 = if noEvent(Chile.y_dig[1] < Chile.digester.pH_UL_h2) then exp((-3.0) * ((Chile.y_dig[1] - Chile.digester.pH_UL_h2) / (Chile.digester.pH_UL_h2 - Chile.digester.pH_LL_h2)) ^ 2.0) else 1.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2744(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2744};
  modelica_boolean tmp8;
  modelica_real tmp9;
  modelica_boolean tmp10;
  modelica_real tmp11;
  tmp8 = Less((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */),(data->simulationInfo->realParameter[400] /* Chile.digester.pH_UL_h2 PARAM */));
  tmp10 = (modelica_boolean)tmp8;
  if(tmp10)
  {
    tmp9 = DIVISION_SIM((data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) - (data->simulationInfo->realParameter[400] /* Chile.digester.pH_UL_h2 PARAM */),(data->simulationInfo->realParameter[400] /* Chile.digester.pH_UL_h2 PARAM */) - (data->simulationInfo->realParameter[397] /* Chile.digester.pH_LL_h2 PARAM */),"Chile.digester.pH_UL_h2 - Chile.digester.pH_LL_h2",equationIndexes);
    tmp11 = exp((-3.0) * ((tmp9 * tmp9)));
  }
  else
  {
    tmp11 = 1.0;
  }
  (data->localData[0]->realVars[362] /* Chile.digester.I_pH_h2 variable */) = tmp11;
  TRACE_POP
}
/*
equation index: 2745
type: SIMPLE_ASSIGN
Chile.digester.S_co2 = Chile.digester.S_ic + (-Chile.digester.S_hco3) - Chile.digester.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2745(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2745};
  (data->localData[0]->realVars[438] /* Chile.digester.S_co2 variable */) = (data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */) + (-(data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */)) - (data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */);
  TRACE_POP
}
/*
equation index: 2746
type: SIMPLE_ASSIGN
Chile.digester.rt10 = Chile.digester.kla_co2 * (Chile.digester.S_co2 - Chile.digester.KH_co2 * Chile.gasbag.p_gas_co2_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2746(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2746};
  (data->localData[0]->realVars[621] /* Chile.digester.rt10 variable */) = ((data->localData[0]->realVars[578] /* Chile.digester.kla_co2 variable */)) * ((data->localData[0]->realVars[438] /* Chile.digester.S_co2 variable */) - (((data->localData[0]->realVars[364] /* Chile.digester.KH_co2 variable */)) * ((data->localData[0]->realVars[665] /* Chile.gasbag.p_gas_co2_in variable */))));
  TRACE_POP
}
/*
equation index: 2747
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_gas_co2 = 4.629629629629631e-05 * Chile.digester.rt10 + 0.003858024691358026 * (-Chile.digester.S_gas_co2) * Chile.digester.Q_gas
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2747(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2747};
  (data->localData[0]->realVars[99] /* der(Chile.digester.S_gas_co2) STATE_DER */) = (4.629629629629631e-05) * ((data->localData[0]->realVars[621] /* Chile.digester.rt10 variable */)) + (0.003858024691358026) * (((-(data->localData[0]->realVars[26] /* Chile.digester.S_gas_co2 STATE(1) */))) * ((data->localData[0]->realVars[424] /* Chile.digester.Q_gas variable */)));
  TRACE_POP
}
/*
equation index: 2748
type: SIMPLE_ASSIGN
Chile.digester.a_ca = Chile.digester.g_bi * Chile.digester.S_ca
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2748(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2748};
  (data->localData[0]->realVars[502] /* Chile.digester.a_ca variable */) = ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) * ((data->localData[0]->realVars[21] /* Chile.digester.S_ca STATE(1) */));
  TRACE_POP
}
/*
equation index: 2749
type: SIMPLE_ASSIGN
Chile.digester.arg_log_ccm = max(1e-140, Chile.digester.a_ca * Chile.digester.a_co3 / Chile.digester.Ksp_ccm)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2749(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2749};
  (data->localData[0]->realVars[517] /* Chile.digester.arg_log_ccm variable */) = fmax(1e-140,DIVISION_SIM(((data->localData[0]->realVars[502] /* Chile.digester.a_ca variable */)) * ((data->localData[0]->realVars[503] /* Chile.digester.a_co3 variable */)),(data->localData[0]->realVars[385] /* Chile.digester.Ksp_ccm variable */),"Chile.digester.Ksp_ccm",equationIndexes));
  TRACE_POP
}
/*
equation index: 2750
type: SIMPLE_ASSIGN
Chile.digester.SI_ccm = log10(Chile.digester.arg_log_ccm)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2750(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2750};
  modelica_real tmp12;
  tmp12 = (data->localData[0]->realVars[517] /* Chile.digester.arg_log_ccm variable */);
  if(!(tmp12 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(Chile.digester.arg_log_ccm) was %g should be > 0", tmp12);
    }
  }
  (data->localData[0]->realVars[426] /* Chile.digester.SI_ccm variable */) = log10(tmp12);
  TRACE_POP
}
/*
equation index: 2751
type: SIMPLE_ASSIGN
Chile.digester.rp3 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 0.35 * (0.5 + 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_ccm)) * Chile.digester.X_ccm * (10.0 ^ (Chile.digester.SI_ccm * 0.5) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2751(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2751};
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  tmp22 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp22)
  {
    tmp23 = 0.0;
  }
  else
  {
    tmp14 = 10.0;
    tmp15 = ((data->localData[0]->realVars[426] /* Chile.digester.SI_ccm variable */)) * (0.5);
    if(tmp14 < 0.0 && tmp15 != 0.0)
    {
      tmp17 = modf(tmp15, &tmp18);
      
      if(tmp17 > 0.5)
      {
        tmp17 -= 1.0;
        tmp18 += 1.0;
      }
      else if(tmp17 < -0.5)
      {
        tmp17 += 1.0;
        tmp18 -= 1.0;
      }
      
      if(fabs(tmp17) < 1e-10)
        tmp16 = pow(tmp14, tmp18);
      else
      {
        tmp20 = modf(1.0/tmp15, &tmp19);
        if(tmp20 > 0.5)
        {
          tmp20 -= 1.0;
          tmp19 += 1.0;
        }
        else if(tmp20 < -0.5)
        {
          tmp20 += 1.0;
          tmp19 -= 1.0;
        }
        if(fabs(tmp20) < 1e-10 && ((unsigned long)tmp19 & 1))
        {
          tmp16 = -pow(-tmp14, tmp17)*pow(tmp14, tmp18);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp14, tmp15);
        }
      }
    }
    else
    {
      tmp16 = pow(tmp14, tmp15);
    }
    if(isnan(tmp16) || isinf(tmp16))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp14, tmp15);
    }tmp21 = tmp16 - 1.0;
    tmp23 = (((0.35) * (0.5 + (0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[426] /* Chile.digester.SI_ccm variable */))))) * ((data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */))) * ((tmp21 * tmp21));
  }
  (data->localData[0]->realVars[619] /* Chile.digester.rp3 variable */) = tmp23;
  TRACE_POP
}
/*
equation index: 2752
type: SIMPLE_ASSIGN
Chile.digester.rd3 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 0.35 * (0.5 - 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_ccm)) * Chile.digester.X_ccm * (10.0 ^ (Chile.digester.SI_ccm * 0.5) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2752(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2752};
  modelica_real tmp25;
  modelica_real tmp26;
  modelica_real tmp27;
  modelica_real tmp28;
  modelica_real tmp29;
  modelica_real tmp30;
  modelica_real tmp31;
  modelica_real tmp32;
  modelica_boolean tmp33;
  modelica_real tmp34;
  tmp33 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp33)
  {
    tmp34 = 0.0;
  }
  else
  {
    tmp25 = 10.0;
    tmp26 = ((data->localData[0]->realVars[426] /* Chile.digester.SI_ccm variable */)) * (0.5);
    if(tmp25 < 0.0 && tmp26 != 0.0)
    {
      tmp28 = modf(tmp26, &tmp29);
      
      if(tmp28 > 0.5)
      {
        tmp28 -= 1.0;
        tmp29 += 1.0;
      }
      else if(tmp28 < -0.5)
      {
        tmp28 += 1.0;
        tmp29 -= 1.0;
      }
      
      if(fabs(tmp28) < 1e-10)
        tmp27 = pow(tmp25, tmp29);
      else
      {
        tmp31 = modf(1.0/tmp26, &tmp30);
        if(tmp31 > 0.5)
        {
          tmp31 -= 1.0;
          tmp30 += 1.0;
        }
        else if(tmp31 < -0.5)
        {
          tmp31 += 1.0;
          tmp30 -= 1.0;
        }
        if(fabs(tmp31) < 1e-10 && ((unsigned long)tmp30 & 1))
        {
          tmp27 = -pow(-tmp25, tmp28)*pow(tmp25, tmp29);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp25, tmp26);
        }
      }
    }
    else
    {
      tmp27 = pow(tmp25, tmp26);
    }
    if(isnan(tmp27) || isinf(tmp27))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp25, tmp26);
    }tmp32 = tmp27 - 1.0;
    tmp34 = (((0.35) * (0.5 - ((0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[426] /* Chile.digester.SI_ccm variable */)))))) * ((data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */))) * ((tmp32 * tmp32));
  }
  (data->localData[0]->realVars[614] /* Chile.digester.rd3 variable */) = tmp34;
  TRACE_POP
}
/*
equation index: 2753
type: SIMPLE_ASSIGN
Chile.digester.arg_log_acp = max(1e-140, Chile.digester.a_ca ^ 3.0 * Chile.digester.a_po4 ^ 2.0 / Chile.digester.Ksp_acp)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2753(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2753};
  modelica_real tmp35;
  modelica_real tmp36;
  tmp35 = (data->localData[0]->realVars[502] /* Chile.digester.a_ca variable */);
  tmp36 = (data->localData[0]->realVars[512] /* Chile.digester.a_po4 variable */);
  (data->localData[0]->realVars[516] /* Chile.digester.arg_log_acp variable */) = fmax(1e-140,DIVISION_SIM(((tmp35 * tmp35 * tmp35)) * ((tmp36 * tmp36)),(data->localData[0]->realVars[384] /* Chile.digester.Ksp_acp variable */),"Chile.digester.Ksp_acp",equationIndexes));
  TRACE_POP
}
/*
equation index: 2754
type: SIMPLE_ASSIGN
Chile.digester.SI_acp = log10(Chile.digester.arg_log_acp)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2754(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2754};
  modelica_real tmp37;
  tmp37 = (data->localData[0]->realVars[516] /* Chile.digester.arg_log_acp variable */);
  if(!(tmp37 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(Chile.digester.arg_log_acp) was %g should be > 0", tmp37);
    }
  }
  (data->localData[0]->realVars[425] /* Chile.digester.SI_acp variable */) = log10(tmp37);
  TRACE_POP
}
/*
equation index: 2755
type: SIMPLE_ASSIGN
Chile.digester.rp1 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 3.0 * (0.5 + 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_acp)) * Chile.digester.X_acp * (10.0 ^ (Chile.digester.SI_acp * 0.2) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2755(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2755};
  modelica_real tmp39;
  modelica_real tmp40;
  modelica_real tmp41;
  modelica_real tmp42;
  modelica_real tmp43;
  modelica_real tmp44;
  modelica_real tmp45;
  modelica_real tmp46;
  modelica_boolean tmp47;
  modelica_real tmp48;
  tmp47 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp47)
  {
    tmp48 = 0.0;
  }
  else
  {
    tmp39 = 10.0;
    tmp40 = ((data->localData[0]->realVars[425] /* Chile.digester.SI_acp variable */)) * (0.2);
    if(tmp39 < 0.0 && tmp40 != 0.0)
    {
      tmp42 = modf(tmp40, &tmp43);
      
      if(tmp42 > 0.5)
      {
        tmp42 -= 1.0;
        tmp43 += 1.0;
      }
      else if(tmp42 < -0.5)
      {
        tmp42 += 1.0;
        tmp43 -= 1.0;
      }
      
      if(fabs(tmp42) < 1e-10)
        tmp41 = pow(tmp39, tmp43);
      else
      {
        tmp45 = modf(1.0/tmp40, &tmp44);
        if(tmp45 > 0.5)
        {
          tmp45 -= 1.0;
          tmp44 += 1.0;
        }
        else if(tmp45 < -0.5)
        {
          tmp45 += 1.0;
          tmp44 -= 1.0;
        }
        if(fabs(tmp45) < 1e-10 && ((unsigned long)tmp44 & 1))
        {
          tmp41 = -pow(-tmp39, tmp42)*pow(tmp39, tmp43);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp39, tmp40);
        }
      }
    }
    else
    {
      tmp41 = pow(tmp39, tmp40);
    }
    if(isnan(tmp41) || isinf(tmp41))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp39, tmp40);
    }tmp46 = tmp41 - 1.0;
    tmp48 = (((3.0) * (0.5 + (0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[425] /* Chile.digester.SI_acp variable */))))) * ((data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */))) * ((tmp46 * tmp46));
  }
  (data->localData[0]->realVars[617] /* Chile.digester.rp1 variable */) = tmp48;
  TRACE_POP
}
/*
equation index: 2756
type: SIMPLE_ASSIGN
Chile.digester.rd1 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 3.0 * (0.5 - 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_acp)) * Chile.digester.X_acp * (10.0 ^ (Chile.digester.SI_acp * 0.2) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2756(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2756};
  modelica_real tmp50;
  modelica_real tmp51;
  modelica_real tmp52;
  modelica_real tmp53;
  modelica_real tmp54;
  modelica_real tmp55;
  modelica_real tmp56;
  modelica_real tmp57;
  modelica_boolean tmp58;
  modelica_real tmp59;
  tmp58 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp58)
  {
    tmp59 = 0.0;
  }
  else
  {
    tmp50 = 10.0;
    tmp51 = ((data->localData[0]->realVars[425] /* Chile.digester.SI_acp variable */)) * (0.2);
    if(tmp50 < 0.0 && tmp51 != 0.0)
    {
      tmp53 = modf(tmp51, &tmp54);
      
      if(tmp53 > 0.5)
      {
        tmp53 -= 1.0;
        tmp54 += 1.0;
      }
      else if(tmp53 < -0.5)
      {
        tmp53 += 1.0;
        tmp54 -= 1.0;
      }
      
      if(fabs(tmp53) < 1e-10)
        tmp52 = pow(tmp50, tmp54);
      else
      {
        tmp56 = modf(1.0/tmp51, &tmp55);
        if(tmp56 > 0.5)
        {
          tmp56 -= 1.0;
          tmp55 += 1.0;
        }
        else if(tmp56 < -0.5)
        {
          tmp56 += 1.0;
          tmp55 -= 1.0;
        }
        if(fabs(tmp56) < 1e-10 && ((unsigned long)tmp55 & 1))
        {
          tmp52 = -pow(-tmp50, tmp53)*pow(tmp50, tmp54);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp50, tmp51);
        }
      }
    }
    else
    {
      tmp52 = pow(tmp50, tmp51);
    }
    if(isnan(tmp52) || isinf(tmp52))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp50, tmp51);
    }tmp57 = tmp52 - 1.0;
    tmp59 = (((3.0) * (0.5 - ((0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[425] /* Chile.digester.SI_acp variable */)))))) * ((data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */))) * ((tmp57 * tmp57));
  }
  (data->localData[0]->realVars[612] /* Chile.digester.rd1 variable */) = tmp59;
  TRACE_POP
}
/*
equation index: 2757
type: SIMPLE_ASSIGN
Chile.digester.a_mg = Chile.digester.g_bi * Chile.digester.S_mg
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2757(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2757};
  (data->localData[0]->realVars[509] /* Chile.digester.a_mg variable */) = ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) * ((data->localData[0]->realVars[35] /* Chile.digester.S_mg STATE(1) */));
  TRACE_POP
}
/*
equation index: 2758
type: SIMPLE_ASSIGN
Chile.digester.arg_log_mag = max(1e-140, Chile.digester.a_mg * Chile.digester.a_co3 / Chile.digester.Ksp_mag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2758(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2758};
  (data->localData[0]->realVars[518] /* Chile.digester.arg_log_mag variable */) = fmax(1e-140,DIVISION_SIM(((data->localData[0]->realVars[509] /* Chile.digester.a_mg variable */)) * ((data->localData[0]->realVars[503] /* Chile.digester.a_co3 variable */)),(data->localData[0]->realVars[386] /* Chile.digester.Ksp_mag variable */),"Chile.digester.Ksp_mag",equationIndexes));
  TRACE_POP
}
/*
equation index: 2759
type: SIMPLE_ASSIGN
Chile.digester.SI_mag = log10(Chile.digester.arg_log_mag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2759(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2759};
  modelica_real tmp60;
  tmp60 = (data->localData[0]->realVars[518] /* Chile.digester.arg_log_mag variable */);
  if(!(tmp60 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(Chile.digester.arg_log_mag) was %g should be > 0", tmp60);
    }
  }
  (data->localData[0]->realVars[427] /* Chile.digester.SI_mag variable */) = log10(tmp60);
  TRACE_POP
}
/*
equation index: 2760
type: SIMPLE_ASSIGN
Chile.digester.rp4 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 0.034 * (0.5 + 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_mag)) * Chile.digester.X_mag * (10.0 ^ (Chile.digester.SI_mag * 0.5) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2760(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2760};
  modelica_real tmp62;
  modelica_real tmp63;
  modelica_real tmp64;
  modelica_real tmp65;
  modelica_real tmp66;
  modelica_real tmp67;
  modelica_real tmp68;
  modelica_real tmp69;
  modelica_boolean tmp70;
  modelica_real tmp71;
  tmp70 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp70)
  {
    tmp71 = 0.0;
  }
  else
  {
    tmp62 = 10.0;
    tmp63 = ((data->localData[0]->realVars[427] /* Chile.digester.SI_mag variable */)) * (0.5);
    if(tmp62 < 0.0 && tmp63 != 0.0)
    {
      tmp65 = modf(tmp63, &tmp66);
      
      if(tmp65 > 0.5)
      {
        tmp65 -= 1.0;
        tmp66 += 1.0;
      }
      else if(tmp65 < -0.5)
      {
        tmp65 += 1.0;
        tmp66 -= 1.0;
      }
      
      if(fabs(tmp65) < 1e-10)
        tmp64 = pow(tmp62, tmp66);
      else
      {
        tmp68 = modf(1.0/tmp63, &tmp67);
        if(tmp68 > 0.5)
        {
          tmp68 -= 1.0;
          tmp67 += 1.0;
        }
        else if(tmp68 < -0.5)
        {
          tmp68 += 1.0;
          tmp67 -= 1.0;
        }
        if(fabs(tmp68) < 1e-10 && ((unsigned long)tmp67 & 1))
        {
          tmp64 = -pow(-tmp62, tmp65)*pow(tmp62, tmp66);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
        }
      }
    }
    else
    {
      tmp64 = pow(tmp62, tmp63);
    }
    if(isnan(tmp64) || isinf(tmp64))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp62, tmp63);
    }tmp69 = tmp64 - 1.0;
    tmp71 = (((0.034) * (0.5 + (0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[427] /* Chile.digester.SI_mag variable */))))) * ((data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */))) * ((tmp69 * tmp69));
  }
  (data->localData[0]->realVars[620] /* Chile.digester.rp4 variable */) = tmp71;
  TRACE_POP
}
/*
equation index: 2761
type: SIMPLE_ASSIGN
Chile.digester.rd4 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 0.034 * (0.5 - 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_mag)) * Chile.digester.X_mag * (10.0 ^ (Chile.digester.SI_mag * 0.5) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2761(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2761};
  modelica_real tmp73;
  modelica_real tmp74;
  modelica_real tmp75;
  modelica_real tmp76;
  modelica_real tmp77;
  modelica_real tmp78;
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_boolean tmp81;
  modelica_real tmp82;
  tmp81 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp81)
  {
    tmp82 = 0.0;
  }
  else
  {
    tmp73 = 10.0;
    tmp74 = ((data->localData[0]->realVars[427] /* Chile.digester.SI_mag variable */)) * (0.5);
    if(tmp73 < 0.0 && tmp74 != 0.0)
    {
      tmp76 = modf(tmp74, &tmp77);
      
      if(tmp76 > 0.5)
      {
        tmp76 -= 1.0;
        tmp77 += 1.0;
      }
      else if(tmp76 < -0.5)
      {
        tmp76 += 1.0;
        tmp77 -= 1.0;
      }
      
      if(fabs(tmp76) < 1e-10)
        tmp75 = pow(tmp73, tmp77);
      else
      {
        tmp79 = modf(1.0/tmp74, &tmp78);
        if(tmp79 > 0.5)
        {
          tmp79 -= 1.0;
          tmp78 += 1.0;
        }
        else if(tmp79 < -0.5)
        {
          tmp79 += 1.0;
          tmp78 -= 1.0;
        }
        if(fabs(tmp79) < 1e-10 && ((unsigned long)tmp78 & 1))
        {
          tmp75 = -pow(-tmp73, tmp76)*pow(tmp73, tmp77);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp73, tmp74);
        }
      }
    }
    else
    {
      tmp75 = pow(tmp73, tmp74);
    }
    if(isnan(tmp75) || isinf(tmp75))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp73, tmp74);
    }tmp80 = tmp75 - 1.0;
    tmp82 = (((0.034) * (0.5 - ((0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[427] /* Chile.digester.SI_mag variable */)))))) * ((data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */))) * ((tmp80 * tmp80));
  }
  (data->localData[0]->realVars[615] /* Chile.digester.rd4 variable */) = tmp82;
  TRACE_POP
}
/*
equation index: 2762
type: SIMPLE_ASSIGN
Chile.digester.arg_log_stru = max(1e-140, Chile.digester.a_nh4 * Chile.digester.a_po4 * Chile.digester.a_mg / Chile.digester.Ksp_stru)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2762(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2762};
  (data->localData[0]->realVars[519] /* Chile.digester.arg_log_stru variable */) = fmax(1e-140,DIVISION_SIM((((data->localData[0]->realVars[510] /* Chile.digester.a_nh4 variable */)) * ((data->localData[0]->realVars[512] /* Chile.digester.a_po4 variable */))) * ((data->localData[0]->realVars[509] /* Chile.digester.a_mg variable */)),(data->localData[0]->realVars[387] /* Chile.digester.Ksp_stru variable */),"Chile.digester.Ksp_stru",equationIndexes));
  TRACE_POP
}
/*
equation index: 2763
type: SIMPLE_ASSIGN
Chile.digester.SI_stru = log10(Chile.digester.arg_log_stru)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2763(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2763};
  modelica_real tmp83;
  tmp83 = (data->localData[0]->realVars[519] /* Chile.digester.arg_log_stru variable */);
  if(!(tmp83 > 0.0))
  {
    if (data->simulationInfo->noThrowAsserts) {
      FILE_INFO info = {"",0,0,0,0,0};
      infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      data->simulationInfo->needToReThrow = 1;
    } else {
      FILE_INFO info = {"",0,0,0,0,0};
      omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
      throwStreamPrintWithEquationIndexes(threadData, info, equationIndexes, "Model error: Argument of log10(Chile.digester.arg_log_stru) was %g should be > 0", tmp83);
    }
  }
  (data->localData[0]->realVars[428] /* Chile.digester.SI_stru variable */) = log10(tmp83);
  TRACE_POP
}
/*
equation index: 2764
type: SIMPLE_ASSIGN
Chile.digester.rp2 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 5.0 * (0.5 + 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_stru)) * Chile.digester.X_stru * (10.0 ^ (Chile.digester.SI_stru * 0.3333333333333333) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2764(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2764};
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_real tmp87;
  modelica_real tmp88;
  modelica_real tmp89;
  modelica_real tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_boolean tmp93;
  modelica_real tmp94;
  tmp93 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp93)
  {
    tmp94 = 0.0;
  }
  else
  {
    tmp85 = 10.0;
    tmp86 = ((data->localData[0]->realVars[428] /* Chile.digester.SI_stru variable */)) * (0.3333333333333333);
    if(tmp85 < 0.0 && tmp86 != 0.0)
    {
      tmp88 = modf(tmp86, &tmp89);
      
      if(tmp88 > 0.5)
      {
        tmp88 -= 1.0;
        tmp89 += 1.0;
      }
      else if(tmp88 < -0.5)
      {
        tmp88 += 1.0;
        tmp89 -= 1.0;
      }
      
      if(fabs(tmp88) < 1e-10)
        tmp87 = pow(tmp85, tmp89);
      else
      {
        tmp91 = modf(1.0/tmp86, &tmp90);
        if(tmp91 > 0.5)
        {
          tmp91 -= 1.0;
          tmp90 += 1.0;
        }
        else if(tmp91 < -0.5)
        {
          tmp91 += 1.0;
          tmp90 -= 1.0;
        }
        if(fabs(tmp91) < 1e-10 && ((unsigned long)tmp90 & 1))
        {
          tmp87 = -pow(-tmp85, tmp88)*pow(tmp85, tmp89);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp85, tmp86);
        }
      }
    }
    else
    {
      tmp87 = pow(tmp85, tmp86);
    }
    if(isnan(tmp87) || isinf(tmp87))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp85, tmp86);
    }tmp92 = tmp87 - 1.0;
    tmp94 = (((5.0) * (0.5 + (0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[428] /* Chile.digester.SI_stru variable */))))) * ((data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */))) * ((tmp92 * tmp92));
  }
  (data->localData[0]->realVars[618] /* Chile.digester.rp2 variable */) = tmp94;
  TRACE_POP
}
/*
equation index: 2765
type: SIMPLE_ASSIGN
Chile.digester.rd2 = if noEvent(Chile.digester.precipitation == false) then 0.0 else 5.0 * (0.5 - 0.5 * ADM1_P.Functions.regSign(Chile.digester.SI_stru)) * Chile.digester.X_stru * (10.0 ^ (Chile.digester.SI_stru * 0.3333333333333333) - 1.0) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2765(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2765};
  modelica_real tmp96;
  modelica_real tmp97;
  modelica_real tmp98;
  modelica_real tmp99;
  modelica_real tmp100;
  modelica_real tmp101;
  modelica_real tmp102;
  modelica_real tmp103;
  modelica_boolean tmp104;
  modelica_real tmp105;
  tmp104 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && !0) || ((data->simulationInfo->booleanParameter[15] /* Chile.digester.precipitation PARAM */) && 0));
  if(tmp104)
  {
    tmp105 = 0.0;
  }
  else
  {
    tmp96 = 10.0;
    tmp97 = ((data->localData[0]->realVars[428] /* Chile.digester.SI_stru variable */)) * (0.3333333333333333);
    if(tmp96 < 0.0 && tmp97 != 0.0)
    {
      tmp99 = modf(tmp97, &tmp100);
      
      if(tmp99 > 0.5)
      {
        tmp99 -= 1.0;
        tmp100 += 1.0;
      }
      else if(tmp99 < -0.5)
      {
        tmp99 += 1.0;
        tmp100 -= 1.0;
      }
      
      if(fabs(tmp99) < 1e-10)
        tmp98 = pow(tmp96, tmp100);
      else
      {
        tmp102 = modf(1.0/tmp97, &tmp101);
        if(tmp102 > 0.5)
        {
          tmp102 -= 1.0;
          tmp101 += 1.0;
        }
        else if(tmp102 < -0.5)
        {
          tmp102 += 1.0;
          tmp101 -= 1.0;
        }
        if(fabs(tmp102) < 1e-10 && ((unsigned long)tmp101 & 1))
        {
          tmp98 = -pow(-tmp96, tmp99)*pow(tmp96, tmp100);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp96, tmp97);
        }
      }
    }
    else
    {
      tmp98 = pow(tmp96, tmp97);
    }
    if(isnan(tmp98) || isinf(tmp98))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp96, tmp97);
    }tmp103 = tmp98 - 1.0;
    tmp105 = (((5.0) * (0.5 - ((0.5) * (omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[428] /* Chile.digester.SI_stru variable */)))))) * ((data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */))) * ((tmp103 * tmp103));
  }
  (data->localData[0]->realVars[613] /* Chile.digester.rd2 variable */) = tmp105;
  TRACE_POP
}
/*
equation index: 2766
type: SIMPLE_ASSIGN
Chile.y_dig[3] = 50000.0 * (Chile.digester.S_hco3 + 2.0 * Chile.digester.S_co3 + Chile.digester.S_oh + 0.0156119900083264 * Chile.digester.S_acm + 0.008918929342795433 * Chile.digester.S_prom + 0.006242905788876278 * Chile.digester.S_bum + 0.004801572656267654 * Chile.digester.S_vam + Chile.digester.S_nh3 + Chile.digester.S_hpo4 + 2.0 * Chile.digester.S_po4 + (-Chile.digester.S_h3po4) - Chile.digester.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2766(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2766};
  (data->localData[0]->realVars[1232] /* Chile.y_dig[3] variable */) = (50000.0) * ((data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */) + (2.0) * ((data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */)) + (data->localData[0]->realVars[456] /* Chile.digester.S_oh variable */) + (0.0156119900083264) * ((data->localData[0]->realVars[431] /* Chile.digester.S_acm variable */)) + (0.008918929342795433) * ((data->localData[0]->realVars[459] /* Chile.digester.S_prom variable */)) + (0.006242905788876278) * ((data->localData[0]->realVars[434] /* Chile.digester.S_bum variable */)) + (0.004801572656267654) * ((data->localData[0]->realVars[462] /* Chile.digester.S_vam variable */)) + (data->localData[0]->realVars[454] /* Chile.digester.S_nh3 variable */) + (data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */) + (2.0) * ((data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */)) + (-(data->localData[0]->realVars[443] /* Chile.digester.S_h3po4 variable */)) - (data->localData[0]->realVars[440] /* Chile.digester.S_h variable */));
  TRACE_POP
}
/*
equation index: 2767
type: SIMPLE_ASSIGN
$DER.Chile.digester.ionic_force = (-4000.0) * Chile.digester.ionic_force
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2767(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2767};
  (data->localData[0]->realVars[138] /* der(Chile.digester.ionic_force) STATE_DER */) = (-4000.0) * ((data->localData[0]->realVars[65] /* Chile.digester.ionic_force STATE(1) */));
  TRACE_POP
}
/*
equation index: 2768
type: SIMPLE_ASSIGN
Chile.digester.I_in_lim = 1.0 / (1.0 + Chile.digester.Ks_IN / Chile.digester.S_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2768(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2768};
  (data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->simulationInfo->realParameter[216] /* Chile.digester.Ks_IN PARAM */),(data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */),"Chile.digester.S_in",equationIndexes),"1.0 + Chile.digester.Ks_IN / Chile.digester.S_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 2769
type: SIMPLE_ASSIGN
Chile.digester.I_ip_lim = 1.0 / (1.0 + Chile.digester.Ks_IP / Chile.digester.S_ip)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2769(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2769};
  (data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->simulationInfo->realParameter[217] /* Chile.digester.Ks_IP PARAM */),(data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */),"Chile.digester.S_ip",equationIndexes),"1.0 + Chile.digester.Ks_IP / Chile.digester.S_ip",equationIndexes);
  TRACE_POP
}
/*
equation index: 2770
type: SIMPLE_ASSIGN
Chile.digester.I_6 = Chile.digester.I_pH_aa * Chile.digester.I_in_lim * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2770(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2770};
  (data->localData[0]->realVars[349] /* Chile.digester.I_6 variable */) = ((data->localData[0]->realVars[360] /* Chile.digester.I_pH_aa variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */)));
  TRACE_POP
}
/*
equation index: 2771
type: SIMPLE_ASSIGN
Chile.digester.r5 = Chile.digester.k_m_su_T * Chile.digester.S_su * Chile.digester.X_su * Chile.digester.I_6 / (Chile.digester.S_su + Chile.digester.Ks_su_T)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2771(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2771};
  (data->localData[0]->realVars[602] /* Chile.digester.r5 variable */) = ((data->localData[0]->realVars[576] /* Chile.digester.k_m_su_T variable */)) * (((data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */)) * (((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */)) * (DIVISION_SIM((data->localData[0]->realVars[349] /* Chile.digester.I_6 variable */),(data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */) + (data->localData[0]->realVars[383] /* Chile.digester.Ks_su_T variable */),"Chile.digester.S_su + Chile.digester.Ks_su_T",equationIndexes))));
  TRACE_POP
}
/*
equation index: 2772
type: SIMPLE_ASSIGN
Chile.digester.r6 = Chile.digester.k_m_aa_T * Chile.digester.S_aa * Chile.digester.X_aa * Chile.digester.I_6 / (Chile.digester.S_aa + Chile.digester.Ks_aa_T)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2772(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2772};
  (data->localData[0]->realVars[603] /* Chile.digester.r6 variable */) = ((data->localData[0]->realVars[571] /* Chile.digester.k_m_aa_T variable */)) * (((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */)) * (DIVISION_SIM(((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */)) * ((data->localData[0]->realVars[349] /* Chile.digester.I_6 variable */)),(data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[378] /* Chile.digester.Ks_aa_T variable */),"Chile.digester.S_aa + Chile.digester.Ks_aa_T",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2773
type: SIMPLE_ASSIGN
Chile.digester.I_11 = Chile.digester.I_pH_ac * Chile.digester.I_in_lim * Chile.digester.I_nh3 * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2773(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2773};
  (data->localData[0]->realVars[347] /* Chile.digester.I_11 variable */) = ((data->localData[0]->realVars[361] /* Chile.digester.I_pH_ac variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * (((data->localData[0]->realVars[359] /* Chile.digester.I_nh3 variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */))));
  TRACE_POP
}
/*
equation index: 2774
type: SIMPLE_ASSIGN
Chile.digester.I_12 = Chile.digester.I_pH_h2 * Chile.digester.I_in_lim * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2774(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2774};
  (data->localData[0]->realVars[348] /* Chile.digester.I_12 variable */) = ((data->localData[0]->realVars[362] /* Chile.digester.I_pH_h2 variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */)));
  TRACE_POP
}
/*
equation index: 2775
type: SIMPLE_ASSIGN
Chile.digester.r12 = Chile.digester.k_m_h2_T * Chile.digester.S_h2 * Chile.digester.X_h2 * Chile.digester.I_12 / (Chile.digester.S_h2 + Chile.digester.Ks_h2_T)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2775(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2775};
  (data->localData[0]->realVars[588] /* Chile.digester.r12 variable */) = ((data->localData[0]->realVars[574] /* Chile.digester.k_m_h2_T variable */)) * (((data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */)) * (DIVISION_SIM(((data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */)) * ((data->localData[0]->realVars[348] /* Chile.digester.I_12 variable */)),(data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */) + (data->localData[0]->realVars[381] /* Chile.digester.Ks_h2_T variable */),"Chile.digester.S_h2 + Chile.digester.Ks_h2_T",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2776
type: SIMPLE_ASSIGN
Chile.digester.I_h2_fa = 1.0 / (1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_fa)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2776(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2776};
  (data->localData[0]->realVars[353] /* Chile.digester.I_h2_fa variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */),(data->simulationInfo->realParameter[211] /* Chile.digester.Ki_h2_fa PARAM */),"Chile.digester.Ki_h2_fa",equationIndexes),"1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_fa",equationIndexes);
  TRACE_POP
}
/*
equation index: 2777
type: SIMPLE_ASSIGN
Chile.digester.I_7 = Chile.digester.I_pH_aa * Chile.digester.I_in_lim * Chile.digester.I_h2_fa * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2777(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2777};
  (data->localData[0]->realVars[350] /* Chile.digester.I_7 variable */) = ((data->localData[0]->realVars[360] /* Chile.digester.I_pH_aa variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * (((data->localData[0]->realVars[353] /* Chile.digester.I_h2_fa variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */))));
  TRACE_POP
}
/*
equation index: 2778
type: SIMPLE_ASSIGN
Chile.digester.r7 = Chile.digester.k_m_fa_T * Chile.digester.S_fa * Chile.digester.X_fa * Chile.digester.I_7 / (Chile.digester.S_fa + Chile.digester.Ks_fa_T)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2778(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2778};
  (data->localData[0]->realVars[604] /* Chile.digester.r7 variable */) = ((data->localData[0]->realVars[573] /* Chile.digester.k_m_fa_T variable */)) * (((data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */)) * (DIVISION_SIM(((data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */)) * ((data->localData[0]->realVars[350] /* Chile.digester.I_7 variable */)),(data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[380] /* Chile.digester.Ks_fa_T variable */),"Chile.digester.S_fa + Chile.digester.Ks_fa_T",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2779
type: SIMPLE_ASSIGN
Chile.digester.I_h2_c4 = 1.0 / (1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_c4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2779(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2779};
  (data->localData[0]->realVars[352] /* Chile.digester.I_h2_c4 variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */),(data->simulationInfo->realParameter[210] /* Chile.digester.Ki_h2_c4 PARAM */),"Chile.digester.Ki_h2_c4",equationIndexes),"1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_c4",equationIndexes);
  TRACE_POP
}
/*
equation index: 2780
type: SIMPLE_ASSIGN
Chile.digester.I_9 = Chile.digester.I_pH_aa * Chile.digester.I_in_lim * Chile.digester.I_h2_c4 * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2780(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2780};
  (data->localData[0]->realVars[351] /* Chile.digester.I_9 variable */) = ((data->localData[0]->realVars[360] /* Chile.digester.I_pH_aa variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * (((data->localData[0]->realVars[352] /* Chile.digester.I_h2_c4 variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */))));
  TRACE_POP
}
/*
equation index: 2781
type: SIMPLE_ASSIGN
Chile.digester.r8 = Chile.digester.k_m_c4 * Chile.digester.S_va ^ 2.0 * Chile.digester.X_c4 * Chile.digester.I_9 / ((Chile.digester.S_va + Chile.digester.Ks_c4) * (1e-06 + Chile.digester.S_bu + Chile.digester.S_va))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2781(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2781};
  modelica_real tmp106;
  tmp106 = (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */);
  (data->localData[0]->realVars[605] /* Chile.digester.r8 variable */) = ((data->simulationInfo->realParameter[383] /* Chile.digester.k_m_c4 PARAM */)) * (((tmp106 * tmp106)) * (((data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */)) * (DIVISION_SIM((data->localData[0]->realVars[351] /* Chile.digester.I_9 variable */),((data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */) + (data->simulationInfo->realParameter[220] /* Chile.digester.Ks_c4 PARAM */)) * (1e-06 + (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */) + (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */)),"(Chile.digester.S_va + Chile.digester.Ks_c4) * (1e-06 + Chile.digester.S_bu + Chile.digester.S_va)",equationIndexes))));
  TRACE_POP
}
/*
equation index: 2782
type: SIMPLE_ASSIGN
Chile.digester.r9 = Chile.digester.k_m_c4 * Chile.digester.S_bu ^ 2.0 * Chile.digester.X_c4 * Chile.digester.I_9 / (1e-06 + Chile.digester.S_bu + Chile.digester.S_va) / (Chile.digester.S_bu + Chile.digester.Ks_c4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2782(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2782};
  modelica_real tmp107;
  tmp107 = (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */);
  (data->localData[0]->realVars[606] /* Chile.digester.r9 variable */) = ((data->simulationInfo->realParameter[383] /* Chile.digester.k_m_c4 PARAM */)) * (((tmp107 * tmp107)) * (DIVISION_SIM(((data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */)) * (DIVISION_SIM((data->localData[0]->realVars[351] /* Chile.digester.I_9 variable */),1e-06 + (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */) + (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */),"1e-06 + Chile.digester.S_bu + Chile.digester.S_va",equationIndexes)),(data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */) + (data->simulationInfo->realParameter[220] /* Chile.digester.Ks_c4 PARAM */),"Chile.digester.S_bu + Chile.digester.Ks_c4",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2783
type: SIMPLE_ASSIGN
Chile.digester.I_h2_pro = 1.0 / (1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_pro)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2783(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2783};
  (data->localData[0]->realVars[354] /* Chile.digester.I_h2_pro variable */) = DIVISION_SIM(1.0,1.0 + DIVISION_SIM((data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */),(data->simulationInfo->realParameter[212] /* Chile.digester.Ki_h2_pro PARAM */),"Chile.digester.Ki_h2_pro",equationIndexes),"1.0 + Chile.digester.S_h2 / Chile.digester.Ki_h2_pro",equationIndexes);
  TRACE_POP
}
/*
equation index: 2784
type: SIMPLE_ASSIGN
Chile.digester.I_10 = Chile.digester.I_pH_aa * Chile.digester.I_in_lim * Chile.digester.I_h2_pro * Chile.digester.I_ip_lim
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2784(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2784};
  (data->localData[0]->realVars[346] /* Chile.digester.I_10 variable */) = ((data->localData[0]->realVars[360] /* Chile.digester.I_pH_aa variable */)) * (((data->localData[0]->realVars[357] /* Chile.digester.I_in_lim variable */)) * (((data->localData[0]->realVars[354] /* Chile.digester.I_h2_pro variable */)) * ((data->localData[0]->realVars[358] /* Chile.digester.I_ip_lim variable */))));
  TRACE_POP
}
/*
equation index: 2785
type: SIMPLE_ASSIGN
Chile.digester.r10 = Chile.digester.k_m_pro_T * Chile.digester.S_pro * Chile.digester.X_pro * Chile.digester.I_10 / (Chile.digester.S_pro + Chile.digester.Ks_pro_T + Chile.digester.S_pro ^ 2.0 / Chile.digester.Ki_hpro_pro)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2785(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2785};
  modelica_real tmp108;
  tmp108 = (data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */);
  (data->localData[0]->realVars[586] /* Chile.digester.r10 variable */) = ((data->localData[0]->realVars[575] /* Chile.digester.k_m_pro_T variable */)) * (((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */)) * (DIVISION_SIM(((data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */)) * ((data->localData[0]->realVars[346] /* Chile.digester.I_10 variable */)),(data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */) + (data->localData[0]->realVars[382] /* Chile.digester.Ks_pro_T variable */) + DIVISION_SIM((tmp108 * tmp108),(data->simulationInfo->realParameter[214] /* Chile.digester.Ki_hpro_pro PARAM */),"Chile.digester.Ki_hpro_pro",equationIndexes),"Chile.digester.S_pro + Chile.digester.Ks_pro_T + Chile.digester.S_pro ^ 2.0 / Chile.digester.Ki_hpro_pro",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2786
type: SIMPLE_ASSIGN
Chile.digester.I_hald_pro = Chile.digester.k_m_pro_T * Chile.digester.S_pro / (Chile.digester.S_pro + Chile.digester.Ks_pro_T + Chile.digester.S_pro ^ 2.0 / Chile.digester.Ki_hpro_pro)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2786(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2786};
  modelica_real tmp109;
  tmp109 = (data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */);
  (data->localData[0]->realVars[356] /* Chile.digester.I_hald_pro variable */) = ((data->localData[0]->realVars[575] /* Chile.digester.k_m_pro_T variable */)) * (DIVISION_SIM((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */),(data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */) + (data->localData[0]->realVars[382] /* Chile.digester.Ks_pro_T variable */) + DIVISION_SIM((tmp109 * tmp109),(data->simulationInfo->realParameter[214] /* Chile.digester.Ki_hpro_pro PARAM */),"Chile.digester.Ki_hpro_pro",equationIndexes),"Chile.digester.S_pro + Chile.digester.Ks_pro_T + Chile.digester.S_pro ^ 2.0 / Chile.digester.Ki_hpro_pro",equationIndexes));
  TRACE_POP
}
/*
equation index: 2787
type: SIMPLE_ASSIGN
Chile.digester.r1 = if noEvent(Chile.digester.noXc == true) then 0.0 else Chile.digester.k_dis * Chile.digester.X_c
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2787(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2787};
  (data->localData[0]->realVars[585] /* Chile.digester.r1 variable */) = (((!(data->simulationInfo->booleanParameter[14] /* Chile.digester.noXc PARAM */) && !1) || ((data->simulationInfo->booleanParameter[14] /* Chile.digester.noXc PARAM */) && 1))?0.0:((data->simulationInfo->realParameter[364] /* Chile.digester.k_dis PARAM */)) * ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)));
  TRACE_POP
}
/*
equation index: 2788
type: SIMPLE_ASSIGN
Chile.digester.r2[1] = Chile.digester.k_hyd_T[3] * Chile.digester.X_ch[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2788(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2788};
  (data->localData[0]->realVars[596] /* Chile.digester.r2[1] variable */) = ((data->localData[0]->realVars[565] /* Chile.digester.k_hyd_T[3] variable */)) * ((data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */));
  TRACE_POP
}
/*
equation index: 2789
type: SIMPLE_ASSIGN
Chile.digester.r2[2] = Chile.digester.k_hyd_T[4] * Chile.digester.X_ch[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2789(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2789};
  (data->localData[0]->realVars[597] /* Chile.digester.r2[2] variable */) = ((data->localData[0]->realVars[566] /* Chile.digester.k_hyd_T[4] variable */)) * ((data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */));
  TRACE_POP
}
/*
equation index: 2790
type: SIMPLE_ASSIGN
Chile.digester.r2[3] = Chile.digester.k_hyd_T[5] * Chile.digester.X_ch[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2790(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2790};
  (data->localData[0]->realVars[598] /* Chile.digester.r2[3] variable */) = ((data->localData[0]->realVars[567] /* Chile.digester.k_hyd_T[5] variable */)) * ((data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */));
  TRACE_POP
}
/*
equation index: 2791
type: SIMPLE_ASSIGN
Chile.digester.r3[1] = Chile.digester.k_hyd_T[6] * Chile.digester.X_pr[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2791(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2791};
  (data->localData[0]->realVars[599] /* Chile.digester.r3[1] variable */) = ((data->localData[0]->realVars[568] /* Chile.digester.k_hyd_T[6] variable */)) * ((data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */));
  TRACE_POP
}
/*
equation index: 2792
type: SIMPLE_ASSIGN
Chile.digester.r3[2] = Chile.digester.k_hyd_T[7] * Chile.digester.X_pr[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2792(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2792};
  (data->localData[0]->realVars[600] /* Chile.digester.r3[2] variable */) = ((data->localData[0]->realVars[569] /* Chile.digester.k_hyd_T[7] variable */)) * ((data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */));
  TRACE_POP
}
/*
equation index: 2793
type: SIMPLE_ASSIGN
Chile.digester.r4 = Chile.digester.k_hyd_T[8] * Chile.digester.X_li
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2793(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2793};
  (data->localData[0]->realVars[601] /* Chile.digester.r4 variable */) = ((data->localData[0]->realVars[570] /* Chile.digester.k_hyd_T[8] variable */)) * ((data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */));
  TRACE_POP
}
/*
equation index: 2794
type: SIMPLE_ASSIGN
Chile.digester.r13 = Chile.digester.k_dec_su_T * Chile.digester.X_su
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2794(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2794};
  (data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) = ((data->localData[0]->realVars[562] /* Chile.digester.k_dec_su_T variable */)) * ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */));
  TRACE_POP
}
/*
equation index: 2795
type: SIMPLE_ASSIGN
Chile.digester.r14 = Chile.digester.k_dec_aa_T * Chile.digester.X_aa
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2795(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2795};
  (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) = ((data->localData[0]->realVars[557] /* Chile.digester.k_dec_aa_T variable */)) * ((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */));
  TRACE_POP
}
/*
equation index: 2796
type: SIMPLE_ASSIGN
Chile.digester.r15 = Chile.digester.k_dec_fa_T * Chile.digester.X_fa
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2796(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2796};
  (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) = ((data->localData[0]->realVars[559] /* Chile.digester.k_dec_fa_T variable */)) * ((data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */));
  TRACE_POP
}
/*
equation index: 2797
type: SIMPLE_ASSIGN
Chile.digester.r16 = Chile.digester.k_dec_c4 * Chile.digester.X_c4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2797(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2797};
  (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) = ((data->simulationInfo->realParameter[359] /* Chile.digester.k_dec_c4 PARAM */)) * ((data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */));
  TRACE_POP
}
/*
equation index: 2798
type: SIMPLE_ASSIGN
Chile.digester.r17 = Chile.digester.k_dec_pro_T * Chile.digester.X_pro
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2798(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2798};
  (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) = ((data->localData[0]->realVars[561] /* Chile.digester.k_dec_pro_T variable */)) * ((data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */));
  TRACE_POP
}
/*
equation index: 2799
type: SIMPLE_ASSIGN
Chile.digester.r18 = Chile.digester.k_dec_ac_T * Chile.digester.X_ac
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2799(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2799};
  (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) = ((data->localData[0]->realVars[558] /* Chile.digester.k_dec_ac_T variable */)) * ((data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */));
  TRACE_POP
}
/*
equation index: 2800
type: SIMPLE_ASSIGN
Chile.digester.r19 = Chile.digester.k_dec_h2_T * Chile.digester.X_h2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2800(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2800};
  (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */) = ((data->localData[0]->realVars[560] /* Chile.digester.k_dec_h2_T variable */)) * ((data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */));
  TRACE_POP
}
/*
equation index: 2801
type: SIMPLE_ASSIGN
$DER.Chile.digester.charge = (-4000.0) * Chile.digester.charge
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2801(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2801};
  (data->localData[0]->realVars[137] /* der(Chile.digester.charge) STATE_DER */) = (-4000.0) * ((data->localData[0]->realVars[64] /* Chile.digester.charge STATE(1) */));
  TRACE_POP
}
/*
equation index: 2802
type: SIMPLE_ASSIGN
Chile.y_dig[2] = 60000.0 * (0.0156119900083264 * Chile.digester.S_ac + 0.008918929342795433 * Chile.digester.S_pro + 0.006242905788876278 * Chile.digester.S_bu + 0.004801572656267654 * Chile.digester.S_va)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2802(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2802};
  (data->localData[0]->realVars[1231] /* Chile.y_dig[2] variable */) = (60000.0) * ((0.0156119900083264) * ((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */)) + (0.008918929342795433) * ((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */)) + (0.006242905788876278) * ((data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */)) + (0.004801572656267654) * ((data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */)));
  TRACE_POP
}
/*
equation index: 2803
type: SIMPLE_ASSIGN
Chile.y_dig[6] = Chile.y_dig[2] / Chile.y_dig[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2803(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2803};
  (data->localData[0]->realVars[1235] /* Chile.y_dig[6] variable */) = DIVISION_SIM((data->localData[0]->realVars[1231] /* Chile.y_dig[2] variable */),(data->localData[0]->realVars[1232] /* Chile.y_dig[3] variable */),"Chile.y_dig[3]",equationIndexes);
  TRACE_POP
}
/*
equation index: 2804
type: SIMPLE_ASSIGN
Chile.y_dig[4] = 14000.0 * Chile.digester.S_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2804(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2804};
  (data->localData[0]->realVars[1233] /* Chile.y_dig[4] variable */) = (14000.0) * ((data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */));
  TRACE_POP
}
/*
equation index: 2805
type: SIMPLE_ASSIGN
Chile.digester.COD_tot = Chile.digester.S_aa + Chile.digester.S_ac + Chile.digester.S_bu + Chile.digester.S_ch4 + Chile.digester.S_fa + Chile.digester.S_h2 + Chile.digester.S_i + Chile.digester.S_pro + Chile.digester.S_su + Chile.digester.S_va + Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c + Chile.digester.X_c4 + Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3] + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_i + Chile.digester.X_li + Chile.digester.X_pr[1] + Chile.digester.X_pr[2] + Chile.digester.X_pro + Chile.digester.X_su + Chile.digester.X_lig + Chile.digester.X_p
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2805(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2805};
  (data->localData[0]->realVars[333] /* Chile.digester.COD_tot variable */) = (data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */) + (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */) + (data->localData[0]->realVars[23] /* Chile.digester.S_ch4 STATE(1) */) + (data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */) + (data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */) + (data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */) + (data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */) + (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */) + (data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */) + (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */) + (data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */);
  TRACE_POP
}
/*
equation index: 2806
type: SIMPLE_ASSIGN
Chile.digester.COD_tot_bd = Chile.digester.S_aa + Chile.digester.S_fa + Chile.digester.S_su + Chile.digester.X_c + Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3] + Chile.digester.X_li + Chile.digester.X_pr[1] + Chile.digester.X_pr[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2806(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2806};
  (data->localData[0]->realVars[334] /* Chile.digester.COD_tot_bd variable */) = (data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */) + (data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */) + (data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */) + (data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */) + (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */);
  TRACE_POP
}
/*
equation index: 2807
type: SIMPLE_ASSIGN
Chile.digester.acidogens = 0.7081346012633912 * (Chile.digester.X_su + Chile.digester.X_aa + Chile.digester.X_fa)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2807(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2807};
  (data->localData[0]->realVars[515] /* Chile.digester.acidogens variable */) = (0.7081346012633912) * ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */));
  TRACE_POP
}
/*
equation index: 2808
type: SIMPLE_ASSIGN
Chile.digester.methanogens = 0.7081346012633912 * (Chile.digester.X_ac + Chile.digester.X_h2 + Chile.digester.X_c4 + Chile.digester.X_pro)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2808(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2808};
  (data->localData[0]->realVars[581] /* Chile.digester.methanogens variable */) = (0.7081346012633912) * ((data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */));
  TRACE_POP
}
/*
equation index: 2809
type: SIMPLE_ASSIGN
Chile.digester.COD_s = Chile.digester.S_aa + Chile.digester.S_fa + Chile.digester.S_su
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2809(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2809};
  (data->localData[0]->realVars[330] /* Chile.digester.COD_s variable */) = (data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */);
  TRACE_POP
}
/*
equation index: 2810
type: SIMPLE_ASSIGN
Chile.comp_maize.timeScaled = time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2810(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2810};
  (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */) = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 2811
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.timeScaled = time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2811(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2811};
  (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */) = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 2812
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.timeScaled = time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2812(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2812};
  (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */) = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 2813
type: SIMPLE_ASSIGN
$DER.Chile.gasbag.V_gasbag = 0.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2813(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2813};
  (data->localData[0]->realVars[144] /* der(Chile.gasbag.V_gasbag) STATE_DER */) = 0.0;
  TRACE_POP
}
/*
equation index: 2814
type: SIMPLE_ASSIGN
Chile.atmosphere.p_gas_h2_in = Chile.gasbag.S_gas_h2 * 0.083145 * Chile.gasbag.T_op_mean / 16.0388
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2814(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2814};
  (data->localData[0]->realVars[175] /* Chile.atmosphere.p_gas_h2_in variable */) = DIVISION_SIM((((data->localData[0]->realVars[68] /* Chile.gasbag.S_gas_h2 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),16.0388,"16.0388",equationIndexes);
  TRACE_POP
}
/*
equation index: 2815
type: SIMPLE_ASSIGN
Chile.atmosphere.x_h2_in = Chile.atmosphere.p_gas_h2_in / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2815(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2815};
  (data->localData[0]->realVars[181] /* Chile.atmosphere.x_h2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[175] /* Chile.atmosphere.p_gas_h2_in variable */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2816
type: SIMPLE_ASSIGN
Chile.atmosphere.S_gas_h2_in = 16.0388 * Chile.atmosphere.p_gas_h2_in / (0.083145 * Chile.atmosphere.T_op_mean)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2816(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2816};
  (data->localData[0]->realVars[162] /* Chile.atmosphere.S_gas_h2_in variable */) = (16.0388) * (DIVISION_SIM((data->localData[0]->realVars[175] /* Chile.atmosphere.p_gas_h2_in variable */),(0.083145) * ((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */)),"0.083145 * Chile.atmosphere.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2817
type: SIMPLE_ASSIGN
Chile.atmosphere.p_gas_ch4_in = Chile.gasbag.S_gas_ch4 * 0.083145 * Chile.gasbag.T_op_mean / 63.9996
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2817(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2817};
  (data->localData[0]->realVars[173] /* Chile.atmosphere.p_gas_ch4_in variable */) = DIVISION_SIM((((data->localData[0]->realVars[66] /* Chile.gasbag.S_gas_ch4 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)),63.9996,"63.9996",equationIndexes);
  TRACE_POP
}
/*
equation index: 2818
type: SIMPLE_ASSIGN
Chile.atmosphere.x_ch4_in = Chile.atmosphere.p_gas_ch4_in / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2818(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2818};
  (data->localData[0]->realVars[178] /* Chile.atmosphere.x_ch4_in variable */) = DIVISION_SIM((data->localData[0]->realVars[173] /* Chile.atmosphere.p_gas_ch4_in variable */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2819
type: SIMPLE_ASSIGN
Chile.atmosphere.S_gas_ch4_in = 63.9996 * Chile.atmosphere.p_gas_ch4_in / (0.083145 * Chile.atmosphere.T_op_mean)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2819(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2819};
  (data->localData[0]->realVars[160] /* Chile.atmosphere.S_gas_ch4_in variable */) = (63.9996) * (DIVISION_SIM((data->localData[0]->realVars[173] /* Chile.atmosphere.p_gas_ch4_in variable */),(0.083145) * ((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */)),"0.083145 * Chile.atmosphere.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2820
type: SIMPLE_ASSIGN
Chile.atmosphere.p_gas_co2_in = 0.083145 * Chile.gasbag.S_gas_co2 * Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2820(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2820};
  (data->localData[0]->realVars[174] /* Chile.atmosphere.p_gas_co2_in variable */) = (0.083145) * (((data->localData[0]->realVars[67] /* Chile.gasbag.S_gas_co2 STATE(1) */)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)));
  TRACE_POP
}
/*
equation index: 2821
type: SIMPLE_ASSIGN
Chile.atmosphere.x_co2_in = Chile.atmosphere.p_gas_co2_in / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2821(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2821};
  (data->localData[0]->realVars[179] /* Chile.atmosphere.x_co2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[174] /* Chile.atmosphere.p_gas_co2_in variable */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2822
type: SIMPLE_ASSIGN
Chile.atmosphere.S_gas_co2_in = 12.02718143003187 * Chile.atmosphere.p_gas_co2_in / Chile.atmosphere.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2822(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2822};
  (data->localData[0]->realVars[161] /* Chile.atmosphere.S_gas_co2_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[174] /* Chile.atmosphere.p_gas_co2_in variable */),(data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),"Chile.atmosphere.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2823
type: SIMPLE_ASSIGN
Chile.atmosphere.p_gas_nh3_in = 0.083145 * Chile.gasbag.S_gas_nh3 * Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2823(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2823};
  (data->localData[0]->realVars[177] /* Chile.atmosphere.p_gas_nh3_in variable */) = (0.083145) * (((data->localData[0]->realVars[70] /* Chile.gasbag.S_gas_nh3 STATE(1) */)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)));
  TRACE_POP
}
/*
equation index: 2824
type: SIMPLE_ASSIGN
Chile.atmosphere.x_nh3_in = Chile.atmosphere.p_gas_nh3_in / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2824(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2824};
  (data->localData[0]->realVars[185] /* Chile.atmosphere.x_nh3_in variable */) = DIVISION_SIM((data->localData[0]->realVars[177] /* Chile.atmosphere.p_gas_nh3_in variable */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2825
type: SIMPLE_ASSIGN
Chile.atmosphere.S_gas_nh3_in = 12.02718143003187 * Chile.atmosphere.p_gas_nh3_in / Chile.atmosphere.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2825(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2825};
  (data->localData[0]->realVars[164] /* Chile.atmosphere.S_gas_nh3_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[177] /* Chile.atmosphere.p_gas_nh3_in variable */),(data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),"Chile.atmosphere.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2826
type: SIMPLE_ASSIGN
Chile.atmosphere.p_gas_n2_in = 0.083145 * Chile.gasbag.S_gas_n2 * Chile.gasbag.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2826(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2826};
  (data->localData[0]->realVars[176] /* Chile.atmosphere.p_gas_n2_in variable */) = (0.083145) * (((data->localData[0]->realVars[69] /* Chile.gasbag.S_gas_n2 STATE(1) */)) * ((data->simulationInfo->realParameter[483] /* Chile.gasbag.T_op_mean PARAM */)));
  TRACE_POP
}
/*
equation index: 2827
type: SIMPLE_ASSIGN
Chile.atmosphere.x_n2_in = Chile.atmosphere.p_gas_n2_in / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2827(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2827};
  (data->localData[0]->realVars[183] /* Chile.atmosphere.x_n2_in variable */) = DIVISION_SIM((data->localData[0]->realVars[176] /* Chile.atmosphere.p_gas_n2_in variable */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes);
  TRACE_POP
}
/*
equation index: 2828
type: SIMPLE_ASSIGN
Chile.atmosphere.S_gas_n2_in = 12.02718143003187 * Chile.atmosphere.p_gas_n2_in / Chile.atmosphere.T_op_mean
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2828(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2828};
  (data->localData[0]->realVars[163] /* Chile.atmosphere.S_gas_n2_in variable */) = (12.02718143003187) * (DIVISION_SIM((data->localData[0]->realVars[176] /* Chile.atmosphere.p_gas_n2_in variable */),(data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),"Chile.atmosphere.T_op_mean",equationIndexes));
  TRACE_POP
}
/*
equation index: 2829
type: SIMPLE_ASSIGN
$DER.Chile.atmosphere.S_gas_ch4 = 1.157407407407407e-17 - Chile.atmosphere.S_gas_ch4 / 86400000000.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2829(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2829};
  (data->localData[0]->realVars[73] /* der(Chile.atmosphere.S_gas_ch4) STATE_DER */) = 1.157407407407407e-17 - (DIVISION_SIM((data->localData[0]->realVars[0] /* Chile.atmosphere.S_gas_ch4 STATE(1) */),86400000000.0,"86400000000.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2830
type: SIMPLE_ASSIGN
$DER.Chile.atmosphere.S_gas_co2 = 4.62962962962963e-15 - Chile.atmosphere.S_gas_co2 / 86400000000.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2830(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2830};
  (data->localData[0]->realVars[74] /* der(Chile.atmosphere.S_gas_co2) STATE_DER */) = 4.62962962962963e-15 - (DIVISION_SIM((data->localData[0]->realVars[1] /* Chile.atmosphere.S_gas_co2 STATE(1) */),86400000000.0,"86400000000.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2831
type: SIMPLE_ASSIGN
$DER.Chile.atmosphere.S_gas_h2 = 1.157407407407407e-17 - Chile.atmosphere.S_gas_h2 / 86400000000.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2831(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2831};
  (data->localData[0]->realVars[75] /* der(Chile.atmosphere.S_gas_h2) STATE_DER */) = 1.157407407407407e-17 - (DIVISION_SIM((data->localData[0]->realVars[2] /* Chile.atmosphere.S_gas_h2 STATE(1) */),86400000000.0,"86400000000.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2832
type: SIMPLE_ASSIGN
$DER.Chile.atmosphere.S_gas_n2 = 8.101851851851852e-12 - Chile.atmosphere.S_gas_n2 / 86400000000.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2832(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2832};
  (data->localData[0]->realVars[76] /* der(Chile.atmosphere.S_gas_n2) STATE_DER */) = 8.101851851851852e-12 - (DIVISION_SIM((data->localData[0]->realVars[3] /* Chile.atmosphere.S_gas_n2 STATE(1) */),86400000000.0,"86400000000.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2833
type: SIMPLE_ASSIGN
Chile.atmosphere.x_h2 = Chile.atmosphere.S_gas_h2 * 0.083145 * Chile.atmosphere.T_op_mean / (16.0388 * (1.035 - Chile.gasbag.outlet.p_gas_h2o))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2833(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2833};
  (data->localData[0]->realVars[180] /* Chile.atmosphere.x_h2 variable */) = DIVISION_SIM((((data->localData[0]->realVars[2] /* Chile.atmosphere.S_gas_h2 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */)),(16.0388) * (1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */)),"16.0388 * (1.035 - Chile.gasbag.outlet.p_gas_h2o)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2834
type: SIMPLE_ASSIGN
Chile.atmosphere.Q_h2_N = 1000.0 * Chile.atmosphere.y[1] * Chile.atmosphere.x_h2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2834(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2834};
  (data->localData[0]->realVars[158] /* Chile.atmosphere.Q_h2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[180] /* Chile.atmosphere.x_h2 variable */)));
  TRACE_POP
}
/*
equation index: 2835
type: SIMPLE_ASSIGN
Chile.atmosphere.y[2] = Chile.atmosphere.S_gas_ch4 * 0.083145 * Chile.atmosphere.T_op_mean / (63.9996 * (1.035 - Chile.gasbag.outlet.p_gas_h2o))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2835(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2835};
  (data->localData[0]->realVars[187] /* Chile.atmosphere.y[2] variable */) = DIVISION_SIM((((data->localData[0]->realVars[0] /* Chile.atmosphere.S_gas_ch4 STATE(1) */)) * (0.083145)) * ((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */)),(63.9996) * (1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */)),"63.9996 * (1.035 - Chile.gasbag.outlet.p_gas_h2o)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2836
type: SIMPLE_ASSIGN
Chile.atmosphere.Q_ch4_N = 1000.0 * Chile.atmosphere.y[1] * Chile.atmosphere.y[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2836(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2836};
  (data->localData[0]->realVars[156] /* Chile.atmosphere.Q_ch4_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[187] /* Chile.atmosphere.y[2] variable */)));
  TRACE_POP
}
/*
equation index: 2837
type: SIMPLE_ASSIGN
Chile.atmosphere.y[3] = 0.083145 * Chile.atmosphere.S_gas_co2 * Chile.atmosphere.T_op_mean / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2837(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2837};
  (data->localData[0]->realVars[188] /* Chile.atmosphere.y[3] variable */) = (0.083145) * (((data->localData[0]->realVars[1] /* Chile.atmosphere.S_gas_co2 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2838
type: SIMPLE_ASSIGN
Chile.atmosphere.Q_co2_N = 1000.0 * Chile.atmosphere.y[1] * Chile.atmosphere.y[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2838(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2838};
  (data->localData[0]->realVars[157] /* Chile.atmosphere.Q_co2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[188] /* Chile.atmosphere.y[3] variable */)));
  TRACE_POP
}
/*
equation index: 2839
type: SIMPLE_ASSIGN
Chile.atmosphere.x_n2 = 0.083145 * Chile.atmosphere.S_gas_n2 * Chile.atmosphere.T_op_mean / (1.035 - Chile.gasbag.outlet.p_gas_h2o)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2839(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2839};
  (data->localData[0]->realVars[182] /* Chile.atmosphere.x_n2 variable */) = (0.083145) * (((data->localData[0]->realVars[3] /* Chile.atmosphere.S_gas_n2 STATE(1) */)) * (DIVISION_SIM((data->simulationInfo->realParameter[16] /* Chile.atmosphere.T_op_mean PARAM */),1.035 - (data->localData[0]->realVars[663] /* Chile.gasbag.outlet.p_gas_h2o variable */),"1.035 - Chile.gasbag.outlet.p_gas_h2o",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2840
type: SIMPLE_ASSIGN
Chile.atmosphere.Q_n2_N = 1000.0 * Chile.atmosphere.y[1] * Chile.atmosphere.x_n2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2840(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2840};
  (data->localData[0]->realVars[159] /* Chile.atmosphere.Q_n2_N variable */) = (1000.0) * (((data->localData[0]->realVars[186] /* Chile.atmosphere.y[1] variable */)) * ((data->localData[0]->realVars[182] /* Chile.atmosphere.x_n2 variable */)));
  TRACE_POP
}
/*
equation index: 2841
type: SIMPLE_ASSIGN
Manual_flowrates_real.timeScaled = time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2841(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2841};
  (data->localData[0]->realVars[1241] /* Manual_flowrates_real.timeScaled variable */) = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 2842
type: SIMPLE_ASSIGN
$whenCondition4 = time >= pre(Manual_flowrates_real.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2842(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2842};
  modelica_boolean tmp111;
  relationhysteresis(data, &tmp111, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1262] /* Manual_flowrates_real.nextTimeEvent DISCRETE */), 5, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[3] /* $whenCondition4 DISCRETE */) = tmp111;
  TRACE_POP
}
/*
equation index: 2843
type: WHEN

when {$whenCondition4} then
  Manual_flowrates_real.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Manual_flowrates_real.tableID, Manual_flowrates_real.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2843(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2843};
  if(((data->localData[0]->booleanVars[3] /* $whenCondition4 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[3] /* $whenCondition4 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[5]), (data->localData[0]->realVars[1241] /* Manual_flowrates_real.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 2844
type: SIMPLE_ASSIGN
Manual_flowrates_real.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates_real.tableID, 1, Manual_flowrates_real.timeScaled, Manual_flowrates_real.nextTimeEventScaled, pre(Manual_flowrates_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2844(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2844};
  (data->localData[0]->realVars[1242] /* Manual_flowrates_real.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[5]), ((modelica_integer) 1), (data->localData[0]->realVars[1241] /* Manual_flowrates_real.timeScaled variable */), (data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2845
type: SIMPLE_ASSIGN
Chile.q[3] = if impulse then 0.000288 * Manual_flowrates_real.y[1] else if not impulse then silage_bar.k else 1e-10
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2845(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2845};
  (data->localData[0]->realVars[872] /* Chile.q[3] variable */) = ((data->simulationInfo->booleanParameter[37] /* impulse PARAM */)?(0.000288) * ((data->localData[0]->realVars[1242] /* Manual_flowrates_real.y[1] variable */)):((!(data->simulationInfo->booleanParameter[37] /* impulse PARAM */))?(data->simulationInfo->realParameter[1246] /* silage_bar.k PARAM */):1e-10));
  TRACE_POP
}
/*
equation index: 2846
type: SIMPLE_ASSIGN
$cse1 = max(Chile.q[3], 1e-19)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2846(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2846};
  (data->localData[0]->realVars[148] /* $cse1 variable */) = fmax((data->localData[0]->realVars[872] /* Chile.q[3] variable */),1e-19);
  TRACE_POP
}
/*
equation index: 2847
type: SIMPLE_ASSIGN
Manual_flowrates_real.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates_real.tableID, 2, Manual_flowrates_real.timeScaled, Manual_flowrates_real.nextTimeEventScaled, pre(Manual_flowrates_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2847(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2847};
  (data->localData[0]->realVars[1243] /* Manual_flowrates_real.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[5]), ((modelica_integer) 2), (data->localData[0]->realVars[1241] /* Manual_flowrates_real.timeScaled variable */), (data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2848
type: SIMPLE_ASSIGN
Chile.q[2] = if impulse then 0.000288 * Manual_flowrates_real.y[2] else if not impulse then slurry_bar.k else 1e-10
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2848(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2848};
  (data->localData[0]->realVars[871] /* Chile.q[2] variable */) = ((data->simulationInfo->booleanParameter[37] /* impulse PARAM */)?(0.000288) * ((data->localData[0]->realVars[1243] /* Manual_flowrates_real.y[2] variable */)):((!(data->simulationInfo->booleanParameter[37] /* impulse PARAM */))?(data->simulationInfo->realParameter[1250] /* slurry_bar.k PARAM */):1e-10));
  TRACE_POP
}
/*
equation index: 2849
type: SIMPLE_ASSIGN
$cse3 = max(Chile.q[2], 1e-19)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2849(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2849};
  (data->localData[0]->realVars[150] /* $cse3 variable */) = fmax((data->localData[0]->realVars[871] /* Chile.q[2] variable */),1e-19);
  TRACE_POP
}
/*
equation index: 2850
type: SIMPLE_ASSIGN
Manual_flowrates_real.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Manual_flowrates_real.tableID, 3, Manual_flowrates_real.timeScaled, Manual_flowrates_real.nextTimeEventScaled, pre(Manual_flowrates_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2850(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2850};
  (data->localData[0]->realVars[1244] /* Manual_flowrates_real.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[5]), ((modelica_integer) 3), (data->localData[0]->realVars[1241] /* Manual_flowrates_real.timeScaled variable */), (data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2851
type: SIMPLE_ASSIGN
Chile.q[1] = 1e-06 * Manual_flowrates_real.y[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2851(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2851};
  (data->localData[0]->realVars[870] /* Chile.q[1] variable */) = (1e-06) * ((data->localData[0]->realVars[1244] /* Manual_flowrates_real.y[3] variable */));
  TRACE_POP
}
/*
equation index: 2852
type: SIMPLE_ASSIGN
$cse2 = max(Chile.q[1], 1e-19)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2852(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2852};
  (data->localData[0]->realVars[149] /* $cse2 variable */) = fmax((data->localData[0]->realVars[870] /* Chile.q[1] variable */),1e-19);
  TRACE_POP
}
/*
equation index: 2853
type: SIMPLE_ASSIGN
Chile.digester.X_ac_in = ($cse1 * Chile.maize.xac + $cse2 * Chile.tomatosouce.xac + $cse3 * Chile.slurry.xac) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2853(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2853};
  (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2854
type: SIMPLE_ASSIGN
Chile.digester.X_pro_in = ($cse1 * Chile.maize.xpro + $cse2 * Chile.tomatosouce.xpro + $cse3 * Chile.slurry.xpro) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2854(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2854};
  (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2855
type: SIMPLE_ASSIGN
Chile.digester.X_c4_in = ($cse1 * Chile.maize.xc4 + $cse2 * Chile.tomatosouce.xc4 + $cse3 * Chile.slurry.xc4) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2855(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2855};
  (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2856
type: SIMPLE_ASSIGN
Chile.digester.X_fa_in = ($cse1 * Chile.maize.xfa + $cse2 * Chile.tomatosouce.xfa + $cse3 * Chile.slurry.xfa) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2856(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2856};
  (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2857
type: SIMPLE_ASSIGN
Chile.digester.X_aa_in = ($cse1 * Chile.maize.xaa + $cse2 * Chile.tomatosouce.xaa + $cse3 * Chile.slurry.xaa) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2857(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2857};
  (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2858
type: SIMPLE_ASSIGN
Chile.digester.X_su_in = ($cse1 * Chile.maize.xsu + $cse2 * Chile.tomatosouce.xsu + $cse3 * Chile.slurry.xsu) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2858(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2858};
  (data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2859
type: SIMPLE_ASSIGN
Chile.digester.S_an_in = ($cse1 * Chile.maize.an + $cse2 * Chile.tomatosouce.an + $cse3 * Chile.slurry.an) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2859(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2859};
  (data->localData[0]->realVars[432] /* Chile.digester.S_an_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[585] /* Chile.maize.an PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[993] /* Chile.tomatosouce.an PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[787] /* Chile.slurry.an PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2860
type: SIMPLE_ASSIGN
Chile.digester.S_ch4_in = ($cse1 * Chile.maize.ch4 + $cse2 * Chile.tomatosouce.ch4 + $cse3 * Chile.slurry.ch4) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2860(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2860};
  (data->localData[0]->realVars[437] /* Chile.digester.S_ch4_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[594] /* Chile.maize.ch4 PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1002] /* Chile.tomatosouce.ch4 PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[796] /* Chile.slurry.ch4 PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2861
type: SIMPLE_ASSIGN
Chile.digester.S_h2_in = ($cse1 * Chile.maize.h2 + $cse2 * Chile.tomatosouce.h2 + $cse3 * Chile.slurry.h2) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2861(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2861};
  (data->localData[0]->realVars[441] /* Chile.digester.S_h2_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[616] /* Chile.maize.h2 PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1024] /* Chile.tomatosouce.h2 PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[818] /* Chile.slurry.h2 PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2862
type: SIMPLE_ASSIGN
Chile.digester.X_h2_in = ($cse1 * Chile.maize.xh2 + $cse2 * Chile.tomatosouce.xh2 + $cse3 * Chile.slurry.xh2) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2862(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2862};
  (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2863
type: SIMPLE_ASSIGN
Chile.digester.S_i_in[4] = ($cse1 * Chile.maize.si + $cse2 * Chile.tomatosouce.si + $cse3 * Chile.slurry.si) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2863(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2863};
  (data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2864
type: SIMPLE_ASSIGN
Chile.digester.S_i_in[3] = ($cse1 * Chile.maize.si + $cse2 * Chile.tomatosouce.si + $cse3 * Chile.slurry.si) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2864(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2864};
  (data->localData[0]->realVars[448] /* Chile.digester.S_i_in[3] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2865
type: SIMPLE_ASSIGN
Chile.digester.f_si[3] = if noEvent(Chile.digester.S_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.S_i_in[3] / Chile.digester.S_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2865(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2865};
  modelica_boolean tmp112;
  tmp112 = Less((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */) = (tmp112?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[448] /* Chile.digester.S_i_in[3] variable */),(data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),"Chile.digester.S_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 2866
type: SIMPLE_ASSIGN
Chile.digester.i_SI[5] = 0.0003421741796374586 * Chile.digester.f_si[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2866(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2866};
  (data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */) = (0.0003421741796374586) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */));
  TRACE_POP
}
/*
equation index: 2867
type: SIMPLE_ASSIGN
Chile.digester.LI_sol = 0.3532661514862131 * (Chile.digester.S_fa + Chile.digester.S_i * Chile.digester.f_si[3])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2867(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2867};
  (data->localData[0]->realVars[388] /* Chile.digester.LI_sol variable */) = (0.3532661514862131) * ((data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */)));
  TRACE_POP
}
/*
equation index: 2868
type: SIMPLE_ASSIGN
Chile.digester.S_i_in[2] = ($cse1 * Chile.maize.si + $cse2 * Chile.tomatosouce.si + $cse3 * Chile.slurry.si) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2868(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2868};
  (data->localData[0]->realVars[447] /* Chile.digester.S_i_in[2] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2869
type: SIMPLE_ASSIGN
Chile.digester.f_si[2] = if noEvent(Chile.digester.S_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.S_i_in[2] / Chile.digester.S_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2869(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2869};
  modelica_boolean tmp113;
  tmp113 = Less((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */) = (tmp113?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[447] /* Chile.digester.S_i_in[2] variable */),(data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),"Chile.digester.S_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 2870
type: SIMPLE_ASSIGN
Chile.digester.i_SI[4] = 0.00748502994011976 * Chile.digester.f_si[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2870(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2870};
  (data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */) = (0.00748502994011976) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */));
  TRACE_POP
}
/*
equation index: 2871
type: SIMPLE_ASSIGN
Chile.digester.n13 = 0.006078672612418971 + (-0.00748502994011976) * Chile.digester.f_pr_xb + (-0.0043) * Chile.digester.f_xi_xb - Chile.digester.i_SI[4] * Chile.digester.f_si_xb
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2871(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2871};
  (data->localData[0]->realVars[583] /* Chile.digester.n13 variable */) = 0.006078672612418971 + (-0.00748502994011976) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)) + (-0.0043) * ((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */)) - (((data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */)) * ((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */)));
  TRACE_POP
}
/*
equation index: 2872
type: SIMPLE_ASSIGN
Chile.digester.PR_sol_BCA = (Chile.digester.S_aa + Chile.digester.S_i * Chile.digester.f_si[2]) / Chile.digester.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2872(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2872};
  (data->localData[0]->realVars[418] /* Chile.digester.PR_sol_BCA variable */) = DIVISION_SIM((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)),(data->simulationInfo->realParameter[191] /* Chile.digester.COD_VS_PR_BCA PARAM */),"Chile.digester.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 2873
type: SIMPLE_ASSIGN
Chile.digester.PR_sol_TKN = 0.6534431137724552 * (Chile.digester.S_aa + Chile.digester.S_i * Chile.digester.f_si[2]) / Chile.digester.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2873(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2873};
  (data->localData[0]->realVars[419] /* Chile.digester.PR_sol_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)),(data->simulationInfo->realParameter[240] /* Chile.digester.N_PR PARAM */),"Chile.digester.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 2874
type: SIMPLE_ASSIGN
Chile.digester.S_i_in[1] = ($cse1 * Chile.maize.si + $cse2 * Chile.tomatosouce.si + $cse3 * Chile.slurry.si) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2874(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2874};
  (data->localData[0]->realVars[446] /* Chile.digester.S_i_in[1] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 2875
type: SIMPLE_ASSIGN
Chile.digester.f_si[1] = if noEvent(Chile.digester.S_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.S_i_in[1] / Chile.digester.S_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2875(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2875};
  modelica_boolean tmp114;
  tmp114 = Less((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */) = (tmp114?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[446] /* Chile.digester.S_i_in[1] variable */),(data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),"Chile.digester.S_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 2876
type: SIMPLE_ASSIGN
Chile.digester.i_SI[1] = 0.03125 * Chile.digester.f_si[1] + 0.02994011976047905 * Chile.digester.f_si[2] + 0.02168188132480155 * Chile.digester.f_si[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2876(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2876};
  (data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */) = (0.03125) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)) + (0.02168188132480155) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */));
  TRACE_POP
}
/*
equation index: 2877
type: SIMPLE_ASSIGN
Chile.digester.v13 = -0.03039336306209486 + 0.02994011976047905 * Chile.digester.f_pr_xb + 0.03125 * Chile.digester.f_ch_xb + 0.02168188132480155 * Chile.digester.f_li_xb + 0.0301 * Chile.digester.f_xi_xb + Chile.digester.i_SI[1] * Chile.digester.f_si_xb
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2877(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2877};
  (data->localData[0]->realVars[636] /* Chile.digester.v13 variable */) = -0.03039336306209486 + (0.02994011976047905) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)) + (0.03125) * ((data->simulationInfo->realParameter[318] /* Chile.digester.f_ch_xb PARAM */)) + (0.02168188132480155) * ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)) + (0.0301) * ((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */)) + ((data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */)) * ((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */));
  TRACE_POP
}
/*
equation index: 2878
type: SIMPLE_ASSIGN
Chile.digester.CH_sol = 0.9345794392523364 * Chile.digester.S_su + 0.84375 * Chile.digester.S_i * Chile.digester.f_si[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2878(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2878};
  (data->localData[0]->realVars[297] /* Chile.digester.CH_sol variable */) = (0.9345794392523364) * ((data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */)) + (0.84375) * (((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)));
  TRACE_POP
}
/*
equation index: 2879
type: SIMPLE_ASSIGN
Chile.digester.COD_VS[13] = 1.0 / (0.84375 * Chile.digester.f_si[1] + Chile.digester.f_si[3] / 2.830726906025207 + Chile.digester.f_si[2] / 1.530355097365406)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2879(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2879};
  (data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */) = DIVISION_SIM(1.0,(0.84375) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes),"0.84375 * Chile.digester.f_si[1] + Chile.digester.f_si[3] / 2.830726906025207 + Chile.digester.f_si[2] / 1.530355097365406",equationIndexes);
  TRACE_POP
}
/*
equation index: 2880
type: SIMPLE_ASSIGN
Chile.digester.MW[13] = 1.0 / (Chile.digester.COD_VS[13] * (Chile.digester.f_si[1] / 192.0 + Chile.digester.f_si[3] / 2352.194407671715 + Chile.digester.f_si[2] / 133.6))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2880(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2880};
  (data->localData[0]->realVars[402] /* Chile.digester.MW[13] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */),133.6,"133.6",equationIndexes)),"Chile.digester.COD_VS[13] * (Chile.digester.f_si[1] / 192.0 + Chile.digester.f_si[3] / 2352.194407671715 + Chile.digester.f_si[2] / 133.6)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2881
type: SIMPLE_ASSIGN
Chile.digester.Q = Chile.q[3] - ((-Chile.q[2]) - Chile.q[1])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2881(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2881};
  (data->localData[0]->realVars[423] /* Chile.digester.Q variable */) = (data->localData[0]->realVars[872] /* Chile.q[3] variable */) - ((-(data->localData[0]->realVars[871] /* Chile.q[2] variable */)) - (data->localData[0]->realVars[870] /* Chile.q[1] variable */));
  TRACE_POP
}
/*
equation index: 2882
type: SIMPLE_ASSIGN
Chile.digester.HRT = 0.012 / (1e-10 + Chile.digester.Q)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2882(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2882};
  (data->localData[0]->realVars[336] /* Chile.digester.HRT variable */) = DIVISION_SIM(0.012,1e-10 + (data->localData[0]->realVars[423] /* Chile.digester.Q variable */),"1e-10 + Chile.digester.Q",equationIndexes);
  TRACE_POP
}
/*
equation index: 2883
type: SIMPLE_ASSIGN
Chile.digester.COD_balance_out = (-Chile.digester.Q) * (Chile.digester.COD_sol + Chile.digester.COD_X)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2883(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2883};
  (data->localData[0]->realVars[329] /* Chile.digester.COD_balance_out variable */) = ((-(data->localData[0]->realVars[423] /* Chile.digester.Q variable */))) * ((data->localData[0]->realVars[332] /* Chile.digester.COD_sol variable */) + (data->localData[0]->realVars[326] /* Chile.digester.COD_X variable */));
  TRACE_POP
}
/*
equation index: 2884
type: SIMPLE_ASSIGN
$DER.Chile.digester.COD_balance_out_cum = Chile.digester.COD_balance_out / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2884(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2884};
  (data->localData[0]->realVars[81] /* der(Chile.digester.COD_balance_out_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[329] /* Chile.digester.COD_balance_out variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2885
type: SIMPLE_ASSIGN
$DER.Chile.digester.V_in_cum = Chile.digester.Q / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2885(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2885};
  (data->localData[0]->realVars[112] /* der(Chile.digester.V_in_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[423] /* Chile.digester.Q variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2886
type: SIMPLE_ASSIGN
$DER.Chile.digester.Vcum = Chile.digester.Q / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2886(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2886};
  (data->localData[0]->realVars[113] /* der(Chile.digester.Vcum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[423] /* Chile.digester.Q variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2887
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_c = 0.0009645061728395061 * Chile.digester.Q * (1e-10 - Chile.digester.X_c) - Chile.digester.r1 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2887(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2887};
  (data->localData[0]->realVars[118] /* der(Chile.digester.X_c) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (1e-10 - (data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */))) - (DIVISION_SIM((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 2888
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_p = 0.0009645061728395061 * (-Chile.digester.Q) * Chile.digester.X_p + Chile.digester.f_xi_xb * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2888(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2888};
  (data->localData[0]->realVars[130] /* der(Chile.digester.X_p) STATE_DER */) = (0.0009645061728395061) * (((-(data->localData[0]->realVars[423] /* Chile.digester.Q variable */))) * ((data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2889
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_i = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_i_in[4] - Chile.digester.S_i) + (Chile.digester.f_si_xb * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) + Chile.digester.f_xc[5] * Chile.digester.r1) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2889(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2889};
  (data->localData[0]->realVars[104] /* der(Chile.digester.S_i) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */) - (data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2890
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_h2 = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_h2_in - Chile.digester.S_h2) + (1.0 - Chile.digester.Y_su) * Chile.digester.f_h2_su * Chile.digester.r5 / 86400.0 + (1.0 - Chile.digester.Y_aa) * Chile.digester.f_h2_aa * Chile.digester.r6 / 86400.0 + 3.472222222222222e-06 * (1.0 - Chile.digester.Y_fa) * Chile.digester.r7 + 1.736111111111111e-06 * (1.0 - Chile.digester.Y_c4) * Chile.digester.r8 + 2.314814814814815e-06 * (1.0 - Chile.digester.Y_c4) * Chile.digester.r9 + 4.976851851851851e-06 * (1.0 - Chile.digester.Y_pro) * Chile.digester.r10 + ((-Chile.digester.r12) - Chile.digester.rt8) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2890(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2890};
  (data->localData[0]->realVars[103] /* der(Chile.digester.S_h2) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[441] /* Chile.digester.S_h2_in variable */) - (data->localData[0]->realVars[30] /* Chile.digester.S_h2 STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * (((data->localData[0]->realVars[523] /* Chile.digester.f_h2_su variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))),86400.0,"86400.0",equationIndexes) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * (((data->simulationInfo->realParameter[320] /* Chile.digester.f_h2_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))),86400.0,"86400.0",equationIndexes) + (3.472222222222222e-06) * ((1.0 - (data->simulationInfo->realParameter[305] /* Chile.digester.Y_fa PARAM */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */))) + (1.736111111111111e-06) * ((1.0 - (data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) + (2.314814814814815e-06) * ((1.0 - (data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */))) + (4.976851851851851e-06) * ((1.0 - (data->simulationInfo->realParameter[307] /* Chile.digester.Y_pro PARAM */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */))) + DIVISION_SIM((-(data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)) - (data->localData[0]->realVars[623] /* Chile.digester.rt8 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2891
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_su = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_su_in - Chile.digester.X_su) + (Chile.digester.Y_su * Chile.digester.r5 - Chile.digester.r13) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2891(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2891};
  (data->localData[0]->realVars[135] /* der(Chile.digester.X_su) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) - (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */)) - (data->localData[0]->realVars[589] /* Chile.digester.r13 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2892
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_aa = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_aa_in - Chile.digester.X_aa) + (Chile.digester.Y_aa * Chile.digester.r6 - Chile.digester.r14) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2892(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2892};
  (data->localData[0]->realVars[115] /* der(Chile.digester.X_aa) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) - (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */)) - (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2893
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_fa = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_fa_in - Chile.digester.X_fa) + (Chile.digester.Y_fa * Chile.digester.r7 - Chile.digester.r15) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2893(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2893};
  (data->localData[0]->realVars[124] /* der(Chile.digester.X_fa) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) - (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[305] /* Chile.digester.Y_fa PARAM */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */)) - (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2894
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_c4 = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_c4_in - Chile.digester.X_c4) + (Chile.digester.Y_c4 * Chile.digester.r8 + Chile.digester.Y_c4 * Chile.digester.r9 - Chile.digester.r16) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2894(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2894};
  (data->localData[0]->realVars[119] /* der(Chile.digester.X_c4) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) - (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */)) + ((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */)) - (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2895
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_pro = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_pro_in - Chile.digester.X_pro) + (Chile.digester.Y_pro * Chile.digester.r10 - Chile.digester.r17) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2895(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2895};
  (data->localData[0]->realVars[133] /* der(Chile.digester.X_pro) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) - (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[307] /* Chile.digester.Y_pro PARAM */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */)) - (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2896
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_h2 = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_h2_in - Chile.digester.X_h2) + (Chile.digester.Y_h2 * Chile.digester.r12 - Chile.digester.r19) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2896(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2896};
  (data->localData[0]->realVars[125] /* der(Chile.digester.X_h2) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */) - (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[306] /* Chile.digester.Y_h2 PARAM */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)) - (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 2897
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_an = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_an_in - Chile.digester.S_an)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2897(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2897};
  (data->localData[0]->realVars[92] /* der(Chile.digester.S_an) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[432] /* Chile.digester.S_an_in variable */) - (data->localData[0]->realVars[19] /* Chile.digester.S_an STATE(1) */)));
  TRACE_POP
}
/*
equation index: 2898
type: WHEN

when {$whenCondition4} then
  Manual_flowrates_real.nextTimeEvent = if Manual_flowrates_real.nextTimeEventScaled < 9.999999999999999e+59 then Manual_flowrates_real.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2898(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2898};
  modelica_boolean tmp115;
  if(((data->localData[0]->booleanVars[3] /* $whenCondition4 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[3] /* $whenCondition4 DISCRETE */) /* edge */))
  {
    tmp115 = Less((data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1262] /* Manual_flowrates_real.nextTimeEvent DISCRETE */) = (tmp115?(data->localData[0]->realVars[1263] /* Manual_flowrates_real.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 2899
type: SIMPLE_ASSIGN
$whenCondition5 = time >= pre(Chile.comp_slurry_real.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2899(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2899};
  modelica_boolean tmp116;
  relationhysteresis(data, &tmp116, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1255] /* Chile.comp_slurry_real.nextTimeEvent DISCRETE */), 4, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[4] /* $whenCondition5 DISCRETE */) = tmp116;
  TRACE_POP
}
/*
equation index: 2900
type: WHEN

when {$whenCondition5} then
  Chile.comp_slurry_real.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Chile.comp_slurry_real.tableID, Chile.comp_slurry_real.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2900(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2900};
  if(((data->localData[0]->booleanVars[4] /* $whenCondition5 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[4] /* $whenCondition5 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[2]), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 2901
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 1, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2901(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2901};
  (data->localData[0]->realVars[244] /* Chile.comp_slurry_real.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 1), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2902
type: SIMPLE_ASSIGN
Chile.slurry.TS_in = if Chile.slurry.steady == true then Chile.slurry.ts else Chile.comp_slurry_real.y[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2902(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2902};
  (data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[898] /* Chile.slurry.ts PARAM */):(data->localData[0]->realVars[244] /* Chile.comp_slurry_real.y[1] variable */));
  TRACE_POP
}
/*
equation index: 2903
type: SIMPLE_ASSIGN
Chile.slurry.u = 1.0 + (-0.001) * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2903(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2903};
  (data->localData[0]->realVars[1049] /* Chile.slurry.u variable */) = 1.0 + (-0.001) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */));
  TRACE_POP
}
/*
equation index: 2904
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 2, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2904(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2904};
  (data->localData[0]->realVars[245] /* Chile.comp_slurry_real.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 2), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2905
type: SIMPLE_ASSIGN
Chile.slurry.VS_in = if Chile.slurry.steady == true then 0.01 * Chile.slurry.vs_ts * Chile.slurry.TS_in else 0.01 * Chile.comp_slurry_real.y[2] * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2905(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2905};
  (data->localData[0]->realVars[993] /* Chile.slurry.VS_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(0.01) * (((data->simulationInfo->realParameter[900] /* Chile.slurry.vs_ts PARAM */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */))):(0.01) * (((data->localData[0]->realVars[245] /* Chile.comp_slurry_real.y[2] variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 2906
type: SIMPLE_ASSIGN
Chile.slurry.v = Chile.slurry.VS_in / Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2906(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2906};
  (data->localData[0]->realVars[1050] /* Chile.slurry.v variable */) = DIVISION_SIM((data->localData[0]->realVars[993] /* Chile.slurry.VS_in variable */),(data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */),"Chile.slurry.TS_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 2907
type: SIMPLE_ASSIGN
Chile.slurry.d = 1.0 / (0.001 * Chile.slurry.u + (1.0 - Chile.slurry.u) * (0.0004 + Chile.slurry.v * 0.0005523809523809524))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2907(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2907};
  (data->localData[0]->realVars[996] /* Chile.slurry.d variable */) = DIVISION_SIM(1.0,(0.001) * ((data->localData[0]->realVars[1049] /* Chile.slurry.u variable */)) + (1.0 - (data->localData[0]->realVars[1049] /* Chile.slurry.u variable */)) * (0.0004 + ((data->localData[0]->realVars[1050] /* Chile.slurry.v variable */)) * (0.0005523809523809524)),"0.001 * Chile.slurry.u + (1.0 - Chile.slurry.u) * (0.0004 + Chile.slurry.v * 0.0005523809523809524)",equationIndexes);
  TRACE_POP
}
/*
equation index: 2908
type: SIMPLE_ASSIGN
Chile.slurry.outlet.ash = Chile.slurry.TS_in - Chile.slurry.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2908(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2908};
  (data->localData[0]->realVars[1037] /* Chile.slurry.outlet.ash variable */) = (data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */) - (data->localData[0]->realVars[993] /* Chile.slurry.VS_in variable */);
  TRACE_POP
}
/*
equation index: 2909
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 3, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2909(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2909};
  (data->localData[0]->realVars[246] /* Chile.comp_slurry_real.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 3), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2910
type: SIMPLE_ASSIGN
Chile.slurry.pH = if Chile.slurry.steady == true then Chile.slurry.ph else Chile.comp_slurry_real.y[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2910(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2910};
  (data->localData[0]->realVars[1038] /* Chile.slurry.pH variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[888] /* Chile.slurry.ph PARAM */):(data->localData[0]->realVars[246] /* Chile.comp_slurry_real.y[3] variable */));
  TRACE_POP
}
/*
equation index: 2911
type: SIMPLE_ASSIGN
Chile.slurry.S_h = 10.0 ^ (-Chile.slurry.pH)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2911(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2911};
  modelica_real tmp120;
  modelica_real tmp121;
  modelica_real tmp122;
  modelica_real tmp123;
  modelica_real tmp124;
  modelica_real tmp125;
  modelica_real tmp126;
  tmp120 = 10.0;
  tmp121 = (-(data->localData[0]->realVars[1038] /* Chile.slurry.pH variable */));
  if(tmp120 < 0.0 && tmp121 != 0.0)
  {
    tmp123 = modf(tmp121, &tmp124);
    
    if(tmp123 > 0.5)
    {
      tmp123 -= 1.0;
      tmp124 += 1.0;
    }
    else if(tmp123 < -0.5)
    {
      tmp123 += 1.0;
      tmp124 -= 1.0;
    }
    
    if(fabs(tmp123) < 1e-10)
      tmp122 = pow(tmp120, tmp124);
    else
    {
      tmp126 = modf(1.0/tmp121, &tmp125);
      if(tmp126 > 0.5)
      {
        tmp126 -= 1.0;
        tmp125 += 1.0;
      }
      else if(tmp126 < -0.5)
      {
        tmp126 += 1.0;
        tmp125 -= 1.0;
      }
      if(fabs(tmp126) < 1e-10 && ((unsigned long)tmp125 & 1))
      {
        tmp122 = -pow(-tmp120, tmp123)*pow(tmp120, tmp124);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp120, tmp121);
      }
    }
  }
  else
  {
    tmp122 = pow(tmp120, tmp121);
  }
  if(isnan(tmp122) || isinf(tmp122))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp120, tmp121);
  }
  (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) = tmp122;
  TRACE_POP
}
/*
equation index: 2912
type: SIMPLE_ASSIGN
Chile.slurry.S_oh = Chile.slurry.Ka_h2o / Chile.slurry.S_h
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2912(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2912};
  (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) = DIVISION_SIM((data->localData[0]->realVars[926] /* Chile.slurry.Ka_h2o variable */),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes);
  TRACE_POP
}
/*
equation index: 2913
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[4] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 4, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2913(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2913};
  (data->localData[0]->realVars[247] /* Chile.comp_slurry_real.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 4), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2914
type: SIMPLE_ASSIGN
Chile.slurry.Alk_in = if Chile.slurry.steady == true then Chile.slurry.tac else Chile.comp_slurry_real.y[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2914(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2914};
  (data->localData[0]->realVars[875] /* Chile.slurry.Alk_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[894] /* Chile.slurry.tac PARAM */):(data->localData[0]->realVars[247] /* Chile.comp_slurry_real.y[4] variable */));
  TRACE_POP
}
/*
equation index: 2915
type: SIMPLE_ASSIGN
Chile.slurry.Alk_mol = 2e-05 * Chile.slurry.Alk_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2915(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2915};
  (data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) = (2e-05) * ((data->localData[0]->realVars[875] /* Chile.slurry.Alk_in variable */));
  TRACE_POP
}
/*
equation index: 2916
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[5] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 5, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2916(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2916};
  (data->localData[0]->realVars[248] /* Chile.comp_slurry_real.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 5), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2917
type: SIMPLE_ASSIGN
Chile.slurry.Ammonium_in = if Chile.slurry.steady == true then Chile.slurry.tan else Chile.comp_slurry_real.y[5]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2917(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2917};
  (data->localData[0]->realVars[877] /* Chile.slurry.Ammonium_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[895] /* Chile.slurry.tan PARAM */):(data->localData[0]->realVars[248] /* Chile.comp_slurry_real.y[5] variable */));
  TRACE_POP
}
/*
equation index: 2918
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_in = 7.142857142857143e-05 * Chile.slurry.Ammonium_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2918(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2918};
  (data->localData[0]->realVars[1017] /* Chile.slurry.outlet.S_in variable */) = (7.142857142857143e-05) * ((data->localData[0]->realVars[877] /* Chile.slurry.Ammonium_in variable */));
  TRACE_POP
}
/*
equation index: 2919
type: SIMPLE_ASSIGN
Chile.slurry.TAN = 14000.0 * Chile.slurry.outlet.S_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2919(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2919};
  (data->localData[0]->realVars[989] /* Chile.slurry.TAN variable */) = (14000.0) * ((data->localData[0]->realVars[1017] /* Chile.slurry.outlet.S_in variable */));
  TRACE_POP
}
/*
equation index: 2920
type: SIMPLE_ASSIGN
Chile.slurry.S_nh4 = Chile.slurry.outlet.S_in * Chile.slurry.S_h / (Chile.slurry.Ka_nh4 + Chile.slurry.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2920(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2920};
  (data->localData[0]->realVars[980] /* Chile.slurry.S_nh4 variable */) = ((data->localData[0]->realVars[1017] /* Chile.slurry.outlet.S_in variable */)) * (DIVISION_SIM((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),(data->localData[0]->realVars[931] /* Chile.slurry.Ka_nh4 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.Ka_nh4 + Chile.slurry.S_h",equationIndexes));
  TRACE_POP
}
/*
equation index: 2921
type: SIMPLE_ASSIGN
Chile.slurry.S_nh3 = Chile.slurry.outlet.S_in - Chile.slurry.S_nh4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2921(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2921};
  (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) = (data->localData[0]->realVars[1017] /* Chile.slurry.outlet.S_in variable */) - (data->localData[0]->realVars[980] /* Chile.slurry.S_nh4 variable */);
  TRACE_POP
}
/*
equation index: 2922
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[6] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 6, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2922(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2922};
  (data->localData[0]->realVars[249] /* Chile.comp_slurry_real.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 6), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2923
type: SIMPLE_ASSIGN
Chile.slurry.Fosfates_in = if Chile.slurry.steady == true then Chile.slurry.ortop else Chile.comp_slurry_real.y[6]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2923(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2923};
  (data->localData[0]->realVars[921] /* Chile.slurry.Fosfates_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[858] /* Chile.slurry.ortop PARAM */):(data->localData[0]->realVars[249] /* Chile.comp_slurry_real.y[6] variable */));
  TRACE_POP
}
/*
equation index: 2924
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_ip = 3.228539045402363e-05 * Chile.slurry.Fosfates_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2924(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2924};
  (data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */) = (3.228539045402363e-05) * ((data->localData[0]->realVars[921] /* Chile.slurry.Fosfates_in variable */));
  TRACE_POP
}
/*
equation index: 2925
type: SIMPLE_ASSIGN
Chile.slurry.S_hpo4 = Chile.slurry.Ka_h2po4 * Chile.slurry.outlet.S_ip / (Chile.slurry.Ka_hpo4 * Chile.slurry.Ka_h2po4 / Chile.slurry.S_h + Chile.slurry.Ka_h2po4 + Chile.slurry.S_h + Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_h3po4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2925(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2925};
  modelica_real tmp130;
  tmp130 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) = ((data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */),((data->localData[0]->realVars[930] /* Chile.slurry.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes)) + (data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + DIVISION_SIM((tmp130 * tmp130),(data->localData[0]->realVars[928] /* Chile.slurry.Ka_h3po4 variable */),"Chile.slurry.Ka_h3po4",equationIndexes),"Chile.slurry.Ka_hpo4 * Chile.slurry.Ka_h2po4 / Chile.slurry.S_h + Chile.slurry.Ka_h2po4 + Chile.slurry.S_h + Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_h3po4",equationIndexes));
  TRACE_POP
}
/*
equation index: 2926
type: SIMPLE_ASSIGN
Chile.slurry.S_po4 = Chile.slurry.Ka_hpo4 * Chile.slurry.outlet.S_ip / (Chile.slurry.Ka_hpo4 + Chile.slurry.S_h + Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_h2po4 + Chile.slurry.S_h ^ 3.0 / (Chile.slurry.Ka_h3po4 * Chile.slurry.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2926(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2926};
  modelica_real tmp131;
  modelica_real tmp132;
  tmp131 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  tmp132 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */) = ((data->localData[0]->realVars[930] /* Chile.slurry.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */),(data->localData[0]->realVars[930] /* Chile.slurry.Ka_hpo4 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + DIVISION_SIM((tmp131 * tmp131),(data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */),"Chile.slurry.Ka_h2po4",equationIndexes) + DIVISION_SIM((tmp132 * tmp132 * tmp132),((data->localData[0]->realVars[928] /* Chile.slurry.Ka_h3po4 variable */)) * ((data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */)),"Chile.slurry.Ka_h3po4 * Chile.slurry.Ka_h2po4",equationIndexes),"Chile.slurry.Ka_hpo4 + Chile.slurry.S_h + Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_h2po4 + Chile.slurry.S_h ^ 3.0 / (Chile.slurry.Ka_h3po4 * Chile.slurry.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 2927
type: SIMPLE_ASSIGN
Chile.slurry.S_h2po4 = Chile.slurry.outlet.S_ip * Chile.slurry.Ka_h3po4 / (Chile.slurry.S_h + Chile.slurry.Ka_h3po4 * (1.0 + (1.0 / Chile.slurry.S_h + Chile.slurry.Ka_hpo4 / Chile.slurry.S_h ^ 2.0) * Chile.slurry.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2927(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2927};
  modelica_real tmp133;
  tmp133 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[975] /* Chile.slurry.S_h2po4 variable */) = ((data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */)) * (DIVISION_SIM((data->localData[0]->realVars[928] /* Chile.slurry.Ka_h3po4 variable */),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + ((data->localData[0]->realVars[928] /* Chile.slurry.Ka_h3po4 variable */)) * (1.0 + (DIVISION_SIM(1.0,(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[930] /* Chile.slurry.Ka_hpo4 variable */),(tmp133 * tmp133),"Chile.slurry.S_h ^ 2.0",equationIndexes)) * ((data->localData[0]->realVars[927] /* Chile.slurry.Ka_h2po4 variable */))),"Chile.slurry.S_h + Chile.slurry.Ka_h3po4 * (1.0 + (1.0 / Chile.slurry.S_h + Chile.slurry.Ka_hpo4 / Chile.slurry.S_h ^ 2.0) * Chile.slurry.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 2928
type: SIMPLE_ASSIGN
Chile.slurry.S_h3po4 = Chile.slurry.outlet.S_ip + (-Chile.slurry.S_po4) - Chile.slurry.S_h2po4 - Chile.slurry.S_hpo4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2928(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2928};
  (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) = (data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */) + (-(data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */)) - (data->localData[0]->realVars[975] /* Chile.slurry.S_h2po4 variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */);
  TRACE_POP
}
/*
equation index: 2929
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[7] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 7, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2929(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2929};
  (data->localData[0]->realVars[250] /* Chile.comp_slurry_real.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 7), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2930
type: SIMPLE_ASSIGN
Chile.slurry.Ca_in = if Chile.slurry.steady == true or Chile.slurry.liquid == false then Chile.slurry.ca else Chile.comp_slurry_real.y[7]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2930(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2930};
  (data->localData[0]->realVars[917] /* Chile.slurry.Ca_in variable */) = ((((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[793] /* Chile.slurry.ca PARAM */):(data->localData[0]->realVars[250] /* Chile.comp_slurry_real.y[7] variable */));
  TRACE_POP
}
/*
equation index: 2931
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[8] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 8, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2931(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2931};
  (data->localData[0]->realVars[251] /* Chile.comp_slurry_real.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 8), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2932
type: SIMPLE_ASSIGN
Chile.slurry.Mg_in = if Chile.slurry.steady == true or Chile.slurry.liquid == false then Chile.slurry.mg else Chile.comp_slurry_real.y[8]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2932(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2932};
  (data->localData[0]->realVars[964] /* Chile.slurry.Mg_in variable */) = ((((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[855] /* Chile.slurry.mg PARAM */):(data->localData[0]->realVars[251] /* Chile.comp_slurry_real.y[8] variable */));
  TRACE_POP
}
/*
equation index: 2933
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[9] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 9, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2933(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2933};
  (data->localData[0]->realVars[252] /* Chile.comp_slurry_real.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 9), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2934
type: SIMPLE_ASSIGN
Chile.slurry.ac_in = if Chile.slurry.steady == true then Chile.slurry.ac else Chile.comp_slurry_real.y[9]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2934(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2934};
  (data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[785] /* Chile.slurry.ac PARAM */):(data->localData[0]->realVars[252] /* Chile.comp_slurry_real.y[9] variable */));
  TRACE_POP
}
/*
equation index: 2935
type: SIMPLE_ASSIGN
Chile.slurry.S_acm = 1.737800828749376e-05 * Chile.slurry.ac_in / (64.05333333333333 * (Chile.slurry.S_h + 1.737800828749376e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2935(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2935};
  (data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) = (1.737800828749376e-05) * (DIVISION_SIM((data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */),(64.05333333333333) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + 1.737800828749376e-05),"64.05333333333333 * (Chile.slurry.S_h + 1.737800828749376e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 2936
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[10] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 10, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2936(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2936};
  (data->localData[0]->realVars[253] /* Chile.comp_slurry_real.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 10), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2937
type: SIMPLE_ASSIGN
Chile.slurry.pro_in = if Chile.slurry.steady == true then Chile.slurry.pro else Chile.comp_slurry_real.y[10]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2937(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2937};
  (data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[889] /* Chile.slurry.pro PARAM */):(data->localData[0]->realVars[253] /* Chile.comp_slurry_real.y[10] variable */));
  TRACE_POP
}
/*
equation index: 2938
type: SIMPLE_ASSIGN
Chile.slurry.S_prom = 1.318256738556407e-05 * Chile.slurry.pro_in / (112.1210810810811 * (Chile.slurry.S_h + 1.318256738556407e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2938(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2938};
  (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) = (1.318256738556407e-05) * (DIVISION_SIM((data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */),(112.1210810810811) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + 1.318256738556407e-05),"112.1210810810811 * (Chile.slurry.S_h + 1.318256738556407e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 2939
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[11] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 11, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2939(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2939};
  (data->localData[0]->realVars[254] /* Chile.comp_slurry_real.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 11), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2940
type: SIMPLE_ASSIGN
Chile.slurry.bu_in = if Chile.slurry.steady == true then Chile.slurry.bu else Chile.comp_slurry_real.y[11]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2940(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2940};
  (data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[792] /* Chile.slurry.bu PARAM */):(data->localData[0]->realVars[254] /* Chile.comp_slurry_real.y[11] variable */));
  TRACE_POP
}
/*
equation index: 2941
type: SIMPLE_ASSIGN
Chile.slurry.S_bum = 1.513561248436207e-05 * Chile.slurry.bu_in / (160.1818181818182 * (Chile.slurry.S_h + 1.513561248436207e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2941(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2941};
  (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) = (1.513561248436207e-05) * (DIVISION_SIM((data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */),(160.1818181818182) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + 1.513561248436207e-05),"160.1818181818182 * (Chile.slurry.S_h + 1.513561248436207e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 2942
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[12] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 12, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2942(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2942};
  (data->localData[0]->realVars[255] /* Chile.comp_slurry_real.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 12), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2943
type: SIMPLE_ASSIGN
Chile.slurry.va_in = if Chile.slurry.steady == true then Chile.slurry.va else Chile.comp_slurry_real.y[12]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2943(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2943};
  (data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[899] /* Chile.slurry.va PARAM */):(data->localData[0]->realVars[255] /* Chile.comp_slurry_real.y[12] variable */));
  TRACE_POP
}
/*
equation index: 2944
type: SIMPLE_ASSIGN
Chile.slurry.TVFA = 60000.0 * (0.0156119900083264 * Chile.slurry.ac_in + 0.008918929342795433 * Chile.slurry.pro_in + 0.006242905788876278 * Chile.slurry.bu_in + 0.004801572656267654 * Chile.slurry.va_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2944(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2944};
  (data->localData[0]->realVars[991] /* Chile.slurry.TVFA variable */) = (60000.0) * ((0.0156119900083264) * ((data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */)) + (0.008918929342795433) * ((data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */)) + (0.006242905788876278) * ((data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */)) + (0.004801572656267654) * ((data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */)));
  TRACE_POP
}
/*
equation index: 2945
type: SIMPLE_ASSIGN
Chile.slurry.S_vam = 1.380384264602884e-05 * Chile.slurry.va_in / (208.2650980392157 * (Chile.slurry.S_h + 1.380384264602884e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2945(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2945};
  (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */) = (1.380384264602884e-05) * (DIVISION_SIM((data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */),(208.2650980392157) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + 1.380384264602884e-05),"208.2650980392157 * (Chile.slurry.S_h + 1.380384264602884e-05)",equationIndexes));
  TRACE_POP
}
void ADM1_P_Chile_OL_MPC_eqFunction_2946(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2947(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_2948(DATA*, threadData_t*);
/*
equation index: 2952
indexNonlinear: 10
type: NONLINEAR

vars: {Chile.slurry.outlet.S_ic}
eqns: {2946, 2947, 2948}
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2952(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2952};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 2952 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[10].nlsxOld[0] = (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */);
  retValue = solve_nonlinear_system(data, threadData, 10);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,2952};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 2952 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */) = data->simulationInfo->nonlinearSystemData[10].nlsx[0];
  TRACE_POP
}
/*
equation index: 2953
type: SIMPLE_ASSIGN
Chile.slurry.S_co2 = Chile.slurry.outlet.S_ic + (-Chile.slurry.S_hco3) - Chile.slurry.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2953(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2953};
  (data->localData[0]->realVars[972] /* Chile.slurry.S_co2 variable */) = (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */) + (-(data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */)) - (data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */);
  TRACE_POP
}
/*
equation index: 2954
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_cat = if Chile.slurry.liquid == false then Chile.slurry.cat else (-Chile.slurry.S_nh4) - Chile.slurry.S_h - 2.0 * Chile.slurry.Ca_in - 2.0 * Chile.slurry.Mg_in + Chile.slurry.an + Chile.slurry.S_hco3 + Chile.slurry.S_oh + Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam + 2.0 * Chile.slurry.S_hpo4 + Chile.slurry.S_h2po4 + 3.0 * Chile.slurry.S_po4 + 2.0 * Chile.slurry.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2954(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2954};
  (data->localData[0]->realVars[1014] /* Chile.slurry.outlet.S_cat variable */) = (((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?(data->simulationInfo->realParameter[794] /* Chile.slurry.cat PARAM */):(-(data->localData[0]->realVars[980] /* Chile.slurry.S_nh4 variable */)) - (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - ((2.0) * ((data->localData[0]->realVars[917] /* Chile.slurry.Ca_in variable */))) - ((2.0) * ((data->localData[0]->realVars[964] /* Chile.slurry.Mg_in variable */))) + (data->simulationInfo->realParameter[787] /* Chile.slurry.an PARAM */) + (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */) + (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) + (data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */) + (2.0) * ((data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */)) + (data->localData[0]->realVars[975] /* Chile.slurry.S_h2po4 variable */) + (3.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */)) + (2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)));
  TRACE_POP
}
/*
equation index: 2955
type: SIMPLE_ASSIGN
Chile.slurry.Alk = 50000.0 * (Chile.slurry.S_hco3 + 2.0 * Chile.slurry.S_co3 + Chile.slurry.S_oh + Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam + Chile.slurry.S_nh3 + Chile.slurry.S_hpo4 + 2.0 * Chile.slurry.S_po4 - Chile.slurry.S_h3po4 - Chile.slurry.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2955(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2955};
  (data->localData[0]->realVars[874] /* Chile.slurry.Alk variable */) = (50000.0) * ((data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */) + (2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)) + (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) + (data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */) + (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) + (2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */)) - (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */));
  TRACE_POP
}
/*
equation index: 2956
type: SIMPLE_ASSIGN
Chile.slurry.FOS_TAC = Chile.slurry.TVFA / Chile.slurry.Alk
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2956(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2956};
  (data->localData[0]->realVars[920] /* Chile.slurry.FOS_TAC variable */) = DIVISION_SIM((data->localData[0]->realVars[991] /* Chile.slurry.TVFA variable */),(data->localData[0]->realVars[874] /* Chile.slurry.Alk variable */),"Chile.slurry.Alk",equationIndexes);
  TRACE_POP
}
/*
equation index: 2957
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[13] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 13, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2957(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2957};
  (data->localData[0]->realVars[256] /* Chile.comp_slurry_real.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 13), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2958
type: SIMPLE_ASSIGN
Chile.slurry.Ssu_in = if Chile.slurry.steady == true then Chile.slurry.su else Chile.comp_slurry_real.y[13]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2958(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2958};
  (data->localData[0]->realVars[987] /* Chile.slurry.Ssu_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[893] /* Chile.slurry.su PARAM */):(data->localData[0]->realVars[256] /* Chile.comp_slurry_real.y[13] variable */));
  TRACE_POP
}
/*
equation index: 2959
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_su = 0.0107 * Chile.slurry.Ssu_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2959(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2959};
  (data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */) = (0.0107) * (((data->localData[0]->realVars[987] /* Chile.slurry.Ssu_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 2960
type: SIMPLE_ASSIGN
Chile.slurry.CH_sol = 0.84375 * (Chile.slurry.outlet.S_su + Chile.slurry.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2960(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2960};
  (data->localData[0]->realVars[885] /* Chile.slurry.CH_sol variable */) = (0.84375) * ((data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */));
  TRACE_POP
}
/*
equation index: 2961
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[14] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 14, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2961(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2961};
  (data->localData[0]->realVars[257] /* Chile.comp_slurry_real.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 14), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2962
type: SIMPLE_ASSIGN
Chile.slurry.Saa_in = if Chile.slurry.steady == true then Chile.slurry.aa else Chile.comp_slurry_real.y[14]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2962(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2962};
  (data->localData[0]->realVars[985] /* Chile.slurry.Saa_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[784] /* Chile.slurry.aa PARAM */):(data->localData[0]->realVars[257] /* Chile.comp_slurry_real.y[14] variable */));
  TRACE_POP
}
/*
equation index: 2963
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_aa = 0.0153 * Chile.slurry.Saa_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2963(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2963};
  (data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) = (0.0153) * (((data->localData[0]->realVars[985] /* Chile.slurry.Saa_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 2964
type: SIMPLE_ASSIGN
Chile.slurry.PR_sol_BCA = (Chile.slurry.outlet.S_aa + Chile.slurry.si) / Chile.slurry.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2964(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2964};
  (data->localData[0]->realVars[966] /* Chile.slurry.PR_sol_BCA variable */) = DIVISION_SIM((data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */),(data->simulationInfo->realParameter[741] /* Chile.slurry.COD_VS_PR_BCA PARAM */),"Chile.slurry.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 2965
type: SIMPLE_ASSIGN
Chile.slurry.PR_sol_TKN = 0.6534431137724552 * (Chile.slurry.outlet.S_aa + Chile.slurry.si) / Chile.slurry.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2965(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2965};
  (data->localData[0]->realVars[967] /* Chile.slurry.PR_sol_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM((data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */),(data->simulationInfo->realParameter[769] /* Chile.slurry.N_PR PARAM */),"Chile.slurry.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 2966
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[15] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 15, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2966(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2966};
  (data->localData[0]->realVars[258] /* Chile.comp_slurry_real.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 15), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2967
type: SIMPLE_ASSIGN
Chile.slurry.Sfa_in = if Chile.slurry.steady == true then Chile.slurry.fa else Chile.comp_slurry_real.y[15]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2967(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2967};
  (data->localData[0]->realVars[986] /* Chile.slurry.Sfa_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[817] /* Chile.slurry.fa PARAM */):(data->localData[0]->realVars[258] /* Chile.comp_slurry_real.y[15] variable */));
  TRACE_POP
}
/*
equation index: 2968
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_fa = 0.0287 * Chile.slurry.Sfa_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2968(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2968};
  (data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) = (0.0287) * (((data->localData[0]->realVars[986] /* Chile.slurry.Sfa_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 2969
type: SIMPLE_ASSIGN
Chile.slurry.COD_sol = Chile.slurry.outlet.S_aa + Chile.slurry.ac_in + Chile.slurry.bu_in + Chile.slurry.ch4 + Chile.slurry.outlet.S_fa + Chile.slurry.h2 + Chile.slurry.si + Chile.slurry.pro_in + Chile.slurry.outlet.S_su + Chile.slurry.va_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2969(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2969};
  (data->localData[0]->realVars[914] /* Chile.slurry.COD_sol variable */) = (data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */) + (data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */) + (data->simulationInfo->realParameter[796] /* Chile.slurry.ch4 PARAM */) + (data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) + (data->simulationInfo->realParameter[818] /* Chile.slurry.h2 PARAM */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */) + (data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */) + (data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */);
  TRACE_POP
}
/*
equation index: 2970
type: SIMPLE_ASSIGN
Chile.slurry.LI_sol = 0.3532661514862131 * (Chile.slurry.outlet.S_fa + Chile.slurry.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2970(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2970};
  (data->localData[0]->realVars[934] /* Chile.slurry.LI_sol variable */) = (0.3532661514862131) * ((data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */));
  TRACE_POP
}
/*
equation index: 2971
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[16] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 16, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2971(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2971};
  (data->localData[0]->realVars[259] /* Chile.comp_slurry_real.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 16), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2972
type: SIMPLE_ASSIGN
Chile.slurry.tBMP_VS_in = if Chile.slurry.steady == true then Chile.slurry.tbmp_vs else Chile.comp_slurry_real.y[16]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2972(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2972};
  (data->localData[0]->realVars[1040] /* Chile.slurry.tBMP_VS_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[896] /* Chile.slurry.tbmp_vs PARAM */):(data->localData[0]->realVars[259] /* Chile.comp_slurry_real.y[16] variable */));
  TRACE_POP
}
/*
equation index: 2973
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[17] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 17, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2973(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2973};
  (data->localData[0]->realVars[260] /* Chile.comp_slurry_real.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 17), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2974
type: SIMPLE_ASSIGN
Chile.slurry.CP_in = if Chile.slurry.steady == true then Chile.slurry.protein else Chile.comp_slurry_real.y[17]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2974(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2974};
  (data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[890] /* Chile.slurry.protein PARAM */):(data->localData[0]->realVars[260] /* Chile.comp_slurry_real.y[17] variable */));
  TRACE_POP
}
/*
equation index: 2975
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[18] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 18, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2975(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2975};
  (data->localData[0]->realVars[261] /* Chile.comp_slurry_real.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 18), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2976
type: SIMPLE_ASSIGN
Chile.slurry.EE_in = if Chile.slurry.steady == true then Chile.slurry.lipid else Chile.comp_slurry_real.y[18]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2976(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2976};
  (data->localData[0]->realVars[919] /* Chile.slurry.EE_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[854] /* Chile.slurry.lipid PARAM */):(data->localData[0]->realVars[261] /* Chile.comp_slurry_real.y[18] variable */));
  TRACE_POP
}
/*
equation index: 2977
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[19] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 19, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2977(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2977};
  (data->localData[0]->realVars[262] /* Chile.comp_slurry_real.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 19), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2978
type: SIMPLE_ASSIGN
Chile.slurry.Cellulose_in = if Chile.slurry.steady == true then Chile.slurry.cellulose else Chile.comp_slurry_real.y[19]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2978(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2978};
  (data->localData[0]->realVars[918] /* Chile.slurry.Cellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[795] /* Chile.slurry.cellulose PARAM */):(data->localData[0]->realVars[262] /* Chile.comp_slurry_real.y[19] variable */));
  TRACE_POP
}
/*
equation index: 2979
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[20] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 20, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2979(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2979};
  (data->localData[0]->realVars[263] /* Chile.comp_slurry_real.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 20), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2980
type: SIMPLE_ASSIGN
Chile.slurry.Hemicellulose_in = if Chile.slurry.steady == true then Chile.slurry.hemicellulose else Chile.comp_slurry_real.y[20]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2980(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2980};
  (data->localData[0]->realVars[922] /* Chile.slurry.Hemicellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[819] /* Chile.slurry.hemicellulose PARAM */):(data->localData[0]->realVars[263] /* Chile.comp_slurry_real.y[20] variable */));
  TRACE_POP
}
/*
equation index: 2981
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[21] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 21, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2981(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2981};
  (data->localData[0]->realVars[264] /* Chile.comp_slurry_real.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 21), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2982
type: SIMPLE_ASSIGN
Chile.slurry.Lignin_in = if Chile.slurry.steady == true then Chile.slurry.adl else Chile.comp_slurry_real.y[21]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2982(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2982};
  (data->localData[0]->realVars[936] /* Chile.slurry.Lignin_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[786] /* Chile.slurry.adl PARAM */):(data->localData[0]->realVars[264] /* Chile.comp_slurry_real.y[21] variable */));
  TRACE_POP
}
/*
equation index: 2983
type: SIMPLE_ASSIGN
Chile.slurry.NDF_in = Chile.slurry.Cellulose_in + Chile.slurry.Hemicellulose_in + Chile.slurry.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2983(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2983};
  (data->localData[0]->realVars[965] /* Chile.slurry.NDF_in variable */) = (data->localData[0]->realVars[918] /* Chile.slurry.Cellulose_in variable */) + (data->localData[0]->realVars[922] /* Chile.slurry.Hemicellulose_in variable */) + (data->localData[0]->realVars[936] /* Chile.slurry.Lignin_in variable */);
  TRACE_POP
}
/*
equation index: 2984
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_lig = 0.01361702127659574 * Chile.slurry.TS_in * Chile.slurry.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2984(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2984};
  (data->localData[0]->realVars[1031] /* Chile.slurry.outlet.X_lig variable */) = (0.01361702127659574) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((data->localData[0]->realVars[936] /* Chile.slurry.Lignin_in variable */)));
  TRACE_POP
}
/*
equation index: 2985
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[22] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 22, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2985(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2985};
  (data->localData[0]->realVars[265] /* Chile.comp_slurry_real.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 22), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2986
type: SIMPLE_ASSIGN
Chile.slurry.Starch_in = if Chile.slurry.steady == true then Chile.slurry.starch else Chile.comp_slurry_real.y[22]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2986(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2986};
  (data->localData[0]->realVars[988] /* Chile.slurry.Starch_in variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[892] /* Chile.slurry.starch PARAM */):(data->localData[0]->realVars[265] /* Chile.comp_slurry_real.y[22] variable */));
  TRACE_POP
}
/*
equation index: 2987
type: SIMPLE_ASSIGN
Chile.slurry.CH_in = Chile.slurry.Ssu_in + Chile.slurry.Starch_in + Chile.slurry.NDF_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2987(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2987};
  (data->localData[0]->realVars[884] /* Chile.slurry.CH_in variable */) = (data->localData[0]->realVars[987] /* Chile.slurry.Ssu_in variable */) + (data->localData[0]->realVars[988] /* Chile.slurry.Starch_in variable */) + (data->localData[0]->realVars[965] /* Chile.slurry.NDF_in variable */);
  TRACE_POP
}
/*
equation index: 2988
type: SIMPLE_ASSIGN
Chile.slurry.tBMPth_vs = 0.01 * (496.0 * Chile.slurry.CP_in + 1014.0 * Chile.slurry.EE_in + 415.0 * Chile.slurry.CH_in) * Chile.slurry.TS_in / Chile.slurry.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2988(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2988};
  (data->localData[0]->realVars[1048] /* Chile.slurry.tBMPth_vs variable */) = (0.01) * (((496.0) * ((data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */)) + (1014.0) * ((data->localData[0]->realVars[919] /* Chile.slurry.EE_in variable */)) + (415.0) * ((data->localData[0]->realVars[884] /* Chile.slurry.CH_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */),(data->localData[0]->realVars[993] /* Chile.slurry.VS_in variable */),"Chile.slurry.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2989
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_ch[1] = 0.01185185185185185 * Chile.slurry.Starch_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2989(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2989};
  (data->localData[0]->realVars[1023] /* Chile.slurry.outlet.X_ch[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[988] /* Chile.slurry.Starch_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 2990
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[23] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 23, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2990(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2990};
  (data->localData[0]->realVars[266] /* Chile.comp_slurry_real.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 23), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2991
type: SIMPLE_ASSIGN
Chile.slurry.BD_pr = if Chile.slurry.steady == true then Chile.slurry.bd_pr else Chile.comp_slurry_real.y[23]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2991(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2991};
  (data->localData[0]->realVars[882] /* Chile.slurry.BD_pr variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[791] /* Chile.slurry.bd_pr PARAM */):(data->localData[0]->realVars[266] /* Chile.comp_slurry_real.y[23] variable */));
  TRACE_POP
}
/*
equation index: 2992
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_i[2] = 0.01530355097365406 * Chile.slurry.TS_in * (1.0 + (-0.01) * Chile.slurry.BD_pr) * Chile.slurry.CP_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2992(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2992};
  (data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */) = (0.01530355097365406) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[882] /* Chile.slurry.BD_pr variable */))) * ((data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */))));
  TRACE_POP
}
/*
equation index: 2993
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_pr[2] = 0.0001530355097365406 * Chile.slurry.f_pr_s * Chile.slurry.CP_in * Chile.slurry.TS_in * Chile.slurry.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2993(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2993};
  (data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[811] /* Chile.slurry.f_pr_s PARAM */)) * (((data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */)) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((data->localData[0]->realVars[882] /* Chile.slurry.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 2994
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_pr[1] = 0.0001530355097365406 * Chile.slurry.f_pr_r * Chile.slurry.CP_in * Chile.slurry.TS_in * Chile.slurry.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2994(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2994};
  (data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[810] /* Chile.slurry.f_pr_r PARAM */)) * (((data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */)) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((data->localData[0]->realVars[882] /* Chile.slurry.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 2995
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[24] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 24, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2995(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2995};
  (data->localData[0]->realVars[267] /* Chile.comp_slurry_real.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 24), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 2996
type: SIMPLE_ASSIGN
Chile.slurry.BD_li = if Chile.slurry.steady == true then Chile.slurry.bd_li else Chile.comp_slurry_real.y[24]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2996(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2996};
  (data->localData[0]->realVars[881] /* Chile.slurry.BD_li variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[790] /* Chile.slurry.bd_li PARAM */):(data->localData[0]->realVars[267] /* Chile.comp_slurry_real.y[24] variable */));
  TRACE_POP
}
/*
equation index: 2997
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_i[3] = 0.02830726906025207 * Chile.slurry.TS_in * (1.0 + (-0.01) * Chile.slurry.BD_li) * Chile.slurry.EE_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2997(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2997};
  (data->localData[0]->realVars[1028] /* Chile.slurry.outlet.X_i[3] variable */) = (0.02830726906025207) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[881] /* Chile.slurry.BD_li variable */))) * ((data->localData[0]->realVars[919] /* Chile.slurry.EE_in variable */))));
  TRACE_POP
}
/*
equation index: 2998
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_li = 0.0002830726906025207 * Chile.slurry.EE_in * Chile.slurry.TS_in * Chile.slurry.BD_li
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2998(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2998};
  (data->localData[0]->realVars[1030] /* Chile.slurry.outlet.X_li variable */) = (0.0002830726906025207) * (((data->localData[0]->realVars[919] /* Chile.slurry.EE_in variable */)) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((data->localData[0]->realVars[881] /* Chile.slurry.BD_li variable */))));
  TRACE_POP
}
/*
equation index: 2999
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[25] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 25, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2999(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2999};
  (data->localData[0]->realVars[268] /* Chile.comp_slurry_real.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 25), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3000
type: SIMPLE_ASSIGN
Chile.slurry.BD_cell = if Chile.slurry.steady == true then Chile.slurry.bd_cell else Chile.comp_slurry_real.y[25]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3000(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3000};
  (data->localData[0]->realVars[878] /* Chile.slurry.BD_cell variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[788] /* Chile.slurry.bd_cell PARAM */):(data->localData[0]->realVars[268] /* Chile.comp_slurry_real.y[25] variable */));
  TRACE_POP
}
/*
equation index: 3001
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_ch[3] = 0.0001185185185185185 * Chile.slurry.BD_cell * Chile.slurry.Cellulose_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3001(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3001};
  (data->localData[0]->realVars[1025] /* Chile.slurry.outlet.X_ch[3] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[878] /* Chile.slurry.BD_cell variable */)) * (((data->localData[0]->realVars[918] /* Chile.slurry.Cellulose_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3002
type: SIMPLE_ASSIGN
Chile.comp_slurry_real.y[26] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry_real.tableID, 26, Chile.comp_slurry_real.timeScaled, Chile.comp_slurry_real.nextTimeEventScaled, pre(Chile.comp_slurry_real.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3002(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3002};
  (data->localData[0]->realVars[269] /* Chile.comp_slurry_real.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[2]), ((modelica_integer) 26), (data->localData[0]->realVars[243] /* Chile.comp_slurry_real.timeScaled variable */), (data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3003
type: SIMPLE_ASSIGN
Chile.slurry.BD_hemicell = if Chile.slurry.steady == true then Chile.slurry.bd_hemicell else Chile.comp_slurry_real.y[26]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3003(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3003};
  (data->localData[0]->realVars[880] /* Chile.slurry.BD_hemicell variable */) = (((!(data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[28] /* Chile.slurry.steady PARAM */) && 1))?(data->simulationInfo->realParameter[789] /* Chile.slurry.bd_hemicell PARAM */):(data->localData[0]->realVars[269] /* Chile.comp_slurry_real.y[26] variable */));
  TRACE_POP
}
/*
equation index: 3004
type: SIMPLE_ASSIGN
Chile.slurry.BD_ch = 100.0 * (Chile.slurry.Ssu_in + Chile.slurry.Starch_in + 0.01 * (Chile.slurry.BD_cell * Chile.slurry.Cellulose_in + Chile.slurry.BD_hemicell * Chile.slurry.Hemicellulose_in)) / Chile.slurry.CH_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3004(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3004};
  (data->localData[0]->realVars[879] /* Chile.slurry.BD_ch variable */) = DIVISION_SIM((100.0) * ((data->localData[0]->realVars[987] /* Chile.slurry.Ssu_in variable */) + (data->localData[0]->realVars[988] /* Chile.slurry.Starch_in variable */) + (0.01) * (((data->localData[0]->realVars[878] /* Chile.slurry.BD_cell variable */)) * ((data->localData[0]->realVars[918] /* Chile.slurry.Cellulose_in variable */)) + ((data->localData[0]->realVars[880] /* Chile.slurry.BD_hemicell variable */)) * ((data->localData[0]->realVars[922] /* Chile.slurry.Hemicellulose_in variable */)))),(data->localData[0]->realVars[884] /* Chile.slurry.CH_in variable */),"Chile.slurry.CH_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 3005
type: SIMPLE_ASSIGN
Chile.slurry.BD_vs = 0.01 * (Chile.slurry.BD_ch * Chile.slurry.CH_in + Chile.slurry.BD_pr * Chile.slurry.CP_in + Chile.slurry.BD_li * Chile.slurry.EE_in) * Chile.slurry.TS_in / Chile.slurry.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3005(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3005};
  (data->localData[0]->realVars[883] /* Chile.slurry.BD_vs variable */) = (0.01) * ((((data->localData[0]->realVars[879] /* Chile.slurry.BD_ch variable */)) * ((data->localData[0]->realVars[884] /* Chile.slurry.CH_in variable */)) + ((data->localData[0]->realVars[882] /* Chile.slurry.BD_pr variable */)) * ((data->localData[0]->realVars[916] /* Chile.slurry.CP_in variable */)) + ((data->localData[0]->realVars[881] /* Chile.slurry.BD_li variable */)) * ((data->localData[0]->realVars[919] /* Chile.slurry.EE_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */),(data->localData[0]->realVars[993] /* Chile.slurry.VS_in variable */),"Chile.slurry.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3006
type: SIMPLE_ASSIGN
Chile.slurry.tBMPerror = 0.01 * Chile.slurry.BD_vs * Chile.slurry.tBMPth_vs - Chile.slurry.tBMP_VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3006(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3006};
  (data->localData[0]->realVars[1041] /* Chile.slurry.tBMPerror variable */) = (0.01) * (((data->localData[0]->realVars[883] /* Chile.slurry.BD_vs variable */)) * ((data->localData[0]->realVars[1048] /* Chile.slurry.tBMPth_vs variable */))) - (data->localData[0]->realVars[1040] /* Chile.slurry.tBMP_VS_in variable */);
  TRACE_POP
}
/*
equation index: 3007
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_i[1] = 0.01185185185185185 * Chile.slurry.TS_in * ((1.0 + (-0.01) * Chile.slurry.BD_cell) * Chile.slurry.Cellulose_in + (1.0 + (-0.01) * Chile.slurry.BD_hemicell) * Chile.slurry.Hemicellulose_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3007(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3007};
  (data->localData[0]->realVars[1026] /* Chile.slurry.outlet.X_i[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[878] /* Chile.slurry.BD_cell variable */))) * ((data->localData[0]->realVars[918] /* Chile.slurry.Cellulose_in variable */)) + (1.0 + (-0.01) * ((data->localData[0]->realVars[880] /* Chile.slurry.BD_hemicell variable */))) * ((data->localData[0]->realVars[922] /* Chile.slurry.Hemicellulose_in variable */))));
  TRACE_POP
}
/*
equation index: 3008
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_i[4] = Chile.slurry.outlet.X_i[1] + Chile.slurry.outlet.X_i[2] + Chile.slurry.outlet.X_i[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3008(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3008};
  (data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */) = (data->localData[0]->realVars[1026] /* Chile.slurry.outlet.X_i[1] variable */) + (data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */) + (data->localData[0]->realVars[1028] /* Chile.slurry.outlet.X_i[3] variable */);
  TRACE_POP
}
/*
equation index: 3009
type: SIMPLE_ASSIGN
Chile.slurry.f_xi[2] = Chile.slurry.outlet.X_i[2] / Chile.slurry.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3009(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3009};
  (data->localData[0]->realVars[1011] /* Chile.slurry.f_xi[2] variable */) = DIVISION_SIM((data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */),(data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */),"Chile.slurry.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3010
type: SIMPLE_ASSIGN
Chile.slurry.PR_tot_BCA = (1.166666666666667e-10 + Chile.slurry.outlet.S_aa + Chile.slurry.outlet.X_pr[1] + Chile.slurry.outlet.X_pr[2] + 1e-10 * Chile.slurry.f_xi[2] + Chile.slurry.si + Chile.slurry.outlet.X_i[2] + (Chile.slurry.xaa + Chile.slurry.xac + Chile.slurry.xc4 + Chile.slurry.xfa + Chile.slurry.xh2 + Chile.slurry.xpro + Chile.slurry.xsu) * Chile.slurry.f_Xbiom_pr) / Chile.slurry.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3010(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3010};
  (data->localData[0]->realVars[968] /* Chile.slurry.PR_tot_BCA variable */) = DIVISION_SIM(1.166666666666667e-10 + (data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[1011] /* Chile.slurry.f_xi[2] variable */)) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */)) * ((data->simulationInfo->realParameter[803] /* Chile.slurry.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[741] /* Chile.slurry.COD_VS_PR_BCA PARAM */),"Chile.slurry.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3011
type: SIMPLE_ASSIGN
Chile.slurry.PR_tot_TKN = 0.6534431137724552 * (2e-10 + Chile.slurry.outlet.S_aa + Chile.slurry.outlet.X_pr[1] + Chile.slurry.outlet.X_pr[2] + 1e-10 * Chile.slurry.f_xi[2] + Chile.slurry.si + Chile.slurry.outlet.X_i[2] + (Chile.slurry.xaa + Chile.slurry.xac + Chile.slurry.xc4 + Chile.slurry.xfa + Chile.slurry.xh2 + Chile.slurry.xpro + Chile.slurry.xsu) * Chile.slurry.f_Xbiom_pr) / Chile.slurry.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3011(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3011};
  (data->localData[0]->realVars[969] /* Chile.slurry.PR_tot_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM(2e-10 + (data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[1011] /* Chile.slurry.f_xi[2] variable */)) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */)) * ((data->simulationInfo->realParameter[803] /* Chile.slurry.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[769] /* Chile.slurry.N_PR PARAM */),"Chile.slurry.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3012
type: SIMPLE_ASSIGN
Chile.slurry.f_xi[3] = Chile.slurry.outlet.X_i[3] / Chile.slurry.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3012(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3012};
  (data->localData[0]->realVars[1012] /* Chile.slurry.f_xi[3] variable */) = DIVISION_SIM((data->localData[0]->realVars[1028] /* Chile.slurry.outlet.X_i[3] variable */),(data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */),"Chile.slurry.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3013
type: SIMPLE_ASSIGN
Chile.slurry.LI_tot = 0.3532661514862131 * (2e-10 + Chile.slurry.outlet.S_fa + Chile.slurry.outlet.X_li + 1e-10 * Chile.slurry.f_xi[3] + Chile.slurry.si + Chile.slurry.outlet.X_i[3] + (Chile.slurry.xaa + Chile.slurry.xac + Chile.slurry.xc4 + Chile.slurry.xfa + Chile.slurry.xh2 + Chile.slurry.xpro + Chile.slurry.xsu) * Chile.slurry.f_Xbiom_li)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3013(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3013};
  (data->localData[0]->realVars[935] /* Chile.slurry.LI_tot variable */) = (0.3532661514862131) * (2e-10 + (data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) + (data->localData[0]->realVars[1030] /* Chile.slurry.outlet.X_li variable */) + (1e-10) * ((data->localData[0]->realVars[1012] /* Chile.slurry.f_xi[3] variable */)) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1028] /* Chile.slurry.outlet.X_i[3] variable */) + ((data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */)) * ((data->simulationInfo->realParameter[802] /* Chile.slurry.f_Xbiom_li PARAM */)));
  TRACE_POP
}
/*
equation index: 3014
type: SIMPLE_ASSIGN
Chile.slurry.f_xi[1] = Chile.slurry.outlet.X_i[1] / Chile.slurry.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3014(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3014};
  (data->localData[0]->realVars[1010] /* Chile.slurry.f_xi[1] variable */) = DIVISION_SIM((data->localData[0]->realVars[1026] /* Chile.slurry.outlet.X_i[1] variable */),(data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */),"Chile.slurry.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3015
type: SIMPLE_ASSIGN
Chile.slurry.COD_VS[25] = 1.0 / (0.84375 * Chile.slurry.f_xi[1] + Chile.slurry.f_xi[2] / 1.530355097365406 + Chile.slurry.f_xi[3] / 2.830726906025207)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3015(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3015};
  (data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */) = DIVISION_SIM(1.0,(0.84375) * ((data->localData[0]->realVars[1010] /* Chile.slurry.f_xi[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[1011] /* Chile.slurry.f_xi[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1012] /* Chile.slurry.f_xi[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes),"0.84375 * Chile.slurry.f_xi[1] + Chile.slurry.f_xi[2] / 1.530355097365406 + Chile.slurry.f_xi[3] / 2.830726906025207",equationIndexes);
  TRACE_POP
}
/*
equation index: 3016
type: SIMPLE_ASSIGN
Chile.slurry.COD_VS[14] = 1.0 / (4.435293530517336 + 1.0 / Chile.slurry.COD_VS[25])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3016(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3016};
  (data->localData[0]->realVars[900] /* Chile.slurry.COD_VS[14] variable */) = DIVISION_SIM(1.0,4.435293530517336 + DIVISION_SIM(1.0,(data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */),"Chile.slurry.COD_VS[25]",equationIndexes),"4.435293530517336 + 1.0 / Chile.slurry.COD_VS[25]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3017
type: SIMPLE_ASSIGN
Chile.slurry.MW[25] = 1.0 / (Chile.slurry.COD_VS[25] * (Chile.slurry.f_xi[1] / 192.0 + Chile.slurry.f_xi[2] / 133.6 + Chile.slurry.f_xi[3] / 2352.194407671715))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3017(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3017};
  (data->localData[0]->realVars[961] /* Chile.slurry.MW[25] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1010] /* Chile.slurry.f_xi[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1011] /* Chile.slurry.f_xi[2] variable */),133.6,"133.6",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1012] /* Chile.slurry.f_xi[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes)),"Chile.slurry.COD_VS[25] * (Chile.slurry.f_xi[1] / 192.0 + Chile.slurry.f_xi[2] / 133.6 + Chile.slurry.f_xi[3] / 2352.194407671715)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3018
type: SIMPLE_ASSIGN
Chile.slurry.MW[14] = 1.0 / ((0.03404949640278076 + 1.0 / (Chile.slurry.MW[25] * Chile.slurry.COD_VS[25])) * Chile.slurry.COD_VS[14])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3018(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3018};
  (data->localData[0]->realVars[950] /* Chile.slurry.MW[14] variable */) = DIVISION_SIM(1.0,(0.03404949640278076 + DIVISION_SIM(1.0,((data->localData[0]->realVars[961] /* Chile.slurry.MW[25] variable */)) * ((data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */)),"Chile.slurry.MW[25] * Chile.slurry.COD_VS[25]",equationIndexes)) * ((data->localData[0]->realVars[900] /* Chile.slurry.COD_VS[14] variable */)),"(0.03404949640278076 + 1.0 / (Chile.slurry.MW[25] * Chile.slurry.COD_VS[25])) * Chile.slurry.COD_VS[14]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3019
type: SIMPLE_ASSIGN
Chile.slurry.outlet.X_ch[2] = 0.0001185185185185185 * Chile.slurry.BD_hemicell * Chile.slurry.Hemicellulose_in * Chile.slurry.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3019(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3019};
  (data->localData[0]->realVars[1024] /* Chile.slurry.outlet.X_ch[2] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[880] /* Chile.slurry.BD_hemicell variable */)) * (((data->localData[0]->realVars[922] /* Chile.slurry.Hemicellulose_in variable */)) * ((data->localData[0]->realVars[990] /* Chile.slurry.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3020
type: SIMPLE_ASSIGN
Chile.slurry.CH_tot = 1.223958333333333e-11 + 0.9345794392523364 * Chile.slurry.outlet.S_su + 0.84375 * (2e-10 + Chile.slurry.outlet.X_ch[1] + Chile.slurry.outlet.X_ch[2] + Chile.slurry.outlet.X_ch[3] + 1e-10 * Chile.slurry.f_xi[1] + Chile.slurry.si + Chile.slurry.outlet.X_i[1] + (Chile.slurry.xaa + Chile.slurry.xac + Chile.slurry.xc4 + Chile.slurry.xfa + Chile.slurry.xh2 + Chile.slurry.xpro + Chile.slurry.xsu) * Chile.slurry.f_Xbiom_ch) + 0.734375 * Chile.slurry.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3020(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3020};
  (data->localData[0]->realVars[886] /* Chile.slurry.CH_tot variable */) = 1.223958333333333e-11 + (0.9345794392523364) * ((data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */)) + (0.84375) * (2e-10 + (data->localData[0]->realVars[1023] /* Chile.slurry.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1024] /* Chile.slurry.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1025] /* Chile.slurry.outlet.X_ch[3] variable */) + (1e-10) * ((data->localData[0]->realVars[1010] /* Chile.slurry.f_xi[1] variable */)) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1026] /* Chile.slurry.outlet.X_i[1] variable */) + ((data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */)) * ((data->simulationInfo->realParameter[801] /* Chile.slurry.f_Xbiom_ch PARAM */))) + (0.734375) * ((data->localData[0]->realVars[1031] /* Chile.slurry.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3021
type: SIMPLE_ASSIGN
Chile.slurry.COD_tot = 1e-10 + Chile.slurry.outlet.S_aa + Chile.slurry.ac_in + Chile.slurry.bu_in + Chile.slurry.ch4 + Chile.slurry.outlet.S_fa + Chile.slurry.h2 + Chile.slurry.si + Chile.slurry.pro_in + Chile.slurry.outlet.S_su + Chile.slurry.va_in + Chile.slurry.xaa + Chile.slurry.xac + Chile.slurry.xc4 + Chile.slurry.outlet.X_ch[1] + Chile.slurry.outlet.X_ch[2] + Chile.slurry.outlet.X_ch[3] + Chile.slurry.xfa + Chile.slurry.xh2 + Chile.slurry.outlet.X_i[4] + Chile.slurry.outlet.X_li + Chile.slurry.outlet.X_pr[1] + Chile.slurry.outlet.X_pr[2] + Chile.slurry.xpro + Chile.slurry.xsu + Chile.slurry.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3021(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3021};
  (data->localData[0]->realVars[915] /* Chile.slurry.COD_tot variable */) = 1e-10 + (data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */) + (data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */) + (data->simulationInfo->realParameter[796] /* Chile.slurry.ch4 PARAM */) + (data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) + (data->simulationInfo->realParameter[818] /* Chile.slurry.h2 PARAM */) + (data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */) + (data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */) + (data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */) + (data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */) + (data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->localData[0]->realVars[1023] /* Chile.slurry.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1024] /* Chile.slurry.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1025] /* Chile.slurry.outlet.X_ch[3] variable */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */) + (data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */) + (data->localData[0]->realVars[1030] /* Chile.slurry.outlet.X_li variable */) + (data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */) + (data->localData[0]->realVars[1031] /* Chile.slurry.outlet.X_lig variable */);
  TRACE_POP
}
/*
equation index: 3022
type: SIMPLE_ASSIGN
Chile.slurry.VS = (Chile.slurry.xsu + Chile.slurry.xaa + Chile.slurry.xfa + Chile.slurry.xc4 + Chile.slurry.xpro + Chile.slurry.xac + Chile.slurry.xh2) * (0.84375 * Chile.slurry.f_ch_xb + 0.6534431137724552 * Chile.slurry.f_pr_xb + 0.3532661514862131 * Chile.slurry.f_li_xb + 1.850459265258668 * Chile.slurry.f_si_xb + Chile.slurry.f_xi_xb / Chile.slurry.COD_VS[25]) + 0.9345794392523364 * Chile.slurry.outlet.S_su + 0.84375 * (Chile.slurry.outlet.X_ch[1] + Chile.slurry.outlet.X_ch[2] + Chile.slurry.outlet.X_ch[3]) + 0.6534431137724552 * (Chile.slurry.outlet.S_aa + Chile.slurry.outlet.X_pr[1] + Chile.slurry.outlet.X_pr[2]) + 0.3532661514862131 * (Chile.slurry.outlet.S_fa + Chile.slurry.outlet.X_li) + 1.850459265258668 * Chile.slurry.si + Chile.slurry.outlet.X_i[4] / Chile.slurry.COD_VS[25] + 1e-10 / Chile.slurry.COD_VS[14] + 0.734375 * Chile.slurry.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3022(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3022};
  (data->localData[0]->realVars[992] /* Chile.slurry.VS variable */) = ((data->simulationInfo->realParameter[907] /* Chile.slurry.xsu PARAM */) + (data->simulationInfo->realParameter[901] /* Chile.slurry.xaa PARAM */) + (data->simulationInfo->realParameter[904] /* Chile.slurry.xfa PARAM */) + (data->simulationInfo->realParameter[903] /* Chile.slurry.xc4 PARAM */) + (data->simulationInfo->realParameter[906] /* Chile.slurry.xpro PARAM */) + (data->simulationInfo->realParameter[902] /* Chile.slurry.xac PARAM */) + (data->simulationInfo->realParameter[905] /* Chile.slurry.xh2 PARAM */)) * ((0.84375) * ((data->simulationInfo->realParameter[806] /* Chile.slurry.f_ch_xb PARAM */)) + (0.6534431137724552) * ((data->simulationInfo->realParameter[812] /* Chile.slurry.f_pr_xb PARAM */)) + (0.3532661514862131) * ((data->simulationInfo->realParameter[809] /* Chile.slurry.f_li_xb PARAM */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[814] /* Chile.slurry.f_si_xb PARAM */)) + DIVISION_SIM((data->simulationInfo->realParameter[816] /* Chile.slurry.f_xi_xb PARAM */),(data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */),"Chile.slurry.COD_VS[25]",equationIndexes)) + (0.9345794392523364) * ((data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */)) + (0.84375) * ((data->localData[0]->realVars[1023] /* Chile.slurry.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1024] /* Chile.slurry.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1025] /* Chile.slurry.outlet.X_ch[3] variable */)) + (0.6534431137724552) * ((data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */) + (data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */)) + (0.3532661514862131) * ((data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */) + (data->localData[0]->realVars[1030] /* Chile.slurry.outlet.X_li variable */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[891] /* Chile.slurry.si PARAM */)) + DIVISION_SIM((data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */),(data->localData[0]->realVars[911] /* Chile.slurry.COD_VS[25] variable */),"Chile.slurry.COD_VS[25]",equationIndexes) + DIVISION_SIM(1e-10,(data->localData[0]->realVars[900] /* Chile.slurry.COD_VS[14] variable */),"Chile.slurry.COD_VS[14]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[1031] /* Chile.slurry.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3023
type: WHEN

when {$whenCondition5} then
  Chile.comp_slurry_real.nextTimeEvent = if Chile.comp_slurry_real.nextTimeEventScaled < 9.999999999999999e+59 then Chile.comp_slurry_real.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3023(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3023};
  modelica_boolean tmp15;
  if(((data->localData[0]->booleanVars[4] /* $whenCondition5 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[4] /* $whenCondition5 DISCRETE */) /* edge */))
  {
    tmp15 = Less((data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1255] /* Chile.comp_slurry_real.nextTimeEvent DISCRETE */) = (tmp15?(data->localData[0]->realVars[1256] /* Chile.comp_slurry_real.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 3024
type: SIMPLE_ASSIGN
$whenCondition6 = time >= pre(Chile.comp_tomatosouce.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3024(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3024};
  modelica_boolean tmp16;
  relationhysteresis(data, &tmp16, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1257] /* Chile.comp_tomatosouce.nextTimeEvent DISCRETE */), 3, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[5] /* $whenCondition6 DISCRETE */) = tmp16;
  TRACE_POP
}
/*
equation index: 3025
type: WHEN

when {$whenCondition6} then
  Chile.comp_tomatosouce.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Chile.comp_tomatosouce.tableID, Chile.comp_tomatosouce.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3025(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3025};
  if(((data->localData[0]->booleanVars[5] /* $whenCondition6 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[5] /* $whenCondition6 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[3]), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 3026
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 1, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3026(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3026};
  (data->localData[0]->realVars[271] /* Chile.comp_tomatosouce.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 1), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3027
type: SIMPLE_ASSIGN
Chile.tomatosouce.TS_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.ts else Chile.comp_tomatosouce.y[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3027(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3027};
  (data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1104] /* Chile.tomatosouce.ts PARAM */):(data->localData[0]->realVars[271] /* Chile.comp_tomatosouce.y[1] variable */));
  TRACE_POP
}
/*
equation index: 3028
type: SIMPLE_ASSIGN
Chile.tomatosouce.u = 1.0 + (-0.001) * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3028(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3028};
  (data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */) = 1.0 + (-0.001) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */));
  TRACE_POP
}
/*
equation index: 3029
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 2, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3029(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3029};
  (data->localData[0]->realVars[272] /* Chile.comp_tomatosouce.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 2), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3030
type: SIMPLE_ASSIGN
Chile.tomatosouce.VS_in = if Chile.tomatosouce.steady == true then 0.01 * Chile.tomatosouce.vs_ts * Chile.tomatosouce.TS_in else 0.01 * Chile.comp_tomatosouce.y[2] * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3030(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3030};
  (data->localData[0]->realVars[1171] /* Chile.tomatosouce.VS_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(0.01) * (((data->simulationInfo->realParameter[1106] /* Chile.tomatosouce.vs_ts PARAM */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */))):(0.01) * (((data->localData[0]->realVars[272] /* Chile.comp_tomatosouce.y[2] variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3031
type: SIMPLE_ASSIGN
Chile.tomatosouce.v = Chile.tomatosouce.VS_in / Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3031(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3031};
  (data->localData[0]->realVars[1228] /* Chile.tomatosouce.v variable */) = DIVISION_SIM((data->localData[0]->realVars[1171] /* Chile.tomatosouce.VS_in variable */),(data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */),"Chile.tomatosouce.TS_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 3032
type: SIMPLE_ASSIGN
Chile.tomatosouce.d = 1.0 / (0.001 * Chile.tomatosouce.u + (1.0 - Chile.tomatosouce.u) * (0.0004 + Chile.tomatosouce.v * 0.0005523809523809524))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3032(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3032};
  (data->localData[0]->realVars[1174] /* Chile.tomatosouce.d variable */) = DIVISION_SIM(1.0,(0.001) * ((data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */)) + (1.0 - (data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */)) * (0.0004 + ((data->localData[0]->realVars[1228] /* Chile.tomatosouce.v variable */)) * (0.0005523809523809524)),"0.001 * Chile.tomatosouce.u + (1.0 - Chile.tomatosouce.u) * (0.0004 + Chile.tomatosouce.v * 0.0005523809523809524)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3033
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.ash = Chile.tomatosouce.TS_in - Chile.tomatosouce.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3033(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3033};
  (data->localData[0]->realVars[1215] /* Chile.tomatosouce.outlet.ash variable */) = (data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */) - (data->localData[0]->realVars[1171] /* Chile.tomatosouce.VS_in variable */);
  TRACE_POP
}
/*
equation index: 3034
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 3, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3034(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3034};
  (data->localData[0]->realVars[273] /* Chile.comp_tomatosouce.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 3), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3035
type: SIMPLE_ASSIGN
Chile.tomatosouce.pH = if Chile.tomatosouce.steady == true then Chile.tomatosouce.ph else Chile.comp_tomatosouce.y[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3035(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3035};
  (data->localData[0]->realVars[1216] /* Chile.tomatosouce.pH variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1094] /* Chile.tomatosouce.ph PARAM */):(data->localData[0]->realVars[273] /* Chile.comp_tomatosouce.y[3] variable */));
  TRACE_POP
}
/*
equation index: 3036
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_h = 10.0 ^ (-Chile.tomatosouce.pH)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3036(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3036};
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  tmp20 = 10.0;
  tmp21 = (-(data->localData[0]->realVars[1216] /* Chile.tomatosouce.pH variable */));
  if(tmp20 < 0.0 && tmp21 != 0.0)
  {
    tmp23 = modf(tmp21, &tmp24);
    
    if(tmp23 > 0.5)
    {
      tmp23 -= 1.0;
      tmp24 += 1.0;
    }
    else if(tmp23 < -0.5)
    {
      tmp23 += 1.0;
      tmp24 -= 1.0;
    }
    
    if(fabs(tmp23) < 1e-10)
      tmp22 = pow(tmp20, tmp24);
    else
    {
      tmp26 = modf(1.0/tmp21, &tmp25);
      if(tmp26 > 0.5)
      {
        tmp26 -= 1.0;
        tmp25 += 1.0;
      }
      else if(tmp26 < -0.5)
      {
        tmp26 += 1.0;
        tmp25 -= 1.0;
      }
      if(fabs(tmp26) < 1e-10 && ((unsigned long)tmp25 & 1))
      {
        tmp22 = -pow(-tmp20, tmp23)*pow(tmp20, tmp24);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
      }
    }
  }
  else
  {
    tmp22 = pow(tmp20, tmp21);
  }
  if(isnan(tmp22) || isinf(tmp22))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
  }
  (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) = tmp22;
  TRACE_POP
}
/*
equation index: 3037
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_oh = Chile.tomatosouce.Ka_h2o / Chile.tomatosouce.S_h
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3037(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3037};
  (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) = DIVISION_SIM((data->localData[0]->realVars[1104] /* Chile.tomatosouce.Ka_h2o variable */),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes);
  TRACE_POP
}
/*
equation index: 3038
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[4] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 4, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3038(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3038};
  (data->localData[0]->realVars[274] /* Chile.comp_tomatosouce.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 4), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3039
type: SIMPLE_ASSIGN
Chile.tomatosouce.Alk_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.tac else Chile.comp_tomatosouce.y[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3039(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3039};
  (data->localData[0]->realVars[1053] /* Chile.tomatosouce.Alk_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1100] /* Chile.tomatosouce.tac PARAM */):(data->localData[0]->realVars[274] /* Chile.comp_tomatosouce.y[4] variable */));
  TRACE_POP
}
/*
equation index: 3040
type: SIMPLE_ASSIGN
Chile.tomatosouce.Alk_mol = 2e-05 * Chile.tomatosouce.Alk_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3040(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3040};
  (data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) = (2e-05) * ((data->localData[0]->realVars[1053] /* Chile.tomatosouce.Alk_in variable */));
  TRACE_POP
}
/*
equation index: 3041
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[5] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 5, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3041(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3041};
  (data->localData[0]->realVars[275] /* Chile.comp_tomatosouce.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 5), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3042
type: SIMPLE_ASSIGN
Chile.tomatosouce.Ammonium_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.tan else Chile.comp_tomatosouce.y[5]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3042(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3042};
  (data->localData[0]->realVars[1055] /* Chile.tomatosouce.Ammonium_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1101] /* Chile.tomatosouce.tan PARAM */):(data->localData[0]->realVars[275] /* Chile.comp_tomatosouce.y[5] variable */));
  TRACE_POP
}
/*
equation index: 3043
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_in = 7.142857142857143e-05 * Chile.tomatosouce.Ammonium_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3043(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3043};
  (data->localData[0]->realVars[1195] /* Chile.tomatosouce.outlet.S_in variable */) = (7.142857142857143e-05) * ((data->localData[0]->realVars[1055] /* Chile.tomatosouce.Ammonium_in variable */));
  TRACE_POP
}
/*
equation index: 3044
type: SIMPLE_ASSIGN
Chile.tomatosouce.TAN = 14000.0 * Chile.tomatosouce.outlet.S_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3044(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3044};
  (data->localData[0]->realVars[1167] /* Chile.tomatosouce.TAN variable */) = (14000.0) * ((data->localData[0]->realVars[1195] /* Chile.tomatosouce.outlet.S_in variable */));
  TRACE_POP
}
/*
equation index: 3045
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_nh4 = Chile.tomatosouce.outlet.S_in * Chile.tomatosouce.S_h / (Chile.tomatosouce.Ka_nh4 + Chile.tomatosouce.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3045(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3045};
  (data->localData[0]->realVars[1158] /* Chile.tomatosouce.S_nh4 variable */) = ((data->localData[0]->realVars[1195] /* Chile.tomatosouce.outlet.S_in variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),(data->localData[0]->realVars[1109] /* Chile.tomatosouce.Ka_nh4 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.Ka_nh4 + Chile.tomatosouce.S_h",equationIndexes));
  TRACE_POP
}
/*
equation index: 3046
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_nh3 = Chile.tomatosouce.outlet.S_in - Chile.tomatosouce.S_nh4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3046(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3046};
  (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) = (data->localData[0]->realVars[1195] /* Chile.tomatosouce.outlet.S_in variable */) - (data->localData[0]->realVars[1158] /* Chile.tomatosouce.S_nh4 variable */);
  TRACE_POP
}
/*
equation index: 3047
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[6] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 6, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3047(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3047};
  (data->localData[0]->realVars[276] /* Chile.comp_tomatosouce.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 6), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3048
type: SIMPLE_ASSIGN
Chile.tomatosouce.Fosfates_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.ortop else Chile.comp_tomatosouce.y[6]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3048(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3048};
  (data->localData[0]->realVars[1099] /* Chile.tomatosouce.Fosfates_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1064] /* Chile.tomatosouce.ortop PARAM */):(data->localData[0]->realVars[276] /* Chile.comp_tomatosouce.y[6] variable */));
  TRACE_POP
}
/*
equation index: 3049
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_ip = 3.228539045402363e-05 * Chile.tomatosouce.Fosfates_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3049(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3049};
  (data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */) = (3.228539045402363e-05) * ((data->localData[0]->realVars[1099] /* Chile.tomatosouce.Fosfates_in variable */));
  TRACE_POP
}
/*
equation index: 3050
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_hpo4 = Chile.tomatosouce.Ka_h2po4 * Chile.tomatosouce.outlet.S_ip / (Chile.tomatosouce.Ka_hpo4 * Chile.tomatosouce.Ka_h2po4 / Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_h2po4 + Chile.tomatosouce.S_h + Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_h3po4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3050(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3050};
  modelica_real tmp30;
  tmp30 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) = ((data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */),((data->localData[0]->realVars[1108] /* Chile.tomatosouce.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes)) + (data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + DIVISION_SIM((tmp30 * tmp30),(data->localData[0]->realVars[1106] /* Chile.tomatosouce.Ka_h3po4 variable */),"Chile.tomatosouce.Ka_h3po4",equationIndexes),"Chile.tomatosouce.Ka_hpo4 * Chile.tomatosouce.Ka_h2po4 / Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_h2po4 + Chile.tomatosouce.S_h + Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_h3po4",equationIndexes));
  TRACE_POP
}
/*
equation index: 3051
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_po4 = Chile.tomatosouce.Ka_hpo4 * Chile.tomatosouce.outlet.S_ip / (Chile.tomatosouce.Ka_hpo4 + Chile.tomatosouce.S_h + Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_h2po4 + Chile.tomatosouce.S_h ^ 3.0 / (Chile.tomatosouce.Ka_h3po4 * Chile.tomatosouce.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3051(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3051};
  modelica_real tmp31;
  modelica_real tmp32;
  tmp31 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  tmp32 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */) = ((data->localData[0]->realVars[1108] /* Chile.tomatosouce.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */),(data->localData[0]->realVars[1108] /* Chile.tomatosouce.Ka_hpo4 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + DIVISION_SIM((tmp31 * tmp31),(data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */),"Chile.tomatosouce.Ka_h2po4",equationIndexes) + DIVISION_SIM((tmp32 * tmp32 * tmp32),((data->localData[0]->realVars[1106] /* Chile.tomatosouce.Ka_h3po4 variable */)) * ((data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */)),"Chile.tomatosouce.Ka_h3po4 * Chile.tomatosouce.Ka_h2po4",equationIndexes),"Chile.tomatosouce.Ka_hpo4 + Chile.tomatosouce.S_h + Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_h2po4 + Chile.tomatosouce.S_h ^ 3.0 / (Chile.tomatosouce.Ka_h3po4 * Chile.tomatosouce.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3052
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_h2po4 = Chile.tomatosouce.outlet.S_ip * Chile.tomatosouce.Ka_h3po4 / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_h3po4 * (1.0 + (1.0 / Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hpo4 / Chile.tomatosouce.S_h ^ 2.0) * Chile.tomatosouce.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3052(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3052};
  modelica_real tmp33;
  tmp33 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1153] /* Chile.tomatosouce.S_h2po4 variable */) = ((data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1106] /* Chile.tomatosouce.Ka_h3po4 variable */),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + ((data->localData[0]->realVars[1106] /* Chile.tomatosouce.Ka_h3po4 variable */)) * (1.0 + (DIVISION_SIM(1.0,(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1108] /* Chile.tomatosouce.Ka_hpo4 variable */),(tmp33 * tmp33),"Chile.tomatosouce.S_h ^ 2.0",equationIndexes)) * ((data->localData[0]->realVars[1105] /* Chile.tomatosouce.Ka_h2po4 variable */))),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_h3po4 * (1.0 + (1.0 / Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hpo4 / Chile.tomatosouce.S_h ^ 2.0) * Chile.tomatosouce.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3053
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_h3po4 = Chile.tomatosouce.outlet.S_ip + (-Chile.tomatosouce.S_po4) - Chile.tomatosouce.S_h2po4 - Chile.tomatosouce.S_hpo4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3053(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3053};
  (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) = (data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */) + (-(data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */)) - (data->localData[0]->realVars[1153] /* Chile.tomatosouce.S_h2po4 variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */);
  TRACE_POP
}
/*
equation index: 3054
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[7] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 7, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3054(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3054};
  (data->localData[0]->realVars[277] /* Chile.comp_tomatosouce.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 7), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3055
type: SIMPLE_ASSIGN
Chile.tomatosouce.Ca_in = if Chile.tomatosouce.steady == true or Chile.tomatosouce.liquid == false then Chile.tomatosouce.ca else Chile.comp_tomatosouce.y[7]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3055(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3055};
  (data->localData[0]->realVars[1095] /* Chile.tomatosouce.Ca_in variable */) = ((((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[999] /* Chile.tomatosouce.ca PARAM */):(data->localData[0]->realVars[277] /* Chile.comp_tomatosouce.y[7] variable */));
  TRACE_POP
}
/*
equation index: 3056
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[8] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 8, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3056(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3056};
  (data->localData[0]->realVars[278] /* Chile.comp_tomatosouce.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 8), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3057
type: SIMPLE_ASSIGN
Chile.tomatosouce.Mg_in = if Chile.tomatosouce.steady == true or Chile.tomatosouce.liquid == false then Chile.tomatosouce.mg else Chile.comp_tomatosouce.y[8]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3057(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3057};
  (data->localData[0]->realVars[1142] /* Chile.tomatosouce.Mg_in variable */) = ((((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[1061] /* Chile.tomatosouce.mg PARAM */):(data->localData[0]->realVars[278] /* Chile.comp_tomatosouce.y[8] variable */));
  TRACE_POP
}
/*
equation index: 3058
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[9] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 9, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3058(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3058};
  (data->localData[0]->realVars[279] /* Chile.comp_tomatosouce.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 9), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3059
type: SIMPLE_ASSIGN
Chile.tomatosouce.ac_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.ac else Chile.comp_tomatosouce.y[9]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3059(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3059};
  (data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[991] /* Chile.tomatosouce.ac PARAM */):(data->localData[0]->realVars[279] /* Chile.comp_tomatosouce.y[9] variable */));
  TRACE_POP
}
/*
equation index: 3060
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_acm = 1.737800828749376e-05 * Chile.tomatosouce.ac_in / (64.05333333333333 * (Chile.tomatosouce.S_h + 1.737800828749376e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3060(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3060};
  (data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) = (1.737800828749376e-05) * (DIVISION_SIM((data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */),(64.05333333333333) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + 1.737800828749376e-05),"64.05333333333333 * (Chile.tomatosouce.S_h + 1.737800828749376e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3061
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[10] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 10, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3061(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3061};
  (data->localData[0]->realVars[280] /* Chile.comp_tomatosouce.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 10), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3062
type: SIMPLE_ASSIGN
Chile.tomatosouce.pro_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.pro else Chile.comp_tomatosouce.y[10]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3062(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3062};
  (data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1095] /* Chile.tomatosouce.pro PARAM */):(data->localData[0]->realVars[280] /* Chile.comp_tomatosouce.y[10] variable */));
  TRACE_POP
}
/*
equation index: 3063
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_prom = 1.318256738556407e-05 * Chile.tomatosouce.pro_in / (112.1210810810811 * (Chile.tomatosouce.S_h + 1.318256738556407e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3063(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3063};
  (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) = (1.318256738556407e-05) * (DIVISION_SIM((data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */),(112.1210810810811) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + 1.318256738556407e-05),"112.1210810810811 * (Chile.tomatosouce.S_h + 1.318256738556407e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3064
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[11] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 11, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3064(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3064};
  (data->localData[0]->realVars[281] /* Chile.comp_tomatosouce.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 11), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3065
type: SIMPLE_ASSIGN
Chile.tomatosouce.bu_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.bu else Chile.comp_tomatosouce.y[11]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3065(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3065};
  (data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[998] /* Chile.tomatosouce.bu PARAM */):(data->localData[0]->realVars[281] /* Chile.comp_tomatosouce.y[11] variable */));
  TRACE_POP
}
/*
equation index: 3066
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_bum = 1.513561248436207e-05 * Chile.tomatosouce.bu_in / (160.1818181818182 * (Chile.tomatosouce.S_h + 1.513561248436207e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3066(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3066};
  (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) = (1.513561248436207e-05) * (DIVISION_SIM((data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */),(160.1818181818182) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + 1.513561248436207e-05),"160.1818181818182 * (Chile.tomatosouce.S_h + 1.513561248436207e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3067
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[12] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 12, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3067(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3067};
  (data->localData[0]->realVars[282] /* Chile.comp_tomatosouce.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 12), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3068
type: SIMPLE_ASSIGN
Chile.tomatosouce.va_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.va else Chile.comp_tomatosouce.y[12]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3068(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3068};
  (data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1105] /* Chile.tomatosouce.va PARAM */):(data->localData[0]->realVars[282] /* Chile.comp_tomatosouce.y[12] variable */));
  TRACE_POP
}
/*
equation index: 3069
type: SIMPLE_ASSIGN
Chile.tomatosouce.TVFA = 60000.0 * (0.0156119900083264 * Chile.tomatosouce.ac_in + 0.008918929342795433 * Chile.tomatosouce.pro_in + 0.006242905788876278 * Chile.tomatosouce.bu_in + 0.004801572656267654 * Chile.tomatosouce.va_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3069(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3069};
  (data->localData[0]->realVars[1169] /* Chile.tomatosouce.TVFA variable */) = (60000.0) * ((0.0156119900083264) * ((data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */)) + (0.008918929342795433) * ((data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */)) + (0.006242905788876278) * ((data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */)) + (0.004801572656267654) * ((data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */)));
  TRACE_POP
}
/*
equation index: 3070
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_vam = 1.380384264602884e-05 * Chile.tomatosouce.va_in / (208.2650980392157 * (Chile.tomatosouce.S_h + 1.380384264602884e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3070(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3070};
  (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */) = (1.380384264602884e-05) * (DIVISION_SIM((data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */),(208.2650980392157) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + 1.380384264602884e-05),"208.2650980392157 * (Chile.tomatosouce.S_h + 1.380384264602884e-05)",equationIndexes));
  TRACE_POP
}
void ADM1_P_Chile_OL_MPC_eqFunction_3071(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_3072(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_3073(DATA*, threadData_t*);
/*
equation index: 3077
indexNonlinear: 11
type: NONLINEAR

vars: {Chile.tomatosouce.outlet.S_ic}
eqns: {3071, 3072, 3073}
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3077(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3077};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 3077 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[11].nlsxOld[0] = (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */);
  retValue = solve_nonlinear_system(data, threadData, 11);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,3077};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 3077 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */) = data->simulationInfo->nonlinearSystemData[11].nlsx[0];
  TRACE_POP
}
/*
equation index: 3078
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co2 = Chile.tomatosouce.outlet.S_ic + (-Chile.tomatosouce.S_hco3) - Chile.tomatosouce.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3078(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3078};
  (data->localData[0]->realVars[1150] /* Chile.tomatosouce.S_co2 variable */) = (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */) + (-(data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */)) - (data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */);
  TRACE_POP
}
/*
equation index: 3079
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_cat = if Chile.tomatosouce.liquid == false then Chile.tomatosouce.cat else (-Chile.tomatosouce.S_nh4) - Chile.tomatosouce.S_h - 2.0 * Chile.tomatosouce.Ca_in - 2.0 * Chile.tomatosouce.Mg_in + Chile.tomatosouce.an + Chile.tomatosouce.S_hco3 + Chile.tomatosouce.S_oh + Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam + 2.0 * Chile.tomatosouce.S_hpo4 + Chile.tomatosouce.S_h2po4 + 3.0 * Chile.tomatosouce.S_po4 + 2.0 * Chile.tomatosouce.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3079(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3079};
  (data->localData[0]->realVars[1192] /* Chile.tomatosouce.outlet.S_cat variable */) = (((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?(data->simulationInfo->realParameter[1000] /* Chile.tomatosouce.cat PARAM */):(-(data->localData[0]->realVars[1158] /* Chile.tomatosouce.S_nh4 variable */)) - (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - ((2.0) * ((data->localData[0]->realVars[1095] /* Chile.tomatosouce.Ca_in variable */))) - ((2.0) * ((data->localData[0]->realVars[1142] /* Chile.tomatosouce.Mg_in variable */))) + (data->simulationInfo->realParameter[993] /* Chile.tomatosouce.an PARAM */) + (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */) + (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) + (data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */) + (2.0) * ((data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */)) + (data->localData[0]->realVars[1153] /* Chile.tomatosouce.S_h2po4 variable */) + (3.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */)) + (2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)));
  TRACE_POP
}
/*
equation index: 3080
type: SIMPLE_ASSIGN
Chile.tomatosouce.Alk = 50000.0 * (Chile.tomatosouce.S_hco3 + 2.0 * Chile.tomatosouce.S_co3 + Chile.tomatosouce.S_oh + Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam + Chile.tomatosouce.S_nh3 + Chile.tomatosouce.S_hpo4 + 2.0 * Chile.tomatosouce.S_po4 - Chile.tomatosouce.S_h3po4 - Chile.tomatosouce.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3080(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3080};
  (data->localData[0]->realVars[1052] /* Chile.tomatosouce.Alk variable */) = (50000.0) * ((data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */) + (2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)) + (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) + (data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */) + (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) + (2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */)) - (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */));
  TRACE_POP
}
/*
equation index: 3081
type: SIMPLE_ASSIGN
Chile.tomatosouce.FOS_TAC = Chile.tomatosouce.TVFA / Chile.tomatosouce.Alk
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3081(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3081};
  (data->localData[0]->realVars[1098] /* Chile.tomatosouce.FOS_TAC variable */) = DIVISION_SIM((data->localData[0]->realVars[1169] /* Chile.tomatosouce.TVFA variable */),(data->localData[0]->realVars[1052] /* Chile.tomatosouce.Alk variable */),"Chile.tomatosouce.Alk",equationIndexes);
  TRACE_POP
}
/*
equation index: 3082
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[13] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 13, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3082(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3082};
  (data->localData[0]->realVars[283] /* Chile.comp_tomatosouce.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 13), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3083
type: SIMPLE_ASSIGN
Chile.tomatosouce.Ssu_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.su else Chile.comp_tomatosouce.y[13]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3083(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3083};
  (data->localData[0]->realVars[1165] /* Chile.tomatosouce.Ssu_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1099] /* Chile.tomatosouce.su PARAM */):(data->localData[0]->realVars[283] /* Chile.comp_tomatosouce.y[13] variable */));
  TRACE_POP
}
/*
equation index: 3084
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_su = 0.0107 * Chile.tomatosouce.Ssu_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3084(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3084};
  (data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */) = (0.0107) * (((data->localData[0]->realVars[1165] /* Chile.tomatosouce.Ssu_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3085
type: SIMPLE_ASSIGN
Chile.tomatosouce.CH_sol = 0.84375 * (Chile.tomatosouce.outlet.S_su + Chile.tomatosouce.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3085(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3085};
  (data->localData[0]->realVars[1063] /* Chile.tomatosouce.CH_sol variable */) = (0.84375) * ((data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */));
  TRACE_POP
}
/*
equation index: 3086
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[14] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 14, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3086(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3086};
  (data->localData[0]->realVars[284] /* Chile.comp_tomatosouce.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 14), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3087
type: SIMPLE_ASSIGN
Chile.tomatosouce.Saa_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.aa else Chile.comp_tomatosouce.y[14]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3087(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3087};
  (data->localData[0]->realVars[1163] /* Chile.tomatosouce.Saa_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[990] /* Chile.tomatosouce.aa PARAM */):(data->localData[0]->realVars[284] /* Chile.comp_tomatosouce.y[14] variable */));
  TRACE_POP
}
/*
equation index: 3088
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_aa = 0.0153 * Chile.tomatosouce.Saa_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3088(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3088};
  (data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) = (0.0153) * (((data->localData[0]->realVars[1163] /* Chile.tomatosouce.Saa_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3089
type: SIMPLE_ASSIGN
Chile.tomatosouce.PR_sol_BCA = (Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.si) / Chile.tomatosouce.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3089(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3089};
  (data->localData[0]->realVars[1144] /* Chile.tomatosouce.PR_sol_BCA variable */) = DIVISION_SIM((data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */),(data->simulationInfo->realParameter[947] /* Chile.tomatosouce.COD_VS_PR_BCA PARAM */),"Chile.tomatosouce.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3090
type: SIMPLE_ASSIGN
Chile.tomatosouce.PR_sol_TKN = 0.6534431137724552 * (Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.si) / Chile.tomatosouce.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3090(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3090};
  (data->localData[0]->realVars[1145] /* Chile.tomatosouce.PR_sol_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM((data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */),(data->simulationInfo->realParameter[975] /* Chile.tomatosouce.N_PR PARAM */),"Chile.tomatosouce.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3091
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[15] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 15, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3091(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3091};
  (data->localData[0]->realVars[285] /* Chile.comp_tomatosouce.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 15), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3092
type: SIMPLE_ASSIGN
Chile.tomatosouce.Sfa_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.fa else Chile.comp_tomatosouce.y[15]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3092(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3092};
  (data->localData[0]->realVars[1164] /* Chile.tomatosouce.Sfa_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1023] /* Chile.tomatosouce.fa PARAM */):(data->localData[0]->realVars[285] /* Chile.comp_tomatosouce.y[15] variable */));
  TRACE_POP
}
/*
equation index: 3093
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_fa = 0.0287 * Chile.tomatosouce.Sfa_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3093(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3093};
  (data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) = (0.0287) * (((data->localData[0]->realVars[1164] /* Chile.tomatosouce.Sfa_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3094
type: SIMPLE_ASSIGN
Chile.tomatosouce.COD_sol = Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.ac_in + Chile.tomatosouce.bu_in + Chile.tomatosouce.ch4 + Chile.tomatosouce.outlet.S_fa + Chile.tomatosouce.h2 + Chile.tomatosouce.si + Chile.tomatosouce.pro_in + Chile.tomatosouce.outlet.S_su + Chile.tomatosouce.va_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3094(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3094};
  (data->localData[0]->realVars[1092] /* Chile.tomatosouce.COD_sol variable */) = (data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */) + (data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */) + (data->simulationInfo->realParameter[1002] /* Chile.tomatosouce.ch4 PARAM */) + (data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) + (data->simulationInfo->realParameter[1024] /* Chile.tomatosouce.h2 PARAM */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */) + (data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */) + (data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */);
  TRACE_POP
}
/*
equation index: 3095
type: SIMPLE_ASSIGN
Chile.tomatosouce.LI_sol = 0.3532661514862131 * (Chile.tomatosouce.outlet.S_fa + Chile.tomatosouce.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3095(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3095};
  (data->localData[0]->realVars[1112] /* Chile.tomatosouce.LI_sol variable */) = (0.3532661514862131) * ((data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */));
  TRACE_POP
}
/*
equation index: 3096
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[16] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 16, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3096(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3096};
  (data->localData[0]->realVars[286] /* Chile.comp_tomatosouce.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 16), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3097
type: SIMPLE_ASSIGN
Chile.tomatosouce.tBMP_VS_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.tbmp_vs else Chile.comp_tomatosouce.y[16]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3097(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3097};
  (data->localData[0]->realVars[1218] /* Chile.tomatosouce.tBMP_VS_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1102] /* Chile.tomatosouce.tbmp_vs PARAM */):(data->localData[0]->realVars[286] /* Chile.comp_tomatosouce.y[16] variable */));
  TRACE_POP
}
/*
equation index: 3098
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[17] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 17, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3098(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3098};
  (data->localData[0]->realVars[287] /* Chile.comp_tomatosouce.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 17), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3099
type: SIMPLE_ASSIGN
Chile.tomatosouce.CP_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.protein else Chile.comp_tomatosouce.y[17]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3099(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3099};
  (data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1096] /* Chile.tomatosouce.protein PARAM */):(data->localData[0]->realVars[287] /* Chile.comp_tomatosouce.y[17] variable */));
  TRACE_POP
}
/*
equation index: 3100
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[18] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 18, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3100(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3100};
  (data->localData[0]->realVars[288] /* Chile.comp_tomatosouce.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 18), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3101
type: SIMPLE_ASSIGN
Chile.tomatosouce.EE_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.lipid else Chile.comp_tomatosouce.y[18]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3101(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3101};
  (data->localData[0]->realVars[1097] /* Chile.tomatosouce.EE_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1060] /* Chile.tomatosouce.lipid PARAM */):(data->localData[0]->realVars[288] /* Chile.comp_tomatosouce.y[18] variable */));
  TRACE_POP
}
/*
equation index: 3102
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[19] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 19, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3102(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3102};
  (data->localData[0]->realVars[289] /* Chile.comp_tomatosouce.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 19), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3103
type: SIMPLE_ASSIGN
Chile.tomatosouce.Cellulose_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.cellulose else Chile.comp_tomatosouce.y[19]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3103(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3103};
  (data->localData[0]->realVars[1096] /* Chile.tomatosouce.Cellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1001] /* Chile.tomatosouce.cellulose PARAM */):(data->localData[0]->realVars[289] /* Chile.comp_tomatosouce.y[19] variable */));
  TRACE_POP
}
/*
equation index: 3104
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[20] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 20, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3104(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3104};
  (data->localData[0]->realVars[290] /* Chile.comp_tomatosouce.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 20), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3105
type: SIMPLE_ASSIGN
Chile.tomatosouce.Hemicellulose_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.hemicellulose else Chile.comp_tomatosouce.y[20]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3105(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3105};
  (data->localData[0]->realVars[1100] /* Chile.tomatosouce.Hemicellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1025] /* Chile.tomatosouce.hemicellulose PARAM */):(data->localData[0]->realVars[290] /* Chile.comp_tomatosouce.y[20] variable */));
  TRACE_POP
}
/*
equation index: 3106
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[21] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 21, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3106(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3106};
  (data->localData[0]->realVars[291] /* Chile.comp_tomatosouce.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 21), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3107
type: SIMPLE_ASSIGN
Chile.tomatosouce.Lignin_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.adl else Chile.comp_tomatosouce.y[21]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3107(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3107};
  (data->localData[0]->realVars[1114] /* Chile.tomatosouce.Lignin_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[992] /* Chile.tomatosouce.adl PARAM */):(data->localData[0]->realVars[291] /* Chile.comp_tomatosouce.y[21] variable */));
  TRACE_POP
}
/*
equation index: 3108
type: SIMPLE_ASSIGN
Chile.tomatosouce.NDF_in = Chile.tomatosouce.Cellulose_in + Chile.tomatosouce.Hemicellulose_in + Chile.tomatosouce.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3108(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3108};
  (data->localData[0]->realVars[1143] /* Chile.tomatosouce.NDF_in variable */) = (data->localData[0]->realVars[1096] /* Chile.tomatosouce.Cellulose_in variable */) + (data->localData[0]->realVars[1100] /* Chile.tomatosouce.Hemicellulose_in variable */) + (data->localData[0]->realVars[1114] /* Chile.tomatosouce.Lignin_in variable */);
  TRACE_POP
}
/*
equation index: 3109
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_lig = 0.01361702127659574 * Chile.tomatosouce.TS_in * Chile.tomatosouce.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3109(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3109};
  (data->localData[0]->realVars[1209] /* Chile.tomatosouce.outlet.X_lig variable */) = (0.01361702127659574) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((data->localData[0]->realVars[1114] /* Chile.tomatosouce.Lignin_in variable */)));
  TRACE_POP
}
/*
equation index: 3110
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[22] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 22, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3110(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3110};
  (data->localData[0]->realVars[292] /* Chile.comp_tomatosouce.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 22), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3111
type: SIMPLE_ASSIGN
Chile.tomatosouce.Starch_in = if Chile.tomatosouce.steady == true then Chile.tomatosouce.starch else Chile.comp_tomatosouce.y[22]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3111(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3111};
  (data->localData[0]->realVars[1166] /* Chile.tomatosouce.Starch_in variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[1098] /* Chile.tomatosouce.starch PARAM */):(data->localData[0]->realVars[292] /* Chile.comp_tomatosouce.y[22] variable */));
  TRACE_POP
}
/*
equation index: 3112
type: SIMPLE_ASSIGN
Chile.tomatosouce.CH_in = Chile.tomatosouce.Ssu_in + Chile.tomatosouce.Starch_in + Chile.tomatosouce.NDF_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3112(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3112};
  (data->localData[0]->realVars[1062] /* Chile.tomatosouce.CH_in variable */) = (data->localData[0]->realVars[1165] /* Chile.tomatosouce.Ssu_in variable */) + (data->localData[0]->realVars[1166] /* Chile.tomatosouce.Starch_in variable */) + (data->localData[0]->realVars[1143] /* Chile.tomatosouce.NDF_in variable */);
  TRACE_POP
}
/*
equation index: 3113
type: SIMPLE_ASSIGN
Chile.tomatosouce.tBMPth_vs = 0.01 * (496.0 * Chile.tomatosouce.CP_in + 1014.0 * Chile.tomatosouce.EE_in + 415.0 * Chile.tomatosouce.CH_in) * Chile.tomatosouce.TS_in / Chile.tomatosouce.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3113(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3113};
  (data->localData[0]->realVars[1226] /* Chile.tomatosouce.tBMPth_vs variable */) = (0.01) * (((496.0) * ((data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */)) + (1014.0) * ((data->localData[0]->realVars[1097] /* Chile.tomatosouce.EE_in variable */)) + (415.0) * ((data->localData[0]->realVars[1062] /* Chile.tomatosouce.CH_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */),(data->localData[0]->realVars[1171] /* Chile.tomatosouce.VS_in variable */),"Chile.tomatosouce.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3114
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_ch[1] = 0.01185185185185185 * Chile.tomatosouce.Starch_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3114(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3114};
  (data->localData[0]->realVars[1201] /* Chile.tomatosouce.outlet.X_ch[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[1166] /* Chile.tomatosouce.Starch_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3115
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[23] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 23, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3115(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3115};
  (data->localData[0]->realVars[293] /* Chile.comp_tomatosouce.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 23), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3116
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_pr = if Chile.tomatosouce.steady == true then Chile.tomatosouce.bd_pr else Chile.comp_tomatosouce.y[23]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3116(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3116};
  (data->localData[0]->realVars[1060] /* Chile.tomatosouce.BD_pr variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[997] /* Chile.tomatosouce.bd_pr PARAM */):(data->localData[0]->realVars[293] /* Chile.comp_tomatosouce.y[23] variable */));
  TRACE_POP
}
/*
equation index: 3117
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_i[2] = 0.01530355097365406 * Chile.tomatosouce.TS_in * (1.0 + (-0.01) * Chile.tomatosouce.BD_pr) * Chile.tomatosouce.CP_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3117(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3117};
  (data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */) = (0.01530355097365406) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[1060] /* Chile.tomatosouce.BD_pr variable */))) * ((data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */))));
  TRACE_POP
}
/*
equation index: 3118
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_pr[2] = 0.0001530355097365406 * Chile.tomatosouce.f_pr_s * Chile.tomatosouce.CP_in * Chile.tomatosouce.TS_in * Chile.tomatosouce.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3118(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3118};
  (data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[1017] /* Chile.tomatosouce.f_pr_s PARAM */)) * (((data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */)) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((data->localData[0]->realVars[1060] /* Chile.tomatosouce.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 3119
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_pr[1] = 0.0001530355097365406 * Chile.tomatosouce.f_pr_r * Chile.tomatosouce.CP_in * Chile.tomatosouce.TS_in * Chile.tomatosouce.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3119(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3119};
  (data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[1016] /* Chile.tomatosouce.f_pr_r PARAM */)) * (((data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */)) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((data->localData[0]->realVars[1060] /* Chile.tomatosouce.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 3120
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[24] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 24, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3120(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3120};
  (data->localData[0]->realVars[294] /* Chile.comp_tomatosouce.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 24), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3121
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_li = if Chile.tomatosouce.steady == true then Chile.tomatosouce.bd_li else Chile.comp_tomatosouce.y[24]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3121(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3121};
  (data->localData[0]->realVars[1059] /* Chile.tomatosouce.BD_li variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[996] /* Chile.tomatosouce.bd_li PARAM */):(data->localData[0]->realVars[294] /* Chile.comp_tomatosouce.y[24] variable */));
  TRACE_POP
}
/*
equation index: 3122
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_i[3] = 0.02830726906025207 * Chile.tomatosouce.TS_in * (1.0 + (-0.01) * Chile.tomatosouce.BD_li) * Chile.tomatosouce.EE_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3122(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3122};
  (data->localData[0]->realVars[1206] /* Chile.tomatosouce.outlet.X_i[3] variable */) = (0.02830726906025207) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[1059] /* Chile.tomatosouce.BD_li variable */))) * ((data->localData[0]->realVars[1097] /* Chile.tomatosouce.EE_in variable */))));
  TRACE_POP
}
/*
equation index: 3123
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_li = 0.0002830726906025207 * Chile.tomatosouce.EE_in * Chile.tomatosouce.TS_in * Chile.tomatosouce.BD_li
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3123(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3123};
  (data->localData[0]->realVars[1208] /* Chile.tomatosouce.outlet.X_li variable */) = (0.0002830726906025207) * (((data->localData[0]->realVars[1097] /* Chile.tomatosouce.EE_in variable */)) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((data->localData[0]->realVars[1059] /* Chile.tomatosouce.BD_li variable */))));
  TRACE_POP
}
/*
equation index: 3124
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[25] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 25, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3124(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3124};
  (data->localData[0]->realVars[295] /* Chile.comp_tomatosouce.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 25), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3125
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_cell = if Chile.tomatosouce.steady == true then Chile.tomatosouce.bd_cell else Chile.comp_tomatosouce.y[25]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3125(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3125};
  (data->localData[0]->realVars[1056] /* Chile.tomatosouce.BD_cell variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[994] /* Chile.tomatosouce.bd_cell PARAM */):(data->localData[0]->realVars[295] /* Chile.comp_tomatosouce.y[25] variable */));
  TRACE_POP
}
/*
equation index: 3126
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_ch[3] = 0.0001185185185185185 * Chile.tomatosouce.BD_cell * Chile.tomatosouce.Cellulose_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3126(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3126};
  (data->localData[0]->realVars[1203] /* Chile.tomatosouce.outlet.X_ch[3] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[1056] /* Chile.tomatosouce.BD_cell variable */)) * (((data->localData[0]->realVars[1096] /* Chile.tomatosouce.Cellulose_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3127
type: SIMPLE_ASSIGN
Chile.comp_tomatosouce.y[26] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_tomatosouce.tableID, 26, Chile.comp_tomatosouce.timeScaled, Chile.comp_tomatosouce.nextTimeEventScaled, pre(Chile.comp_tomatosouce.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3127(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3127};
  (data->localData[0]->realVars[296] /* Chile.comp_tomatosouce.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[3]), ((modelica_integer) 26), (data->localData[0]->realVars[270] /* Chile.comp_tomatosouce.timeScaled variable */), (data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3128
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_hemicell = if Chile.tomatosouce.steady == true then Chile.tomatosouce.bd_hemicell else Chile.comp_tomatosouce.y[26]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3128(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3128};
  (data->localData[0]->realVars[1058] /* Chile.tomatosouce.BD_hemicell variable */) = (((!(data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[30] /* Chile.tomatosouce.steady PARAM */) && 1))?(data->simulationInfo->realParameter[995] /* Chile.tomatosouce.bd_hemicell PARAM */):(data->localData[0]->realVars[296] /* Chile.comp_tomatosouce.y[26] variable */));
  TRACE_POP
}
/*
equation index: 3129
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_ch = 100.0 * (Chile.tomatosouce.Ssu_in + Chile.tomatosouce.Starch_in + 0.01 * (Chile.tomatosouce.BD_cell * Chile.tomatosouce.Cellulose_in + Chile.tomatosouce.BD_hemicell * Chile.tomatosouce.Hemicellulose_in)) / Chile.tomatosouce.CH_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3129(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3129};
  (data->localData[0]->realVars[1057] /* Chile.tomatosouce.BD_ch variable */) = DIVISION_SIM((100.0) * ((data->localData[0]->realVars[1165] /* Chile.tomatosouce.Ssu_in variable */) + (data->localData[0]->realVars[1166] /* Chile.tomatosouce.Starch_in variable */) + (0.01) * (((data->localData[0]->realVars[1056] /* Chile.tomatosouce.BD_cell variable */)) * ((data->localData[0]->realVars[1096] /* Chile.tomatosouce.Cellulose_in variable */)) + ((data->localData[0]->realVars[1058] /* Chile.tomatosouce.BD_hemicell variable */)) * ((data->localData[0]->realVars[1100] /* Chile.tomatosouce.Hemicellulose_in variable */)))),(data->localData[0]->realVars[1062] /* Chile.tomatosouce.CH_in variable */),"Chile.tomatosouce.CH_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 3130
type: SIMPLE_ASSIGN
Chile.tomatosouce.BD_vs = 0.01 * (Chile.tomatosouce.BD_ch * Chile.tomatosouce.CH_in + Chile.tomatosouce.BD_pr * Chile.tomatosouce.CP_in + Chile.tomatosouce.BD_li * Chile.tomatosouce.EE_in) * Chile.tomatosouce.TS_in / Chile.tomatosouce.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3130(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3130};
  (data->localData[0]->realVars[1061] /* Chile.tomatosouce.BD_vs variable */) = (0.01) * ((((data->localData[0]->realVars[1057] /* Chile.tomatosouce.BD_ch variable */)) * ((data->localData[0]->realVars[1062] /* Chile.tomatosouce.CH_in variable */)) + ((data->localData[0]->realVars[1060] /* Chile.tomatosouce.BD_pr variable */)) * ((data->localData[0]->realVars[1094] /* Chile.tomatosouce.CP_in variable */)) + ((data->localData[0]->realVars[1059] /* Chile.tomatosouce.BD_li variable */)) * ((data->localData[0]->realVars[1097] /* Chile.tomatosouce.EE_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */),(data->localData[0]->realVars[1171] /* Chile.tomatosouce.VS_in variable */),"Chile.tomatosouce.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3131
type: SIMPLE_ASSIGN
Chile.tomatosouce.tBMPerror = 0.01 * Chile.tomatosouce.BD_vs * Chile.tomatosouce.tBMPth_vs - Chile.tomatosouce.tBMP_VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3131(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3131};
  (data->localData[0]->realVars[1219] /* Chile.tomatosouce.tBMPerror variable */) = (0.01) * (((data->localData[0]->realVars[1061] /* Chile.tomatosouce.BD_vs variable */)) * ((data->localData[0]->realVars[1226] /* Chile.tomatosouce.tBMPth_vs variable */))) - (data->localData[0]->realVars[1218] /* Chile.tomatosouce.tBMP_VS_in variable */);
  TRACE_POP
}
/*
equation index: 3132
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_i[1] = 0.01185185185185185 * Chile.tomatosouce.TS_in * ((1.0 + (-0.01) * Chile.tomatosouce.BD_cell) * Chile.tomatosouce.Cellulose_in + (1.0 + (-0.01) * Chile.tomatosouce.BD_hemicell) * Chile.tomatosouce.Hemicellulose_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3132(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3132};
  (data->localData[0]->realVars[1204] /* Chile.tomatosouce.outlet.X_i[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[1056] /* Chile.tomatosouce.BD_cell variable */))) * ((data->localData[0]->realVars[1096] /* Chile.tomatosouce.Cellulose_in variable */)) + (1.0 + (-0.01) * ((data->localData[0]->realVars[1058] /* Chile.tomatosouce.BD_hemicell variable */))) * ((data->localData[0]->realVars[1100] /* Chile.tomatosouce.Hemicellulose_in variable */))));
  TRACE_POP
}
/*
equation index: 3133
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_i[4] = Chile.tomatosouce.outlet.X_i[1] + Chile.tomatosouce.outlet.X_i[2] + Chile.tomatosouce.outlet.X_i[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3133(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3133};
  (data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */) = (data->localData[0]->realVars[1204] /* Chile.tomatosouce.outlet.X_i[1] variable */) + (data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */) + (data->localData[0]->realVars[1206] /* Chile.tomatosouce.outlet.X_i[3] variable */);
  TRACE_POP
}
/*
equation index: 3134
type: SIMPLE_ASSIGN
Chile.tomatosouce.f_xi[2] = Chile.tomatosouce.outlet.X_i[2] / Chile.tomatosouce.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3134(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3134};
  (data->localData[0]->realVars[1189] /* Chile.tomatosouce.f_xi[2] variable */) = DIVISION_SIM((data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */),(data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */),"Chile.tomatosouce.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3135
type: SIMPLE_ASSIGN
Chile.tomatosouce.PR_tot_BCA = (1.166666666666667e-10 + Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.outlet.X_pr[1] + Chile.tomatosouce.outlet.X_pr[2] + 1e-10 * Chile.tomatosouce.f_xi[2] + Chile.tomatosouce.si + Chile.tomatosouce.outlet.X_i[2] + (Chile.tomatosouce.xaa + Chile.tomatosouce.xac + Chile.tomatosouce.xc4 + Chile.tomatosouce.xfa + Chile.tomatosouce.xh2 + Chile.tomatosouce.xpro + Chile.tomatosouce.xsu) * Chile.tomatosouce.f_Xbiom_pr) / Chile.tomatosouce.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3135(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3135};
  (data->localData[0]->realVars[1146] /* Chile.tomatosouce.PR_tot_BCA variable */) = DIVISION_SIM(1.166666666666667e-10 + (data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[1189] /* Chile.tomatosouce.f_xi[2] variable */)) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */)) * ((data->simulationInfo->realParameter[1009] /* Chile.tomatosouce.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[947] /* Chile.tomatosouce.COD_VS_PR_BCA PARAM */),"Chile.tomatosouce.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3136
type: SIMPLE_ASSIGN
Chile.tomatosouce.PR_tot_TKN = 0.6534431137724552 * (2e-10 + Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.outlet.X_pr[1] + Chile.tomatosouce.outlet.X_pr[2] + 1e-10 * Chile.tomatosouce.f_xi[2] + Chile.tomatosouce.si + Chile.tomatosouce.outlet.X_i[2] + (Chile.tomatosouce.xaa + Chile.tomatosouce.xac + Chile.tomatosouce.xc4 + Chile.tomatosouce.xfa + Chile.tomatosouce.xh2 + Chile.tomatosouce.xpro + Chile.tomatosouce.xsu) * Chile.tomatosouce.f_Xbiom_pr) / Chile.tomatosouce.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3136(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3136};
  (data->localData[0]->realVars[1147] /* Chile.tomatosouce.PR_tot_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM(2e-10 + (data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[1189] /* Chile.tomatosouce.f_xi[2] variable */)) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */)) * ((data->simulationInfo->realParameter[1009] /* Chile.tomatosouce.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[975] /* Chile.tomatosouce.N_PR PARAM */),"Chile.tomatosouce.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3137
type: SIMPLE_ASSIGN
Chile.tomatosouce.f_xi[3] = Chile.tomatosouce.outlet.X_i[3] / Chile.tomatosouce.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3137(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3137};
  (data->localData[0]->realVars[1190] /* Chile.tomatosouce.f_xi[3] variable */) = DIVISION_SIM((data->localData[0]->realVars[1206] /* Chile.tomatosouce.outlet.X_i[3] variable */),(data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */),"Chile.tomatosouce.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3138
type: SIMPLE_ASSIGN
Chile.tomatosouce.LI_tot = 0.3532661514862131 * (2e-10 + Chile.tomatosouce.outlet.S_fa + Chile.tomatosouce.outlet.X_li + 1e-10 * Chile.tomatosouce.f_xi[3] + Chile.tomatosouce.si + Chile.tomatosouce.outlet.X_i[3] + (Chile.tomatosouce.xaa + Chile.tomatosouce.xac + Chile.tomatosouce.xc4 + Chile.tomatosouce.xfa + Chile.tomatosouce.xh2 + Chile.tomatosouce.xpro + Chile.tomatosouce.xsu) * Chile.tomatosouce.f_Xbiom_li)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3138(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3138};
  (data->localData[0]->realVars[1113] /* Chile.tomatosouce.LI_tot variable */) = (0.3532661514862131) * (2e-10 + (data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) + (data->localData[0]->realVars[1208] /* Chile.tomatosouce.outlet.X_li variable */) + (1e-10) * ((data->localData[0]->realVars[1190] /* Chile.tomatosouce.f_xi[3] variable */)) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1206] /* Chile.tomatosouce.outlet.X_i[3] variable */) + ((data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */)) * ((data->simulationInfo->realParameter[1008] /* Chile.tomatosouce.f_Xbiom_li PARAM */)));
  TRACE_POP
}
/*
equation index: 3139
type: SIMPLE_ASSIGN
Chile.tomatosouce.f_xi[1] = Chile.tomatosouce.outlet.X_i[1] / Chile.tomatosouce.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3139(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3139};
  (data->localData[0]->realVars[1188] /* Chile.tomatosouce.f_xi[1] variable */) = DIVISION_SIM((data->localData[0]->realVars[1204] /* Chile.tomatosouce.outlet.X_i[1] variable */),(data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */),"Chile.tomatosouce.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3140
type: SIMPLE_ASSIGN
Chile.tomatosouce.COD_VS[25] = 1.0 / (0.84375 * Chile.tomatosouce.f_xi[1] + Chile.tomatosouce.f_xi[2] / 1.530355097365406 + Chile.tomatosouce.f_xi[3] / 2.830726906025207)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3140(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3140};
  (data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */) = DIVISION_SIM(1.0,(0.84375) * ((data->localData[0]->realVars[1188] /* Chile.tomatosouce.f_xi[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[1189] /* Chile.tomatosouce.f_xi[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1190] /* Chile.tomatosouce.f_xi[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes),"0.84375 * Chile.tomatosouce.f_xi[1] + Chile.tomatosouce.f_xi[2] / 1.530355097365406 + Chile.tomatosouce.f_xi[3] / 2.830726906025207",equationIndexes);
  TRACE_POP
}
/*
equation index: 3141
type: SIMPLE_ASSIGN
Chile.tomatosouce.COD_VS[14] = 1.0 / (4.435293530517336 + 1.0 / Chile.tomatosouce.COD_VS[25])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3141(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3141};
  (data->localData[0]->realVars[1078] /* Chile.tomatosouce.COD_VS[14] variable */) = DIVISION_SIM(1.0,4.435293530517336 + DIVISION_SIM(1.0,(data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */),"Chile.tomatosouce.COD_VS[25]",equationIndexes),"4.435293530517336 + 1.0 / Chile.tomatosouce.COD_VS[25]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3142
type: SIMPLE_ASSIGN
Chile.tomatosouce.MW[25] = 1.0 / (Chile.tomatosouce.COD_VS[25] * (Chile.tomatosouce.f_xi[1] / 192.0 + Chile.tomatosouce.f_xi[2] / 133.6 + Chile.tomatosouce.f_xi[3] / 2352.194407671715))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3142(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3142};
  (data->localData[0]->realVars[1139] /* Chile.tomatosouce.MW[25] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1188] /* Chile.tomatosouce.f_xi[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1189] /* Chile.tomatosouce.f_xi[2] variable */),133.6,"133.6",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[1190] /* Chile.tomatosouce.f_xi[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes)),"Chile.tomatosouce.COD_VS[25] * (Chile.tomatosouce.f_xi[1] / 192.0 + Chile.tomatosouce.f_xi[2] / 133.6 + Chile.tomatosouce.f_xi[3] / 2352.194407671715)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3143
type: SIMPLE_ASSIGN
Chile.tomatosouce.MW[14] = 1.0 / ((0.03404949640278076 + 1.0 / (Chile.tomatosouce.MW[25] * Chile.tomatosouce.COD_VS[25])) * Chile.tomatosouce.COD_VS[14])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3143(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3143};
  (data->localData[0]->realVars[1128] /* Chile.tomatosouce.MW[14] variable */) = DIVISION_SIM(1.0,(0.03404949640278076 + DIVISION_SIM(1.0,((data->localData[0]->realVars[1139] /* Chile.tomatosouce.MW[25] variable */)) * ((data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */)),"Chile.tomatosouce.MW[25] * Chile.tomatosouce.COD_VS[25]",equationIndexes)) * ((data->localData[0]->realVars[1078] /* Chile.tomatosouce.COD_VS[14] variable */)),"(0.03404949640278076 + 1.0 / (Chile.tomatosouce.MW[25] * Chile.tomatosouce.COD_VS[25])) * Chile.tomatosouce.COD_VS[14]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3144
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.X_ch[2] = 0.0001185185185185185 * Chile.tomatosouce.BD_hemicell * Chile.tomatosouce.Hemicellulose_in * Chile.tomatosouce.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3144(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3144};
  (data->localData[0]->realVars[1202] /* Chile.tomatosouce.outlet.X_ch[2] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[1058] /* Chile.tomatosouce.BD_hemicell variable */)) * (((data->localData[0]->realVars[1100] /* Chile.tomatosouce.Hemicellulose_in variable */)) * ((data->localData[0]->realVars[1168] /* Chile.tomatosouce.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3145
type: SIMPLE_ASSIGN
Chile.tomatosouce.CH_tot = 1.223958333333333e-11 + 0.9345794392523364 * Chile.tomatosouce.outlet.S_su + 0.84375 * (2e-10 + Chile.tomatosouce.outlet.X_ch[1] + Chile.tomatosouce.outlet.X_ch[2] + Chile.tomatosouce.outlet.X_ch[3] + 1e-10 * Chile.tomatosouce.f_xi[1] + Chile.tomatosouce.si + Chile.tomatosouce.outlet.X_i[1] + (Chile.tomatosouce.xaa + Chile.tomatosouce.xac + Chile.tomatosouce.xc4 + Chile.tomatosouce.xfa + Chile.tomatosouce.xh2 + Chile.tomatosouce.xpro + Chile.tomatosouce.xsu) * Chile.tomatosouce.f_Xbiom_ch) + 0.734375 * Chile.tomatosouce.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3145(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3145};
  (data->localData[0]->realVars[1064] /* Chile.tomatosouce.CH_tot variable */) = 1.223958333333333e-11 + (0.9345794392523364) * ((data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */)) + (0.84375) * (2e-10 + (data->localData[0]->realVars[1201] /* Chile.tomatosouce.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1202] /* Chile.tomatosouce.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1203] /* Chile.tomatosouce.outlet.X_ch[3] variable */) + (1e-10) * ((data->localData[0]->realVars[1188] /* Chile.tomatosouce.f_xi[1] variable */)) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1204] /* Chile.tomatosouce.outlet.X_i[1] variable */) + ((data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */)) * ((data->simulationInfo->realParameter[1007] /* Chile.tomatosouce.f_Xbiom_ch PARAM */))) + (0.734375) * ((data->localData[0]->realVars[1209] /* Chile.tomatosouce.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3146
type: SIMPLE_ASSIGN
Chile.tomatosouce.COD_tot = 1e-10 + Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.ac_in + Chile.tomatosouce.bu_in + Chile.tomatosouce.ch4 + Chile.tomatosouce.outlet.S_fa + Chile.tomatosouce.h2 + Chile.tomatosouce.si + Chile.tomatosouce.pro_in + Chile.tomatosouce.outlet.S_su + Chile.tomatosouce.va_in + Chile.tomatosouce.xaa + Chile.tomatosouce.xac + Chile.tomatosouce.xc4 + Chile.tomatosouce.outlet.X_ch[1] + Chile.tomatosouce.outlet.X_ch[2] + Chile.tomatosouce.outlet.X_ch[3] + Chile.tomatosouce.xfa + Chile.tomatosouce.xh2 + Chile.tomatosouce.outlet.X_i[4] + Chile.tomatosouce.outlet.X_li + Chile.tomatosouce.outlet.X_pr[1] + Chile.tomatosouce.outlet.X_pr[2] + Chile.tomatosouce.xpro + Chile.tomatosouce.xsu + Chile.tomatosouce.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3146(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3146};
  (data->localData[0]->realVars[1093] /* Chile.tomatosouce.COD_tot variable */) = 1e-10 + (data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */) + (data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */) + (data->simulationInfo->realParameter[1002] /* Chile.tomatosouce.ch4 PARAM */) + (data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) + (data->simulationInfo->realParameter[1024] /* Chile.tomatosouce.h2 PARAM */) + (data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */) + (data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */) + (data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */) + (data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */) + (data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->localData[0]->realVars[1201] /* Chile.tomatosouce.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1202] /* Chile.tomatosouce.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1203] /* Chile.tomatosouce.outlet.X_ch[3] variable */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */) + (data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */) + (data->localData[0]->realVars[1208] /* Chile.tomatosouce.outlet.X_li variable */) + (data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */) + (data->localData[0]->realVars[1209] /* Chile.tomatosouce.outlet.X_lig variable */);
  TRACE_POP
}
/*
equation index: 3147
type: SIMPLE_ASSIGN
Chile.tomatosouce.VS = (Chile.tomatosouce.xsu + Chile.tomatosouce.xaa + Chile.tomatosouce.xfa + Chile.tomatosouce.xc4 + Chile.tomatosouce.xpro + Chile.tomatosouce.xac + Chile.tomatosouce.xh2) * (0.84375 * Chile.tomatosouce.f_ch_xb + 0.6534431137724552 * Chile.tomatosouce.f_pr_xb + 0.3532661514862131 * Chile.tomatosouce.f_li_xb + 1.850459265258668 * Chile.tomatosouce.f_si_xb + Chile.tomatosouce.f_xi_xb / Chile.tomatosouce.COD_VS[25]) + 0.9345794392523364 * Chile.tomatosouce.outlet.S_su + 0.84375 * (Chile.tomatosouce.outlet.X_ch[1] + Chile.tomatosouce.outlet.X_ch[2] + Chile.tomatosouce.outlet.X_ch[3]) + 0.6534431137724552 * (Chile.tomatosouce.outlet.S_aa + Chile.tomatosouce.outlet.X_pr[1] + Chile.tomatosouce.outlet.X_pr[2]) + 0.3532661514862131 * (Chile.tomatosouce.outlet.S_fa + Chile.tomatosouce.outlet.X_li) + 1.850459265258668 * Chile.tomatosouce.si + Chile.tomatosouce.outlet.X_i[4] / Chile.tomatosouce.COD_VS[25] + 1e-10 / Chile.tomatosouce.COD_VS[14] + 0.734375 * Chile.tomatosouce.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3147(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3147};
  (data->localData[0]->realVars[1170] /* Chile.tomatosouce.VS variable */) = ((data->simulationInfo->realParameter[1113] /* Chile.tomatosouce.xsu PARAM */) + (data->simulationInfo->realParameter[1107] /* Chile.tomatosouce.xaa PARAM */) + (data->simulationInfo->realParameter[1110] /* Chile.tomatosouce.xfa PARAM */) + (data->simulationInfo->realParameter[1109] /* Chile.tomatosouce.xc4 PARAM */) + (data->simulationInfo->realParameter[1112] /* Chile.tomatosouce.xpro PARAM */) + (data->simulationInfo->realParameter[1108] /* Chile.tomatosouce.xac PARAM */) + (data->simulationInfo->realParameter[1111] /* Chile.tomatosouce.xh2 PARAM */)) * ((0.84375) * ((data->simulationInfo->realParameter[1012] /* Chile.tomatosouce.f_ch_xb PARAM */)) + (0.6534431137724552) * ((data->simulationInfo->realParameter[1018] /* Chile.tomatosouce.f_pr_xb PARAM */)) + (0.3532661514862131) * ((data->simulationInfo->realParameter[1015] /* Chile.tomatosouce.f_li_xb PARAM */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[1020] /* Chile.tomatosouce.f_si_xb PARAM */)) + DIVISION_SIM((data->simulationInfo->realParameter[1022] /* Chile.tomatosouce.f_xi_xb PARAM */),(data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */),"Chile.tomatosouce.COD_VS[25]",equationIndexes)) + (0.9345794392523364) * ((data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */)) + (0.84375) * ((data->localData[0]->realVars[1201] /* Chile.tomatosouce.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[1202] /* Chile.tomatosouce.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[1203] /* Chile.tomatosouce.outlet.X_ch[3] variable */)) + (0.6534431137724552) * ((data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */) + (data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */)) + (0.3532661514862131) * ((data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */) + (data->localData[0]->realVars[1208] /* Chile.tomatosouce.outlet.X_li variable */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[1097] /* Chile.tomatosouce.si PARAM */)) + DIVISION_SIM((data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */),(data->localData[0]->realVars[1089] /* Chile.tomatosouce.COD_VS[25] variable */),"Chile.tomatosouce.COD_VS[25]",equationIndexes) + DIVISION_SIM(1e-10,(data->localData[0]->realVars[1078] /* Chile.tomatosouce.COD_VS[14] variable */),"Chile.tomatosouce.COD_VS[14]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[1209] /* Chile.tomatosouce.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3148
type: WHEN

when {$whenCondition6} then
  Chile.comp_tomatosouce.nextTimeEvent = if Chile.comp_tomatosouce.nextTimeEventScaled < 9.999999999999999e+59 then Chile.comp_tomatosouce.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3148(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3148};
  modelica_boolean tmp15;
  if(((data->localData[0]->booleanVars[5] /* $whenCondition6 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[5] /* $whenCondition6 DISCRETE */) /* edge */))
  {
    tmp15 = Less((data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1257] /* Chile.comp_tomatosouce.nextTimeEvent DISCRETE */) = (tmp15?(data->localData[0]->realVars[1258] /* Chile.comp_tomatosouce.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 3149
type: SIMPLE_ASSIGN
$whenCondition7 = time >= pre(Chile.comp_maize.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3149(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3149};
  modelica_boolean tmp16;
  relationhysteresis(data, &tmp16, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1251] /* Chile.comp_maize.nextTimeEvent DISCRETE */), 2, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[6] /* $whenCondition7 DISCRETE */) = tmp16;
  TRACE_POP
}
/*
equation index: 3150
type: WHEN

when {$whenCondition7} then
  Chile.comp_maize.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Chile.comp_maize.tableID, Chile.comp_maize.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3150(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3150};
  if(((data->localData[0]->booleanVars[6] /* $whenCondition7 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[6] /* $whenCondition7 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[0]), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 3151
type: SIMPLE_ASSIGN
Chile.comp_maize.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 1, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3151(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3151};
  (data->localData[0]->realVars[190] /* Chile.comp_maize.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 1), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3152
type: SIMPLE_ASSIGN
Chile.maize.TS_in = if Chile.maize.steady == true then Chile.maize.ts else Chile.comp_maize.y[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3152(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3152};
  (data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[696] /* Chile.maize.ts PARAM */):(data->localData[0]->realVars[190] /* Chile.comp_maize.y[1] variable */));
  TRACE_POP
}
/*
equation index: 3153
type: SIMPLE_ASSIGN
Chile.maize.u = 1.0 + (-0.001) * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3153(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3153};
  (data->localData[0]->realVars[863] /* Chile.maize.u variable */) = 1.0 + (-0.001) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */));
  TRACE_POP
}
/*
equation index: 3154
type: SIMPLE_ASSIGN
Chile.comp_maize.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 2, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3154(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3154};
  (data->localData[0]->realVars[191] /* Chile.comp_maize.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 2), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3155
type: SIMPLE_ASSIGN
Chile.maize.VS_in = if Chile.maize.steady == true then 0.01 * Chile.maize.vs_ts * Chile.maize.TS_in else 0.01 * Chile.comp_maize.y[2] * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3155(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3155};
  (data->localData[0]->realVars[807] /* Chile.maize.VS_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(0.01) * (((data->simulationInfo->realParameter[698] /* Chile.maize.vs_ts PARAM */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */))):(0.01) * (((data->localData[0]->realVars[191] /* Chile.comp_maize.y[2] variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3156
type: SIMPLE_ASSIGN
Chile.maize.v = Chile.maize.VS_in / Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3156(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3156};
  (data->localData[0]->realVars[864] /* Chile.maize.v variable */) = DIVISION_SIM((data->localData[0]->realVars[807] /* Chile.maize.VS_in variable */),(data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */),"Chile.maize.TS_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 3157
type: SIMPLE_ASSIGN
Chile.maize.d = 1.0 / (0.001 * Chile.maize.u + (1.0 - Chile.maize.u) * (0.0004 + Chile.maize.v * 0.0005523809523809524))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3157(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3157};
  (data->localData[0]->realVars[810] /* Chile.maize.d variable */) = DIVISION_SIM(1.0,(0.001) * ((data->localData[0]->realVars[863] /* Chile.maize.u variable */)) + (1.0 - (data->localData[0]->realVars[863] /* Chile.maize.u variable */)) * (0.0004 + ((data->localData[0]->realVars[864] /* Chile.maize.v variable */)) * (0.0005523809523809524)),"0.001 * Chile.maize.u + (1.0 - Chile.maize.u) * (0.0004 + Chile.maize.v * 0.0005523809523809524)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3158
type: SIMPLE_ASSIGN
Chile.maize.outlet.ash = Chile.maize.TS_in - Chile.maize.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3158(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3158};
  (data->localData[0]->realVars[851] /* Chile.maize.outlet.ash variable */) = (data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */) - (data->localData[0]->realVars[807] /* Chile.maize.VS_in variable */);
  TRACE_POP
}
/*
equation index: 3159
type: SIMPLE_ASSIGN
Chile.digester.ash_in = ($cse1 * Chile.maize.outlet.ash + $cse2 * Chile.tomatosouce.outlet.ash + $cse3 * Chile.slurry.outlet.ash) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3159(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3159};
  (data->localData[0]->realVars[520] /* Chile.digester.ash_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[851] /* Chile.maize.outlet.ash variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1215] /* Chile.tomatosouce.outlet.ash variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1037] /* Chile.slurry.outlet.ash variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3160
type: SIMPLE_ASSIGN
$DER.Chile.digester.ash = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.ash_in - Chile.digester.ash)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3160(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3160};
  (data->localData[0]->realVars[136] /* der(Chile.digester.ash) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[520] /* Chile.digester.ash_in variable */) - (data->localData[0]->realVars[63] /* Chile.digester.ash STATE(1) */)));
  TRACE_POP
}
/*
equation index: 3161
type: SIMPLE_ASSIGN
Chile.comp_maize.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 3, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3161(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3161};
  (data->localData[0]->realVars[192] /* Chile.comp_maize.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 3), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3162
type: SIMPLE_ASSIGN
Chile.maize.pH = if Chile.maize.steady == true then Chile.maize.ph else Chile.comp_maize.y[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3162(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3162};
  (data->localData[0]->realVars[852] /* Chile.maize.pH variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[686] /* Chile.maize.ph PARAM */):(data->localData[0]->realVars[192] /* Chile.comp_maize.y[3] variable */));
  TRACE_POP
}
/*
equation index: 3163
type: SIMPLE_ASSIGN
Chile.maize.S_h = 10.0 ^ (-Chile.maize.pH)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3163(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3163};
  modelica_real tmp20;
  modelica_real tmp21;
  modelica_real tmp22;
  modelica_real tmp23;
  modelica_real tmp24;
  modelica_real tmp25;
  modelica_real tmp26;
  tmp20 = 10.0;
  tmp21 = (-(data->localData[0]->realVars[852] /* Chile.maize.pH variable */));
  if(tmp20 < 0.0 && tmp21 != 0.0)
  {
    tmp23 = modf(tmp21, &tmp24);
    
    if(tmp23 > 0.5)
    {
      tmp23 -= 1.0;
      tmp24 += 1.0;
    }
    else if(tmp23 < -0.5)
    {
      tmp23 += 1.0;
      tmp24 -= 1.0;
    }
    
    if(fabs(tmp23) < 1e-10)
      tmp22 = pow(tmp20, tmp24);
    else
    {
      tmp26 = modf(1.0/tmp21, &tmp25);
      if(tmp26 > 0.5)
      {
        tmp26 -= 1.0;
        tmp25 += 1.0;
      }
      else if(tmp26 < -0.5)
      {
        tmp26 += 1.0;
        tmp25 -= 1.0;
      }
      if(fabs(tmp26) < 1e-10 && ((unsigned long)tmp25 & 1))
      {
        tmp22 = -pow(-tmp20, tmp23)*pow(tmp20, tmp24);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
      }
    }
  }
  else
  {
    tmp22 = pow(tmp20, tmp21);
  }
  if(isnan(tmp22) || isinf(tmp22))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp20, tmp21);
  }
  (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) = tmp22;
  TRACE_POP
}
/*
equation index: 3164
type: SIMPLE_ASSIGN
Chile.maize.S_oh = Chile.maize.Ka_h2o / Chile.maize.S_h
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3164(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3164};
  (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) = DIVISION_SIM((data->localData[0]->realVars[740] /* Chile.maize.Ka_h2o variable */),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes);
  TRACE_POP
}
/*
equation index: 3165
type: SIMPLE_ASSIGN
Chile.comp_maize.y[4] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 4, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3165(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3165};
  (data->localData[0]->realVars[193] /* Chile.comp_maize.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 4), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3166
type: SIMPLE_ASSIGN
Chile.maize.Alk_in = if Chile.maize.steady == true then Chile.maize.tac else Chile.comp_maize.y[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3166(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3166};
  (data->localData[0]->realVars[689] /* Chile.maize.Alk_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[692] /* Chile.maize.tac PARAM */):(data->localData[0]->realVars[193] /* Chile.comp_maize.y[4] variable */));
  TRACE_POP
}
/*
equation index: 3167
type: SIMPLE_ASSIGN
Chile.maize.Alk_mol = 2e-05 * Chile.maize.Alk_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3167(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3167};
  (data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) = (2e-05) * ((data->localData[0]->realVars[689] /* Chile.maize.Alk_in variable */));
  TRACE_POP
}
/*
equation index: 3168
type: SIMPLE_ASSIGN
Chile.comp_maize.y[5] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 5, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3168(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3168};
  (data->localData[0]->realVars[194] /* Chile.comp_maize.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 5), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3169
type: SIMPLE_ASSIGN
Chile.maize.Ammonium_in = if Chile.maize.steady == true then Chile.maize.tan else Chile.comp_maize.y[5]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3169(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3169};
  (data->localData[0]->realVars[691] /* Chile.maize.Ammonium_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[693] /* Chile.maize.tan PARAM */):(data->localData[0]->realVars[194] /* Chile.comp_maize.y[5] variable */));
  TRACE_POP
}
/*
equation index: 3170
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_in = 7.142857142857143e-05 * Chile.maize.Ammonium_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3170(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3170};
  (data->localData[0]->realVars[831] /* Chile.maize.outlet.S_in variable */) = (7.142857142857143e-05) * ((data->localData[0]->realVars[691] /* Chile.maize.Ammonium_in variable */));
  TRACE_POP
}
/*
equation index: 3171
type: SIMPLE_ASSIGN
Chile.maize.TAN = 14000.0 * Chile.maize.outlet.S_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3171(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3171};
  (data->localData[0]->realVars[803] /* Chile.maize.TAN variable */) = (14000.0) * ((data->localData[0]->realVars[831] /* Chile.maize.outlet.S_in variable */));
  TRACE_POP
}
/*
equation index: 3172
type: SIMPLE_ASSIGN
Chile.maize.S_nh4 = Chile.maize.outlet.S_in * Chile.maize.S_h / (Chile.maize.Ka_nh4 + Chile.maize.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3172(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3172};
  (data->localData[0]->realVars[794] /* Chile.maize.S_nh4 variable */) = ((data->localData[0]->realVars[831] /* Chile.maize.outlet.S_in variable */)) * (DIVISION_SIM((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),(data->localData[0]->realVars[745] /* Chile.maize.Ka_nh4 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.Ka_nh4 + Chile.maize.S_h",equationIndexes));
  TRACE_POP
}
/*
equation index: 3173
type: SIMPLE_ASSIGN
Chile.maize.S_nh3 = Chile.maize.outlet.S_in - Chile.maize.S_nh4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3173(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3173};
  (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) = (data->localData[0]->realVars[831] /* Chile.maize.outlet.S_in variable */) - (data->localData[0]->realVars[794] /* Chile.maize.S_nh4 variable */);
  TRACE_POP
}
/*
equation index: 3174
type: SIMPLE_ASSIGN
Chile.digester.S_in_in = ($cse1 * Chile.maize.outlet.S_in + $cse2 * Chile.tomatosouce.outlet.S_in + $cse3 * Chile.slurry.outlet.S_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3174(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3174};
  (data->localData[0]->realVars[451] /* Chile.digester.S_in_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[831] /* Chile.maize.outlet.S_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1195] /* Chile.tomatosouce.outlet.S_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1017] /* Chile.slurry.outlet.S_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3175
type: SIMPLE_ASSIGN
Chile.comp_maize.y[6] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 6, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3175(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3175};
  (data->localData[0]->realVars[195] /* Chile.comp_maize.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 6), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3176
type: SIMPLE_ASSIGN
Chile.maize.Fosfates_in = if Chile.maize.steady == true then Chile.maize.ortop else Chile.comp_maize.y[6]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3176(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3176};
  (data->localData[0]->realVars[735] /* Chile.maize.Fosfates_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[656] /* Chile.maize.ortop PARAM */):(data->localData[0]->realVars[195] /* Chile.comp_maize.y[6] variable */));
  TRACE_POP
}
/*
equation index: 3177
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_ip = 3.228539045402363e-05 * Chile.maize.Fosfates_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3177(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3177};
  (data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */) = (3.228539045402363e-05) * ((data->localData[0]->realVars[735] /* Chile.maize.Fosfates_in variable */));
  TRACE_POP
}
/*
equation index: 3178
type: SIMPLE_ASSIGN
Chile.maize.S_hpo4 = Chile.maize.Ka_h2po4 * Chile.maize.outlet.S_ip / (Chile.maize.Ka_hpo4 * Chile.maize.Ka_h2po4 / Chile.maize.S_h + Chile.maize.Ka_h2po4 + Chile.maize.S_h + Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_h3po4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3178(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3178};
  modelica_real tmp30;
  tmp30 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) = ((data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */),((data->localData[0]->realVars[744] /* Chile.maize.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes)) + (data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + DIVISION_SIM((tmp30 * tmp30),(data->localData[0]->realVars[742] /* Chile.maize.Ka_h3po4 variable */),"Chile.maize.Ka_h3po4",equationIndexes),"Chile.maize.Ka_hpo4 * Chile.maize.Ka_h2po4 / Chile.maize.S_h + Chile.maize.Ka_h2po4 + Chile.maize.S_h + Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_h3po4",equationIndexes));
  TRACE_POP
}
/*
equation index: 3179
type: SIMPLE_ASSIGN
Chile.maize.S_po4 = Chile.maize.Ka_hpo4 * Chile.maize.outlet.S_ip / (Chile.maize.Ka_hpo4 + Chile.maize.S_h + Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_h2po4 + Chile.maize.S_h ^ 3.0 / (Chile.maize.Ka_h3po4 * Chile.maize.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3179(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3179};
  modelica_real tmp31;
  modelica_real tmp32;
  tmp31 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  tmp32 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */) = ((data->localData[0]->realVars[744] /* Chile.maize.Ka_hpo4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */),(data->localData[0]->realVars[744] /* Chile.maize.Ka_hpo4 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + DIVISION_SIM((tmp31 * tmp31),(data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */),"Chile.maize.Ka_h2po4",equationIndexes) + DIVISION_SIM((tmp32 * tmp32 * tmp32),((data->localData[0]->realVars[742] /* Chile.maize.Ka_h3po4 variable */)) * ((data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */)),"Chile.maize.Ka_h3po4 * Chile.maize.Ka_h2po4",equationIndexes),"Chile.maize.Ka_hpo4 + Chile.maize.S_h + Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_h2po4 + Chile.maize.S_h ^ 3.0 / (Chile.maize.Ka_h3po4 * Chile.maize.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3180
type: SIMPLE_ASSIGN
Chile.maize.S_h2po4 = Chile.maize.outlet.S_ip * Chile.maize.Ka_h3po4 / (Chile.maize.S_h + Chile.maize.Ka_h3po4 * (1.0 + (1.0 / Chile.maize.S_h + Chile.maize.Ka_hpo4 / Chile.maize.S_h ^ 2.0) * Chile.maize.Ka_h2po4))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3180(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3180};
  modelica_real tmp33;
  tmp33 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[789] /* Chile.maize.S_h2po4 variable */) = ((data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */)) * (DIVISION_SIM((data->localData[0]->realVars[742] /* Chile.maize.Ka_h3po4 variable */),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + ((data->localData[0]->realVars[742] /* Chile.maize.Ka_h3po4 variable */)) * (1.0 + (DIVISION_SIM(1.0,(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[744] /* Chile.maize.Ka_hpo4 variable */),(tmp33 * tmp33),"Chile.maize.S_h ^ 2.0",equationIndexes)) * ((data->localData[0]->realVars[741] /* Chile.maize.Ka_h2po4 variable */))),"Chile.maize.S_h + Chile.maize.Ka_h3po4 * (1.0 + (1.0 / Chile.maize.S_h + Chile.maize.Ka_hpo4 / Chile.maize.S_h ^ 2.0) * Chile.maize.Ka_h2po4)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3181
type: SIMPLE_ASSIGN
Chile.maize.S_h3po4 = Chile.maize.outlet.S_ip + (-Chile.maize.S_po4) - Chile.maize.S_h2po4 - Chile.maize.S_hpo4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3181(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3181};
  (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) = (data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */) + (-(data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */)) - (data->localData[0]->realVars[789] /* Chile.maize.S_h2po4 variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */);
  TRACE_POP
}
/*
equation index: 3182
type: SIMPLE_ASSIGN
Chile.digester.S_ip_in = ($cse1 * Chile.maize.outlet.S_ip + $cse2 * Chile.tomatosouce.outlet.S_ip + $cse3 * Chile.slurry.outlet.S_ip) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3182(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3182};
  (data->localData[0]->realVars[452] /* Chile.digester.S_ip_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[832] /* Chile.maize.outlet.S_ip variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1196] /* Chile.tomatosouce.outlet.S_ip variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1018] /* Chile.slurry.outlet.S_ip variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3183
type: SIMPLE_ASSIGN
Chile.comp_maize.y[7] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 7, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3183(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3183};
  (data->localData[0]->realVars[196] /* Chile.comp_maize.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 7), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3184
type: SIMPLE_ASSIGN
Chile.maize.Ca_in = if Chile.maize.steady == true or Chile.maize.liquid == false then Chile.maize.ca else Chile.comp_maize.y[7]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3184(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3184};
  (data->localData[0]->realVars[731] /* Chile.maize.Ca_in variable */) = ((((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[591] /* Chile.maize.ca PARAM */):(data->localData[0]->realVars[196] /* Chile.comp_maize.y[7] variable */));
  TRACE_POP
}
/*
equation index: 3185
type: SIMPLE_ASSIGN
Chile.digester.S_ca_in = ($cse1 * Chile.maize.Ca_in + $cse2 * Chile.tomatosouce.Ca_in + $cse3 * Chile.slurry.Ca_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3185(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3185};
  (data->localData[0]->realVars[435] /* Chile.digester.S_ca_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[731] /* Chile.maize.Ca_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1095] /* Chile.tomatosouce.Ca_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[917] /* Chile.slurry.Ca_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3186
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_ca = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_ca_in - Chile.digester.S_ca) + (-0.05) * (Chile.digester.rp1 - Chile.digester.rd1) + (-0.01666666666666667) * (Chile.digester.rp3 - Chile.digester.rd3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3186(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3186};
  (data->localData[0]->realVars[94] /* der(Chile.digester.S_ca) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[435] /* Chile.digester.S_ca_in variable */) - (data->localData[0]->realVars[21] /* Chile.digester.S_ca STATE(1) */))) + (-0.05) * ((data->localData[0]->realVars[617] /* Chile.digester.rp1 variable */) - (data->localData[0]->realVars[612] /* Chile.digester.rd1 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[619] /* Chile.digester.rp3 variable */) - (data->localData[0]->realVars[614] /* Chile.digester.rd3 variable */));
  TRACE_POP
}
/*
equation index: 3187
type: SIMPLE_ASSIGN
Chile.comp_maize.y[8] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 8, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3187(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3187};
  (data->localData[0]->realVars[197] /* Chile.comp_maize.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 8), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3188
type: SIMPLE_ASSIGN
Chile.maize.Mg_in = if Chile.maize.steady == true or Chile.maize.liquid == false then Chile.maize.mg else Chile.comp_maize.y[8]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3188(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3188};
  (data->localData[0]->realVars[778] /* Chile.maize.Mg_in variable */) = ((((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1)) || ((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0)))?(data->simulationInfo->realParameter[653] /* Chile.maize.mg PARAM */):(data->localData[0]->realVars[197] /* Chile.comp_maize.y[8] variable */));
  TRACE_POP
}
/*
equation index: 3189
type: SIMPLE_ASSIGN
Chile.digester.S_mg_in = ($cse1 * Chile.maize.Mg_in + $cse2 * Chile.tomatosouce.Mg_in + $cse3 * Chile.slurry.Mg_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3189(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3189};
  (data->localData[0]->realVars[453] /* Chile.digester.S_mg_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[778] /* Chile.maize.Mg_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1142] /* Chile.tomatosouce.Mg_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[964] /* Chile.slurry.Mg_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3190
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_mg = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_mg_in - Chile.digester.S_mg) + (-0.01666666666666667) * (Chile.digester.rp2 + Chile.digester.rp4 - Chile.digester.rd4 - Chile.digester.rd2)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3190(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3190};
  (data->localData[0]->realVars[108] /* der(Chile.digester.S_mg) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[453] /* Chile.digester.S_mg_in variable */) - (data->localData[0]->realVars[35] /* Chile.digester.S_mg STATE(1) */))) + (-0.01666666666666667) * ((data->localData[0]->realVars[618] /* Chile.digester.rp2 variable */) + (data->localData[0]->realVars[620] /* Chile.digester.rp4 variable */) - (data->localData[0]->realVars[615] /* Chile.digester.rd4 variable */) - (data->localData[0]->realVars[613] /* Chile.digester.rd2 variable */));
  TRACE_POP
}
/*
equation index: 3191
type: SIMPLE_ASSIGN
Chile.comp_maize.y[9] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 9, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3191(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3191};
  (data->localData[0]->realVars[198] /* Chile.comp_maize.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 9), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3192
type: SIMPLE_ASSIGN
Chile.maize.ac_in = if Chile.maize.steady == true then Chile.maize.ac else Chile.comp_maize.y[9]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3192(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3192};
  (data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[583] /* Chile.maize.ac PARAM */):(data->localData[0]->realVars[198] /* Chile.comp_maize.y[9] variable */));
  TRACE_POP
}
/*
equation index: 3193
type: SIMPLE_ASSIGN
Chile.maize.S_acm = 1.737800828749376e-05 * Chile.maize.ac_in / (64.05333333333333 * (Chile.maize.S_h + 1.737800828749376e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3193(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3193};
  (data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) = (1.737800828749376e-05) * (DIVISION_SIM((data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */),(64.05333333333333) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + 1.737800828749376e-05),"64.05333333333333 * (Chile.maize.S_h + 1.737800828749376e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3194
type: SIMPLE_ASSIGN
Chile.digester.S_ac_in = ($cse1 * Chile.maize.ac_in + $cse2 * Chile.tomatosouce.ac_in + $cse3 * Chile.slurry.ac_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3194(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3194};
  (data->localData[0]->realVars[430] /* Chile.digester.S_ac_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1172] /* Chile.tomatosouce.ac_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[994] /* Chile.slurry.ac_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3195
type: SIMPLE_ASSIGN
Chile.comp_maize.y[10] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 10, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3195(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3195};
  (data->localData[0]->realVars[199] /* Chile.comp_maize.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 10), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3196
type: SIMPLE_ASSIGN
Chile.maize.pro_in = if Chile.maize.steady == true then Chile.maize.pro else Chile.comp_maize.y[10]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3196(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3196};
  (data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[687] /* Chile.maize.pro PARAM */):(data->localData[0]->realVars[199] /* Chile.comp_maize.y[10] variable */));
  TRACE_POP
}
/*
equation index: 3197
type: SIMPLE_ASSIGN
Chile.maize.S_prom = 1.318256738556407e-05 * Chile.maize.pro_in / (112.1210810810811 * (Chile.maize.S_h + 1.318256738556407e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3197(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3197};
  (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) = (1.318256738556407e-05) * (DIVISION_SIM((data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */),(112.1210810810811) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + 1.318256738556407e-05),"112.1210810810811 * (Chile.maize.S_h + 1.318256738556407e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3198
type: SIMPLE_ASSIGN
Chile.digester.S_pro_in = ($cse1 * Chile.maize.pro_in + $cse2 * Chile.tomatosouce.pro_in + $cse3 * Chile.slurry.pro_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3198(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3198};
  (data->localData[0]->realVars[458] /* Chile.digester.S_pro_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1217] /* Chile.tomatosouce.pro_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1039] /* Chile.slurry.pro_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3199
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_pro = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_pro_in - Chile.digester.S_pro) + (1.0 - Chile.digester.Y_su) * Chile.digester.f_pro_su * Chile.digester.r5 / 86400.0 + (1.0 - Chile.digester.Y_aa) * Chile.digester.f_pro_aa * Chile.digester.r6 / 86400.0 + 6.25e-06 * (1.0 - Chile.digester.Y_c4) * Chile.digester.r8 - Chile.digester.r10 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3199(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3199};
  (data->localData[0]->realVars[109] /* der(Chile.digester.S_pro) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[458] /* Chile.digester.S_pro_in variable */) - (data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * (((data->localData[0]->realVars[524] /* Chile.digester.f_pro_su variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))),86400.0,"86400.0",equationIndexes) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * (((data->simulationInfo->realParameter[323] /* Chile.digester.f_pro_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))),86400.0,"86400.0",equationIndexes) + (6.25e-06) * ((1.0 - (data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) - (DIVISION_SIM((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3200
type: SIMPLE_ASSIGN
Chile.comp_maize.y[11] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 11, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3200(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3200};
  (data->localData[0]->realVars[200] /* Chile.comp_maize.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 11), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3201
type: SIMPLE_ASSIGN
Chile.maize.bu_in = if Chile.maize.steady == true then Chile.maize.bu else Chile.comp_maize.y[11]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3201(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3201};
  (data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[590] /* Chile.maize.bu PARAM */):(data->localData[0]->realVars[200] /* Chile.comp_maize.y[11] variable */));
  TRACE_POP
}
/*
equation index: 3202
type: SIMPLE_ASSIGN
Chile.maize.S_bum = 1.513561248436207e-05 * Chile.maize.bu_in / (160.1818181818182 * (Chile.maize.S_h + 1.513561248436207e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3202(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3202};
  (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) = (1.513561248436207e-05) * (DIVISION_SIM((data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */),(160.1818181818182) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + 1.513561248436207e-05),"160.1818181818182 * (Chile.maize.S_h + 1.513561248436207e-05)",equationIndexes));
  TRACE_POP
}
/*
equation index: 3203
type: SIMPLE_ASSIGN
Chile.digester.S_bu_in = ($cse1 * Chile.maize.bu_in + $cse2 * Chile.tomatosouce.bu_in + $cse3 * Chile.slurry.bu_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3203(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3203};
  (data->localData[0]->realVars[433] /* Chile.digester.S_bu_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1173] /* Chile.tomatosouce.bu_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[995] /* Chile.slurry.bu_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3204
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_bu = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_bu_in - Chile.digester.S_bu) + ((1.0 - Chile.digester.Y_su) * Chile.digester.f_bu_su * Chile.digester.r5 + (1.0 - Chile.digester.Y_aa) * Chile.digester.f_bu_aa * Chile.digester.r6 - Chile.digester.r9) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3204(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3204};
  (data->localData[0]->realVars[93] /* der(Chile.digester.S_bu) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[433] /* Chile.digester.S_bu_in variable */) - (data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * (((data->localData[0]->realVars[522] /* Chile.digester.f_bu_su variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))) + (1.0 - (data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * (((data->simulationInfo->realParameter[317] /* Chile.digester.f_bu_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))) - (data->localData[0]->realVars[606] /* Chile.digester.r9 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3205
type: SIMPLE_ASSIGN
Chile.comp_maize.y[12] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 12, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3205(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3205};
  (data->localData[0]->realVars[201] /* Chile.comp_maize.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 12), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3206
type: SIMPLE_ASSIGN
Chile.maize.va_in = if Chile.maize.steady == true then Chile.maize.va else Chile.comp_maize.y[12]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3206(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3206};
  (data->localData[0]->realVars[865] /* Chile.maize.va_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[697] /* Chile.maize.va PARAM */):(data->localData[0]->realVars[201] /* Chile.comp_maize.y[12] variable */));
  TRACE_POP
}
/*
equation index: 3207
type: SIMPLE_ASSIGN
Chile.maize.TVFA = 60000.0 * (0.0156119900083264 * Chile.maize.ac_in + 0.008918929342795433 * Chile.maize.pro_in + 0.006242905788876278 * Chile.maize.bu_in + 0.004801572656267654 * Chile.maize.va_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3207(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3207};
  (data->localData[0]->realVars[805] /* Chile.maize.TVFA variable */) = (60000.0) * ((0.0156119900083264) * ((data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */)) + (0.008918929342795433) * ((data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */)) + (0.006242905788876278) * ((data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */)) + (0.004801572656267654) * ((data->localData[0]->realVars[865] /* Chile.maize.va_in variable */)));
  TRACE_POP
}
/*
equation index: 3208
type: SIMPLE_ASSIGN
Chile.maize.S_vam = 1.380384264602884e-05 * Chile.maize.va_in / (208.2650980392157 * (Chile.maize.S_h + 1.380384264602884e-05))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3208(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3208};
  (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */) = (1.380384264602884e-05) * (DIVISION_SIM((data->localData[0]->realVars[865] /* Chile.maize.va_in variable */),(208.2650980392157) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + 1.380384264602884e-05),"208.2650980392157 * (Chile.maize.S_h + 1.380384264602884e-05)",equationIndexes));
  TRACE_POP
}
void ADM1_P_Chile_OL_MPC_eqFunction_3209(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_3210(DATA*, threadData_t*);
void ADM1_P_Chile_OL_MPC_eqFunction_3211(DATA*, threadData_t*);
/*
equation index: 3215
indexNonlinear: 12
type: NONLINEAR

vars: {Chile.maize.outlet.S_ic}
eqns: {3209, 3210, 3211}
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3215(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3215};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 3215 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[12].nlsxOld[0] = (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */);
  retValue = solve_nonlinear_system(data, threadData, 12);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,3215};
    throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, indexes, "Solving non-linear system 3215 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */) = data->simulationInfo->nonlinearSystemData[12].nlsx[0];
  TRACE_POP
}
/*
equation index: 3216
type: SIMPLE_ASSIGN
Chile.digester.S_ic_in = ($cse1 * Chile.maize.outlet.S_ic + $cse2 * Chile.tomatosouce.outlet.S_ic + $cse3 * Chile.slurry.outlet.S_ic) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3216(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3216};
  (data->localData[0]->realVars[450] /* Chile.digester.S_ic_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3217
type: SIMPLE_ASSIGN
Chile.maize.S_co2 = Chile.maize.outlet.S_ic + (-Chile.maize.S_hco3) - Chile.maize.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3217(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3217};
  (data->localData[0]->realVars[786] /* Chile.maize.S_co2 variable */) = (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */) + (-(data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */)) - (data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */);
  TRACE_POP
}
/*
equation index: 3218
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_cat = if Chile.maize.liquid == false then Chile.maize.cat else (-Chile.maize.S_nh4) - Chile.maize.S_h - 2.0 * Chile.maize.Ca_in - 2.0 * Chile.maize.Mg_in + Chile.maize.an + Chile.maize.S_hco3 + Chile.maize.S_oh + Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam + 2.0 * Chile.maize.S_hpo4 + Chile.maize.S_h2po4 + 3.0 * Chile.maize.S_po4 + 2.0 * Chile.maize.S_co3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3218(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3218};
  (data->localData[0]->realVars[828] /* Chile.maize.outlet.S_cat variable */) = (((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?(data->simulationInfo->realParameter[592] /* Chile.maize.cat PARAM */):(-(data->localData[0]->realVars[794] /* Chile.maize.S_nh4 variable */)) - (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - ((2.0) * ((data->localData[0]->realVars[731] /* Chile.maize.Ca_in variable */))) - ((2.0) * ((data->localData[0]->realVars[778] /* Chile.maize.Mg_in variable */))) + (data->simulationInfo->realParameter[585] /* Chile.maize.an PARAM */) + (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */) + (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) + (data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */) + (2.0) * ((data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */)) + (data->localData[0]->realVars[789] /* Chile.maize.S_h2po4 variable */) + (3.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */)) + (2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)));
  TRACE_POP
}
/*
equation index: 3219
type: SIMPLE_ASSIGN
Chile.digester.S_cat_in = ($cse1 * Chile.maize.outlet.S_cat + $cse2 * Chile.tomatosouce.outlet.S_cat + $cse3 * Chile.slurry.outlet.S_cat) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3219(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3219};
  (data->localData[0]->realVars[436] /* Chile.digester.S_cat_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[828] /* Chile.maize.outlet.S_cat variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1192] /* Chile.tomatosouce.outlet.S_cat variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1014] /* Chile.slurry.outlet.S_cat variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3220
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_cat = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_cat_in - Chile.digester.S_cat)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3220(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3220};
  (data->localData[0]->realVars[95] /* der(Chile.digester.S_cat) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[436] /* Chile.digester.S_cat_in variable */) - (data->localData[0]->realVars[22] /* Chile.digester.S_cat STATE(1) */)));
  TRACE_POP
}
/*
equation index: 3221
type: SIMPLE_ASSIGN
Chile.maize.Alk = 50000.0 * (Chile.maize.S_hco3 + 2.0 * Chile.maize.S_co3 + Chile.maize.S_oh + Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam + Chile.maize.S_nh3 + Chile.maize.S_hpo4 + 2.0 * Chile.maize.S_po4 - Chile.maize.S_h3po4 - Chile.maize.S_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3221(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3221};
  (data->localData[0]->realVars[688] /* Chile.maize.Alk variable */) = (50000.0) * ((data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */) + (2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)) + (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) + (data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */) + (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) + (2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */)) - (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */));
  TRACE_POP
}
/*
equation index: 3222
type: SIMPLE_ASSIGN
Chile.maize.FOS_TAC = Chile.maize.TVFA / Chile.maize.Alk
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3222(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3222};
  (data->localData[0]->realVars[734] /* Chile.maize.FOS_TAC variable */) = DIVISION_SIM((data->localData[0]->realVars[805] /* Chile.maize.TVFA variable */),(data->localData[0]->realVars[688] /* Chile.maize.Alk variable */),"Chile.maize.Alk",equationIndexes);
  TRACE_POP
}
/*
equation index: 3223
type: SIMPLE_ASSIGN
Chile.digester.S_va_in = ($cse1 * Chile.maize.va_in + $cse2 * Chile.tomatosouce.va_in + $cse3 * Chile.slurry.va_in) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3223(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3223};
  (data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[865] /* Chile.maize.va_in variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1229] /* Chile.tomatosouce.va_in variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1051] /* Chile.slurry.va_in variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3224
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_fa = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_va_in - Chile.digester.S_fa) + (Chile.digester.f_fa_li * Chile.digester.r4 - Chile.digester.r7) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3224(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3224};
  (data->localData[0]->realVars[97] /* der(Chile.digester.S_fa) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) - (data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[319] /* Chile.digester.f_fa_li PARAM */)) * ((data->localData[0]->realVars[601] /* Chile.digester.r4 variable */)) - (data->localData[0]->realVars[604] /* Chile.digester.r7 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3225
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_va = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_va_in - Chile.digester.S_va) + ((1.0 - Chile.digester.Y_aa) * Chile.digester.f_va_aa * Chile.digester.r6 - Chile.digester.r8) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3225(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3225};
  (data->localData[0]->realVars[111] /* der(Chile.digester.S_va) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) - (data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * (((data->simulationInfo->realParameter[325] /* Chile.digester.f_va_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))) - (data->localData[0]->realVars[605] /* Chile.digester.r8 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3226
type: SIMPLE_ASSIGN
Chile.comp_maize.y[13] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 13, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3226(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3226};
  (data->localData[0]->realVars[202] /* Chile.comp_maize.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 13), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3227
type: SIMPLE_ASSIGN
Chile.maize.Ssu_in = if Chile.maize.steady == true then Chile.maize.su else Chile.comp_maize.y[13]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3227(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3227};
  (data->localData[0]->realVars[801] /* Chile.maize.Ssu_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[691] /* Chile.maize.su PARAM */):(data->localData[0]->realVars[202] /* Chile.comp_maize.y[13] variable */));
  TRACE_POP
}
/*
equation index: 3228
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_su = 0.0107 * Chile.maize.Ssu_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3228(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3228};
  (data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */) = (0.0107) * (((data->localData[0]->realVars[801] /* Chile.maize.Ssu_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3229
type: SIMPLE_ASSIGN
Chile.maize.CH_sol = 0.84375 * (Chile.maize.outlet.S_su + Chile.maize.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3229(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3229};
  (data->localData[0]->realVars[699] /* Chile.maize.CH_sol variable */) = (0.84375) * ((data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */));
  TRACE_POP
}
/*
equation index: 3230
type: SIMPLE_ASSIGN
Chile.digester.S_su_in = ($cse1 * Chile.maize.outlet.S_su + $cse2 * Chile.tomatosouce.outlet.S_su + $cse3 * Chile.slurry.outlet.S_su) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3230(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3230};
  (data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1197] /* Chile.tomatosouce.outlet.S_su variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1019] /* Chile.slurry.outlet.S_su variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3231
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_su = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_su_in - Chile.digester.S_su) + (Chile.digester.r2[1] + Chile.digester.r2[2] + Chile.digester.r2[3] + (1.0 - Chile.digester.f_fa_li) * Chile.digester.r4 - Chile.digester.r5) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3231(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3231};
  (data->localData[0]->realVars[110] /* der(Chile.digester.S_su) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */) - (data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */))) + DIVISION_SIM((data->localData[0]->realVars[596] /* Chile.digester.r2[1] variable */) + (data->localData[0]->realVars[597] /* Chile.digester.r2[2] variable */) + (data->localData[0]->realVars[598] /* Chile.digester.r2[3] variable */) + (1.0 - (data->simulationInfo->realParameter[319] /* Chile.digester.f_fa_li PARAM */)) * ((data->localData[0]->realVars[601] /* Chile.digester.r4 variable */)) - (data->localData[0]->realVars[602] /* Chile.digester.r5 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3232
type: SIMPLE_ASSIGN
Chile.comp_maize.y[14] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 14, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3232(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3232};
  (data->localData[0]->realVars[203] /* Chile.comp_maize.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 14), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3233
type: SIMPLE_ASSIGN
Chile.maize.Saa_in = if Chile.maize.steady == true then Chile.maize.aa else Chile.comp_maize.y[14]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3233(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3233};
  (data->localData[0]->realVars[799] /* Chile.maize.Saa_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[582] /* Chile.maize.aa PARAM */):(data->localData[0]->realVars[203] /* Chile.comp_maize.y[14] variable */));
  TRACE_POP
}
/*
equation index: 3234
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_aa = 0.0153 * Chile.maize.Saa_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3234(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3234};
  (data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) = (0.0153) * (((data->localData[0]->realVars[799] /* Chile.maize.Saa_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3235
type: SIMPLE_ASSIGN
Chile.maize.PR_sol_BCA = (Chile.maize.outlet.S_aa + Chile.maize.si) / Chile.maize.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3235(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3235};
  (data->localData[0]->realVars[780] /* Chile.maize.PR_sol_BCA variable */) = DIVISION_SIM((data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */),(data->simulationInfo->realParameter[539] /* Chile.maize.COD_VS_PR_BCA PARAM */),"Chile.maize.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3236
type: SIMPLE_ASSIGN
Chile.maize.PR_sol_TKN = 0.6534431137724552 * (Chile.maize.outlet.S_aa + Chile.maize.si) / Chile.maize.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3236(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3236};
  (data->localData[0]->realVars[781] /* Chile.maize.PR_sol_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM((data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */),(data->simulationInfo->realParameter[567] /* Chile.maize.N_PR PARAM */),"Chile.maize.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3237
type: SIMPLE_ASSIGN
Chile.digester.S_aa_in = ($cse1 * Chile.maize.outlet.S_aa + $cse2 * Chile.tomatosouce.outlet.S_aa + $cse3 * Chile.slurry.outlet.S_aa) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3237(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3237};
  (data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1191] /* Chile.tomatosouce.outlet.S_aa variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1013] /* Chile.slurry.outlet.S_aa variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3238
type: SIMPLE_ASSIGN
Chile.digester.COD_s_in = Chile.digester.S_aa_in + Chile.digester.S_va_in + Chile.digester.S_su_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3238(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3238};
  (data->localData[0]->realVars[331] /* Chile.digester.COD_s_in variable */) = (data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) + (data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) + (data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */);
  TRACE_POP
}
/*
equation index: 3239
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_aa = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_aa_in - Chile.digester.S_aa) + (Chile.digester.r3[1] + Chile.digester.r3[2] - Chile.digester.r6) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3239(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3239};
  (data->localData[0]->realVars[90] /* der(Chile.digester.S_aa) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) - (data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */))) + DIVISION_SIM((data->localData[0]->realVars[599] /* Chile.digester.r3[1] variable */) + (data->localData[0]->realVars[600] /* Chile.digester.r3[2] variable */) - (data->localData[0]->realVars[603] /* Chile.digester.r6 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3240
type: SIMPLE_ASSIGN
Chile.comp_maize.y[15] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 15, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3240(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3240};
  (data->localData[0]->realVars[204] /* Chile.comp_maize.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 15), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3241
type: SIMPLE_ASSIGN
Chile.maize.Sfa_in = if Chile.maize.steady == true then Chile.maize.fa else Chile.comp_maize.y[15]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3241(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3241};
  (data->localData[0]->realVars[800] /* Chile.maize.Sfa_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[615] /* Chile.maize.fa PARAM */):(data->localData[0]->realVars[204] /* Chile.comp_maize.y[15] variable */));
  TRACE_POP
}
/*
equation index: 3242
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_fa = 0.0287 * Chile.maize.Sfa_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3242(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3242};
  (data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) = (0.0287) * (((data->localData[0]->realVars[800] /* Chile.maize.Sfa_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3243
type: SIMPLE_ASSIGN
Chile.maize.COD_sol = Chile.maize.outlet.S_aa + Chile.maize.ac_in + Chile.maize.bu_in + Chile.maize.ch4 + Chile.maize.outlet.S_fa + Chile.maize.h2 + Chile.maize.si + Chile.maize.pro_in + Chile.maize.outlet.S_su + Chile.maize.va_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3243(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3243};
  (data->localData[0]->realVars[728] /* Chile.maize.COD_sol variable */) = (data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */) + (data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */) + (data->simulationInfo->realParameter[594] /* Chile.maize.ch4 PARAM */) + (data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) + (data->simulationInfo->realParameter[616] /* Chile.maize.h2 PARAM */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */) + (data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */) + (data->localData[0]->realVars[865] /* Chile.maize.va_in variable */);
  TRACE_POP
}
/*
equation index: 3244
type: SIMPLE_ASSIGN
Chile.maize.LI_sol = 0.3532661514862131 * (Chile.maize.outlet.S_fa + Chile.maize.si)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3244(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3244};
  (data->localData[0]->realVars[748] /* Chile.maize.LI_sol variable */) = (0.3532661514862131) * ((data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */));
  TRACE_POP
}
/*
equation index: 3245
type: SIMPLE_ASSIGN
Chile.digester.inlet.S_fa = ($cse1 * Chile.maize.outlet.S_fa + $cse2 * Chile.tomatosouce.outlet.S_fa + $cse3 * Chile.slurry.outlet.S_fa) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3245(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3245};
  (data->localData[0]->realVars[556] /* Chile.digester.inlet.S_fa variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1193] /* Chile.tomatosouce.outlet.S_fa variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1015] /* Chile.slurry.outlet.S_fa variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3246
type: SIMPLE_ASSIGN
Chile.comp_maize.y[16] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 16, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3246(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3246};
  (data->localData[0]->realVars[205] /* Chile.comp_maize.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 16), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3247
type: SIMPLE_ASSIGN
Chile.maize.tBMP_VS_in = if Chile.maize.steady == true then Chile.maize.tbmp_vs else Chile.comp_maize.y[16]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3247(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3247};
  (data->localData[0]->realVars[854] /* Chile.maize.tBMP_VS_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[694] /* Chile.maize.tbmp_vs PARAM */):(data->localData[0]->realVars[205] /* Chile.comp_maize.y[16] variable */));
  TRACE_POP
}
/*
equation index: 3248
type: SIMPLE_ASSIGN
Chile.comp_maize.y[17] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 17, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3248(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3248};
  (data->localData[0]->realVars[206] /* Chile.comp_maize.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 17), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3249
type: SIMPLE_ASSIGN
Chile.maize.CP_in = if Chile.maize.steady == true then Chile.maize.protein else Chile.comp_maize.y[17]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3249(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3249};
  (data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[688] /* Chile.maize.protein PARAM */):(data->localData[0]->realVars[206] /* Chile.comp_maize.y[17] variable */));
  TRACE_POP
}
/*
equation index: 3250
type: SIMPLE_ASSIGN
Chile.comp_maize.y[18] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 18, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3250(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3250};
  (data->localData[0]->realVars[207] /* Chile.comp_maize.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 18), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3251
type: SIMPLE_ASSIGN
Chile.maize.EE_in = if Chile.maize.steady == true then Chile.maize.lipid else Chile.comp_maize.y[18]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3251(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3251};
  (data->localData[0]->realVars[733] /* Chile.maize.EE_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[652] /* Chile.maize.lipid PARAM */):(data->localData[0]->realVars[207] /* Chile.comp_maize.y[18] variable */));
  TRACE_POP
}
/*
equation index: 3252
type: SIMPLE_ASSIGN
Chile.comp_maize.y[19] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 19, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3252(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3252};
  (data->localData[0]->realVars[208] /* Chile.comp_maize.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 19), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3253
type: SIMPLE_ASSIGN
Chile.maize.Cellulose_in = if Chile.maize.steady == true then Chile.maize.cellulose else Chile.comp_maize.y[19]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3253(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3253};
  (data->localData[0]->realVars[732] /* Chile.maize.Cellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[593] /* Chile.maize.cellulose PARAM */):(data->localData[0]->realVars[208] /* Chile.comp_maize.y[19] variable */));
  TRACE_POP
}
/*
equation index: 3254
type: SIMPLE_ASSIGN
Chile.comp_maize.y[20] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 20, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3254(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3254};
  (data->localData[0]->realVars[209] /* Chile.comp_maize.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 20), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3255
type: SIMPLE_ASSIGN
Chile.maize.Hemicellulose_in = if Chile.maize.steady == true then Chile.maize.hemicellulose else Chile.comp_maize.y[20]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3255(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3255};
  (data->localData[0]->realVars[736] /* Chile.maize.Hemicellulose_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[617] /* Chile.maize.hemicellulose PARAM */):(data->localData[0]->realVars[209] /* Chile.comp_maize.y[20] variable */));
  TRACE_POP
}
/*
equation index: 3256
type: SIMPLE_ASSIGN
Chile.comp_maize.y[21] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 21, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3256(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3256};
  (data->localData[0]->realVars[210] /* Chile.comp_maize.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 21), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3257
type: SIMPLE_ASSIGN
Chile.maize.Lignin_in = if Chile.maize.steady == true then Chile.maize.adl else Chile.comp_maize.y[21]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3257(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3257};
  (data->localData[0]->realVars[750] /* Chile.maize.Lignin_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[584] /* Chile.maize.adl PARAM */):(data->localData[0]->realVars[210] /* Chile.comp_maize.y[21] variable */));
  TRACE_POP
}
/*
equation index: 3258
type: SIMPLE_ASSIGN
Chile.maize.NDF_in = Chile.maize.Cellulose_in + Chile.maize.Hemicellulose_in + Chile.maize.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3258(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3258};
  (data->localData[0]->realVars[779] /* Chile.maize.NDF_in variable */) = (data->localData[0]->realVars[732] /* Chile.maize.Cellulose_in variable */) + (data->localData[0]->realVars[736] /* Chile.maize.Hemicellulose_in variable */) + (data->localData[0]->realVars[750] /* Chile.maize.Lignin_in variable */);
  TRACE_POP
}
/*
equation index: 3259
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_lig = 0.01361702127659574 * Chile.maize.TS_in * Chile.maize.Lignin_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3259(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3259};
  (data->localData[0]->realVars[845] /* Chile.maize.outlet.X_lig variable */) = (0.01361702127659574) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((data->localData[0]->realVars[750] /* Chile.maize.Lignin_in variable */)));
  TRACE_POP
}
/*
equation index: 3260
type: SIMPLE_ASSIGN
Chile.digester.X_lig_in = ($cse1 * Chile.maize.outlet.X_lig + $cse2 * Chile.tomatosouce.outlet.X_lig + $cse3 * Chile.slurry.outlet.X_lig) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3260(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3260};
  (data->localData[0]->realVars[492] /* Chile.digester.X_lig_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[845] /* Chile.maize.outlet.X_lig variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1209] /* Chile.tomatosouce.outlet.X_lig variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1031] /* Chile.slurry.outlet.X_lig variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3261
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_lig = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_lig_in - Chile.digester.X_lig) + Chile.digester.f_xc[6] * Chile.digester.r1 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3261(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3261};
  (data->localData[0]->realVars[128] /* der(Chile.digester.X_lig) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[492] /* Chile.digester.X_lig_in variable */) - (data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3262
type: SIMPLE_ASSIGN
Chile.comp_maize.y[22] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 22, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3262(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3262};
  (data->localData[0]->realVars[211] /* Chile.comp_maize.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 22), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3263
type: SIMPLE_ASSIGN
Chile.maize.Starch_in = if Chile.maize.steady == true then Chile.maize.starch else Chile.comp_maize.y[22]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3263(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3263};
  (data->localData[0]->realVars[802] /* Chile.maize.Starch_in variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[690] /* Chile.maize.starch PARAM */):(data->localData[0]->realVars[211] /* Chile.comp_maize.y[22] variable */));
  TRACE_POP
}
/*
equation index: 3264
type: SIMPLE_ASSIGN
Chile.maize.CH_in = Chile.maize.Ssu_in + Chile.maize.Starch_in + Chile.maize.NDF_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3264(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3264};
  (data->localData[0]->realVars[698] /* Chile.maize.CH_in variable */) = (data->localData[0]->realVars[801] /* Chile.maize.Ssu_in variable */) + (data->localData[0]->realVars[802] /* Chile.maize.Starch_in variable */) + (data->localData[0]->realVars[779] /* Chile.maize.NDF_in variable */);
  TRACE_POP
}
/*
equation index: 3265
type: SIMPLE_ASSIGN
Chile.maize.tBMPth_vs = 0.01 * (496.0 * Chile.maize.CP_in + 1014.0 * Chile.maize.EE_in + 415.0 * Chile.maize.CH_in) * Chile.maize.TS_in / Chile.maize.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3265(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3265};
  (data->localData[0]->realVars[862] /* Chile.maize.tBMPth_vs variable */) = (0.01) * (((496.0) * ((data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */)) + (1014.0) * ((data->localData[0]->realVars[733] /* Chile.maize.EE_in variable */)) + (415.0) * ((data->localData[0]->realVars[698] /* Chile.maize.CH_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */),(data->localData[0]->realVars[807] /* Chile.maize.VS_in variable */),"Chile.maize.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3266
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_ch[1] = 0.01185185185185185 * Chile.maize.Starch_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3266(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3266};
  (data->localData[0]->realVars[837] /* Chile.maize.outlet.X_ch[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[802] /* Chile.maize.Starch_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)));
  TRACE_POP
}
/*
equation index: 3267
type: SIMPLE_ASSIGN
Chile.digester.X_ch_in[1] = ($cse1 * Chile.maize.outlet.X_ch[1] + $cse2 * Chile.tomatosouce.outlet.X_ch[1] + $cse3 * Chile.slurry.outlet.X_ch[1]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3267(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3267};
  (data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[837] /* Chile.maize.outlet.X_ch[1] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1201] /* Chile.tomatosouce.outlet.X_ch[1] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1023] /* Chile.slurry.outlet.X_ch[1] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3268
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_ch[1] = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_ch_in[1] - Chile.digester.X_ch[1]) - Chile.digester.r2[1] / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3268(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3268};
  (data->localData[0]->realVars[121] /* der(Chile.digester.X_ch[1]) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) - (data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */))) - (DIVISION_SIM((data->localData[0]->realVars[596] /* Chile.digester.r2[1] variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3269
type: SIMPLE_ASSIGN
Chile.comp_maize.y[23] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 23, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3269(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3269};
  (data->localData[0]->realVars[212] /* Chile.comp_maize.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 23), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3270
type: SIMPLE_ASSIGN
Chile.maize.BD_pr = if Chile.maize.steady == true then Chile.maize.bd_pr else Chile.comp_maize.y[23]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3270(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3270};
  (data->localData[0]->realVars[696] /* Chile.maize.BD_pr variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[589] /* Chile.maize.bd_pr PARAM */):(data->localData[0]->realVars[212] /* Chile.comp_maize.y[23] variable */));
  TRACE_POP
}
/*
equation index: 3271
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_i[2] = 0.01530355097365406 * Chile.maize.TS_in * (1.0 + (-0.01) * Chile.maize.BD_pr) * Chile.maize.CP_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3271(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3271};
  (data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */) = (0.01530355097365406) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[696] /* Chile.maize.BD_pr variable */))) * ((data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */))));
  TRACE_POP
}
/*
equation index: 3272
type: SIMPLE_ASSIGN
Chile.digester.X_i_in[2] = ($cse1 * Chile.maize.outlet.X_i[2] + $cse2 * Chile.tomatosouce.outlet.X_i[2] + $cse3 * Chile.slurry.outlet.X_i[2]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3272(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3272};
  (data->localData[0]->realVars[488] /* Chile.digester.X_i_in[2] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1205] /* Chile.tomatosouce.outlet.X_i[2] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1027] /* Chile.slurry.outlet.X_i[2] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3273
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_pr[2] = 0.0001530355097365406 * Chile.maize.f_pr_s * Chile.maize.CP_in * Chile.maize.TS_in * Chile.maize.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3273(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3273};
  (data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[609] /* Chile.maize.f_pr_s PARAM */)) * (((data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */)) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((data->localData[0]->realVars[696] /* Chile.maize.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 3274
type: SIMPLE_ASSIGN
Chile.digester.X_pr_in[2] = ($cse1 * Chile.maize.outlet.X_pr[2] + $cse2 * Chile.tomatosouce.outlet.X_pr[2] + $cse3 * Chile.slurry.outlet.X_pr[2]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3274(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3274};
  (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1213] /* Chile.tomatosouce.outlet.X_pr[2] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1035] /* Chile.slurry.outlet.X_pr[2] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3275
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_pr[2] = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_pr_in[2] - Chile.digester.X_pr[2]) + (Chile.digester.f_xc[2] * Chile.digester.r1 + Chile.digester.f_pr_xb * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) - Chile.digester.r3[2]) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3275(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3275};
  (data->localData[0]->realVars[132] /* der(Chile.digester.X_pr[2]) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */) - (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)) + ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)) - (data->localData[0]->realVars[600] /* Chile.digester.r3[2] variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3276
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_pr[1] = 0.0001530355097365406 * Chile.maize.f_pr_r * Chile.maize.CP_in * Chile.maize.TS_in * Chile.maize.BD_pr
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3276(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3276};
  (data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */) = (0.0001530355097365406) * (((data->simulationInfo->realParameter[608] /* Chile.maize.f_pr_r PARAM */)) * (((data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */)) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((data->localData[0]->realVars[696] /* Chile.maize.BD_pr variable */)))));
  TRACE_POP
}
/*
equation index: 3277
type: SIMPLE_ASSIGN
Chile.digester.X_pr_in[1] = ($cse1 * Chile.maize.outlet.X_pr[1] + $cse2 * Chile.tomatosouce.outlet.X_pr[1] + $cse3 * Chile.slurry.outlet.X_pr[1]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3277(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3277};
  (data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1212] /* Chile.tomatosouce.outlet.X_pr[1] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1034] /* Chile.slurry.outlet.X_pr[1] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3278
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_pr[1] = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_pr_in[1] - Chile.digester.X_pr[1]) - Chile.digester.r3[1] / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3278(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3278};
  (data->localData[0]->realVars[131] /* der(Chile.digester.X_pr[1]) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) - (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */))) - (DIVISION_SIM((data->localData[0]->realVars[599] /* Chile.digester.r3[1] variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3279
type: SIMPLE_ASSIGN
Chile.comp_maize.y[24] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 24, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3279(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3279};
  (data->localData[0]->realVars[213] /* Chile.comp_maize.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 24), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3280
type: SIMPLE_ASSIGN
Chile.maize.BD_li = if Chile.maize.steady == true then Chile.maize.bd_li else Chile.comp_maize.y[24]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3280(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3280};
  (data->localData[0]->realVars[695] /* Chile.maize.BD_li variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[588] /* Chile.maize.bd_li PARAM */):(data->localData[0]->realVars[213] /* Chile.comp_maize.y[24] variable */));
  TRACE_POP
}
/*
equation index: 3281
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_i[3] = 0.02830726906025207 * Chile.maize.TS_in * (1.0 + (-0.01) * Chile.maize.BD_li) * Chile.maize.EE_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3281(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3281};
  (data->localData[0]->realVars[842] /* Chile.maize.outlet.X_i[3] variable */) = (0.02830726906025207) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[695] /* Chile.maize.BD_li variable */))) * ((data->localData[0]->realVars[733] /* Chile.maize.EE_in variable */))));
  TRACE_POP
}
/*
equation index: 3282
type: SIMPLE_ASSIGN
Chile.digester.X_i_in[3] = ($cse1 * Chile.maize.outlet.X_i[3] + $cse2 * Chile.tomatosouce.outlet.X_i[3] + $cse3 * Chile.slurry.outlet.X_i[3]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3282(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3282};
  (data->localData[0]->realVars[489] /* Chile.digester.X_i_in[3] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[842] /* Chile.maize.outlet.X_i[3] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1206] /* Chile.tomatosouce.outlet.X_i[3] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1028] /* Chile.slurry.outlet.X_i[3] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3283
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_li = 0.0002830726906025207 * Chile.maize.EE_in * Chile.maize.TS_in * Chile.maize.BD_li
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3283(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3283};
  (data->localData[0]->realVars[844] /* Chile.maize.outlet.X_li variable */) = (0.0002830726906025207) * (((data->localData[0]->realVars[733] /* Chile.maize.EE_in variable */)) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((data->localData[0]->realVars[695] /* Chile.maize.BD_li variable */))));
  TRACE_POP
}
/*
equation index: 3284
type: SIMPLE_ASSIGN
Chile.digester.X_li_in = ($cse1 * Chile.maize.outlet.X_li + $cse2 * Chile.tomatosouce.outlet.X_li + $cse3 * Chile.slurry.outlet.X_li) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3284(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3284};
  (data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[844] /* Chile.maize.outlet.X_li variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1208] /* Chile.tomatosouce.outlet.X_li variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1030] /* Chile.slurry.outlet.X_li variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3285
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_li = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_li_in - Chile.digester.X_li) + (Chile.digester.f_xc[3] * Chile.digester.r1 + Chile.digester.f_li_xb * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) - Chile.digester.r4) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3285(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3285};
  (data->localData[0]->realVars[127] /* der(Chile.digester.X_li) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */) - (data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)) + ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)) - (data->localData[0]->realVars[601] /* Chile.digester.r4 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3286
type: SIMPLE_ASSIGN
Chile.comp_maize.y[25] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 25, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3286(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3286};
  (data->localData[0]->realVars[214] /* Chile.comp_maize.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 25), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3287
type: SIMPLE_ASSIGN
Chile.maize.BD_cell = if Chile.maize.steady == true then Chile.maize.bd_cell else Chile.comp_maize.y[25]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3287(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3287};
  (data->localData[0]->realVars[692] /* Chile.maize.BD_cell variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[586] /* Chile.maize.bd_cell PARAM */):(data->localData[0]->realVars[214] /* Chile.comp_maize.y[25] variable */));
  TRACE_POP
}
/*
equation index: 3288
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_ch[3] = 0.0001185185185185185 * Chile.maize.BD_cell * Chile.maize.Cellulose_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3288(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3288};
  (data->localData[0]->realVars[839] /* Chile.maize.outlet.X_ch[3] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[692] /* Chile.maize.BD_cell variable */)) * (((data->localData[0]->realVars[732] /* Chile.maize.Cellulose_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3289
type: SIMPLE_ASSIGN
Chile.digester.X_ch_in[3] = ($cse1 * Chile.maize.outlet.X_ch[3] + $cse2 * Chile.tomatosouce.outlet.X_ch[3] + $cse3 * Chile.slurry.outlet.X_ch[3]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3289(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3289};
  (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[839] /* Chile.maize.outlet.X_ch[3] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1203] /* Chile.tomatosouce.outlet.X_ch[3] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1025] /* Chile.slurry.outlet.X_ch[3] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3290
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_ch[3] = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_ch_in[3] - Chile.digester.X_ch[3]) - Chile.digester.r2[3] / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3290(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3290};
  (data->localData[0]->realVars[123] /* der(Chile.digester.X_ch[3]) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */) - (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */))) - (DIVISION_SIM((data->localData[0]->realVars[598] /* Chile.digester.r2[3] variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3291
type: SIMPLE_ASSIGN
Chile.comp_maize.y[26] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_maize.tableID, 26, Chile.comp_maize.timeScaled, Chile.comp_maize.nextTimeEventScaled, pre(Chile.comp_maize.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3291(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3291};
  (data->localData[0]->realVars[215] /* Chile.comp_maize.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[0]), ((modelica_integer) 26), (data->localData[0]->realVars[189] /* Chile.comp_maize.timeScaled variable */), (data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3292
type: SIMPLE_ASSIGN
Chile.maize.BD_hemicell = if Chile.maize.steady == true then Chile.maize.bd_hemicell else Chile.comp_maize.y[26]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3292(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3292};
  (data->localData[0]->realVars[694] /* Chile.maize.BD_hemicell variable */) = (((!(data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && !1) || ((data->simulationInfo->booleanParameter[24] /* Chile.maize.steady PARAM */) && 1))?(data->simulationInfo->realParameter[587] /* Chile.maize.bd_hemicell PARAM */):(data->localData[0]->realVars[215] /* Chile.comp_maize.y[26] variable */));
  TRACE_POP
}
/*
equation index: 3293
type: SIMPLE_ASSIGN
Chile.maize.BD_ch = 100.0 * (Chile.maize.Ssu_in + Chile.maize.Starch_in + 0.01 * (Chile.maize.BD_cell * Chile.maize.Cellulose_in + Chile.maize.BD_hemicell * Chile.maize.Hemicellulose_in)) / Chile.maize.CH_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3293(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3293};
  (data->localData[0]->realVars[693] /* Chile.maize.BD_ch variable */) = DIVISION_SIM((100.0) * ((data->localData[0]->realVars[801] /* Chile.maize.Ssu_in variable */) + (data->localData[0]->realVars[802] /* Chile.maize.Starch_in variable */) + (0.01) * (((data->localData[0]->realVars[692] /* Chile.maize.BD_cell variable */)) * ((data->localData[0]->realVars[732] /* Chile.maize.Cellulose_in variable */)) + ((data->localData[0]->realVars[694] /* Chile.maize.BD_hemicell variable */)) * ((data->localData[0]->realVars[736] /* Chile.maize.Hemicellulose_in variable */)))),(data->localData[0]->realVars[698] /* Chile.maize.CH_in variable */),"Chile.maize.CH_in",equationIndexes);
  TRACE_POP
}
/*
equation index: 3294
type: SIMPLE_ASSIGN
Chile.maize.BD_vs = 0.01 * (Chile.maize.BD_ch * Chile.maize.CH_in + Chile.maize.BD_pr * Chile.maize.CP_in + Chile.maize.BD_li * Chile.maize.EE_in) * Chile.maize.TS_in / Chile.maize.VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3294(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3294};
  (data->localData[0]->realVars[697] /* Chile.maize.BD_vs variable */) = (0.01) * ((((data->localData[0]->realVars[693] /* Chile.maize.BD_ch variable */)) * ((data->localData[0]->realVars[698] /* Chile.maize.CH_in variable */)) + ((data->localData[0]->realVars[696] /* Chile.maize.BD_pr variable */)) * ((data->localData[0]->realVars[730] /* Chile.maize.CP_in variable */)) + ((data->localData[0]->realVars[695] /* Chile.maize.BD_li variable */)) * ((data->localData[0]->realVars[733] /* Chile.maize.EE_in variable */))) * (DIVISION_SIM((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */),(data->localData[0]->realVars[807] /* Chile.maize.VS_in variable */),"Chile.maize.VS_in",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3295
type: SIMPLE_ASSIGN
Chile.maize.tBMPerror = 0.01 * Chile.maize.BD_vs * Chile.maize.tBMPth_vs - Chile.maize.tBMP_VS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3295(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3295};
  (data->localData[0]->realVars[855] /* Chile.maize.tBMPerror variable */) = (0.01) * (((data->localData[0]->realVars[697] /* Chile.maize.BD_vs variable */)) * ((data->localData[0]->realVars[862] /* Chile.maize.tBMPth_vs variable */))) - (data->localData[0]->realVars[854] /* Chile.maize.tBMP_VS_in variable */);
  TRACE_POP
}
/*
equation index: 3296
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_i[1] = 0.01185185185185185 * Chile.maize.TS_in * ((1.0 + (-0.01) * Chile.maize.BD_cell) * Chile.maize.Cellulose_in + (1.0 + (-0.01) * Chile.maize.BD_hemicell) * Chile.maize.Hemicellulose_in)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3296(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3296};
  (data->localData[0]->realVars[840] /* Chile.maize.outlet.X_i[1] variable */) = (0.01185185185185185) * (((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */)) * ((1.0 + (-0.01) * ((data->localData[0]->realVars[692] /* Chile.maize.BD_cell variable */))) * ((data->localData[0]->realVars[732] /* Chile.maize.Cellulose_in variable */)) + (1.0 + (-0.01) * ((data->localData[0]->realVars[694] /* Chile.maize.BD_hemicell variable */))) * ((data->localData[0]->realVars[736] /* Chile.maize.Hemicellulose_in variable */))));
  TRACE_POP
}
/*
equation index: 3297
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_i[4] = Chile.maize.outlet.X_i[1] + Chile.maize.outlet.X_i[2] + Chile.maize.outlet.X_i[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3297(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3297};
  (data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */) = (data->localData[0]->realVars[840] /* Chile.maize.outlet.X_i[1] variable */) + (data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */) + (data->localData[0]->realVars[842] /* Chile.maize.outlet.X_i[3] variable */);
  TRACE_POP
}
/*
equation index: 3298
type: SIMPLE_ASSIGN
Chile.maize.f_xi[2] = Chile.maize.outlet.X_i[2] / Chile.maize.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3298(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3298};
  (data->localData[0]->realVars[825] /* Chile.maize.f_xi[2] variable */) = DIVISION_SIM((data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */),(data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */),"Chile.maize.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3299
type: SIMPLE_ASSIGN
Chile.maize.PR_tot_BCA = (1.166666666666667e-10 + Chile.maize.outlet.S_aa + Chile.maize.outlet.X_pr[1] + Chile.maize.outlet.X_pr[2] + 1e-10 * Chile.maize.f_xi[2] + Chile.maize.si + Chile.maize.outlet.X_i[2] + (Chile.maize.xaa + Chile.maize.xac + Chile.maize.xc4 + Chile.maize.xfa + Chile.maize.xh2 + Chile.maize.xpro + Chile.maize.xsu) * Chile.maize.f_Xbiom_pr) / Chile.maize.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3299(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3299};
  (data->localData[0]->realVars[782] /* Chile.maize.PR_tot_BCA variable */) = DIVISION_SIM(1.166666666666667e-10 + (data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[825] /* Chile.maize.f_xi[2] variable */)) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */)) * ((data->simulationInfo->realParameter[601] /* Chile.maize.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[539] /* Chile.maize.COD_VS_PR_BCA PARAM */),"Chile.maize.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3300
type: SIMPLE_ASSIGN
Chile.maize.PR_tot_TKN = 0.6534431137724552 * (2e-10 + Chile.maize.outlet.S_aa + Chile.maize.outlet.X_pr[1] + Chile.maize.outlet.X_pr[2] + 1e-10 * Chile.maize.f_xi[2] + Chile.maize.si + Chile.maize.outlet.X_i[2] + (Chile.maize.xaa + Chile.maize.xac + Chile.maize.xc4 + Chile.maize.xfa + Chile.maize.xh2 + Chile.maize.xpro + Chile.maize.xsu) * Chile.maize.f_Xbiom_pr) / Chile.maize.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3300(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3300};
  (data->localData[0]->realVars[783] /* Chile.maize.PR_tot_TKN variable */) = (0.6534431137724552) * (DIVISION_SIM(2e-10 + (data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */) + (1e-10) * ((data->localData[0]->realVars[825] /* Chile.maize.f_xi[2] variable */)) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[841] /* Chile.maize.outlet.X_i[2] variable */) + ((data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */)) * ((data->simulationInfo->realParameter[601] /* Chile.maize.f_Xbiom_pr PARAM */)),(data->simulationInfo->realParameter[567] /* Chile.maize.N_PR PARAM */),"Chile.maize.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3301
type: SIMPLE_ASSIGN
Chile.maize.f_xi[3] = Chile.maize.outlet.X_i[3] / Chile.maize.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3301(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3301};
  (data->localData[0]->realVars[826] /* Chile.maize.f_xi[3] variable */) = DIVISION_SIM((data->localData[0]->realVars[842] /* Chile.maize.outlet.X_i[3] variable */),(data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */),"Chile.maize.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3302
type: SIMPLE_ASSIGN
Chile.maize.LI_tot = 0.3532661514862131 * (2e-10 + Chile.maize.outlet.S_fa + Chile.maize.outlet.X_li + 1e-10 * Chile.maize.f_xi[3] + Chile.maize.si + Chile.maize.outlet.X_i[3] + (Chile.maize.xaa + Chile.maize.xac + Chile.maize.xc4 + Chile.maize.xfa + Chile.maize.xh2 + Chile.maize.xpro + Chile.maize.xsu) * Chile.maize.f_Xbiom_li)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3302(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3302};
  (data->localData[0]->realVars[749] /* Chile.maize.LI_tot variable */) = (0.3532661514862131) * (2e-10 + (data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) + (data->localData[0]->realVars[844] /* Chile.maize.outlet.X_li variable */) + (1e-10) * ((data->localData[0]->realVars[826] /* Chile.maize.f_xi[3] variable */)) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[842] /* Chile.maize.outlet.X_i[3] variable */) + ((data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */)) * ((data->simulationInfo->realParameter[600] /* Chile.maize.f_Xbiom_li PARAM */)));
  TRACE_POP
}
/*
equation index: 3303
type: SIMPLE_ASSIGN
Chile.digester.X_i_in[4] = ($cse1 * Chile.maize.outlet.X_i[4] + $cse2 * Chile.tomatosouce.outlet.X_i[4] + $cse3 * Chile.slurry.outlet.X_i[4]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3303(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3303};
  (data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1207] /* Chile.tomatosouce.outlet.X_i[4] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1029] /* Chile.slurry.outlet.X_i[4] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3304
type: SIMPLE_ASSIGN
Chile.digester.f_xi[3] = if noEvent(Chile.digester.X_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.X_i_in[3] / Chile.digester.X_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3304(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3304};
  modelica_boolean tmp15;
  tmp15 = Less((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */) = (tmp15?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[489] /* Chile.digester.X_i_in[3] variable */),(data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),"Chile.digester.X_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 3305
type: SIMPLE_ASSIGN
Chile.mass_to_info.outlet[40] = Chile.digester.X_i * Chile.digester.f_xi[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3305(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3305};
  (data->localData[0]->realVars[869] /* Chile.mass_to_info.outlet[40] variable */) = ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) * ((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */));
  TRACE_POP
}
/*
equation index: 3306
type: SIMPLE_ASSIGN
Chile.digester.i_XI[5] = 0.0003421741796374586 * Chile.digester.f_xi[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3306(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3306};
  (data->localData[0]->realVars[555] /* Chile.digester.i_XI[5] variable */) = (0.0003421741796374586) * ((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */));
  TRACE_POP
}
/*
equation index: 3307
type: SIMPLE_ASSIGN
Chile.digester.i_XC[5] = 0.0003421741796374586 * Chile.digester.f_xc[3] + Chile.digester.f_xc[4] * Chile.digester.i_XI[5] + Chile.digester.f_xc[5] * Chile.digester.i_SI[5]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3307(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3307};
  (data->localData[0]->realVars[550] /* Chile.digester.i_XC[5] variable */) = (0.0003421741796374586) * ((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) + ((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[555] /* Chile.digester.i_XI[5] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */));
  TRACE_POP
}
/*
equation index: 3308
type: SIMPLE_ASSIGN
Chile.digester.IP_balance_out = (-Chile.digester.Q) * (0.00021 * Chile.digester.X_p + Chile.digester.S_ip + Chile.digester.i_SI[5] * Chile.digester.S_i + Chile.digester.i_XI[5] * Chile.digester.X_i + 0.0003421741796374586 * Chile.digester.X_li + 0.0006853095503241148 * (Chile.digester.X_su + Chile.digester.X_aa + Chile.digester.X_fa + Chile.digester.X_c4 + Chile.digester.X_pro + Chile.digester.X_ac + Chile.digester.X_h2) + 2.0 * Chile.digester.X_acp + Chile.digester.X_stru + Chile.digester.X_c * Chile.digester.i_XC[5])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3308(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3308};
  (data->localData[0]->realVars[345] /* Chile.digester.IP_balance_out variable */) = ((-(data->localData[0]->realVars[423] /* Chile.digester.Q variable */))) * ((0.00021) * ((data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */)) + (data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */) + ((data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */)) * ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) + ((data->localData[0]->realVars[555] /* Chile.digester.i_XI[5] variable */)) * ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) + (0.0003421741796374586) * ((data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */)) + (0.0006853095503241148) * ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */)) + (2.0) * ((data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */)) + (data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * ((data->localData[0]->realVars[550] /* Chile.digester.i_XC[5] variable */)));
  TRACE_POP
}
/*
equation index: 3309
type: SIMPLE_ASSIGN
$DER.Chile.digester.IP_balance_out_cum = Chile.digester.IP_balance_out / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3309(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3309};
  (data->localData[0]->realVars[89] /* der(Chile.digester.IP_balance_out_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[345] /* Chile.digester.IP_balance_out variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3310
type: SIMPLE_ASSIGN
Chile.digester.LI_tot = 0.3484320557491289 * Chile.digester.S_fa + 0.3532661514862131 * (Chile.digester.X_li + Chile.digester.X_c * Chile.digester.f_xc[4] * Chile.digester.f_xi[3] + Chile.digester.X_c * Chile.digester.f_xc[5] * Chile.digester.f_si[3] + Chile.digester.X_c * Chile.digester.f_xc[3] + Chile.digester.S_i * Chile.digester.f_si[3] + Chile.mass_to_info.outlet[40] + (Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c4 + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_pro + Chile.digester.X_su) * Chile.digester.f_li_xb)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3310(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3310};
  (data->localData[0]->realVars[389] /* Chile.digester.LI_tot variable */) = (0.3484320557491289) * ((data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */)) + (0.3532661514862131) * ((data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * ((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */)) + (data->localData[0]->realVars[869] /* Chile.mass_to_info.outlet[40] variable */) + ((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */)) * ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)));
  TRACE_POP
}
/*
equation index: 3311
type: SIMPLE_ASSIGN
Chile.digester.f_xi[2] = if noEvent(Chile.digester.X_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.X_i_in[2] / Chile.digester.X_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3311(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3311};
  modelica_boolean tmp16;
  tmp16 = Less((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */) = (tmp16?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[488] /* Chile.digester.X_i_in[2] variable */),(data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),"Chile.digester.X_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 3312
type: SIMPLE_ASSIGN
Chile.mass_to_info.outlet[39] = Chile.digester.X_i * Chile.digester.f_xi[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3312(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3312};
  (data->localData[0]->realVars[868] /* Chile.mass_to_info.outlet[39] variable */) = ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */));
  TRACE_POP
}
/*
equation index: 3313
type: SIMPLE_ASSIGN
Chile.digester.i_XI[4] = 0.00748502994011976 * Chile.digester.f_xi[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3313(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3313};
  (data->localData[0]->realVars[554] /* Chile.digester.i_XI[4] variable */) = (0.00748502994011976) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */));
  TRACE_POP
}
/*
equation index: 3314
type: SIMPLE_ASSIGN
Chile.digester.i_XC[4] = 0.00748502994011976 * Chile.digester.f_xc[2] + Chile.digester.f_xc[4] * Chile.digester.i_XI[4] + Chile.digester.f_xc[5] * Chile.digester.i_SI[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3314(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3314};
  (data->localData[0]->realVars[549] /* Chile.digester.i_XC[4] variable */) = (0.00748502994011976) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) + ((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[554] /* Chile.digester.i_XI[4] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */));
  TRACE_POP
}
/*
equation index: 3315
type: SIMPLE_ASSIGN
Chile.digester.n1 = Chile.digester.i_XC[4] + (-0.00748502994011976) * Chile.digester.f_xc[2] - Chile.digester.f_xc[4] * Chile.digester.i_XI[4] - Chile.digester.f_xc[5] * Chile.digester.i_SI[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3315(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3315};
  (data->localData[0]->realVars[582] /* Chile.digester.n1 variable */) = (data->localData[0]->realVars[549] /* Chile.digester.i_XC[4] variable */) + (-0.00748502994011976) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) - (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[554] /* Chile.digester.i_XI[4] variable */))) - (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */)));
  TRACE_POP
}
/*
equation index: 3316
type: SIMPLE_ASSIGN
Chile.digester.IN_balance_out = (-Chile.digester.Q) * (0.0043 * Chile.digester.X_p + Chile.digester.S_in + Chile.digester.i_SI[4] * Chile.digester.S_i + Chile.digester.i_XI[4] * Chile.digester.X_i + 0.00748502994011976 * (Chile.digester.S_aa + Chile.digester.X_pr[1] + Chile.digester.X_pr[2]) + 0.006078672612418971 * (Chile.digester.X_su + Chile.digester.X_aa + Chile.digester.X_fa + Chile.digester.X_c4 + Chile.digester.X_pro + Chile.digester.X_ac + Chile.digester.X_h2) + Chile.digester.X_stru + Chile.digester.i_XC[4] * Chile.digester.X_c)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3316(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3316};
  (data->localData[0]->realVars[343] /* Chile.digester.IN_balance_out variable */) = ((-(data->localData[0]->realVars[423] /* Chile.digester.Q variable */))) * ((0.0043) * ((data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */)) + (data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */) + ((data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */)) * ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) + ((data->localData[0]->realVars[554] /* Chile.digester.i_XI[4] variable */)) * ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) + (0.00748502994011976) * ((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */)) + (0.006078672612418971) * ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */)) + (data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */) + ((data->localData[0]->realVars[549] /* Chile.digester.i_XC[4] variable */)) * ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)));
  TRACE_POP
}
/*
equation index: 3317
type: SIMPLE_ASSIGN
$DER.Chile.digester.IN_balance_out_cum = Chile.digester.IN_balance_out / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3317(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3317};
  (data->localData[0]->realVars[87] /* der(Chile.digester.IN_balance_out_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[343] /* Chile.digester.IN_balance_out variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3318
type: SIMPLE_ASSIGN
Chile.digester.PR_tot_BCA = 0.6535947712418301 * Chile.digester.S_aa + (Chile.digester.X_pr[1] + Chile.digester.X_pr[2] + Chile.digester.X_c * Chile.digester.f_xc[4] * Chile.digester.f_xi[2] + Chile.digester.X_c * Chile.digester.f_xc[5] * Chile.digester.f_si[2] + Chile.digester.X_c * Chile.digester.f_xc[2] + Chile.digester.S_i * Chile.digester.f_si[2] + Chile.mass_to_info.outlet[39] + (Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c4 + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_pro + Chile.digester.X_su) * Chile.digester.f_pr_xb) / Chile.digester.COD_VS_PR_BCA
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3318(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3318};
  (data->localData[0]->realVars[420] /* Chile.digester.PR_tot_BCA variable */) = (0.6535947712418301) * ((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */)) + DIVISION_SIM((data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)) + (data->localData[0]->realVars[868] /* Chile.mass_to_info.outlet[39] variable */) + ((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */)) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)),(data->simulationInfo->realParameter[191] /* Chile.digester.COD_VS_PR_BCA PARAM */),"Chile.digester.COD_VS_PR_BCA",equationIndexes);
  TRACE_POP
}
/*
equation index: 3319
type: SIMPLE_ASSIGN
Chile.digester.PR_tot_TKN = 0.6535947712418301 * Chile.digester.S_aa / Chile.digester.N_PR + 0.6534431137724552 * (Chile.digester.X_pr[1] + Chile.digester.X_pr[2] + Chile.digester.X_c * Chile.digester.f_xc[4] * Chile.digester.f_xi[2] + Chile.digester.X_c * Chile.digester.f_xc[5] * Chile.digester.f_si[2] + Chile.digester.X_c * Chile.digester.f_xc[2] + Chile.digester.S_i * Chile.digester.f_si[2] + Chile.mass_to_info.outlet[39] + (Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c4 + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_pro + Chile.digester.X_su) * Chile.digester.f_pr_xb) / Chile.digester.N_PR
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3319(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3319};
  (data->localData[0]->realVars[421] /* Chile.digester.PR_tot_TKN variable */) = (0.6535947712418301) * (DIVISION_SIM((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */),(data->simulationInfo->realParameter[240] /* Chile.digester.N_PR PARAM */),"Chile.digester.N_PR",equationIndexes)) + (0.6534431137724552) * (DIVISION_SIM((data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)) + (data->localData[0]->realVars[868] /* Chile.mass_to_info.outlet[39] variable */) + ((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */)) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)),(data->simulationInfo->realParameter[240] /* Chile.digester.N_PR PARAM */),"Chile.digester.N_PR",equationIndexes));
  TRACE_POP
}
/*
equation index: 3320
type: SIMPLE_ASSIGN
Chile.digester.IN_balance_in = Chile.digester.Q * (Chile.digester.S_in_in + Chile.digester.i_SI[4] * Chile.digester.S_i_in[4] + Chile.digester.i_XI[4] * Chile.digester.X_i_in[4] + 0.00748502994011976 * (Chile.digester.S_aa_in + Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2]) + 0.006078672612418971 * (Chile.digester.X_su_in + Chile.digester.X_aa_in + Chile.digester.X_fa_in + Chile.digester.X_c4_in + Chile.digester.X_pro_in + Chile.digester.X_ac_in + Chile.digester.X_h2_in) + 1e-10 * Chile.digester.i_XC[4])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3320(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3320};
  (data->localData[0]->realVars[342] /* Chile.digester.IN_balance_in variable */) = ((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[451] /* Chile.digester.S_in_in variable */) + ((data->localData[0]->realVars[544] /* Chile.digester.i_SI[4] variable */)) * ((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */)) + ((data->localData[0]->realVars[554] /* Chile.digester.i_XI[4] variable */)) * ((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */)) + (0.00748502994011976) * ((data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) + (data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */)) + (0.006078672612418971) * ((data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) + (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) + (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) + (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) + (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) + (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) + (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */)) + (1e-10) * ((data->localData[0]->realVars[549] /* Chile.digester.i_XC[4] variable */)));
  TRACE_POP
}
/*
equation index: 3321
type: SIMPLE_ASSIGN
$DER.Chile.digester.IN_balance_in_cum = Chile.digester.IN_balance_in / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3321(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3321};
  (data->localData[0]->realVars[86] /* der(Chile.digester.IN_balance_in_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[342] /* Chile.digester.IN_balance_in variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3322
type: SIMPLE_ASSIGN
Chile.digester.IP_balance_in = Chile.digester.Q * (Chile.digester.S_ip_in + Chile.digester.i_SI[5] * Chile.digester.S_i_in[4] + Chile.digester.i_XI[5] * Chile.digester.X_i_in[4] + 0.0003421741796374586 * Chile.digester.X_li_in + 0.0006853095503241148 * (Chile.digester.X_su_in + Chile.digester.X_aa_in + Chile.digester.X_fa_in + Chile.digester.X_c4_in + Chile.digester.X_pro_in + Chile.digester.X_ac_in + Chile.digester.X_h2_in) + 1e-10 * Chile.digester.i_XC[5])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3322(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3322};
  (data->localData[0]->realVars[344] /* Chile.digester.IP_balance_in variable */) = ((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[452] /* Chile.digester.S_ip_in variable */) + ((data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */)) * ((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */)) + ((data->localData[0]->realVars[555] /* Chile.digester.i_XI[5] variable */)) * ((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */)) + (0.0003421741796374586) * ((data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */)) + (0.0006853095503241148) * ((data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) + (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) + (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) + (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) + (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) + (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) + (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */)) + (1e-10) * ((data->localData[0]->realVars[550] /* Chile.digester.i_XC[5] variable */)));
  TRACE_POP
}
/*
equation index: 3323
type: SIMPLE_ASSIGN
$DER.Chile.digester.IP_balance_in_cum = Chile.digester.IP_balance_in / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3323(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3323};
  (data->localData[0]->realVars[88] /* der(Chile.digester.IP_balance_in_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[344] /* Chile.digester.IP_balance_in variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3324
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_i = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_i_in[4] - Chile.digester.X_i) + Chile.digester.f_xc[4] * Chile.digester.r1 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3324(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3324};
  (data->localData[0]->realVars[126] /* der(Chile.digester.X_i) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */) - (data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3325
type: SIMPLE_ASSIGN
Chile.maize.f_xi[1] = Chile.maize.outlet.X_i[1] / Chile.maize.outlet.X_i[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3325(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3325};
  (data->localData[0]->realVars[824] /* Chile.maize.f_xi[1] variable */) = DIVISION_SIM((data->localData[0]->realVars[840] /* Chile.maize.outlet.X_i[1] variable */),(data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */),"Chile.maize.outlet.X_i[4]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3326
type: SIMPLE_ASSIGN
Chile.maize.COD_VS[25] = 1.0 / (0.84375 * Chile.maize.f_xi[1] + Chile.maize.f_xi[2] / 1.530355097365406 + Chile.maize.f_xi[3] / 2.830726906025207)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3326(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3326};
  (data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */) = DIVISION_SIM(1.0,(0.84375) * ((data->localData[0]->realVars[824] /* Chile.maize.f_xi[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[825] /* Chile.maize.f_xi[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[826] /* Chile.maize.f_xi[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes),"0.84375 * Chile.maize.f_xi[1] + Chile.maize.f_xi[2] / 1.530355097365406 + Chile.maize.f_xi[3] / 2.830726906025207",equationIndexes);
  TRACE_POP
}
/*
equation index: 3327
type: SIMPLE_ASSIGN
Chile.maize.COD_VS[14] = 1.0 / (4.435293530517336 + 1.0 / Chile.maize.COD_VS[25])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3327(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3327};
  (data->localData[0]->realVars[714] /* Chile.maize.COD_VS[14] variable */) = DIVISION_SIM(1.0,4.435293530517336 + DIVISION_SIM(1.0,(data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */),"Chile.maize.COD_VS[25]",equationIndexes),"4.435293530517336 + 1.0 / Chile.maize.COD_VS[25]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3328
type: SIMPLE_ASSIGN
Chile.maize.MW[25] = 1.0 / (Chile.maize.COD_VS[25] * (Chile.maize.f_xi[1] / 192.0 + Chile.maize.f_xi[2] / 133.6 + Chile.maize.f_xi[3] / 2352.194407671715))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3328(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3328};
  (data->localData[0]->realVars[775] /* Chile.maize.MW[25] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[824] /* Chile.maize.f_xi[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[825] /* Chile.maize.f_xi[2] variable */),133.6,"133.6",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[826] /* Chile.maize.f_xi[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes)),"Chile.maize.COD_VS[25] * (Chile.maize.f_xi[1] / 192.0 + Chile.maize.f_xi[2] / 133.6 + Chile.maize.f_xi[3] / 2352.194407671715)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3329
type: SIMPLE_ASSIGN
Chile.maize.MW[14] = 1.0 / ((0.03404949640278076 + 1.0 / (Chile.maize.MW[25] * Chile.maize.COD_VS[25])) * Chile.maize.COD_VS[14])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3329(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3329};
  (data->localData[0]->realVars[764] /* Chile.maize.MW[14] variable */) = DIVISION_SIM(1.0,(0.03404949640278076 + DIVISION_SIM(1.0,((data->localData[0]->realVars[775] /* Chile.maize.MW[25] variable */)) * ((data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */)),"Chile.maize.MW[25] * Chile.maize.COD_VS[25]",equationIndexes)) * ((data->localData[0]->realVars[714] /* Chile.maize.COD_VS[14] variable */)),"(0.03404949640278076 + 1.0 / (Chile.maize.MW[25] * Chile.maize.COD_VS[25])) * Chile.maize.COD_VS[14]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3330
type: SIMPLE_ASSIGN
Chile.digester.X_i_in[1] = ($cse1 * Chile.maize.outlet.X_i[1] + $cse2 * Chile.tomatosouce.outlet.X_i[1] + $cse3 * Chile.slurry.outlet.X_i[1]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3330(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3330};
  (data->localData[0]->realVars[487] /* Chile.digester.X_i_in[1] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[840] /* Chile.maize.outlet.X_i[1] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1204] /* Chile.tomatosouce.outlet.X_i[1] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1026] /* Chile.slurry.outlet.X_i[1] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3331
type: SIMPLE_ASSIGN
Chile.digester.f_xi[1] = if noEvent(Chile.digester.X_i_in[4] < 1e-10) then 0.3333333333333333 else Chile.digester.X_i_in[1] / Chile.digester.X_i_in[4]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3331(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3331};
  modelica_boolean tmp17;
  tmp17 = Less((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),1e-10);
  (data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */) = (tmp17?0.3333333333333333:DIVISION_SIM((data->localData[0]->realVars[487] /* Chile.digester.X_i_in[1] variable */),(data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),"Chile.digester.X_i_in[4]",equationIndexes));
  TRACE_POP
}
/*
equation index: 3332
type: SIMPLE_ASSIGN
Chile.mass_to_info.outlet[38] = Chile.digester.X_i * Chile.digester.f_xi[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3332(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3332};
  (data->localData[0]->realVars[867] /* Chile.mass_to_info.outlet[38] variable */) = ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) * ((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */));
  TRACE_POP
}
/*
equation index: 3333
type: SIMPLE_ASSIGN
Chile.digester.i_XI[1] = 0.03125 * Chile.digester.f_xi[1] + 0.02994011976047905 * Chile.digester.f_xi[2] + 0.02168188132480155 * Chile.digester.f_xi[3]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3333(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3333};
  (data->localData[0]->realVars[551] /* Chile.digester.i_XI[1] variable */) = (0.03125) * ((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */)) + (0.02168188132480155) * ((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */));
  TRACE_POP
}
/*
equation index: 3334
type: SIMPLE_ASSIGN
Chile.digester.i_XC[1] = 0.02168188132480155 * Chile.digester.f_xc[3] + 0.02994011976047905 * Chile.digester.f_xc[2] + 0.03125 * Chile.digester.f_xc[1] + Chile.digester.f_xc[4] * Chile.digester.i_XI[1] + Chile.digester.f_xc[5] * Chile.digester.i_SI[1] + 0.0234375 * Chile.digester.f_xc[6]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3334(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3334};
  (data->localData[0]->realVars[546] /* Chile.digester.i_XC[1] variable */) = (0.02168188132480155) * ((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) + (0.03125) * ((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */)) + ((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[551] /* Chile.digester.i_XI[1] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */)) + (0.0234375) * ((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */));
  TRACE_POP
}
/*
equation index: 3335
type: SIMPLE_ASSIGN
Chile.digester.v1 = 0.0234375 + Chile.digester.f_xc[5] * Chile.digester.i_SI[1] + 0.03125 * Chile.digester.f_xc[1] + 0.02994011976047905 * Chile.digester.f_xc[2] + 0.02168188132480155 * Chile.digester.f_xc[3] + Chile.digester.f_xc[4] * Chile.digester.i_XI[1] + Chile.digester.f_xc[6] - Chile.digester.i_XC[1]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3335(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3335};
  (data->localData[0]->realVars[632] /* Chile.digester.v1 variable */) = 0.0234375 + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */)) + (0.03125) * ((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */)) + (0.02168188132480155) * ((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) + ((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[551] /* Chile.digester.i_XI[1] variable */)) + (data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */) - (data->localData[0]->realVars[546] /* Chile.digester.i_XC[1] variable */);
  TRACE_POP
}
/*
equation index: 3336
type: SIMPLE_ASSIGN
Chile.digester.IC_balance_out = (-Chile.digester.Q) * (0.0234375 * Chile.digester.X_lig + 0.0301 * Chile.digester.X_p + Chile.digester.S_ic + Chile.digester.i_SI[1] * Chile.digester.S_i + Chile.digester.i_XI[1] * Chile.digester.X_i + 0.03125 * (Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3]) + 0.02994011976047905 * (Chile.digester.X_pr[1] + Chile.digester.X_pr[2]) + 0.02168188132480155 * Chile.digester.X_li + 0.0313 * Chile.digester.S_su + 0.02994011976047905 * Chile.digester.S_aa + 0.02174 * Chile.digester.S_fa + 0.024 * Chile.digester.S_va + 0.025 * Chile.digester.S_bu + 0.0268 * Chile.digester.S_pro + 0.0313 * Chile.digester.S_ac + 0.0156 * Chile.digester.S_ch4 + 0.03039336306209486 * (Chile.digester.X_su + Chile.digester.X_aa + Chile.digester.X_fa + Chile.digester.X_c4 + Chile.digester.X_pro + Chile.digester.X_ac + Chile.digester.X_h2) + Chile.digester.i_XC[1] * Chile.digester.X_c + Chile.digester.X_ccm + Chile.digester.X_mag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3336(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3336};
  (data->localData[0]->realVars[340] /* Chile.digester.IC_balance_out variable */) = ((-(data->localData[0]->realVars[423] /* Chile.digester.Q variable */))) * ((0.0234375) * ((data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */)) + (0.0301) * ((data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */)) + (data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */) + ((data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */)) * ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) + ((data->localData[0]->realVars[551] /* Chile.digester.i_XI[1] variable */)) * ((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */)) + (0.03125) * ((data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */)) + (0.02994011976047905) * ((data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */)) + (0.02168188132480155) * ((data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */)) + (0.0313) * ((data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */)) + (0.02994011976047905) * ((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */)) + (0.02174) * ((data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */)) + (0.024) * ((data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */)) + (0.025) * ((data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */)) + (0.0268) * ((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */)) + (0.0313) * ((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */)) + (0.0156) * ((data->localData[0]->realVars[23] /* Chile.digester.S_ch4 STATE(1) */)) + (0.03039336306209486) * ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */)) + ((data->localData[0]->realVars[546] /* Chile.digester.i_XC[1] variable */)) * ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) + (data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */) + (data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */));
  TRACE_POP
}
/*
equation index: 3337
type: SIMPLE_ASSIGN
$DER.Chile.digester.IC_balance_out_cum = Chile.digester.IC_balance_out / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3337(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3337};
  (data->localData[0]->realVars[84] /* der(Chile.digester.IC_balance_out_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[340] /* Chile.digester.IC_balance_out variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3338
type: SIMPLE_ASSIGN
Chile.digester.CH_tot = 0.9345794392523364 * Chile.digester.S_su + 0.734375 * (Chile.digester.X_lig + Chile.digester.f_xc[6] * Chile.digester.X_c) + 0.84375 * (Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3] + Chile.digester.X_c * Chile.digester.f_xc[4] * Chile.digester.f_xi[1] + Chile.digester.X_c * Chile.digester.f_xc[5] * Chile.digester.f_si[1] + Chile.digester.X_c * Chile.digester.f_xc[1] + Chile.digester.S_i * Chile.digester.f_si[1] + Chile.mass_to_info.outlet[38] + (Chile.digester.X_aa + Chile.digester.X_ac + Chile.digester.X_c4 + Chile.digester.X_fa + Chile.digester.X_h2 + Chile.digester.X_pro + Chile.digester.X_su) * Chile.digester.f_ch_xb)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3338(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3338};
  (data->localData[0]->realVars[298] /* Chile.digester.CH_tot variable */) = (0.9345794392523364) * ((data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */)) + (0.734375) * ((data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */) + ((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */)) * ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */))) + (0.84375) * ((data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */))) + ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * ((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */)) + ((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */)) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)) + (data->localData[0]->realVars[867] /* Chile.mass_to_info.outlet[38] variable */) + ((data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */)) * ((data->simulationInfo->realParameter[318] /* Chile.digester.f_ch_xb PARAM */)));
  TRACE_POP
}
/*
equation index: 3339
type: SIMPLE_ASSIGN
Chile.digester.COD_VS[25] = 1.0 / (0.84375 * Chile.digester.f_xi[1] + Chile.digester.f_xi[2] / 1.530355097365406 + Chile.digester.f_xi[3] / 2.830726906025207)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3339(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3339};
  (data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */) = DIVISION_SIM(1.0,(0.84375) * ((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes),"0.84375 * Chile.digester.f_xi[1] + Chile.digester.f_xi[2] / 1.530355097365406 + Chile.digester.f_xi[3] / 2.830726906025207",equationIndexes);
  TRACE_POP
}
/*
equation index: 3340
type: SIMPLE_ASSIGN
Chile.digester.COD_VS[14] = 1.0 / (Chile.digester.f_xc[2] / 1.530355097365406 + Chile.digester.f_xc[3] / 2.830726906025207 + 0.84375 * Chile.digester.f_xc[1] + Chile.digester.f_xc[4] / Chile.digester.COD_VS[25] + Chile.digester.f_xc[5] / Chile.digester.COD_VS[13] + 0.734375 * Chile.digester.f_xc[6])
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3340(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3340};
  (data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */) = DIVISION_SIM(1.0,DIVISION_SIM((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */),1.530355097365406,"1.530355097365406",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */),2.830726906025207,"2.830726906025207",equationIndexes) + (0.84375) * ((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */)) + DIVISION_SIM((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */),(data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */),"Chile.digester.COD_VS[25]",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */),(data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */),"Chile.digester.COD_VS[13]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */)),"Chile.digester.f_xc[2] / 1.530355097365406 + Chile.digester.f_xc[3] / 2.830726906025207 + 0.84375 * Chile.digester.f_xc[1] + Chile.digester.f_xc[4] / Chile.digester.COD_VS[25] + Chile.digester.f_xc[5] / Chile.digester.COD_VS[13] + 0.734375 * Chile.digester.f_xc[6]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3341
type: SIMPLE_ASSIGN
Chile.digester.VS_bd_x = 0.84375 * (Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3]) + 0.6534431137724552 * (Chile.digester.X_pr[1] + Chile.digester.X_pr[2]) + 0.3532661514862131 * Chile.digester.X_li + Chile.digester.X_c / Chile.digester.COD_VS[14]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3341(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3341};
  (data->localData[0]->realVars[464] /* Chile.digester.VS_bd_x variable */) = (0.84375) * ((data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */)) + (0.6534431137724552) * ((data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */)) + (0.3532661514862131) * ((data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */)) + DIVISION_SIM((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */),(data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */),"Chile.digester.COD_VS[14]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3342
type: SIMPLE_ASSIGN
Chile.y_dig[5] = (Chile.digester.X_su + Chile.digester.X_aa + Chile.digester.X_fa + Chile.digester.X_c4 + Chile.digester.X_pro + Chile.digester.X_ac + Chile.digester.X_h2) * (0.84375 * Chile.digester.f_ch_xb + 0.6534431137724552 * Chile.digester.f_pr_xb + 0.3532661514862131 * Chile.digester.f_li_xb + Chile.digester.f_si_xb / Chile.digester.COD_VS[13] + Chile.digester.f_xi_xb / Chile.digester.COD_VS[25]) + 0.84375 * (Chile.digester.S_su + Chile.digester.X_ch[1] + Chile.digester.X_ch[2] + Chile.digester.X_ch[3]) + 0.6534431137724552 * (Chile.digester.S_aa + Chile.digester.X_pr[1] + Chile.digester.X_pr[2]) + 0.3532661514862131 * (Chile.digester.S_fa + Chile.digester.X_li) + Chile.digester.S_i / Chile.digester.COD_VS[13] + Chile.digester.X_i / Chile.digester.COD_VS[25] + Chile.digester.X_c / Chile.digester.COD_VS[14] + 0.734375 * Chile.digester.X_lig + 0.6493506493506493 * Chile.digester.X_p
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3342(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3342};
  (data->localData[0]->realVars[1234] /* Chile.y_dig[5] variable */) = ((data->localData[0]->realVars[62] /* Chile.digester.X_su STATE(1) */) + (data->localData[0]->realVars[42] /* Chile.digester.X_aa STATE(1) */) + (data->localData[0]->realVars[51] /* Chile.digester.X_fa STATE(1) */) + (data->localData[0]->realVars[46] /* Chile.digester.X_c4 STATE(1) */) + (data->localData[0]->realVars[60] /* Chile.digester.X_pro STATE(1) */) + (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */) + (data->localData[0]->realVars[52] /* Chile.digester.X_h2 STATE(1) */)) * ((0.84375) * ((data->simulationInfo->realParameter[318] /* Chile.digester.f_ch_xb PARAM */)) + (0.6534431137724552) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)) + (0.3532661514862131) * ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)) + DIVISION_SIM((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */),(data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */),"Chile.digester.COD_VS[13]",equationIndexes) + DIVISION_SIM((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */),(data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */),"Chile.digester.COD_VS[25]",equationIndexes)) + (0.84375) * ((data->localData[0]->realVars[37] /* Chile.digester.S_su STATE(1) */) + (data->localData[0]->realVars[48] /* Chile.digester.X_ch[1] STATE(1) */) + (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */) + (data->localData[0]->realVars[50] /* Chile.digester.X_ch[3] STATE(1) */)) + (0.6534431137724552) * ((data->localData[0]->realVars[17] /* Chile.digester.S_aa STATE(1) */) + (data->localData[0]->realVars[58] /* Chile.digester.X_pr[1] STATE(1) */) + (data->localData[0]->realVars[59] /* Chile.digester.X_pr[2] STATE(1) */)) + (0.3532661514862131) * ((data->localData[0]->realVars[24] /* Chile.digester.S_fa STATE(1) */) + (data->localData[0]->realVars[54] /* Chile.digester.X_li STATE(1) */)) + DIVISION_SIM((data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */),(data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */),"Chile.digester.COD_VS[13]",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[53] /* Chile.digester.X_i STATE(1) */),(data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */),"Chile.digester.COD_VS[25]",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */),(data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */),"Chile.digester.COD_VS[14]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */)) + (0.6493506493506493) * ((data->localData[0]->realVars[57] /* Chile.digester.X_p STATE(1) */));
  TRACE_POP
}
/*
equation index: 3343
type: SIMPLE_ASSIGN
Chile.digester.MW[25] = 1.0 / (Chile.digester.COD_VS[25] * (Chile.digester.f_xi[1] / 192.0 + Chile.digester.f_xi[2] / 133.6 + Chile.digester.f_xi[3] / 2352.194407671715))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3343(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3343};
  (data->localData[0]->realVars[414] /* Chile.digester.MW[25] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */),133.6,"133.6",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes)),"Chile.digester.COD_VS[25] * (Chile.digester.f_xi[1] / 192.0 + Chile.digester.f_xi[2] / 133.6 + Chile.digester.f_xi[3] / 2352.194407671715)",equationIndexes);
  TRACE_POP
}
/*
equation index: 3344
type: SIMPLE_ASSIGN
Chile.digester.MW[14] = 1.0 / (Chile.digester.COD_VS[14] * (Chile.digester.f_xc[2] / 133.6 + Chile.digester.f_xc[3] / 2352.194407671715 + Chile.digester.f_xc[1] / 192.0 + Chile.digester.f_xc[4] / (Chile.digester.MW[25] * Chile.digester.COD_VS[25]) + Chile.digester.f_xc[5] / (Chile.digester.MW[13] * Chile.digester.COD_VS[13]) + 0.0078125 * Chile.digester.f_xc[6]))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3344(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3344};
  (data->localData[0]->realVars[403] /* Chile.digester.MW[14] variable */) = DIVISION_SIM(1.0,((data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */)) * (DIVISION_SIM((data->localData[0]->realVars[529] /* Chile.digester.f_xc[2] variable */),133.6,"133.6",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */),2352.194407671715,"2352.194407671715",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */),192.0,"192.0",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */),((data->localData[0]->realVars[414] /* Chile.digester.MW[25] variable */)) * ((data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */)),"Chile.digester.MW[25] * Chile.digester.COD_VS[25]",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */),((data->localData[0]->realVars[402] /* Chile.digester.MW[13] variable */)) * ((data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */)),"Chile.digester.MW[13] * Chile.digester.COD_VS[13]",equationIndexes) + (0.0078125) * ((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */))),"Chile.digester.COD_VS[14] * (Chile.digester.f_xc[2] / 133.6 + Chile.digester.f_xc[3] / 2352.194407671715 + Chile.digester.f_xc[1] / 192.0 + Chile.digester.f_xc[4] / (Chile.digester.MW[25] * Chile.digester.COD_VS[25]) + Chile.digester.f_xc[5] / (Chile.digester.MW[13] * Chile.digester.COD_VS[13]) + 0.0078125 * Chile.digester.f_xc[6])",equationIndexes);
  TRACE_POP
}
/*
equation index: 3345
type: SIMPLE_ASSIGN
Chile.digester.resBMP_vs = (1014.0 * (Chile.digester.LI_tot + 0.3532661514862131 * ((-Chile.digester.S_i) * Chile.digester.f_si[3] - Chile.mass_to_info.outlet[40] - Chile.digester.X_c * (Chile.digester.f_xc[4] * Chile.digester.f_xi[3] + Chile.digester.f_xc[5] * Chile.digester.f_si[3]))) + 415.0 * (Chile.digester.CH_tot + (-0.734375) * Chile.digester.X_lig + (-0.734375) * Chile.digester.f_xc[6] * Chile.digester.X_c + 0.84375 * ((-Chile.digester.S_i) * Chile.digester.f_si[1] - Chile.mass_to_info.outlet[38] - Chile.digester.X_c * (Chile.digester.f_xc[4] * Chile.digester.f_xi[1] + Chile.digester.f_xc[5] * Chile.digester.f_si[1]))) + 496.0 * (Chile.digester.PR_tot_TKN + 0.6534431137724552 * ((-Chile.digester.S_i) * Chile.digester.f_si[2] - Chile.mass_to_info.outlet[39] - Chile.digester.X_c * (Chile.digester.f_xc[4] * Chile.digester.f_xi[2] + Chile.digester.f_xc[5] * Chile.digester.f_si[2])))) / Chile.y_dig[5]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3345(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3345};
  (data->localData[0]->realVars[616] /* Chile.digester.resBMP_vs variable */) = DIVISION_SIM((1014.0) * ((data->localData[0]->realVars[389] /* Chile.digester.LI_tot variable */) + (0.3532661514862131) * (((-(data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */))) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */)) - (data->localData[0]->realVars[869] /* Chile.mass_to_info.outlet[40] variable */) - (((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[536] /* Chile.digester.f_xi[3] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[527] /* Chile.digester.f_si[3] variable */)))))) + (415.0) * ((data->localData[0]->realVars[298] /* Chile.digester.CH_tot variable */) + (-0.734375) * ((data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */)) + (-0.734375) * (((data->localData[0]->realVars[533] /* Chile.digester.f_xc[6] variable */)) * ((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */))) + (0.84375) * (((-(data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */))) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)) - (data->localData[0]->realVars[867] /* Chile.mass_to_info.outlet[38] variable */) - (((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[534] /* Chile.digester.f_xi[1] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[525] /* Chile.digester.f_si[1] variable */)))))) + (496.0) * ((data->localData[0]->realVars[421] /* Chile.digester.PR_tot_TKN variable */) + (0.6534431137724552) * (((-(data->localData[0]->realVars[31] /* Chile.digester.S_i STATE(1) */))) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)) - (data->localData[0]->realVars[868] /* Chile.mass_to_info.outlet[39] variable */) - (((data->localData[0]->realVars[45] /* Chile.digester.X_c STATE(1) */)) * (((data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */)) * ((data->localData[0]->realVars[535] /* Chile.digester.f_xi[2] variable */)) + ((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[526] /* Chile.digester.f_si[2] variable */)))))),(data->localData[0]->realVars[1234] /* Chile.y_dig[5] variable */),"Chile.y_dig[5]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3346
type: SIMPLE_ASSIGN
Chile.maize.outlet.X_ch[2] = 0.0001185185185185185 * Chile.maize.BD_hemicell * Chile.maize.Hemicellulose_in * Chile.maize.TS_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3346(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3346};
  (data->localData[0]->realVars[838] /* Chile.maize.outlet.X_ch[2] variable */) = (0.0001185185185185185) * (((data->localData[0]->realVars[694] /* Chile.maize.BD_hemicell variable */)) * (((data->localData[0]->realVars[736] /* Chile.maize.Hemicellulose_in variable */)) * ((data->localData[0]->realVars[804] /* Chile.maize.TS_in variable */))));
  TRACE_POP
}
/*
equation index: 3347
type: SIMPLE_ASSIGN
Chile.maize.CH_tot = 1.223958333333333e-11 + 0.9345794392523364 * Chile.maize.outlet.S_su + 0.84375 * (2e-10 + Chile.maize.outlet.X_ch[1] + Chile.maize.outlet.X_ch[2] + Chile.maize.outlet.X_ch[3] + 1e-10 * Chile.maize.f_xi[1] + Chile.maize.si + Chile.maize.outlet.X_i[1] + (Chile.maize.xaa + Chile.maize.xac + Chile.maize.xc4 + Chile.maize.xfa + Chile.maize.xh2 + Chile.maize.xpro + Chile.maize.xsu) * Chile.maize.f_Xbiom_ch) + 0.734375 * Chile.maize.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3347(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3347};
  (data->localData[0]->realVars[700] /* Chile.maize.CH_tot variable */) = 1.223958333333333e-11 + (0.9345794392523364) * ((data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */)) + (0.84375) * (2e-10 + (data->localData[0]->realVars[837] /* Chile.maize.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[838] /* Chile.maize.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[839] /* Chile.maize.outlet.X_ch[3] variable */) + (1e-10) * ((data->localData[0]->realVars[824] /* Chile.maize.f_xi[1] variable */)) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[840] /* Chile.maize.outlet.X_i[1] variable */) + ((data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */)) * ((data->simulationInfo->realParameter[599] /* Chile.maize.f_Xbiom_ch PARAM */))) + (0.734375) * ((data->localData[0]->realVars[845] /* Chile.maize.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3348
type: SIMPLE_ASSIGN
Chile.maize.COD_tot = 1e-10 + Chile.maize.outlet.S_aa + Chile.maize.ac_in + Chile.maize.bu_in + Chile.maize.ch4 + Chile.maize.outlet.S_fa + Chile.maize.h2 + Chile.maize.si + Chile.maize.pro_in + Chile.maize.outlet.S_su + Chile.maize.va_in + Chile.maize.xaa + Chile.maize.xac + Chile.maize.xc4 + Chile.maize.outlet.X_ch[1] + Chile.maize.outlet.X_ch[2] + Chile.maize.outlet.X_ch[3] + Chile.maize.xfa + Chile.maize.xh2 + Chile.maize.outlet.X_i[4] + Chile.maize.outlet.X_li + Chile.maize.outlet.X_pr[1] + Chile.maize.outlet.X_pr[2] + Chile.maize.xpro + Chile.maize.xsu + Chile.maize.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3348(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3348};
  (data->localData[0]->realVars[729] /* Chile.maize.COD_tot variable */) = 1e-10 + (data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->localData[0]->realVars[808] /* Chile.maize.ac_in variable */) + (data->localData[0]->realVars[809] /* Chile.maize.bu_in variable */) + (data->simulationInfo->realParameter[594] /* Chile.maize.ch4 PARAM */) + (data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) + (data->simulationInfo->realParameter[616] /* Chile.maize.h2 PARAM */) + (data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */) + (data->localData[0]->realVars[853] /* Chile.maize.pro_in variable */) + (data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */) + (data->localData[0]->realVars[865] /* Chile.maize.va_in variable */) + (data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->localData[0]->realVars[837] /* Chile.maize.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[838] /* Chile.maize.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[839] /* Chile.maize.outlet.X_ch[3] variable */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */) + (data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */) + (data->localData[0]->realVars[844] /* Chile.maize.outlet.X_li variable */) + (data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */) + (data->localData[0]->realVars[845] /* Chile.maize.outlet.X_lig variable */);
  TRACE_POP
}
/*
equation index: 3349
type: SIMPLE_ASSIGN
Chile.maize.VS = (Chile.maize.xsu + Chile.maize.xaa + Chile.maize.xfa + Chile.maize.xc4 + Chile.maize.xpro + Chile.maize.xac + Chile.maize.xh2) * (0.84375 * Chile.maize.f_ch_xb + 0.6534431137724552 * Chile.maize.f_pr_xb + 0.3532661514862131 * Chile.maize.f_li_xb + 1.850459265258668 * Chile.maize.f_si_xb + Chile.maize.f_xi_xb / Chile.maize.COD_VS[25]) + 0.9345794392523364 * Chile.maize.outlet.S_su + 0.84375 * (Chile.maize.outlet.X_ch[1] + Chile.maize.outlet.X_ch[2] + Chile.maize.outlet.X_ch[3]) + 0.6534431137724552 * (Chile.maize.outlet.S_aa + Chile.maize.outlet.X_pr[1] + Chile.maize.outlet.X_pr[2]) + 0.3532661514862131 * (Chile.maize.outlet.S_fa + Chile.maize.outlet.X_li) + 1.850459265258668 * Chile.maize.si + Chile.maize.outlet.X_i[4] / Chile.maize.COD_VS[25] + 1e-10 / Chile.maize.COD_VS[14] + 0.734375 * Chile.maize.outlet.X_lig
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3349(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3349};
  (data->localData[0]->realVars[806] /* Chile.maize.VS variable */) = ((data->simulationInfo->realParameter[705] /* Chile.maize.xsu PARAM */) + (data->simulationInfo->realParameter[699] /* Chile.maize.xaa PARAM */) + (data->simulationInfo->realParameter[702] /* Chile.maize.xfa PARAM */) + (data->simulationInfo->realParameter[701] /* Chile.maize.xc4 PARAM */) + (data->simulationInfo->realParameter[704] /* Chile.maize.xpro PARAM */) + (data->simulationInfo->realParameter[700] /* Chile.maize.xac PARAM */) + (data->simulationInfo->realParameter[703] /* Chile.maize.xh2 PARAM */)) * ((0.84375) * ((data->simulationInfo->realParameter[604] /* Chile.maize.f_ch_xb PARAM */)) + (0.6534431137724552) * ((data->simulationInfo->realParameter[610] /* Chile.maize.f_pr_xb PARAM */)) + (0.3532661514862131) * ((data->simulationInfo->realParameter[607] /* Chile.maize.f_li_xb PARAM */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[612] /* Chile.maize.f_si_xb PARAM */)) + DIVISION_SIM((data->simulationInfo->realParameter[614] /* Chile.maize.f_xi_xb PARAM */),(data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */),"Chile.maize.COD_VS[25]",equationIndexes)) + (0.9345794392523364) * ((data->localData[0]->realVars[833] /* Chile.maize.outlet.S_su variable */)) + (0.84375) * ((data->localData[0]->realVars[837] /* Chile.maize.outlet.X_ch[1] variable */) + (data->localData[0]->realVars[838] /* Chile.maize.outlet.X_ch[2] variable */) + (data->localData[0]->realVars[839] /* Chile.maize.outlet.X_ch[3] variable */)) + (0.6534431137724552) * ((data->localData[0]->realVars[827] /* Chile.maize.outlet.S_aa variable */) + (data->localData[0]->realVars[848] /* Chile.maize.outlet.X_pr[1] variable */) + (data->localData[0]->realVars[849] /* Chile.maize.outlet.X_pr[2] variable */)) + (0.3532661514862131) * ((data->localData[0]->realVars[829] /* Chile.maize.outlet.S_fa variable */) + (data->localData[0]->realVars[844] /* Chile.maize.outlet.X_li variable */)) + (1.850459265258668) * ((data->simulationInfo->realParameter[689] /* Chile.maize.si PARAM */)) + DIVISION_SIM((data->localData[0]->realVars[843] /* Chile.maize.outlet.X_i[4] variable */),(data->localData[0]->realVars[725] /* Chile.maize.COD_VS[25] variable */),"Chile.maize.COD_VS[25]",equationIndexes) + DIVISION_SIM(1e-10,(data->localData[0]->realVars[714] /* Chile.maize.COD_VS[14] variable */),"Chile.maize.COD_VS[14]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[845] /* Chile.maize.outlet.X_lig variable */));
  TRACE_POP
}
/*
equation index: 3350
type: SIMPLE_ASSIGN
Chile.digester.X_ch_in[2] = ($cse1 * Chile.maize.outlet.X_ch[2] + $cse2 * Chile.tomatosouce.outlet.X_ch[2] + $cse3 * Chile.slurry.outlet.X_ch[2]) / ($cse1 + $cse2 + $cse3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3350(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3350};
  (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) = DIVISION_SIM(((data->localData[0]->realVars[148] /* $cse1 variable */)) * ((data->localData[0]->realVars[838] /* Chile.maize.outlet.X_ch[2] variable */)) + ((data->localData[0]->realVars[149] /* $cse2 variable */)) * ((data->localData[0]->realVars[1202] /* Chile.tomatosouce.outlet.X_ch[2] variable */)) + ((data->localData[0]->realVars[150] /* $cse3 variable */)) * ((data->localData[0]->realVars[1024] /* Chile.slurry.outlet.X_ch[2] variable */)),(data->localData[0]->realVars[148] /* $cse1 variable */) + (data->localData[0]->realVars[149] /* $cse2 variable */) + (data->localData[0]->realVars[150] /* $cse3 variable */),"$cse1 + $cse2 + $cse3",equationIndexes);
  TRACE_POP
}
/*
equation index: 3351
type: SIMPLE_ASSIGN
Chile.digester.COD_tot_bd_in = 7e-10 + Chile.digester.S_aa_in + Chile.digester.S_va_in + Chile.digester.S_su_in + Chile.digester.X_ch_in[1] + Chile.digester.X_ch_in[2] + Chile.digester.X_ch_in[3] + Chile.digester.X_li_in + Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3351(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3351};
  (data->localData[0]->realVars[335] /* Chile.digester.COD_tot_bd_in variable */) = 7e-10 + (data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) + (data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) + (data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */) + (data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) + (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) + (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */) + (data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */) + (data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */);
  TRACE_POP
}
/*
equation index: 3352
type: SIMPLE_ASSIGN
Chile.digester.VS_bd_x_in = 0.84375 * (Chile.digester.X_ch_in[1] + Chile.digester.X_ch_in[2] + Chile.digester.X_ch_in[3]) + 0.6534431137724552 * (Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2]) + 0.3532661514862131 * Chile.digester.X_li_in + 7e-10 / Chile.digester.COD_VS[14]
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3352(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3352};
  (data->localData[0]->realVars[465] /* Chile.digester.VS_bd_x_in variable */) = (0.84375) * ((data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) + (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) + (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */)) + (0.6534431137724552) * ((data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */)) + (0.3532661514862131) * ((data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */)) + DIVISION_SIM(7e-10,(data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */),"Chile.digester.COD_VS[14]",equationIndexes);
  TRACE_POP
}
/*
equation index: 3353
type: SIMPLE_ASSIGN
Chile.digester.VS_in = (Chile.digester.X_su_in + Chile.digester.X_aa_in + Chile.digester.X_fa_in + Chile.digester.X_c4_in + Chile.digester.X_pro_in + Chile.digester.X_ac_in + Chile.digester.X_h2_in) * (0.84375 * Chile.digester.f_ch_xb + 0.6534431137724552 * Chile.digester.f_pr_xb + 0.3532661514862131 * Chile.digester.f_li_xb + Chile.digester.f_si_xb / Chile.digester.COD_VS[13] + Chile.digester.f_xi_xb / Chile.digester.COD_VS[25]) + 0.9345794392523364 * Chile.digester.S_su_in + 0.84375 * (Chile.digester.X_ch_in[1] + Chile.digester.X_ch_in[2] + Chile.digester.X_ch_in[3]) + 0.6535947712418301 * Chile.digester.S_aa_in + 0.6534431137724552 * (Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2]) + 0.3484320557491289 * Chile.digester.inlet.S_fa + 0.3532661514862131 * Chile.digester.X_li_in + Chile.digester.S_i_in[4] / Chile.digester.COD_VS[13] + 1e-10 / Chile.digester.COD_VS[14] + Chile.digester.X_i_in[4] / Chile.digester.COD_VS[25] + 0.734375 * Chile.digester.X_lig_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3353(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3353};
  (data->localData[0]->realVars[466] /* Chile.digester.VS_in variable */) = ((data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) + (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) + (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) + (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) + (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) + (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) + (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */)) * ((0.84375) * ((data->simulationInfo->realParameter[318] /* Chile.digester.f_ch_xb PARAM */)) + (0.6534431137724552) * ((data->simulationInfo->realParameter[322] /* Chile.digester.f_pr_xb PARAM */)) + (0.3532661514862131) * ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)) + DIVISION_SIM((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */),(data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */),"Chile.digester.COD_VS[13]",equationIndexes) + DIVISION_SIM((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */),(data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */),"Chile.digester.COD_VS[25]",equationIndexes)) + (0.9345794392523364) * ((data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */)) + (0.84375) * ((data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) + (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) + (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */)) + (0.6535947712418301) * ((data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */)) + (0.6534431137724552) * ((data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */)) + (0.3484320557491289) * ((data->localData[0]->realVars[556] /* Chile.digester.inlet.S_fa variable */)) + (0.3532661514862131) * ((data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */)) + DIVISION_SIM((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */),(data->localData[0]->realVars[311] /* Chile.digester.COD_VS[13] variable */),"Chile.digester.COD_VS[13]",equationIndexes) + DIVISION_SIM(1e-10,(data->localData[0]->realVars[312] /* Chile.digester.COD_VS[14] variable */),"Chile.digester.COD_VS[14]",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */),(data->localData[0]->realVars[323] /* Chile.digester.COD_VS[25] variable */),"Chile.digester.COD_VS[25]",equationIndexes) + (0.734375) * ((data->localData[0]->realVars[492] /* Chile.digester.X_lig_in variable */));
  TRACE_POP
}
/*
equation index: 3354
type: SIMPLE_ASSIGN
Chile.digester.COD_balance_in = Chile.digester.Q * (1e-10 + Chile.digester.S_aa_in + Chile.digester.S_ac_in + Chile.digester.S_bu_in + Chile.digester.S_ch4_in + Chile.digester.inlet.S_fa + Chile.digester.S_h2_in + Chile.digester.S_i_in[4] + Chile.digester.S_pro_in + Chile.digester.S_su_in + Chile.digester.S_va_in + Chile.digester.X_aa_in + Chile.digester.X_ac_in + Chile.digester.X_c4_in + Chile.digester.X_fa_in + Chile.digester.X_h2_in + Chile.digester.X_pro_in + Chile.digester.X_su_in + Chile.digester.X_ch_in[1] + Chile.digester.X_ch_in[2] + Chile.digester.X_ch_in[3] + Chile.digester.X_i_in[4] + Chile.digester.X_li_in + Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2] + Chile.digester.X_lig)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3354(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3354};
  (data->localData[0]->realVars[328] /* Chile.digester.COD_balance_in variable */) = ((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (1e-10 + (data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */) + (data->localData[0]->realVars[430] /* Chile.digester.S_ac_in variable */) + (data->localData[0]->realVars[433] /* Chile.digester.S_bu_in variable */) + (data->localData[0]->realVars[437] /* Chile.digester.S_ch4_in variable */) + (data->localData[0]->realVars[556] /* Chile.digester.inlet.S_fa variable */) + (data->localData[0]->realVars[441] /* Chile.digester.S_h2_in variable */) + (data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */) + (data->localData[0]->realVars[458] /* Chile.digester.S_pro_in variable */) + (data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */) + (data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */) + (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) + (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) + (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) + (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) + (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */) + (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) + (data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) + (data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) + (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) + (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */) + (data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */) + (data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */) + (data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */) + (data->localData[0]->realVars[55] /* Chile.digester.X_lig STATE(1) */));
  TRACE_POP
}
/*
equation index: 3355
type: SIMPLE_ASSIGN
Chile.digester.OLR = 83.33333333333333 * Chile.digester.COD_balance_in
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3355(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3355};
  (data->localData[0]->realVars[417] /* Chile.digester.OLR variable */) = (83.33333333333333) * ((data->localData[0]->realVars[328] /* Chile.digester.COD_balance_in variable */));
  TRACE_POP
}
/*
equation index: 3356
type: SIMPLE_ASSIGN
$DER.Chile.digester.COD_balance_in_cum = Chile.digester.COD_balance_in / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3356(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3356};
  (data->localData[0]->realVars[80] /* der(Chile.digester.COD_balance_in_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[328] /* Chile.digester.COD_balance_in variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3357
type: SIMPLE_ASSIGN
Chile.digester.IC_balance_in = Chile.digester.Q * (0.0234375 * Chile.digester.X_lig_in + Chile.digester.S_ic_in + 1e-10 * Chile.digester.i_XC[1] + Chile.digester.i_SI[1] * Chile.digester.S_i_in[4] + Chile.digester.i_XI[1] * Chile.digester.X_i_in[4] + 0.03125 * (Chile.digester.X_ch_in[1] + Chile.digester.X_ch_in[2] + Chile.digester.X_ch_in[3]) + 0.02994011976047905 * (Chile.digester.X_pr_in[1] + Chile.digester.X_pr_in[2]) + 0.02168188132480155 * Chile.digester.X_li_in + 0.0313 * Chile.digester.S_su_in + 0.02994011976047905 * Chile.digester.S_aa_in + 0.02174 * Chile.digester.inlet.S_fa + 0.024 * Chile.digester.S_va_in + 0.025 * Chile.digester.S_bu_in + 0.0268 * Chile.digester.S_pro_in + 0.0313 * Chile.digester.S_ac_in + 0.0156 * Chile.digester.S_ch4_in + 0.03039336306209486 * (Chile.digester.X_su_in + Chile.digester.X_aa_in + Chile.digester.X_fa_in + Chile.digester.X_c4_in + Chile.digester.X_pro_in + Chile.digester.X_ac_in + Chile.digester.X_h2_in))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3357(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3357};
  (data->localData[0]->realVars[339] /* Chile.digester.IC_balance_in variable */) = ((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((0.0234375) * ((data->localData[0]->realVars[492] /* Chile.digester.X_lig_in variable */)) + (data->localData[0]->realVars[450] /* Chile.digester.S_ic_in variable */) + (1e-10) * ((data->localData[0]->realVars[546] /* Chile.digester.i_XC[1] variable */)) + ((data->localData[0]->realVars[541] /* Chile.digester.i_SI[1] variable */)) * ((data->localData[0]->realVars[449] /* Chile.digester.S_i_in[4] variable */)) + ((data->localData[0]->realVars[551] /* Chile.digester.i_XI[1] variable */)) * ((data->localData[0]->realVars[490] /* Chile.digester.X_i_in[4] variable */)) + (0.03125) * ((data->localData[0]->realVars[482] /* Chile.digester.X_ch_in[1] variable */) + (data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) + (data->localData[0]->realVars[484] /* Chile.digester.X_ch_in[3] variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[495] /* Chile.digester.X_pr_in[1] variable */) + (data->localData[0]->realVars[496] /* Chile.digester.X_pr_in[2] variable */)) + (0.02168188132480155) * ((data->localData[0]->realVars[491] /* Chile.digester.X_li_in variable */)) + (0.0313) * ((data->localData[0]->realVars[460] /* Chile.digester.S_su_in variable */)) + (0.02994011976047905) * ((data->localData[0]->realVars[429] /* Chile.digester.S_aa_in variable */)) + (0.02174) * ((data->localData[0]->realVars[556] /* Chile.digester.inlet.S_fa variable */)) + (0.024) * ((data->localData[0]->realVars[461] /* Chile.digester.S_va_in variable */)) + (0.025) * ((data->localData[0]->realVars[433] /* Chile.digester.S_bu_in variable */)) + (0.0268) * ((data->localData[0]->realVars[458] /* Chile.digester.S_pro_in variable */)) + (0.0313) * ((data->localData[0]->realVars[430] /* Chile.digester.S_ac_in variable */)) + (0.0156) * ((data->localData[0]->realVars[437] /* Chile.digester.S_ch4_in variable */)) + (0.03039336306209486) * ((data->localData[0]->realVars[499] /* Chile.digester.X_su_in variable */) + (data->localData[0]->realVars[470] /* Chile.digester.X_aa_in variable */) + (data->localData[0]->realVars[485] /* Chile.digester.X_fa_in variable */) + (data->localData[0]->realVars[473] /* Chile.digester.X_c4_in variable */) + (data->localData[0]->realVars[497] /* Chile.digester.X_pro_in variable */) + (data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) + (data->localData[0]->realVars[486] /* Chile.digester.X_h2_in variable */)));
  TRACE_POP
}
/*
equation index: 3358
type: SIMPLE_ASSIGN
$DER.Chile.digester.IC_balance_in_cum = Chile.digester.IC_balance_in / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3358(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3358};
  (data->localData[0]->realVars[83] /* der(Chile.digester.IC_balance_in_cum) STATE_DER */) = DIVISION_SIM((data->localData[0]->realVars[339] /* Chile.digester.IC_balance_in variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3359
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_ch[2] = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_ch_in[2] - Chile.digester.X_ch[2]) + (Chile.digester.f_xc[1] * Chile.digester.r1 + Chile.digester.f_ch_xb * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) - Chile.digester.r2[2]) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3359(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3359};
  (data->localData[0]->realVars[122] /* der(Chile.digester.X_ch[2]) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[483] /* Chile.digester.X_ch_in[2] variable */) - (data->localData[0]->realVars[49] /* Chile.digester.X_ch[2] STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[528] /* Chile.digester.f_xc[1] variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)) + ((data->simulationInfo->realParameter[318] /* Chile.digester.f_ch_xb PARAM */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)) - (data->localData[0]->realVars[597] /* Chile.digester.r2[2] variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3360
type: WHEN

when {$whenCondition7} then
  Chile.comp_maize.nextTimeEvent = if Chile.comp_maize.nextTimeEventScaled < 9.999999999999999e+59 then Chile.comp_maize.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3360(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3360};
  modelica_boolean tmp18;
  if(((data->localData[0]->booleanVars[6] /* $whenCondition7 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[6] /* $whenCondition7 DISCRETE */) /* edge */))
  {
    tmp18 = Less((data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1251] /* Chile.comp_maize.nextTimeEvent DISCRETE */) = (tmp18?(data->localData[0]->realVars[1252] /* Chile.comp_maize.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 3361
type: SIMPLE_ASSIGN
$whenCondition8 = integer((time - Chile.digester.trapezoid.startTime) / Chile.digester.trapezoid.period, 0) > pre(Chile.digester.trapezoid.count)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3361(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3361};
  modelica_boolean tmp19;
  relation(data, &tmp19, (_event_integer(DIVISION_SIM(data->localData[0]->timeValue - (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */),(data->simulationInfo->realParameter[441] /* Chile.digester.trapezoid.period PARAM */),"Chile.digester.trapezoid.period",equationIndexes), ((modelica_integer) 0), data)), (data->simulationInfo->integerVarsPre[0] /* Chile.digester.trapezoid.count DISCRETE */), 1, Greater);
  (data->localData[0]->booleanVars[7] /* $whenCondition8 DISCRETE */) = tmp19;
  TRACE_POP
}
/*
equation index: 3362
type: WHEN

when {$whenCondition8} then
  Chile.digester.trapezoid.T_start = time;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3362(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3362};
  if(((data->localData[0]->booleanVars[7] /* $whenCondition8 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[7] /* $whenCondition8 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 3363
type: WHEN

when {$whenCondition8} then
  Chile.digester.trapezoid.count = 1 + pre(Chile.digester.trapezoid.count);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3363(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3363};
  if(((data->localData[0]->booleanVars[7] /* $whenCondition8 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[7] /* $whenCondition8 DISCRETE */) /* edge */))
  {
    (data->localData[0]->integerVars[0] /* Chile.digester.trapezoid.count DISCRETE */) = ((modelica_integer) 1) + (data->simulationInfo->integerVarsPre[0] /* Chile.digester.trapezoid.count DISCRETE */);
  }
  TRACE_POP
}
/*
equation index: 3364
type: SIMPLE_ASSIGN
Chile.digester.trapezoid.y = Chile.digester.trapezoid.offset + (if time < Chile.digester.trapezoid.startTime or Chile.digester.trapezoid.nperiod == 0 or Chile.digester.trapezoid.nperiod > 0 and Chile.digester.trapezoid.count >= Chile.digester.trapezoid.nperiod then 0.0 else if time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_rising then Chile.digester.trapezoid.amplitude * (time - Chile.digester.trapezoid.T_start) / Chile.digester.trapezoid.rising else if time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_width then Chile.digester.trapezoid.amplitude else if time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_falling then Chile.digester.trapezoid.amplitude * (Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_falling - time) / Chile.digester.trapezoid.falling else 0.0)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3364(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3364};
  modelica_boolean tmp20;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_real tmp28;
  modelica_boolean tmp29;
  modelica_real tmp30;
  modelica_boolean tmp31;
  modelica_real tmp32;
  relationhysteresis(data, &tmp20, data->localData[0]->timeValue, (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */), 6, Less, LessZC);
  tmp22 = Greater((data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */),((modelica_integer) 0));
  tmp23 = GreaterEq((data->localData[0]->integerVars[0] /* Chile.digester.trapezoid.count DISCRETE */),(data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */));
  tmp31 = (modelica_boolean)((tmp20 || ((data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */) == ((modelica_integer) 0))) || (tmp22 && tmp23));
  if(tmp31)
  {
    tmp32 = 0.0;
  }
  else
  {
    relationhysteresis(data, &tmp24, data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[436] /* Chile.digester.trapezoid.T_rising PARAM */), 7, Less, LessZC);
    tmp29 = (modelica_boolean)tmp24;
    if(tmp29)
    {
      tmp30 = DIVISION_SIM(((data->simulationInfo->realParameter[438] /* Chile.digester.trapezoid.amplitude PARAM */)) * (data->localData[0]->timeValue - (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */)),(data->simulationInfo->realParameter[442] /* Chile.digester.trapezoid.rising PARAM */),"Chile.digester.trapezoid.rising",equationIndexes);
    }
    else
    {
      relationhysteresis(data, &tmp25, data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[437] /* Chile.digester.trapezoid.T_width PARAM */), 8, Less, LessZC);
      tmp27 = (modelica_boolean)tmp25;
      if(tmp27)
      {
        tmp28 = (data->simulationInfo->realParameter[438] /* Chile.digester.trapezoid.amplitude PARAM */);
      }
      else
      {
        relationhysteresis(data, &tmp26, data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[435] /* Chile.digester.trapezoid.T_falling PARAM */), 9, Less, LessZC);
        tmp28 = (tmp26?DIVISION_SIM(((data->simulationInfo->realParameter[438] /* Chile.digester.trapezoid.amplitude PARAM */)) * ((data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[435] /* Chile.digester.trapezoid.T_falling PARAM */) - data->localData[0]->timeValue),(data->simulationInfo->realParameter[439] /* Chile.digester.trapezoid.falling PARAM */),"Chile.digester.trapezoid.falling",equationIndexes):0.0);
      }
      tmp30 = tmp28;
    }
    tmp32 = tmp30;
  }
  (data->localData[0]->realVars[631] /* Chile.digester.trapezoid.y variable */) = (data->simulationInfo->realParameter[440] /* Chile.digester.trapezoid.offset PARAM */) + tmp32;
  TRACE_POP
}
/*
equation index: 3365
type: SIMPLE_ASSIGN
Chile.digester.k_m_ac_T = (Chile.digester.k_m_ac - Chile.digester.trapezoid.y) * $cse8
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3365(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3365};
  (data->localData[0]->realVars[572] /* Chile.digester.k_m_ac_T variable */) = ((data->simulationInfo->realParameter[382] /* Chile.digester.k_m_ac PARAM */) - (data->localData[0]->realVars[631] /* Chile.digester.trapezoid.y variable */)) * ((data->simulationInfo->realParameter[0] /* $cse8 PARAM */));
  TRACE_POP
}
/*
equation index: 3366
type: SIMPLE_ASSIGN
Chile.digester.I_hald_ac = Chile.digester.k_m_ac_T * Chile.digester.S_ac / (Chile.digester.S_ac + Chile.digester.Ks_ac_T + Chile.digester.S_ac ^ 2.0 / Chile.digester.Ki_hac_ac)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3366(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3366};
  modelica_real tmp33;
  tmp33 = (data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */);
  (data->localData[0]->realVars[355] /* Chile.digester.I_hald_ac variable */) = ((data->localData[0]->realVars[572] /* Chile.digester.k_m_ac_T variable */)) * (DIVISION_SIM((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */),(data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */) + (data->localData[0]->realVars[379] /* Chile.digester.Ks_ac_T variable */) + DIVISION_SIM((tmp33 * tmp33),(data->simulationInfo->realParameter[213] /* Chile.digester.Ki_hac_ac PARAM */),"Chile.digester.Ki_hac_ac",equationIndexes),"Chile.digester.S_ac + Chile.digester.Ks_ac_T + Chile.digester.S_ac ^ 2.0 / Chile.digester.Ki_hac_ac",equationIndexes));
  TRACE_POP
}
/*
equation index: 3367
type: SIMPLE_ASSIGN
Chile.digester.r11 = Chile.digester.k_m_ac_T * Chile.digester.S_ac * Chile.digester.X_ac * Chile.digester.I_11 / (Chile.digester.S_ac + Chile.digester.Ks_ac_T + Chile.digester.S_ac ^ 2.0 / Chile.digester.Ki_hac_ac)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3367(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3367};
  modelica_real tmp34;
  tmp34 = (data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */);
  (data->localData[0]->realVars[587] /* Chile.digester.r11 variable */) = ((data->localData[0]->realVars[572] /* Chile.digester.k_m_ac_T variable */)) * (((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */)) * (DIVISION_SIM(((data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */)) * ((data->localData[0]->realVars[347] /* Chile.digester.I_11 variable */)),(data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */) + (data->localData[0]->realVars[379] /* Chile.digester.Ks_ac_T variable */) + DIVISION_SIM((tmp34 * tmp34),(data->simulationInfo->realParameter[213] /* Chile.digester.Ki_hac_ac PARAM */),"Chile.digester.Ki_hac_ac",equationIndexes),"Chile.digester.S_ac + Chile.digester.Ks_ac_T + Chile.digester.S_ac ^ 2.0 / Chile.digester.Ki_hac_ac",equationIndexes)));
  TRACE_POP
}
/*
equation index: 3368
type: SIMPLE_ASSIGN
$DER.Chile.digester.CH4_cum = 1.388888888888889e-07 * ((1.0 - Chile.digester.Y_ac) * Chile.digester.r11 + (1.0 - Chile.digester.Y_h2) * Chile.digester.r12)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3368(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3368};
  (data->localData[0]->realVars[78] /* der(Chile.digester.CH4_cum) STATE_DER */) = (1.388888888888889e-07) * ((1.0 - (data->simulationInfo->realParameter[303] /* Chile.digester.Y_ac PARAM */)) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)) + (1.0 - (data->simulationInfo->realParameter[306] /* Chile.digester.Y_h2 PARAM */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)));
  TRACE_POP
}
/*
equation index: 3369
type: SIMPLE_ASSIGN
Chile.digester.rate_overall_Sic = (-5.000000000000143e-05) * (Chile.digester.r2[1] + Chile.digester.r2[2] + Chile.digester.r2[3]) - Chile.digester.v1 * Chile.digester.r1 - Chile.digester.v4 * Chile.digester.r4 - Chile.digester.v5 * Chile.digester.r5 - Chile.digester.v6 * Chile.digester.r6 - Chile.digester.v7 * Chile.digester.r7 - Chile.digester.v8 * Chile.digester.r8 - Chile.digester.v9 * Chile.digester.r9 - Chile.digester.v10 * Chile.digester.r10 - Chile.digester.v11 * Chile.digester.r11 - Chile.digester.v13 * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) - Chile.digester.v12 * Chile.digester.r12
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3369(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3369};
  (data->localData[0]->realVars[611] /* Chile.digester.rate_overall_Sic variable */) = (-5.000000000000143e-05) * ((data->localData[0]->realVars[596] /* Chile.digester.r2[1] variable */) + (data->localData[0]->realVars[597] /* Chile.digester.r2[2] variable */) + (data->localData[0]->realVars[598] /* Chile.digester.r2[3] variable */)) - (((data->localData[0]->realVars[632] /* Chile.digester.v1 variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */))) - (((data->localData[0]->realVars[639] /* Chile.digester.v4 variable */)) * ((data->localData[0]->realVars[601] /* Chile.digester.r4 variable */))) - (((data->localData[0]->realVars[640] /* Chile.digester.v5 variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))) - (((data->localData[0]->realVars[641] /* Chile.digester.v6 variable */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))) - (((data->localData[0]->realVars[642] /* Chile.digester.v7 variable */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */))) - (((data->localData[0]->realVars[643] /* Chile.digester.v8 variable */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) - (((data->localData[0]->realVars[644] /* Chile.digester.v9 variable */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */))) - (((data->localData[0]->realVars[633] /* Chile.digester.v10 variable */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */))) - (((data->localData[0]->realVars[634] /* Chile.digester.v11 variable */)) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */))) - (((data->localData[0]->realVars[636] /* Chile.digester.v13 variable */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */))) - (((data->localData[0]->realVars[635] /* Chile.digester.v12 variable */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)));
  TRACE_POP
}
/*
equation index: 3370
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_ac = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_ac_in - Chile.digester.S_ac) + (1.0 - Chile.digester.Y_su) * Chile.digester.f_ac_su * Chile.digester.r5 / 86400.0 + (1.0 - Chile.digester.Y_aa) * Chile.digester.f_ac_aa * Chile.digester.r6 / 86400.0 + 8.101851851851852e-06 * (1.0 - Chile.digester.Y_fa) * Chile.digester.r7 + 3.587962962962963e-06 * (1.0 - Chile.digester.Y_c4) * Chile.digester.r8 + 9.259259259259259e-06 * (1.0 - Chile.digester.Y_c4) * Chile.digester.r9 + 6.597222222222221e-06 * (1.0 - Chile.digester.Y_pro) * Chile.digester.r10 - Chile.digester.r11 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3370(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3370};
  (data->localData[0]->realVars[91] /* der(Chile.digester.S_ac) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[430] /* Chile.digester.S_ac_in variable */) - (data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * (((data->localData[0]->realVars[521] /* Chile.digester.f_ac_su variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))),86400.0,"86400.0",equationIndexes) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * (((data->simulationInfo->realParameter[316] /* Chile.digester.f_ac_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))),86400.0,"86400.0",equationIndexes) + (8.101851851851852e-06) * ((1.0 - (data->simulationInfo->realParameter[305] /* Chile.digester.Y_fa PARAM */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */))) + (3.587962962962963e-06) * ((1.0 - (data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) + (9.259259259259259e-06) * ((1.0 - (data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */))) + (6.597222222222221e-06) * ((1.0 - (data->simulationInfo->realParameter[307] /* Chile.digester.Y_pro PARAM */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */))) - (DIVISION_SIM((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3371
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_ch4 = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_ch4_in - Chile.digester.S_ch4) + ((1.0 - Chile.digester.Y_ac) * Chile.digester.r11 + (1.0 - Chile.digester.Y_h2) * Chile.digester.r12 - Chile.digester.rt9) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3371(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3371};
  (data->localData[0]->realVars[96] /* der(Chile.digester.S_ch4) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[437] /* Chile.digester.S_ch4_in variable */) - (data->localData[0]->realVars[23] /* Chile.digester.S_ch4 STATE(1) */))) + DIVISION_SIM((1.0 - (data->simulationInfo->realParameter[303] /* Chile.digester.Y_ac PARAM */)) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)) + (1.0 - (data->simulationInfo->realParameter[306] /* Chile.digester.Y_h2 PARAM */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)) - (data->localData[0]->realVars[624] /* Chile.digester.rt9 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3372
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_ic = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_ic_in - Chile.digester.S_ic) + (-0.01666666666666667) * (Chile.digester.rp3 + Chile.digester.rp4 - Chile.digester.rd4 - Chile.digester.rd3) + (-5.787037037037202e-10) * (Chile.digester.r2[1] + Chile.digester.r2[2] + Chile.digester.r2[3]) - Chile.digester.v1 * Chile.digester.r1 / 86400.0 - Chile.digester.v4 * Chile.digester.r4 / 86400.0 - Chile.digester.v5 * Chile.digester.r5 / 86400.0 - Chile.digester.v6 * Chile.digester.r6 / 86400.0 - Chile.digester.v7 * Chile.digester.r7 / 86400.0 - Chile.digester.v8 * Chile.digester.r8 / 86400.0 - Chile.digester.v9 * Chile.digester.r9 / 86400.0 - Chile.digester.v10 * Chile.digester.r10 / 86400.0 - Chile.digester.v11 * Chile.digester.r11 / 86400.0 - Chile.digester.v12 * Chile.digester.r12 / 86400.0 - Chile.digester.v13 * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) / 86400.0 - Chile.digester.rt10 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3372(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3372};
  (data->localData[0]->realVars[105] /* der(Chile.digester.S_ic) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[450] /* Chile.digester.S_ic_in variable */) - (data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */))) + (-0.01666666666666667) * ((data->localData[0]->realVars[619] /* Chile.digester.rp3 variable */) + (data->localData[0]->realVars[620] /* Chile.digester.rp4 variable */) - (data->localData[0]->realVars[615] /* Chile.digester.rd4 variable */) - (data->localData[0]->realVars[614] /* Chile.digester.rd3 variable */)) + (-5.787037037037202e-10) * ((data->localData[0]->realVars[596] /* Chile.digester.r2[1] variable */) + (data->localData[0]->realVars[597] /* Chile.digester.r2[2] variable */) + (data->localData[0]->realVars[598] /* Chile.digester.r2[3] variable */)) - (DIVISION_SIM(((data->localData[0]->realVars[632] /* Chile.digester.v1 variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[639] /* Chile.digester.v4 variable */)) * ((data->localData[0]->realVars[601] /* Chile.digester.r4 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[640] /* Chile.digester.v5 variable */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[641] /* Chile.digester.v6 variable */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[642] /* Chile.digester.v7 variable */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[643] /* Chile.digester.v8 variable */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[644] /* Chile.digester.v9 variable */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[633] /* Chile.digester.v10 variable */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[634] /* Chile.digester.v11 variable */)) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[635] /* Chile.digester.v12 variable */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM(((data->localData[0]->realVars[636] /* Chile.digester.v13 variable */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)),86400.0,"86400.0",equationIndexes)) - (DIVISION_SIM((data->localData[0]->realVars[621] /* Chile.digester.rt10 variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3373
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_in = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_in_in - Chile.digester.S_in) + Chile.digester.n6 * Chile.digester.r6 / 86400.0 + Chile.digester.n13 * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) / 86400.0 + Chile.digester.n1 * Chile.digester.r1 / 86400.0 + (-0.01666666666666667) * (Chile.digester.rp2 - Chile.digester.rd2) + 7.035500708818253e-08 * ((-Chile.digester.Y_ac) * Chile.digester.r11 - Chile.digester.Y_h2 * Chile.digester.r12 - Chile.digester.Y_pro * Chile.digester.r10 - Chile.digester.Y_c4 * Chile.digester.r9 - Chile.digester.Y_c4 * Chile.digester.r8 - Chile.digester.Y_su * Chile.digester.r5 - Chile.digester.Y_fa * Chile.digester.r7) - Chile.digester.rt12 / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3373(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3373};
  (data->localData[0]->realVars[106] /* der(Chile.digester.S_in) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[451] /* Chile.digester.S_in_in variable */) - (data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */))) + DIVISION_SIM(((data->localData[0]->realVars[584] /* Chile.digester.n6 variable */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */)),86400.0,"86400.0",equationIndexes) + DIVISION_SIM(((data->localData[0]->realVars[583] /* Chile.digester.n13 variable */)) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)),86400.0,"86400.0",equationIndexes) + DIVISION_SIM(((data->localData[0]->realVars[582] /* Chile.digester.n1 variable */)) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes) + (-0.01666666666666667) * ((data->localData[0]->realVars[618] /* Chile.digester.rp2 variable */) - (data->localData[0]->realVars[613] /* Chile.digester.rd2 variable */)) + (7.035500708818253e-08) * (((-(data->simulationInfo->realParameter[303] /* Chile.digester.Y_ac PARAM */))) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)) - (((data->simulationInfo->realParameter[306] /* Chile.digester.Y_h2 PARAM */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */))) - (((data->simulationInfo->realParameter[307] /* Chile.digester.Y_pro PARAM */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */))) - (((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */))) - (((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) - (((data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))) - (((data->simulationInfo->realParameter[305] /* Chile.digester.Y_fa PARAM */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */)))) - (DIVISION_SIM((data->localData[0]->realVars[622] /* Chile.digester.rt12 variable */),86400.0,"86400.0",equationIndexes));
  TRACE_POP
}
/*
equation index: 3374
type: SIMPLE_ASSIGN
$DER.Chile.digester.S_ip = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.S_ip_in - Chile.digester.S_ip) + 3.960349301359475e-09 * Chile.digester.r4 + (0.0006853095503241148 + (-0.0003421741796374586) * Chile.digester.f_li_xb + (-0.00021) * Chile.digester.f_xi_xb - Chile.digester.i_SI[5] * Chile.digester.f_si_xb) * (Chile.digester.r13 + Chile.digester.r14 + Chile.digester.r15 + Chile.digester.r16 + Chile.digester.r17 + Chile.digester.r18 + Chile.digester.r19) / 86400.0 + (Chile.digester.i_XC[5] + (-0.0003421741796374586) * Chile.digester.f_xc[3] + (-Chile.digester.f_xc[4]) * Chile.digester.i_XI[5] - Chile.digester.f_xc[5] * Chile.digester.i_SI[5]) * Chile.digester.r1 / 86400.0 + (-0.03333333333333333) * (Chile.digester.rp1 - Chile.digester.rd1) + (-0.01666666666666667) * (Chile.digester.rp2 - Chile.digester.rd2) + 7.931823499121699e-09 * ((-Chile.digester.Y_ac) * Chile.digester.r11 - Chile.digester.Y_h2 * Chile.digester.r12 - Chile.digester.Y_pro * Chile.digester.r10 - Chile.digester.Y_c4 * Chile.digester.r9 - Chile.digester.Y_c4 * Chile.digester.r8 - Chile.digester.Y_fa * Chile.digester.r7 - Chile.digester.Y_su * Chile.digester.r5 - Chile.digester.Y_aa * Chile.digester.r6)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3374(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3374};
  (data->localData[0]->realVars[107] /* der(Chile.digester.S_ip) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[452] /* Chile.digester.S_ip_in variable */) - (data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */))) + (3.960349301359475e-09) * ((data->localData[0]->realVars[601] /* Chile.digester.r4 variable */)) + DIVISION_SIM((0.0006853095503241148 + (-0.0003421741796374586) * ((data->simulationInfo->realParameter[321] /* Chile.digester.f_li_xb PARAM */)) + (-0.00021) * ((data->simulationInfo->realParameter[326] /* Chile.digester.f_xi_xb PARAM */)) - (((data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */)) * ((data->simulationInfo->realParameter[324] /* Chile.digester.f_si_xb PARAM */)))) * ((data->localData[0]->realVars[589] /* Chile.digester.r13 variable */) + (data->localData[0]->realVars[590] /* Chile.digester.r14 variable */) + (data->localData[0]->realVars[591] /* Chile.digester.r15 variable */) + (data->localData[0]->realVars[592] /* Chile.digester.r16 variable */) + (data->localData[0]->realVars[593] /* Chile.digester.r17 variable */) + (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */) + (data->localData[0]->realVars[595] /* Chile.digester.r19 variable */)),86400.0,"86400.0",equationIndexes) + DIVISION_SIM(((data->localData[0]->realVars[550] /* Chile.digester.i_XC[5] variable */) + (-0.0003421741796374586) * ((data->localData[0]->realVars[530] /* Chile.digester.f_xc[3] variable */)) + ((-(data->localData[0]->realVars[531] /* Chile.digester.f_xc[4] variable */))) * ((data->localData[0]->realVars[555] /* Chile.digester.i_XI[5] variable */)) - (((data->localData[0]->realVars[532] /* Chile.digester.f_xc[5] variable */)) * ((data->localData[0]->realVars[545] /* Chile.digester.i_SI[5] variable */)))) * ((data->localData[0]->realVars[585] /* Chile.digester.r1 variable */)),86400.0,"86400.0",equationIndexes) + (-0.03333333333333333) * ((data->localData[0]->realVars[617] /* Chile.digester.rp1 variable */) - (data->localData[0]->realVars[612] /* Chile.digester.rd1 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[618] /* Chile.digester.rp2 variable */) - (data->localData[0]->realVars[613] /* Chile.digester.rd2 variable */)) + (7.931823499121699e-09) * (((-(data->simulationInfo->realParameter[303] /* Chile.digester.Y_ac PARAM */))) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)) - (((data->simulationInfo->realParameter[306] /* Chile.digester.Y_h2 PARAM */)) * ((data->localData[0]->realVars[588] /* Chile.digester.r12 variable */))) - (((data->simulationInfo->realParameter[307] /* Chile.digester.Y_pro PARAM */)) * ((data->localData[0]->realVars[586] /* Chile.digester.r10 variable */))) - (((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[606] /* Chile.digester.r9 variable */))) - (((data->simulationInfo->realParameter[304] /* Chile.digester.Y_c4 PARAM */)) * ((data->localData[0]->realVars[605] /* Chile.digester.r8 variable */))) - (((data->simulationInfo->realParameter[305] /* Chile.digester.Y_fa PARAM */)) * ((data->localData[0]->realVars[604] /* Chile.digester.r7 variable */))) - (((data->simulationInfo->realParameter[308] /* Chile.digester.Y_su PARAM */)) * ((data->localData[0]->realVars[602] /* Chile.digester.r5 variable */))) - (((data->simulationInfo->realParameter[302] /* Chile.digester.Y_aa PARAM */)) * ((data->localData[0]->realVars[603] /* Chile.digester.r6 variable */))));
  TRACE_POP
}
/*
equation index: 3375
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_ac = 0.0009645061728395061 * Chile.digester.Q * (Chile.digester.X_ac_in - Chile.digester.X_ac) + (Chile.digester.Y_ac * Chile.digester.r11 - Chile.digester.r18) / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3375(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3375};
  (data->localData[0]->realVars[116] /* der(Chile.digester.X_ac) STATE_DER */) = (0.0009645061728395061) * (((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * ((data->localData[0]->realVars[471] /* Chile.digester.X_ac_in variable */) - (data->localData[0]->realVars[43] /* Chile.digester.X_ac STATE(1) */))) + DIVISION_SIM(((data->simulationInfo->realParameter[303] /* Chile.digester.Y_ac PARAM */)) * ((data->localData[0]->realVars[587] /* Chile.digester.r11 variable */)) - (data->localData[0]->realVars[594] /* Chile.digester.r18 variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3376
type: SIMPLE_ASSIGN
$cse7 = ADM1_P.Functions.regSign(Chile.digester.X_mag)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3376(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3376};
  (data->localData[0]->realVars[154] /* $cse7 variable */) = omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */));
  TRACE_POP
}
/*
equation index: 3377
type: SIMPLE_ASSIGN
Chile.digester.r_mag = if noEvent($cse7 + 1.0 < 1e-10) then (-1000.0) * Chile.digester.X_mag else 0.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3377(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3377};
  modelica_boolean tmp35;
  tmp35 = Less((data->localData[0]->realVars[154] /* $cse7 variable */) + 1.0,1e-10);
  (data->localData[0]->realVars[609] /* Chile.digester.r_mag variable */) = (tmp35?(-1000.0) * ((data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */)):0.0);
  TRACE_POP
}
/*
equation index: 3378
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_mag = Chile.digester.Q * (8.333333333333333e-05 - 83.33333333333333 * Chile.digester.X_mag) / 86400.0 + 0.01666666666666667 * Chile.digester.rp4 + (-0.01666666666666667) * Chile.digester.rd4 + Chile.digester.r_mag / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3378(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3378};
  (data->localData[0]->realVars[129] /* der(Chile.digester.X_mag) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (8.333333333333333e-05 - ((83.33333333333333) * ((data->localData[0]->realVars[56] /* Chile.digester.X_mag STATE(1) */)))),86400.0,"86400.0",equationIndexes) + (0.01666666666666667) * ((data->localData[0]->realVars[620] /* Chile.digester.rp4 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[615] /* Chile.digester.rd4 variable */)) + DIVISION_SIM((data->localData[0]->realVars[609] /* Chile.digester.r_mag variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3379
type: SIMPLE_ASSIGN
$cse6 = ADM1_P.Functions.regSign(Chile.digester.X_ccm)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3379(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3379};
  (data->localData[0]->realVars[153] /* $cse6 variable */) = omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */));
  TRACE_POP
}
/*
equation index: 3380
type: SIMPLE_ASSIGN
Chile.digester.r_ccm = if noEvent($cse6 + 1.0 < 1e-100) then (-1000.0) * Chile.digester.X_ccm else 0.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3380(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3380};
  modelica_boolean tmp36;
  tmp36 = Less((data->localData[0]->realVars[153] /* $cse6 variable */) + 1.0,1e-100);
  (data->localData[0]->realVars[608] /* Chile.digester.r_ccm variable */) = (tmp36?(-1000.0) * ((data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */)):0.0);
  TRACE_POP
}
/*
equation index: 3381
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_ccm = Chile.digester.Q * (8.333333333333333e-05 - 83.33333333333333 * Chile.digester.X_ccm) / 86400.0 + 0.01666666666666667 * Chile.digester.rp3 + (-0.01666666666666667) * Chile.digester.rd3 + Chile.digester.r_ccm / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3381(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3381};
  (data->localData[0]->realVars[120] /* der(Chile.digester.X_ccm) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (8.333333333333333e-05 - ((83.33333333333333) * ((data->localData[0]->realVars[47] /* Chile.digester.X_ccm STATE(1) */)))),86400.0,"86400.0",equationIndexes) + (0.01666666666666667) * ((data->localData[0]->realVars[619] /* Chile.digester.rp3 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[614] /* Chile.digester.rd3 variable */)) + DIVISION_SIM((data->localData[0]->realVars[608] /* Chile.digester.r_ccm variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3382
type: SIMPLE_ASSIGN
$cse5 = ADM1_P.Functions.regSign(Chile.digester.X_acp)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3382(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3382};
  (data->localData[0]->realVars[152] /* $cse5 variable */) = omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */));
  TRACE_POP
}
/*
equation index: 3383
type: SIMPLE_ASSIGN
Chile.digester.r_acp = if noEvent($cse5 + 1.0 < 1e-100) then (-1000.0) * Chile.digester.X_acp else 0.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3383(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3383};
  modelica_boolean tmp37;
  tmp37 = Less((data->localData[0]->realVars[152] /* $cse5 variable */) + 1.0,1e-100);
  (data->localData[0]->realVars[607] /* Chile.digester.r_acp variable */) = (tmp37?(-1000.0) * ((data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */)):0.0);
  TRACE_POP
}
/*
equation index: 3384
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_acp = Chile.digester.Q * (8.333333333333333e-05 - 83.33333333333333 * Chile.digester.X_acp) / 86400.0 + 0.01666666666666667 * Chile.digester.rp1 + (-0.01666666666666667) * Chile.digester.rd1 + Chile.digester.r_acp / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3384(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3384};
  (data->localData[0]->realVars[117] /* der(Chile.digester.X_acp) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (8.333333333333333e-05 - ((83.33333333333333) * ((data->localData[0]->realVars[44] /* Chile.digester.X_acp STATE(1) */)))),86400.0,"86400.0",equationIndexes) + (0.01666666666666667) * ((data->localData[0]->realVars[617] /* Chile.digester.rp1 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[612] /* Chile.digester.rd1 variable */)) + DIVISION_SIM((data->localData[0]->realVars[607] /* Chile.digester.r_acp variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3385
type: SIMPLE_ASSIGN
$cse4 = ADM1_P.Functions.regSign(Chile.digester.X_stru)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3385(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3385};
  (data->localData[0]->realVars[151] /* $cse4 variable */) = omc_ADM1__P_Functions_regSign(threadData, (data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */));
  TRACE_POP
}
/*
equation index: 3386
type: SIMPLE_ASSIGN
Chile.digester.r_stru = if noEvent($cse4 + 1.0 < 1e-100) then (-1000.0) * Chile.digester.X_stru else 0.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3386(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3386};
  modelica_boolean tmp38;
  tmp38 = Less((data->localData[0]->realVars[151] /* $cse4 variable */) + 1.0,1e-100);
  (data->localData[0]->realVars[610] /* Chile.digester.r_stru variable */) = (tmp38?(-1000.0) * ((data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */)):0.0);
  TRACE_POP
}
/*
equation index: 3387
type: SIMPLE_ASSIGN
$DER.Chile.digester.X_stru = Chile.digester.Q * (8.333333333333333e-05 - 83.33333333333333 * Chile.digester.X_stru) / 86400.0 + 0.01666666666666667 * Chile.digester.rp2 + (-0.01666666666666667) * Chile.digester.rd2 + Chile.digester.r_stru / 86400.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3387(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3387};
  (data->localData[0]->realVars[134] /* der(Chile.digester.X_stru) STATE_DER */) = DIVISION_SIM(((data->localData[0]->realVars[423] /* Chile.digester.Q variable */)) * (8.333333333333333e-05 - ((83.33333333333333) * ((data->localData[0]->realVars[61] /* Chile.digester.X_stru STATE(1) */)))),86400.0,"86400.0",equationIndexes) + (0.01666666666666667) * ((data->localData[0]->realVars[618] /* Chile.digester.rp2 variable */)) + (-0.01666666666666667) * ((data->localData[0]->realVars[613] /* Chile.digester.rd2 variable */)) + DIVISION_SIM((data->localData[0]->realVars[610] /* Chile.digester.r_stru variable */),86400.0,"86400.0",equationIndexes);
  TRACE_POP
}
/*
equation index: 3388
type: SIMPLE_ASSIGN
$whenCondition3 = time >= pre(Chile.comp_slurry.nextTimeEvent)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3388(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3388};
  modelica_boolean tmp39;
  relationhysteresis(data, &tmp39, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1253] /* Chile.comp_slurry.nextTimeEvent DISCRETE */), 10, GreaterEq, GreaterEqZC);
  (data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) = tmp39;
  TRACE_POP
}
/*
equation index: 3389
type: SIMPLE_ASSIGN
Chile.comp_slurry.timeScaled = time
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3389(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3389};
  (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */) = data->localData[0]->timeValue;
  TRACE_POP
}
/*
equation index: 3390
type: WHEN

when {$whenCondition3} then
  Chile.comp_slurry.nextTimeEventScaled = Modelica.Blocks.Tables.Internal.getNextTimeEvent(Chile.comp_slurry.tableID, Chile.comp_slurry.timeScaled);
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3390(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3390};
  if(((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */) = omc_Modelica_Blocks_Tables_Internal_getNextTimeEvent(threadData, (data->simulationInfo->extObjs[1]), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */));
  }
  TRACE_POP
}
/*
equation index: 3391
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[1] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 1, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3391(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3391};
  (data->localData[0]->realVars[217] /* Chile.comp_slurry.y[1] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 1), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3392
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[2] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 2, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3392(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3392};
  (data->localData[0]->realVars[218] /* Chile.comp_slurry.y[2] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 2), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3393
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[3] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 3, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3393(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3393};
  (data->localData[0]->realVars[219] /* Chile.comp_slurry.y[3] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 3), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3394
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[4] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 4, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3394};
  (data->localData[0]->realVars[220] /* Chile.comp_slurry.y[4] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 4), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3395
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[5] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 5, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3395};
  (data->localData[0]->realVars[221] /* Chile.comp_slurry.y[5] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 5), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3396
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[6] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 6, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3396(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3396};
  (data->localData[0]->realVars[222] /* Chile.comp_slurry.y[6] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 6), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3397
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[7] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 7, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3397(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3397};
  (data->localData[0]->realVars[223] /* Chile.comp_slurry.y[7] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 7), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3398
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[8] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 8, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3398(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3398};
  (data->localData[0]->realVars[224] /* Chile.comp_slurry.y[8] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 8), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3399
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[9] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 9, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3399(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3399};
  (data->localData[0]->realVars[225] /* Chile.comp_slurry.y[9] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 9), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3400
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[10] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 10, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3400(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3400};
  (data->localData[0]->realVars[226] /* Chile.comp_slurry.y[10] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 10), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3401
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[11] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 11, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3401(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3401};
  (data->localData[0]->realVars[227] /* Chile.comp_slurry.y[11] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 11), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3402
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[12] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 12, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3402(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3402};
  (data->localData[0]->realVars[228] /* Chile.comp_slurry.y[12] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 12), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3403
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[13] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 13, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3403(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3403};
  (data->localData[0]->realVars[229] /* Chile.comp_slurry.y[13] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 13), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3404
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[14] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 14, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3404(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3404};
  (data->localData[0]->realVars[230] /* Chile.comp_slurry.y[14] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 14), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3405
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[15] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 15, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3405(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3405};
  (data->localData[0]->realVars[231] /* Chile.comp_slurry.y[15] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 15), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3406
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[16] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 16, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3406(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3406};
  (data->localData[0]->realVars[232] /* Chile.comp_slurry.y[16] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 16), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3407
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[17] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 17, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3407(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3407};
  (data->localData[0]->realVars[233] /* Chile.comp_slurry.y[17] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 17), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3408
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[18] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 18, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3408(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3408};
  (data->localData[0]->realVars[234] /* Chile.comp_slurry.y[18] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 18), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3409
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[19] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 19, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3409(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3409};
  (data->localData[0]->realVars[235] /* Chile.comp_slurry.y[19] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 19), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3410
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[20] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 20, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3410(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3410};
  (data->localData[0]->realVars[236] /* Chile.comp_slurry.y[20] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 20), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3411
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[21] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 21, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3411(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3411};
  (data->localData[0]->realVars[237] /* Chile.comp_slurry.y[21] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 21), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3412
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[22] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 22, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3412(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3412};
  (data->localData[0]->realVars[238] /* Chile.comp_slurry.y[22] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 22), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3413
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[23] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 23, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3413(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3413};
  (data->localData[0]->realVars[239] /* Chile.comp_slurry.y[23] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 23), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3414
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[24] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 24, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3414(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3414};
  (data->localData[0]->realVars[240] /* Chile.comp_slurry.y[24] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 24), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3415
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[25] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 25, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3415(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3415};
  (data->localData[0]->realVars[241] /* Chile.comp_slurry.y[25] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 25), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3416
type: SIMPLE_ASSIGN
Chile.comp_slurry.y[26] = Modelica.Blocks.Tables.Internal.getTimeTableValueNoDer(Chile.comp_slurry.tableID, 26, Chile.comp_slurry.timeScaled, Chile.comp_slurry.nextTimeEventScaled, pre(Chile.comp_slurry.nextTimeEventScaled))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3416(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3416};
  (data->localData[0]->realVars[242] /* Chile.comp_slurry.y[26] variable */) = omc_Modelica_Blocks_Tables_Internal_getTimeTableValueNoDer(threadData, (data->simulationInfo->extObjs[1]), ((modelica_integer) 26), (data->localData[0]->realVars[216] /* Chile.comp_slurry.timeScaled variable */), (data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */), (data->simulationInfo->realVarsPre[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */));
  TRACE_POP
}
/*
equation index: 3417
type: WHEN

when {$whenCondition3} then
  Chile.comp_slurry.nextTimeEvent = if Chile.comp_slurry.nextTimeEventScaled < 9.999999999999999e+59 then Chile.comp_slurry.nextTimeEventScaled else 9.999999999999999e+59;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3417(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3417};
  modelica_boolean tmp40;
  if(((data->localData[0]->booleanVars[2] /* $whenCondition3 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[2] /* $whenCondition3 DISCRETE */) /* edge */))
  {
    tmp40 = Less((data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */),9.999999999999999e+59);
    (data->localData[0]->realVars[1253] /* Chile.comp_slurry.nextTimeEvent DISCRETE */) = (tmp40?(data->localData[0]->realVars[1254] /* Chile.comp_slurry.nextTimeEventScaled DISCRETE */):9.999999999999999e+59);
  }
  TRACE_POP
}
/*
equation index: 3418
type: SIMPLE_ASSIGN
tomatosouce_step.y = tomatosouce_step.offset + (if time < tomatosouce_step.startTime then 0.0 else tomatosouce_step.height)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3418(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3418};
  modelica_boolean tmp41;
  relationhysteresis(data, &tmp41, data->localData[0]->timeValue, (data->simulationInfo->realParameter[1259] /* tomatosouce_step.startTime PARAM */), 12, Less, LessZC);
  (data->localData[0]->realVars[1247] /* tomatosouce_step.y variable */) = (data->simulationInfo->realParameter[1258] /* tomatosouce_step.offset PARAM */) + (tmp41?0.0:(data->simulationInfo->realParameter[1257] /* tomatosouce_step.height PARAM */));
  TRACE_POP
}
/*
equation index: 3419
type: SIMPLE_ASSIGN
pump_onoff.sampling_time = 864000.0 / (1e-10 + 1000000.0 * tomatosouce_step.y)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3419(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3419};
  (data->localData[0]->realVars[1246] /* pump_onoff.sampling_time variable */) = DIVISION_SIM(864000.0,1e-10 + (1000000.0) * ((data->localData[0]->realVars[1247] /* tomatosouce_step.y variable */)),"1e-10 + 1000000.0 * tomatosouce_step.y",equationIndexes);
  TRACE_POP
}
/*
equation index: 3420
type: SIMPLE_ASSIGN
$cse9 = ADM1_P.Functions.round(pump_onoff.sampling_time)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3420(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3420};
  (data->localData[0]->realVars[155] /* $cse9 variable */) = omc_ADM1__P_Functions_round(threadData, (data->localData[0]->realVars[1246] /* pump_onoff.sampling_time variable */));
  TRACE_POP
}
/*
equation index: 3421
type: SIMPLE_ASSIGN
$whenCondition2 = time > pre(pump_onoff.tfr_pump) + $cse9
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3421(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3421};
  modelica_boolean tmp42;
  relationhysteresis(data, &tmp42, data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1264] /* pump_onoff.tfr_pump DISCRETE */) + (data->localData[0]->realVars[155] /* $cse9 variable */), 13, Greater, GreaterZC);
  (data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) = tmp42;
  TRACE_POP
}
/*
equation index: 3422
type: WHEN

when {$whenCondition2} then
  pump_onoff.tfr_pump = time;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3422(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3422};
  if(((data->localData[0]->booleanVars[1] /* $whenCondition2 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[1] /* $whenCondition2 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1264] /* pump_onoff.tfr_pump DISCRETE */) = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 3423
type: SIMPLE_ASSIGN
pump_onoff.onoff_load = if abs(time - pump_onoff.tfr_pump) < 60.0 and impulse then 0.0144 else if not impulse then tomatosouce_step.y else 1e-10
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3423(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3423};
  modelica_boolean tmp43;
  relationhysteresis(data, &tmp43, fabs(data->localData[0]->timeValue - (data->localData[0]->realVars[1264] /* pump_onoff.tfr_pump DISCRETE */)), 60.0, 11, Less, LessZC);
  (data->localData[0]->realVars[1245] /* pump_onoff.onoff_load variable */) = ((tmp43 && (data->simulationInfo->booleanParameter[37] /* impulse PARAM */))?0.0144:((!(data->simulationInfo->booleanParameter[37] /* impulse PARAM */))?(data->localData[0]->realVars[1247] /* tomatosouce_step.y variable */):1e-10));
  TRACE_POP
}
/*
equation index: 3424
type: SIMPLE_ASSIGN
$whenCondition1 = sample(1, 0.0, 86400.0)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3424(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3424};
  (data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) = data->simulationInfo->samples[0];
  TRACE_POP
}
/*
equation index: 3425
type: WHEN

when {$whenCondition1} then
  tfr = time;
end when;
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3425(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3425};
  if(((data->localData[0]->booleanVars[0] /* $whenCondition1 DISCRETE */) && !(data->simulationInfo->booleanVarsPre[0] /* $whenCondition1 DISCRETE */) /* edge */))
  {
    (data->localData[0]->realVars[1265] /* tfr DISCRETE */) = data->localData[0]->timeValue;
  }
  TRACE_POP
}
/*
equation index: 3435
type: ALGORITHM

  assert(Manual_flowrates_real.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3435(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3435};
  static const MMC_DEFSTRINGLIT(tmp46,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp47,42,"tableOnFile = true and no table name given");
  static int tmp48 = 0;
  {
    if(!(!stringEqual((data->simulationInfo->stringParameter[11] /* Manual_flowrates_real.tableName PARAM */), MMC_REFSTRINGLIT(tmp46))))
    {
      {
        const char* assert_cond = "(Manual_flowrates_real.tableName <> \"NoName\")";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp47)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp47)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3434
type: ALGORITHM

  assert(Chile.comp_slurry_real.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3434(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3434};
  static const MMC_DEFSTRINGLIT(tmp51,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp52,42,"tableOnFile = true and no table name given");
  static int tmp53 = 0;
  {
    if(!(!stringEqual((data->simulationInfo->stringParameter[5] /* Chile.comp_slurry_real.tableName PARAM */), MMC_REFSTRINGLIT(tmp51))))
    {
      {
        const char* assert_cond = "(Chile.comp_slurry_real.tableName <> \"NoName\")";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp52)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp52)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3433
type: ALGORITHM

  assert(Chile.comp_tomatosouce.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3433(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3433};
  static const MMC_DEFSTRINGLIT(tmp56,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp57,42,"tableOnFile = true and no table name given");
  static int tmp58 = 0;
  {
    if(!(!stringEqual((data->simulationInfo->stringParameter[7] /* Chile.comp_tomatosouce.tableName PARAM */), MMC_REFSTRINGLIT(tmp56))))
    {
      {
        const char* assert_cond = "(Chile.comp_tomatosouce.tableName <> \"NoName\")";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp57)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp57)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3432
type: ALGORITHM

  assert(Chile.comp_slurry.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3432(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3432};
  static const MMC_DEFSTRINGLIT(tmp61,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp62,42,"tableOnFile = true and no table name given");
  static int tmp63 = 0;
  {
    if(!(!stringEqual((data->simulationInfo->stringParameter[3] /* Chile.comp_slurry.tableName PARAM */), MMC_REFSTRINGLIT(tmp61))))
    {
      {
        const char* assert_cond = "(Chile.comp_slurry.tableName <> \"NoName\")";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp62)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp62)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3431
type: ALGORITHM

  assert(Chile.comp_maize.tableName <> "NoName", "tableOnFile = true and no table name given");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3431(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3431};
  static const MMC_DEFSTRINGLIT(tmp66,6,"NoName");
  static const MMC_DEFSTRINGLIT(tmp67,42,"tableOnFile = true and no table name given");
  static int tmp68 = 0;
  {
    if(!(!stringEqual((data->simulationInfo->stringParameter[1] /* Chile.comp_maize.tableName PARAM */), MMC_REFSTRINGLIT(tmp66))))
    {
      {
        const char* assert_cond = "(Chile.comp_maize.tableName <> \"NoName\")";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp67)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Sources.mo",1636,7,1637,54,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp67)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3430
type: ALGORITHM

  assert(Chile.limPID.limiter.uMax >= Chile.limPID.limiter.uMin, "Limiter: Limits must be consistent. However, uMax (=" + String(Chile.limPID.limiter.uMax, 6, 0, true) + ") < uMin (=" + String(Chile.limPID.limiter.uMin, 6, 0, true) + ")");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3430(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3430};
  modelica_boolean tmp69;
  static const MMC_DEFSTRINGLIT(tmp70,52,"Limiter: Limits must be consistent. However, uMax (=");
  modelica_string tmp71;
  modelica_metatype tmpMeta72;
  static const MMC_DEFSTRINGLIT(tmp73,11,") < uMin (=");
  modelica_metatype tmpMeta74;
  modelica_string tmp75;
  modelica_metatype tmpMeta76;
  modelica_metatype tmpMeta77;
  static int tmp78 = 0;
  {
    tmp69 = GreaterEq((data->simulationInfo->realParameter[519] /* Chile.limPID.limiter.uMax PARAM */),(data->simulationInfo->realParameter[520] /* Chile.limPID.limiter.uMin PARAM */));
    if(!tmp69)
    {
      tmp71 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[519] /* Chile.limPID.limiter.uMax PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta72 = stringAppend(MMC_REFSTRINGLIT(tmp70),tmp71);
      tmpMeta74 = stringAppend(tmpMeta72,MMC_REFSTRINGLIT(tmp73));
      tmp75 = modelica_real_to_modelica_string((data->simulationInfo->realParameter[520] /* Chile.limPID.limiter.uMin PARAM */), ((modelica_integer) 6), ((modelica_integer) 0), 1);
      tmpMeta76 = stringAppend(tmpMeta74,tmp75);
      tmpMeta77 = stringAppend(tmpMeta76,(modelica_string) mmc_strings_len1[41]);
      {
        const char* assert_cond = "(Chile.limPID.limiter.uMax >= Chile.limPID.limiter.uMin)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta77));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om/Blocks/Nonlinear.mo",19,9,20,65,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta77));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3429
type: ALGORITHM

  assert(Chile.digester.outlet.nW == Chile.mass_to_info.inlet.nW, "Connected constants/parameters must be equal");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3429(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3429};
  static const MMC_DEFSTRINGLIT(tmp80,44,"Connected constants/parameters must be equal");
  static int tmp81 = 0;
  {
    if(!((data->simulationInfo->integerParameter[123] /* Chile.digester.outlet.nW PARAM */) == (data->simulationInfo->integerParameter[134] /* Chile.mass_to_info.inlet.nW PARAM */)))
    {
      {
        const char* assert_cond = "(Chile.digester.outlet.nW == Chile.mass_to_info.inlet.nW)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5913,5,5914,63,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp80)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5913,5,5914,63,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp80)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3428
type: ALGORITHM

  assert(Chile.slurry.outlet.nW == Chile.maize.outlet.nW, "Connected constants/parameters must be equal");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3428(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3428};
  static const MMC_DEFSTRINGLIT(tmp83,44,"Connected constants/parameters must be equal");
  static int tmp84 = 0;
  {
    if(!((data->simulationInfo->integerParameter[142] /* Chile.slurry.outlet.nW PARAM */) == (data->simulationInfo->integerParameter[133] /* Chile.maize.outlet.nW PARAM */)))
    {
      {
        const char* assert_cond = "(Chile.slurry.outlet.nW == Chile.maize.outlet.nW)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp83)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp83)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3427
type: ALGORITHM

  assert(Chile.slurry.outlet.nW == Chile.tomatosouce.outlet.nW, "Connected constants/parameters must be equal");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3427(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3427};
  static const MMC_DEFSTRINGLIT(tmp86,44,"Connected constants/parameters must be equal");
  static int tmp87 = 0;
  {
    if(!((data->simulationInfo->integerParameter[142] /* Chile.slurry.outlet.nW PARAM */) == (data->simulationInfo->integerParameter[146] /* Chile.tomatosouce.outlet.nW PARAM */)))
    {
      {
        const char* assert_cond = "(Chile.slurry.outlet.nW == Chile.tomatosouce.outlet.nW)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp86)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp86)));
        }
      }
    }
  }
  TRACE_POP
}
/*
equation index: 3426
type: ALGORITHM

  assert(Chile.slurry.outlet.nW == Chile.digester.inlet.nW, "Connected constants/parameters must be equal");
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3426(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3426};
  static const MMC_DEFSTRINGLIT(tmp89,44,"Connected constants/parameters must be equal");
  static int tmp90 = 0;
  {
    if(!((data->simulationInfo->integerParameter[142] /* Chile.slurry.outlet.nW PARAM */) == (data->simulationInfo->integerParameter[120] /* Chile.digester.inlet.nW PARAM */)))
    {
      {
        const char* assert_cond = "(Chile.slurry.outlet.nW == Chile.digester.inlet.nW)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp89)));
          data->simulationInfo->needToReThrow = 1;
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",5889,5,5890,55,0};
          omc_assert_withEquationIndexes(threadData, info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(MMC_REFSTRINGLIT(tmp89)));
        }
      }
    }
  }
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_DAE);
#endif

  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  ADM1_P_Chile_OL_MPC_functionLocalKnownVars(data, threadData);
  ADM1_P_Chile_OL_MPC_eqFunction_2603(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2604(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2605(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2606(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2607(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2608(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2609(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2610(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2611(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2612(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2613(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2614(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2615(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2616(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2617(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2618(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2619(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2620(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2621(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2622(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2623(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2624(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2625(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2626(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2627(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2628(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2629(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2630(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2631(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2632(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2633(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2634(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2635(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2636(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2637(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2638(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2639(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2640(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2641(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2642(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2643(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2644(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2645(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2646(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2647(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2648(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2649(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2650(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2651(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2652(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2653(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2654(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2655(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2656(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2657(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2658(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2659(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2660(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2661(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2662(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2663(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2664(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2665(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2666(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2667(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2668(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2669(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2670(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2671(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2672(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2673(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2734(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2735(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2736(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2737(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2738(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2739(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2741(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2742(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2743(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2744(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2745(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2746(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2747(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2748(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2749(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2750(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2751(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2752(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2753(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2754(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2755(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2756(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2757(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2758(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2759(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2760(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2761(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2762(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2763(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2764(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2765(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2766(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2767(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2768(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2769(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2770(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2771(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2772(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2773(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2774(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2775(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2776(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2777(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2778(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2779(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2780(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2781(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2782(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2783(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2784(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2785(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2786(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2787(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2788(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2789(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2790(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2791(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2792(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2793(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2794(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2795(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2796(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2797(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2798(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2799(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2800(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2801(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2802(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2803(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2804(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2805(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2806(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2807(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2808(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2809(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2810(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2811(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2812(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2813(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2814(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2815(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2816(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2817(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2818(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2819(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2820(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2821(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2822(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2823(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2824(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2825(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2826(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2827(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2828(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2829(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2830(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2831(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2832(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2833(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2834(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2835(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2836(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2837(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2838(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2839(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2840(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2841(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2842(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2843(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2844(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2845(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2846(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2847(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2848(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2849(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2850(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2851(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2852(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2853(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2854(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2855(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2856(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2857(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2858(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2859(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2860(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2861(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2862(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2863(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2864(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2865(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2866(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2867(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2868(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2869(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2870(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2871(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2872(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2873(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2874(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2875(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2876(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2877(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2878(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2879(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2880(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2881(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2882(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2883(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2884(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2885(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2886(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2887(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2888(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2889(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2890(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2891(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2892(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2893(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2894(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2895(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2896(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2897(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2898(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2899(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2900(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2901(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2902(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2903(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2904(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2905(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2906(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2907(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2908(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2909(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2910(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2911(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2912(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2913(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2914(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2915(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2916(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2917(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2918(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2919(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2920(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2921(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2922(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2923(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2924(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2925(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2926(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2927(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2928(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2929(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2930(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2931(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2932(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2933(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2934(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2935(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2936(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2937(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2938(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2939(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2940(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2941(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2942(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2943(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2944(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2945(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2952(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2953(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2954(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2955(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2956(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2957(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2958(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2959(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2960(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2961(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2962(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2963(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2964(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2965(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2966(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2967(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2968(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2969(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2970(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2971(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2972(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2973(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2974(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2975(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2976(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2977(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2978(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2979(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2980(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2981(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2982(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2983(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2984(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2985(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2986(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2987(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2988(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2989(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2990(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2991(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2992(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2993(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2994(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2995(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2996(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2997(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2998(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_2999(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3000(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3001(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3002(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3003(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3004(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3005(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3006(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3007(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3008(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3009(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3010(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3011(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3012(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3013(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3014(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3015(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3016(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3017(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3018(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3019(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3020(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3021(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3022(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3023(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3024(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3025(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3026(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3027(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3028(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3029(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3030(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3031(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3032(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3033(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3034(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3035(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3036(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3037(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3038(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3039(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3040(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3041(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3042(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3043(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3044(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3045(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3046(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3047(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3048(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3049(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3050(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3051(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3052(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3053(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3054(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3055(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3056(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3057(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3058(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3059(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3060(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3061(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3062(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3063(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3064(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3065(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3066(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3067(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3068(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3069(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3070(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3077(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3078(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3079(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3080(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3081(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3082(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3083(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3084(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3085(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3086(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3087(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3088(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3089(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3090(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3091(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3092(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3093(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3094(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3095(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3096(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3097(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3098(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3099(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3100(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3101(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3102(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3103(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3104(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3105(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3106(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3107(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3108(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3109(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3110(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3111(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3112(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3113(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3114(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3115(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3116(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3117(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3118(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3119(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3120(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3121(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3122(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3123(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3124(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3125(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3126(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3127(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3128(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3129(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3130(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3131(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3132(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3133(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3134(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3135(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3136(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3137(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3138(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3139(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3140(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3141(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3142(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3143(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3144(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3145(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3146(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3147(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3148(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3149(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3150(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3151(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3152(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3153(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3154(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3155(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3156(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3157(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3158(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3159(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3160(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3161(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3162(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3163(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3164(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3165(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3166(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3167(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3168(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3169(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3170(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3171(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3172(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3173(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3174(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3175(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3176(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3177(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3178(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3179(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3180(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3181(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3182(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3183(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3184(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3185(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3186(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3187(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3188(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3189(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3190(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3191(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3192(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3193(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3194(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3195(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3196(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3197(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3198(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3199(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3200(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3201(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3202(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3203(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3204(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3205(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3206(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3207(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3208(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3215(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3216(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3217(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3218(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3219(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3220(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3221(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3222(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3223(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3224(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3225(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3226(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3227(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3228(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3229(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3230(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3231(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3232(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3233(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3234(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3235(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3236(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3237(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3238(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3239(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3240(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3241(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3242(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3243(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3244(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3245(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3246(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3247(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3248(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3249(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3250(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3251(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3252(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3253(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3254(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3255(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3256(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3257(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3258(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3259(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3260(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3261(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3262(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3263(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3264(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3265(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3266(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3267(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3268(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3269(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3270(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3271(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3272(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3273(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3274(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3275(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3276(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3277(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3278(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3279(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3280(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3281(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3282(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3283(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3284(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3285(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3286(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3287(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3288(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3289(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3290(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3291(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3292(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3293(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3294(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3295(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3296(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3297(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3298(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3299(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3300(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3301(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3302(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3303(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3304(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3305(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3306(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3307(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3308(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3309(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3310(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3311(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3312(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3313(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3314(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3315(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3316(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3317(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3318(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3319(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3320(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3321(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3322(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3323(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3324(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3325(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3326(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3327(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3328(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3329(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3330(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3331(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3332(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3333(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3334(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3335(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3336(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3337(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3338(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3339(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3340(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3341(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3342(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3343(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3344(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3345(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3346(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3347(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3348(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3349(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3350(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3351(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3352(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3353(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3354(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3355(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3356(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3357(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3358(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3359(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3360(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3361(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3362(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3363(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3364(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3365(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3366(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3367(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3368(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3369(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3370(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3371(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3372(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3373(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3374(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3375(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3376(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3377(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3378(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3379(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3380(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3381(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3382(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3383(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3384(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3385(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3386(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3387(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3388(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3389(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3390(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3391(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3392(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3393(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3394(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3395(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3396(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3397(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3398(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3399(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3400(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3401(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3402(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3403(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3404(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3405(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3406(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3407(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3408(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3409(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3410(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3411(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3412(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3413(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3414(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3415(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3416(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3417(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3418(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3419(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3420(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3421(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3422(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3423(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3424(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3425(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3435(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3434(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3433(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3432(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3431(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3430(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3429(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3428(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3427(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3426(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_DAE);
#endif
  TRACE_POP
  return 0;
}


int ADM1_P_Chile_OL_MPC_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


/* forwarded equations */
extern void ADM1_P_Chile_OL_MPC_eqFunction_2615(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2616(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2617(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2618(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2619(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2620(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2621(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2622(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2623(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2624(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2625(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2626(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2627(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2628(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2629(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2630(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2631(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2632(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2633(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2634(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2635(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2637(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2638(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2639(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2640(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2641(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2642(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2643(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2644(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2645(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2646(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2647(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2648(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2649(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2650(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2651(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2652(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2654(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2655(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2672(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2673(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2734(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2736(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2737(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2738(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2739(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2741(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2742(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2743(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2744(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2745(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2746(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2747(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2748(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2749(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2750(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2751(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2752(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2753(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2754(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2755(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2756(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2757(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2758(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2759(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2760(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2761(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2762(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2763(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2764(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2765(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2767(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2768(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2769(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2770(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2771(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2772(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2773(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2774(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2775(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2776(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2777(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2778(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2779(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2780(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2781(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2782(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2783(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2784(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2785(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2787(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2788(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2789(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2790(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2791(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2792(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2793(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2794(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2795(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2796(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2797(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2798(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2799(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2800(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2801(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2810(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2811(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2812(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2813(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2829(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2830(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2831(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2832(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2841(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2842(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2844(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2845(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2846(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2847(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2848(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2849(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2850(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2851(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2852(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2853(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2854(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2855(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2856(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2857(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2858(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2859(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2860(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2861(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2862(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2863(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2864(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2865(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2866(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2868(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2869(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2870(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2871(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2874(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2875(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2876(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2877(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2881(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2883(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2884(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2885(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2886(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2887(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2888(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2889(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2890(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2891(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2892(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2893(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2894(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2895(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2896(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2897(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2899(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2901(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2902(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2904(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2905(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2908(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2909(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2910(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2911(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2912(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2913(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2914(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2915(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2916(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2917(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2918(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2920(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2921(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2922(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2923(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2924(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2925(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2926(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2927(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2928(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2929(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2930(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2931(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2932(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2933(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2934(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2935(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2936(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2937(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2938(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2939(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2940(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2941(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2942(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2943(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2945(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2952(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2954(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2957(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2958(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2959(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2961(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2962(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2963(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2966(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2967(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2968(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2973(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2974(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2975(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2976(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2977(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2978(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2979(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2980(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2981(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2982(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2984(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2985(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2986(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2989(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2990(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2991(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2992(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2993(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2994(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2995(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2996(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2997(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2998(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2999(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3000(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3001(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3002(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3003(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3007(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3008(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3019(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3024(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3026(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3027(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3029(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3030(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3033(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3034(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3035(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3036(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3037(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3038(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3039(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3040(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3041(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3042(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3043(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3045(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3046(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3047(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3048(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3049(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3050(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3051(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3052(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3053(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3054(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3055(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3056(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3057(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3058(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3059(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3060(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3061(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3062(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3063(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3064(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3065(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3066(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3067(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3068(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3070(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3077(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3079(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3082(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3083(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3084(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3086(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3087(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3088(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3091(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3092(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3093(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3098(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3099(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3100(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3101(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3102(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3103(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3104(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3105(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3106(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3107(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3109(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3110(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3111(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3114(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3115(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3116(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3117(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3118(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3119(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3120(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3121(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3122(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3123(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3124(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3125(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3126(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3127(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3128(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3132(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3133(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3144(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3149(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3151(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3152(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3154(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3155(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3158(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3159(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3160(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3161(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3162(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3163(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3164(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3165(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3166(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3167(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3168(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3169(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3170(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3172(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3173(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3174(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3175(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3176(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3177(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3178(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3179(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3180(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3181(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3182(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3183(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3184(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3185(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3186(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3187(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3188(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3189(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3190(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3191(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3192(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3193(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3194(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3195(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3196(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3197(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3198(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3199(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3200(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3201(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3202(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3203(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3204(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3205(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3206(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3208(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3215(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3216(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3218(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3219(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3220(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3223(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3224(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3225(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3226(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3227(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3228(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3230(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3231(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3232(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3233(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3234(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3237(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3239(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3240(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3241(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3242(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3245(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3248(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3249(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3250(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3251(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3252(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3253(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3254(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3255(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3256(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3257(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3259(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3260(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3261(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3262(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3263(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3266(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3267(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3268(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3269(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3270(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3271(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3272(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3273(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3274(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3275(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3276(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3277(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3278(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3279(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3280(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3281(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3282(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3283(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3284(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3285(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3286(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3287(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3288(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3289(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3290(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3291(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3292(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3296(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3297(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3303(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3304(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3306(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3307(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3308(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3309(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3311(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3313(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3314(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3315(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3316(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3317(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3320(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3321(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3322(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3323(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3324(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3330(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3331(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3333(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3334(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3335(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3336(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3337(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3346(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3350(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3354(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3356(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3357(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3358(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3359(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3361(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3364(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3365(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3367(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3368(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3370(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3371(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3372(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3373(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3374(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3375(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3376(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3377(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3378(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3379(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3380(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3381(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3382(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3383(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3384(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3385(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3386(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3387(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_2614(DATA* data, threadData_t *threadData);

static void functionODE_system0(DATA *data, threadData_t *threadData)
{
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2615(data, threadData);
    threadData->lastEquationSolved = 2615;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2616(data, threadData);
    threadData->lastEquationSolved = 2616;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2617(data, threadData);
    threadData->lastEquationSolved = 2617;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2618(data, threadData);
    threadData->lastEquationSolved = 2618;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2619(data, threadData);
    threadData->lastEquationSolved = 2619;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2620(data, threadData);
    threadData->lastEquationSolved = 2620;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2621(data, threadData);
    threadData->lastEquationSolved = 2621;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2622(data, threadData);
    threadData->lastEquationSolved = 2622;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2623(data, threadData);
    threadData->lastEquationSolved = 2623;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2624(data, threadData);
    threadData->lastEquationSolved = 2624;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2625(data, threadData);
    threadData->lastEquationSolved = 2625;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2626(data, threadData);
    threadData->lastEquationSolved = 2626;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2627(data, threadData);
    threadData->lastEquationSolved = 2627;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2628(data, threadData);
    threadData->lastEquationSolved = 2628;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2629(data, threadData);
    threadData->lastEquationSolved = 2629;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2630(data, threadData);
    threadData->lastEquationSolved = 2630;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2631(data, threadData);
    threadData->lastEquationSolved = 2631;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2632(data, threadData);
    threadData->lastEquationSolved = 2632;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2633(data, threadData);
    threadData->lastEquationSolved = 2633;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2634(data, threadData);
    threadData->lastEquationSolved = 2634;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2635(data, threadData);
    threadData->lastEquationSolved = 2635;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2637(data, threadData);
    threadData->lastEquationSolved = 2637;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2638(data, threadData);
    threadData->lastEquationSolved = 2638;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2639(data, threadData);
    threadData->lastEquationSolved = 2639;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2640(data, threadData);
    threadData->lastEquationSolved = 2640;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2641(data, threadData);
    threadData->lastEquationSolved = 2641;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2642(data, threadData);
    threadData->lastEquationSolved = 2642;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2643(data, threadData);
    threadData->lastEquationSolved = 2643;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2644(data, threadData);
    threadData->lastEquationSolved = 2644;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2645(data, threadData);
    threadData->lastEquationSolved = 2645;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2646(data, threadData);
    threadData->lastEquationSolved = 2646;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2647(data, threadData);
    threadData->lastEquationSolved = 2647;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2648(data, threadData);
    threadData->lastEquationSolved = 2648;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2649(data, threadData);
    threadData->lastEquationSolved = 2649;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2650(data, threadData);
    threadData->lastEquationSolved = 2650;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2651(data, threadData);
    threadData->lastEquationSolved = 2651;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2652(data, threadData);
    threadData->lastEquationSolved = 2652;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2654(data, threadData);
    threadData->lastEquationSolved = 2654;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2655(data, threadData);
    threadData->lastEquationSolved = 2655;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2672(data, threadData);
    threadData->lastEquationSolved = 2672;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2673(data, threadData);
    threadData->lastEquationSolved = 2673;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2734(data, threadData);
    threadData->lastEquationSolved = 2734;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2736(data, threadData);
    threadData->lastEquationSolved = 2736;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2737(data, threadData);
    threadData->lastEquationSolved = 2737;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2738(data, threadData);
    threadData->lastEquationSolved = 2738;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2739(data, threadData);
    threadData->lastEquationSolved = 2739;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2741(data, threadData);
    threadData->lastEquationSolved = 2741;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2742(data, threadData);
    threadData->lastEquationSolved = 2742;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2743(data, threadData);
    threadData->lastEquationSolved = 2743;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2744(data, threadData);
    threadData->lastEquationSolved = 2744;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2745(data, threadData);
    threadData->lastEquationSolved = 2745;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2746(data, threadData);
    threadData->lastEquationSolved = 2746;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2747(data, threadData);
    threadData->lastEquationSolved = 2747;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2748(data, threadData);
    threadData->lastEquationSolved = 2748;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2749(data, threadData);
    threadData->lastEquationSolved = 2749;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2750(data, threadData);
    threadData->lastEquationSolved = 2750;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2751(data, threadData);
    threadData->lastEquationSolved = 2751;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2752(data, threadData);
    threadData->lastEquationSolved = 2752;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2753(data, threadData);
    threadData->lastEquationSolved = 2753;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2754(data, threadData);
    threadData->lastEquationSolved = 2754;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2755(data, threadData);
    threadData->lastEquationSolved = 2755;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2756(data, threadData);
    threadData->lastEquationSolved = 2756;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2757(data, threadData);
    threadData->lastEquationSolved = 2757;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2758(data, threadData);
    threadData->lastEquationSolved = 2758;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2759(data, threadData);
    threadData->lastEquationSolved = 2759;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2760(data, threadData);
    threadData->lastEquationSolved = 2760;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2761(data, threadData);
    threadData->lastEquationSolved = 2761;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2762(data, threadData);
    threadData->lastEquationSolved = 2762;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2763(data, threadData);
    threadData->lastEquationSolved = 2763;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2764(data, threadData);
    threadData->lastEquationSolved = 2764;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2765(data, threadData);
    threadData->lastEquationSolved = 2765;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2767(data, threadData);
    threadData->lastEquationSolved = 2767;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2768(data, threadData);
    threadData->lastEquationSolved = 2768;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2769(data, threadData);
    threadData->lastEquationSolved = 2769;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2770(data, threadData);
    threadData->lastEquationSolved = 2770;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2771(data, threadData);
    threadData->lastEquationSolved = 2771;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2772(data, threadData);
    threadData->lastEquationSolved = 2772;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2773(data, threadData);
    threadData->lastEquationSolved = 2773;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2774(data, threadData);
    threadData->lastEquationSolved = 2774;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2775(data, threadData);
    threadData->lastEquationSolved = 2775;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2776(data, threadData);
    threadData->lastEquationSolved = 2776;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2777(data, threadData);
    threadData->lastEquationSolved = 2777;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2778(data, threadData);
    threadData->lastEquationSolved = 2778;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2779(data, threadData);
    threadData->lastEquationSolved = 2779;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2780(data, threadData);
    threadData->lastEquationSolved = 2780;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2781(data, threadData);
    threadData->lastEquationSolved = 2781;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2782(data, threadData);
    threadData->lastEquationSolved = 2782;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2783(data, threadData);
    threadData->lastEquationSolved = 2783;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2784(data, threadData);
    threadData->lastEquationSolved = 2784;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2785(data, threadData);
    threadData->lastEquationSolved = 2785;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2787(data, threadData);
    threadData->lastEquationSolved = 2787;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2788(data, threadData);
    threadData->lastEquationSolved = 2788;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2789(data, threadData);
    threadData->lastEquationSolved = 2789;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2790(data, threadData);
    threadData->lastEquationSolved = 2790;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2791(data, threadData);
    threadData->lastEquationSolved = 2791;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2792(data, threadData);
    threadData->lastEquationSolved = 2792;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2793(data, threadData);
    threadData->lastEquationSolved = 2793;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2794(data, threadData);
    threadData->lastEquationSolved = 2794;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2795(data, threadData);
    threadData->lastEquationSolved = 2795;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2796(data, threadData);
    threadData->lastEquationSolved = 2796;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2797(data, threadData);
    threadData->lastEquationSolved = 2797;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2798(data, threadData);
    threadData->lastEquationSolved = 2798;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2799(data, threadData);
    threadData->lastEquationSolved = 2799;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2800(data, threadData);
    threadData->lastEquationSolved = 2800;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2801(data, threadData);
    threadData->lastEquationSolved = 2801;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2810(data, threadData);
    threadData->lastEquationSolved = 2810;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2811(data, threadData);
    threadData->lastEquationSolved = 2811;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2812(data, threadData);
    threadData->lastEquationSolved = 2812;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2813(data, threadData);
    threadData->lastEquationSolved = 2813;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2829(data, threadData);
    threadData->lastEquationSolved = 2829;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2830(data, threadData);
    threadData->lastEquationSolved = 2830;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2831(data, threadData);
    threadData->lastEquationSolved = 2831;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2832(data, threadData);
    threadData->lastEquationSolved = 2832;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2841(data, threadData);
    threadData->lastEquationSolved = 2841;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2842(data, threadData);
    threadData->lastEquationSolved = 2842;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2844(data, threadData);
    threadData->lastEquationSolved = 2844;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2845(data, threadData);
    threadData->lastEquationSolved = 2845;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2846(data, threadData);
    threadData->lastEquationSolved = 2846;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2847(data, threadData);
    threadData->lastEquationSolved = 2847;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2848(data, threadData);
    threadData->lastEquationSolved = 2848;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2849(data, threadData);
    threadData->lastEquationSolved = 2849;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2850(data, threadData);
    threadData->lastEquationSolved = 2850;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2851(data, threadData);
    threadData->lastEquationSolved = 2851;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2852(data, threadData);
    threadData->lastEquationSolved = 2852;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2853(data, threadData);
    threadData->lastEquationSolved = 2853;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2854(data, threadData);
    threadData->lastEquationSolved = 2854;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2855(data, threadData);
    threadData->lastEquationSolved = 2855;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2856(data, threadData);
    threadData->lastEquationSolved = 2856;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2857(data, threadData);
    threadData->lastEquationSolved = 2857;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2858(data, threadData);
    threadData->lastEquationSolved = 2858;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2859(data, threadData);
    threadData->lastEquationSolved = 2859;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2860(data, threadData);
    threadData->lastEquationSolved = 2860;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2861(data, threadData);
    threadData->lastEquationSolved = 2861;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2862(data, threadData);
    threadData->lastEquationSolved = 2862;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2863(data, threadData);
    threadData->lastEquationSolved = 2863;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2864(data, threadData);
    threadData->lastEquationSolved = 2864;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2865(data, threadData);
    threadData->lastEquationSolved = 2865;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2866(data, threadData);
    threadData->lastEquationSolved = 2866;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2868(data, threadData);
    threadData->lastEquationSolved = 2868;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2869(data, threadData);
    threadData->lastEquationSolved = 2869;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2870(data, threadData);
    threadData->lastEquationSolved = 2870;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2871(data, threadData);
    threadData->lastEquationSolved = 2871;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2874(data, threadData);
    threadData->lastEquationSolved = 2874;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2875(data, threadData);
    threadData->lastEquationSolved = 2875;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2876(data, threadData);
    threadData->lastEquationSolved = 2876;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2877(data, threadData);
    threadData->lastEquationSolved = 2877;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2881(data, threadData);
    threadData->lastEquationSolved = 2881;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2883(data, threadData);
    threadData->lastEquationSolved = 2883;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2884(data, threadData);
    threadData->lastEquationSolved = 2884;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2885(data, threadData);
    threadData->lastEquationSolved = 2885;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2886(data, threadData);
    threadData->lastEquationSolved = 2886;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2887(data, threadData);
    threadData->lastEquationSolved = 2887;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2888(data, threadData);
    threadData->lastEquationSolved = 2888;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2889(data, threadData);
    threadData->lastEquationSolved = 2889;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2890(data, threadData);
    threadData->lastEquationSolved = 2890;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2891(data, threadData);
    threadData->lastEquationSolved = 2891;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2892(data, threadData);
    threadData->lastEquationSolved = 2892;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2893(data, threadData);
    threadData->lastEquationSolved = 2893;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2894(data, threadData);
    threadData->lastEquationSolved = 2894;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2895(data, threadData);
    threadData->lastEquationSolved = 2895;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2896(data, threadData);
    threadData->lastEquationSolved = 2896;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2897(data, threadData);
    threadData->lastEquationSolved = 2897;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2899(data, threadData);
    threadData->lastEquationSolved = 2899;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2901(data, threadData);
    threadData->lastEquationSolved = 2901;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2902(data, threadData);
    threadData->lastEquationSolved = 2902;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2904(data, threadData);
    threadData->lastEquationSolved = 2904;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2905(data, threadData);
    threadData->lastEquationSolved = 2905;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2908(data, threadData);
    threadData->lastEquationSolved = 2908;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2909(data, threadData);
    threadData->lastEquationSolved = 2909;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2910(data, threadData);
    threadData->lastEquationSolved = 2910;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2911(data, threadData);
    threadData->lastEquationSolved = 2911;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2912(data, threadData);
    threadData->lastEquationSolved = 2912;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2913(data, threadData);
    threadData->lastEquationSolved = 2913;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2914(data, threadData);
    threadData->lastEquationSolved = 2914;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2915(data, threadData);
    threadData->lastEquationSolved = 2915;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2916(data, threadData);
    threadData->lastEquationSolved = 2916;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2917(data, threadData);
    threadData->lastEquationSolved = 2917;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2918(data, threadData);
    threadData->lastEquationSolved = 2918;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2920(data, threadData);
    threadData->lastEquationSolved = 2920;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2921(data, threadData);
    threadData->lastEquationSolved = 2921;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2922(data, threadData);
    threadData->lastEquationSolved = 2922;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2923(data, threadData);
    threadData->lastEquationSolved = 2923;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2924(data, threadData);
    threadData->lastEquationSolved = 2924;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2925(data, threadData);
    threadData->lastEquationSolved = 2925;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2926(data, threadData);
    threadData->lastEquationSolved = 2926;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2927(data, threadData);
    threadData->lastEquationSolved = 2927;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2928(data, threadData);
    threadData->lastEquationSolved = 2928;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2929(data, threadData);
    threadData->lastEquationSolved = 2929;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2930(data, threadData);
    threadData->lastEquationSolved = 2930;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2931(data, threadData);
    threadData->lastEquationSolved = 2931;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2932(data, threadData);
    threadData->lastEquationSolved = 2932;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2933(data, threadData);
    threadData->lastEquationSolved = 2933;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2934(data, threadData);
    threadData->lastEquationSolved = 2934;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2935(data, threadData);
    threadData->lastEquationSolved = 2935;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2936(data, threadData);
    threadData->lastEquationSolved = 2936;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2937(data, threadData);
    threadData->lastEquationSolved = 2937;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2938(data, threadData);
    threadData->lastEquationSolved = 2938;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2939(data, threadData);
    threadData->lastEquationSolved = 2939;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2940(data, threadData);
    threadData->lastEquationSolved = 2940;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2941(data, threadData);
    threadData->lastEquationSolved = 2941;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2942(data, threadData);
    threadData->lastEquationSolved = 2942;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2943(data, threadData);
    threadData->lastEquationSolved = 2943;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2945(data, threadData);
    threadData->lastEquationSolved = 2945;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2952(data, threadData);
    threadData->lastEquationSolved = 2952;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2954(data, threadData);
    threadData->lastEquationSolved = 2954;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2957(data, threadData);
    threadData->lastEquationSolved = 2957;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2958(data, threadData);
    threadData->lastEquationSolved = 2958;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2959(data, threadData);
    threadData->lastEquationSolved = 2959;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2961(data, threadData);
    threadData->lastEquationSolved = 2961;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2962(data, threadData);
    threadData->lastEquationSolved = 2962;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2963(data, threadData);
    threadData->lastEquationSolved = 2963;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2966(data, threadData);
    threadData->lastEquationSolved = 2966;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2967(data, threadData);
    threadData->lastEquationSolved = 2967;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2968(data, threadData);
    threadData->lastEquationSolved = 2968;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2973(data, threadData);
    threadData->lastEquationSolved = 2973;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2974(data, threadData);
    threadData->lastEquationSolved = 2974;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2975(data, threadData);
    threadData->lastEquationSolved = 2975;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2976(data, threadData);
    threadData->lastEquationSolved = 2976;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2977(data, threadData);
    threadData->lastEquationSolved = 2977;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2978(data, threadData);
    threadData->lastEquationSolved = 2978;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2979(data, threadData);
    threadData->lastEquationSolved = 2979;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2980(data, threadData);
    threadData->lastEquationSolved = 2980;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2981(data, threadData);
    threadData->lastEquationSolved = 2981;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2982(data, threadData);
    threadData->lastEquationSolved = 2982;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2984(data, threadData);
    threadData->lastEquationSolved = 2984;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2985(data, threadData);
    threadData->lastEquationSolved = 2985;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2986(data, threadData);
    threadData->lastEquationSolved = 2986;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2989(data, threadData);
    threadData->lastEquationSolved = 2989;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2990(data, threadData);
    threadData->lastEquationSolved = 2990;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2991(data, threadData);
    threadData->lastEquationSolved = 2991;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2992(data, threadData);
    threadData->lastEquationSolved = 2992;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2993(data, threadData);
    threadData->lastEquationSolved = 2993;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2994(data, threadData);
    threadData->lastEquationSolved = 2994;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2995(data, threadData);
    threadData->lastEquationSolved = 2995;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2996(data, threadData);
    threadData->lastEquationSolved = 2996;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2997(data, threadData);
    threadData->lastEquationSolved = 2997;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2998(data, threadData);
    threadData->lastEquationSolved = 2998;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2999(data, threadData);
    threadData->lastEquationSolved = 2999;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3000(data, threadData);
    threadData->lastEquationSolved = 3000;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3001(data, threadData);
    threadData->lastEquationSolved = 3001;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3002(data, threadData);
    threadData->lastEquationSolved = 3002;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3003(data, threadData);
    threadData->lastEquationSolved = 3003;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3007(data, threadData);
    threadData->lastEquationSolved = 3007;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3008(data, threadData);
    threadData->lastEquationSolved = 3008;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3019(data, threadData);
    threadData->lastEquationSolved = 3019;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3024(data, threadData);
    threadData->lastEquationSolved = 3024;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3026(data, threadData);
    threadData->lastEquationSolved = 3026;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3027(data, threadData);
    threadData->lastEquationSolved = 3027;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3029(data, threadData);
    threadData->lastEquationSolved = 3029;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3030(data, threadData);
    threadData->lastEquationSolved = 3030;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3033(data, threadData);
    threadData->lastEquationSolved = 3033;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3034(data, threadData);
    threadData->lastEquationSolved = 3034;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3035(data, threadData);
    threadData->lastEquationSolved = 3035;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3036(data, threadData);
    threadData->lastEquationSolved = 3036;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3037(data, threadData);
    threadData->lastEquationSolved = 3037;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3038(data, threadData);
    threadData->lastEquationSolved = 3038;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3039(data, threadData);
    threadData->lastEquationSolved = 3039;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3040(data, threadData);
    threadData->lastEquationSolved = 3040;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3041(data, threadData);
    threadData->lastEquationSolved = 3041;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3042(data, threadData);
    threadData->lastEquationSolved = 3042;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3043(data, threadData);
    threadData->lastEquationSolved = 3043;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3045(data, threadData);
    threadData->lastEquationSolved = 3045;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3046(data, threadData);
    threadData->lastEquationSolved = 3046;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3047(data, threadData);
    threadData->lastEquationSolved = 3047;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3048(data, threadData);
    threadData->lastEquationSolved = 3048;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3049(data, threadData);
    threadData->lastEquationSolved = 3049;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3050(data, threadData);
    threadData->lastEquationSolved = 3050;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3051(data, threadData);
    threadData->lastEquationSolved = 3051;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3052(data, threadData);
    threadData->lastEquationSolved = 3052;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3053(data, threadData);
    threadData->lastEquationSolved = 3053;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3054(data, threadData);
    threadData->lastEquationSolved = 3054;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3055(data, threadData);
    threadData->lastEquationSolved = 3055;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3056(data, threadData);
    threadData->lastEquationSolved = 3056;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3057(data, threadData);
    threadData->lastEquationSolved = 3057;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3058(data, threadData);
    threadData->lastEquationSolved = 3058;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3059(data, threadData);
    threadData->lastEquationSolved = 3059;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3060(data, threadData);
    threadData->lastEquationSolved = 3060;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3061(data, threadData);
    threadData->lastEquationSolved = 3061;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3062(data, threadData);
    threadData->lastEquationSolved = 3062;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3063(data, threadData);
    threadData->lastEquationSolved = 3063;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3064(data, threadData);
    threadData->lastEquationSolved = 3064;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3065(data, threadData);
    threadData->lastEquationSolved = 3065;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3066(data, threadData);
    threadData->lastEquationSolved = 3066;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3067(data, threadData);
    threadData->lastEquationSolved = 3067;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3068(data, threadData);
    threadData->lastEquationSolved = 3068;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3070(data, threadData);
    threadData->lastEquationSolved = 3070;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3077(data, threadData);
    threadData->lastEquationSolved = 3077;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3079(data, threadData);
    threadData->lastEquationSolved = 3079;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3082(data, threadData);
    threadData->lastEquationSolved = 3082;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3083(data, threadData);
    threadData->lastEquationSolved = 3083;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3084(data, threadData);
    threadData->lastEquationSolved = 3084;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3086(data, threadData);
    threadData->lastEquationSolved = 3086;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3087(data, threadData);
    threadData->lastEquationSolved = 3087;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3088(data, threadData);
    threadData->lastEquationSolved = 3088;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3091(data, threadData);
    threadData->lastEquationSolved = 3091;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3092(data, threadData);
    threadData->lastEquationSolved = 3092;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3093(data, threadData);
    threadData->lastEquationSolved = 3093;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3098(data, threadData);
    threadData->lastEquationSolved = 3098;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3099(data, threadData);
    threadData->lastEquationSolved = 3099;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3100(data, threadData);
    threadData->lastEquationSolved = 3100;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3101(data, threadData);
    threadData->lastEquationSolved = 3101;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3102(data, threadData);
    threadData->lastEquationSolved = 3102;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3103(data, threadData);
    threadData->lastEquationSolved = 3103;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3104(data, threadData);
    threadData->lastEquationSolved = 3104;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3105(data, threadData);
    threadData->lastEquationSolved = 3105;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3106(data, threadData);
    threadData->lastEquationSolved = 3106;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3107(data, threadData);
    threadData->lastEquationSolved = 3107;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3109(data, threadData);
    threadData->lastEquationSolved = 3109;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3110(data, threadData);
    threadData->lastEquationSolved = 3110;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3111(data, threadData);
    threadData->lastEquationSolved = 3111;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3114(data, threadData);
    threadData->lastEquationSolved = 3114;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3115(data, threadData);
    threadData->lastEquationSolved = 3115;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3116(data, threadData);
    threadData->lastEquationSolved = 3116;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3117(data, threadData);
    threadData->lastEquationSolved = 3117;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3118(data, threadData);
    threadData->lastEquationSolved = 3118;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3119(data, threadData);
    threadData->lastEquationSolved = 3119;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3120(data, threadData);
    threadData->lastEquationSolved = 3120;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3121(data, threadData);
    threadData->lastEquationSolved = 3121;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3122(data, threadData);
    threadData->lastEquationSolved = 3122;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3123(data, threadData);
    threadData->lastEquationSolved = 3123;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3124(data, threadData);
    threadData->lastEquationSolved = 3124;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3125(data, threadData);
    threadData->lastEquationSolved = 3125;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3126(data, threadData);
    threadData->lastEquationSolved = 3126;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3127(data, threadData);
    threadData->lastEquationSolved = 3127;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3128(data, threadData);
    threadData->lastEquationSolved = 3128;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3132(data, threadData);
    threadData->lastEquationSolved = 3132;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3133(data, threadData);
    threadData->lastEquationSolved = 3133;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3144(data, threadData);
    threadData->lastEquationSolved = 3144;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3149(data, threadData);
    threadData->lastEquationSolved = 3149;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3151(data, threadData);
    threadData->lastEquationSolved = 3151;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3152(data, threadData);
    threadData->lastEquationSolved = 3152;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3154(data, threadData);
    threadData->lastEquationSolved = 3154;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3155(data, threadData);
    threadData->lastEquationSolved = 3155;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3158(data, threadData);
    threadData->lastEquationSolved = 3158;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3159(data, threadData);
    threadData->lastEquationSolved = 3159;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3160(data, threadData);
    threadData->lastEquationSolved = 3160;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3161(data, threadData);
    threadData->lastEquationSolved = 3161;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3162(data, threadData);
    threadData->lastEquationSolved = 3162;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3163(data, threadData);
    threadData->lastEquationSolved = 3163;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3164(data, threadData);
    threadData->lastEquationSolved = 3164;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3165(data, threadData);
    threadData->lastEquationSolved = 3165;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3166(data, threadData);
    threadData->lastEquationSolved = 3166;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3167(data, threadData);
    threadData->lastEquationSolved = 3167;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3168(data, threadData);
    threadData->lastEquationSolved = 3168;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3169(data, threadData);
    threadData->lastEquationSolved = 3169;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3170(data, threadData);
    threadData->lastEquationSolved = 3170;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3172(data, threadData);
    threadData->lastEquationSolved = 3172;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3173(data, threadData);
    threadData->lastEquationSolved = 3173;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3174(data, threadData);
    threadData->lastEquationSolved = 3174;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3175(data, threadData);
    threadData->lastEquationSolved = 3175;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3176(data, threadData);
    threadData->lastEquationSolved = 3176;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3177(data, threadData);
    threadData->lastEquationSolved = 3177;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3178(data, threadData);
    threadData->lastEquationSolved = 3178;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3179(data, threadData);
    threadData->lastEquationSolved = 3179;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3180(data, threadData);
    threadData->lastEquationSolved = 3180;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3181(data, threadData);
    threadData->lastEquationSolved = 3181;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3182(data, threadData);
    threadData->lastEquationSolved = 3182;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3183(data, threadData);
    threadData->lastEquationSolved = 3183;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3184(data, threadData);
    threadData->lastEquationSolved = 3184;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3185(data, threadData);
    threadData->lastEquationSolved = 3185;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3186(data, threadData);
    threadData->lastEquationSolved = 3186;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3187(data, threadData);
    threadData->lastEquationSolved = 3187;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3188(data, threadData);
    threadData->lastEquationSolved = 3188;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3189(data, threadData);
    threadData->lastEquationSolved = 3189;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3190(data, threadData);
    threadData->lastEquationSolved = 3190;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3191(data, threadData);
    threadData->lastEquationSolved = 3191;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3192(data, threadData);
    threadData->lastEquationSolved = 3192;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3193(data, threadData);
    threadData->lastEquationSolved = 3193;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3194(data, threadData);
    threadData->lastEquationSolved = 3194;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3195(data, threadData);
    threadData->lastEquationSolved = 3195;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3196(data, threadData);
    threadData->lastEquationSolved = 3196;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3197(data, threadData);
    threadData->lastEquationSolved = 3197;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3198(data, threadData);
    threadData->lastEquationSolved = 3198;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3199(data, threadData);
    threadData->lastEquationSolved = 3199;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3200(data, threadData);
    threadData->lastEquationSolved = 3200;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3201(data, threadData);
    threadData->lastEquationSolved = 3201;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3202(data, threadData);
    threadData->lastEquationSolved = 3202;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3203(data, threadData);
    threadData->lastEquationSolved = 3203;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3204(data, threadData);
    threadData->lastEquationSolved = 3204;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3205(data, threadData);
    threadData->lastEquationSolved = 3205;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3206(data, threadData);
    threadData->lastEquationSolved = 3206;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3208(data, threadData);
    threadData->lastEquationSolved = 3208;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3215(data, threadData);
    threadData->lastEquationSolved = 3215;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3216(data, threadData);
    threadData->lastEquationSolved = 3216;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3218(data, threadData);
    threadData->lastEquationSolved = 3218;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3219(data, threadData);
    threadData->lastEquationSolved = 3219;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3220(data, threadData);
    threadData->lastEquationSolved = 3220;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3223(data, threadData);
    threadData->lastEquationSolved = 3223;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3224(data, threadData);
    threadData->lastEquationSolved = 3224;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3225(data, threadData);
    threadData->lastEquationSolved = 3225;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3226(data, threadData);
    threadData->lastEquationSolved = 3226;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3227(data, threadData);
    threadData->lastEquationSolved = 3227;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3228(data, threadData);
    threadData->lastEquationSolved = 3228;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3230(data, threadData);
    threadData->lastEquationSolved = 3230;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3231(data, threadData);
    threadData->lastEquationSolved = 3231;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3232(data, threadData);
    threadData->lastEquationSolved = 3232;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3233(data, threadData);
    threadData->lastEquationSolved = 3233;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3234(data, threadData);
    threadData->lastEquationSolved = 3234;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3237(data, threadData);
    threadData->lastEquationSolved = 3237;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3239(data, threadData);
    threadData->lastEquationSolved = 3239;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3240(data, threadData);
    threadData->lastEquationSolved = 3240;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3241(data, threadData);
    threadData->lastEquationSolved = 3241;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3242(data, threadData);
    threadData->lastEquationSolved = 3242;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3245(data, threadData);
    threadData->lastEquationSolved = 3245;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3248(data, threadData);
    threadData->lastEquationSolved = 3248;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3249(data, threadData);
    threadData->lastEquationSolved = 3249;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3250(data, threadData);
    threadData->lastEquationSolved = 3250;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3251(data, threadData);
    threadData->lastEquationSolved = 3251;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3252(data, threadData);
    threadData->lastEquationSolved = 3252;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3253(data, threadData);
    threadData->lastEquationSolved = 3253;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3254(data, threadData);
    threadData->lastEquationSolved = 3254;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3255(data, threadData);
    threadData->lastEquationSolved = 3255;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3256(data, threadData);
    threadData->lastEquationSolved = 3256;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3257(data, threadData);
    threadData->lastEquationSolved = 3257;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3259(data, threadData);
    threadData->lastEquationSolved = 3259;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3260(data, threadData);
    threadData->lastEquationSolved = 3260;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3261(data, threadData);
    threadData->lastEquationSolved = 3261;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3262(data, threadData);
    threadData->lastEquationSolved = 3262;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3263(data, threadData);
    threadData->lastEquationSolved = 3263;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3266(data, threadData);
    threadData->lastEquationSolved = 3266;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3267(data, threadData);
    threadData->lastEquationSolved = 3267;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3268(data, threadData);
    threadData->lastEquationSolved = 3268;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3269(data, threadData);
    threadData->lastEquationSolved = 3269;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3270(data, threadData);
    threadData->lastEquationSolved = 3270;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3271(data, threadData);
    threadData->lastEquationSolved = 3271;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3272(data, threadData);
    threadData->lastEquationSolved = 3272;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3273(data, threadData);
    threadData->lastEquationSolved = 3273;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3274(data, threadData);
    threadData->lastEquationSolved = 3274;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3275(data, threadData);
    threadData->lastEquationSolved = 3275;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3276(data, threadData);
    threadData->lastEquationSolved = 3276;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3277(data, threadData);
    threadData->lastEquationSolved = 3277;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3278(data, threadData);
    threadData->lastEquationSolved = 3278;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3279(data, threadData);
    threadData->lastEquationSolved = 3279;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3280(data, threadData);
    threadData->lastEquationSolved = 3280;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3281(data, threadData);
    threadData->lastEquationSolved = 3281;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3282(data, threadData);
    threadData->lastEquationSolved = 3282;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3283(data, threadData);
    threadData->lastEquationSolved = 3283;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3284(data, threadData);
    threadData->lastEquationSolved = 3284;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3285(data, threadData);
    threadData->lastEquationSolved = 3285;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3286(data, threadData);
    threadData->lastEquationSolved = 3286;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3287(data, threadData);
    threadData->lastEquationSolved = 3287;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3288(data, threadData);
    threadData->lastEquationSolved = 3288;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3289(data, threadData);
    threadData->lastEquationSolved = 3289;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3290(data, threadData);
    threadData->lastEquationSolved = 3290;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3291(data, threadData);
    threadData->lastEquationSolved = 3291;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3292(data, threadData);
    threadData->lastEquationSolved = 3292;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3296(data, threadData);
    threadData->lastEquationSolved = 3296;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3297(data, threadData);
    threadData->lastEquationSolved = 3297;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3303(data, threadData);
    threadData->lastEquationSolved = 3303;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3304(data, threadData);
    threadData->lastEquationSolved = 3304;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3306(data, threadData);
    threadData->lastEquationSolved = 3306;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3307(data, threadData);
    threadData->lastEquationSolved = 3307;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3308(data, threadData);
    threadData->lastEquationSolved = 3308;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3309(data, threadData);
    threadData->lastEquationSolved = 3309;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3311(data, threadData);
    threadData->lastEquationSolved = 3311;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3313(data, threadData);
    threadData->lastEquationSolved = 3313;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3314(data, threadData);
    threadData->lastEquationSolved = 3314;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3315(data, threadData);
    threadData->lastEquationSolved = 3315;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3316(data, threadData);
    threadData->lastEquationSolved = 3316;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3317(data, threadData);
    threadData->lastEquationSolved = 3317;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3320(data, threadData);
    threadData->lastEquationSolved = 3320;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3321(data, threadData);
    threadData->lastEquationSolved = 3321;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3322(data, threadData);
    threadData->lastEquationSolved = 3322;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3323(data, threadData);
    threadData->lastEquationSolved = 3323;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3324(data, threadData);
    threadData->lastEquationSolved = 3324;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3330(data, threadData);
    threadData->lastEquationSolved = 3330;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3331(data, threadData);
    threadData->lastEquationSolved = 3331;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3333(data, threadData);
    threadData->lastEquationSolved = 3333;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3334(data, threadData);
    threadData->lastEquationSolved = 3334;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3335(data, threadData);
    threadData->lastEquationSolved = 3335;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3336(data, threadData);
    threadData->lastEquationSolved = 3336;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3337(data, threadData);
    threadData->lastEquationSolved = 3337;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3346(data, threadData);
    threadData->lastEquationSolved = 3346;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3350(data, threadData);
    threadData->lastEquationSolved = 3350;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3354(data, threadData);
    threadData->lastEquationSolved = 3354;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3356(data, threadData);
    threadData->lastEquationSolved = 3356;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3357(data, threadData);
    threadData->lastEquationSolved = 3357;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3358(data, threadData);
    threadData->lastEquationSolved = 3358;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3359(data, threadData);
    threadData->lastEquationSolved = 3359;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3361(data, threadData);
    threadData->lastEquationSolved = 3361;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3364(data, threadData);
    threadData->lastEquationSolved = 3364;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3365(data, threadData);
    threadData->lastEquationSolved = 3365;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3367(data, threadData);
    threadData->lastEquationSolved = 3367;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3368(data, threadData);
    threadData->lastEquationSolved = 3368;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3370(data, threadData);
    threadData->lastEquationSolved = 3370;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3371(data, threadData);
    threadData->lastEquationSolved = 3371;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3372(data, threadData);
    threadData->lastEquationSolved = 3372;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3373(data, threadData);
    threadData->lastEquationSolved = 3373;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3374(data, threadData);
    threadData->lastEquationSolved = 3374;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3375(data, threadData);
    threadData->lastEquationSolved = 3375;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3376(data, threadData);
    threadData->lastEquationSolved = 3376;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3377(data, threadData);
    threadData->lastEquationSolved = 3377;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3378(data, threadData);
    threadData->lastEquationSolved = 3378;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3379(data, threadData);
    threadData->lastEquationSolved = 3379;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3380(data, threadData);
    threadData->lastEquationSolved = 3380;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3381(data, threadData);
    threadData->lastEquationSolved = 3381;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3382(data, threadData);
    threadData->lastEquationSolved = 3382;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3383(data, threadData);
    threadData->lastEquationSolved = 3383;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3384(data, threadData);
    threadData->lastEquationSolved = 3384;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3385(data, threadData);
    threadData->lastEquationSolved = 3385;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3386(data, threadData);
    threadData->lastEquationSolved = 3386;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_3387(data, threadData);
    threadData->lastEquationSolved = 3387;
  }
  {
    ADM1_P_Chile_OL_MPC_eqFunction_2614(data, threadData);
    threadData->lastEquationSolved = 2614;
  }
}

int ADM1_P_Chile_OL_MPC_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_FUNCTION_ODE);
#endif

  
  data->simulationInfo->callStatistics.functionODE++;
  
  ADM1_P_Chile_OL_MPC_functionLocalKnownVars(data, threadData);
  functionODE_system0(data, threadData);

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_FUNCTION_ODE);
#endif

  TRACE_POP
  return 0;
}

/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "ADM1_P.Chile_OL_MPC_12jac.h"
#include "ADM1_P.Chile_OL_MPC_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks ADM1_P_Chile_OL_MPC_callback = {
   (int (*)(DATA *, threadData_t *, void *)) ADM1_P_Chile_OL_MPC_performSimulation,    /* performSimulation */
   (int (*)(DATA *, threadData_t *, void *)) ADM1_P_Chile_OL_MPC_performQSSSimulation,    /* performQSSSimulation */
   ADM1_P_Chile_OL_MPC_updateContinuousSystem,    /* updateContinuousSystem */
   ADM1_P_Chile_OL_MPC_callExternalObjectDestructors,    /* callExternalObjectDestructors */
   ADM1_P_Chile_OL_MPC_initialNonLinearSystem,    /* initialNonLinearSystem */
   NULL,    /* initialLinearSystem */
   NULL,    /* initialMixedSystem */
   #if !defined(OMC_NO_STATESELECTION)
   ADM1_P_Chile_OL_MPC_initializeStateSets,
   #else
   NULL,
   #endif    /* initializeStateSets */
   ADM1_P_Chile_OL_MPC_initializeDAEmodeData,
   ADM1_P_Chile_OL_MPC_functionODE,
   ADM1_P_Chile_OL_MPC_functionAlgebraics,
   ADM1_P_Chile_OL_MPC_functionDAE,
   ADM1_P_Chile_OL_MPC_functionLocalKnownVars,
   ADM1_P_Chile_OL_MPC_input_function,
   ADM1_P_Chile_OL_MPC_input_function_init,
   ADM1_P_Chile_OL_MPC_input_function_updateStartValues,
   ADM1_P_Chile_OL_MPC_data_function,
   ADM1_P_Chile_OL_MPC_output_function,
   ADM1_P_Chile_OL_MPC_setc_function,
   ADM1_P_Chile_OL_MPC_setb_function,
   ADM1_P_Chile_OL_MPC_function_storeDelayed,
   ADM1_P_Chile_OL_MPC_function_storeSpatialDistribution,
   ADM1_P_Chile_OL_MPC_function_initSpatialDistribution,
   ADM1_P_Chile_OL_MPC_updateBoundVariableAttributes,
   ADM1_P_Chile_OL_MPC_functionInitialEquations,
   1, /* useHomotopy - 0: local homotopy (equidistant lambda), 1: global homotopy (equidistant lambda), 2: new global homotopy approach (adaptive lambda), 3: new local homotopy approach (adaptive lambda)*/
   ADM1_P_Chile_OL_MPC_functionInitialEquations_lambda0,
   ADM1_P_Chile_OL_MPC_functionRemovedInitialEquations,
   ADM1_P_Chile_OL_MPC_updateBoundParameters,
   ADM1_P_Chile_OL_MPC_checkForAsserts,
   ADM1_P_Chile_OL_MPC_function_ZeroCrossingsEquations,
   ADM1_P_Chile_OL_MPC_function_ZeroCrossings,
   ADM1_P_Chile_OL_MPC_function_updateRelations,
   ADM1_P_Chile_OL_MPC_zeroCrossingDescription,
   ADM1_P_Chile_OL_MPC_relationDescription,
   ADM1_P_Chile_OL_MPC_function_initSample,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_A,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_B,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_C,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_D,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_F,
   ADM1_P_Chile_OL_MPC_INDEX_JAC_H,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianA,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianB,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianC,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianD,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianF,
   ADM1_P_Chile_OL_MPC_initialAnalyticJacobianH,
   ADM1_P_Chile_OL_MPC_functionJacA_column,
   ADM1_P_Chile_OL_MPC_functionJacB_column,
   ADM1_P_Chile_OL_MPC_functionJacC_column,
   ADM1_P_Chile_OL_MPC_functionJacD_column,
   ADM1_P_Chile_OL_MPC_functionJacF_column,
   ADM1_P_Chile_OL_MPC_functionJacH_column,
   ADM1_P_Chile_OL_MPC_linear_model_frame,
   ADM1_P_Chile_OL_MPC_linear_model_datarecovery_frame,
   ADM1_P_Chile_OL_MPC_mayer,
   ADM1_P_Chile_OL_MPC_lagrange,
   ADM1_P_Chile_OL_MPC_pickUpBoundsForInputsInOptimization,
   ADM1_P_Chile_OL_MPC_setInputData,
   ADM1_P_Chile_OL_MPC_getTimeGrid,
   ADM1_P_Chile_OL_MPC_symbolicInlineSystem,
   ADM1_P_Chile_OL_MPC_function_initSynchronous,
   ADM1_P_Chile_OL_MPC_function_updateSynchronous,
   ADM1_P_Chile_OL_MPC_function_equationsSynchronous,
   ADM1_P_Chile_OL_MPC_inputNames,
   ADM1_P_Chile_OL_MPC_dataReconciliationInputNames,
   ADM1_P_Chile_OL_MPC_dataReconciliationUnmeasuredVariables,
   NULL,
   NULL,
   NULL,
   -1,
   NULL,
   NULL,
   -1

};

#define _OMC_LIT_RESOURCE_0_name_data "ADM1_P"
#define _OMC_LIT_RESOURCE_0_dir_data "C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_name,6,_OMC_LIT_RESOURCE_0_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir,116,_OMC_LIT_RESOURCE_0_dir_data);

#define _OMC_LIT_RESOURCE_1_name_data "Complex"
#define _OMC_LIT_RESOURCE_1_dir_data "C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Complex 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_name,7,_OMC_LIT_RESOURCE_1_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir,78,_OMC_LIT_RESOURCE_1_dir_data);

#define _OMC_LIT_RESOURCE_2_name_data "Modelica"
#define _OMC_LIT_RESOURCE_2_dir_data "C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_name,8,_OMC_LIT_RESOURCE_2_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir,79,_OMC_LIT_RESOURCE_2_dir_data);

#define _OMC_LIT_RESOURCE_3_name_data "ModelicaServices"
#define _OMC_LIT_RESOURCE_3_dir_data "C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/ModelicaServices 4.0.0+maint.om"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_name,16,_OMC_LIT_RESOURCE_3_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir,87,_OMC_LIT_RESOURCE_3_dir_data);

#define _OMC_LIT_RESOURCE_4_name_data "Modelica_LinearSystems2"
#define _OMC_LIT_RESOURCE_4_dir_data "C:/Users/lenovo/AppData/Roaming/.openmodelica/libraries/Modelica_LinearSystems2 2.4.0"
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_name,23,_OMC_LIT_RESOURCE_4_name_data);
static const MMC_DEFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir,85,_OMC_LIT_RESOURCE_4_dir_data);

static const MMC_DEFSTRUCTLIT(_OMC_LIT_RESOURCES,10,MMC_ARRAY_TAG) {MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_0_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_1_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_2_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_3_dir), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_name), MMC_REFSTRINGLIT(_OMC_LIT_RESOURCE_4_dir)}};
void ADM1_P_Chile_OL_MPC_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  threadData->localRoots[LOCAL_ROOT_SIMULATION_DATA] = data;
  data->callback = &ADM1_P_Chile_OL_MPC_callback;
  OpenModelica_updateUriMapping(threadData, MMC_REFSTRUCTLIT(_OMC_LIT_RESOURCES));
  data->modelData->modelName = "ADM1_P.Chile_OL_MPC";
  data->modelData->modelFilePrefix = "ADM1_P.Chile_OL_MPC";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline";
  data->modelData->modelGUID = "{01ae6d3e-f4fd-4eb0-8498-7a471f7054f1}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "ADM1_P.Chile_OL_MPC_init.c"
    ;
  static const char contents_info[] =
    #include "ADM1_P.Chile_OL_MPC_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "ADM1_P.Chile_OL_MPC_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "ADM1_P.Chile_OL_MPC_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  data->modelData->modelDataXml.fileName = "ADM1_P.Chile_OL_MPC_info.json";
  data->modelData->resourcesDir = NULL;
  data->modelData->runTestsuite = 0;
  data->modelData->nStates = 73;
  data->modelData->nVariablesReal = 1266;
  data->modelData->nDiscreteReal = 15;
  data->modelData->nVariablesInteger = 1;
  data->modelData->nVariablesBoolean = 10;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 1282;
  data->modelData->nParametersInteger = 161;
  data->modelData->nParametersBoolean = 41;
  data->modelData->nParametersString = 12;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  data->modelData->nAliasReal = 450;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  data->modelData->nZeroCrossings = 15;
  data->modelData->nSamples = 1;
  data->modelData->nRelations = 14;
  data->modelData->nMathEvents = 1;
  data->modelData->nExtObjs = 6;
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 12;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 4988;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 13;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 16;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  data->modelData->nDelayExpressions = 0;
  data->modelData->nBaseClocks = 0;
  data->modelData->nSpatialDistributions = 0;
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
  data->modelData->nSetcVars = 0;
  data->modelData->ndataReconVars = 0;
  data->modelData->nSetbVars = 0;
  data->modelData->nRelatedBoundaryConditions = 0;
  data->modelData->linearizationDumpLanguage = OMC_LINEARIZE_DUMP_LANGUAGE_MODELICA;
}

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  /*
    Set the error functions to be used for simulation.
    The default value for them is 'functions' version. Change it here to 'simulation' versions
  */
  omc_assert = omc_assert_simulation;
  omc_assert_withEquationIndexes = omc_assert_simulation_withEquationIndexes;

  omc_assert_warning_withEquationIndexes = omc_assert_warning_simulation_withEquationIndexes;
  omc_assert_warning = omc_assert_warning_simulation;
  omc_terminate = omc_terminate_simulation;
  omc_throw = omc_throw_simulation;

  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    ADM1_P_Chile_OL_MPC_setupDataStruc(&data, threadData);
    res = _main_initRuntimeAndSimulation(argc, argv, &data, threadData);
    if(res == 0) {
      res = _main_SimulationRuntime(argc, argv, &data, threadData);
    }
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

#ifdef __cplusplus
}
#endif


