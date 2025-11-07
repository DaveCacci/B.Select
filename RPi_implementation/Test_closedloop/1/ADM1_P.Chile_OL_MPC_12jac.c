/* Jacobians 16 */
#include "ADM1_P.Chile_OL_MPC_model.h"
#include "ADM1_P.Chile_OL_MPC_12jac.h"
#include "simulation/jacobian_util.h"
#include "util/omc_file.h"
/* constant equations */
/* dynamic equations */

/*
equation index: 397
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 = if Chile.maize.liquid == false then 0.0 else Chile.maize.S_hco3.SeedNLSJac2 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) * Chile.maize.Ka_co2 / Chile.maize.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_397(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,397};
  modelica_real tmp1;
  modelica_boolean tmp2;
  modelica_real tmp3;
  tmp2 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
  if(tmp2)
  {
    tmp3 = 0.0;
  }
  else
  {
    tmp1 = (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */);
    tmp3 = DIVISION(((jacobian->seedVars[0] /* Chile.maize.S_hco3.SeedNLSJac2 SEED_VAR */) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"))) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(tmp1 * tmp1),"Chile.maize.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_DIFF_VAR */ = tmp3;
  TRACE_POP
}

/*
equation index: 398
type: SIMPLE_ASSIGN
Chile.maize.S_co3.$pDERNLSJac2.dummyVarNLSJac2 = Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_398(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,398};
  modelica_real tmp4;
  tmp4 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  jacobian->tmpVars[1] /* Chile.maize.S_co3.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION((tmp4 * tmp4),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2") + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 399
type: SIMPLE_ASSIGN
$res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 = (if noEvent(0.0 > (if Chile.maize.liquid == false then Chile.maize.outlet.S_ic * Chile.maize.Ka_co2 / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) else Chile.maize.Alk_mol - (Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam) - Chile.maize.S_oh - Chile.maize.S_nh3 + Chile.maize.S_h - Chile.maize.S_hpo4 - 2.0 * Chile.maize.S_po4 + Chile.maize.S_h3po4 - 2.0 * Chile.maize.S_co3)) then 0.0 else if Chile.maize.liquid == false then Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 * Chile.maize.Ka_co2 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0 else (-2.0) * Chile.maize.S_co3.$pDERNLSJac2.dummyVarNLSJac2) - Chile.maize.S_hco3.SeedNLSJac2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_399(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,399};
  modelica_boolean tmp6;
  modelica_real tmp8;
  modelica_boolean tmp9;
  modelica_real tmp10;
  modelica_boolean tmp11;
  modelica_real tmp12;
  tmp6 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h"):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)))));
  tmp11 = (modelica_boolean)tmp6;
  if(tmp11)
  {
    tmp12 = 0.0;
  }
  else
  {
    tmp9 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
    if(tmp9)
    {
      tmp8 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h");
      tmp10 = DIVISION(((jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */))) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h")),(tmp8 * tmp8),"(Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0");
    }
    else
    {
      tmp10 = (-2.0) * (jacobian->tmpVars[1] /* Chile.maize.S_co3.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_DIFF_VAR */);
    }
    tmp12 = tmp10;
  }
  jacobian->resultVars[0] /* $res_NLSJac2_1.$pDERNLSJac2.dummyVarNLSJac2 JACOBIAN_VAR */ = tmp12 - jacobian->seedVars[0] /* Chile.maize.S_hco3.SeedNLSJac2 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac2_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac2;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac2;
  ADM1_P_Chile_OL_MPC_eqFunction_397(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_398(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_399(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 520
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 = if Chile.tomatosouce.liquid == false then 0.0 else Chile.tomatosouce.S_hco3.SeedNLSJac3 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_520(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,520};
  modelica_real tmp14;
  modelica_boolean tmp15;
  modelica_real tmp16;
  tmp15 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
  if(tmp15)
  {
    tmp16 = 0.0;
  }
  else
  {
    tmp14 = (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */);
    tmp16 = DIVISION(((jacobian->seedVars[0] /* Chile.tomatosouce.S_hco3.SeedNLSJac3 SEED_VAR */) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"))) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(tmp14 * tmp14),"Chile.tomatosouce.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_DIFF_VAR */ = tmp16;
  TRACE_POP
}

/*
equation index: 521
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3.$pDERNLSJac3.dummyVarNLSJac3 = Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_521(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,521};
  modelica_real tmp17;
  tmp17 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  jacobian->tmpVars[1] /* Chile.tomatosouce.S_co3.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION((tmp17 * tmp17),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2") + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 522
type: SIMPLE_ASSIGN
$res_NLSJac3_1.$pDERNLSJac3.dummyVarNLSJac3 = (if noEvent(0.0 > (if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_co2 / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) else Chile.tomatosouce.Alk_mol - (Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam) - Chile.tomatosouce.S_oh - Chile.tomatosouce.S_nh3 + Chile.tomatosouce.S_h - Chile.tomatosouce.S_hpo4 - 2.0 * Chile.tomatosouce.S_po4 + Chile.tomatosouce.S_h3po4 - 2.0 * Chile.tomatosouce.S_co3)) then 0.0 else if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 * Chile.tomatosouce.Ka_co2 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0 else (-2.0) * Chile.tomatosouce.S_co3.$pDERNLSJac3.dummyVarNLSJac3) - Chile.tomatosouce.S_hco3.SeedNLSJac3
*/
void ADM1_P_Chile_OL_MPC_eqFunction_522(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,522};
  modelica_boolean tmp19;
  modelica_real tmp21;
  modelica_boolean tmp22;
  modelica_real tmp23;
  modelica_boolean tmp24;
  modelica_real tmp25;
  tmp19 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h"):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)))));
  tmp24 = (modelica_boolean)tmp19;
  if(tmp24)
  {
    tmp25 = 0.0;
  }
  else
  {
    tmp22 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
    if(tmp22)
    {
      tmp21 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h");
      tmp23 = DIVISION(((jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */))) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h")),(tmp21 * tmp21),"(Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0");
    }
    else
    {
      tmp23 = (-2.0) * (jacobian->tmpVars[1] /* Chile.tomatosouce.S_co3.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_DIFF_VAR */);
    }
    tmp25 = tmp23;
  }
  jacobian->resultVars[0] /* $res_NLSJac3_1.$pDERNLSJac3.dummyVarNLSJac3 JACOBIAN_VAR */ = tmp25 - jacobian->seedVars[0] /* Chile.tomatosouce.S_hco3.SeedNLSJac3 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac3_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac3;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac3_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac3;
  ADM1_P_Chile_OL_MPC_eqFunction_520(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_521(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_522(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 643
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 = if Chile.slurry.liquid == false then 0.0 else Chile.slurry.S_hco3.SeedNLSJac4 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) * Chile.slurry.Ka_co2 / Chile.slurry.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_643(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,643};
  modelica_real tmp27;
  modelica_boolean tmp28;
  modelica_real tmp29;
  tmp28 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
  if(tmp28)
  {
    tmp29 = 0.0;
  }
  else
  {
    tmp27 = (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */);
    tmp29 = DIVISION(((jacobian->seedVars[0] /* Chile.slurry.S_hco3.SeedNLSJac4 SEED_VAR */) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"))) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(tmp27 * tmp27),"Chile.slurry.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */ = tmp29;
  TRACE_POP
}

/*
equation index: 644
type: SIMPLE_ASSIGN
Chile.slurry.S_co3.$pDERNLSJac4.dummyVarNLSJac4 = Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_644(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,644};
  modelica_real tmp30;
  tmp30 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  jacobian->tmpVars[1] /* Chile.slurry.S_co3.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION((tmp30 * tmp30),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2") + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 645
type: SIMPLE_ASSIGN
$res_NLSJac4_1.$pDERNLSJac4.dummyVarNLSJac4 = (if noEvent(0.0 > (if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic * Chile.slurry.Ka_co2 / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) else Chile.slurry.Alk_mol - (Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam) - Chile.slurry.S_oh - Chile.slurry.S_nh3 + Chile.slurry.S_h - Chile.slurry.S_hpo4 - 2.0 * Chile.slurry.S_po4 + Chile.slurry.S_h3po4 - 2.0 * Chile.slurry.S_co3)) then 0.0 else if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 * Chile.slurry.Ka_co2 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0 else (-2.0) * Chile.slurry.S_co3.$pDERNLSJac4.dummyVarNLSJac4) - Chile.slurry.S_hco3.SeedNLSJac4
*/
void ADM1_P_Chile_OL_MPC_eqFunction_645(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,645};
  modelica_boolean tmp32;
  modelica_real tmp34;
  modelica_boolean tmp35;
  modelica_real tmp36;
  modelica_boolean tmp37;
  modelica_real tmp38;
  tmp32 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h"):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)))));
  tmp37 = (modelica_boolean)tmp32;
  if(tmp37)
  {
    tmp38 = 0.0;
  }
  else
  {
    tmp35 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
    if(tmp35)
    {
      tmp34 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h");
      tmp36 = DIVISION(((jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */))) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h")),(tmp34 * tmp34),"(Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0");
    }
    else
    {
      tmp36 = (-2.0) * (jacobian->tmpVars[1] /* Chile.slurry.S_co3.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_DIFF_VAR */);
    }
    tmp38 = tmp36;
  }
  jacobian->resultVars[0] /* $res_NLSJac4_1.$pDERNLSJac4.dummyVarNLSJac4 JACOBIAN_VAR */ = tmp38 - jacobian->seedVars[0] /* Chile.slurry.S_hco3.SeedNLSJac4 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac4_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac4;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac4_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac4;
  ADM1_P_Chile_OL_MPC_eqFunction_643(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_644(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_645(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 1703
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 = if Chile.maize.liquid == false then 0.0 else Chile.maize.S_hco3.SeedNLSJac7 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) * Chile.maize.Ka_co2 / Chile.maize.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1703(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,1703};
  modelica_real tmp40;
  modelica_boolean tmp41;
  modelica_real tmp42;
  tmp41 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
  if(tmp41)
  {
    tmp42 = 0.0;
  }
  else
  {
    tmp40 = (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */);
    tmp42 = DIVISION(((jacobian->seedVars[0] /* Chile.maize.S_hco3.SeedNLSJac7 SEED_VAR */) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"))) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(tmp40 * tmp40),"Chile.maize.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_DIFF_VAR */ = tmp42;
  TRACE_POP
}

/*
equation index: 1704
type: SIMPLE_ASSIGN
Chile.maize.S_co3.$pDERNLSJac7.dummyVarNLSJac7 = Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1704(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,1704};
  modelica_real tmp43;
  tmp43 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  jacobian->tmpVars[1] /* Chile.maize.S_co3.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION((tmp43 * tmp43),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2") + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 1705
type: SIMPLE_ASSIGN
$res_NLSJac7_1.$pDERNLSJac7.dummyVarNLSJac7 = (if noEvent(0.0 > (if Chile.maize.liquid == false then Chile.maize.outlet.S_ic * Chile.maize.Ka_co2 / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) else Chile.maize.Alk_mol - (Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam) - Chile.maize.S_oh - Chile.maize.S_nh3 + Chile.maize.S_h - Chile.maize.S_hpo4 - 2.0 * Chile.maize.S_po4 + Chile.maize.S_h3po4 - 2.0 * Chile.maize.S_co3)) then 0.0 else if Chile.maize.liquid == false then Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 * Chile.maize.Ka_co2 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0 else (-2.0) * Chile.maize.S_co3.$pDERNLSJac7.dummyVarNLSJac7) - Chile.maize.S_hco3.SeedNLSJac7
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1705(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,1705};
  modelica_boolean tmp45;
  modelica_real tmp47;
  modelica_boolean tmp48;
  modelica_real tmp49;
  modelica_boolean tmp50;
  modelica_real tmp51;
  tmp45 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h"):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)))));
  tmp50 = (modelica_boolean)tmp45;
  if(tmp50)
  {
    tmp51 = 0.0;
  }
  else
  {
    tmp48 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
    if(tmp48)
    {
      tmp47 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h");
      tmp49 = DIVISION(((jacobian->tmpVars[0] /* Chile.maize.outlet.S_ic.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */))) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h")),(tmp47 * tmp47),"(Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0");
    }
    else
    {
      tmp49 = (-2.0) * (jacobian->tmpVars[1] /* Chile.maize.S_co3.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_DIFF_VAR */);
    }
    tmp51 = tmp49;
  }
  jacobian->resultVars[0] /* $res_NLSJac7_1.$pDERNLSJac7.dummyVarNLSJac7 JACOBIAN_VAR */ = tmp51 - jacobian->seedVars[0] /* Chile.maize.S_hco3.SeedNLSJac7 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac7_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac7;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac7_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac7;
  ADM1_P_Chile_OL_MPC_eqFunction_1703(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1704(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1705(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 1826
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 = if Chile.tomatosouce.liquid == false then 0.0 else Chile.tomatosouce.S_hco3.SeedNLSJac8 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1826(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,1826};
  modelica_real tmp53;
  modelica_boolean tmp54;
  modelica_real tmp55;
  tmp54 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
  if(tmp54)
  {
    tmp55 = 0.0;
  }
  else
  {
    tmp53 = (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */);
    tmp55 = DIVISION(((jacobian->seedVars[0] /* Chile.tomatosouce.S_hco3.SeedNLSJac8 SEED_VAR */) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"))) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(tmp53 * tmp53),"Chile.tomatosouce.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_DIFF_VAR */ = tmp55;
  TRACE_POP
}

/*
equation index: 1827
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3.$pDERNLSJac8.dummyVarNLSJac8 = Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1827(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,1827};
  modelica_real tmp56;
  tmp56 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  jacobian->tmpVars[1] /* Chile.tomatosouce.S_co3.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION((tmp56 * tmp56),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2") + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 1828
type: SIMPLE_ASSIGN
$res_NLSJac8_1.$pDERNLSJac8.dummyVarNLSJac8 = (if noEvent(0.0 > (if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_co2 / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) else Chile.tomatosouce.Alk_mol - (Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam) - Chile.tomatosouce.S_oh - Chile.tomatosouce.S_nh3 + Chile.tomatosouce.S_h - Chile.tomatosouce.S_hpo4 - 2.0 * Chile.tomatosouce.S_po4 + Chile.tomatosouce.S_h3po4 - 2.0 * Chile.tomatosouce.S_co3)) then 0.0 else if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 * Chile.tomatosouce.Ka_co2 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0 else (-2.0) * Chile.tomatosouce.S_co3.$pDERNLSJac8.dummyVarNLSJac8) - Chile.tomatosouce.S_hco3.SeedNLSJac8
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1828(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,1828};
  modelica_boolean tmp58;
  modelica_real tmp60;
  modelica_boolean tmp61;
  modelica_real tmp62;
  modelica_boolean tmp63;
  modelica_real tmp64;
  tmp58 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h"):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)))));
  tmp63 = (modelica_boolean)tmp58;
  if(tmp63)
  {
    tmp64 = 0.0;
  }
  else
  {
    tmp61 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
    if(tmp61)
    {
      tmp60 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h");
      tmp62 = DIVISION(((jacobian->tmpVars[0] /* Chile.tomatosouce.outlet.S_ic.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */))) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h")),(tmp60 * tmp60),"(Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0");
    }
    else
    {
      tmp62 = (-2.0) * (jacobian->tmpVars[1] /* Chile.tomatosouce.S_co3.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_DIFF_VAR */);
    }
    tmp64 = tmp62;
  }
  jacobian->resultVars[0] /* $res_NLSJac8_1.$pDERNLSJac8.dummyVarNLSJac8 JACOBIAN_VAR */ = tmp64 - jacobian->seedVars[0] /* Chile.tomatosouce.S_hco3.SeedNLSJac8 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac8_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac8;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac8_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac8;
  ADM1_P_Chile_OL_MPC_eqFunction_1826(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1827(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1828(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 1949
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 = if Chile.slurry.liquid == false then 0.0 else Chile.slurry.S_hco3.SeedNLSJac9 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) * Chile.slurry.Ka_co2 / Chile.slurry.Ka_co2 ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1949(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,1949};
  modelica_real tmp66;
  modelica_boolean tmp67;
  modelica_real tmp68;
  tmp67 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
  if(tmp67)
  {
    tmp68 = 0.0;
  }
  else
  {
    tmp66 = (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */);
    tmp68 = DIVISION(((jacobian->seedVars[0] /* Chile.slurry.S_hco3.SeedNLSJac9 SEED_VAR */) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"))) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(tmp66 * tmp66),"Chile.slurry.Ka_co2 ^ 2.0");
  }
  jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_DIFF_VAR */ = tmp68;
  TRACE_POP
}

