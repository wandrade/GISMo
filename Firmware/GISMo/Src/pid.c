#include "pid.h"

void calculatePID(PID_t *pid) {
	pid->error = pid->setpoint - pid->measured_value;
    pid->integral += pid->error;
    pid->control_output = pid->kp * pid->error + pid->ki * pid->integral + pid->kd * (pid->error - pid->previous_error);
    // This step effectively increases the order of magnitute of Kp, kd and ki
    // since they need to be 10000x bigger, this allows us to use uint32_t instead of
    // float which are faster operations
    pid->control_output /= 1000;
    if (pid->control_output > pid->out_lim_max) {
        pid->control_output = pid->out_lim_max;
    } else if (pid->control_output < pid->out_lim_min) {
        pid->control_output = pid->out_lim_min;
    }
    pid->previous_error = pid->error;
}

uint32_t moving_avg_filter(MAF_t *data, uint32_t value){
    data->buffer[data->buffer_start] = value;
    data->buffer_start = (data->buffer_start + 1) % data->window_size;

    uint32_t sum = 0;
    for (uint16_t i = 0; i < data->window_size; i++) {
        sum += data->buffer[i];
    }

    return sum / data->window_size;
}
