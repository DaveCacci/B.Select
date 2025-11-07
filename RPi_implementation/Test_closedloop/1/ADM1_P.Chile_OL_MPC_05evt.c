/* Events: Sample, Zero Crossings, Relations, Discrete Changes */
#include "ADM1_P.Chile_OL_MPC_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* Initializes the raw time events of the simulation using the now
   calcualted parameters. */
void ADM1_P_Chile_OL_MPC_function_initSample(DATA *data, threadData_t *threadData)
{
  long i=0;
  /* sample 1 */
  data->modelData->samplesInfo[i].index = 1;
  data->modelData->samplesInfo[i].start = 0.0;
  data->modelData->samplesInfo[i].interval = 86400.0 /* (max int for single time events) */;
  i++;
}

const char *ADM1_P_Chile_OL_MPC_zeroCrossingDescription(int i, int **out_EquationIndexes)
{
  static const char *res[] = {"time >= pre(Manual_flowrates.nextTimeEvent)",
  "integer((time - Chile.digester.trapezoid.startTime) / Chile.digester.trapezoid.period) > pre(Chile.digester.trapezoid.count)",
  "integer((time - Chile.digester.trapezoid.startTime) / Chile.digester.trapezoid.period, 0)",
  "time >= pre(Chile.comp_maize.nextTimeEvent)",
  "time >= pre(Chile.comp_tomatosouce.nextTimeEvent)",
  "time >= pre(Chile.comp_slurry_real.nextTimeEvent)",
  "time >= pre(Manual_flowrates_real.nextTimeEvent)",
  "time < Chile.digester.trapezoid.startTime or Chile.digester.trapezoid.nperiod == 0 or Chile.digester.trapezoid.nperiod > 0 and Chile.digester.trapezoid.count >= Chile.digester.trapezoid.nperiod",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_rising",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_width",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_falling",
  "time >= pre(Chile.comp_slurry.nextTimeEvent)",
  "abs(time - pump_onoff.tfr_pump) < 60.0 and impulse",
  "time < tomatosouce_step.startTime",
  "time > pre(pump_onoff.tfr_pump) + $cse9"};
  static const int occurEqs0[] = {1,2606};
  static const int occurEqs1[] = {1,2608};
  static const int occurEqs2[] = {1,2608};
  static const int occurEqs3[] = {1,2612};
  static const int occurEqs4[] = {1,2606};
  static const int occurEqs5[] = {1,2899};
  static const int occurEqs6[] = {1,2842};
  static const int occurEqs7[] = {1,3364};
  static const int occurEqs8[] = {1,3364};
  static const int occurEqs9[] = {1,3364};
  static const int occurEqs10[] = {1,3364};
  static const int occurEqs11[] = {1,2830};
  static const int occurEqs12[] = {1,2609};
  static const int occurEqs13[] = {1,2611};
  static const int occurEqs14[] = {1,2608};
  static const int *occurEqs[] = {occurEqs0,occurEqs1,occurEqs2,occurEqs3,occurEqs4,occurEqs5,occurEqs6,occurEqs7,occurEqs8,occurEqs9,occurEqs10,occurEqs11,occurEqs12,occurEqs13,occurEqs14};
  *out_EquationIndexes = (int*) occurEqs[i];
  return res[i];
}

