// pid.h
#ifndef PID_H
#define PID_H

#include <stdint.h>

#define MAF_BUFFER_SIZE 50

typedef struct {
    uint32_t kp;
    uint32_t ki;
    uint32_t kd;
    int32_t previous_error;
    int32_t integral;
    int32_t setpoint;
    int32_t measured_value;
    int32_t control_output;
    int32_t error;
    int32_t out_lim_min;
    int32_t out_lim_max;
} PID_t;

typedef struct {
	uint16_t window_size;
	int32_t buffer[MAF_BUFFER_SIZE];
	uint16_t buffer_start;
} MAF_t;

void calculatePID(PID_t *pid);
uint32_t moving_avg_filter(MAF_t *data, uint32_t value);

#endif //PID_H
