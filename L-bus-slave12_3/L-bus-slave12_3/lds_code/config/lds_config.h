/*
 * lds_config.h
 *  Created on: Nov 13, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#ifndef __LDS_CONFING_H
#define __LDS_CONFING_H

#ifdef __cplusplus
 extern "C" {
#endif

#include <stddef.h>
#include "stdio.h"
#include "string.h"
#include "stm32f0xx_hal.h"
#include "lds_LBus_attributeID.h"
#include "lds_LBus_objectID.h"
#include "lds_hal_debugPrintf.h"
 //ѡ�����ĳ���
#define FIRMWARE_COMPILER_MODE  2//1��boot�� 2��app1,3��APP2��

 //�ڲ�flash�涨
#define FLASH_BASE_LBUS                           FLASH_BASE
#define FLASH_END_LBUS                            FLASH_BANK1_END
#define FLASH_SYSTEM_DATA_ADDR                    0x08013800UL//0x08006000UL//�����ļ��ȷŹ̼���������BOOT����ʱ��Ҫ����
#define FLASH_SYSTEM_DATA_SECTOR_SIZE			  0x800
#define FLASH_DEVICE_PRO_ADDR                     0x08014000UL//0x08006800UL
#define FLASH_DEVICE_PRO_SECTOR_SIZE			  0x800
#define FLASH_APP_FIRMWARE_ADDR                   0x08007000UL
#define FLASH_APP_FIRMWARE_SECTOR_SIZE	          0xC800
#define FLASH_APP_FIRMWARE_UPDATA_ADDR            0x08013800UL
#define FLASH_APP_FIRMWARE_UPDATA_SECTOR_SIZE	  0xC800
#define FLASH_APP_FIRMWARE_PAGE_NUM               25 //FLASH_APP_FIRMWARE_UPDATA_SECTOR_SIZE/ FLASH_PAGE_SIZE
#define FLASH_APP_PAGE_SIZE                       0x800


 /*
 DT1�����ƶ����������նȴ���������һ
 DT2����IO�������ģ��
 DT3����4·0-10V���������
 DT4����6�����
 DT5����8·16A�̵���������
 DT6����6·9A�ɿع���������
 */


#define LBUS_DT1_TYPE   0x001
#define LBUS_DT2_TYPE   0x002
#define LBUS_DT3_TYPE   0x003
#define LBUS_DT4_TYPE   0x004
#define LBUS_DT5_TYPE   0x005
#define LBUS_DT6_TYPE   0x006


/*��ͬ�Ĳ�Ʒ�ͺŴ�ֵ��������ѡ��*/
#define LBUS_DEVICE_TYPE     LBUS_DT4_TYPE

 /****/
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
 //�̼���
  #define FW_VERSION_NO           0   //Ԥ��
  #define FW_VERSION_MAGOR        1   //0~9
  #define FW_VERSION_MINOR        0   //0~99
  #define FW_VERSION_LAST         0   //0~99
 //Ӳ���汾��
  #define HW_VERSION_NO           0   //Ԥ��
  #define HW_VERSION_MAGOR        1   //0~9
  #define HW_VERSION_MINOR        0   //0~99
  #define HW_VERSION_LAST         0   //0~99


/****/
#elif (LBUS_DEVICE_TYPE == LBUS_DT2_TYPE)


 /****/
#elif (LBUS_DEVICE_TYPE == LBUS_DT3_TYPE)

 /****/
#elif (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)
 /****/

 //�̼���
  #define FW_VERSION_NO           0   //Ԥ��
  #define FW_VERSION_MAGOR        1   //0~9
  #define FW_VERSION_MINOR        0   //0~99
  #define FW_VERSION_LAST         0   //0~99
 //Ӳ���汾��
  #define HW_VERSION_NO           0   //Ԥ��
  #define HW_VERSION_MAGOR        1   //0~9
  #define HW_VERSION_MINOR        0   //0~99
  #define HW_VERSION_LAST         0   //0~99
#elif (LBUS_DEVICE_TYPE == LBUS_DT5_TYPE)

 /****/
#elif (LBUS_DEVICE_TYPE == LBUS_DT6_TYPE)

#else

#endif

