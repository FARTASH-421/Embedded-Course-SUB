//
// File: fun.cpp
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
#include "fun.h"
#include "rtwtypes.h"
#include <cstring>

// Named constants for Chart: '<Root>/Fan'
const uint8_T fun_IN_LeftHigh{ 1U };

const uint8_T fun_IN_LeftLow{ 2U };

const uint8_T fun_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T fun_IN_Off{ 1U };

const uint8_T fun_IN_On{ 2U };

const uint8_T fun_IN_RighHigh{ 3U };

const uint8_T fun_IN_RightLow{ 4U };

// Model step function
void fun_step(RT_MODEL_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T *fun_Y)
{
  DW_fun_T *fun_DW{ fun_M->dwork };

  // Chart: '<Root>/Fan'
  if (fun_DW->is_active_c3_fun == 0U) {
    fun_DW->is_active_c3_fun = 1U;
    fun_DW->is_c3_fun = fun_IN_Off;

    // Outport: '<Root>/V1'
    fun_Y->V1 = 0.0;

    // Outport: '<Root>/V2'
    fun_Y->V2 = 0.0;
    fun_DW->counter = 0.0;
  } else if (fun_DW->is_c3_fun == fun_IN_Off) {
    // Outport: '<Root>/V2'
    fun_Y->V2 = 0.0;
    if (fun_U->temp > 20.0) {
      fun_DW->is_c3_fun = fun_IN_On;
      fun_DW->is_On = fun_IN_RightLow;

      // Outport: '<Root>/V1'
      fun_Y->V1 = fun_U->temp - 20.0;

      // Outport: '<Root>/V2'
      fun_Y->V2 = 10.0;
    }

    // case IN_On:
  } else if (fun_U->temp <= 20.0) {
    fun_DW->is_On = fun_IN_NO_ACTIVE_CHILD;
    fun_DW->is_c3_fun = fun_IN_Off;

    // Outport: '<Root>/V1'
    fun_Y->V1 = 0.0;

    // Outport: '<Root>/V2'
    fun_Y->V2 = 0.0;
    fun_DW->counter = 0.0;
  } else {
    switch (fun_DW->is_On) {
     case fun_IN_LeftHigh:
      if (fun_DW->counter >= 5.0) {
        fun_DW->counter = 0.0;
        fun_DW->is_On = fun_IN_RighHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 20.0;
      } else if (fun_U->SS == 0.0) {
        fun_DW->is_On = fun_IN_LeftLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -10.0;
      } else {
        fun_DW->counter++;
        fun_DW->is_On = fun_IN_LeftHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -20.0;
      }
      break;

     case fun_IN_LeftLow:
      if (fun_U->SS == 1.0) {
        fun_DW->is_On = fun_IN_LeftHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -20.0;
      } else if (fun_DW->counter >= 10.0) {
        fun_DW->counter = 0.0;
        fun_DW->is_On = fun_IN_RightLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 10.0;
      } else {
        fun_DW->counter++;
        fun_DW->is_On = fun_IN_LeftLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -10.0;
      }
      break;

     case fun_IN_RighHigh:
      if (fun_U->SS == 0.0) {
        fun_DW->is_On = fun_IN_RightLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 10.0;
      } else if (fun_DW->counter >= 5.0) {
        fun_DW->counter = 0.0;
        fun_DW->is_On = fun_IN_LeftHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -20.0;
      } else {
        fun_DW->counter++;
        fun_DW->is_On = fun_IN_RighHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 20.0;
      }
      break;

     default:
      // case IN_RightLow:
      if (fun_U->SS == 1.0) {
        fun_DW->is_On = fun_IN_RighHigh;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 20.0;
      } else if (fun_DW->counter >= 10.0) {
        fun_DW->counter = 0.0;
        fun_DW->is_On = fun_IN_LeftLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = -10.0;
      } else {
        fun_DW->counter++;
        fun_DW->is_On = fun_IN_RightLow;

        // Outport: '<Root>/V1'
        fun_Y->V1 = fun_U->temp - 20.0;

        // Outport: '<Root>/V2'
        fun_Y->V2 = 10.0;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Fan'
}

// Model initialize function
void fun_initialize(RT_MODEL_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T
                    *fun_Y)
{
  DW_fun_T *fun_DW{ fun_M->dwork };

  // Registration code

  // states (dwork)
  (void) std::memset(static_cast<void *>(fun_DW), 0,
                     sizeof(DW_fun_T));
  fun_DW->counter = 0.0;

  // external inputs
  fun_U->SS = 0.0;
  fun_U->temp = 0.0;

  // external outputs
  fun_Y->V1 = 0.0;
  fun_Y->V2 = 0.0;

  // SystemInitialize for Chart: '<Root>/Fan'
  fun_DW->is_active_c3_fun = 0U;
  fun_DW->is_c3_fun = fun_IN_NO_ACTIVE_CHILD;
  fun_DW->is_On = fun_IN_NO_ACTIVE_CHILD;

  // SystemInitialize for Outport: '<Root>/V1' incorporates:
  //   Chart: '<Root>/Fan'

  fun_Y->V1 = 0.0;

  // SystemInitialize for Chart: '<Root>/Fan'
  fun_DW->counter = 0.0;
}

// Model terminate function
void fun_terminate(RT_MODEL_fun_T *const fun_M)
{
  // (no terminate code required)
  UNUSED_PARAMETER(fun_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
