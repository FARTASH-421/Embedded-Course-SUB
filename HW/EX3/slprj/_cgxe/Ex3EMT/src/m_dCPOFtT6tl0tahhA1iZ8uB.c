/* Include files */

#include "modelInterface.h"
#include "m_dCPOFtT6tl0tahhA1iZ8uB.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static void cgxe_mdl_start(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_derivative(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_enable(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_disable(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static void Outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance);
static void b_Outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance);
static const mxArray *emlrt_marshallOut(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);
static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance);
static void emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *u, cgxertBlkSrcLocInfo *blkSrc);
static real_T b_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc);
static real_T c_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T d_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *nullptr, const char_T *identifier,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T e_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc);
static void cgxe_mdl_set_sim_state(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *st);
static real_T f_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T g_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *src, const emlrtMsgIdentifier *msgId,
  cgxertBlkSrcLocInfo *blkSrc);
static int32_T _s32_add__(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance,
  int32_T b, int32_T c, cgxertBlkSrcLocInfo *blkSrc);
static int32_T _s32_minus__(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, int32_T b, int32_T c, cgxertBlkSrcLocInfo *blkSrc);
static void init_simulink_io_address(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance);

/* Function Definitions */
static void cgxe_mdl_start(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance)
{
  init_simulink_io_address(moduleInstance);
}

static void cgxe_mdl_initialize(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  *moduleInstance->pipeStage = 0;
  *moduleInstance->InBufIdx = 0;
  *moduleInstance->InBuf = 0.0;
  *moduleInstance->ModuloIdx = 0;
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 3,
    SS_CALL_MDL_INITIALIZE_CONDITIONS);
  moduleInstance->sectionProfiles = cgxertCreateSectionProfiles(2U);
}

static void cgxe_mdl_outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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
  cgxertCallAccelRunBlock(moduleInstance->S, *moduleInstance->sysIdxToRun, 3,
    SS_CALL_MDL_OUTPUTS);
}

static void cgxe_mdl_update(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_derivative(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_enable(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_disable(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  uint32_T sectionBlkIds[2] = { 1U, 2U };

  cgxertExportToEngineSectionProfiles(moduleInstance->sectionProfiles,
    sectionBlkIds, moduleInstance->S);
  cgxertDestroySectionProfiles(moduleInstance->sectionProfiles);
}

static void Outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance)
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
    for (n = 1; n >= 0; n--) {
      moduleInstance->AccVal[outidx] = *moduleInstance->AccVal +
        (*moduleInstance->u0)[j + str];
      str++;
    }

    moduleInstance->B1_Y0 = *moduleInstance->AccVal / 3.0;
    blkSrcLoc.sysIdx = moduleInstance->sysIdx;
    blkSrcLoc.blkIdx = 1;
    outidx = _s32_add__(moduleInstance, outidx, 1, &blkSrcLoc);
  }
}

static void b_Outputs(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance)
{
  cgxertBlkSrcLocInfo blkSrcLoc;
  real_T *FILTER;
  int32_T i;
  int32_T k;
  int32_T *StartIdx;
  int32_T *StopIdx;
  FILTER = (real_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 0);
  StopIdx = (int32_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 3);
  StartIdx = (int32_T *)cgxertGetRunTimeParamInfoData(moduleInstance->S, 2);

  /* Determine the input and output frame sizes */
  /* Update inBufIdx and inputChannelOffset for current channel */
  /* Read input into inBufArray */
  *moduleInstance->InBuf = moduleInstance->B1_Y0;

  /* Generate outputs (if any) for current input n */
  for (k = *StartIdx; k < *StopIdx; k++) {
    *moduleInstance->b_y1 = 0.0;
    for (i = *moduleInstance->InBufIdx; i < 1; i++) {
      *moduleInstance->b_y1 += *FILTER * *moduleInstance->InBuf;
    }

    for (i = 0; i < *moduleInstance->InBufIdx; i++) {
      *moduleInstance->b_y1 += *FILTER * *moduleInstance->InBuf;
    }
  }

  /* Decrement inBufIdx, wrap if necessary */
  if (*moduleInstance->InBufIdx != 0) {
    blkSrcLoc.sysIdx = moduleInstance->sysIdx;
    blkSrcLoc.blkIdx = 2;
    *moduleInstance->InBufIdx = _s32_minus__(moduleInstance,
      *moduleInstance->InBufIdx, 1, &blkSrcLoc);
  }

  /* Update inBufIdx */
  *moduleInstance->ModuloIdx = 0;
}

