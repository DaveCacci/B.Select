/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;

#if defined(__cplusplus)
extern "C" {
#endif

/* Jacobian Variables */
#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac2 0
int ADM1_P_Chile_OL_MPC_functionJacNLSJac2_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac2(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac3 1
int ADM1_P_Chile_OL_MPC_functionJacNLSJac3_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac3(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac4 2
int ADM1_P_Chile_OL_MPC_functionJacNLSJac4_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac4(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac7 3
int ADM1_P_Chile_OL_MPC_functionJacNLSJac7_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac7(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac8 4
int ADM1_P_Chile_OL_MPC_functionJacNLSJac8_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac8(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac9 5
int ADM1_P_Chile_OL_MPC_functionJacNLSJac9_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac9(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac10 6
int ADM1_P_Chile_OL_MPC_functionJacNLSJac10_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac10(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac12 7
int ADM1_P_Chile_OL_MPC_functionJacNLSJac12_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac12(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac13 8
int ADM1_P_Chile_OL_MPC_functionJacNLSJac13_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac13(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_NLSJac14 9
int ADM1_P_Chile_OL_MPC_functionJacNLSJac14_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianNLSJac14(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_H 10
int ADM1_P_Chile_OL_MPC_functionJacH_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianH(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_F 11
int ADM1_P_Chile_OL_MPC_functionJacF_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianF(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_D 12
int ADM1_P_Chile_OL_MPC_functionJacD_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianD(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_C 13
int ADM1_P_Chile_OL_MPC_functionJacC_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianC(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_B 14
int ADM1_P_Chile_OL_MPC_functionJacB_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianB(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);


#define ADM1_P_Chile_OL_MPC_INDEX_JAC_A 15
int ADM1_P_Chile_OL_MPC_functionJacA_column(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *thisJacobian, ANALYTIC_JACOBIAN *parentJacobian);
int ADM1_P_Chile_OL_MPC_initialAnalyticJacobianA(DATA* data, threadData_t *threadData, ANALYTIC_JACOBIAN *jacobian);

#if defined(__cplusplus)
}
#endif

