#ifndef __LhIl6bkiF8HI5r8OZspQ5B_h__
#define __LhIl6bkiF8HI5r8OZspQ5B_h__

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

#ifndef typedef_InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B
#define typedef_InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B

typedef struct {
  SimStruct *S;
  void *sectionProfiles;
  void *emlrtRootTLSGlobal;
  real_T (*u0)[4];
  real_T *u1;
  real_T (*u2)[2];
  real_T (*b_y0)[4];
  real_T *b_y1;
  real_T (*y2)[2];
  real_T *AccVal;
  int32_T *pipeStage;
  int32_T *sysIdxToRun;
  int32_T sysIdx;
} InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B;

#endif                                 /* typedef_InstanceStruct_LhIl6bkiF8HI5r8OZspQ5B */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_LhIl6bkiF8HI5r8OZspQ5B(SimStruct *S, int_T method,
  void* data);

#endif
