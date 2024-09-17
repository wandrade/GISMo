// data.h
#ifndef DATA_H
#define DATA_H

#include <stdint.h>

#define DATA_REGISTER_SIZE 256

typedef struct {
    // RO
    uint16_t device_ID;            // 0x00
    uint8_t  version_major;        // 0x02
    uint8_t  version_minor;        // 0x03
    int32_t  encoder_raw;          // 0x04
    int32_t  encoder_multiturn;    // 0x08
    uint32_t encoder_error;        // 0x0C
    float    controller_pos_error; // 0x10
    // RW
    int16_t  cmd;                            // 0x14
    uint8_t  led_mode;                       // 0x16
    uint8_t  enable_motor;                   // 0x17
    uint8_t  controller_mode;                // 0x18
    float    controller_pos_setpoint;        // 0x19
    float    controller_pos_setpoint_scale;  // 0x1D
    uint32_t controller_pos_setpoint_scaled; // 0x21
    uint32_t controller_pos_kp;              // 0x25
    uint32_t controller_pos_ki;              // 0x29
    uint32_t controller_pos_kd;              // 0x2D
    int32_t  controller_pos_integral;        // 0x31
    int32_t  controller_pos_out_lim_min;     // 0x35
    int32_t  controller_pos_out_lim_max;     // 0x39
    int32_t  controller_pos_previous_error;  // 0x3D
    uint8_t  position_filter_window_size;    // 0x41
    int16_t  duty_cycle;                     // 0x42
} structured_data_t;

typedef union {
    uint8_t           r[DATA_REGISTER_SIZE]; // Raw
    structured_data_t s;                     // Structured
} data_register_t;

extern data_register_t data_register;

void init_data();

#endif
