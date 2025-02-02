#ifndef __raCHpldexqYpqn6pvJMu3D_h__
#define __raCHpldexqYpqn6pvJMu3D_h__

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

#ifndef typedef_InstanceStruct_raCHpldexqYpqn6pvJMu3D
#define typedef_InstanceStruct_raCHpldexqYpqn6pvJMu3D

typedef struct {
  SimStruct *S;
  real_T B0_Y0;
  real_T B0_Y1;
  real_T B0_Y2;
  real_T B0_Y3;
  real_T B1_Y0;
  real_T B2_Y0;
  real_T B3_Y0;
  real_T B3_Y1;
  real_T B3_Y2;
  void *sectionProfiles;
  void *emlrtRootTLSGlobal;
  real_T (*b_y0)[2];
  real_T *b_y1;
  int32_T *pipeStage;
  int32_T *sysIdxToRun;
  int32_T sysIdx;
} InstanceStruct_raCHpldexqYpqn6pvJMu3D;

#endif                                 /* typedef_InstanceStruct_raCHpldexqYpqn6pvJMu3D */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_raCHpldexqYpqn6pvJMu3D(SimStruct *S, int_T method,
  void* data);

#endif
