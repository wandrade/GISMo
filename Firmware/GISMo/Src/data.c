// data.c

#include "data.h"
#include "led.h"
data_register_t    data_register;
structured_data_t* d = &data_register.s;

void init_data() {
    d->device_ID                     = 0x5541;
    d->version_major                 = 1;
    d->version_minor                 = 0;
    d->commit_hash                   = 0x19217ded;
    d->led_mode                      = LED_MODE_OFF;
    d->controller_pos_kp             = 1500;
    d->controller_pos_ki             = 10;
    d->controller_pos_kd             = 50;
    d->controller_pos_integral       = 0;
    d->controller_pos_out_lim_min    = -1500;
    d->controller_pos_out_lim_max    = 1500;
    d->position_filter_window_size   = 1;
    d->controller_pos_setpoint_scale = 4096.0 / 360.0; // degrees to raw
}
