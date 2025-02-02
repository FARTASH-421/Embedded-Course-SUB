//
// File: fun.h
//
// Code generated for Simulink model 'fun'.
//
// Model version                  : 1.7
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Dec 14 01:36:07 2024
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

// External inputs (root inport signals with default storage)
struct ExtU_fun_T {
  real_T SS;                           // '<Root>/SS'
  real_T temp;                         // '<Root>/temp'
};

// External outputs (root outports fed by signals with default storage)
struct ExtY_fun_T {
  real_T V1;                           // '<Root>/V1'
  real_T V2;                           // '<Root>/V2'
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
  extern void fun_initialize(RT_MODEL_fun_T *const fun_M, ExtU_fun_T *fun_U,
    ExtY_fun_T *fun_Y);
  extern void fun_step(RT_MODEL_fun_T *const fun_M, ExtU_fun_T *fun_U,
                       ExtY_fun_T *fun_Y);
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
