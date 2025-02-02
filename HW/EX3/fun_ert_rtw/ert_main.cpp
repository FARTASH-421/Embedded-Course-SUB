//
// File: ert_main.cpp
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
#include <stdio.h>              // This example main program uses printf/fflush
#include "fun.h"                       // Model header file

static RT_MODEL_fun_T fun_M_;
static RT_MODEL_fun_T *const fun_MPtr{ &fun_M_ };// Real-time model

static DW_fun_T fun_DW;                // Observable states
static ExtU_fun_T fun_U;               // External inputs
static ExtY_fun_T fun_Y;               // External outputs

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(RT_MODEL_fun_T *const fun_M);
void rt_OneStep(RT_MODEL_fun_T *const fun_M)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(fun_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  fun_step(fun_M, &fun_U, &fun_Y);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  RT_MODEL_fun_T *const fun_M{ fun_MPtr };

  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Pack model data into RTM
  fun_M->dwork = &fun_DW;

  // Initialize model
  fun_initialize(fun_M, &fun_U, &fun_Y);

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 1.0 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep(fun_M);

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (rtmGetErrorStatus(fun_M) == (nullptr)) {
    //  Perform application tasks here
  }

  // Terminate model
  fun_terminate(fun_M);
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
