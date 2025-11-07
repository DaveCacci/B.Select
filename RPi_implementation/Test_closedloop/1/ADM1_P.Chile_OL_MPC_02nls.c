/* Non Linear Systems */
#include "ADM1_P.Chile_OL_MPC_model.h"
#include "ADM1_P.Chile_OL_MPC_12jac.h"
#include "simulation/jacobian_util.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

void residualFunc257(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,257};
  int i,j;
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc257: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc257 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  tmp0 = 10.0;
  tmp1 = (-(data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */));
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }res[0] = tmp2 - (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS257(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}
void initializeNonlinearPatternNLS257(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS257(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.y_dig[1] */
  sysData->nominal[i] = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS257(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS257(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS257(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */);
}


/* inner equations */

/*
equation index: 394
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_ic = if Chile.maize.liquid == false then Chile.maize.tic / 12000.0 else Chile.maize.S_hco3 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) / Chile.maize.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_394(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,394};
  (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[695] /* Chile.maize.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */)) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes)),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 395
type: SIMPLE_ASSIGN
Chile.maize.S_co3 = Chile.maize.outlet.S_ic * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_395(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,395};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */) = ((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc400(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,400};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc400: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc400 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_394(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_395(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h",equationIndexes):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */))))) - (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS400(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS400(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS400(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.maize.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS400(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS400(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS400(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */);
}


/* inner equations */

/*
equation index: 517
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_ic = if Chile.tomatosouce.liquid == false then Chile.tomatosouce.tic / 12000.0 else Chile.tomatosouce.S_hco3 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) / Chile.tomatosouce.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_517(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,517};
  (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[1103] /* Chile.tomatosouce.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */)) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes)),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 518
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3 = Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_518(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,518};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */) = ((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc523(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,523};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc523: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc523 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_517(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_518(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h",equationIndexes):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */))))) - (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS523(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS523(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS523(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.tomatosouce.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS523(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS523(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS523(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */);
}


/* inner equations */

/*
equation index: 640
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_ic = if Chile.slurry.liquid == false then Chile.slurry.tic / 12000.0 else Chile.slurry.S_hco3 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) / Chile.slurry.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_640(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,640};
  (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[897] /* Chile.slurry.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */)) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes)),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 641
