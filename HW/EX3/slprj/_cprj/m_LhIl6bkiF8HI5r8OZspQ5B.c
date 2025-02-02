/* Include files */

#include "modelInterface.h"
#include "m_LhIl6bkiF8HI5r8OZspQ5B.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static void Outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance);
static void b_Outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance);
static const mxArray *emlrt_marshallOut(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, cgxertBlkSrcLocInfo *blkSrc);
static real_T b_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc);
static real_T c_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T d_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T e_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc);
static void cgxe_mdl_set_sim_state(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *st);
static real_T f_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T g_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T _s32_add__(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance,
  int32_T b, int32_T c, cgxertBlkSrcLocInfo *blkSrc);
static void init_simulink_io_address(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
}

static void cgxe_mdl_initialize(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  *moduleInstance->pipeStage = 0;
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 2,
    SS_CALL_MDL_INITIALIZE_CONDITIONS);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 4,
    SS_CALL_MDL_INITIALIZE_CONDITIONS);
  moduleInstance->sectionProfiles = cgxertCreateSectionProfiles(2U);
}

static void cgxe_mdl_outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 0,
    SS_CALL_MDL_OUTPUTS);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 0U);
  Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 0U);
  cgxertStartProfiling(moduleInstance->sectionProfiles, 1U);
  b_Outputs(moduleInstance);
  cgxertStopProfiling(moduleInstance->sectionProfiles, 1U);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 2,
    SS_CALL_MDL_OUTPUTS);
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 4,
    SS_CALL_MDL_OUTPUTS);
}

static void cgxe_mdl_update(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  uint32_T sectionBlkIds[2] = { 1U, 3U };

  cgxertExportToEngineSectionProfiles(moduleInstance->sectionProfiles,
    sectionBlkIds, moduleInstance->S);
  cgxertDestroySectionProfiles(moduleInstance->sectionProfiles);
}

static void Outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance)
{
  cgxertBlkSrcLocInfo blkSrcLoc;
  int32_T j;
  int32_T n;
  int32_T outidx;
  int32_T str;
  outidx = 0;
  for (j = 0; j < 1; j++) {
    *moduleInstance->AccVal = (*moduleInstance->u0)[j];
    str = 1;
    for (n = 2; n >= 0; n--) {
      moduleInstance->AccVal[outidx] = *moduleInstance->AccVal +
        (*moduleInstance->u0)[j + str];
      str++;
    }

    *moduleInstance->b_y1 = *moduleInstance->AccVal / 4.0;
    blkSrcLoc.sysIdx = moduleInstance->sysIdx;
    blkSrcLoc.blkIdx = 1;
    outidx = _s32_add__(moduleInstance, outidx, 1, &blkSrcLoc);
  }
}

static void b_Outputs(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance)
{
  (*moduleInstance->y2)[0] = *moduleInstance->b_y1;
  (*moduleInstance->y2)[1] = *moduleInstance->b_y1;
}

static const mxArray *emlrt_marshallOut(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(3, 1));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(*moduleInstance->AccVal);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->pipeStage;
  emlrtAssign(&c_y, m);
  emlrtSetCell(y, 1, c_y);
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->sysIdxToRun;
  emlrtAssign(&d_y, m);
  emlrtSetCell(y, 2, d_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, cgxertBlkSrcLocInfo *blkSrc)
{
  emlrtMsgIdentifier thisId;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  thisId.fIdentifier = "AccVal";
  *moduleInstance->AccVal = b_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 0)), "AccVal", blkSrc);
  thisId.fIdentifier = "pipeStage";
  *moduleInstance->pipeStage = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 1)), "pipeStage", blkSrc);
  thisId.fIdentifier = "sysIdxToRun";
  *moduleInstance->sysIdxToRun = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 2)), "sysIdxToRun", blkSrc);
  emlrtDestroyArray(&u);
}

static real_T b_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(moduleInstance, emlrtAlias(nullptr), &thisId, blkSrc);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T c_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  real_T y;
  y = f_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, blkSrc);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T d_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc)
{
  emlrtMsgIdentifier thisId;
  int32_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = e_emlrt_marshallIn(moduleInstance, emlrtAlias(nullptr), &thisId, blkSrc);
  emlrtDestroyArray(&nullptr);
  return y;
}

static int32_T e_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  int32_T y;
  y = g_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, blkSrc);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *st)
{
  cgxertBlkSrcLocInfo blkSrcLoc;
  blkSrcLoc.sysIdx = moduleInstance->sysIdx;
  blkSrcLoc.blkIdx = -1;
  emlrt_marshallIn(moduleInstance, emlrtAlias(st), &blkSrcLoc);
  emlrtDestroyArray(&st);
}

static real_T f_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), msgId,
    src, "double", false, 0U, (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static int32_T g_emlrt_marshallIn(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
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

static int32_T _s32_add__(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance,
  int32_T b, int32_T c, cgxertBlkSrcLocInfo *blkSrc)
{
  int32_T a;
  a = b + c;
  if (((a ^ b) & (a ^ c)) < 0) {
    emlrtIntegerOverflowWarningOrError2018b(NULL, cgxertPrepareEmlrtTLS
      (moduleInstance->S, moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx,
       blkSrc->blkIdx));
  }

  return a;
}

static void init_simulink_io_address(InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[4])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->u2 = (real_T (*)[2])cgxertGetInputPortSignal(moduleInstance->S,
    2);
  moduleInstance->b_y0 = (real_T (*)[4])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
  moduleInstance->y2 = (real_T (*)[2])cgxertGetOutputPortSignal
    (moduleInstance->S, 2);
  moduleInstance->AccVal = (real_T *)cgxertGetDWork(moduleInstance->S, 0);
  moduleInstance->pipeStage = (int32_T *)cgxertGetDWork(moduleInstance->S, 1);
  moduleInstance->sysIdxToRun = (int32_T *)cgxertGetDWork(moduleInstance->S, 2);
  moduleInstance->sysIdx = (int32_T)cgxertGetSubsysIdx(moduleInstance->S);
}

/* CGXE Glue Code */
static void mdlOutputs_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S, int_T tid)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S, int_T tid)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
  InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *moduleInstance =
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B *)calloc(1, sizeof
    (InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlInitializeConditions(S, mdlInitialize_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlUpdate(S, mdlUpdate_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlDerivatives(S, mdlDerivatives_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlTerminate(S, mdlTerminate_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlEnable(S, mdlEnable_LhIl6bkiF8HI5r8OZspQ5B);
  ssSetmdlDisable(S, mdlDisable_LhIl6bkiF8HI5r8OZspQ5B);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S)
{
}

void method_dispatcher_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_LhIl6bkiF8HI5r8OZspQ5B(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_LhIl6bkiF8HI5r8OZspQ5B(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_LhIl6bkiF8HI5r8OZspQ5B(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_LhIl6bkiF8HI5r8OZspQ5B(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: LhIl6bkiF8HI5r8OZspQ5B.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_LhIl6bkiF8HI5r8OZspQ5B_BuildInfoUpdate(void)
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

mxArray *cgxe_LhIl6bkiF8HI5r8OZspQ5B_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("clientSpecification");
  mxArray* incompatibleSymbol = mxCreateString("");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
