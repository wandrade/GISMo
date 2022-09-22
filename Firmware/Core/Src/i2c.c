/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    i2c.c
  * @brief   This file provides code for the configuration
  *          of the I2C instances.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

I2C_HandleTypeDef hi2c1;

/* I2C1 init function */
void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */
  // Get I2C address code from hardware jumpers
  // Address starts at I2C_ADDRESS_BASE and is offset by value read on jumpers array
  uint8_t I2C_Address = 0x0;
  I2C_Address = (I2C_ADDRESS_BASE + (
		  (HAL_GPIO_ReadPin(AD0_GPIO_Port, AD0_Pin) << 0)|
		  (HAL_GPIO_ReadPin(AD1_GPIO_Port, AD1_Pin) << 1)|
		  (HAL_GPIO_ReadPin(AD2_GPIO_Port, AD2_Pin) << 2)|
		  (HAL_GPIO_ReadPin(AD3_GPIO_Port, AD3_Pin) << 3)
  )) << 1;
  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x2000090E;
  hi2c1.Init.OwnAddress1 = I2C_Address;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_ENABLE;
  hi2c1.Init.OwnAddress2 = (I2C_ADDRESS_BASE + 16) << 1;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspInit 0 */

  /* USER CODE END I2C1_MspInit 0 */

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* I2C1 clock enable */
    __HAL_RCC_I2C1_CLK_ENABLE();

    /* I2C1 interrupt Init */
    HAL_NVIC_SetPriority(I2C1_EV_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_SetPriority(I2C1_ER_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspInit 1 */

  /* USER CODE END I2C1_MspInit 1 */
  }
}

void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
{

  if(i2cHandle->Instance==I2C1)
  {
  /* USER CODE BEGIN I2C1_MspDeInit 0 */

  /* USER CODE END I2C1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_I2C1_CLK_DISABLE();

    /**I2C1 GPIO Configuration
    PB6     ------> I2C1_SCL
    PB7     ------> I2C1_SDA
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_7);

    /* I2C1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(I2C1_EV_IRQn);
    HAL_NVIC_DisableIRQ(I2C1_ER_IRQn);
  /* USER CODE BEGIN I2C1_MspDeInit 1 */

  /* USER CODE END I2C1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

#define I2C_BUFFER_SIZE 8
uint8_t i2c_buffer[I2C_BUFFER_SIZE];

#define I2C_ADD_SIZE 		1
static uint8_t data_size;

uint8_t MEMORY[7];



extern void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode){
	UNUSED(AddrMatchCode);
	MEMORY[0] = 0x10;
	MEMORY[1] = 0x11;
	MEMORY[2] = 0x12;
	MEMORY[3] = 0x13;
	MEMORY[4] = 0x14;
	MEMORY[5] = 0x15;
	MEMORY[6] = 0x16;
	i2c_buffer[1] = 0x41;
	i2c_buffer[2] = 0x55;
	// If is master write, listen to necessary amount of bytes
	if(TransferDirection == I2C_DIRECTION_TRANSMIT){
		// Saves last command at the end of buffer
		i2c_buffer[I2C_BUFFER_SIZE-1] = i2c_buffer[0];
		HAL_I2C_Slave_Sequential_Receive_IT(hi2c, (void*)i2c_buffer, I2C_ADD_SIZE + data_size, I2C_FIRST_FRAME);
	}
	else {
			HAL_I2C_Slave_Sequential_Transmit_IT(hi2c, (void*)&MEMORY[i2c_buffer[0]], 2, I2C_LAST_FRAME);
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
/* USER CODE END 1 */