/*
equation index: 1950
type: SIMPLE_ASSIGN
Chile.slurry.S_co3.$pDERNLSJac9.dummyVarNLSJac9 = Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1950(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,1950};
  modelica_real tmp69;
  tmp69 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  jacobian->tmpVars[1] /* Chile.slurry.S_co3.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_DIFF_VAR */ = (jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_DIFF_VAR */) * (DIVISION((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION((tmp69 * tmp69),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2") + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 1951
type: SIMPLE_ASSIGN
$res_NLSJac9_1.$pDERNLSJac9.dummyVarNLSJac9 = (if noEvent(0.0 > (if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic * Chile.slurry.Ka_co2 / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) else Chile.slurry.Alk_mol - (Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam) - Chile.slurry.S_oh - Chile.slurry.S_nh3 + Chile.slurry.S_h - Chile.slurry.S_hpo4 - 2.0 * Chile.slurry.S_po4 + Chile.slurry.S_h3po4 - 2.0 * Chile.slurry.S_co3)) then 0.0 else if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 * Chile.slurry.Ka_co2 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0 else (-2.0) * Chile.slurry.S_co3.$pDERNLSJac9.dummyVarNLSJac9) - Chile.slurry.S_hco3.SeedNLSJac9
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1951(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,1951};
  modelica_boolean tmp71;
  modelica_real tmp73;
  modelica_boolean tmp74;
  modelica_real tmp75;
  modelica_boolean tmp76;
  modelica_real tmp77;
  tmp71 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h"):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)))));
  tmp76 = (modelica_boolean)tmp71;
  if(tmp76)
  {
    tmp77 = 0.0;
  }
  else
  {
    tmp74 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
    if(tmp74)
    {
      tmp73 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h");
      tmp75 = DIVISION(((jacobian->tmpVars[0] /* Chile.slurry.outlet.S_ic.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */))) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h")),(tmp73 * tmp73),"(Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0");
    }
    else
    {
      tmp75 = (-2.0) * (jacobian->tmpVars[1] /* Chile.slurry.S_co3.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_DIFF_VAR */);
    }
    tmp77 = tmp75;
  }
  jacobian->resultVars[0] /* $res_NLSJac9_1.$pDERNLSJac9.dummyVarNLSJac9 JACOBIAN_VAR */ = tmp77 - jacobian->seedVars[0] /* Chile.slurry.S_hco3.SeedNLSJac9 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac9_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac9;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac9_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac9;
  ADM1_P_Chile_OL_MPC_eqFunction_1949(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1950(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_1951(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 2704
type: SIMPLE_ASSIGN
Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 = 2.0 * Chile.digester.z * Chile.digester.z.SeedNLSJac10
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2704(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,2704};
  jacobian->tmpVars[0] /* Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (2.0) * (((data->localData[0]->realVars[645] /* Chile.digester.z variable */)) * (jacobian->seedVars[1] /* Chile.digester.z.SeedNLSJac10 SEED_VAR */));
  TRACE_POP
}

