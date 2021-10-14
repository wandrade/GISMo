/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */



uint16_t turns, pwm_value, dir, step;
uint8_t buf;
#include "i2c.h"

#define I2C_BUFFER_SIZE 10
uint8_t i2c_buffer[I2C_BUFFER_SIZE];
//#define MASTER

/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 1);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 1);
	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 1);
	osDelay(200);
	HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, 0);
	HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, 0);
	HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, 0);


#ifdef MASTER
	i2c_buffer[0] = 0xFF; // 255
	i2c_buffer[1] = 0xAA; // 170
	i2c_buffer[2] = 0x81; // 129
	i2c_buffer[3] = 0x10; // 16

	HAL_I2C_Mem_Write(&hi2c1, (0x1F << 1) | 0x00, 0x07, 1, (void*)i2c_buffer, 4, 10000);

	HAL_Delay(5000);
	HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin);

	HAL_I2C_Mem_Read(&hi2c1, (0x1F << 1) | 0x01, 0x07, 1, (void*)i2c_buffer, 4, 10000);
//    if (HAL_I2C_Master_Transmit(&hi2c1, 0x1F << 1, (uint8_t *)"0123", 1, 10000) != HAL_OK)
//    {
//        asm("bkpt 255");
//    }
#else
	HAL_I2C_EnableListen_IT(&hi2c1);
#endif
  for(;;)
  {
	#ifdef MASTER
	#else
//		enable_i2c_it_DMA();
	#endif

  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

#define I2C_ADD_SIZE 		1
static uint8_t data_size;

extern void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode){
	UNUSED(AddrMatchCode);

	// If is master write, listen to necessary amount of bytes
	if(TransferDirection == I2C_DIRECTION_TRANSMIT){
		data_size = 4;
		// Get amount of data to send
		HAL_I2C_Slave_Sequential_Receive_IT(hi2c, (void*)i2c_buffer, I2C_ADD_SIZE + data_size, I2C_FIRST_FRAME);
	}
	else {
		// Get data into I2C buffer
		data_size = 4;
		HAL_I2C_Slave_Sequential_Transmit_IT(hi2c, (void*)&i2c_buffer[1], data_size, I2C_FIRST_FRAME);
	}
	// Read address + data size. If it is a read command, data size will be zero
}


extern void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c){
	HAL_I2C_EnableListen_IT(hi2c);
}

extern void HAL_I2C_ListenCpltCallback (I2C_HandleTypeDef *hi2c){
	HAL_I2C_EnableListen_IT(hi2c);
}

extern void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c){
	HAL_I2C_EnableListen_IT(hi2c);
}


extern void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	//HAL_I2C_ERROR_NONE       0x00000000U    /*!< No error           */
	//HAL_I2C_ERROR_BERR       0x00000001U    /*!< BERR error         */
	//HAL_I2C_ERROR_ARLO       0x00000002U    /*!< ARLO error         */
	//HAL_I2C_ERROR_AF         0x00000004U    /*!< Ack Failure error  */
	//HAL_I2C_ERROR_OVR        0x00000008U    /*!< OVR error          */
	//HAL_I2C_ERROR_DMA        0x00000010U    /*!< DMA transfer error */
	//HAL_I2C_ERROR_TIMEOUT    0x00000020U    /*!< Timeout Error      */
	uint32_t error_code = HAL_I2C_GetError(hi2c);
	if (error_code != HAL_I2C_ERROR_AF){}
	HAL_I2C_EnableListen_IT(hi2c);
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
