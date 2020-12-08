/*
 * lds_LBus_cmd.c
 *
 *  Created on: 2020年11月19日
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
        case 1://属性：使能
          cIndex = 0;
          break;
      
        case 2://属性：值
          cIndex = 1;
          break;
      
        case 17://属性：传感器灵敏度
          cIndex = 2;
          break;

        case 18://属性：占空延时时间
          cIndex = 3;
          break;

        case 21://属性：使能定时上报周期
          cIndex = 4;
          break;

        default :
          return E_HAL_ERROR;
          break;
      }
      /*主机查询参数*/
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
      /*主机设置参数*/
      else if((1 < stCmdFrame->cDataLen)&&(5 > stCmdFrame->cDataLen)){
        gunMotionSensor.ausArray[cIndex] = ((uint16_t)stCmdFrame->acAttributeVal[0]<<8) | ((uint16_t)stCmdFrame->acAttributeVal[1]);
        /*设置motion sensor的灵敏度*/
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
        case 1://属性：使能
          cIndex = 0;
          break;
      
        case 2://属性：值
          cIndex = 1;
          break;
      
        case 15://属性：阈值下限
          cIndex = 2;
          break;

        case 16://属性：阈值上限
          cIndex = 3;
          break;

        case 20://属性：采样周期
          cIndex = 4;
          break;

        case 21://属性：定时上报周期
          cIndex = 5;
          break;

        default :
          return E_HAL_ERROR;
          break;
      }
      /*主机查询参数*/
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
      /*主机设置参数*/
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