/*
equation index: 2705
type: SIMPLE_ASSIGN
Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 = if noEvent(Chile.digester.ideality == true) then 0.0 else 10.0 ^ ((-0.51) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I)) * 2.302585092994046 * (-0.51) * (Chile.digester.z.SeedNLSJac10 * (1.0 + Chile.digester.z - Chile.digester.z) / (1.0 + Chile.digester.z) ^ 2.0 - 0.24 * Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2705(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,2705};
  modelica_real tmp79;
  modelica_real tmp80;
  modelica_real tmp81;
  modelica_real tmp82;
  modelica_real tmp83;
  modelica_real tmp84;
  modelica_real tmp85;
  modelica_real tmp86;
  modelica_boolean tmp87;
  modelica_real tmp88;
  tmp87 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp87)
  {
    tmp88 = 0.0;
  }
  else
  {
    tmp79 = 10.0;
    tmp80 = (-0.51) * (DIVISION((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z") - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp79 < 0.0 && tmp80 != 0.0)
    {
      tmp82 = modf(tmp80, &tmp83);
      
      if(tmp82 > 0.5)
      {
        tmp82 -= 1.0;
        tmp83 += 1.0;
      }
      else if(tmp82 < -0.5)
      {
        tmp82 += 1.0;
        tmp83 -= 1.0;
      }
      
      if(fabs(tmp82) < 1e-10)
        tmp81 = pow(tmp79, tmp83);
      else
      {
        tmp85 = modf(1.0/tmp80, &tmp84);
        if(tmp85 > 0.5)
        {
          tmp85 -= 1.0;
          tmp84 += 1.0;
        }
        else if(tmp85 < -0.5)
        {
          tmp85 += 1.0;
          tmp84 -= 1.0;
        }
        if(fabs(tmp85) < 1e-10 && ((unsigned long)tmp84 & 1))
        {
          tmp81 = -pow(-tmp79, tmp82)*pow(tmp79, tmp83);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp79, tmp80);
        }
      }
    }
    else
    {
      tmp81 = pow(tmp79, tmp80);
    }
    if(isnan(tmp81) || isinf(tmp81))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp79, tmp80);
    }tmp86 = 1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
    tmp88 = ((tmp81) * (2.302585092994046)) * ((-0.51) * (DIVISION((jacobian->seedVars[1] /* Chile.digester.z.SeedNLSJac10 SEED_VAR */) * (1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */) - (data->localData[0]->realVars[645] /* Chile.digester.z variable */)),(tmp86 * tmp86),"(1.0 + Chile.digester.z) ^ 2.0") - ((0.24) * (jacobian->tmpVars[0] /* Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */))));
  }
  jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = tmp88;
  TRACE_POP
}

/*
equation index: 2706
type: SIMPLE_ASSIGN
Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 = if noEvent(Chile.digester.ideality == true) then 0.0 else 10.0 ^ ((-2.04) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I)) * 2.302585092994046 * (-2.04) * (Chile.digester.z.SeedNLSJac10 * (1.0 + Chile.digester.z - Chile.digester.z) / (1.0 + Chile.digester.z) ^ 2.0 - 0.24 * Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2706(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,2706};
  modelica_real tmp90;
  modelica_real tmp91;
  modelica_real tmp92;
  modelica_real tmp93;
  modelica_real tmp94;
  modelica_real tmp95;
  modelica_real tmp96;
  modelica_real tmp97;
  modelica_boolean tmp98;
  modelica_real tmp99;
  tmp98 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp98)
  {
    tmp99 = 0.0;
  }
  else
  {
    tmp90 = 10.0;
    tmp91 = (-2.04) * (DIVISION((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z") - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp90 < 0.0 && tmp91 != 0.0)
    {
      tmp93 = modf(tmp91, &tmp94);
      
      if(tmp93 > 0.5)
      {
        tmp93 -= 1.0;
        tmp94 += 1.0;
      }
      else if(tmp93 < -0.5)
      {
        tmp93 += 1.0;
        tmp94 -= 1.0;
      }
      
      if(fabs(tmp93) < 1e-10)
        tmp92 = pow(tmp90, tmp94);
      else
      {
        tmp96 = modf(1.0/tmp91, &tmp95);
        if(tmp96 > 0.5)
        {
          tmp96 -= 1.0;
          tmp95 += 1.0;
        }
        else if(tmp96 < -0.5)
        {
          tmp96 += 1.0;
          tmp95 -= 1.0;
        }
        if(fabs(tmp96) < 1e-10 && ((unsigned long)tmp95 & 1))
        {
          tmp92 = -pow(-tmp90, tmp93)*pow(tmp90, tmp94);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp90, tmp91);
        }
      }
    }
    else
    {
      tmp92 = pow(tmp90, tmp91);
    }
    if(isnan(tmp92) || isinf(tmp92))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp90, tmp91);
    }tmp97 = 1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
    tmp99 = ((tmp92) * (2.302585092994046)) * ((-2.04) * (DIVISION((jacobian->seedVars[1] /* Chile.digester.z.SeedNLSJac10 SEED_VAR */) * (1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */) - (data->localData[0]->realVars[645] /* Chile.digester.z variable */)),(tmp97 * tmp97),"(1.0 + Chile.digester.z) ^ 2.0") - ((0.24) * (jacobian->tmpVars[0] /* Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */))));
  }
  jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = tmp99;
  TRACE_POP
}

/*
equation index: 2707
type: SIMPLE_ASSIGN
Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 = if noEvent(Chile.digester.ideality == true) then 0.0 else 10.0 ^ ((-4.59) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I)) * 2.302585092994046 * (-4.59) * (Chile.digester.z.SeedNLSJac10 * (1.0 + Chile.digester.z - Chile.digester.z) / (1.0 + Chile.digester.z) ^ 2.0 - 0.24 * Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2707(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 3;
  const int equationIndexes[2] = {1,2707};
  modelica_real tmp101;
  modelica_real tmp102;
  modelica_real tmp103;
  modelica_real tmp104;
  modelica_real tmp105;
  modelica_real tmp106;
  modelica_real tmp107;
  modelica_real tmp108;
  modelica_boolean tmp109;
  modelica_real tmp110;
  tmp109 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp109)
  {
    tmp110 = 0.0;
  }
  else
  {
    tmp101 = 10.0;
    tmp102 = (-4.59) * (DIVISION((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z") - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp101 < 0.0 && tmp102 != 0.0)
    {
      tmp104 = modf(tmp102, &tmp105);
      
      if(tmp104 > 0.5)
      {
        tmp104 -= 1.0;
        tmp105 += 1.0;
      }
      else if(tmp104 < -0.5)
      {
        tmp104 += 1.0;
        tmp105 -= 1.0;
      }
      
      if(fabs(tmp104) < 1e-10)
        tmp103 = pow(tmp101, tmp105);
      else
      {
        tmp107 = modf(1.0/tmp102, &tmp106);
        if(tmp107 > 0.5)
        {
          tmp107 -= 1.0;
          tmp106 += 1.0;
        }
        else if(tmp107 < -0.5)
        {
          tmp107 += 1.0;
          tmp106 -= 1.0;
        }
        if(fabs(tmp107) < 1e-10 && ((unsigned long)tmp106 & 1))
        {
          tmp103 = -pow(-tmp101, tmp104)*pow(tmp101, tmp105);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp101, tmp102);
        }
      }
    }
    else
    {
      tmp103 = pow(tmp101, tmp102);
    }
    if(isnan(tmp103) || isinf(tmp103))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp101, tmp102);
    }tmp108 = 1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
    tmp110 = ((tmp103) * (2.302585092994046)) * ((-4.59) * (DIVISION((jacobian->seedVars[1] /* Chile.digester.z.SeedNLSJac10 SEED_VAR */) * (1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */) - (data->localData[0]->realVars[645] /* Chile.digester.z variable */)),(tmp108 * tmp108),"(1.0 + Chile.digester.z) ^ 2.0") - ((0.24) * (jacobian->tmpVars[0] /* Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */))));
  }
  jacobian->tmpVars[3] /* Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = tmp110;
  TRACE_POP
}

/*
equation index: 2708
type: SIMPLE_ASSIGN
Chile.digester.a_hpo4.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.S_ip * Chile.digester.Ka_h3po4 * (Chile.digester.a_h * (-Chile.digester.Ka_h2po4) * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + Chile.digester.Ka_h3po4 * ((2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0 + Chile.digester.Ka_h2po4 * ((Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_bi - Chile.digester.a_h * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0 - Chile.digester.Ka_hpo4 * Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 / Chile.digester.g_tri ^ 2.0))) / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0 + Chile.digester.a_h.SeedNLSJac10 * Chile.digester.Ka_h2po4 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2708(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 4;
  const int equationIndexes[2] = {1,2708};
  modelica_real tmp111;
  modelica_real tmp112;
  modelica_real tmp113;
  modelica_real tmp114;
  modelica_real tmp115;
  modelica_real tmp116;
  modelica_real tmp117;
  modelica_real tmp118;
  modelica_real tmp119;
  modelica_real tmp120;
  tmp111 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp112 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp113 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp114 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  tmp115 = (data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */);
  tmp116 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp117 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp118 = (tmp116 * tmp116 * tmp116) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((tmp117 * tmp117),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi") + DIVISION((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri")));
  tmp119 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp120 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[4] /* Chile.digester.a_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (((-(data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */))) * (DIVISION((3.0) * (((tmp111 * tmp111)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp112 * tmp112)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp113 * tmp113),"Chile.digester.g_mono ^ 2.0") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp114 * tmp114),"Chile.digester.g_bi ^ 2.0") - (((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */)) * (DIVISION(jacobian->tmpVars[3] /* Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */,(tmp115 * tmp115),"Chile.digester.g_tri ^ 2.0"))))),(tmp118 * tmp118),"(Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0"))) + (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */),(tmp119 * tmp119 * tmp119) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((tmp120 * tmp120),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi") + DIVISION((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri"))),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))"))));
  TRACE_POP
}

