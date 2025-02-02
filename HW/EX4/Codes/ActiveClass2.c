
/*
 * File: classActivity0x2820x29.c
 *
 * Code generated for Simulink model 'classActivity0x2820x29'.
 *
 * Model version                  : 1.28
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Nov  4 21:15:08 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "classActivity0x2820x29.h"
#include "rtwtypes.h"

/* Named constants for Chart: '<Root>/Alarm' */
#define classActivity0x2820_IN_Shutdown ((uint8_T)2U)
#define classActivity0x2820x29_IN_ON   ((uint8_T)1U)
#define classActivity0x2820x29_IN_OP   ((uint8_T)1U)
#define classActivity0x2820x29_IN_Off  ((uint8_T)2U)
#define classActivity0x2820x29_IN_One  ((uint8_T)1U)
#define classActivity0x2820x29_IN_Two  ((uint8_T)2U)

/* Block signals (default storage) */
B_classActivity0x2820x29_T classActivity0x2820x29_B;

/* Block states (default storage) */
DW_classActivity0x2820x29_T classActivity0x2820x29_DW;

/* Real-time model */
static RT_MODEL_classActivity0x2820x_T classActivity0x2820x29_M_;
RT_MODEL_classActivity0x2820x_T *const classActivity0x2820x29_M =
  &classActivity0x2820x29_M_;

/* Model step function */
void classActivity0x2820x29_step(void)
{
  uint16_T b_varargout_1;
  boolean_T rtb_Compare;
  boolean_T rtb_Compare_l;

  /* MATLABSystem: '<Root>/Analog Input' */
  if (classActivity0x2820x29_DW.obj_e.SampleTime !=
      classActivity0x2820x29_P.AnalogInput_SampleTime) {
    classActivity0x2820x29_DW.obj_e.SampleTime =
      classActivity0x2820x29_P.AnalogInput_SampleTime;
  }

  classActivity0x2820x29_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(55UL);
  MW_AnalogInSingle_ReadResult
    (classActivity0x2820x29_DW.obj_e.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLABSystem: '<Root>/Analog Input'
   * */
  rtb_Compare = (b_varargout_1 <=
                 classActivity0x2820x29_P.CompareToConstant_const);

  /* MATLABSystem: '<Root>/Analog Input1' */
  if (classActivity0x2820x29_DW.obj_n.SampleTime !=
      classActivity0x2820x29_P.AnalogInput1_SampleTime) {
    classActivity0x2820x29_DW.obj_n.SampleTime =
      classActivity0x2820x29_P.AnalogInput1_SampleTime;
  }

  classActivity0x2820x29_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(56UL);
  MW_AnalogInSingle_ReadResult
    (classActivity0x2820x29_DW.obj_n.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   *  MATLABSystem: '<Root>/Analog Input1'
   * */
  rtb_Compare_l = (b_varargout_1 <=
                   classActivity0x2820x29_P.CompareToConstant1_const);

  /* MATLABSystem: '<Root>/Analog Input2' */
  if (classActivity0x2820x29_DW.obj.SampleTime !=
      classActivity0x2820x29_P.AnalogInput2_SampleTime) {
    classActivity0x2820x29_DW.obj.SampleTime =
      classActivity0x2820x29_P.AnalogInput2_SampleTime;
  }

  classActivity0x2820x29_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE =
    MW_AnalogIn_GetHandle(57UL);
  MW_AnalogInSingle_ReadResult
    (classActivity0x2820x29_DW.obj.AnalogInDriverObj.MW_ANALOGIN_HANDLE,
     &b_varargout_1, MW_ANALOGIN_UINT16);

  /* Chart: '<Root>/Alarm' incorporates:
   *  Constant: '<S4>/Constant'
   *  MATLABSystem: '<Root>/Analog Input2'
   *  RelationalOperator: '<S4>/Compare'
   * */
  if (classActivity0x2820x29_DW.is_active_c3_classActivity0x282 == 0U) {
    classActivity0x2820x29_DW.is_active_c3_classActivity0x282 = 1U;
    classActivity0x2820x29_DW.is_c3_classActivity0x2820x29 =
      classActivity0x2820_IN_Shutdown;
  } else if (classActivity0x2820x29_DW.is_c3_classActivity0x2820x29 ==
             classActivity0x2820x29_IN_OP) {
    if (classActivity0x2820x29_DW.is_Vol == classActivity0x2820x29_IN_One) {
      if (rtb_Compare_l) {
        classActivity0x2820x29_B.a1 = false;
        classActivity0x2820x29_DW.is_Vol = classActivity0x2820x29_IN_Two;
        classActivity0x2820x29_B.a2 = true;
      }

      /* case IN_Two: */
    } else if (rtb_Compare) {
      classActivity0x2820x29_B.a2 = false;
      classActivity0x2820x29_DW.is_Vol = classActivity0x2820x29_IN_One;
      classActivity0x2820x29_B.a1 = true;
    }

    if (classActivity0x2820x29_DW.is_Mode == classActivity0x2820x29_IN_ON) {
      if (rtb_Compare_l) {
        classActivity0x2820x29_B.on_out = false;
        classActivity0x2820x29_DW.is_Mode = classActivity0x2820x29_IN_Off;
        classActivity0x2820x29_B.off_out = true;
      }

      /* case IN_Off: */
    } else if (rtb_Compare_l) {
      classActivity0x2820x29_B.off_out = false;
      classActivity0x2820x29_DW.is_Mode = classActivity0x2820x29_IN_ON;
      classActivity0x2820x29_B.on_out = true;
    }

    /* case IN_Shutdown: */
  } else if ((b_varargout_1 <= classActivity0x2820x29_P.CompareToConstant2_const)
             || rtb_Compare) {
    classActivity0x2820x29_DW.is_c3_classActivity0x2820x29 =
      classActivity0x2820x29_IN_OP;
    classActivity0x2820x29_DW.is_Vol = classActivity0x2820x29_IN_One;
    classActivity0x2820x29_B.a1 = true;
    classActivity0x2820x29_DW.is_Mode = classActivity0x2820x29_IN_Off;
    classActivity0x2820x29_B.off_out = true;
  } else if (rtb_Compare_l) {
    classActivity0x2820x29_DW.is_c3_classActivity0x2820x29 =
      classActivity0x2820x29_IN_OP;
    classActivity0x2820x29_DW.is_Vol = classActivity0x2820x29_IN_One;
    classActivity0x2820x29_B.a1 = true;
    classActivity0x2820x29_DW.is_Mode = classActivity0x2820x29_IN_ON;
    classActivity0x2820x29_B.on_out = true;
  }

  /* End of Chart: '<Root>/Alarm' */

  /* MATLABSystem: '<Root>/Digital Output' */
  writeDigitalPin(12, (uint8_T)classActivity0x2820x29_B.on_out);

  /* MATLABSystem: '<Root>/Digital Output1' */
  writeDigitalPin(10, (uint8_T)classActivity0x2820x29_B.off_out);

  /* MATLABSystem: '<Root>/Digital Output2' */