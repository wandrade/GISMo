#include "encoder.h"

extern ENCODER_STRUCT encoder;
extern TIM_HandleTypeDef htim1;


void init_encoder(){
	  HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_3); // Rising edge
	  HAL_TIM_IC_Start(&htim1, TIM_CHANNEL_4); // Falling Edge - Initialize interrupt capture but no callback function (We only need the CCR4 value)
}

// Define interupt function
void TIM1_CC_IRQHandler(void)
{
#ifdef DEBUG_PIN
	HAL_GPIO_WritePin(DEBUG_1_GPIO_Port, DEBUG_1_Pin, 1);
#endif
	// Check if it comes from channel3
	if(__HAL_TIM_GET_IT_SOURCE(&htim1, TIM_IT_CC3) != RESET){
		// Clear interrupt flag on channel 3
		__HAL_TIM_CLEAR_IT(&htim1, TIM_IT_CC3);
		// Set counter to 48 which is how long it takes for this function to zero (to its like setting it to zero as soon as the PWM sensor rising edge is detected) with a bit of tweaking
		// until i got some known values (e.g. 12 when no magnet is close to the encoder)
		// This value was obtained experimentally by measuring the number of CPU clocks it took to run all these functions (https://www.embedded-computing.com/articles/measuring-code-execution-time-on-arm-cortex-m-mcus)
		__HAL_TIM_SET_COUNTER(&htim1, 65);
		update_encoder(&htim1);
	}
#ifdef DEBUG_PIN
	HAL_GPIO_WritePin(DEBUG_1_GPIO_Port, DEBUG_1_Pin, 0);
#endif
}

void update_encoder(TIM_HandleTypeDef* htim){
	// Reset timer ASAP so we can consider 0 as the beggining of the period,
	// falling edge time as the end of duty cycle and rising time (from next cycle) as the total period time
	encoder.t_rising_edge = htim->Instance->CCR3;
	encoder.t_falling_edge = htim->Instance->CCR4;

	// Get number of clocks of the encoder (4119 per full cycle)
	encoder.pwm_clocks = encoder.t_falling_edge*ENCODER_CLOCKS_PER_CYCLE/encoder.t_rising_edge;


	if(encoder.pwm_clocks >= ENCODER_MIN_VALID_CLOCK_NUM && encoder.pwm_clocks <= ENCODER_MAX_VALID_CLOCK_NUM){
		// Reset error flag
		encoder.error = 0;

		// Calculate singleturn
		encoder.single_prev = encoder.single;
		encoder.single = encoder.pwm_clocks - ENCODER_MIN_VALID_CLOCK_NUM;

		// Multiturn count
		if(encoder.single_prev > 3000 && encoder.single < 1000) // also considers if last measure wasn't an error
			encoder.multiturn_counter++; // positive turn - singleturn goes from a big number to a very small one
		else if (encoder.single_prev < 1000 && encoder.single > 3000) // also considers if last measure wasn't an error
			encoder.multiturn_counter--; // negative turn - singleturn goes from a small number to a very big one

		// Concatenate singleturn and multiturn counters
		encoder.raw = (encoder.multiturn_counter << 12) | encoder.single;

	} else {
		encoder.error++; // Counts consecutive errors;
		if(!encoder.error) encoder.error++; // If overflows, make sure it goes from 0 to 1 again
	}

}


//extern POSITION_STRUCT position;
//extern SPEED_STRUCT speed;


// Get period in seconds
//	encoder.period = (float)encoder.t_rising_edge/(float)TIMER_FREQUENCY;

//void initialize_encoder(){
//	position.filter_size = 5;		// How many readings are averaged for the filtered position reading
//	position.spike_limit = 0.1;		// Max allowed position variation (bigger than this will be discarded)
//	position.spike_counter = 5;		// How many spikes in a row can the system accept before ignoring the spike filter
//}
//
//void update_position_raw(TIM_HandleTypeDef* htim){
//	// Reset timer counter for next interrupt pair
//	__HAL_TIM_SET_COUNTER(htim, 0);
//	position.CCR3 = htim->Instance->CCR3; 	// Rising edge time (channel 3 interrupt time)
//	position.CCR4 = htim->Instance->CCR4; 	// Falling edge time (channel 4 interrupt time)
//
//	// Falling this might happen when position is close to 360 degrees and there is not enough time to process interrupt
//	if(position.CCR4 >= position.CCR3 && position.CCR4 - position.CCR3 < 64000){
//		// Calculate PWM duty cycle
//		position.raw = position.CCR4 - position.CCR3;
//		// Convert Duty cycle into useful stuff
//		update_position_speed();
//	}
//
//}

