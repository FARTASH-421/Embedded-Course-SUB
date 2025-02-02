// #include <Arduino.h>
#include <unity.h>
#include <classActivity.h>
#include <stdio.h>
classActivity classActivity_instance;



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



void test_stop_on1() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 1;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();
    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_on2() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 1;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 1;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();
    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_on3() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 0;
    inputs.inc = 1;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 1;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();
    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_on4() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 1;
    inputs.t_off = 0;
    inputs.stop = 1;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();
    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_on5() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 1;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();
    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_off_and_Start_on() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stop_off_and_T_on() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 1;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_start_on_inc() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 1;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_start_on_dec() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 1;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_start_on_offOn() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_start_on_StateOn() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 0;
    inputs.t_on = 1;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(true, outputs.on_out);
    
}

void test_On_and_Inc() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 1;
    inputs.t_on = 1;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(true, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(true, outputs.on_out);
    
}

void test_On_and_Dec() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 1;
    inputs.inc = 0;
    inputs.t_on = 1;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(true, outputs.on_out);
    
}

void test_off_and_inc() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 0;
    inputs.inc = 1;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(true, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_off_and_dec() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 1;
    inputs.dec = 1;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(true, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(true, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stopAndStart_off1() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 1;
    inputs.inc = 0;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}

void test_stopAndStart_off2() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 0;
    inputs.inc = 1;
    inputs.t_on = 0;
    inputs.t_off = 1;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}


void test_stopAndStart_off3() {    
    classActivity::ExtU_classActivity_T inputs;
    inputs.start_e = 0;
    inputs.dec = 1;
    inputs.inc = 1;
    inputs.t_on = 0;
    inputs.t_off = 0;
    inputs.stop = 0;

    classActivity_instance.setExternalInputs(&inputs);
    classActivity_instance.step();
    
    const classActivity::ExtY_classActivity_T &outputs = classActivity_instance.getExternalOutputs();

    TEST_ASSERT_EQUAL(false, outputs.a1);
    TEST_ASSERT_EQUAL(false, outputs.a2);
    TEST_ASSERT_EQUAL(false, outputs.off_out);
    TEST_ASSERT_EQUAL(false, outputs.on_out);
    
}


void setUp() {
    // Optional: Code to run before each test.
}

void tearDown() {
    // Optional: Code to run after each test.
}

int main(int argc, char** argv) {
    UNITY_BEGIN(); // Start Unity testing framework

    RUN_TEST(test_stop_on1);
    RUN_TEST(test_stop_on2);
    RUN_TEST(test_stop_on3);
    RUN_TEST(test_stop_on4);
    RUN_TEST(test_stop_on5);

    RUN_TEST(test_stop_off_and_Start_on);
    RUN_TEST(test_stop_off_and_T_on);
    RUN_TEST(test_start_on_inc);
    RUN_TEST(test_start_on_dec);
    RUN_TEST(test_start_on_offOn);
    RUN_TEST(test_start_on_StateOn);
    RUN_TEST(test_On_and_Inc);
    RUN_TEST(test_On_and_Dec);
    RUN_TEST(test_off_and_inc);
    RUN_TEST(test_off_and_dec);
    RUN_TEST(test_stopAndStart_off1);
    RUN_TEST(test_stopAndStart_off2);
    RUN_TEST(test_stopAndStart_off3);
    
    UNITY_END();   // End Unity testing framework

    return 0;
}