/*
equation index: 2709
type: SIMPLE_ASSIGN
Chile.digester.a_po4.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.S_ip * Chile.digester.Ka_h3po4 * Chile.digester.Ka_h2po4 * (-Chile.digester.Ka_hpo4) * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + Chile.digester.Ka_h3po4 * ((2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0 + Chile.digester.Ka_h2po4 * ((Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_bi - Chile.digester.a_h * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0 - Chile.digester.Ka_hpo4 * Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 / Chile.digester.g_tri ^ 2.0))) / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2709(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 5;
  const int equationIndexes[2] = {1,2709};
  modelica_real tmp121;
  modelica_real tmp122;
  modelica_real tmp123;
  modelica_real tmp124;
  modelica_real tmp125;
  modelica_real tmp126;
  modelica_real tmp127;
  modelica_real tmp128;
  tmp121 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp122 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp123 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp124 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  tmp125 = (data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */);
  tmp126 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp127 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp128 = (tmp126 * tmp126 * tmp126) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((tmp127 * tmp127),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi") + DIVISION((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri")));
  jacobian->tmpVars[5] /* Chile.digester.a_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (((-(data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */))) * (DIVISION((3.0) * (((tmp121 * tmp121)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp122 * tmp122)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp123 * tmp123),"Chile.digester.g_mono ^ 2.0") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp124 * tmp124),"Chile.digester.g_bi ^ 2.0") - (((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */)) * (DIVISION(jacobian->tmpVars[3] /* Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */,(tmp125 * tmp125),"Chile.digester.g_tri ^ 2.0"))))),(tmp128 * tmp128),"(Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0")))));
  TRACE_POP
}

/*
equation index: 2710
type: SIMPLE_ASSIGN
Chile.digester.a_h2po4.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.S_ip * (Chile.digester.a_h ^ 2.0 * (-Chile.digester.Ka_h3po4) * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + Chile.digester.Ka_h3po4 * ((2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0 + Chile.digester.Ka_h2po4 * ((Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_bi - Chile.digester.a_h * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0 - Chile.digester.Ka_hpo4 * Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 / Chile.digester.g_tri ^ 2.0))) / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0 + 2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.Ka_h3po4 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2710(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 6;
  const int equationIndexes[2] = {1,2710};
  modelica_real tmp129;
  modelica_real tmp130;
  modelica_real tmp131;
  modelica_real tmp132;
  modelica_real tmp133;
  modelica_real tmp134;
  modelica_real tmp135;
  modelica_real tmp136;
  modelica_real tmp137;
  modelica_real tmp138;
  modelica_real tmp139;
  tmp129 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp130 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp131 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp132 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp133 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  tmp134 = (data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */);
  tmp135 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp136 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp137 = (tmp135 * tmp135 * tmp135) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((tmp136 * tmp136),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi") + DIVISION((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri")));
  tmp138 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp139 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[6] /* Chile.digester.a_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((tmp129 * tmp129)) * (((-(data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */))) * (DIVISION((3.0) * (((tmp130 * tmp130)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp131 * tmp131)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp132 * tmp132),"Chile.digester.g_mono ^ 2.0") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp133 * tmp133),"Chile.digester.g_bi ^ 2.0") - (((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */)) * (DIVISION(jacobian->tmpVars[3] /* Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */,(tmp134 * tmp134),"Chile.digester.g_tri ^ 2.0"))))),(tmp137 * tmp137),"(Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))) ^ 2.0"))) + (2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */),(tmp138 * tmp138 * tmp138) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION((tmp139 * tmp139),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono") + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi") + DIVISION((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri"))),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))")))));
  TRACE_POP
}

/*
equation index: 2711
type: SIMPLE_ASSIGN
Chile.digester.a_hco3.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.Ka_co2 * (-Chile.digester.S_ic) * ((1.0 + (1.0 / (Chile.digester.a_h * Chile.digester.g_mono) + Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi)) * Chile.digester.Ka_co2) * Chile.digester.a_h.SeedNLSJac10 + (((-Chile.digester.g_mono) * Chile.digester.a_h.SeedNLSJac10 - Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.a_h) / (Chile.digester.g_mono * Chile.digester.a_h) ^ 2.0 - Chile.digester.Ka_hco3 * (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 + 2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_bi) / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi) ^ 2.0) * Chile.digester.Ka_co2 * Chile.digester.a_h) / ((1.0 + (1.0 / (Chile.digester.a_h * Chile.digester.g_mono) + Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi)) * Chile.digester.Ka_co2) * Chile.digester.a_h) ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2711(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 7;
  const int equationIndexes[2] = {1,2711};
  modelica_real tmp140;
  modelica_real tmp141;
  modelica_real tmp142;
  modelica_real tmp143;
  modelica_real tmp144;
  modelica_real tmp145;
  modelica_real tmp146;
  tmp140 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp141 = ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */));
  tmp142 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp143 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp144 = ((tmp143 * tmp143)) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */));
  tmp145 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp146 = (1.0 + (DIVISION(1.0,((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)),"Chile.digester.a_h * Chile.digester.g_mono") + DIVISION((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */),((tmp145 * tmp145)) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)),"Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi")) * ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */))) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */));
  jacobian->tmpVars[7] /* Chile.digester.a_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (DIVISION(((-(data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */))) * ((1.0 + (DIVISION(1.0,((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)),"Chile.digester.a_h * Chile.digester.g_mono") + DIVISION((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */),((tmp140 * tmp140)) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)),"Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi")) * ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */))) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) + (DIVISION(((-(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */))) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) - ((jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */))),(tmp141 * tmp141),"(Chile.digester.g_mono * Chile.digester.a_h) ^ 2.0") - (((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */)) * (DIVISION(((tmp142 * tmp142)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)))),(tmp144 * tmp144),"(Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi) ^ 2.0")))) * (((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)))),(tmp146 * tmp146),"((1.0 + (1.0 / (Chile.digester.a_h * Chile.digester.g_mono) + Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi)) * Chile.digester.Ka_co2) * Chile.digester.a_h) ^ 2.0"));
  TRACE_POP
}

/*
equation index: 2712
type: SIMPLE_ASSIGN
Chile.digester.a_co3.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.S_ic * Chile.digester.Ka_co2 * (Chile.digester.a_h * (-Chile.digester.Ka_hco3) * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * (Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_bi - Chile.digester.a_h * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0 + (2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0)) / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono)) ^ 2.0 + Chile.digester.a_h.SeedNLSJac10 * Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono)))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2712(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 8;
  const int equationIndexes[2] = {1,2712};
  modelica_real tmp147;
  modelica_real tmp148;
  modelica_real tmp149;
  modelica_real tmp150;
  modelica_real tmp151;
  modelica_real tmp152;
  modelica_real tmp153;
  modelica_real tmp154;
  modelica_real tmp155;
  tmp147 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp148 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  tmp149 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp150 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp151 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp152 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp153 = (tmp151 * tmp151 * tmp151) + ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi")) + DIVISION((tmp152 * tmp152),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono"));
  tmp154 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp155 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[8] /* Chile.digester.a_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */)) * (((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (((-(data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */))) * (DIVISION((3.0) * (((tmp147 * tmp147)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */)) * (DIVISION((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp148 * tmp148),"Chile.digester.g_bi ^ 2.0")) + DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp149 * tmp149)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp150 * tmp150),"Chile.digester.g_mono ^ 2.0")),(tmp153 * tmp153),"(Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono)) ^ 2.0"))) + (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */),(tmp154 * tmp154 * tmp154) + ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */)) * (DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi")) + DIVISION((tmp155 * tmp155),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono")),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono)"))));
  TRACE_POP
}

