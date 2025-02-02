#include <Arduino.h>

// Example code for controlling a hypothetical rotating fan using FreeRTOS
// This code includes input and output tasks and demonstrates ISR-based task triggering
#include <Arduino_FreeRTOS.h>
// #include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>
#include <Servo.h>
#include <stdio.h>

// Simulated input/output pins
#define TEMP_SENSOR_PIN A0
#define SWITCH_PIN 2
#define FAN_SPEED_PIN 3
#define SERVO_PIN 9

// Queue and Semaphore Handles
QueueHandle_t xSpeedQueue;
QueueHandle_t xDirectionQueue;
SemaphoreHandle_t xISRTrigger;

// Servo object
Servo fanServo;

// Function Prototypes
void vFanSpeedTask(void *pvParameters);
void vFanDirectionTask(void *pvParameters);
void vInputProcessingTask(void *pvParameters);
void vTimerCallback(TimerHandle_t xTimer);
void vISRHandler(void);

// Main Function
int main(void)
{
    // Initialize hardware
    pinMode(TEMP_SENSOR_PIN, INPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(FAN_SPEED_PIN, OUTPUT);
    fanServo.attach(SERVO_PIN);
    fanServo.write(0); // Initial position

    // Create queues for communication
    xSpeedQueue = xQueueCreate(10, sizeof(int));
    xDirectionQueue = xQueueCreate(10, sizeof(int));

    // Create binary semaphore for ISR synchronization
    xISRTrigger = xSemaphoreCreateBinary();

    // Create tasks
    xTaskCreate(vFanSpeedTask, "FanSpeedTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vFanDirectionTask, "FanDirectionTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);
    xTaskCreate(vInputProcessingTask, "InputProcessingTask", configMINIMAL_STACK_SIZE, NULL, 2, NULL);

    // Create a timer for periodic task triggering
    TimerHandle_t xTimer = xTimerCreate("PeriodicTimer", pdMS_TO_TICKS(1000), pdTRUE, NULL, vTimerCallback);
    xTimerStart(xTimer, 0);

    // Start the scheduler
    vTaskStartScheduler();

    // Code should never reach here
    for (;;);
}

// Task to process fan speed output
void vFanSpeedTask(void *pvParameters)
{
    int fanSpeed;
    for (;;)
    {
       analogWrite(FAN_SPEED_PIN, 120);
        // Wait for new speed data
        if (xQueueReceive(xSpeedQueue, &fanSpeed, portMAX_DELAY) == pdPASS)
        {
            // Simulate setting the fan speed
           
            printf("Fan Speed Set to: %d\n", fanSpeed);
        }
    }
}

// Task to process fan direction output
void vFanDirectionTask(void *pvParameters)
{
    int fanDirection;
    static int pos = 0;
    for (;;)
    {
        // Wait for new direction data
        if (xQueueReceive(xDirectionQueue, &fanDirection, portMAX_DELAY) == pdPASS)
        {
            // Adjust servo position
            for (int i = pos; i != pos + fanDirection; i += (fanDirection > 0 ? 1 : -1))
            {
                fanServo.write(i);
                vTaskDelay(pdMS_TO_TICKS(20)); // Smooth rotation
            }
            pos += fanDirection;
            printf("Fan Direction Adjusted to Position: %d\n", pos);
        }
    }
}

// Task to process input
void vInputProcessingTask(void *pvParameters)
{
    int speedInput;
    int directionInput;

    for (;;)
    {
        // Simulate reading inputs
        int rawTemp = analogRead(TEMP_SENSOR_PIN);
        float voltage = (rawTemp * 5.0) / 1024.0;
        float temperature = (voltage - 0.5) * 100.0; // Convert to Celsius
        int switchState = digitalRead(SWITCH_PIN);

        // Determine speed based on temperature
        if (temperature > 30.0)
            speedInput = 255;
        else if (temperature > 20.0)
            speedInput = 128;
        else
            speedInput = 0;

        // Determine direction based on switch state
        directionInput = (switchState == LOW) ? 30 : -30; // Example step values

        // Send inputs to respective queues
        xQueueSend(xSpeedQueue, &speedInput, portMAX_DELAY);
        xQueueSend(xDirectionQueue, &directionInput, portMAX_DELAY);

        // Wait for ISR-triggered semaphore if needed
        if (xSemaphoreTake(xISRTrigger, portMAX_DELAY) == pdTRUE)
        {
            printf("Event-Triggered Input Processing\n");
        }

        vTaskDelay(pdMS_TO_TICKS(500)); // Polling delay
    }
}

// Timer callback for periodic events
void vTimerCallback(TimerHandle_t xTimer)
{
    static int periodicSpeed = 50; // Example value
    xQueueSend(xSpeedQueue, &periodicSpeed, 0);
    printf("Periodic Speed Update: %d\n", periodicSpeed);
}

// Simulated ISR handler
void vISRHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(xISRTrigger, &xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(); // Corrected call without argument
}

void loop() {
    // This function is required by Arduino but is not used with FreeRTOS.
}

