
#include "lds_LBus_func.h"
#include "lds_Lbus_func_DT1.h"
#include "lds_LBus_basic_func.h"
#include "lds_hal_can.h"
#include "lds_hal_debugPrintf.h"


static stLBusTxBuf_t sastLBusTxBuf;
static stLBusTxBuf_t sastLBusTxBufEmerg;
static stLBusRxBuf_t sastLBusRxBuf;

/**
  * @brief  解包并执行
  *
  * @param : None
  *
  * @retval None
  */
void LBus_func_decode(void){
  uint8_t cFuncCode;
  stCmdFrame_t stCmdFrame;
  
  if(sastLBusRxBuf.cCurrentNum != sastLBusRxBuf.cFinalNum){
    cFuncCode = (uint8_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID>>7);
    
    switch(cFuncCode){
      case E_SN_FRAME:
        lds_debug_printf("E_SN_FRAME\n");
        LBus_basic_SN_func(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID, 
                          sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf, 
                          sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen);
        break;
    
      case E_UPDATE_FRAME:
        lds_debug_printf("E_UPDATE_FRAME\n");
        LBus_basic_firewmareUpdata(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID, 
                                  sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf, 
                                  sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen);
        break;
    
      case E_ID_FRAME:
        lds_debug_printf("E_ID_FRAME\n");
        LBus_basic_CAN_ID_func(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID, 
                              sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf, 
                              sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen);
        break;

      case E_CMD_FRAME:
        lds_debug_printf("E_CMD_FRAME\n");
        stCmdFrame.cTotalNum = (uint8_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID>>4) & 0x07;
        stCmdFrame.cPresentNum = (uint8_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID>>1) & 0x07;
        stCmdFrame.usObjectID = ((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID&0x00000001)<<9) | 
                              (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[0]))<<1) | 
                              (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]))>>7);
        stCmdFrame.cObjectChannel = (sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]&0x7C)>>2;
        stCmdFrame.usAttributeID = (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]))<<9) | 
                                (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[2]))<<1) | 
                                (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[3]))>>7);
        stCmdFrame.cAttributeChannel = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[3]&0x7F;
        stCmdFrame.acAttributeVal[0] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[4]; 
        stCmdFrame.acAttributeVal[1] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[5]; 
        stCmdFrame.acAttributeVal[2] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[6]; 
        stCmdFrame.acAttributeVal[3] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[7]; 
        stCmdFrame.cDataLen = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen-4;
      
        for(uint8_t i=0; i>sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen; i++){
            stCmdFrame.acAttributeVal[i] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[i+4];
        }
#if  (LBUS_DEVICE_TYPE == LBUS_DT1_ENABLE)
        LBus_func_DT1_task(&stCmdFrame);
#endif
        break;

      case E_EMERG_EVENT_FRAME:
        lds_debug_printf("E_EMERG_EVENT_FRAME\n");
        stCmdFrame.cTotalNum = (uint8_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID>>4) & 0x07;
        stCmdFrame.cPresentNum = (uint8_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID>>1) & 0x07;
        stCmdFrame.usObjectID = ((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].uiExtID&0x00000001)<<9) | 
                              (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[0]))<<1) | 
                              (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]))>>7);
        stCmdFrame.cObjectChannel = (sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]&0x7C)>>2;
        stCmdFrame.usAttributeID = (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[1]))<<9) | 
                                (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[2]))<<1) | 
                                (((uint16_t)(sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[3]))>>7);
        stCmdFrame.cAttributeChannel = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[3]&0x7F;
        stCmdFrame.acAttributeVal[0] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[4]; 
        stCmdFrame.acAttributeVal[1] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[5]; 
        stCmdFrame.acAttributeVal[2] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[6]; 
        stCmdFrame.acAttributeVal[3] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[7]; 
        stCmdFrame.cDataLen = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen-4;
      
        for(uint8_t i=0; i<sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].cLen; i++){
            stCmdFrame.acAttributeVal[i] = sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cCurrentNum].acBuf[i+4];
        }
      
