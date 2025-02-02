//
// File: classActivity.cpp
//
// Code generated for Simulink model 'classActivity'.
//
// Model version                  : 1.33
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Jan  3 13:17:11 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Atmel->AVR
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "classActivity.h"
#include "rtwtypes.h"

// Named constants for Chart: '<Root>/Alarm'
const uint8_T classActivit_IN_NO_ACTIVE_CHILD{ 0U };

const uint8_T classActivity_IN_ON{ 1U };

const uint8_T classActivity_IN_OP{ 1U };

const uint8_T classActivity_IN_Off{ 2U };

const uint8_T classActivity_IN_One{ 1U };

const uint8_T classActivity_IN_Shutdown{ 2U };

const uint8_T classActivity_IN_Two{ 2U };

// Model step function
void classActivity::step()
{
  boolean_T tmp;

  // Chart: '<Root>/Alarm' incorporates:
  //   Inport: '<Root>/dec'
  //   Inport: '<Root>/inc'
  //   Inport: '<Root>/start'
  //   Inport: '<Root>/stop'
  //   Inport: '<Root>/t_off'
  //   Inport: '<Root>/t_on'

  if (classActivity_DW.is_active_c3_classActivity == 0U) {
    classActivity_DW.is_active_c3_classActivity = 1U;

    // Outport: '<Root>/a1'
    classActivity_Y.a1 = false;

    // Outport: '<Root>/a2'
    classActivity_Y.a2 = false;

    // Outport: '<Root>/on_out'
    classActivity_Y.on_out = false;

    // Outport: '<Root>/off_out'
    classActivity_Y.off_out = false;
    classActivity_DW.is_c3_classActivity = classActivity_IN_Shutdown;
  } else if (classActivity_DW.is_c3_classActivity == classActivity_IN_OP) {
    if (classActivity_U.stop || (!classActivity_U.start_e)) {
      // Outport: '<Root>/a1'
      classActivity_Y.a1 = false;

      // Outport: '<Root>/a2'
      classActivity_Y.a2 = false;

      // Outport: '<Root>/on_out'
      classActivity_Y.on_out = false;

      // Outport: '<Root>/off_out'
      classActivity_Y.off_out = false;
      classActivity_DW.is_Vol = classActivit_IN_NO_ACTIVE_CHILD;
      classActivity_DW.is_Mode = classActivit_IN_NO_ACTIVE_CHILD;
      classActivity_DW.is_c3_classActivity = classActivity_IN_Shutdown;
    } else {
      if (classActivity_DW.is_Mode == classActivity_IN_ON) {
        if (classActivity_U.t_off && (!classActivity_U.t_on)) {
          classActivity_DW.is_Mode = classActivity_IN_Off;

          // Outport: '<Root>/off_out'
          classActivity_Y.off_out = true;

          // Outport: '<Root>/on_out'
          classActivity_Y.on_out = false;
        }

        // case IN_Off:
      } else if (classActivity_U.t_on && (!classActivity_U.t_off)) {
        classActivity_DW.is_Mode = classActivity_IN_ON;

        // Outport: '<Root>/on_out'
        classActivity_Y.on_out = true;

        // Outport: '<Root>/off_out'
        classActivity_Y.off_out = false;
      }

      if (classActivity_DW.is_Vol == classActivity_IN_One) {
        if (classActivity_U.inc && (!classActivity_U.dec) &&
            classActivity_U.start_e) {
          classActivity_DW.is_Vol = classActivity_IN_Two;

          // Outport: '<Root>/a2'
          classActivity_Y.a2 = true;

          // Outport: '<Root>/a1'
          classActivity_Y.a1 = false;
        }

        // case IN_Two:
      } else if (classActivity_U.dec && (!classActivity_U.inc) &&
                 classActivity_U.start_e) {
        classActivity_DW.is_Vol = classActivity_IN_One;

        // Outport: '<Root>/a1'
        classActivity_Y.a1 = true;

        // Outport: '<Root>/a2'
        classActivity_Y.a2 = false;
      }
    }
  } else {
    // case IN_Shutdown:
    tmp = !classActivity_U.stop;
    if (classActivity_U.start_e && tmp) {
      classActivity_DW.is_c3_classActivity = classActivity_IN_OP;
      classActivity_DW.is_Mode = classActivity_IN_Off;

      // Outport: '<Root>/off_out'
      classActivity_Y.off_out = true;

      // Outport: '<Root>/on_out'
      classActivity_Y.on_out = false;
      classActivity_DW.is_Vol = classActivity_IN_One;

      // Outport: '<Root>/a1'
      classActivity_Y.a1 = true;

      // Outport: '<Root>/a2'
      classActivity_Y.a2 = false;
    } else if (classActivity_U.t_on && tmp) {
      classActivity_DW.is_c3_classActivity = classActivity_IN_OP;
      classActivity_DW.is_Mode = classActivity_IN_ON;

      // Outport: '<Root>/on_out'
      classActivity_Y.on_out = true;

      // Outport: '<Root>/off_out'
      classActivity_Y.off_out = false;
      classActivity_DW.is_Vol = classActivity_IN_One;

      // Outport: '<Root>/a1'
      classActivity_Y.a1 = true;

      // Outport: '<Root>/a2'
      classActivity_Y.a2 = false;
    }
  }

  // End of Chart: '<Root>/Alarm'
}

// Model initialize function
void classActivity::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void classActivity::terminate()
{
  // (no terminate code required)
}

// Constructor
classActivity::classActivity() :
  classActivity_U(),
  classActivity_Y(),
  classActivity_DW(),
  classActivity_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
classActivity::~classActivity() = default;

// Real-Time Model get method
classActivity::RT_MODEL_classActivity_T * classActivity::getRTM()
{
  return (&classActivity_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