/*
equation index: 2713
type: SIMPLE_ASSIGN
Chile.digester.a_bum.$pDERNLSJac10.dummyVarNLSJac10 = 0.006242905788876279 * Chile.digester.S_bu * ((-1.513561248436207e-05) * Chile.digester.a_h ^ 2.0 * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + 1.513561248436207e-05 * (2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0) / (Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0 + 3.027122496872414e-05 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 / (Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2713(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 9;
  const int equationIndexes[2] = {1,2713};
  modelica_real tmp156;
  modelica_real tmp157;
  modelica_real tmp158;
  modelica_real tmp159;
  modelica_real tmp160;
  modelica_real tmp161;
  modelica_real tmp162;
  modelica_real tmp163;
  modelica_real tmp164;
  tmp156 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp157 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp158 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp159 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp160 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp161 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp162 = (tmp160 * tmp160 * tmp160) + (1.513561248436207e-05) * (DIVISION((tmp161 * tmp161),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono"));
  tmp163 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp164 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[9] /* Chile.digester.a_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (0.006242905788876279) * (((data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */)) * ((-1.513561248436207e-05) * (((tmp156 * tmp156)) * (DIVISION((3.0) * (((tmp157 * tmp157)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + (1.513561248436207e-05) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp158 * tmp158)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp159 * tmp159),"Chile.digester.g_mono ^ 2.0")),(tmp162 * tmp162),"(Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0"))) + (3.027122496872414e-05) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (DIVISION(jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */,(tmp163 * tmp163 * tmp163) + (1.513561248436207e-05) * (DIVISION((tmp164 * tmp164),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono")),"Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono")))));
  TRACE_POP
}

/*
equation index: 2714
type: SIMPLE_ASSIGN
Chile.digester.a_nh4.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.a_h * (-Chile.digester.S_in) * (Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) * (Chile.digester.Ka_nh4 / (Chile.digester.Ka_nh4 * Chile.digester.g_mono * (1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono)) * Chile.digester.Ka_nh4)) ^ 2.0 + Chile.digester.a_h.SeedNLSJac10 * Chile.digester.S_in / (Chile.digester.Ka_nh4 * (1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono)))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2714(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 10;
  const int equationIndexes[2] = {1,2714};
  modelica_real tmp165;
  tmp165 = DIVISION((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */),(((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */))) * ((1.0 + DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)),"Chile.digester.Ka_nh4 * Chile.digester.g_mono")) * ((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */))),"Chile.digester.Ka_nh4 * Chile.digester.g_mono * (1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono)) * Chile.digester.Ka_nh4");
  jacobian->tmpVars[10] /* Chile.digester.a_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (((-(data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */))) * (((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */))) * ((tmp165 * tmp165)))) + (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */),((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)) * (1.0 + DIVISION((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)),"Chile.digester.Ka_nh4 * Chile.digester.g_mono")),"Chile.digester.Ka_nh4 * (1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono))"));
  TRACE_POP
}

/*
equation index: 2715
type: SIMPLE_ASSIGN
Chile.digester.a_acm.$pDERNLSJac10.dummyVarNLSJac10 = 0.0156119900083264 * Chile.digester.S_ac * ((-1.737800828749376e-05) * Chile.digester.a_h ^ 2.0 * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + 1.737800828749376e-05 * (2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0) / (Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0 + 3.475601657498753e-05 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 / (Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2715(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 11;
  const int equationIndexes[2] = {1,2715};
  modelica_real tmp166;
  modelica_real tmp167;
  modelica_real tmp168;
  modelica_real tmp169;
  modelica_real tmp170;
  modelica_real tmp171;
  modelica_real tmp172;
  modelica_real tmp173;
  modelica_real tmp174;
  tmp166 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp167 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp168 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp169 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp170 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp171 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp172 = (tmp170 * tmp170 * tmp170) + (1.737800828749376e-05) * (DIVISION((tmp171 * tmp171),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono"));
  tmp173 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp174 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[11] /* Chile.digester.a_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (0.0156119900083264) * (((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */)) * ((-1.737800828749376e-05) * (((tmp166 * tmp166)) * (DIVISION((3.0) * (((tmp167 * tmp167)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + (1.737800828749376e-05) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp168 * tmp168)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp169 * tmp169),"Chile.digester.g_mono ^ 2.0")),(tmp172 * tmp172),"(Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0"))) + (3.475601657498753e-05) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (DIVISION(jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */,(tmp173 * tmp173 * tmp173) + (1.737800828749376e-05) * (DIVISION((tmp174 * tmp174),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono")),"Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono")))));
  TRACE_POP
}

/*
equation index: 2716
type: SIMPLE_ASSIGN
Chile.digester.a_prom.$pDERNLSJac10.dummyVarNLSJac10 = 0.008918929342795433 * Chile.digester.S_pro * ((-1.318256738556407e-05) * Chile.digester.a_h ^ 2.0 * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + 1.318256738556407e-05 * (2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0) / (Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0 + 2.636513477112815e-05 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 / (Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2716(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 12;
  const int equationIndexes[2] = {1,2716};
  modelica_real tmp175;
  modelica_real tmp176;
  modelica_real tmp177;
  modelica_real tmp178;
  modelica_real tmp179;
  modelica_real tmp180;
  modelica_real tmp181;
  modelica_real tmp182;
  modelica_real tmp183;
  tmp175 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp176 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp177 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp178 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp179 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp180 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp181 = (tmp179 * tmp179 * tmp179) + (1.318256738556407e-05) * (DIVISION((tmp180 * tmp180),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono"));
  tmp182 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp183 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[12] /* Chile.digester.a_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (0.008918929342795433) * (((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */)) * ((-1.318256738556407e-05) * (((tmp175 * tmp175)) * (DIVISION((3.0) * (((tmp176 * tmp176)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + (1.318256738556407e-05) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp177 * tmp177)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp178 * tmp178),"Chile.digester.g_mono ^ 2.0")),(tmp181 * tmp181),"(Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0"))) + (2.636513477112815e-05) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (DIVISION(jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */,(tmp182 * tmp182 * tmp182) + (1.318256738556407e-05) * (DIVISION((tmp183 * tmp183),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono")),"Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono")))));
  TRACE_POP
}

/*
equation index: 2717
type: SIMPLE_ASSIGN
Chile.digester.a_vam.$pDERNLSJac10.dummyVarNLSJac10 = 0.004801572656267654 * Chile.digester.S_va * ((-1.380384264602884e-05) * Chile.digester.a_h ^ 2.0 * (3.0 * Chile.digester.a_h ^ 2.0 * Chile.digester.a_h.SeedNLSJac10 + 1.380384264602884e-05 * (2.0 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 * Chile.digester.g_mono - Chile.digester.a_h ^ 2.0 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0) / (Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0 + 2.760768529205768e-05 * Chile.digester.a_h * Chile.digester.a_h.SeedNLSJac10 / (Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2717(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 13;
  const int equationIndexes[2] = {1,2717};
  modelica_real tmp184;
  modelica_real tmp185;
  modelica_real tmp186;
  modelica_real tmp187;
  modelica_real tmp188;
  modelica_real tmp189;
  modelica_real tmp190;
  modelica_real tmp191;
  modelica_real tmp192;
  tmp184 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp185 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp186 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp187 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  tmp188 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp189 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp190 = (tmp188 * tmp188 * tmp188) + (1.380384264602884e-05) * (DIVISION((tmp189 * tmp189),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono"));
  tmp191 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp192 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[13] /* Chile.digester.a_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (0.004801572656267654) * (((data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */)) * ((-1.380384264602884e-05) * (((tmp184 * tmp184)) * (DIVISION((3.0) * (((tmp185 * tmp185)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)) + (1.380384264602884e-05) * (DIVISION((2.0) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * ((jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)))) - (((tmp186 * tmp186)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp187 * tmp187),"Chile.digester.g_mono ^ 2.0")),(tmp190 * tmp190),"(Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) ^ 2.0"))) + (2.760768529205768e-05) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (DIVISION(jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */,(tmp191 * tmp191 * tmp191) + (1.380384264602884e-05) * (DIVISION((tmp192 * tmp192),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono")),"Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono")))));
  TRACE_POP
}

/*
equation index: 2718
type: SIMPLE_ASSIGN
Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 = 160.1818181818182 * (Chile.digester.a_bum.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_bum * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2718(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 14;
  const int equationIndexes[2] = {1,2718};
  modelica_real tmp193;
  tmp193 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[14] /* Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (160.1818181818182) * (DIVISION((jacobian->tmpVars[9] /* Chile.digester.a_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[501] /* Chile.digester.a_bum variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp193 * tmp193),"Chile.digester.g_mono ^ 2.0"));
  TRACE_POP
}

/*
equation index: 2719
type: SIMPLE_ASSIGN
Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 = 64.05333333333333 * (Chile.digester.a_acm.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_acm * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2719(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 15;
  const int equationIndexes[2] = {1,2719};
  modelica_real tmp194;
  tmp194 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[15] /* Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (64.05333333333333) * (DIVISION((jacobian->tmpVars[11] /* Chile.digester.a_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[500] /* Chile.digester.a_acm variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp194 * tmp194),"Chile.digester.g_mono ^ 2.0"));
  TRACE_POP
}

/*
equation index: 2720
type: SIMPLE_ASSIGN
Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 = 112.1210810810811 * (Chile.digester.a_prom.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_prom * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2720(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 16;
  const int equationIndexes[2] = {1,2720};
  modelica_real tmp195;
  tmp195 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[16] /* Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (112.1210810810811) * (DIVISION((jacobian->tmpVars[12] /* Chile.digester.a_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[513] /* Chile.digester.a_prom variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp195 * tmp195),"Chile.digester.g_mono ^ 2.0"));
  TRACE_POP
}

/*
equation index: 2721
type: SIMPLE_ASSIGN
Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 = 208.2650980392157 * (Chile.digester.a_vam.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_vam * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2721(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 17;
  const int equationIndexes[2] = {1,2721};
  modelica_real tmp196;
  tmp196 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[17] /* Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (208.2650980392157) * (DIVISION((jacobian->tmpVars[13] /* Chile.digester.a_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[514] /* Chile.digester.a_vam variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp196 * tmp196),"Chile.digester.g_mono ^ 2.0"));
  TRACE_POP
}

/*
equation index: 2722
type: SIMPLE_ASSIGN
Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_hco3.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_hco3 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2722(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 18;
  const int equationIndexes[2] = {1,2722};
  modelica_real tmp197;
  tmp197 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[18] /* Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[7] /* Chile.digester.a_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[507] /* Chile.digester.a_hco3 variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp197 * tmp197),"Chile.digester.g_mono ^ 2.0");
  TRACE_POP
}

/*
equation index: 2723
type: SIMPLE_ASSIGN
Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_co3.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_bi - Chile.digester.a_co3 * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2723(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 19;
  const int equationIndexes[2] = {1,2723};
  modelica_real tmp198;
  tmp198 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  jacobian->tmpVars[19] /* Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[8] /* Chile.digester.a_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[503] /* Chile.digester.a_co3 variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp198 * tmp198),"Chile.digester.g_bi ^ 2.0");
  TRACE_POP
}

/*
equation index: 2724
type: SIMPLE_ASSIGN
Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_nh4.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_nh4 * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2724(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 20;
  const int equationIndexes[2] = {1,2724};
  modelica_real tmp199;
  tmp199 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[20] /* Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[10] /* Chile.digester.a_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[510] /* Chile.digester.a_nh4 variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp199 * tmp199),"Chile.digester.g_mono ^ 2.0");
  TRACE_POP
}

/*
equation index: 2725
type: SIMPLE_ASSIGN
Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_hpo4.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_bi - Chile.digester.a_hpo4 * Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_bi ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2725(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 21;
  const int equationIndexes[2] = {1,2725};
  modelica_real tmp200;
  tmp200 = (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */);
  jacobian->tmpVars[21] /* Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[4] /* Chile.digester.a_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)) - (((data->localData[0]->realVars[508] /* Chile.digester.a_hpo4 variable */)) * (jacobian->tmpVars[2] /* Chile.digester.g_bi.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp200 * tmp200),"Chile.digester.g_bi ^ 2.0");
  TRACE_POP
}

/*
equation index: 2726
type: SIMPLE_ASSIGN
Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_po4.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_tri - Chile.digester.a_po4 * Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_tri ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2726(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 22;
  const int equationIndexes[2] = {1,2726};
  modelica_real tmp201;
  tmp201 = (data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */);
  jacobian->tmpVars[22] /* Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[5] /* Chile.digester.a_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */)) - (((data->localData[0]->realVars[512] /* Chile.digester.a_po4 variable */)) * (jacobian->tmpVars[3] /* Chile.digester.g_tri.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp201 * tmp201),"Chile.digester.g_tri ^ 2.0");
  TRACE_POP
}

/*
equation index: 2727
type: SIMPLE_ASSIGN
Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 = 2.0 * Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 - (9.0 * Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 + 4.0 * Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 + 4.0 * Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 + 0.0156119900083264 * Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 + 0.008918929342795433 * Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 + 0.006242905788876278 * Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 + 0.004801572656267654 * Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2727(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 23;
  const int equationIndexes[2] = {1,2727};
  jacobian->tmpVars[23] /* Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (2.0) * (jacobian->tmpVars[0] /* Chile.digester.I.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) - ((9.0) * (jacobian->tmpVars[22] /* Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[20] /* Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + (4.0) * (jacobian->tmpVars[21] /* Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + jacobian->tmpVars[18] /* Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + (4.0) * (jacobian->tmpVars[19] /* Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.0156119900083264) * (jacobian->tmpVars[15] /* Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.008918929342795433) * (jacobian->tmpVars[16] /* Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.006242905788876278) * (jacobian->tmpVars[14] /* Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.004801572656267654) * (jacobian->tmpVars[17] /* Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */));
  TRACE_POP
}

