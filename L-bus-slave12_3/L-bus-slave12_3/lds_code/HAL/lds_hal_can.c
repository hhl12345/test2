/*
 * lds_hal_can.c
 *
 *  Created on: 2020年11月18日
 *      Author: zhangtao2
 */

#include "lds_hal_can.h"
#include "can.h"
#include "stm32f0xx_hal_can.h"

void hal_can_init(void){
  MX_CAN_Init();
  stm32f0xx_can_init();
}

/**
  * @brief  接收CAN的扩展ID和数据包
  *
  * @param[out]  uiExtID  : 扩展ID
  * @param[out]  pcBuf    : ExtID+dataBuff.
  * @param[out]  cLen     : 数据包有效长度.
  *
  * @retval eState_t
  */
eState_t hal_can0_getExtData(stLBusRec_t *stLBusRec){
  HAL_StatusTypeDef HAL_Status;
  uint8_t acArray[8];
  
  HAL_Status = HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &stCanRxMeg, acArray);
  if(HAL_OK == HAL_Status){
    stLBusRec->uiExtID = stCanRxMeg.ExtId;
    stLBusRec->cLen = stCanRxMeg.DLC;
    //lds_debug_printf("CAN接收ExtId为: %#X \r\n",stLBusRec->uiExtID);
    lds_debug_printf("CAN接收ExtId为: %x \r\n",stLBusRec->uiExtID);
    lds_debug_printf("CAN接收数据包长度为: %d \r\n",stLBusRec->cLen);

    for(uint8_t i=0; i<stLBusRec->cLen; i++){
      stLBusRec->acBuf[i] = acArray[i];
      //lds_debug_printf("%#X \r\n",acArray[i]); 
    }
    return E_HAL_OK;
  }
  else{
    return E_HAL_ERROR;
  }
}

/**
  * @brief  Register the timer
  *
  * @param[out] uiExtID  : 扩展ID
  * @param[in]  pcBuf    : ExtID+dataBuff.
  * @param[in]  cLen     : 数据段有效长度.
  *
  * @retval None
  */
eState_t hal_can0_sendExtData(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t cLen){
  HAL_StatusTypeDef	eHalState;
  uint32_t uiSendMail;

  stCanTxMeg.ExtId = uiExtID; 
	stCanTxMeg.DLC = cLen;
  uiSendMail = CAN_TX_MAILBOX0;
  eHalState = HAL_CAN_AddTxMessage(&hcan, &stCanTxMeg, pcDataBuf, &uiSendMail);
  if(HAL_OK == eHalState){
    lds_debug_printf("CAN发送成功! \r\n");
    return E_HAL_OK;
  }
  else{
    lds_debug_printf("CAN发送失败! \r\n");
    return E_HAL_ERROR;
  }
}