static const mxArray *emlrt_marshallOut(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(6, 1));
  b_y = NULL;
  m = emlrtCreateDoubleScalar(*moduleInstance->AccVal);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m = emlrtCreateDoubleScalar(*moduleInstance->InBuf);
  emlrtAssign(&c_y, m);
  emlrtSetCell(y, 1, c_y);
  d_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->InBufIdx;
  emlrtAssign(&d_y, m);
  emlrtSetCell(y, 2, d_y);
  e_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->ModuloIdx;
  emlrtAssign(&e_y, m);
  emlrtSetCell(y, 3, e_y);
  f_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->pipeStage;
  emlrtAssign(&f_y, m);
  emlrtSetCell(y, 4, f_y);
  g_y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m) = *moduleInstance->sysIdxToRun;
  emlrtAssign(&g_y, m);
  emlrtSetCell(y, 5, g_y);
  return y;
}

static const mxArray *cgxe_mdl_get_sim_state
  (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance)
{
  const mxArray *st;
  st = NULL;
  emlrtAssign(&st, emlrt_marshallOut(moduleInstance));
  return st;
}

static void emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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
  thisId.fIdentifier = "InBuf";
  *moduleInstance->InBuf = b_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 1)), "InBuf", blkSrc);
  thisId.fIdentifier = "InBufIdx";
  *moduleInstance->InBufIdx = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 2)), "InBufIdx", blkSrc);
  thisId.fIdentifier = "ModuloIdx";
  *moduleInstance->ModuloIdx = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 3)), "ModuloIdx", blkSrc);
  thisId.fIdentifier = "pipeStage";
  *moduleInstance->pipeStage = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 4)), "pipeStage", blkSrc);
  thisId.fIdentifier = "sysIdxToRun";
  *moduleInstance->sysIdxToRun = d_emlrt_marshallIn(moduleInstance, emlrtAlias
    (emlrtGetCell(cgxertPrepareEmlrtTLS(moduleInstance->S,
    moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx, blkSrc->blkIdx), &thisId,
                  u, 5)), "sysIdxToRun", blkSrc);
  emlrtDestroyArray(&u);
}

static real_T b_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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

static real_T c_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  real_T y;
  y = f_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, blkSrc);
  emlrtDestroyArray(&u);
  return y;
}

static int32_T d_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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

static int32_T e_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *u, const emlrtMsgIdentifier *parentId,
  cgxertBlkSrcLocInfo *blkSrc)
{
  int32_T y;
  y = g_emlrt_marshallIn(moduleInstance, emlrtAlias(u), parentId, blkSrc);
  emlrtDestroyArray(&u);
  return y;
}

static void cgxe_mdl_set_sim_state(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, const mxArray *st)
{
  cgxertBlkSrcLocInfo blkSrcLoc;
  blkSrcLoc.sysIdx = moduleInstance->sysIdx;
  blkSrcLoc.blkIdx = -1;
  emlrt_marshallIn(moduleInstance, emlrtAlias(st), &blkSrcLoc);
  emlrtDestroyArray(&st);
}

static real_T f_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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