/*
equation index: 2728
type: SIMPLE_ASSIGN
Chile.digester.a_h2o.$pDERNLSJac10.dummyVarNLSJac10 = if noEvent(Chile.digester.ideality == true) then 0.0 else (-0.017) * (Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 + 0.004801572656267654 * Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 + 0.006242905788876279 * Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 + 0.008918929342795433 * Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 + 0.0156119900083264 * Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2728(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 24;
  const int equationIndexes[2] = {1,2728};
  jacobian->tmpVars[24] /* Chile.digester.a_h2o.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = (((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1))?0.0:(-0.017) * (jacobian->tmpVars[20] /* Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[18] /* Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[19] /* Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[23] /* Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[21] /* Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + jacobian->tmpVars[22] /* Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + (0.004801572656267654) * (jacobian->tmpVars[17] /* Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.006242905788876279) * (jacobian->tmpVars[14] /* Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.008918929342795433) * (jacobian->tmpVars[16] /* Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (0.0156119900083264) * (jacobian->tmpVars[15] /* Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)));
  TRACE_POP
}

/*
equation index: 2729
type: SIMPLE_ASSIGN
Chile.digester.a_oh.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.Ka_h2o * Chile.digester.convKa * (Chile.digester.a_h2o.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.a_h - Chile.digester.a_h2o * Chile.digester.a_h.SeedNLSJac10) / Chile.digester.a_h ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2729(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 25;
  const int equationIndexes[2] = {1,2729};
  modelica_real tmp203;
  tmp203 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  jacobian->tmpVars[25] /* Chile.digester.a_oh.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = ((data->localData[0]->realVars[370] /* Chile.digester.Ka_h2o variable */)) * (((data->simulationInfo->realParameter[315] /* Chile.digester.convKa PARAM */)) * (DIVISION((jacobian->tmpVars[24] /* Chile.digester.a_h2o.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) - (((data->localData[0]->realVars[505] /* Chile.digester.a_h2o variable */)) * (jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */)),(tmp203 * tmp203),"Chile.digester.a_h ^ 2.0")));
  TRACE_POP
}

/*
equation index: 2730
type: SIMPLE_ASSIGN
Chile.digester.S_oh.$pDERNLSJac10.dummyVarNLSJac10 = (Chile.digester.a_oh.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono - Chile.digester.a_oh * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10) / Chile.digester.g_mono ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2730(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 26;
  const int equationIndexes[2] = {1,2730};
  modelica_real tmp204;
  tmp204 = (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */);
  jacobian->tmpVars[26] /* Chile.digester.S_oh.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = DIVISION((jacobian->tmpVars[25] /* Chile.digester.a_oh.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) - (((data->localData[0]->realVars[511] /* Chile.digester.a_oh variable */)) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */)),(tmp204 * tmp204),"Chile.digester.g_mono ^ 2.0");
  TRACE_POP
}

/*
equation index: 2731
type: SIMPLE_ASSIGN
Chile.digester.S_h.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 - (Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 + (-2.0) * Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 + (-3.0) * Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 + (-2.0) * Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 + (-0.0156119900083264) * Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 + (-0.008918929342795433) * Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 + (-0.006242905788876278) * Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 + (-0.004801572656267654) * Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 - Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 - Chile.digester.S_oh.$pDERNLSJac10.dummyVarNLSJac10)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2731(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 27;
  const int equationIndexes[2] = {1,2731};
  jacobian->tmpVars[27] /* Chile.digester.S_h.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ = jacobian->tmpVars[18] /* Chile.digester.S_hco3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ - (jacobian->tmpVars[20] /* Chile.digester.S_nh4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + (-2.0) * (jacobian->tmpVars[21] /* Chile.digester.S_hpo4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-3.0) * (jacobian->tmpVars[22] /* Chile.digester.S_po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-2.0) * (jacobian->tmpVars[19] /* Chile.digester.S_co3.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-0.0156119900083264) * (jacobian->tmpVars[15] /* Chile.digester.S_acm.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-0.008918929342795433) * (jacobian->tmpVars[16] /* Chile.digester.S_prom.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-0.006242905788876278) * (jacobian->tmpVars[14] /* Chile.digester.S_bum.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (-0.004801572656267654) * (jacobian->tmpVars[17] /* Chile.digester.S_vam.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) - jacobian->tmpVars[23] /* Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ - jacobian->tmpVars[26] /* Chile.digester.S_oh.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */);
  TRACE_POP
}