//
//// AS5048 splits 100% duty cycle into 4119 where max duty cycle is 4111 clock cycles (https://ams.com/documents/20143/36005/AS5048_DS000298_4-00.pdf page 27)
//// Defined on position_encoder.h as CLOCK_TICKS_PER_PWM_CYCLE
//// On each cycle:
////   12 clocks - init (high for 12 clock cycles)
////    4 clocks - Not error (low when there is an error)
//// 4095 clocks - Position
////    8 Clocks - Exit (Low for 8 clock cycles)
//
//// The max value position.raw can be is the max time it takes between two rising edges (refresh period of the sensor) minus the minimal dead time of the line (the 8 exit clocks of the signal)
//// This value is directly measured by CCR4 since we are reseting the timer at each falling edge
//void update_position_speed(){
//	// From MAX_POSITION_TICK_COUNT to 4119 as stated in datasheet
//	uint32_t scaled_raw = CLOCK_TICKS_PER_PWM_CYCLE*position.raw/position.CCR4;
//	if (scaled_raw > 12){ // If its a valid reading
//
//		// Update position single turn
//		position.rad_prev = position.rad;
//		position.rad = (float)(scaled_raw - 15)*PWM_TO_RADIANS_SCALE;
//
//		// Increase multiturn counter when completed a turn
//		if(position.rad_prev > 5.3 && position.rad < 1.0){
//			position.multiturn_counter++;
//		}
//		else if (position.rad_prev < 1.0 && position.rad > 5.3){
//			position.multiturn_counter--;
//		}
//
//		// Update position multiturn
//		position.rad_multiturn_prev = position.rad_multiturn;
//		position.rad_multiturn = position.multiturn_counter*2*PI + position.rad;
//
//		// Multiturn spike filter
//		if(fabs(position.rad_multiturn - position.rad_multiturn_prev) > position.spike_limit && position.spike_counter < 5){
//			position.rad_multiturn = position.rad_multiturn_prev;
//			position.spike_counter++;
//		}
//		else{
//			position.spike_counter = 0;
//		}
//
//		// Position filter
//		if(position.buffer_head < position.filter_size){
//			position.buffer[position.buffer_head] = position.rad_multiturn;
//			position.buffer_head++;
//		}
//		else {
//			position.rad_filtered_prev = position.rad_filtered;
//			position.rad_filtered = 0;
//			for(int i = 0; i < position.filter_size; i++){
//				position.rad_filtered += position.buffer[i];
//			}
//			position.rad_filtered /= position.filter_size;
//			position.buffer_head = 0;
//		}
//
//		// Update speed
//		speed.rad_sec_prev = speed.rad_sec;
//		speed.rad_sec_raw = (position.rad_multiturn - position.rad_multiturn_prev) * ENCODER_REFRESH_RATE;
//
//
//		speed.rad_sec = (position.rad_filtered - position.rad_filtered_prev) * ENCODER_REFRESH_RATE;
//
//		// Speed filter
//		// Put value in buffer if there was no problem with multiturn
//
////		int i;
////		for(i = 0; i < speed.filter_size; i++){
////			// Move all measures 1 position to the left on the buffer vector
////			speed.buffer[i] = speed.buffer[i+1];
////		}
////		speed.buffer[i-1] = speed.rad_sec_raw;
////
////		// Calculate average
////		speed.rad_sec = 0;
////		for(i = 0; i < speed.filter_size; i++){
////			// Move all measures 1 position to the left on the buffer vector
////			speed.rad_sec += speed.buffer[i];
////		}
////		speed.rad_sec /= speed.filter_size;
//
//		position.valid = 1;
//
//	} else {
//		position.valid = 0;
//	}
//
//}










