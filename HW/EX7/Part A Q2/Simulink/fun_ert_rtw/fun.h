//
// File: fun.h
//
// Code generated for Simulink model 'fun'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 11:43:38 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_fun_h_
#define RTW_HEADER_fun_h_
#include "rtwtypes.h"
#include "fun_types.h"
#include <cstring>
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<Root>'
struct DW_fun_T {
  real_T counter;                      // '<Root>/Fan'
  uint8_T is_active_c3_fun;            // '<Root>/Fan'
  uint8_T is_c3_fun;                   // '<Root>/Fan'
  uint8_T is_On;                       // '<Root>/Fan'
};

// Real-time Model Data Structure
struct tag_RTM_fun_T {
  const char_T * volatile errorStatus;
  DW_fun_T *dwork;
};

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void fun_initialize(RT_MODEL_fun_T *const fun_M, real_T *fun_U_SS,
    real_T *fun_U_temp, real_T *fun_Y_V1, real_T *fun_Y_V2);
  extern void fun_step(RT_MODEL_fun_T *const fun_M, real_T fun_U_SS, real_T
                       fun_U_temp, real_T *fun_Y_V1, real_T *fun_Y_V2);
  extern void fun_terminate(RT_MODEL_fun_T *const fun_M);

#ifdef __cplusplus

}

#endif

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'fun'
//  '<S1>'   : 'fun/Fan'

#endif                                 // RTW_HEADER_fun_h_

//
// File trailer for generated code.
//
// [EOF]
//
