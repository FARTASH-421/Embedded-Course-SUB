#include <Arduino.h>
#include <Servo.h>

// Define fixed-point types manually
typedef int16_t fix16; // 16-bit signed integer for fixed-point
const int SCALE = 16;  // 2^4 for 4 fractional bits

// Conversion functions for fixed-point
fix16 floatToFix16(float x) {
    return static_cast<fix16>(x * SCALE);
}

float fix16ToFloat(fix16 x) {
    return static_cast<float>(x) / SCALE;
}

// Data type definitions for fixed-point and other basic types
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef long long int64_T;
typedef unsigned long long uint64_T;
typedef fix16 real_T;  // Change the real_T type to fix16
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef unsigned long long ulonglong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

uint16_T d = 30;

// Named constants
const uint8_T fun_IN_LeftHigh = 1U;
const uint8_T fun_IN_LeftLow = 2U;
const uint8_T fun_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T fun_IN_Off = 1U;
const uint8_T fun_IN_On = 2U;
const uint8_T fun_IN_RighHigh = 3U;
const uint8_T fun_IN_RightLow = 4U;

// Model data structures
struct DW_fun_T {
    fix16 counter;  
    uint8_T is_active_c3_fun;
    uint8_T is_c3_fun;
    uint8_T is_On;
};

struct ExtU_fun_T {
    fix16 SS;  
    fix16 temp; 
};

struct ExtY_fun_T {
    fix16 V1;  
    fix16 V2;  
};

struct tag_RTM_fun_T {
    const char_T * volatile errorStatus;
    DW_fun_T *dwork;
};

// Function prototypes
void fun_step(tag_RTM_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T *fun_Y);
void fun_initialize(tag_RTM_fun_T *const fun_M);
void fun_terminate(tag_RTM_fun_T *const fun_M);
void myDelay(uint16_T temp);

// Global model and state variables
tag_RTM_fun_T fun_M;
ExtU_fun_T fun_U;
ExtY_fun_T fun_Y;

// Step function for the model
void fun_step(tag_RTM_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T *fun_Y) {
    DW_fun_T *fun_DW = fun_M->dwork;
    myDelay(fix16ToFloat(fun_U->temp));  
    
    // Chart logic
    if (fun_DW->is_active_c3_fun == 0U) {
        fun_DW->is_active_c3_fun = 1U;
        fun_DW->is_c3_fun = fun_IN_Off;

        // Initialize outputs
        fun_Y->V1 = floatToFix16(0);  
        fun_Y->V2 = floatToFix16(0);  
        fun_DW->counter = floatToFix16(0);  
    } else if (fun_DW->is_c3_fun == fun_IN_Off) {
        fun_Y->V2 = floatToFix16(0);  
        if (fun_U->temp > floatToFix16(20.0)) {  
            fun_DW->is_c3_fun = fun_IN_On;
            fun_DW->is_On = fun_IN_RightLow;

            // Outport: '<Root>/V1'
            fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

            // Outport: '<Root>/V2'
            fun_Y->V2 = floatToFix16(10.0);  
        }
    } else if (fun_U->temp <= floatToFix16(20.0)) {  
        fun_DW->is_On = fun_IN_NO_ACTIVE_CHILD;
        fun_DW->is_c3_fun = fun_IN_Off;

        // Outport: '<Root>/V1'
        fun_Y->V1 = floatToFix16(0); 

        // Outport: '<Root>/V2'
        fun_Y->V2 = floatToFix16(0); 
        fun_DW->counter = floatToFix16(0);  // Reset counter
    } else {
        switch (fun_DW->is_On) {
            case fun_IN_LeftHigh:
                if (fun_DW->counter >= floatToFix16(5.0)) {  
                    fun_DW->counter = floatToFix16(0);
                    fun_DW->is_On = fun_IN_RighHigh;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(20.0);  
                } else if (fun_U->SS == floatToFix16(0.0)) {  
                    fun_DW->is_On = fun_IN_LeftLow;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0); 

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(-10.0); 
                } else {
                    fun_DW->counter++;
                    fun_DW->is_On = fun_IN_LeftHigh;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(-20.0); 
                }
                break;

            case fun_IN_LeftLow:
                if (fun_U->SS == floatToFix16(1.0)) {  
                    fun_DW->is_On = fun_IN_LeftHigh;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(-20.0);  
                } else if (fun_DW->counter >= floatToFix16(10.0)) {  
                    fun_DW->counter = floatToFix16(0);
                    fun_DW->is_On = fun_IN_RightLow;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(10.0);  
                } else {
                    fun_DW->counter++;
                    fun_DW->is_On = fun_IN_LeftLow;

                    // Outport: '<Root>/V1'
                    fun_Y->V1 = fun_U->temp - floatToFix16(20.0);  

                    // Outport: '<Root>/V2'
                    fun_Y->V2 = floatToFix16(-10.0);  
                }
                break;
        }
    }

    delay(d);
}

// Initialize the model state
void fun_initialize(tag_RTM_fun_T *const fun_M) {
    DW_fun_T *fun_DW = fun_M->dwork;
    fun_DW->is_active_c3_fun = 0U;
    fun_DW->is_c3_fun = fun_IN_NO_ACTIVE_CHILD;
}

// Terminate function
void fun_terminate(tag_RTM_fun_T *const fun_M) {
    // UNUSED_PARAMETER(fun_M);
}

void myDelay(uint16_T temp) {
    if(temp <= 21){
        d = 23;
    } else if(  temp <= 23){
        d = 16;
    } else if(temp <=24){
        d = 13;
    } else if( temp <= 25){
        d = 7;
    } else if( temp <= 26){
        d = 3;
    } else d = 23;
}

const int servoPin = 9;
Servo fanServo; 
const int out_sen= A0 ;
const int switchPin = 2;
const int fanPin = 3; 
int stepMy = 10;

void setup(){
  Serial.begin(9600);
  
  pinMode(out_sen, INPUT);
  pinMode(switchPin, INPUT_PULLUP); 
  pinMode(fanPin, OUTPUT); 
  pinMode(switchPin, INPUT_PULLUP);
  fanServo.attach(servoPin);      
  fanServo.write(0);
  fun_initialize(&fun_M);
}

void loop(){
  float x = analogRead(out_sen); //read sensor pin
  int switchState = digitalRead(switchPin);
  float voltage = (x * 5.0)/ 1024.0;
  int tem = (voltage - 0.5) * 100.0; //convert voltage data to temperature
  
//   Serial.print("Temperature: ");
//   Serial.print(tem);
//   Serial.println(" °C ");
  
  fun_U.SS = switchState;
  fun_U.temp = floatToFix16(tem);
  
  if (switchState == LOW) {
    stepMy = 5;
  } else {
    stepMy = 2;
  }
  analogWrite(fanPin, fun_Y.V1);


  unsigned long start = millis();   // start time
  fun_step(&fun_M, &fun_U, &fun_Y);
  unsigned long end = millis();     // finish time

  Serial.print("Execution Time: ");
  Serial.print(end - start);
  Serial.println(" milliseconds");
  Serial.println("---------------------------------------");
  Serial.println();
  
//   Serial.print("V1: ");
//   Serial.println(fix16ToFloat(fun_Y.V1));
//   Serial.print("V2: ");
//   Serial.println(fix16ToFloat(fun_Y.V2));
  
  if(tem >= 20) {
    for(int i = 0; i < 180; i++) {
      fanServo.write(i);
      delay(stepMy);
    }

    for(int i = 180; i > 0; i--) {
      fanServo.write(i);
      delay(stepMy);
    }
  }

  delay(100);
}
