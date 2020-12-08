/*
 * lds_hal_can.h
 *
 *  Created on: 2020��11��18��
 *      Author: zhangtao2
 */
#ifndef __LDS_HAL_CAN_H__
#define __LDS_HAL_CAN_H__  
  
#include <lds_config.h>

typedef struct{
  uint32_t uiExtID;
  uint8_t acBuf[8];  //CAN����֡�����ݶ�
  uint8_t cLen;                   //���ݶ���Ч����
}stLBusRec_t;


void hal_can_init(void);
eState_t hal_can0_getExtData(stLBusRec_t *stLBusRec);
eState_t hal_can0_sendExtData(uint32_t uiExtID, uint8_t *pcBuf, uint8_t cLen);

#endif

