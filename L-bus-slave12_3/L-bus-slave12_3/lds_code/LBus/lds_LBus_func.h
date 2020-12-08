/*
 * lds_LBus_func.h
 *
 *  Created on: 2020��11��19��
 *      Author: zhangtao2
 */
#ifndef __LDS_LBUS_FUNC_H__
#define __LDS_LBUS_FUNC_H__

#include <stdint.h>
#include <stdbool.h>
#include "lds_config.h"

#define RX_BUF_MAX_SIZE 100
#define TX_BUF_MAX_SIZE 100

/*������*/
#define REPLY_TO_MASTER           0x21
#define REPORT_TO_MASTER          0x22
#define REPORT_TO_MASTER_EMERG    0x23


/**/
#define MASTER_ID           0
#define SUBDEVICE_ID        1//�����ڵ���

/*CAN��չ֡*/
typedef struct{
  uint32_t uiExtID;         //��չ֡ID
  uint8_t acBuf[8];         //CAN����֡�����ݶ�
  uint8_t cLen;             //���ݶ���Ч����
}stCanExtFrame_t;

/*���ͻ���*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  stCanExtFrame_t astCanExtFrame[TX_BUF_MAX_SIZE];
}stLBusTxBuf_t;

/*���ջ���*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  stCanExtFrame_t stCanExtFrame[TX_BUF_MAX_SIZE];
}stLBusRxBuf_t;

/*������ö��*/
typedef enum{
  E_SN_FRAME               = 0x01,
  E_UPDATE_FRAME           = 0x02,
  E_ID_FRAME               = 0x03,
  E_CMD_FRAME              = 0x21,
  E_EVENT_FRAME            = 0x22,
  E_EMERG_EVENT_FRAME      = 0x23
}eFuncCode_t;

/*SN����*/
typedef struct{
    uint8_t cFuncType;
    uint8_t cSNSegmentNum;
    uint8_t cSNVal;
}stSNFrame_t;

/*�����̼�*/
typedef struct{
    bool bFlag;
    uint8_t cType;
    uint32_t uiVersionl;
    uint16_t usDeviceType;
    uint16_t usPackageAmount;
    uint8_t acDataBuf[8];
    uint16_t usCRC;
}stUpadteFrame_t;

/*ʶ�������*/
typedef struct{
    uint32_t uiIdentifyNum;
    uint8_t cRegister;
    uint32_t uiVal;
}stIDFrame_t;

/*�������·�ָ��*/
typedef struct{
    uint8_t cTotalNum;          //�ܰ���
    uint8_t cPresentNum;        //��ǰ�����
    uint16_t usObjectID;        //����ID
    uint8_t cObjectChannel;     //����ͨ��
    uint16_t usAttributeID;     //����ID
    uint8_t cAttributeChannel;  //����ͨ��
    uint8_t acAttributeVal[4];   //����ֵ����
    uint8_t cDataLen;           //����ֵ������Ч����
}stCmdFrame_t;

/*�ֿ����ϱ��¼�*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
}stEventFrame_t;

/*���*/
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

/*���*/
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
