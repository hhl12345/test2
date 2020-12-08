/**
  ******************************************************************************
  * File Name          : CAN.c
  * Description        : This file provides code for the configuration
  *                      of the CAN instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
//#include <lds_hal_debugPrintf.h>
#include "lds_hal_debugPrintf.h"
#include "lds_hal_uart.h"
#include "can.h"

/* USER CODE BEGIN 0 */

CAN_TxHeaderTypeDef     stCanTxMeg;
CAN_RxHeaderTypeDef     stCanRxMeg;

CAN_FilterTypeDef       stFilterConfig; //CAN1ÂË²¨Æ÷

/* USER CODE END 0 */

CAN_HandleTypeDef hcan;

/* CAN init function */
void MX_CAN_Init(void)
{

  hcan.Instance = CAN;
  hcan.Init.Prescaler = 120;
  hcan.Init.Mode = CAN_MODE_LOOPBACK;
  hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan.Init.TimeSeg1 = CAN_BS1_4TQ;
  hcan.Init.TimeSeg2 = CAN_BS2_3TQ;
  hcan.Init.TimeTriggeredMode = DISABLE;
  hcan.Init.AutoBusOff = ENABLE;
  hcan.Init.AutoWakeUp = DISABLE;
  hcan.Init.AutoRetransmission = ENABLE;
  hcan.Init.ReceiveFifoLocked = DISABLE;
  hcan.Init.TransmitFifoPriority = DISABLE;
  if (HAL_CAN_Init(&hcan) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_CAN_MspInit(CAN_HandleTypeDef* canHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(canHandle->Instance==CAN)
  {
  /* USER CODE BEGIN CAN_MspInit 0 */

  /* USER CODE END CAN_MspInit 0 */
    /* CAN clock enable */
    __HAL_RCC_CAN1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**CAN GPIO Configuration
    PB8     ------> CAN_RX
    PB9     ------> CAN_TX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF4_CAN;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* CAN interrupt Init */
    HAL_NVIC_SetPriority(CEC_CAN_IRQn, 1, 0);
    HAL_NVIC_EnableIRQ(CEC_CAN_IRQn);
  /* USER CODE BEGIN CAN_MspInit 1 */

  /* USER CODE END CAN_MspInit 1 */
  }
}

void HAL_CAN_MspDeInit(CAN_HandleTypeDef* canHandle)
{

  if(canHandle->Instance==CAN)
  {
  /* USER CODE BEGIN CAN_MspDeInit 0 */

  /* USER CODE END CAN_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_CAN1_CLK_DISABLE();

    /**CAN GPIO Configuration
    PB8     ------> CAN_RX
    PB9     ------> CAN_TX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_8|GPIO_PIN_9);

    /* CAN interrupt Deinit */
    HAL_NVIC_DisableIRQ(CEC_CAN_IRQn);
  /* USER CODE BEGIN CAN_MspDeInit 1 */

  /* USER CODE END CAN_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
void stm32f0xx_can_init(void){
  CAN_FilterTypeDef  stFilterConfig;
  HAL_StatusTypeDef  HAL_Status;

	stCanTxMeg.ExtId = 0;
	stCanTxMeg.IDE=CAN_ID_EXT;//CAN_ID_STD;
	stCanTxMeg.RTR=CAN_RTR_DATA;
	stCanTxMeg.DLC=8;
	stCanTxMeg.TransmitGlobalTime = DISABLE;
  
  stFilterConfig.FilterIdHigh =PASS_ID_EXT>>13;//((PASS_ID_EXT<<3 | CAN_ID_EXT | CAN_RTR_DATA)&0xFFFF0000)>>16 ;//PASS_ID_STD << 5;
  stFilterConfig.FilterIdLow = (PASS_ID_EXT<<3 | CAN_ID_EXT | CAN_RTR_DATA)&0xFFFF;
  stFilterConfig.FilterMaskIdHigh = 0;//0xFFFF;
  stFilterConfig.FilterMaskIdLow = 0;//0xFFFF;
  stFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
  stFilterConfig.FilterBank = 0;
  stFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
  stFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
  stFilterConfig.FilterActivation = ENABLE;
  stFilterConfig.SlaveStartFilterBank = 0;
  lds_debug_printf("ÅäÖÃCAN¹ýÂËÆ÷!\r\n");
  
  HAL_Status=HAL_CAN_ConfigFilter(&hcan, &stFilterConfig);
  if(HAL_Status!=HAL_OK){
  	lds_debug_printf("ÅäÖÃCAN¹ýÂËÆ÷Ê§°Ü!\r\n");
  }
  HAL_Status=HAL_CAN_Start(&hcan);  //¿ªÆôCAN
  if(HAL_Status!=HAL_OK){
  	lds_debug_printf("¿ªÆôCANÊ§°Ü!\r\n");
  }

  HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING);
}	


/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