/*
equation index: 2732
type: SIMPLE_ASSIGN
$res_NLSJac10_1.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.a_h2po4.$pDERNLSJac10.dummyVarNLSJac10 + (-Chile.digester.S_h2po4) * Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 - Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2732(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 28;
  const int equationIndexes[2] = {1,2732};
  jacobian->resultVars[0] /* $res_NLSJac10_1.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_VAR */ = jacobian->tmpVars[6] /* Chile.digester.a_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */ + ((-(data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */))) * (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) - ((jacobian->tmpVars[23] /* Chile.digester.S_h2po4.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)));
  TRACE_POP
}

/*
equation index: 2733
type: SIMPLE_ASSIGN
$res_NLSJac10_2.$pDERNLSJac10.dummyVarNLSJac10 = Chile.digester.g_mono * Chile.digester.S_h.$pDERNLSJac10.dummyVarNLSJac10 + Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 * Chile.digester.S_h - Chile.digester.a_h.SeedNLSJac10
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2733(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 29;
  const int equationIndexes[2] = {1,2733};
  jacobian->resultVars[1] /* $res_NLSJac10_2.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_VAR */ = ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) * (jacobian->tmpVars[27] /* Chile.digester.S_h.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) + (jacobian->tmpVars[1] /* Chile.digester.g_mono.$pDERNLSJac10.dummyVarNLSJac10 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[440] /* Chile.digester.S_h variable */)) - jacobian->seedVars[0] /* Chile.digester.a_h.SeedNLSJac10 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac10_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac10;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac10_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac10;
  ADM1_P_Chile_OL_MPC_eqFunction_2704(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2705(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2706(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2707(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2708(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2709(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2710(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2711(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2712(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2713(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2714(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2715(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2716(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2717(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2718(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2719(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2720(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2721(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2722(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2723(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2724(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2725(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2726(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2727(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2728(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2729(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2730(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2731(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2732(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2733(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 2949
type: SIMPLE_ASSIGN
Chile.slurry.S_co3.$pDERNLSJac12.dummyVarNLSJac12 = Chile.slurry.outlet.S_ic.SeedNLSJac12 * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2949(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,2949};
  modelica_real tmp205;
  tmp205 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  jacobian->tmpVars[0] /* Chile.slurry.S_co3.$pDERNLSJac12.dummyVarNLSJac12 JACOBIAN_DIFF_VAR */ = (jacobian->seedVars[0] /* Chile.slurry.outlet.S_ic.SeedNLSJac12 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION((tmp205 * tmp205),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2") + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 2950
type: SIMPLE_ASSIGN
Chile.slurry.S_hco3.$pDERNLSJac12.dummyVarNLSJac12 = if noEvent(0.0 > (if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic * Chile.slurry.Ka_co2 / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) else Chile.slurry.Alk_mol - (Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam) - Chile.slurry.S_oh - Chile.slurry.S_nh3 + Chile.slurry.S_h - Chile.slurry.S_hpo4 - 2.0 * Chile.slurry.S_po4 + Chile.slurry.S_h3po4 - 2.0 * Chile.slurry.S_co3)) then 0.0 else if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic.SeedNLSJac12 * Chile.slurry.Ka_co2 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0 else (-2.0) * Chile.slurry.S_co3.$pDERNLSJac12.dummyVarNLSJac12
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2950(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,2950};
  modelica_boolean tmp207;
  modelica_real tmp209;
  modelica_boolean tmp210;
  modelica_real tmp211;
  modelica_boolean tmp212;
  modelica_real tmp213;
  tmp207 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h"):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)))));
  tmp212 = (modelica_boolean)tmp207;
  if(tmp212)
  {
    tmp213 = 0.0;
  }
  else
  {
    tmp210 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
    if(tmp210)
    {
      tmp209 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h");
      tmp211 = DIVISION(((jacobian->seedVars[0] /* Chile.slurry.outlet.S_ic.SeedNLSJac12 SEED_VAR */) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */))) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h")),(tmp209 * tmp209),"(Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) ^ 2.0");
    }
    else
    {
      tmp211 = (-2.0) * (jacobian->tmpVars[0] /* Chile.slurry.S_co3.$pDERNLSJac12.dummyVarNLSJac12 JACOBIAN_DIFF_VAR */);
    }
    tmp213 = tmp211;
  }
  jacobian->tmpVars[1] /* Chile.slurry.S_hco3.$pDERNLSJac12.dummyVarNLSJac12 JACOBIAN_DIFF_VAR */ = tmp213;
  TRACE_POP
}

/*
equation index: 2951
type: SIMPLE_ASSIGN
$res_NLSJac12_1.$pDERNLSJac12.dummyVarNLSJac12 = (if Chile.slurry.liquid == false then 0.0 else Chile.slurry.S_hco3.$pDERNLSJac12.dummyVarNLSJac12 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) * Chile.slurry.Ka_co2 / Chile.slurry.Ka_co2 ^ 2.0) - Chile.slurry.outlet.S_ic.SeedNLSJac12
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2951(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,2951};
  modelica_real tmp215;
  modelica_boolean tmp216;
  modelica_real tmp217;
  tmp216 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0));
  if(tmp216)
  {
    tmp217 = 0.0;
  }
  else
  {
    tmp215 = (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */);
    tmp217 = DIVISION(((jacobian->tmpVars[1] /* Chile.slurry.S_hco3.$pDERNLSJac12.dummyVarNLSJac12 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h"))) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(tmp215 * tmp215),"Chile.slurry.Ka_co2 ^ 2.0");
  }
  jacobian->resultVars[0] /* $res_NLSJac12_1.$pDERNLSJac12.dummyVarNLSJac12 JACOBIAN_VAR */ = tmp217 - jacobian->seedVars[0] /* Chile.slurry.outlet.S_ic.SeedNLSJac12 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac12_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac12;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac12_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac12;
  ADM1_P_Chile_OL_MPC_eqFunction_2949(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2950(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_2951(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 3074
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3.$pDERNLSJac13.dummyVarNLSJac13 = Chile.tomatosouce.outlet.S_ic.SeedNLSJac13 * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3074(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,3074};
  modelica_real tmp218;
  tmp218 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  jacobian->tmpVars[0] /* Chile.tomatosouce.S_co3.$pDERNLSJac13.dummyVarNLSJac13 JACOBIAN_DIFF_VAR */ = (jacobian->seedVars[0] /* Chile.tomatosouce.outlet.S_ic.SeedNLSJac13 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION((tmp218 * tmp218),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2") + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 3075
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_hco3.$pDERNLSJac13.dummyVarNLSJac13 = if noEvent(0.0 > (if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_co2 / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) else Chile.tomatosouce.Alk_mol - (Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam) - Chile.tomatosouce.S_oh - Chile.tomatosouce.S_nh3 + Chile.tomatosouce.S_h - Chile.tomatosouce.S_hpo4 - 2.0 * Chile.tomatosouce.S_po4 + Chile.tomatosouce.S_h3po4 - 2.0 * Chile.tomatosouce.S_co3)) then 0.0 else if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic.SeedNLSJac13 * Chile.tomatosouce.Ka_co2 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0 else (-2.0) * Chile.tomatosouce.S_co3.$pDERNLSJac13.dummyVarNLSJac13
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3075(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,3075};
  modelica_boolean tmp220;
  modelica_real tmp222;
  modelica_boolean tmp223;
  modelica_real tmp224;
  modelica_boolean tmp225;
  modelica_real tmp226;
  tmp220 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h"):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)))));
  tmp225 = (modelica_boolean)tmp220;
  if(tmp225)
  {
    tmp226 = 0.0;
  }
  else
  {
    tmp223 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
    if(tmp223)
    {
      tmp222 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h");
      tmp224 = DIVISION(((jacobian->seedVars[0] /* Chile.tomatosouce.outlet.S_ic.SeedNLSJac13 SEED_VAR */) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */))) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h")),(tmp222 * tmp222),"(Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) ^ 2.0");
    }
    else
    {
      tmp224 = (-2.0) * (jacobian->tmpVars[0] /* Chile.tomatosouce.S_co3.$pDERNLSJac13.dummyVarNLSJac13 JACOBIAN_DIFF_VAR */);
    }
    tmp226 = tmp224;
  }
  jacobian->tmpVars[1] /* Chile.tomatosouce.S_hco3.$pDERNLSJac13.dummyVarNLSJac13 JACOBIAN_DIFF_VAR */ = tmp226;
  TRACE_POP
}

