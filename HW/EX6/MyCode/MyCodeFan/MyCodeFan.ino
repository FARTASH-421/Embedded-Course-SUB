// Data type definitions
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
typedef long long int64_T;
typedef unsigned long long uint64_T;
typedef float real32_T;
typedef double real64_T;
typedef double real_T;
typedef double time_T;
typedef unsigned char boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef unsigned long long ulonglong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

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
    real_T counter;
    uint8_T is_active_c3_fun;
    uint8_T is_c3_fun;
    uint8_T is_On;
};

struct ExtU_fun_T {
    real_T SS;
    real_T temp;
};

struct ExtY_fun_T {
    real_T V1;
    real_T V2;
};

struct tag_RTM_fun_T {
    const char_T * volatile errorStatus;
    DW_fun_T *dwork;
};

// Function prototypes
void fun_step(tag_RTM_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T *fun_Y);
void fun_initialize(tag_RTM_fun_T *const fun_M);
void fun_terminate(tag_RTM_fun_T *const fun_M);

// Global model and state variables
tag_RTM_fun_T fun_M;
ExtU_fun_T fun_U;
ExtY_fun_T fun_Y;


// Step function for the model
void fun_step(tag_RTM_fun_T *const fun_M, ExtU_fun_T *fun_U, ExtY_fun_T *fun_Y) {
    DW_fun_T *fun_DW = fun_M->dwork;

    // Chart logic
    if (fun_DW->is_active_c3_fun == 0U) {
        fun_DW->is_active_c3_fun = 1U;
        fun_DW->is_c3_fun = fun_IN_Off;

        // Initialize outputs
        fun_Y->V1 = 0.0;
        fun_Y->V2 = 0.0;
        fun_DW->counter = 0.0;
    } else if (fun_DW->is_c3_fun == fun_IN_Off) {
        fun_Y->V2 = 0.0;
        if (fun_U->temp > 20.0) {
            fun_DW->is_c3_fun = fun_IN_On;
            fun_DW->is_On = fun_IN_RightLow;

            // Outport: '<Root>/V1'
            fun_Y->V1 = fun_U->temp - 20.0;

            // Outport: '<Root>/V2'
            fun_Y->V2 = 10.0;
        }
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


#include <Servo.h>
int v = 0;
int pos = 0;
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
  unsigned long start = micros(); // زمان شروع
    // step(input, output); // اجرای تابع
  
    
  float x = analogRead(out_sen); //read sensor pin
  int switchState = digitalRead(switchPin);
  Serial.print("this analog TMP: ");
  Serial.println(x);
  float voltage = (x * 5.0)/ 1024.0;
  float tem=(voltage-0.5)*100.0; //convert voltage data to temperature
  
  Serial.print("Temperature: ");
  Serial.print(tem);
  Serial.println(" °C ");
  
   

    // Initialize input values
    fun_U.SS = switchState;
    fun_U.temp = tem;
  
  if (switchState == LOW) {
   		  stepMy = 30;
  }
  else{
   
    stepMy = 10;
  }
  
  //Serial.println("high");
   analogWrite(fanPin, fun_Y.V1);
  
  
   fun_step(&fun_M, &fun_U, &fun_Y);

    // Output the results to the serial monitor
    Serial.print("V1: ");
    Serial.println(fun_Y.V1);
    Serial.print("V2: ");
    Serial.println(fun_Y.V2);
  
  if( tem >= 20){
    for(int i= 0; i < 180; i++){
      fanServo.write(i);
      delay(stepMy);
    }

    for(int i= 180; i > 0; i--){
      fanServo.write(i);
      delay(stepMy);
    }
     
     
  }

  unsigned long end = micros();
  

  Serial.print("Execution Time: ");
  Serial.print(end - start);
  Serial.println(" microseconds");
  // delay(10)
 }

void loop(){
  
  
  // delay(100);
  
}