type: SIMPLE_ASSIGN
Chile.slurry.S_co3 = Chile.slurry.outlet.S_ic * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_641(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,641};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */) = ((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc646(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,646};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc646: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc646 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_640(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_641(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h",equationIndexes):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */))))) - (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS646(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS646(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS646(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.slurry.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS646(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS646(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS646(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */);
}


/* inner equations */

void residualFunc1563(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1563};
  int i,j;
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc1563: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc1563 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  tmp0 = 10.0;
  tmp1 = (-(data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */));
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }res[0] = tmp2 - (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS1563(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}
void initializeNonlinearPatternNLS1563(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS1563(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.y_dig[1] */
  sysData->nominal[i] = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS1563(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS1563(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS1563(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */);
}


/* inner equations */

/*
equation index: 1700
type: SIMPLE_ASSIGN
Chile.maize.outlet.S_ic = if Chile.maize.liquid == false then Chile.maize.tic / 12000.0 else Chile.maize.S_hco3 * (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) / Chile.maize.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1700};
  (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[695] /* Chile.maize.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */)) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes)),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 1701
type: SIMPLE_ASSIGN
Chile.maize.S_co3 = Chile.maize.outlet.S_ic * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1701};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */) = ((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc1706(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1706};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc1706: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc1706 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1700(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1701(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h",equationIndexes):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */))))) - (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS1706(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS1706(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS1706(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.maize.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[791].attribute /* Chile.maize.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS1706(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS1706(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS1706(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */);
}


/* inner equations */

/*
equation index: 1823
type: SIMPLE_ASSIGN
Chile.tomatosouce.outlet.S_ic = if Chile.tomatosouce.liquid == false then Chile.tomatosouce.tic / 12000.0 else Chile.tomatosouce.S_hco3 * (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) / Chile.tomatosouce.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1823(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1823};
  (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[1103] /* Chile.tomatosouce.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */)) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes)),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 1824
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3 = Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1824(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1824};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */) = ((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc1829(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1829};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc1829: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc1829 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1823(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1824(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h",equationIndexes):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */))))) - (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS1829(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS1829(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS1829(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.tomatosouce.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1155].attribute /* Chile.tomatosouce.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS1829(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS1829(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS1829(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */);
}


/* inner equations */

/*
equation index: 1946
type: SIMPLE_ASSIGN
Chile.slurry.outlet.S_ic = if Chile.slurry.liquid == false then Chile.slurry.tic / 12000.0 else Chile.slurry.S_hco3 * (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) / Chile.slurry.Ka_co2
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1946(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1946};
  (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */) = (((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[897] /* Chile.slurry.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */)) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes)),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes));
  TRACE_POP
}
/*
equation index: 1947
type: SIMPLE_ASSIGN
Chile.slurry.S_co3 = Chile.slurry.outlet.S_ic * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_1947(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1947};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */) = ((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3",equationIndexes));
  TRACE_POP
}

void residualFunc1952(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,1952};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc1952: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc1952 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1946(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_1947(data, threadData);
  /* body */
  res[0] = fmax(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h",equationIndexes):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */))))) - (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS1952(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS1952(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 0;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(0*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(0*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,0};
  const int index_eqn[1+1] = {0,0};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[0] = {};
  const int rows[0] = {};
  memcpy(inSysData->nonlinearPattern->columns, columns, 0*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 0*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS1952(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.slurry.S_hco3 */
  sysData->nominal[i] = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.min;
  sysData->max[i++]   = data->modelData->realVarsData[977].attribute /* Chile.slurry.S_hco3 */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS1952(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS1952(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS1952(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */);
}


/* inner equations */

/*
equation index: 2674
type: SIMPLE_ASSIGN
Chile.digester.I = Chile.digester.z ^ 2.0
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2674(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2674};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
  (data->localData[0]->realVars[337] /* Chile.digester.I variable */) = (tmp0 * tmp0);
  TRACE_POP
}
/*
equation index: 2675
type: SIMPLE_ASSIGN
Chile.digester.g_mono = if noEvent(Chile.digester.ideality == true) then 1.0 else 10.0 ^ ((-0.51) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2675(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2675};
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
  tmp8 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp8)
  {
    tmp9 = 1.0;
  }
  else
  {
    tmp1 = 10.0;
    tmp2 = (-0.51) * (DIVISION_SIM((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z",equationIndexes) - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp1 < 0.0 && tmp2 != 0.0)
    {
      tmp4 = modf(tmp2, &tmp5);
      
      if(tmp4 > 0.5)
      {
        tmp4 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp4 < -0.5)
      {
        tmp4 += 1.0;
        tmp5 -= 1.0;
      }
      
      if(fabs(tmp4) < 1e-10)
        tmp3 = pow(tmp1, tmp5);
      else
      {
        tmp7 = modf(1.0/tmp2, &tmp6);
        if(tmp7 > 0.5)
        {
          tmp7 -= 1.0;
          tmp6 += 1.0;
        }
        else if(tmp7 < -0.5)
        {
          tmp7 += 1.0;
          tmp6 -= 1.0;
        }
        if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
        {
          tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
        }
      }
    }
    else
    {
      tmp3 = pow(tmp1, tmp2);
    }
    if(isnan(tmp3) || isinf(tmp3))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
    }
    tmp9 = tmp3;
  }
  (data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */) = tmp9;
  TRACE_POP
}
/*
equation index: 2676
type: SIMPLE_ASSIGN
Chile.digester.g_bi = if noEvent(Chile.digester.ideality == true) then 1.0 else 10.0 ^ ((-2.04) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2676(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2676};
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
  tmp8 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp8)
  {
    tmp9 = 1.0;
  }
  else
  {
    tmp1 = 10.0;
    tmp2 = (-2.04) * (DIVISION_SIM((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z",equationIndexes) - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp1 < 0.0 && tmp2 != 0.0)
    {
      tmp4 = modf(tmp2, &tmp5);
      
      if(tmp4 > 0.5)
      {
        tmp4 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp4 < -0.5)
      {
        tmp4 += 1.0;
        tmp5 -= 1.0;
      }
      
      if(fabs(tmp4) < 1e-10)
        tmp3 = pow(tmp1, tmp5);
      else
      {
        tmp7 = modf(1.0/tmp2, &tmp6);
        if(tmp7 > 0.5)
        {
          tmp7 -= 1.0;
          tmp6 += 1.0;
        }
        else if(tmp7 < -0.5)
        {
          tmp7 += 1.0;
          tmp6 -= 1.0;
        }
        if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
        {
          tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
        }
      }
    }
    else
    {
      tmp3 = pow(tmp1, tmp2);
    }
    if(isnan(tmp3) || isinf(tmp3))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
    }
    tmp9 = tmp3;
  }
  (data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */) = tmp9;
  TRACE_POP
}
/*
equation index: 2677
type: SIMPLE_ASSIGN
Chile.digester.g_tri = if noEvent(Chile.digester.ideality == true) then 1.0 else 10.0 ^ ((-4.59) * (Chile.digester.z / (1.0 + Chile.digester.z) - 0.24 * Chile.digester.I))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2677(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2677};
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_boolean tmp8;
  modelica_real tmp9;
  tmp8 = (modelica_boolean)((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1));
  if(tmp8)
  {
    tmp9 = 1.0;
  }
  else
  {
    tmp1 = 10.0;
    tmp2 = (-4.59) * (DIVISION_SIM((data->localData[0]->realVars[645] /* Chile.digester.z variable */),1.0 + (data->localData[0]->realVars[645] /* Chile.digester.z variable */),"1.0 + Chile.digester.z",equationIndexes) - ((0.24) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */))));
    if(tmp1 < 0.0 && tmp2 != 0.0)
    {
      tmp4 = modf(tmp2, &tmp5);
      
      if(tmp4 > 0.5)
      {
        tmp4 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp4 < -0.5)
      {
        tmp4 += 1.0;
        tmp5 -= 1.0;
      }
      
      if(fabs(tmp4) < 1e-10)
        tmp3 = pow(tmp1, tmp5);
      else
      {
        tmp7 = modf(1.0/tmp2, &tmp6);
        if(tmp7 > 0.5)
        {
          tmp7 -= 1.0;
          tmp6 += 1.0;
        }
        else if(tmp7 < -0.5)
        {
          tmp7 += 1.0;
          tmp6 -= 1.0;
        }
        if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
        {
          tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
        }
        else
        {
          throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
        }
      }
    }
    else
    {
      tmp3 = pow(tmp1, tmp2);
    }
    if(isnan(tmp3) || isinf(tmp3))
    {
      throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
    }
    tmp9 = tmp3;
  }
  (data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */) = tmp9;
  TRACE_POP
}
/*
equation index: 2678
type: SIMPLE_ASSIGN
Chile.digester.a_hpo4 = Chile.digester.S_ip * Chile.digester.a_h * Chile.digester.Ka_h3po4 * Chile.digester.Ka_h2po4 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri)))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2678(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2678};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[508] /* Chile.digester.a_hpo4 variable */) = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */),(tmp0 * tmp0 * tmp0) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION_SIM((tmp1 * tmp1),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes) + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri",equationIndexes))),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))",equationIndexes))));
  TRACE_POP
}
/*
equation index: 2679
type: SIMPLE_ASSIGN
Chile.digester.a_po4 = Chile.digester.S_ip * Chile.digester.Ka_h3po4 * Chile.digester.Ka_h2po4 * Chile.digester.Ka_hpo4 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri)))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2679(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2679};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[512] /* Chile.digester.a_po4 variable */) = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(tmp0 * tmp0 * tmp0) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION_SIM((tmp1 * tmp1),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes) + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri",equationIndexes))),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))",equationIndexes))));
  TRACE_POP
}
/*
equation index: 2680
type: SIMPLE_ASSIGN
Chile.digester.a_h2po4 = Chile.digester.S_ip * Chile.digester.a_h ^ 2.0 * Chile.digester.Ka_h3po4 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri)))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2680(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2680};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp2 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[506] /* Chile.digester.a_h2po4 variable */) = ((data->localData[0]->realVars[34] /* Chile.digester.S_ip STATE(1) */)) * (((tmp0 * tmp0)) * (DIVISION_SIM((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */),(tmp1 * tmp1 * tmp1) + ((data->localData[0]->realVars[372] /* Chile.digester.Ka_h3po4 variable */)) * (DIVISION_SIM((tmp2 * tmp2),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes) + ((data->localData[0]->realVars[371] /* Chile.digester.Ka_h2po4 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[374] /* Chile.digester.Ka_hpo4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri",equationIndexes))),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_h3po4 * (Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono + Chile.digester.Ka_h2po4 * (Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.Ka_hpo4 / Chile.digester.g_tri))",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2681
type: SIMPLE_ASSIGN
Chile.digester.a_hco3 = Chile.digester.Ka_co2 * Chile.digester.S_ic / ((1.0 + (1.0 / (Chile.digester.g_mono * Chile.digester.a_h) + Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi)) * Chile.digester.Ka_co2) * Chile.digester.a_h)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2681(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2681};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[507] /* Chile.digester.a_hco3 variable */) = ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */),(1.0 + (DIVISION_SIM(1.0,((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)),"Chile.digester.g_mono * Chile.digester.a_h",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */),((tmp0 * tmp0)) * ((data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */)),"Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi",equationIndexes)) * ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */))) * ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)),"(1.0 + (1.0 / (Chile.digester.g_mono * Chile.digester.a_h) + Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 2.0 * Chile.digester.g_bi)) * Chile.digester.Ka_co2) * Chile.digester.a_h",equationIndexes));
  TRACE_POP
}
/*
equation index: 2682
type: SIMPLE_ASSIGN
Chile.digester.a_co3 = Chile.digester.S_ic * Chile.digester.a_h * Chile.digester.Ka_co2 * Chile.digester.Ka_hco3 / (Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono))
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2682(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2682};
  modelica_real tmp0;
  modelica_real tmp1;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[503] /* Chile.digester.a_co3 variable */) = ((data->localData[0]->realVars[32] /* Chile.digester.S_ic STATE(1) */)) * (((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */),(tmp0 * tmp0 * tmp0) + ((data->localData[0]->realVars[369] /* Chile.digester.Ka_co2 variable */)) * (((data->localData[0]->realVars[373] /* Chile.digester.Ka_hco3 variable */)) * (DIVISION_SIM((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes)) + DIVISION_SIM((tmp1 * tmp1),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes)),"Chile.digester.a_h ^ 3.0 + Chile.digester.Ka_co2 * (Chile.digester.Ka_hco3 * Chile.digester.a_h / Chile.digester.g_bi + Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono)",equationIndexes))));
  TRACE_POP
}
/*
equation index: 2683
type: SIMPLE_ASSIGN
Chile.digester.a_bum = Chile.digester.S_bu * Chile.digester.a_h ^ 2.0 * 1.513561248436207e-05 / (Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) / 160.1818181818182
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2683(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2683};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp2 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[501] /* Chile.digester.a_bum variable */) = ((data->localData[0]->realVars[20] /* Chile.digester.S_bu STATE(1) */)) * (DIVISION_SIM(((tmp0 * tmp0)) * (DIVISION_SIM(1.513561248436207e-05,(tmp1 * tmp1 * tmp1) + (1.513561248436207e-05) * (DIVISION_SIM((tmp2 * tmp2),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes)),"Chile.digester.a_h ^ 3.0 + 1.513561248436207e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono",equationIndexes)),160.1818181818182,"160.1818181818182",equationIndexes));
  TRACE_POP
}
/*
equation index: 2684
type: SIMPLE_ASSIGN
Chile.digester.a_nh4 = Chile.digester.a_h * Chile.digester.S_in / ((1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono)) * Chile.digester.Ka_nh4)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2684(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2684};
  (data->localData[0]->realVars[510] /* Chile.digester.a_nh4 variable */) = ((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */)) * (DIVISION_SIM((data->localData[0]->realVars[33] /* Chile.digester.S_in STATE(1) */),(1.0 + DIVISION_SIM((data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)),"Chile.digester.Ka_nh4 * Chile.digester.g_mono",equationIndexes)) * ((data->localData[0]->realVars[375] /* Chile.digester.Ka_nh4 variable */)),"(1.0 + Chile.digester.a_h / (Chile.digester.Ka_nh4 * Chile.digester.g_mono)) * Chile.digester.Ka_nh4",equationIndexes));
  TRACE_POP
}
/*
equation index: 2685
type: SIMPLE_ASSIGN
Chile.digester.a_acm = Chile.digester.S_ac * Chile.digester.a_h ^ 2.0 * 1.737800828749376e-05 / (Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) / 64.05333333333333
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2685(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2685};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp2 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[500] /* Chile.digester.a_acm variable */) = ((data->localData[0]->realVars[18] /* Chile.digester.S_ac STATE(1) */)) * (DIVISION_SIM(((tmp0 * tmp0)) * (DIVISION_SIM(1.737800828749376e-05,(tmp1 * tmp1 * tmp1) + (1.737800828749376e-05) * (DIVISION_SIM((tmp2 * tmp2),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes)),"Chile.digester.a_h ^ 3.0 + 1.737800828749376e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono",equationIndexes)),64.05333333333333,"64.05333333333333",equationIndexes));
  TRACE_POP
}
/*
equation index: 2686
type: SIMPLE_ASSIGN
Chile.digester.a_prom = Chile.digester.S_pro * Chile.digester.a_h ^ 2.0 * 1.318256738556407e-05 / (Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) / 112.1210810810811
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2686(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2686};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp2 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[513] /* Chile.digester.a_prom variable */) = ((data->localData[0]->realVars[36] /* Chile.digester.S_pro STATE(1) */)) * (DIVISION_SIM(((tmp0 * tmp0)) * (DIVISION_SIM(1.318256738556407e-05,(tmp1 * tmp1 * tmp1) + (1.318256738556407e-05) * (DIVISION_SIM((tmp2 * tmp2),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes)),"Chile.digester.a_h ^ 3.0 + 1.318256738556407e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono",equationIndexes)),112.1210810810811,"112.1210810810811",equationIndexes));
  TRACE_POP
}
/*
equation index: 2687
type: SIMPLE_ASSIGN
Chile.digester.a_vam = Chile.digester.S_va * Chile.digester.a_h ^ 2.0 * 1.380384264602884e-05 / (Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono) / 208.2650980392157
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2687(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2687};
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  tmp0 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp1 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  tmp2 = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  (data->localData[0]->realVars[514] /* Chile.digester.a_vam variable */) = ((data->localData[0]->realVars[38] /* Chile.digester.S_va STATE(1) */)) * (DIVISION_SIM(((tmp0 * tmp0)) * (DIVISION_SIM(1.380384264602884e-05,(tmp1 * tmp1 * tmp1) + (1.380384264602884e-05) * (DIVISION_SIM((tmp2 * tmp2),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes)),"Chile.digester.a_h ^ 3.0 + 1.380384264602884e-05 * Chile.digester.a_h ^ 2.0 / Chile.digester.g_mono",equationIndexes)),208.2650980392157,"208.2650980392157",equationIndexes));
  TRACE_POP
}
/*
equation index: 2688
type: SIMPLE_ASSIGN
Chile.digester.S_bum = 160.1818181818182 * Chile.digester.a_bum / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2688(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2688};
  (data->localData[0]->realVars[434] /* Chile.digester.S_bum variable */) = (160.1818181818182) * (DIVISION_SIM((data->localData[0]->realVars[501] /* Chile.digester.a_bum variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes));
  TRACE_POP
}
/*
equation index: 2689
type: SIMPLE_ASSIGN
Chile.digester.S_acm = 64.05333333333333 * Chile.digester.a_acm / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2689(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2689};
  (data->localData[0]->realVars[431] /* Chile.digester.S_acm variable */) = (64.05333333333333) * (DIVISION_SIM((data->localData[0]->realVars[500] /* Chile.digester.a_acm variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes));
  TRACE_POP
}
/*
equation index: 2690
type: SIMPLE_ASSIGN
Chile.digester.S_prom = 112.1210810810811 * Chile.digester.a_prom / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2690(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2690};
  (data->localData[0]->realVars[459] /* Chile.digester.S_prom variable */) = (112.1210810810811) * (DIVISION_SIM((data->localData[0]->realVars[513] /* Chile.digester.a_prom variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes));
  TRACE_POP
}
/*
equation index: 2691
type: SIMPLE_ASSIGN
Chile.digester.S_vam = 208.2650980392157 * Chile.digester.a_vam / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2691(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2691};
  (data->localData[0]->realVars[462] /* Chile.digester.S_vam variable */) = (208.2650980392157) * (DIVISION_SIM((data->localData[0]->realVars[514] /* Chile.digester.a_vam variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes));
  TRACE_POP
}
/*
equation index: 2692
type: SIMPLE_ASSIGN
Chile.digester.S_hco3 = Chile.digester.a_hco3 / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2692(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2692};
  (data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */) = DIVISION_SIM((data->localData[0]->realVars[507] /* Chile.digester.a_hco3 variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes);
  TRACE_POP
}
/*
equation index: 2693
type: SIMPLE_ASSIGN
Chile.digester.S_co3 = Chile.digester.a_co3 / Chile.digester.g_bi
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2693(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2693};
  (data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */) = DIVISION_SIM((data->localData[0]->realVars[503] /* Chile.digester.a_co3 variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes);
  TRACE_POP
}
/*
equation index: 2694
type: SIMPLE_ASSIGN
Chile.digester.S_nh4 = Chile.digester.a_nh4 / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2694(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2694};
  (data->localData[0]->realVars[455] /* Chile.digester.S_nh4 variable */) = DIVISION_SIM((data->localData[0]->realVars[510] /* Chile.digester.a_nh4 variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes);
  TRACE_POP
}
/*
equation index: 2695
type: SIMPLE_ASSIGN
Chile.digester.S_hpo4 = Chile.digester.a_hpo4 / Chile.digester.g_bi
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2695(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2695};
  (data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */) = DIVISION_SIM((data->localData[0]->realVars[508] /* Chile.digester.a_hpo4 variable */),(data->localData[0]->realVars[538] /* Chile.digester.g_bi variable */),"Chile.digester.g_bi",equationIndexes);
  TRACE_POP
}
/*
equation index: 2696
type: SIMPLE_ASSIGN
Chile.digester.S_po4 = Chile.digester.a_po4 / Chile.digester.g_tri
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2696(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2696};
  (data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */) = DIVISION_SIM((data->localData[0]->realVars[512] /* Chile.digester.a_po4 variable */),(data->localData[0]->realVars[540] /* Chile.digester.g_tri variable */),"Chile.digester.g_tri",equationIndexes);
  TRACE_POP
}
/*
equation index: 2697
type: SIMPLE_ASSIGN
Chile.digester.S_h2po4 = (-2.0) * Chile.digester.ionic_force - ((-2.0) * Chile.digester.I + 4.0 * Chile.digester.S_ca + 9.0 * Chile.digester.S_po4 + Chile.digester.S_nh4 + 4.0 * Chile.digester.S_mg + 4.0 * Chile.digester.S_hpo4 + Chile.digester.S_hco3 + Chile.digester.S_cat + Chile.digester.S_an + 4.0 * Chile.digester.S_co3 + 0.0156119900083264 * Chile.digester.S_acm + 0.008918929342795433 * Chile.digester.S_prom + 0.006242905788876278 * Chile.digester.S_bum + 0.004801572656267654 * Chile.digester.S_vam)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2697(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2697};
  (data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */) = (-2.0) * ((data->localData[0]->realVars[65] /* Chile.digester.ionic_force STATE(1) */)) - ((-2.0) * ((data->localData[0]->realVars[337] /* Chile.digester.I variable */)) + (4.0) * ((data->localData[0]->realVars[21] /* Chile.digester.S_ca STATE(1) */)) + (9.0) * ((data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */)) + (data->localData[0]->realVars[455] /* Chile.digester.S_nh4 variable */) + (4.0) * ((data->localData[0]->realVars[35] /* Chile.digester.S_mg STATE(1) */)) + (4.0) * ((data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */)) + (data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */) + (data->localData[0]->realVars[22] /* Chile.digester.S_cat STATE(1) */) + (data->localData[0]->realVars[19] /* Chile.digester.S_an STATE(1) */) + (4.0) * ((data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */)) + (0.0156119900083264) * ((data->localData[0]->realVars[431] /* Chile.digester.S_acm variable */)) + (0.008918929342795433) * ((data->localData[0]->realVars[459] /* Chile.digester.S_prom variable */)) + (0.006242905788876278) * ((data->localData[0]->realVars[434] /* Chile.digester.S_bum variable */)) + (0.004801572656267654) * ((data->localData[0]->realVars[462] /* Chile.digester.S_vam variable */)));
  TRACE_POP
}
/*
equation index: 2698
type: SIMPLE_ASSIGN
Chile.digester.a_h2o = if noEvent(Chile.digester.ideality == true) then 1.0 else 1.0 - 0.017 * (Chile.digester.S_nh4 + Chile.digester.S_hco3 + Chile.digester.S_co3 + Chile.digester.S_h2po4 + Chile.digester.S_hpo4 + Chile.digester.S_po4 + Chile.digester.S_vam / 208.2650980392157 + Chile.digester.S_bum / 160.1818181818182 + Chile.digester.S_prom / 112.1210810810811 + Chile.digester.S_acm / 64.05333333333333 + Chile.digester.S_ca + Chile.digester.S_mg + Chile.digester.S_cat + Chile.digester.S_an)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2698(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2698};
  (data->localData[0]->realVars[505] /* Chile.digester.a_h2o variable */) = (((!(data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && !1) || ((data->simulationInfo->booleanParameter[12] /* Chile.digester.ideality PARAM */) && 1))?1.0:1.0 - ((0.017) * ((data->localData[0]->realVars[455] /* Chile.digester.S_nh4 variable */) + (data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */) + (data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */) + (data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */) + (data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */) + (data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */) + DIVISION_SIM((data->localData[0]->realVars[462] /* Chile.digester.S_vam variable */),208.2650980392157,"208.2650980392157",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[434] /* Chile.digester.S_bum variable */),160.1818181818182,"160.1818181818182",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[459] /* Chile.digester.S_prom variable */),112.1210810810811,"112.1210810810811",equationIndexes) + DIVISION_SIM((data->localData[0]->realVars[431] /* Chile.digester.S_acm variable */),64.05333333333333,"64.05333333333333",equationIndexes) + (data->localData[0]->realVars[21] /* Chile.digester.S_ca STATE(1) */) + (data->localData[0]->realVars[35] /* Chile.digester.S_mg STATE(1) */) + (data->localData[0]->realVars[22] /* Chile.digester.S_cat STATE(1) */) + (data->localData[0]->realVars[19] /* Chile.digester.S_an STATE(1) */))));
  TRACE_POP
}
/*
equation index: 2699
type: SIMPLE_ASSIGN
Chile.digester.a_oh = Chile.digester.Ka_h2o * Chile.digester.convKa * Chile.digester.a_h2o / Chile.digester.a_h
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2699(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2699};
  (data->localData[0]->realVars[511] /* Chile.digester.a_oh variable */) = ((data->localData[0]->realVars[370] /* Chile.digester.Ka_h2o variable */)) * (((data->simulationInfo->realParameter[315] /* Chile.digester.convKa PARAM */)) * (DIVISION_SIM((data->localData[0]->realVars[505] /* Chile.digester.a_h2o variable */),(data->localData[0]->realVars[504] /* Chile.digester.a_h variable */),"Chile.digester.a_h",equationIndexes)));
  TRACE_POP
}
/*
equation index: 2700
type: SIMPLE_ASSIGN
Chile.digester.S_oh = Chile.digester.a_oh / Chile.digester.g_mono
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2700(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2700};
  (data->localData[0]->realVars[456] /* Chile.digester.S_oh variable */) = DIVISION_SIM((data->localData[0]->realVars[511] /* Chile.digester.a_oh variable */),(data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */),"Chile.digester.g_mono",equationIndexes);
  TRACE_POP
}
/*
equation index: 2701
type: SIMPLE_ASSIGN
Chile.digester.S_h = Chile.digester.charge - (Chile.digester.S_cat + Chile.digester.S_nh4 + 2.0 * Chile.digester.S_ca + 2.0 * Chile.digester.S_mg + (-2.0) * Chile.digester.S_hpo4 + (-3.0) * Chile.digester.S_po4 + (-2.0) * Chile.digester.S_co3 + (-0.0156119900083264) * Chile.digester.S_acm - Chile.digester.S_hco3 + (-0.008918929342795433) * Chile.digester.S_prom + (-0.006242905788876278) * Chile.digester.S_bum + (-0.004801572656267654) * Chile.digester.S_vam - Chile.digester.S_an - Chile.digester.S_h2po4 - Chile.digester.S_oh)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2701(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2701};
  (data->localData[0]->realVars[440] /* Chile.digester.S_h variable */) = (data->localData[0]->realVars[64] /* Chile.digester.charge STATE(1) */) - ((data->localData[0]->realVars[22] /* Chile.digester.S_cat STATE(1) */) + (data->localData[0]->realVars[455] /* Chile.digester.S_nh4 variable */) + (2.0) * ((data->localData[0]->realVars[21] /* Chile.digester.S_ca STATE(1) */)) + (2.0) * ((data->localData[0]->realVars[35] /* Chile.digester.S_mg STATE(1) */)) + (-2.0) * ((data->localData[0]->realVars[445] /* Chile.digester.S_hpo4 variable */)) + (-3.0) * ((data->localData[0]->realVars[457] /* Chile.digester.S_po4 variable */)) + (-2.0) * ((data->localData[0]->realVars[439] /* Chile.digester.S_co3 variable */)) + (-0.0156119900083264) * ((data->localData[0]->realVars[431] /* Chile.digester.S_acm variable */)) - (data->localData[0]->realVars[444] /* Chile.digester.S_hco3 variable */) + (-0.008918929342795433) * ((data->localData[0]->realVars[459] /* Chile.digester.S_prom variable */)) + (-0.006242905788876278) * ((data->localData[0]->realVars[434] /* Chile.digester.S_bum variable */)) + (-0.004801572656267654) * ((data->localData[0]->realVars[462] /* Chile.digester.S_vam variable */)) - (data->localData[0]->realVars[19] /* Chile.digester.S_an STATE(1) */) - (data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */) - (data->localData[0]->realVars[456] /* Chile.digester.S_oh variable */));
  TRACE_POP
}

