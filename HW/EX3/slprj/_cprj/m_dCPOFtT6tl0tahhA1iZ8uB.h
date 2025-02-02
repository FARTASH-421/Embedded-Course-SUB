#ifndef __dCPOFtT6tl0tahhA1iZ8uB_h__
#define __dCPOFtT6tl0tahhA1iZ8uB_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_simstruct_bridge.h"
#include "sl_sfcn_cov/sl_sfcn_cov_bridge.h"

/* Type Definitions */
#ifndef typedef_cgxertBlkSrcLocInfo
#define typedef_cgxertBlkSrcLocInfo

typedef struct {
  int32_T sysIdx;
  int32_T blkIdx;
} cgxertBlkSrcLocInfo;

#endif                                 /* typedef_cgxertBlkSrcLocInfo */

#ifndef typedef_InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB
#define typedef_InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB

typedef struct {
  SimStruct *S;
  real_T B1_Y0;
  void *sectionProfiles;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[3];
  real_T *u1;
  real_T (*b_y0)[3];
  real_T *b_y1;
  real_T *InBuf;
  int32_T *InBufIdx;
  int32_T *ModuloIdx;
  real_T *AccVal;
  int32_T *pipeStage;
  int32_T *sysIdxToRun;
  int32_T sysIdx;
} InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB;

#endif                                 /* typedef_InstanceStruct_dCPOFtT6tl0tahhA1iZ8uB */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_dCPOFtT6tl0tahhA1iZ8uB(SimStruct *S, int_T method,
  void* data);

#endif
