#include "control.h"
#include "led.h"

extern structured_data_t* d;

PID_t pid_position;

void PositionLoopTask(void* pvParameters) {

    const TickType_t xFrequency                = pdMS_TO_TICKS(12);
    TickType_t       xLastWakeTime             = xTaskGetTickCount();
    static float     previous_setpoint_degrees = 0.0f;
    MAF_t            position_filter;

    // Initialise controller structure every time the task starts
    pid_position.previous_error = 0;

    position_filter.window_size = d->position_filter_window_size;

    for (;;) {
        // Update setpoint parameters if they have changed
        if (d->controller_pos_setpoint != previous_setpoint_degrees) {
            previous_setpoint_degrees = d->controller_pos_setpoint;
            // Convert degrees into raw set point
            pid_position.setpoint =
                (int32_t) (previous_setpoint_degrees * d->controller_pos_setpoint_scale);
            d->controller_pos_setpoint_scaled = pid_position.setpoint;
        }

        // Update pid_position parameters if any of them have changed
        if (pid_position.kp != d->controller_pos_kp) {
            pid_position.kp = d->controller_pos_kp;
        }
        if (pid_position.ki != d->controller_pos_ki) {
            pid_position.ki = d->controller_pos_ki;
        }
        if (pid_position.kd != d->controller_pos_kd) {
            pid_position.kd = d->controller_pos_kd;
        }
        if (pid_position.out_lim_min != d->controller_pos_out_lim_min) {
            pid_position.out_lim_min = d->controller_pos_out_lim_min;
        }
        if (pid_position.out_lim_max != d->controller_pos_out_lim_max) {
            pid_position.out_lim_max = d->controller_pos_out_lim_max;
        }
        if (position_filter.window_size != d->position_filter_window_size) {
            position_filter.window_size = d->position_filter_window_size;
        }

        pid_position.measured_value = moving_avg_filter(&position_filter, d->encoder_raw);
        calculatePID(&pid_position);

        pwm_set_output(pid_position.control_output);

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

void positionLoopStart(TaskHandle_t* taskHandle) {
    if (*taskHandle == NULL) {
        xTaskCreate(PositionLoopTask, "PositionLoop", 256, NULL, tskIDLE_PRIORITY, taskHandle);
    }
}

void positionLoopStop(TaskHandle_t* taskHandle) {
    if (*taskHandle != NULL) {
        vTaskDelete(*taskHandle);
        *taskHandle = NULL;
    }
}