void residualFunc2734(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2734};
  int i,j;
  /* iteration variables */
  for (i=0; i<2; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc2734: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<2; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc2734 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */) = xloc[0];
  (data->localData[0]->realVars[645] /* Chile.digester.z variable */) = xloc[1];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2674(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2675(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2676(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2677(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2678(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2679(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2680(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2681(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2682(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2683(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2684(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2685(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2686(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2687(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2688(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2689(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2690(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2691(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2692(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2693(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2694(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2695(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2696(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2697(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2698(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2699(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2700(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2701(data, threadData);
  /* body */
  res[0] = (data->localData[0]->realVars[506] /* Chile.digester.a_h2po4 variable */) - (((data->localData[0]->realVars[442] /* Chile.digester.S_h2po4 variable */)) * ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)));

  res[1] = ((data->localData[0]->realVars[539] /* Chile.digester.g_mono variable */)) * ((data->localData[0]->realVars[440] /* Chile.digester.S_h variable */)) - (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS2734(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+2] = {0,2,2};
  const int rowIndex[4] = {0,1,0,1};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(2, 4, 2);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (2+1)*sizeof(unsigned int));
  
  for(i=2;i<2+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 4*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {1};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
  
  /* color 2 with 1 columns */
  const int indices_2[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_2[i]] = 2;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS2734(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 2;
  inSysData->nonlinearPattern->numberOfEqns = 2;
  inSysData->nonlinearPattern->numberOfNonlinear = 4;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((2+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((2+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(4*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(4*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+2] = {0,2,2};
  const int index_eqn[1+2] = {0,2,2};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (2+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (2+1)*sizeof(unsigned int));
  for(i=2;i<2+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<2+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[4] = {0,1,0,1};
  const int rows[4] = {0,1,0,1};
  memcpy(inSysData->nonlinearPattern->columns, columns, 4*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 4*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS2734(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.digester.a_h */
  sysData->nominal[i] = data->modelData->realVarsData[504].attribute /* Chile.digester.a_h */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[504].attribute /* Chile.digester.a_h */.min;
  sysData->max[i++]   = data->modelData->realVarsData[504].attribute /* Chile.digester.a_h */.max;
  /* static nls data for Chile.digester.z */
  sysData->nominal[i] = data->modelData->realVarsData[645].attribute /* Chile.digester.z */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[645].attribute /* Chile.digester.z */.min;
  sysData->max[i++]   = data->modelData->realVarsData[645].attribute /* Chile.digester.z */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS2734(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS2734(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS2734(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  array[1] = (data->localData[0]->realVars[645] /* Chile.digester.z variable */);
}


/* inner equations */

void residualFunc2741(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2741};
  int i,j;
  modelica_real tmp0;
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc2741: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc2741 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  tmp0 = 10.0;
  tmp1 = (-(data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */));
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }res[0] = tmp2 - (data->localData[0]->realVars[504] /* Chile.digester.a_h variable */);
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS2741(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = FALSE;
}
void initializeNonlinearPatternNLS2741(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no nonlinear pattern available */
}

OMC_DISABLE_OPT
void initializeStaticDataNLS2741(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.y_dig[1] */
  sysData->nominal[i] = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1230].attribute /* Chile.y_dig[1] */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS2741(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS2741(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS2741(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1230] /* Chile.y_dig[1] variable */);
}


/* inner equations */

/*
equation index: 2946
type: SIMPLE_ASSIGN
Chile.slurry.S_co3 = Chile.slurry.outlet.S_ic * Chile.slurry.Ka_hco3 / (Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2946(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2946};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */);
  (data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */) = ((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */),"Chile.slurry.S_h ^ 2.0 / Chile.slurry.Ka_co2 + Chile.slurry.S_h + Chile.slurry.Ka_hco3",equationIndexes));
  TRACE_POP
}
/*
equation index: 2947
type: SIMPLE_ASSIGN
Chile.slurry.S_hco3 = max(0.0, if Chile.slurry.liquid == false then Chile.slurry.outlet.S_ic * Chile.slurry.Ka_co2 / (Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h) else Chile.slurry.Alk_mol - (Chile.slurry.S_acm + Chile.slurry.S_prom + Chile.slurry.S_bum + Chile.slurry.S_vam) - Chile.slurry.S_oh - Chile.slurry.S_nh3 + Chile.slurry.S_h - Chile.slurry.S_hpo4 - 2.0 * Chile.slurry.S_po4 + Chile.slurry.S_h3po4 - 2.0 * Chile.slurry.S_co3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_2947(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2947};
  (data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */) = fmax(0.0,(((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes),"Chile.slurry.S_h + Chile.slurry.Ka_co2 + Chile.slurry.Ka_hco3 * Chile.slurry.Ka_co2 / Chile.slurry.S_h",equationIndexes):(data->localData[0]->realVars[876] /* Chile.slurry.Alk_mol variable */) - ((data->localData[0]->realVars[970] /* Chile.slurry.S_acm variable */) + (data->localData[0]->realVars[983] /* Chile.slurry.S_prom variable */) + (data->localData[0]->realVars[971] /* Chile.slurry.S_bum variable */) + (data->localData[0]->realVars[984] /* Chile.slurry.S_vam variable */)) - (data->localData[0]->realVars[981] /* Chile.slurry.S_oh variable */) - (data->localData[0]->realVars[979] /* Chile.slurry.S_nh3 variable */) + (data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) - (data->localData[0]->realVars[978] /* Chile.slurry.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[982] /* Chile.slurry.S_po4 variable */))) + (data->localData[0]->realVars[976] /* Chile.slurry.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[973] /* Chile.slurry.S_co3 variable */)))));
  TRACE_POP
}

void residualFunc2952(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,2952};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc2952: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc2952 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2946(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_2947(data, threadData);
  /* body */
  res[0] = (((!(data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[27] /* Chile.slurry.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[897] /* Chile.slurry.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[977] /* Chile.slurry.S_hco3 variable */)) * ((data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */) + (data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[929] /* Chile.slurry.Ka_hco3 variable */)) * ((data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */)),(data->localData[0]->realVars[974] /* Chile.slurry.S_h variable */),"Chile.slurry.S_h",equationIndexes)),(data->localData[0]->realVars[925] /* Chile.slurry.Ka_co2 variable */),"Chile.slurry.Ka_co2",equationIndexes)) - (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS2952(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS2952(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS2952(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.slurry.outlet.S_ic */
  sysData->nominal[i] = data->modelData->realVarsData[1016].attribute /* Chile.slurry.outlet.S_ic */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1016].attribute /* Chile.slurry.outlet.S_ic */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1016].attribute /* Chile.slurry.outlet.S_ic */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS2952(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS2952(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS2952(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1016] /* Chile.slurry.outlet.S_ic variable */);
}


/* inner equations */

/*
equation index: 3071
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_co3 = Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_hco3 / (Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3071(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3071};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */);
  (data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */) = ((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */),"Chile.tomatosouce.S_h ^ 2.0 / Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_hco3",equationIndexes));
  TRACE_POP
}
/*
equation index: 3072
type: SIMPLE_ASSIGN
Chile.tomatosouce.S_hco3 = max(0.0, if Chile.tomatosouce.liquid == false then Chile.tomatosouce.outlet.S_ic * Chile.tomatosouce.Ka_co2 / (Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h) else Chile.tomatosouce.Alk_mol - (Chile.tomatosouce.S_acm + Chile.tomatosouce.S_prom + Chile.tomatosouce.S_bum + Chile.tomatosouce.S_vam) - Chile.tomatosouce.S_oh - Chile.tomatosouce.S_nh3 + Chile.tomatosouce.S_h - Chile.tomatosouce.S_hpo4 - 2.0 * Chile.tomatosouce.S_po4 + Chile.tomatosouce.S_h3po4 - 2.0 * Chile.tomatosouce.S_co3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3072(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3072};
  (data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */) = fmax(0.0,(((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes),"Chile.tomatosouce.S_h + Chile.tomatosouce.Ka_co2 + Chile.tomatosouce.Ka_hco3 * Chile.tomatosouce.Ka_co2 / Chile.tomatosouce.S_h",equationIndexes):(data->localData[0]->realVars[1054] /* Chile.tomatosouce.Alk_mol variable */) - ((data->localData[0]->realVars[1148] /* Chile.tomatosouce.S_acm variable */) + (data->localData[0]->realVars[1161] /* Chile.tomatosouce.S_prom variable */) + (data->localData[0]->realVars[1149] /* Chile.tomatosouce.S_bum variable */) + (data->localData[0]->realVars[1162] /* Chile.tomatosouce.S_vam variable */)) - (data->localData[0]->realVars[1159] /* Chile.tomatosouce.S_oh variable */) - (data->localData[0]->realVars[1157] /* Chile.tomatosouce.S_nh3 variable */) + (data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) - (data->localData[0]->realVars[1156] /* Chile.tomatosouce.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[1160] /* Chile.tomatosouce.S_po4 variable */))) + (data->localData[0]->realVars[1154] /* Chile.tomatosouce.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[1151] /* Chile.tomatosouce.S_co3 variable */)))));
  TRACE_POP
}

void residualFunc3077(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,3077};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc3077: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc3077 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_3071(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_3072(data, threadData);
  /* body */
  res[0] = (((!(data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[29] /* Chile.tomatosouce.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[1103] /* Chile.tomatosouce.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[1155] /* Chile.tomatosouce.S_hco3 variable */)) * ((data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */) + (data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[1107] /* Chile.tomatosouce.Ka_hco3 variable */)) * ((data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */)),(data->localData[0]->realVars[1152] /* Chile.tomatosouce.S_h variable */),"Chile.tomatosouce.S_h",equationIndexes)),(data->localData[0]->realVars[1103] /* Chile.tomatosouce.Ka_co2 variable */),"Chile.tomatosouce.Ka_co2",equationIndexes)) - (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS3077(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS3077(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS3077(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.tomatosouce.outlet.S_ic */
  sysData->nominal[i] = data->modelData->realVarsData[1194].attribute /* Chile.tomatosouce.outlet.S_ic */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[1194].attribute /* Chile.tomatosouce.outlet.S_ic */.min;
  sysData->max[i++]   = data->modelData->realVarsData[1194].attribute /* Chile.tomatosouce.outlet.S_ic */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS3077(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS3077(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS3077(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[1194] /* Chile.tomatosouce.outlet.S_ic variable */);
}


/* inner equations */

/*
equation index: 3209
type: SIMPLE_ASSIGN
Chile.maize.S_co3 = Chile.maize.outlet.S_ic * Chile.maize.Ka_hco3 / (Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3209(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3209};
  modelica_real tmp0;
  tmp0 = (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */);
  (data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */) = ((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * (DIVISION_SIM((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),DIVISION_SIM((tmp0 * tmp0),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */),"Chile.maize.S_h ^ 2.0 / Chile.maize.Ka_co2 + Chile.maize.S_h + Chile.maize.Ka_hco3",equationIndexes));
  TRACE_POP
}
/*
equation index: 3210
type: SIMPLE_ASSIGN
Chile.maize.S_hco3 = max(0.0, if Chile.maize.liquid == false then Chile.maize.outlet.S_ic * Chile.maize.Ka_co2 / (Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h) else Chile.maize.Alk_mol - (Chile.maize.S_acm + Chile.maize.S_prom + Chile.maize.S_bum + Chile.maize.S_vam) - Chile.maize.S_oh - Chile.maize.S_nh3 + Chile.maize.S_h - Chile.maize.S_hpo4 - 2.0 * Chile.maize.S_po4 + Chile.maize.S_h3po4 - 2.0 * Chile.maize.S_co3)
*/
void ADM1_P_Chile_OL_MPC_eqFunction_3210(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3210};
  (data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */) = fmax(0.0,(((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM(((data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes),"Chile.maize.S_h + Chile.maize.Ka_co2 + Chile.maize.Ka_hco3 * Chile.maize.Ka_co2 / Chile.maize.S_h",equationIndexes):(data->localData[0]->realVars[690] /* Chile.maize.Alk_mol variable */) - ((data->localData[0]->realVars[784] /* Chile.maize.S_acm variable */) + (data->localData[0]->realVars[797] /* Chile.maize.S_prom variable */) + (data->localData[0]->realVars[785] /* Chile.maize.S_bum variable */) + (data->localData[0]->realVars[798] /* Chile.maize.S_vam variable */)) - (data->localData[0]->realVars[795] /* Chile.maize.S_oh variable */) - (data->localData[0]->realVars[793] /* Chile.maize.S_nh3 variable */) + (data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) - (data->localData[0]->realVars[792] /* Chile.maize.S_hpo4 variable */) - ((2.0) * ((data->localData[0]->realVars[796] /* Chile.maize.S_po4 variable */))) + (data->localData[0]->realVars[790] /* Chile.maize.S_h3po4 variable */) - ((2.0) * ((data->localData[0]->realVars[787] /* Chile.maize.S_co3 variable */)))));
  TRACE_POP
}

void residualFunc3215(RESIDUAL_USERDATA* userData, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = userData->data;
  threadData_t *threadData = userData->threadData;
  const int equationIndexes[2] = {1,3215};
  int i,j;
  /* iteration variables */
  for (i=0; i<1; i++) {
    if (isinf(xloc[i]) || isnan(xloc[i])) {
      errorStreamPrint(LOG_NLS, 0, "residualFunc3215: Iteration variable xloc[%i] is nan.", i);
      for (j=0; j<1; j++) {
        res[j] = NAN;
      }
      throwStreamPrintWithEquationIndexes(threadData, omc_dummyFileInfo, equationIndexes, "residualFunc3215 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
      return;
    }
  }
  (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */) = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_3209(data, threadData);

  /* local constraints */
  ADM1_P_Chile_OL_MPC_eqFunction_3210(data, threadData);
  /* body */
  res[0] = (((!(data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && !0) || ((data->simulationInfo->booleanParameter[23] /* Chile.maize.liquid PARAM */) && 0))?DIVISION_SIM((data->simulationInfo->realParameter[695] /* Chile.maize.tic PARAM */),12000.0,"12000.0",equationIndexes):DIVISION_SIM(((data->localData[0]->realVars[791] /* Chile.maize.S_hco3 variable */)) * ((data->localData[0]->realVars[788] /* Chile.maize.S_h variable */) + (data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */) + DIVISION_SIM(((data->localData[0]->realVars[743] /* Chile.maize.Ka_hco3 variable */)) * ((data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */)),(data->localData[0]->realVars[788] /* Chile.maize.S_h variable */),"Chile.maize.S_h",equationIndexes)),(data->localData[0]->realVars[739] /* Chile.maize.Ka_co2 variable */),"Chile.maize.Ka_co2",equationIndexes)) - (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */);
  /* restore known outputs */
  TRACE_POP
}

OMC_DISABLE_OPT
void initializeSparsePatternNLS3215(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = TRUE;
  inSysData->sparsePattern = allocSparsePattern(1, 1, 1);
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern->leadindex, colPtrIndex, (1+1)*sizeof(unsigned int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern->leadindex[i] += inSysData->sparsePattern->leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern->index, rowIndex, 1*sizeof(unsigned int));
  
  /* write color array */
  /* color 1 with 1 columns */
  const int indices_1[1] = {0};
  for(i=0; i<1; i++)
    inSysData->sparsePattern->colorCols[indices_1[i]] = 1;
}
OMC_DISABLE_OPT
void initializeNonlinearPatternNLS3215(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  inSysData->nonlinearPattern = (NONLINEAR_PATTERN*) malloc(sizeof(NONLINEAR_PATTERN));
  inSysData->nonlinearPattern->numberOfVars = 1;
  inSysData->nonlinearPattern->numberOfEqns = 1;
  inSysData->nonlinearPattern->numberOfNonlinear = 1;
  inSysData->nonlinearPattern->indexVar = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->indexEqn = (unsigned int*) malloc((1+1)*sizeof(unsigned int));
  inSysData->nonlinearPattern->columns = (unsigned int*) malloc(1*sizeof(unsigned int));
  inSysData->nonlinearPattern->rows = (unsigned int*) malloc(1*sizeof(unsigned int));
  /* initialize and accumulate index vectors */
  const int index_var[1+1] = {0,1};
  const int index_eqn[1+1] = {0,1};
  memcpy(inSysData->nonlinearPattern->indexVar, index_var, (1+1)*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->indexEqn, index_eqn, (1+1)*sizeof(unsigned int));
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexVar[i] += inSysData->nonlinearPattern->indexVar[i-1];
  for(i=2;i<1+1;++i)
    inSysData->nonlinearPattern->indexEqn[i] += inSysData->nonlinearPattern->indexEqn[i-1];
  /* initialize columns and rows */
  const int columns[1] = {0};
  const int rows[1] = {0};
  memcpy(inSysData->nonlinearPattern->columns, columns, 1*sizeof(unsigned int));
  memcpy(inSysData->nonlinearPattern->rows, rows, 1*sizeof(unsigned int));
}

OMC_DISABLE_OPT
void initializeStaticDataNLS3215(DATA* data, threadData_t *threadData, NONLINEAR_SYSTEM_DATA *sysData, modelica_boolean initSparsePattern, modelica_boolean initNonlinearPattern)
{
  int i=0;
  /* static nls data for Chile.maize.outlet.S_ic */
  sysData->nominal[i] = data->modelData->realVarsData[830].attribute /* Chile.maize.outlet.S_ic */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[830].attribute /* Chile.maize.outlet.S_ic */.min;
  sysData->max[i++]   = data->modelData->realVarsData[830].attribute /* Chile.maize.outlet.S_ic */.max;
  /* initial sparse pattern */
  if (initSparsePattern) {
    initializeSparsePatternNLS3215(sysData);
  }
  if (initNonlinearPattern) {
    initializeNonlinearPatternNLS3215(sysData);
  }
}

OMC_DISABLE_OPT
void getIterationVarsNLS3215(DATA* data, double *array)
{
  array[0] = (data->localData[0]->realVars[830] /* Chile.maize.outlet.S_ic variable */);
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void ADM1_P_Chile_OL_MPC_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[12].equationIndex = 3215;
  nonLinearSystemData[12].size = 1;
  nonLinearSystemData[12].homotopySupport = 0;
  nonLinearSystemData[12].mixedSystem = 0;
  nonLinearSystemData[12].residualFunc = residualFunc3215;
  nonLinearSystemData[12].strictTearingFunctionCall = NULL;
  nonLinearSystemData[12].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac14_column;
  nonLinearSystemData[12].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac14;
  nonLinearSystemData[12].jacobianIndex = 9 /*jacInx*/;
  nonLinearSystemData[12].initializeStaticNLSData = initializeStaticDataNLS3215;
  nonLinearSystemData[12].getIterationVars = getIterationVarsNLS3215;
  nonLinearSystemData[12].checkConstraints = NULL;
  
  
  nonLinearSystemData[11].equationIndex = 3077;
  nonLinearSystemData[11].size = 1;
  nonLinearSystemData[11].homotopySupport = 0;
  nonLinearSystemData[11].mixedSystem = 0;
  nonLinearSystemData[11].residualFunc = residualFunc3077;
  nonLinearSystemData[11].strictTearingFunctionCall = NULL;
  nonLinearSystemData[11].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac13_column;
  nonLinearSystemData[11].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac13;
  nonLinearSystemData[11].jacobianIndex = 8 /*jacInx*/;
  nonLinearSystemData[11].initializeStaticNLSData = initializeStaticDataNLS3077;
  nonLinearSystemData[11].getIterationVars = getIterationVarsNLS3077;
  nonLinearSystemData[11].checkConstraints = NULL;
  
  
  nonLinearSystemData[10].equationIndex = 2952;
  nonLinearSystemData[10].size = 1;
  nonLinearSystemData[10].homotopySupport = 0;
  nonLinearSystemData[10].mixedSystem = 0;
  nonLinearSystemData[10].residualFunc = residualFunc2952;
  nonLinearSystemData[10].strictTearingFunctionCall = NULL;
  nonLinearSystemData[10].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac12_column;
  nonLinearSystemData[10].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac12;
  nonLinearSystemData[10].jacobianIndex = 7 /*jacInx*/;
  nonLinearSystemData[10].initializeStaticNLSData = initializeStaticDataNLS2952;
  nonLinearSystemData[10].getIterationVars = getIterationVarsNLS2952;
  nonLinearSystemData[10].checkConstraints = NULL;
  
  
  nonLinearSystemData[9].equationIndex = 2741;
  nonLinearSystemData[9].size = 1;
  nonLinearSystemData[9].homotopySupport = 0;
  nonLinearSystemData[9].mixedSystem = 0;
  nonLinearSystemData[9].residualFunc = residualFunc2741;
  nonLinearSystemData[9].strictTearingFunctionCall = NULL;
  nonLinearSystemData[9].analyticalJacobianColumn = NULL;
  nonLinearSystemData[9].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[9].jacobianIndex = -1;
  nonLinearSystemData[9].initializeStaticNLSData = initializeStaticDataNLS2741;
  nonLinearSystemData[9].getIterationVars = getIterationVarsNLS2741;
  nonLinearSystemData[9].checkConstraints = NULL;
  
  
  nonLinearSystemData[8].equationIndex = 2734;
  nonLinearSystemData[8].size = 2;
  nonLinearSystemData[8].homotopySupport = 0;
  nonLinearSystemData[8].mixedSystem = 0;
  nonLinearSystemData[8].residualFunc = residualFunc2734;
  nonLinearSystemData[8].strictTearingFunctionCall = NULL;
  nonLinearSystemData[8].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac10_column;
  nonLinearSystemData[8].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac10;
  nonLinearSystemData[8].jacobianIndex = 6 /*jacInx*/;
  nonLinearSystemData[8].initializeStaticNLSData = initializeStaticDataNLS2734;
  nonLinearSystemData[8].getIterationVars = getIterationVarsNLS2734;
  nonLinearSystemData[8].checkConstraints = NULL;
  
  
  nonLinearSystemData[7].equationIndex = 1952;
  nonLinearSystemData[7].size = 1;
  nonLinearSystemData[7].homotopySupport = 0;
  nonLinearSystemData[7].mixedSystem = 0;
  nonLinearSystemData[7].residualFunc = residualFunc1952;
  nonLinearSystemData[7].strictTearingFunctionCall = NULL;
  nonLinearSystemData[7].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac9_column;
  nonLinearSystemData[7].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac9;
  nonLinearSystemData[7].jacobianIndex = 5 /*jacInx*/;
  nonLinearSystemData[7].initializeStaticNLSData = initializeStaticDataNLS1952;
  nonLinearSystemData[7].getIterationVars = getIterationVarsNLS1952;
  nonLinearSystemData[7].checkConstraints = NULL;
  
  
  nonLinearSystemData[6].equationIndex = 1829;
  nonLinearSystemData[6].size = 1;
  nonLinearSystemData[6].homotopySupport = 0;
  nonLinearSystemData[6].mixedSystem = 0;
  nonLinearSystemData[6].residualFunc = residualFunc1829;
  nonLinearSystemData[6].strictTearingFunctionCall = NULL;
  nonLinearSystemData[6].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac8_column;
  nonLinearSystemData[6].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac8;
  nonLinearSystemData[6].jacobianIndex = 4 /*jacInx*/;
  nonLinearSystemData[6].initializeStaticNLSData = initializeStaticDataNLS1829;
  nonLinearSystemData[6].getIterationVars = getIterationVarsNLS1829;
  nonLinearSystemData[6].checkConstraints = NULL;
  
  
  nonLinearSystemData[5].equationIndex = 1706;
  nonLinearSystemData[5].size = 1;
  nonLinearSystemData[5].homotopySupport = 0;
  nonLinearSystemData[5].mixedSystem = 0;
  nonLinearSystemData[5].residualFunc = residualFunc1706;
  nonLinearSystemData[5].strictTearingFunctionCall = NULL;
  nonLinearSystemData[5].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac7_column;
  nonLinearSystemData[5].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac7;
  nonLinearSystemData[5].jacobianIndex = 3 /*jacInx*/;
  nonLinearSystemData[5].initializeStaticNLSData = initializeStaticDataNLS1706;
  nonLinearSystemData[5].getIterationVars = getIterationVarsNLS1706;
  nonLinearSystemData[5].checkConstraints = NULL;
  
  
  nonLinearSystemData[4].equationIndex = 1563;
  nonLinearSystemData[4].size = 1;
  nonLinearSystemData[4].homotopySupport = 0;
  nonLinearSystemData[4].mixedSystem = 0;
  nonLinearSystemData[4].residualFunc = residualFunc1563;
  nonLinearSystemData[4].strictTearingFunctionCall = NULL;
  nonLinearSystemData[4].analyticalJacobianColumn = NULL;
  nonLinearSystemData[4].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[4].jacobianIndex = -1;
  nonLinearSystemData[4].initializeStaticNLSData = initializeStaticDataNLS1563;
  nonLinearSystemData[4].getIterationVars = getIterationVarsNLS1563;
  nonLinearSystemData[4].checkConstraints = NULL;
  
  
  nonLinearSystemData[3].equationIndex = 646;
  nonLinearSystemData[3].size = 1;
  nonLinearSystemData[3].homotopySupport = 0;
  nonLinearSystemData[3].mixedSystem = 0;
  nonLinearSystemData[3].residualFunc = residualFunc646;
  nonLinearSystemData[3].strictTearingFunctionCall = NULL;
  nonLinearSystemData[3].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac4_column;
  nonLinearSystemData[3].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac4;
  nonLinearSystemData[3].jacobianIndex = 2 /*jacInx*/;
  nonLinearSystemData[3].initializeStaticNLSData = initializeStaticDataNLS646;
  nonLinearSystemData[3].getIterationVars = getIterationVarsNLS646;
  nonLinearSystemData[3].checkConstraints = NULL;
  
  
  nonLinearSystemData[2].equationIndex = 523;
  nonLinearSystemData[2].size = 1;
  nonLinearSystemData[2].homotopySupport = 0;
  nonLinearSystemData[2].mixedSystem = 0;
  nonLinearSystemData[2].residualFunc = residualFunc523;
  nonLinearSystemData[2].strictTearingFunctionCall = NULL;
  nonLinearSystemData[2].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac3_column;
  nonLinearSystemData[2].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac3;
  nonLinearSystemData[2].jacobianIndex = 1 /*jacInx*/;
  nonLinearSystemData[2].initializeStaticNLSData = initializeStaticDataNLS523;
  nonLinearSystemData[2].getIterationVars = getIterationVarsNLS523;
  nonLinearSystemData[2].checkConstraints = NULL;
  
  
  nonLinearSystemData[1].equationIndex = 400;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc400;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = ADM1_P_Chile_OL_MPC_functionJacNLSJac2_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac2;
  nonLinearSystemData[1].jacobianIndex = 0 /*jacInx*/;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS400;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS400;
  nonLinearSystemData[1].checkConstraints = NULL;
  
  
  nonLinearSystemData[0].equationIndex = 257;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc257;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS257;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS257;
  nonLinearSystemData[0].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