#if  (LBUS_DEVICE_TYPE == LBUS_DT1_ENABLE)
        LBus_func_DT1_task(&stCmdFrame);
#endif
        break;

      default:
        break;
    }

    /*更新发送缓存当前指针*/
    sastLBusRxBuf.cCurrentNum++;
    if(RX_BUF_MAX_SIZE <= sastLBusRxBuf.cCurrentNum){
      sastLBusRxBuf.cCurrentNum = 0;
    }
    
  }
}

/*中断接收*/
eState_t LBus_func_rec(void){
  eState_t eState;
  stLBusRec_t stLBusRec;
  eState = hal_can0_getExtData(&stLBusRec);
  sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cFinalNum].uiExtID = stLBusRec.uiExtID;
  sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cFinalNum].cLen = stLBusRec.cLen;
	//printf("hhl");
	
    lds_debug_printf("CAN接收中断! \r\n");
  for(uint8_t i=0; i<stLBusRec.cLen; i++){
    sastLBusRxBuf.stCanExtFrame[sastLBusRxBuf.cFinalNum].acBuf[i] = stLBusRec.acBuf[i];
  }
  sastLBusRxBuf.cFinalNum++;
  if(RX_BUF_MAX_SIZE <= sastLBusRxBuf.cFinalNum){
    sastLBusRxBuf.cFinalNum = 0;
  }
  return eState;
}


/**
  * @brief  组包
  *
  * @param[in]  cSourceID         : 源地址（当前分控器的ID）
  * @param[in]  cDestID           : 目标地址(分控器只会发送给主机，因此目标地址只能为0)
  * @param[in]  cFuncCode         : 功能码（分控器只用到以下功能码：0x21/0x22/0x23）
  * @param[in]  cTotalNum         : 总包数（分控器不会发送多包）
  * @param[in]  cPresentNum       : 分包数（分控器不会发送多包）
  * @param[in]  usObjectID        : 对象ID
  * @param[in]  cObjectChannel    : 对象通道
  * @param[in]  usAttributeID     : 属性ID
  * @param[in]  cAttributeChannel : 属性通道
  * @param[in]  *uiAttributeVal   : 属性值数组
  * @param[in]  cDataLen          : 属性值数组有效长度（取值范围1~4）
  *
  * @retval eState_t
  */
