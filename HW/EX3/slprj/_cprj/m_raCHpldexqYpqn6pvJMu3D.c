/* Include files */

#include "modelInterface.h"
#include "m_raCHpldexqYpqn6pvJMu3D.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static real_T ground = 0.0;

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static void Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void b_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void c_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void d_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void e_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void f_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void g_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static const mxArray *emlrt_marshallOut(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *u, cgxertBlkSrcLocInfo *blkSrc);
static int32_T b_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T c_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc);
static void cgxe_mdl_set_sim_state(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *st);
static int32_T d_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc);
static void init_simulink_io_address(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 5,
    SS_CALL_MDL_START);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 7,
    SS_CALL_MDL_START);
}

static void cgxe_mdl_initialize(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  *moduleInstance->pipeStage = 0;
  moduleInstance->sectionProfiles = cgxertCreateSectionProfiles(7U);
}

static void cgxe_mdl_outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  cgxertStartProfiling(moduleInstance->sectionProfiles, 0U);
  Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 0U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 1U);
  b_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 1U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 2U);
  c_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 2U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 3U);
  d_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 3U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 4U);
  e_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 4U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 5U);
  f_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 5U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 6U);
  g_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 6U);
}

static void cgxe_mdl_update(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  uint32_T sectionBlkIds[7] = { 0U, 1U, 2U, 3U, 4U, 5U, 7U };

  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 5,
    SS_CALL_MDL_TERMINATE);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 7,
    SS_CALL_MDL_TERMINATE);
  cgxertExportToEngineSectionProfiles(moduleInstance->sectionProfiles,
    sectionBlkIds, moduleInstance->S);
  cgxertDestroySectionProfiles(moduleInstance->sectionProfiles);
}

static void Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  moduleInstance->B0_Y0 = ground;
  moduleInstance->B0_Y1 = ground;
  moduleInstance->B0_Y2 = ground;
  moduleInstance->B0_Y3 = ground;
}

static void b_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  moduleInstance->B1_Y0 = ((moduleInstance->B0_Y0 + moduleInstance->B0_Y1) +
    moduleInstance->B0_Y2) + moduleInstance->B0_Y3;
}

static void c_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  real_T *Gain;
  Gain = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  moduleInstance->B2_Y0 = *Gain * moduleInstance->B1_Y0;
}

static void d_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  moduleInstance->B3_Y0 = moduleInstance->B2_Y0;
  moduleInstance->B3_Y1 = moduleInstance->B2_Y0;
  moduleInstance->B3_Y2 = moduleInstance->B2_Y0;
}

static void e_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  (*moduleInstance->b_y0)[0] = moduleInstance->B3_Y0;
  (*moduleInstance->b_y0)[1] = moduleInstance->B3_Y1;
}

static void f_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 5,
    SS_CALL_MDL_OUTPUTS);
}

static void g_Outputs(InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 7,
    SS_CALL_MDL_OUTPUTS);
}

static const mxArray *emlrt_marshallOut(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->pipeStage;
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->sysIdxToRun;
  emlrtAssign(&c_y, m);
  emlrtSetCell(y, 1, c_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *u, cgxertBlkSrcLocInfo *blkSrc)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "pipeStage";
  *moduleInstance->pipeStage = b_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 0)), "pipeStage", blkSrc);
  thisId.fIdentifier = "sysIdxToRun";
  *moduleInstance->sysIdxToRun = b_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 1)), "sysIdxToRun", blkSrc);
  emlrtDestroyArray(&u);
}

static int32_T b_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc)
{
  emlrtMsgIdentifier thisId;
  int32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(moduleInstance, emlrtAlias(nullptr), &thisId, blkSrc);
  emlrtDestroyArray(&nullptr);
  return y;
}

static int32_T c_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  int32_T y;
  y = d_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, blkSrc);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *st)
{
  cgxertBlkSrcLocInfo blkSrcLoc;
  blkSrcLoc.sysIdx = moduleInstance->sysIdx;
  blkSrcLoc.blkIdx = -1;
  emlrt_marshallIn(moduleInstance, emlrtAlias(st), &blkSrcLoc);
  emlrtDestroyArray(&st);
}

static int32_T d_emlrt_marshallIn(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  static const int32_T dims = 0;
  int32_T ret;
  emlrtCheckBuiltInR2012b(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), msgId,
    src, "int32", false, 0U, (const void *)&dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void init_simulink_io_address(InstanceStruct_raCHpldexqYpqn6pvJMu3D
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->b_y0 = (real_T (*)[2])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
  moduleInstance->pipeStage = (int32_T *)cgxertGetDWork(moduleInstance->S, 0);
  moduleInstance->sysIdxToRun = (int32_T *)cgxertGetDWork(moduleInstance->S, 1);
  moduleInstance->sysIdx = (int32_T)cgxertGetSubsysIdx(moduleInstance->S);
}

/* CGXE Glue Code */
static void mdlOutputs_raCHpldexqYpqn6pvJMu3D(SimStruct *S, int_T tid)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_raCHpldexqYpqn6pvJMu3D(SimStruct *S, int_T tid)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_raCHpldexqYpqn6pvJMu3D(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
  InstanceStruct_raCHpldexqYpqn6pvJMu3D *moduleInstance =
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D *)calloc(1, sizeof
    (InstanceStruct_raCHpldexqYpqn6pvJMu3D));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlInitializeConditions(S, mdlInitialize_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlUpdate(S, mdlUpdate_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlDerivatives(S, mdlDerivatives_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlTerminate(S, mdlTerminate_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlEnable(S, mdlEnable_raCHpldexqYpqn6pvJMu3D);
  ssSetmdlDisable(S, mdlDisable_raCHpldexqYpqn6pvJMu3D);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_raCHpldexqYpqn6pvJMu3D(SimStruct *S)
{
}

void method_dispatcher_raCHpldexqYpqn6pvJMu3D(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_raCHpldexqYpqn6pvJMu3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_raCHpldexqYpqn6pvJMu3D(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_raCHpldexqYpqn6pvJMu3D(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_raCHpldexqYpqn6pvJMu3D(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: raCHpldexqYpqn6pvJMu3D.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_raCHpldexqYpqn6pvJMu3D_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  double * pointer;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateDoubleMatrix(0,0, mxREAL);
  pointer = mxGetPr(elem_8);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_9 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_9);
  return mxBIArgs;
}

mxArray *cgxe_raCHpldexqYpqn6pvJMu3D_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("clientSpecification");
  mxArray* incompatibleSymbol = mxCreateString("");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
