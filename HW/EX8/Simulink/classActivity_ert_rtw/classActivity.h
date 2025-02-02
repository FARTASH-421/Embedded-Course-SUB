//
// File: classActivity.h
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
#ifndef RTW_HEADER_classActivity_h_
#define RTW_HEADER_classActivity_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "classActivity_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model classActivity
class classActivity final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_classActivity_T {
    uint8_T is_active_c3_classActivity;// '<Root>/Alarm'
    uint8_T is_c3_classActivity;       // '<Root>/Alarm'
    uint8_T is_Mode;                   // '<Root>/Alarm'
    uint8_T is_Vol;                    // '<Root>/Alarm'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_classActivity_T {
    boolean_T start_e;                 // '<Root>/start'
    boolean_T dec;                     // '<Root>/dec'
    boolean_T inc;                     // '<Root>/inc'
    boolean_T stop;                    // '<Root>/stop'
    boolean_T t_off;                   // '<Root>/t_off'
    boolean_T t_on;                    // '<Root>/t_on'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_classActivity_T {
    boolean_T off_out;                 // '<Root>/off_out'
    boolean_T a1;                      // '<Root>/a1'
    boolean_T on_out;                  // '<Root>/on_out'
    boolean_T a2;                      // '<Root>/a2'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_classActivity_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  classActivity(classActivity const&) = delete;

  // Assignment Operator
  classActivity& operator= (classActivity const&) & = delete;

  // Move Constructor
  classActivity(classActivity &&) = delete;

  // Move Assignment Operator
  classActivity& operator= (classActivity &&) = delete;

  // Real-Time Model get method
  classActivity::RT_MODEL_classActivity_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_classActivity_T *pExtU_classActivity_T)
  {
    classActivity_U = *pExtU_classActivity_T;
  }

  // Root outports get method
  const ExtY_classActivity_T &getExternalOutputs() const
  {
    return classActivity_Y;
  }

  // model initialize function
  static void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  classActivity();

  // Destructor
  ~classActivity();

  // private data and function members
 private:
  // External inputs
  ExtU_classActivity_T classActivity_U;

  // External outputs
  ExtY_classActivity_T classActivity_Y;

  // Block states
  DW_classActivity_T classActivity_DW;

  // Real-Time Model
  RT_MODEL_classActivity_T classActivity_M;
};

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
//  '<Root>' : 'classActivity'
//  '<S1>'   : 'classActivity/Alarm'

#endif                                 // RTW_HEADER_classActivity_h_

//
// File trailer for generated code.
//
// [EOF]
//