#define FW_VERSION                   ((FW_VERSION_NO << 24U)\
                                        |(FW_VERSION_MAGOR << 16U)\
                                        |(FW_VERSION_MINOR << 8U )\
                                        |(FW_VERSION_LAST))

#define HW_VERSION                   ((FW_VERSION_NO << 24U)\
                                        |(FW_VERSION_MAGOR << 16U)\
                                        |(FW_VERSION_MINOR << 8U )\
                                        |(FW_VERSION_LAST))

 typedef enum{
   LBUS_FACT_CONFIG_REG_SN        = 0x01,
   LBUS_FACT_CONFIG_REG_MODEL     = 0x02,

 }eLBusFactConfigReg_t;

//���ܿ�
//#define LDS_HAL_IWDG_ENABLED
#define LDS_HAL_FLASH_ENABLED
//#define LDS_HAL_PWM_ENABLED
//#define LDS_HAL_ADC_ENABLED
//�����ܺͷ��͵��ֽڴ�С
#define RX_BUF_MAX_SIZE              100
#define TX_BUF_MAX_SIZE              100
#define FRAME_MAX_SIZE               8
#define SN_MAX_SIZE                  15
#define SN_SEGMENT_MAX_SIZE          7
#define MODE_ID_MAX_SIZE             30
#define MODE_ID_SEGMENT_MAX_SIZE     7

 /*����״̬*/
 typedef enum{
   E_HAL_OK       = 0x00U,
   E_HAL_ERROR    = 0x01U,
   E_HAL_BUSY     = 0x02U,
   E_HAL_TIMEOUT  = 0x03U
 }eState_t;


 typedef enum{
   LBUS_OCCUPY_1BIT     = 0x0001,
   LBUS_OCCUPY_2BIT     = 0x0003,
   LBUS_OCCUPY_3BIT     = 0x0007,
   LBUS_OCCUPY_4BIT     = 0x000F,
   LBUS_OCCUPY_5BIT     = 0x001F,
   LBUS_OCCUPY_6BIT     = 0x003F,
   LBUS_OCCUPY_7BIT     = 0x007F,
   LBUS_OCCUPY_8BIT     = 0x00FF,
   LBUS_OCCUPY_9BIT     = 0x01FF,
   LBUS_OCCUPY_10BIT    = 0x03FF,
   LBUS_OCCUPY_11BIT    = 0x07FF,
   LBUS_OCCUPY_12BIT    = 0x0FFF,
   LBUS_OCCUPY_13BIT    = 0x1FFF,
   LBUS_OCCUPY_14BIT    = 0x3FFF,
   LBUS_OCCUPY_15BIT    = 0x7FFF,
   LBUS_OCCUPY_16BIT    = 0xFFFF,
 }eLBusOccupy_t;

 typedef enum{
   ID_OPERATION_REGISTER  = 0x01,
 }eidOperationRegister_t;


 typedef enum{
   APP_TRANSFER_FLAG_SWITCH_NO     = 0x00,//涓嶅垏鎹�?
   APP_TRANSFER_FLAG_SWITCH_YES    = 0x01,//鍒囨�?
   APP_TRANSFER_FLAG_SWITCH_TEMP   = 0xFE,//涓存�?
   APP_TRANSFER_FLAG_SWITCH_NO1     = 0xFF,//榛樿涓嶅垏鎹�
 }eAppTransferFlagSwith_t;

#define  LBUS_QUERY    0xFF//鏌ヨ�?
#define  LBUS_ERR      0x00 //


#pragma pack(1)

 //�����޸Ĳ����������ļ�
typedef struct
{
    uint8_t ucAppTransferFlag;    //�̼�����־λ��0x00Ϊ�����ˣ�0x01Ϊ��Ҫ���ˣ�0xffΪ�����ˣ�
    uint8_t ucCurrentTransferPage; //��ǰ���˵�ҳ��
    uint8_t ucAppCrc16Flag; //bit1����APP1�̼��洢�ռ��У��λ��bit2����APP2�̼��洢�ռ䣻1��ʾ��У�飬0ΪδУ�����У��û����屼綅锛沚it2浠ｈ〃APP2鍥轰欢�?�樺偍绌洪棿锛�1琛ㄧず宸叉牎楠岋�?涓烘湭鏍￠獙鎴栬�呮牎楠屾病杩�
    uint16_t uiApp1Crc16;     //APP1�̼��洢�ռ�ĳ���CRC16У��ֵ
    uint32_t uiApp1Size;      //APP1�̼��洢�ռ�ĳ����С
    uint32_t uiApp1Ver;       //APP1�̼��洢�ռ�ĳ���汾��
    uint16_t uiApp2Crc16;
    uint32_t uiApp2Size;
    uint32_t uiApp2Ver;
    uint8_t ucSN[SN_MAX_SIZE];     //SN�ŵ�����
    uint8_t ucSNSetState;  //SN�ŵ�����״̬
    uint8_t ucDeviceModeID[MODE_ID_MAX_SIZE];
    uint8_t ucBootToTempAppNum;      //Boot���ж���������ʱ����ucAppRunArea==0xF1��||��ucAppRunArea==0xF2��ʱ+1������2�Σ�����汾�Զ����ˡ���0xF1��UiApp2Crc16���̼�APP2�洢�ĳ���CRC16һ�¾ͻ��˵�0x02������ͣ����Boot
    uint16_t uiSystemInfoCrcFlag;       //���ñ��Crc16У��ֵ
} ST_SYSTEM_INFO;

//���Ķ������ñ�
typedef struct
{
    uint8_t ucNetState;                       //����״̬
    uint8_t ucCanId;                          //CANͨѶ��ַ
#if LBUS_DT1_ENABLE == 1

#elif LBUS_DT2_ENABLE == 1

#elif LBUS_DT2_ENABLE == 1

#elif LBUS_DT3_ENABLE == 1

#elif LBUS_DT4_ENABLE == 1

#elif LBUS_DT5_ENABLE == 1

#elif LBUS_DT6_ENABLE == 1

#endif
    uint16_t uiDevicePraCrcFlag;        //�������ñ�Ĳ���У��
}ST_DEVICE_PRA;

#pragma pack()

#if 0
/*CAN��չ֡*/
typedef struct{
  uint32_t uiIDE;	//CAN����֡��չ��ʽ��ID��
  uint8_t acDataBuf[8];	//CAN����֡�����ݶ�
}tCANExtendFrame_t;

/*���ͻ���*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  tCANExtendFrame_t atCANExtendFrame[TX_BUF_MAX_SIZE];
}tLBusTxBuf_t;

/*���ջ���*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  tCANFrame_t atCANFrame[TX_BUF_MAX_SIZE];
}tLBusRxBuf_t;

/*������ö��*/
typedef enum{
  E_SN_FRAME = 0x01,
  E_UPDATE_FRAME = 0x02,
  E_ID_FRAME = 0x03,
  E_CMD_FRAME = 0x21,
  E_EVENT_FRAME = 0x22
}eFuncCode_t;


/*SN����*/
typedef struct{
    uint8_t ucOperateType;
    uint8_t ucSNSegmentNum;
    uint8_t ucSNVal[SN_MAX_SIZE];
  }tSNFrame_t;

  /*�����̼�*/
typedef struct{
    bool bFlag;
    uint8_t cType;
    uint32_t uiVersionl;
    uint16_t usDeviceType;
    uint16_t usPackageAmount;
    uint8_t acDataBuf[8];
    uint16_t usCRC;
  }tUpadteFrame_t;

  /*ʶ�������*/
typedef struct{
    uint32_t uiIdentifyNum;
    uint8_t cRegister;
    uint32_t uiVal;
  }tIDFrame_t;

#endif
  /*�������·�ָ��*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
  }tCmdFrame_t;

  /*�ֿ����ϱ��¼�*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
  }tEventFrame_t;

  /*���*/
  /*
typedef struct{
  uint8_t cSourceID;
  uint8_t cDestID;
  uint8_t cFuncCode;
  tSNFrame_t tSNFrame;
  tUpadteFrame_t tUpadteFrame;
  tIDFrame_t tIDFrame;
  tCmdFrame_t tCmdFrame;
  tEventFrame_t tEventFrame;
}tLBusDecode_t;
*/
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
}tLBusEncode_t;


#ifdef __cplusplus
}
#endif

#endif /* __LDS_CONFING_H */