/*
equation index: 3076
type: SIMPLE_ASSIGN
$res_NLSJac13_1.$pDERNLSJac13.dummyVarNLSJac13 = (if Chile.tomatosouce.liquid == false then 0.0 else Chile.tomatosouce.S_hco3.$pDERNLSJac13.dummyVarNLSJac13 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.Ka_co2 ^ 2.0) - Chile.tomatosouce.outlet.S_ic.SeedNLSJac13
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3076(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,3076};
  modelica_real tmp228;
  modelica_boolean tmp229;
  modelica_real tmp230;
  tmp229 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0));
  if(tmp229)
  {
    tmp230 = 0.0;
  }
  else
  {
    tmp228 = (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */);
    tmp230 = DIVISION(((jacobian->tmpVars[1] /* Chile.tomatosouce.S_hco3.$pDERNLSJac13.dummyVarNLSJac13 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h"))) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(tmp228 * tmp228),"Chile.tomatosouce.Ka_co2 ^ 2.0");
  }
  jacobian->resultVars[0] /* $res_NLSJac13_1.$pDERNLSJac13.dummyVarNLSJac13 JACOBIAN_VAR */ = tmp230 - jacobian->seedVars[0] /* Chile.tomatosouce.outlet.S_ic.SeedNLSJac13 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac13_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac13;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac13_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac13;
  ADM1_P_Chile_OL_MPC_eqFunction_3074(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_3075(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_3076(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

/*
equation index: 3212
type: SIMPLE_ASSIGN
Chile.maize.S_co3.$pDERNLSJac14.dummyVarNLSJac14 = Chile.maize.outlet.S_ic.SeedNLSJac14 * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3212(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 0;
  const int equationIndexes[2] = {1,3212};
  modelica_real tmp231;
  tmp231 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  jacobian->tmpVars[0] /* Chile.maize.S_co3.$pDERNLSJac14.dummyVarNLSJac14 JACOBIAN_DIFF_VAR */ = (jacobian->seedVars[0] /* Chile.maize.outlet.S_ic.SeedNLSJac14 SEED_VAR */) * (DIVISION((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION((tmp231 * tmp231),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2") + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3"));
  TRACE_POP
}

/*
equation index: 3213
type: SIMPLE_ASSIGN
Chile.maize.S_hco3.$pDERNLSJac14.dummyVarNLSJac14 = if noEvent(0.0 > (if Chile.maize.liquid == false then Chile.maize.outlet.S_ic * Chile.maize.Ka_co2 / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) else Chile.maize.Alk_mol - (Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam) - Chile.maize.S_oh - Chile.maize.S_nh3 + Chile.maize.S_h - Chile.maize.S_hpo4 - 2.0 * Chile.maize.S_po4 + Chile.maize.S_h3po4 - 2.0 * Chile.maize.S_co3)) then 0.0 else if Chile.maize.liquid == false then Chile.maize.outlet.S_ic.SeedNLSJac14 * Chile.maize.Ka_co2 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0 else (-2.0) * Chile.maize.S_co3.$pDERNLSJac14.dummyVarNLSJac14
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3213(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 1;
  const int equationIndexes[2] = {1,3213};
  modelica_boolean tmp233;
  modelica_real tmp235;
  modelica_boolean tmp236;
  modelica_real tmp237;
  modelica_boolean tmp238;
  modelica_real tmp239;
  tmp233 = Greater(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h"):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)))));
  tmp238 = (modelica_boolean)tmp233;
  if(tmp238)
  {
    tmp239 = 0.0;
  }
  else
  {
    tmp236 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
    if(tmp236)
    {
      tmp235 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h");
      tmp237 = DIVISION(((jacobian->seedVars[0] /* Chile.maize.outlet.S_ic.SeedNLSJac14 SEED_VAR */) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */))) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h")),(tmp235 * tmp235),"(Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) ^ 2.0");
    }
    else
    {
      tmp237 = (-2.0) * (jacobian->tmpVars[0] /* Chile.maize.S_co3.$pDERNLSJac14.dummyVarNLSJac14 JACOBIAN_DIFF_VAR */);
    }
    tmp239 = tmp237;
  }
  jacobian->tmpVars[1] /* Chile.maize.S_hco3.$pDERNLSJac14.dummyVarNLSJac14 JACOBIAN_DIFF_VAR */ = tmp239;
  TRACE_POP
}

/*
equation index: 3214
type: SIMPLE_ASSIGN
$res_NLSJac14_1.$pDERNLSJac14.dummyVarNLSJac14 = (if Chile.maize.liquid == false then 0.0 else Chile.maize.S_hco3.$pDERNLSJac14.dummyVarNLSJac14 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) * Chile.maize.Ka_co2 / Chile.maize.Ka_co2 ^ 2.0) - Chile.maize.outlet.S_ic.SeedNLSJac14
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3214(DATA *data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  const int baseClockIndex = 0;
  const int subClockIndex = 2;
  const int equationIndexes[2] = {1,3214};
  modelica_real tmp241;
  modelica_boolean tmp242;
  modelica_real tmp243;
  tmp242 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0));
  if(tmp242)
  {
    tmp243 = 0.0;
  }
  else
  {
    tmp241 = (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */);
    tmp243 = DIVISION(((jacobian->tmpVars[1] /* Chile.maize.S_hco3.$pDERNLSJac14.dummyVarNLSJac14 JACOBIAN_DIFF_VAR */) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h"))) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(tmp241 * tmp241),"Chile.maize.Ka_co2 ^ 2.0");
  }
  jacobian->resultVars[0] /* $res_NLSJac14_1.$pDERNLSJac14.dummyVarNLSJac14 JACOBIAN_VAR */ = tmp243 - jacobian->seedVars[0] /* Chile.maize.outlet.S_ic.SeedNLSJac14 SEED_VAR */;
  TRACE_POP
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacNLSJac14_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac14;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacNLSJac14_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac14;
  ADM1_P_Chile_OL_MPC_eqFunction_3212(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_3213(data, threadData, jacobian, parentJacobian);
  ADM1_P_Chile_OL_MPC_eqFunction_3214(data, threadData, jacobian, parentJacobian);
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
/* constant equations */
/* dynamic equations */

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_functionJacA_constantEqns(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_A;
  
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian, ANALYTIC_JACOBIAN *parentJacobian)
{
  TRACE_PUSH

  int index = ADM1_P_Chile_OL_MPC_INDEX_JAC_A;
  TRACE_POP
  return 0;
}

OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac2.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac3(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac3.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac4(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac4.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac7(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac7.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac8(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac8.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac9(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac9.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac10(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac10.bin");
  
  initAnalyticJacobian(jacobian, 2, 2, 30, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(2, 4, 2);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 2+1, pFile, FALSE);
  if (count != 2+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 2+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 4, pFile, FALSE);
  if (count != 4) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 2+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac12(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac12.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac13(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac13.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac14(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacNLSJac14.bin");
  
  initAnalyticJacobian(jacobian, 1, 1, 3, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(1, 1, 1);
  jacobian->availability = JACOBIAN_AVAILABLE;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 1+1, pFile, FALSE);
  if (count != 1+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 1, pFile, FALSE);
  if (count != 1) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 1+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  TRACE_POP
  jacobian->availability = JACOBIAN_NOT_AVAILABLE;
  return 1;
}
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian)
{
  TRACE_PUSH
  size_t count;

  FILE* pFile = openSparsePatternFile(data, threadData, "ADM1_P.Chile_OL_MPC_JacA.bin");
  
  initAnalyticJacobian(jacobian, 73, 73, 0, NULL, jacobian->sparsePattern);
  jacobian->sparsePattern = allocSparsePattern(73, 746, 34);
  jacobian->availability = JACOBIAN_ONLY_SPARSITY;
  
  /* read lead index of compressed sparse column */
  count = omc_fread(jacobian->sparsePattern->leadindex, sizeof(unsigned int), 73+1, pFile, FALSE);
  if (count != 73+1) {
    throwStreamPrint(threadData, "Error while reading lead index list of sparsity pattern. Expected %d, got %ld", 73+1, count);
  }
  
  /* read sparse index */
  count = omc_fread(jacobian->sparsePattern->index, sizeof(unsigned int), 746, pFile, FALSE);
  if (count != 746) {
    throwStreamPrint(threadData, "Error while reading row index list of sparsity pattern. Expected %d, got %ld", 73+1, count);
  }
  
  /* write color array */
  /* color 1 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 1, 1);
  /* color 2 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 2, 1);
  /* color 3 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 3, 1);
  /* color 4 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 4, 1);
  /* color 5 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 5, 1);
  /* color 6 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 6, 1);
  /* color 7 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 7, 2);
  /* color 8 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 8, 1);
  /* color 9 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 9, 1);
  /* color 10 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 10, 1);
  /* color 11 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 11, 1);
  /* color 12 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 12, 1);
  /* color 13 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 13, 1);
  /* color 14 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 14, 1);
  /* color 15 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 15, 1);
  /* color 16 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 16, 1);
  /* color 17 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 17, 1);
  /* color 18 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 18, 2);
  /* color 19 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 19, 2);
  /* color 20 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 20, 1);
  /* color 21 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 21, 1);
  /* color 22 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 22, 2);
  /* color 23 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 23, 1);
  /* color 24 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 24, 2);
  /* color 25 with 3 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 25, 3);
  /* color 26 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 26, 2);
  /* color 27 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 27, 1);
  /* color 28 with 1 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 28, 1);
  /* color 29 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 29, 2);
  /* color 30 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 30, 2);
  /* color 31 with 6 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 31, 6);
  /* color 32 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 32, 2);
  /* color 33 with 2 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 33, 2);
  /* color 34 with 23 columns */
  readSparsePatternColor(threadData, pFile, jacobian->sparsePattern->colorCols, 34, 23);
  
  omc_fclose(pFile);
  
  TRACE_POP
  return 0;
}