static int32_T g_emlrt_marshallIn(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
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

static int32_T _s32_add__(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance,
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

static int32_T _s32_minus__(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance, int32_T b, int32_T c, cgxertBlkSrcLocInfo *blkSrc)
{
  int32_T a;
  a = b - c;
  if (((b ^ a) & (b ^ c)) < 0) {
    emlrtIntegerOverflowWarningOrError2018b(NULL, cgxertPrepareEmlrtTLS
      (moduleInstance->S, moduleInstance->emlrtRootTLSGlobal, blkSrc->sysIdx,
       blkSrc->blkIdx));
  }

  return a;
}

static void init_simulink_io_address(InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
  *moduleInstance)
{
  moduleInstance->emlrtRootTLSGlobal = (void *)cgxertGetEMLRTCtx
    (moduleInstance->S);
  moduleInstance->u0 = (real_T (*)[3])cgxertGetInputPortSignal(moduleInstance->S,
    0);
  moduleInstance->u1 = (real_T *)cgxertGetInputPortSignal(moduleInstance->S, 1);
  moduleInstance->b_y0 = (real_T (*)[3])cgxertGetOutputPortSignal
    (moduleInstance->S, 0);
  moduleInstance->b_y1 = (real_T *)cgxertGetOutputPortSignal(moduleInstance->S,
    1);
  moduleInstance->InBuf = (real_T *)cgxertGetDWork(moduleInstance->S, 0);
  moduleInstance->InBufIdx = (int32_T *)cgxertGetDWork(moduleInstance->S, 1);
  moduleInstance->ModuloIdx = (int32_T *)cgxertGetDWork(moduleInstance->S, 2);
  moduleInstance->AccVal = (real_T *)cgxertGetDWork(moduleInstance->S, 3);
  moduleInstance->pipeStage = (int32_T *)cgxertGetDWork(moduleInstance->S, 4);
  moduleInstance->sysIdxToRun = (int32_T *)cgxertGetDWork(moduleInstance->S, 5);
  moduleInstance->sysIdx = (int32_T)cgxertGetSubsysIdx(moduleInstance->S);
}

/* CGXE Glue Code */
static void mdlOutputs_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S, int_T tid)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_outputs(moduleInstance);
}

static void mdlInitialize_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_initialize(moduleInstance);
}

static void mdlUpdate_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S, int_T tid)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_update(moduleInstance);
}

static void mdlDerivatives_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_derivative(moduleInstance);
}

static mxArray* getSimState_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  mxArray* mxSS;
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  mxSS = (mxArray *) cgxe_mdl_get_sim_state(moduleInstance);
  return mxSS;
}

static void setSimState_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_set_sim_state(moduleInstance, emlrtAlias(ss));
}

static void mdlTerminate_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_terminate(moduleInstance);
  free((void *)moduleInstance);
}

static void mdlEnable_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_enable(moduleInstance);
}

static void mdlDisable_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)cgxertGetRuntimeInstance(S);
  cgxe_mdl_disable(moduleInstance);
}

static void mdlStart_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
  InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *moduleInstance =
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB *)calloc(1, sizeof
    (InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB));
  moduleInstance->S = S;
  cgxertSetRuntimeInstance(S, (void *)moduleInstance);
  ssSetmdlOutputs(S, mdlOutputs_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlInitializeConditions(S, mdlInitialize_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlUpdate(S, mdlUpdate_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlDerivatives(S, mdlDerivatives_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlTerminate(S, mdlTerminate_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlEnable(S, mdlEnable_dCPOFtT6tl0tahhA1iZ8uB);
  ssSetmdlDisable(S, mdlDisable_dCPOFtT6tl0tahhA1iZ8uB);
  cgxe_mdl_start(moduleInstance);

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }
}

static void mdlProcessParameters_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S)
{
}

void method_dispatcher_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_dCPOFtT6tl0tahhA1iZ8uB(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_dCPOFtT6tl0tahhA1iZ8uB(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_dCPOFtT6tl0tahhA1iZ8uB(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_dCPOFtT6tl0tahhA1iZ8uB(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: dCPOFtT6tl0tahhA1iZ8uB.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

mxArray *cgxe_dCPOFtT6tl0tahhA1iZ8uB_BuildInfoUpdate(void)
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

mxArray *cgxe_dCPOFtT6tl0tahhA1iZ8uB_fallback_info(void)
{
  const char* fallbackInfoFields[] = { "fallbackType", "incompatiableSymbol" };

  mxArray* fallbackInfoStruct = mxCreateStructMatrix(1, 1, 2, fallbackInfoFields);
  mxArray* fallbackType = mxCreateString("clientSpecification");
  mxArray* incompatibleSymbol = mxCreateString("");
  mxSetFieldByNumber(fallbackInfoStruct, 0, 0, fallbackType);
  mxSetFieldByNumber(fallbackInfoStruct, 0, 1, incompatibleSymbol);
  return fallbackInfoStruct;
}
