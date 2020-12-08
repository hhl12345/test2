/*
 * lds_LBus_cmd.c
 *
 *  Created on: 2020��11��19��
 *      Author: zhangtao2
 */
 
#include "lds_Lbus_func_DT1.h"
#include "lds_Lbus_func.h"
#include "lds_LBus_para.h"
#include "lds_hal_uart.h"


#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)

eState_t LBus_func_DT1_task(stCmdFrame_t *stCmdFrame){
uint8_t cIndex;

  switch(stCmdFrame->usObjectID){
    /*motion sensor*/
    case 107:
      switch(stCmdFrame->usAttributeID){
        case 1://���ԣ�ʹ��
          cIndex = 0;
          break;
      
        case 2://���ԣ�ֵ
          cIndex = 1;
          break;
      
        case 17://���ԣ�������������
          cIndex = 2;
          break;

        case 18://���ԣ�ռ����ʱʱ��
          cIndex = 3;
          break;

        case 21://���ԣ�ʹ�ܶ�ʱ�ϱ�����
          cIndex = 4;
          break;

        default :
          return E_HAL_ERROR;
          break;
      }
      /*������ѯ����*/
      if(1 == stCmdFrame->cDataLen){
        if(0xFF == stCmdFrame->acAttributeVal[0]){
          LBus_func_encode(SUBDEVICE_ID,
                          MASTER_ID,
                          REPLY_TO_MASTER,
                          stCmdFrame->cTotalNum,
                          stCmdFrame->cPresentNum,
                          stCmdFrame->usObjectID,
                          stCmdFrame->cObjectChannel,
                          stCmdFrame->usAttributeID,
                          stCmdFrame->cAttributeChannel,
                          gunMotionSensor.ausArray,
                          2);
        }
        else{
          return E_HAL_ERROR;
        }
      }
      /*�������ò���*/
      else if((1 < stCmdFrame->cDataLen)&&(5 > stCmdFrame->cDataLen)){
        gunMotionSensor.ausArray[cIndex] = ((uint16_t)stCmdFrame->acAttributeVal[0]<<8) | ((uint16_t)stCmdFrame->acAttributeVal[1]);
        /*����motion sensor��������*/
        if(2 == cIndex){
          uint8_t acBuf[3];
          acBuf[0] = 0x10;
          acBuf[1] = stCmdFrame->acAttributeVal[1];
          acBuf[2] = acBuf[0] + acBuf[1] + 1;
          hal_uart_send(acBuf, 3);
        }
      }
      else{
        return E_HAL_ERROR;
      }
      break;
    /*light sensor*/
    case 108:
      switch(stCmdFrame->usAttributeID){
        case 1://���ԣ�ʹ��
          cIndex = 0;
          break;
      
        case 2://���ԣ�ֵ
          cIndex = 1;
          break;
      
        case 15://���ԣ���ֵ����
          cIndex = 2;
          break;

        case 16://���ԣ���ֵ����
          cIndex = 3;
          break;

        case 20://���ԣ���������
          cIndex = 4;
          break;

        case 21://���ԣ���ʱ�ϱ�����
          cIndex = 5;
          break;

        default :
          return E_HAL_ERROR;
          break;
      }
      /*������ѯ����*/
      if(1 == stCmdFrame->cDataLen){
        if(0xFF == stCmdFrame->acAttributeVal[0]){
          LBus_func_encode(SUBDEVICE_ID,
                          MASTER_ID,
                          REPLY_TO_MASTER,
                          stCmdFrame->cTotalNum,
                          stCmdFrame->cPresentNum,
                          stCmdFrame->usObjectID,
                          stCmdFrame->cObjectChannel,
                          stCmdFrame->usAttributeID,
                          stCmdFrame->cAttributeChannel,
                          gunLightSensor.ausArray,
                          2);
        }
        else{
          return E_HAL_ERROR;
        }
      }
      /*�������ò���*/
      else if((1 < stCmdFrame->cDataLen)&&(5 > stCmdFrame->cDataLen)){
        gunLightSensor.ausArray[cIndex] = ((uint16_t)stCmdFrame->acAttributeVal[0]<<8) | ((uint16_t)stCmdFrame->acAttributeVal[1]);
      }
      
      else{
        return E_HAL_ERROR;
      }
      break;
  
    default :
      return E_HAL_ERROR;
      break;
  }
  return E_HAL_OK;
}

#endif