eState_t LBus_func_encode(uint8_t cSourceID,
                          uint8_t cDestID,
                          uint8_t cFuncCode,
                          uint8_t cTotalNum,
                          uint8_t cPresentNum,
                          uint16_t usObjectID,
                          uint8_t cObjectChannel,
                          uint16_t usAttributeID,
                          uint8_t cAttributeChannel,
                          uint8_t *pacAttributeVal,
                          uint8_t cDataLen){
                          
  /*发送消息为紧急事件*/
  if(REPORT_TO_MASTER_EMERG == cFuncCode){
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].uiExtID = (((uint32_t)cSourceID)<<22) |
                                                                              (((uint32_t)cDestID)<<15) |
                                                                              (((uint32_t)cFuncCode)<<7) |
                                                                              (((uint32_t)cTotalNum)<<4) |
                                                                              (((uint32_t)cPresentNum)<<1) |
                                                                              (((uint32_t)usObjectID)>>9);
    
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[0] = (uint8_t)(usObjectID>>1);
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[1] = (((uint8_t)usObjectID)<<7) |
                                                                                (cObjectChannel<<2) |
                                                                                (uint8_t)(usAttributeID>>9);
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[2] = (uint8_t)(usAttributeID>>1);
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[3] = (uint8_t)(usAttributeID<<7) |
                                                                                (cAttributeChannel>>1);
    if(2 == cDataLen){
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[5] = pacAttributeVal[1];
    }
    else if(3 == cDataLen){
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[5] = pacAttributeVal[1];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[6] = pacAttributeVal[2];
    }
    else if(4 == cDataLen){
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[5] = pacAttributeVal[1];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[6] = pacAttributeVal[2];
      sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].acBuf[7] = pacAttributeVal[3];
    }
    else{
      return E_HAL_ERROR;
    }
    sastLBusTxBufEmerg.cFinalNum++;
    if(TX_BUF_MAX_SIZE <= sastLBusTxBufEmerg.cFinalNum){
      sastLBusTxBufEmerg.cFinalNum = 0;
    }
    sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cFinalNum].cLen = cDataLen+4;
  }
  /*发送消息为常规事件或回复主机*/
  else{
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].uiExtID = (((uint32_t)cSourceID)<<22) |
                                                                    (((uint32_t)cDestID)<<15) |
                                                                    (((uint32_t)cFuncCode)<<7) |
                                                                    (((uint32_t)cTotalNum)<<4) |
                                                                    (((uint32_t)cPresentNum)<<1) |
                                                                    (((uint32_t)usObjectID)>>9);
    
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[0] = (uint8_t)(usObjectID>>1);
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[1] = (((uint8_t)usObjectID)<<7) |
                                                                    (cObjectChannel<<2) |
                                                                    (uint8_t)(usAttributeID>>9);
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[2] = (uint8_t)(usAttributeID>>1);
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[3] = (uint8_t)(usAttributeID<<7) |
                                                                    (cAttributeChannel>>1);
    if(1 == cDataLen){
      if(REPLY_TO_MASTER == cFuncCode){
        sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[4] = pacAttributeVal[0];
      }
      else{
        return E_HAL_ERROR;
      }
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[4] = pacAttributeVal[0];
    }
    else if(2 == cDataLen){
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[5] = pacAttributeVal[1];
    }
    else if(3 == cDataLen){
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[5] = pacAttributeVal[1];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[6] = pacAttributeVal[2];
    }
    else if(4 == cDataLen){
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[4] = pacAttributeVal[0];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[5] = pacAttributeVal[1];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[6] = pacAttributeVal[2];
      sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].acBuf[7] = pacAttributeVal[3];
    }
    else{
      return E_HAL_ERROR;
    }
    sastLBusTxBuf.cFinalNum++;
    if(TX_BUF_MAX_SIZE <= sastLBusTxBufEmerg.cFinalNum){
      sastLBusTxBufEmerg.cFinalNum = 0;
    }
    sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cFinalNum].cLen = cDataLen+4;
  }
  return E_HAL_OK;
}

eState_t LBus_func_send(void){
  /*优先发送紧急事件*/
  eState_t eState;
  if(sastLBusTxBufEmerg.cCurrentNum != sastLBusTxBufEmerg.cFinalNum){
    eState = hal_can0_sendExtData(sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cCurrentNum].uiExtID, 
                                sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cCurrentNum].acBuf, 
                                sastLBusTxBufEmerg.astCanExtFrame[sastLBusTxBufEmerg.cCurrentNum].cLen);
    sastLBusTxBufEmerg.cCurrentNum++;
    if(TX_BUF_MAX_SIZE <= sastLBusTxBufEmerg.cCurrentNum){
      sastLBusTxBufEmerg.cCurrentNum = 0;
    }
  }
  else{
    if(sastLBusTxBuf.cCurrentNum != sastLBusTxBuf.cFinalNum){
      eState = hal_can0_sendExtData(sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cCurrentNum].uiExtID, 
                                  sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cCurrentNum].acBuf, 
                                  sastLBusTxBuf.astCanExtFrame[sastLBusTxBuf.cCurrentNum].cLen);
      sastLBusTxBuf.cCurrentNum++;
      if(TX_BUF_MAX_SIZE <= sastLBusTxBuf.cCurrentNum){
        sastLBusTxBuf.cCurrentNum = 0;
      }
    }
  }
  return eState;
}

