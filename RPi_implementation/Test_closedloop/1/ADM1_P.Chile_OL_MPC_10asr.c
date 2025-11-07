/* Asserts */
#include "ADM1_P.Chile_OL_MPC_model.h"
#if defined(__cplusplus)
extern "C" {
#endif


/*
equation index: 4979
type: ALGORITHM

  assert(Chile.maize.u >= 0.0 and Chile.maize.u <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.maize.u <= 1.0, has value: " + String(Chile.maize.u, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4979(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4979};
  modelica_boolean tmp2;
  modelica_boolean tmp3;
  static const MMC_DEFSTRINGLIT(tmp4,79,"Variable violating min/max constraint: 0.0 <= Chile.maize.u <= 1.0, has value: ");
  modelica_string tmp5;
  modelica_metatype tmpMeta6;
  static int tmp7 = 0;
  if(!tmp7)
  {
    tmp2 = GreaterEq((data->localData[0]->realVars[863] /* Chile.maize.u variable */),0.0);
    tmp3 = LessEq((data->localData[0]->realVars[863] /* Chile.maize.u variable */),1.0);
    if(!(tmp2 && tmp3))
    {
      tmp5 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[863] /* Chile.maize.u variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta6 = stringAppend(MMC_REFSTRINGLIT(tmp4),tmp5);
      {
        const char* assert_cond = "(Chile.maize.u >= 0.0 and Chile.maize.u <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta6));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta6));
        }
      }
      tmp7 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4980
type: ALGORITHM

  assert(Chile.maize.v >= 0.0 and Chile.maize.v <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.maize.v <= 1.0, has value: " + String(Chile.maize.v, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4980(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4980};
  modelica_boolean tmp8;
  modelica_boolean tmp9;
  static const MMC_DEFSTRINGLIT(tmp10,79,"Variable violating min/max constraint: 0.0 <= Chile.maize.v <= 1.0, has value: ");
  modelica_string tmp11;
  modelica_metatype tmpMeta12;
  static int tmp13 = 0;
  if(!tmp13)
  {
    tmp8 = GreaterEq((data->localData[0]->realVars[864] /* Chile.maize.v variable */),0.0);
    tmp9 = LessEq((data->localData[0]->realVars[864] /* Chile.maize.v variable */),1.0);
    if(!(tmp8 && tmp9))
    {
      tmp11 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[864] /* Chile.maize.v variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta12 = stringAppend(MMC_REFSTRINGLIT(tmp10),tmp11);
      {
        const char* assert_cond = "(Chile.maize.v >= 0.0 and Chile.maize.v <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta12));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta12));
        }
      }
      tmp13 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4981
type: ALGORITHM

  assert(Chile.maize.d >= 0.0, "Variable violating min constraint: 0.0 <= Chile.maize.d, has value: " + String(Chile.maize.d, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4981(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4981};
  modelica_boolean tmp14;
  static const MMC_DEFSTRINGLIT(tmp15,68,"Variable violating min constraint: 0.0 <= Chile.maize.d, has value: ");
  modelica_string tmp16;
  modelica_metatype tmpMeta17;
  static int tmp18 = 0;
  if(!tmp18)
  {
    tmp14 = GreaterEq((data->localData[0]->realVars[810] /* Chile.maize.d variable */),0.0);
    if(!tmp14)
    {
      tmp16 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[810] /* Chile.maize.d variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta17 = stringAppend(MMC_REFSTRINGLIT(tmp15),tmp16);
      {
        const char* assert_cond = "(Chile.maize.d >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta17));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta17));
        }
      }
      tmp18 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4982
type: ALGORITHM

  assert(Chile.slurry.u >= 0.0 and Chile.slurry.u <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.slurry.u <= 1.0, has value: " + String(Chile.slurry.u, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4982(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4982};
  modelica_boolean tmp19;
  modelica_boolean tmp20;
  static const MMC_DEFSTRINGLIT(tmp21,80,"Variable violating min/max constraint: 0.0 <= Chile.slurry.u <= 1.0, has value: ");
  modelica_string tmp22;
  modelica_metatype tmpMeta23;
  static int tmp24 = 0;
  if(!tmp24)
  {
    tmp19 = GreaterEq((data->localData[0]->realVars[1049] /* Chile.slurry.u variable */),0.0);
    tmp20 = LessEq((data->localData[0]->realVars[1049] /* Chile.slurry.u variable */),1.0);
    if(!(tmp19 && tmp20))
    {
      tmp22 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1049] /* Chile.slurry.u variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta23 = stringAppend(MMC_REFSTRINGLIT(tmp21),tmp22);
      {
        const char* assert_cond = "(Chile.slurry.u >= 0.0 and Chile.slurry.u <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta23));
        }
      }
      tmp24 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4983
type: ALGORITHM

  assert(Chile.slurry.v >= 0.0 and Chile.slurry.v <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.slurry.v <= 1.0, has value: " + String(Chile.slurry.v, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4983(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4983};
  modelica_boolean tmp25;
  modelica_boolean tmp26;
  static const MMC_DEFSTRINGLIT(tmp27,80,"Variable violating min/max constraint: 0.0 <= Chile.slurry.v <= 1.0, has value: ");
  modelica_string tmp28;
  modelica_metatype tmpMeta29;
  static int tmp30 = 0;
  if(!tmp30)
  {
    tmp25 = GreaterEq((data->localData[0]->realVars[1050] /* Chile.slurry.v variable */),0.0);
    tmp26 = LessEq((data->localData[0]->realVars[1050] /* Chile.slurry.v variable */),1.0);
    if(!(tmp25 && tmp26))
    {
      tmp28 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1050] /* Chile.slurry.v variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta29 = stringAppend(MMC_REFSTRINGLIT(tmp27),tmp28);
      {
        const char* assert_cond = "(Chile.slurry.v >= 0.0 and Chile.slurry.v <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta29));
        }
      }
      tmp30 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4984
type: ALGORITHM

  assert(Chile.slurry.d >= 0.0, "Variable violating min constraint: 0.0 <= Chile.slurry.d, has value: " + String(Chile.slurry.d, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4984(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4984};
  modelica_boolean tmp31;
  static const MMC_DEFSTRINGLIT(tmp32,69,"Variable violating min constraint: 0.0 <= Chile.slurry.d, has value: ");
  modelica_string tmp33;
  modelica_metatype tmpMeta34;
  static int tmp35 = 0;
  if(!tmp35)
  {
    tmp31 = GreaterEq((data->localData[0]->realVars[996] /* Chile.slurry.d variable */),0.0);
    if(!tmp31)
    {
      tmp33 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[996] /* Chile.slurry.d variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta34 = stringAppend(MMC_REFSTRINGLIT(tmp32),tmp33);
      {
        const char* assert_cond = "(Chile.slurry.d >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta34));
        }
      }
      tmp35 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4985
type: ALGORITHM

  assert(Chile.tomatosouce.u >= 0.0 and Chile.tomatosouce.u <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.tomatosouce.u <= 1.0, has value: " + String(Chile.tomatosouce.u, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4985(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4985};
  modelica_boolean tmp36;
  modelica_boolean tmp37;
  static const MMC_DEFSTRINGLIT(tmp38,85,"Variable violating min/max constraint: 0.0 <= Chile.tomatosouce.u <= 1.0, has value: ");
  modelica_string tmp39;
  modelica_metatype tmpMeta40;
  static int tmp41 = 0;
  if(!tmp41)
  {
    tmp36 = GreaterEq((data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */),0.0);
    tmp37 = LessEq((data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */),1.0);
    if(!(tmp36 && tmp37))
    {
      tmp39 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1227] /* Chile.tomatosouce.u variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta40 = stringAppend(MMC_REFSTRINGLIT(tmp38),tmp39);
      {
        const char* assert_cond = "(Chile.tomatosouce.u >= 0.0 and Chile.tomatosouce.u <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",123,5,123,92,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta40));
        }
      }
      tmp41 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4986
type: ALGORITHM

  assert(Chile.tomatosouce.v >= 0.0 and Chile.tomatosouce.v <= 1.0, "Variable violating min/max constraint: 0.0 <= Chile.tomatosouce.v <= 1.0, has value: " + String(Chile.tomatosouce.v, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4986(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4986};
  modelica_boolean tmp42;
  modelica_boolean tmp43;
  static const MMC_DEFSTRINGLIT(tmp44,85,"Variable violating min/max constraint: 0.0 <= Chile.tomatosouce.v <= 1.0, has value: ");
  modelica_string tmp45;
  modelica_metatype tmpMeta46;
  static int tmp47 = 0;
  if(!tmp47)
  {
    tmp42 = GreaterEq((data->localData[0]->realVars[1228] /* Chile.tomatosouce.v variable */),0.0);
    tmp43 = LessEq((data->localData[0]->realVars[1228] /* Chile.tomatosouce.v variable */),1.0);
    if(!(tmp42 && tmp43))
    {
      tmp45 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1228] /* Chile.tomatosouce.v variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta46 = stringAppend(MMC_REFSTRINGLIT(tmp44),tmp45);
      {
        const char* assert_cond = "(Chile.tomatosouce.v >= 0.0 and Chile.tomatosouce.v <= 1.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",124,5,124,110,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta46));
        }
      }
      tmp47 = 1;
    }
  }
  TRACE_POP
}

/*
equation index: 4987
type: ALGORITHM

  assert(Chile.tomatosouce.d >= 0.0, "Variable violating min constraint: 0.0 <= Chile.tomatosouce.d, has value: " + String(Chile.tomatosouce.d, "g"));
*/
void ADM1_P_Chile_OL_MPC_eqFunction_4987(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,4987};
  modelica_boolean tmp48;
  static const MMC_DEFSTRINGLIT(tmp49,74,"Variable violating min constraint: 0.0 <= Chile.tomatosouce.d, has value: ");
  modelica_string tmp50;
  modelica_metatype tmpMeta51;
  static int tmp52 = 0;
  if(!tmp52)
  {
    tmp48 = GreaterEq((data->localData[0]->realVars[1174] /* Chile.tomatosouce.d variable */),0.0);
    if(!tmp48)
    {
      tmp50 = modelica_real_to_modelica_string_format((data->localData[0]->realVars[1174] /* Chile.tomatosouce.d variable */), (modelica_string) mmc_strings_len1[103]);
      tmpMeta51 = stringAppend(MMC_REFSTRINGLIT(tmp49),tmp50);
      {
        const char* assert_cond = "(Chile.tomatosouce.d >= 0.0)";
        if (data->simulationInfo->noThrowAsserts) {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          infoStreamPrintWithEquationIndexes(LOG_ASSERT, info, 0, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta51));
        } else {
          FILE_INFO info = {"C:/Users/lenovo/OneDrive - Politecnico di Milano/Work_cloud/DOTTORATO/Sperimentazione MPC/NMPC/Real_old/Real_offline/agriAcoDM_03.03.2025_DC.mo",125,5,125,74,0};
          omc_assert_warning_withEquationIndexes(info, equationIndexes, "The following assertion has been violated %sat time %f\n(%s) --> \"%s\"", initial() ? "during initialization " : "", data->localData[0]->timeValue, assert_cond, MMC_STRINGDATA(tmpMeta51));
        }
      }
      tmp52 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
OMC_DISABLE_OPT
int ADM1_P_Chile_OL_MPC_checkForAsserts(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  ADM1_P_Chile_OL_MPC_eqFunction_4979(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4980(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4981(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4982(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4983(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4984(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4985(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4986(data, threadData);

  ADM1_P_Chile_OL_MPC_eqFunction_4987(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