/* forwarded equations */
extern void ADM1_P_Chile_OL_MPC_eqFunction_3361(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3418(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3419(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3420(DATA* data, threadData_t *threadData);
extern void ADM1_P_Chile_OL_MPC_eqFunction_3421(DATA* data, threadData_t *threadData);

int ADM1_P_Chile_OL_MPC_function_ZeroCrossingsEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->callStatistics.functionZeroCrossingsEquations++;

  ADM1_P_Chile_OL_MPC_eqFunction_3361(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3418(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3419(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3420(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_3421(data, threadData);
  
  TRACE_POP
  return 0;
}

int ADM1_P_Chile_OL_MPC_function_ZeroCrossings(DATA *data, threadData_t *threadData, double *gout)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp0;
  modelica_boolean tmp1;
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  modelica_boolean tmp4;
  modelica_boolean tmp5;
  modelica_boolean tmp6;
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  modelica_boolean tmp10;
  modelica_boolean tmp11;
  modelica_boolean tmp12;
  modelica_boolean tmp13;
  modelica_boolean tmp14;
  modelica_boolean tmp15;
  modelica_boolean tmp16;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_tick(SIM_TIMER_ZC);
#endif
  data->simulationInfo->callStatistics.functionZeroCrossings++;

  tmp0 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1260] /* Manual_flowrates.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[0]);
  gout[0] = (tmp0) ? 1 : -1;

  tmp1 = Greater(((modelica_integer)floor(DIVISION(data->localData[0]->timeValue - (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */),(data->simulationInfo->realParameter[441] /* Chile.digester.trapezoid.period PARAM */),"Chile.digester.trapezoid.period"))),(data->simulationInfo->integerVarsPre[0] /* Chile.digester.trapezoid.count DISCRETE */));
  gout[1] = (tmp1) ? 1 : -1;

  gout[2] = (floor(DIVISION(data->localData[0]->timeValue - (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */),(data->simulationInfo->realParameter[441] /* Chile.digester.trapezoid.period PARAM */),"Chile.digester.trapezoid.period")) != floor(data->simulationInfo->mathEventsValuePre[((modelica_integer) 0)])) ? 1 : -1;

  tmp2 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1251] /* Chile.comp_maize.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[2]);
  gout[3] = (tmp2) ? 1 : -1;

  tmp3 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1257] /* Chile.comp_tomatosouce.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[3]);
  gout[4] = (tmp3) ? 1 : -1;

  tmp4 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1255] /* Chile.comp_slurry_real.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[4]);
  gout[5] = (tmp4) ? 1 : -1;

  tmp5 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1262] /* Manual_flowrates_real.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[5]);
  gout[6] = (tmp5) ? 1 : -1;

  tmp6 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */), data->simulationInfo->storedRelations[6]);
  tmp8 = Greater((data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */),((modelica_integer) 0));
  tmp9 = GreaterEq((data->localData[0]->integerVars[0] /* Chile.digester.trapezoid.count DISCRETE */),(data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */));
  gout[7] = (((tmp6 || ((data->simulationInfo->integerParameter[124] /* Chile.digester.trapezoid.nperiod PARAM */) == ((modelica_integer) 0))) || (tmp8 && tmp9))) ? 1 : -1;

  tmp10 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[436] /* Chile.digester.trapezoid.T_rising PARAM */), data->simulationInfo->storedRelations[7]);
  gout[8] = (tmp10) ? 1 : -1;

  tmp11 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[437] /* Chile.digester.trapezoid.T_width PARAM */), data->simulationInfo->storedRelations[8]);
  gout[9] = (tmp11) ? 1 : -1;

  tmp12 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[435] /* Chile.digester.trapezoid.T_falling PARAM */), data->simulationInfo->storedRelations[9]);
  gout[10] = (tmp12) ? 1 : -1;

  tmp13 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1253] /* Chile.comp_slurry.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[10]);
  gout[11] = (tmp13) ? 1 : -1;

  tmp14 = LessZC(fabs(data->localData[0]->timeValue - (data->localData[0]->realVars[1264] /* pump_onoff.tfr_pump DISCRETE */)), 60.0, data->simulationInfo->storedRelations[11]);
  gout[12] = ((tmp14 && (data->simulationInfo->booleanParameter[37] /* impulse PARAM */))) ? 1 : -1;

  tmp15 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[1259] /* tomatosouce_step.startTime PARAM */), data->simulationInfo->storedRelations[12]);
  gout[13] = (tmp15) ? 1 : -1;

  tmp16 = GreaterZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1264] /* pump_onoff.tfr_pump DISCRETE */) + (data->localData[0]->realVars[155] /* $cse9 variable */), data->simulationInfo->storedRelations[13]);
  gout[14] = (tmp16) ? 1 : -1;

#if !defined(OMC_MINIMAL_RUNTIME)
  if (measure_time_flag) rt_accumulate(SIM_TIMER_ZC);
#endif

  TRACE_POP
  return 0;
}

const char *ADM1_P_Chile_OL_MPC_relationDescription(int i)
{
  const char *res[] = {"time >= pre(Manual_flowrates.nextTimeEvent)",
  "integer((time - Chile.digester.trapezoid.startTime) / Chile.digester.trapezoid.period) > pre(Chile.digester.trapezoid.count)",
  "time >= pre(Chile.comp_maize.nextTimeEvent)",
  "time >= pre(Chile.comp_tomatosouce.nextTimeEvent)",
  "time >= pre(Chile.comp_slurry_real.nextTimeEvent)",
  "time >= pre(Manual_flowrates_real.nextTimeEvent)",
  "time < Chile.digester.trapezoid.startTime",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_rising",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_width",
  "time < Chile.digester.trapezoid.T_start + Chile.digester.trapezoid.T_falling",
  "time >= pre(Chile.comp_slurry.nextTimeEvent)",
  "abs(time - pump_onoff.tfr_pump) < 60.0",
  "time < tomatosouce_step.startTime",
  "time > pre(pump_onoff.tfr_pump) + $cse9"};
  return res[i];
}

