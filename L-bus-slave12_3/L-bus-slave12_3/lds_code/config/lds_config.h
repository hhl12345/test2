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
 //选择编译的程序
#define FIRMWARE_COMPILER_MODE  2//1是boot， 2是app1,3是APP2；

 //内部flash规定
#define FLASH_BASE_LBUS                           FLASH_BASE
#define FLASH_END_LBUS                            FLASH_BANK1_END
#define FLASH_SYSTEM_DATA_ADDR                    0x08013800UL//0x08006000UL//配置文件先放固件缓冲器，BOOT测试时需要换回
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
 DT1——移动传感器和照度传感器二合一
 DT2——IO输入输出模块
 DT3——4路0-10V调光控制器
 DT4——6键面板
 DT5——8路16A继电器控制器
 DT6——6路9A可控硅调光控制器
 */


#define LBUS_DT1_TYPE   0x001
#define LBUS_DT2_TYPE   0x002
#define LBUS_DT3_TYPE   0x003
#define LBUS_DT4_TYPE   0x004
#define LBUS_DT5_TYPE   0x005
#define LBUS_DT6_TYPE   0x006


/*不同的产品型号此值需在上面选择*/
#define LBUS_DEVICE_TYPE     LBUS_DT4_TYPE

 /****/
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
 //固件号
  #define FW_VERSION_NO           0   //预留
  #define FW_VERSION_MAGOR        1   //0~9
  #define FW_VERSION_MINOR        0   //0~99
  #define FW_VERSION_LAST         0   //0~99
 //硬件版本号
  #define HW_VERSION_NO           0   //预留
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

 //固件号
  #define FW_VERSION_NO           0   //预留
  #define FW_VERSION_MAGOR        1   //0~9
  #define FW_VERSION_MINOR        0   //0~99
  #define FW_VERSION_LAST         0   //0~99
 //硬件版本号
  #define HW_VERSION_NO           0   //预留
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

//功能块
//#define LDS_HAL_IWDG_ENABLED
#define LDS_HAL_FLASH_ENABLED
//#define LDS_HAL_PWM_ENABLED
//#define LDS_HAL_ADC_ENABLED
//最大接受和发送的字节大小
#define RX_BUF_MAX_SIZE              100
#define TX_BUF_MAX_SIZE              100
#define FRAME_MAX_SIZE               8
#define SN_MAX_SIZE                  15
#define SN_SEGMENT_MAX_SIZE          7
#define MODE_ID_MAX_SIZE             30
#define MODE_ID_SEGMENT_MAX_SIZE     7

 /*函数状态*/
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
   APP_TRANSFER_FLAG_SWITCH_NO     = 0x00,//娑撳秴鍨忛幑锟?
   APP_TRANSFER_FLAG_SWITCH_YES    = 0x01,//閸掑洦宕?
   APP_TRANSFER_FLAG_SWITCH_TEMP   = 0xFE,//娑撳瓨妞?
   APP_TRANSFER_FLAG_SWITCH_NO1     = 0xFF,//姒涙ǹ顓绘稉宥呭瀼閹癸拷
 }eAppTransferFlagSwith_t;

#define  LBUS_QUERY    0xFF//閺屻儴顕?
#define  LBUS_ERR      0x00 //


#pragma pack(1)

 //不常修改参数的配置文件
