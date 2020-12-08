/*
 * lds_LBus_func.h
 *
 *  Created on: 2020年11月19日
 *      Author: zhangtao2
 */
#ifndef __LDS_LBUS_FUNC_H__
#define __LDS_LBUS_FUNC_H__

#include <stdint.h>
#include <stdbool.h>
#include "lds_config.h"

#define RX_BUF_MAX_SIZE 100
#define TX_BUF_MAX_SIZE 100

/*功能码*/
#define REPLY_TO_MASTER           0x21
#define REPORT_TO_MASTER          0x22
#define REPORT_TO_MASTER_EMERG    0x23


/**/
#define MASTER_ID           0
#define SUBDEVICE_ID        1//仅用于调试

/*CAN扩展帧*/
typedef struct{
  uint32_t uiExtID;         //扩展帧ID
  uint8_t acBuf[8];         //CAN数据帧的数据段
  uint8_t cLen;             //数据段有效长度
}stCanExtFrame_t;

/*发送缓存*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  stCanExtFrame_t astCanExtFrame[TX_BUF_MAX_SIZE];
}stLBusTxBuf_t;

/*接收缓存*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  stCanExtFrame_t stCanExtFrame[TX_BUF_MAX_SIZE];
}stLBusRxBuf_t;

/*功能码枚举*/
typedef enum{
  E_SN_FRAME               = 0x01,
  E_UPDATE_FRAME           = 0x02,
  E_ID_FRAME               = 0x03,
  E_CMD_FRAME              = 0x21,
  E_EVENT_FRAME            = 0x22,
  E_EMERG_EVENT_FRAME      = 0x23
}eFuncCode_t;

/*SN配置*/
typedef struct{
    uint8_t cFuncType;
    uint8_t cSNSegmentNum;
    uint8_t cSNVal;
}stSNFrame_t;

/*升级固件*/
typedef struct{
    bool bFlag;
    uint8_t cType;
    uint32_t uiVersionl;
    uint16_t usDeviceType;
    uint16_t usPackageAmount;
    uint8_t acDataBuf[8];
    uint16_t usCRC;
}stUpadteFrame_t;

/*识别码操作*/
typedef struct{
    uint32_t uiIdentifyNum;
    uint8_t cRegister;
    uint32_t uiVal;
}stIDFrame_t;

/*主控器下发指令*/
typedef struct{
    uint8_t cTotalNum;          //总包数
    uint8_t cPresentNum;        //当前包序号
    uint16_t usObjectID;        //对象ID
    uint8_t cObjectChannel;     //对象通道
    uint16_t usAttributeID;     //属性ID
    uint8_t cAttributeChannel;  //属性通道
    uint8_t acAttributeVal[4];   //属性值数组
    uint8_t cDataLen;           //属性值数组有效长度
}stCmdFrame_t;

/*分控器上报事件*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
}stEventFrame_t;

/*解包*/
typedef struct{
  uint8_t cSourceID;
  uint8_t cDestID;
  uint8_t cFuncCode;
  stSNFrame_t stSNFrame;
  stUpadteFrame_t stUpadteFrame;
  stIDFrame_t stIDFrame;
  stCmdFrame_t stCmdFrame;
  stEventFrame_t stEventFrame;
}stLBusDecode_t;

/*组包*/
typedef struct{
  uint8_t cSourceID;
  uint8_t cDestID;
  uint8_t cFuncCode;
  uint8_t cTotalNum;
  uint8_t cPresentNum;
  uint16_t usObjectID;
  uint8_t cObjectChannel;
  uint16_t usAttributeID;
  uint8_t cAttributeChannel;
  uint32_t uiAttributeVal;
}stLBusEncode_t;


void LBus_func_decode(void);
eState_t LBus_func_rec(void);
eState_t LBus_func_encode(uint8_t cSourceID,
                          uint8_t cDestID,
                          uint8_t cFuncCode,
                          uint8_t cTotalNum,
                          uint8_t cPresentNum,
                          uint16_t usObjectID,
                          uint8_t cObjectChannel,
                          uint16_t usAttributeID,
                          uint8_t cAttributeChannel,
                          uint8_t *pcAttributeVal,
                          uint8_t cDataLen);
eState_t LBus_func_send(void);



#endif
