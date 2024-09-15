#include "control.h"
#include "led.h"

extern data_register_t data_register;

PID_t pid_position;

void PositionLoopTask(void *pvParameters) {

    const TickType_t xFrequency = pdMS_TO_TICKS(12);
    TickType_t xLastWakeTime = xTaskGetTickCount();
    static float previous_setpoint_degrees = 0.0f;
    MAF_t position_filter;

    // Initialise controller structure every time the task starts
    pid_position.kp = 1500;
    pid_position.ki = 0;
    pid_position.kd = 50;
    pid_position.integral = 0;
    pid_position.out_lim_min = -1500;
    pid_position.out_lim_max = 1500;
    pid_position.previous_error = 0;

    position_filter.window_size = 1;

    for (;;) {
        if (data_register.s.controller_pos_setpoint != previous_setpoint_degrees) {
            previous_setpoint_degrees = data_register.s.controller_pos_setpoint;
            // Convert degrees into raw set point
            pid_position.setpoint = (int32_t)(previous_setpoint_degrees * 4096.0 / 360.0);
        }

        pid_position.measured_value = moving_avg_filter(&position_filter, data_register.s.encoder_raw);
        calculatePID(&pid_position);

        if(pid_position.control_output >= 1000){
            data_register.s.led_mode = LED_MODE_ON_R;
        } else if (pid_position.control_output <= -1000){
            data_register.s.led_mode = LED_MODE_ON_B;
        } else {
            data_register.s.led_mode = LED_MODE_ON_G;
        }
        pwm_set_output(pid_position.control_output);

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void positionLoopStart(TaskHandle_t *taskHandle) {
	if (*taskHandle == NULL) {
		xTaskCreate(PositionLoopTask, "PositionLoop", 256, NULL, tskIDLE_PRIORITY, taskHandle);
    }
}

void positionLoopStop(TaskHandle_t *taskHandle) {
    if (*taskHandle != NULL) {
        vTaskDelete(*taskHandle);
        *taskHandle = NULL;
    }
}
