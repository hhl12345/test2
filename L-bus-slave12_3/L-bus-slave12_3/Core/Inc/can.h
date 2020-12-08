/**
  ******************************************************************************
  * File Name          : CAN.h
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __can_H
#define __can_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#define   PASS_ID_STD   55	
#define   PASS_ID_EXT   ((uint32_t)0x1FFFFFFF)
#define   CAN_ST_ID_1   0x001	  
#define   CAN_ST_ID_2   0x002	  
#define   CAN_ST_ID_3   0x003	  
#define   CAN_ST_ID_4   0x004	  




/* USER CODE END Includes */

extern CAN_HandleTypeDef hcan;

/* USER CODE BEGIN Private defines */
extern CAN_TxHeaderTypeDef     stCanTxMeg;
extern CAN_RxHeaderTypeDef     stCanRxMeg;
extern CAN_FilterTypeDef       stFilterConfig; //CAN1ÂË²¨Æ÷

/* USER CODE END Private defines */

void MX_CAN_Init(void);

/* USER CODE BEGIN Prototypes */
void stm32f0xx_can_init(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ can_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
