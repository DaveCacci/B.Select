/* External objects file */
#include "ADM1_P.Chile_OL_MPC_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

void ADM1_P_Chile_OL_MPC_callExternalObjectDestructors(DATA *data, threadData_t *threadData)
{
  if(data->simulationInfo->extObjs)
  {
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[4]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[0]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[1]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[3]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[2]));
    omc_Modelica_Blocks_Types_ExternalCombiTimeTable_destructor(threadData,(data->simulationInfo->extObjs[5]));
    free(data->simulationInfo->extObjs);
    data->simulationInfo->extObjs = 0;
  }
}
#if defined(__cplusplus)
}
#endif