typedef struct
{
    uint8_t ucAppTransferFlag;    //固件区标志位：0x00为不搬运，0x01为需要搬运，0xff为不搬运；
    uint8_t ucCurrentTransferPage; //当前搬运的页号
    uint8_t ucAppCrc16Flag; //bit1代表APP1固件存储空间的校验位；bit2代表APP2固件存储空间；1表示已校验，0为未校验或者校验没过灞肩秴閿涙矚it2娴狅綀銆傾PP2閸ヨ桨娆㈢?涙ê鍋嶇粚娲？閿涳拷1鐞涖劎銇氬鍙夌墡妤犲矉绱?娑撶儤婀弽锟犵崣閹存牞锟藉懏鐗庢灞剧梾鏉╋拷
    uint16_t uiApp1Crc16;     //APP1固件存储空间的程序CRC16校验值
    uint32_t uiApp1Size;      //APP1固件存储空间的程序大小
    uint32_t uiApp1Ver;       //APP1固件存储空间的程序版本号
    uint16_t uiApp2Crc16;
    uint32_t uiApp2Size;
    uint32_t uiApp2Ver;
    uint8_t ucSN[SN_MAX_SIZE];     //SN号的设置
    uint8_t ucSNSetState;  //SN号的设置状态
    uint8_t ucDeviceModeID[MODE_ID_MAX_SIZE];
    uint8_t ucBootToTempAppNum;      //Boot中判断重新启动时，（ucAppRunArea==0xF1）||（ucAppRunArea==0xF2）时+1，超过2次，软件版本自动回退。如0xF1且UiApp2Crc16跟固件APP2存储的程序CRC16一致就回退到0x02，否则停留在Boot
    uint16_t uiSystemInfoCrcFlag;       //配置表的Crc16校验值
} ST_SYSTEM_INFO;

//常改动的配置表
typedef struct
{
    uint8_t ucNetState;                       //入网状态
    uint8_t ucCanId;                          //CAN通讯地址
#if LBUS_DT1_ENABLE == 1

#elif LBUS_DT2_ENABLE == 1

#elif LBUS_DT2_ENABLE == 1

#elif LBUS_DT3_ENABLE == 1

#elif LBUS_DT4_ENABLE == 1

#elif LBUS_DT5_ENABLE == 1

#elif LBUS_DT6_ENABLE == 1

#endif
    uint16_t uiDevicePraCrcFlag;        //参数配置表的参数校验
}ST_DEVICE_PRA;

#pragma pack()

#if 0
/*CAN扩展帧*/
typedef struct{
  uint32_t uiIDE;	//CAN数据帧扩展格式的ID段
  uint8_t acDataBuf[8];	//CAN数据帧的数据段
}tCANExtendFrame_t;

/*发送缓存*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  tCANExtendFrame_t atCANExtendFrame[TX_BUF_MAX_SIZE];
}tLBusTxBuf_t;

/*接收缓存*/
typedef struct{
  uint8_t cCurrentNum;
  uint8_t cFinalNum;
  tCANFrame_t atCANFrame[TX_BUF_MAX_SIZE];
}tLBusRxBuf_t;

/*功能码枚举*/
typedef enum{
  E_SN_FRAME = 0x01,
  E_UPDATE_FRAME = 0x02,
  E_ID_FRAME = 0x03,
  E_CMD_FRAME = 0x21,
  E_EVENT_FRAME = 0x22
}eFuncCode_t;


/*SN配置*/
typedef struct{
    uint8_t ucOperateType;
    uint8_t ucSNSegmentNum;
    uint8_t ucSNVal[SN_MAX_SIZE];
  }tSNFrame_t;

  /*升级固件*/
typedef struct{
    bool bFlag;
    uint8_t cType;
    uint32_t uiVersionl;
    uint16_t usDeviceType;
    uint16_t usPackageAmount;
    uint8_t acDataBuf[8];
    uint16_t usCRC;
  }tUpadteFrame_t;

  /*识别码操作*/
typedef struct{
    uint32_t uiIdentifyNum;
    uint8_t cRegister;
    uint32_t uiVal;
  }tIDFrame_t;

#endif
  /*主控器下发指令*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
  }tCmdFrame_t;

  /*分控器上报事件*/
typedef struct{
    uint8_t cTotalNum;
    uint8_t cPresentNum;
    uint16_t usObjectID;
    uint8_t cObjectChannel;
    uint16_t usAttributeID;
    uint8_t cAttributeChannel;
    uint32_t uiAttributeVal;
  }tEventFrame_t;

  /*解包*/
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
}tLBusEncode_t;


#ifdef __cplusplus
}
#endif

#endif /* __LDS_CONFING_H */