int ADM1_P_Chile_OL_MPC_function_updateRelations(DATA *data, threadData_t *threadData, int evalforZeroCross)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;

  modelica_boolean tmp17;
  modelica_boolean tmp18;
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  modelica_boolean tmp21;
  modelica_boolean tmp22;
  modelica_boolean tmp23;
  modelica_boolean tmp24;
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  modelica_boolean tmp27;
  modelica_boolean tmp28;
  modelica_boolean tmp29;
  modelica_boolean tmp30;
  
  if(evalforZeroCross) {
    tmp17 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1260] /* Manual_flowrates.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[0]);
    data->simulationInfo->relations[0] = tmp17;

    tmp18 = Greater(((modelica_integer)floor(DIVISION(data->localData[0]->timeValue - (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */),(data->simulationInfo->realParameter[441] /* Chile.digester.trapezoid.period PARAM */),"Chile.digester.trapezoid.period"))),(data->simulationInfo->integerVarsPre[0] /* Chile.digester.trapezoid.count DISCRETE */));
    data->simulationInfo->relations[1] = tmp18;

    tmp19 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1251] /* Chile.comp_maize.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[2]);
    data->simulationInfo->relations[2] = tmp19;

    tmp20 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1257] /* Chile.comp_tomatosouce.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[3]);
    data->simulationInfo->relations[3] = tmp20;

    tmp21 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1255] /* Chile.comp_slurry_real.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[4]);
    data->simulationInfo->relations[4] = tmp21;

    tmp22 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1262] /* Manual_flowrates_real.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[5]);
    data->simulationInfo->relations[5] = tmp22;

    tmp23 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */), data->simulationInfo->storedRelations[6]);
    data->simulationInfo->relations[6] = tmp23;

    tmp24 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[436] /* Chile.digester.trapezoid.T_rising PARAM */), data->simulationInfo->storedRelations[7]);
    data->simulationInfo->relations[7] = tmp24;

    tmp25 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[437] /* Chile.digester.trapezoid.T_width PARAM */), data->simulationInfo->storedRelations[8]);
    data->simulationInfo->relations[8] = tmp25;

    tmp26 = LessZC(data->localData[0]->timeValue, (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[435] /* Chile.digester.trapezoid.T_falling PARAM */), data->simulationInfo->storedRelations[9]);
    data->simulationInfo->relations[9] = tmp26;

    tmp27 = GreaterEqZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1253] /* Chile.comp_slurry.nextTimeEvent DISCRETE */), data->simulationInfo->storedRelations[10]);
    data->simulationInfo->relations[10] = tmp27;

    tmp28 = LessZC(fabs(data->localData[0]->timeValue - (data->localData[0]->realVars[1264] /* pump_onoff.tfr_pump DISCRETE */)), 60.0, data->simulationInfo->storedRelations[11]);
    data->simulationInfo->relations[11] = tmp28;

    tmp29 = LessZC(data->localData[0]->timeValue, (data->simulationInfo->realParameter[1259] /* tomatosouce_step.startTime PARAM */), data->simulationInfo->storedRelations[12]);
    data->simulationInfo->relations[12] = tmp29;

    tmp30 = GreaterZC(data->localData[0]->timeValue, (data->simulationInfo->realVarsPre[1264] /* pump_onoff.tfr_pump DISCRETE */) + (data->localData[0]->realVars[155] /* $cse9 variable */), data->simulationInfo->storedRelations[13]);
    data->simulationInfo->relations[13] = tmp30;
  } else {
    data->simulationInfo->relations[0] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1260] /* Manual_flowrates.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[1] = (((modelica_integer)floor(DIVISION(data->localData[0]->timeValue - (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */),(data->simulationInfo->realParameter[441] /* Chile.digester.trapezoid.period PARAM */),"Chile.digester.trapezoid.period"))) > (data->simulationInfo->integerVarsPre[0] /* Chile.digester.trapezoid.count DISCRETE */));

    data->simulationInfo->relations[2] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1251] /* Chile.comp_maize.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[3] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1257] /* Chile.comp_tomatosouce.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[4] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1255] /* Chile.comp_slurry_real.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[5] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1262] /* Manual_flowrates_real.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[6] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[443] /* Chile.digester.trapezoid.startTime PARAM */));

    data->simulationInfo->relations[7] = (data->localData[0]->timeValue < (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[436] /* Chile.digester.trapezoid.T_rising PARAM */));

    data->simulationInfo->relations[8] = (data->localData[0]->timeValue < (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[437] /* Chile.digester.trapezoid.T_width PARAM */));

    data->simulationInfo->relations[9] = (data->localData[0]->timeValue < (data->localData[0]->realVars[1259] /* Chile.digester.trapezoid.T_start DISCRETE */) + (data->simulationInfo->realParameter[435] /* Chile.digester.trapezoid.T_falling PARAM */));

    data->simulationInfo->relations[10] = (data->localData[0]->timeValue >= (data->simulationInfo->realVarsPre[1253] /* Chile.comp_slurry.nextTimeEvent DISCRETE */));

    data->simulationInfo->relations[11] = (fabs(data->localData[0]->timeValue - (data->localData[0]->realVars[1264] /* pump_onoff.tfr_pump DISCRETE */)) < 60.0);

    data->simulationInfo->relations[12] = (data->localData[0]->timeValue < (data->simulationInfo->realParameter[1259] /* tomatosouce_step.startTime PARAM */));

    data->simulationInfo->relations[13] = (data->localData[0]->timeValue > (data->simulationInfo->realVarsPre[1264] /* pump_onoff.tfr_pump DISCRETE */) + (data->localData[0]->realVars[155] /* $cse9 variable */));
  }
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

