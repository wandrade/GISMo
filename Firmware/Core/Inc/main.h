/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <encoder.h>
#include <driver.h>
#include <led.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define DEBUG_1_Pin GPIO_PIN_0
#define DEBUG_1_GPIO_Port GPIOA
#define I_Sense_Pin GPIO_PIN_1
#define I_Sense_GPIO_Port GPIOA
#define Direction_Pin GPIO_PIN_2
#define Direction_GPIO_Port GPIOA
#define PWM_Out_Pin GPIO_PIN_3
#define PWM_Out_GPIO_Port GPIOA
#define nSleep_Pin GPIO_PIN_4
#define nSleep_GPIO_Port GPIOA
#define nFault_Pin GPIO_PIN_5
#define nFault_GPIO_Port GPIOA
#define DEBUG_2_Pin GPIO_PIN_6
#define DEBUG_2_GPIO_Port GPIOA
#define DEBUG_3_Pin GPIO_PIN_7
#define DEBUG_3_GPIO_Port GPIOA
#define DEBUG_4_Pin GPIO_PIN_0
#define DEBUG_4_GPIO_Port GPIOB
#define DEBUG_5_Pin GPIO_PIN_8
#define DEBUG_5_GPIO_Port GPIOA
#define LED_B_Pin GPIO_PIN_9
#define LED_B_GPIO_Port GPIOA
#define PWM_IN_Pin GPIO_PIN_10
#define PWM_IN_GPIO_Port GPIOA
#define LED_G_Pin GPIO_PIN_11
#define LED_G_GPIO_Port GPIOA
#define LED_R_Pin GPIO_PIN_12
#define LED_R_GPIO_Port GPIOA
#define AD0_Pin GPIO_PIN_15
#define AD0_GPIO_Port GPIOA
#define AD1_Pin GPIO_PIN_3
#define AD1_GPIO_Port GPIOB
#define AD2_Pin GPIO_PIN_4
#define AD2_GPIO_Port GPIOB
#define AD3_Pin GPIO_PIN_5
#define AD3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
// Define IRQ timer interupt handler
void TIM1_CC_IRQHandler(void);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
