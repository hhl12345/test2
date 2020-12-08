/*
 * lds_LBus_para.h
 *
 *  Created on: 2020年11月18日
 *      Author: zhangtao2
 */
#ifndef __LDS_LBUS_PARA_H__
#define __LDS_LBUS_PARA_H__

#include "lds_config.h"

/********************   对象属性结构体定义         ********************/

typedef union{
  uint16_t ausArray[5] ;
  struct{
    uint16_t usEnable;         //0无效、1使能
    uint16_t usMotionVal;      //0x0000无人/0x0001有人/0xff为查询状态（主控器查询）
    uint16_t usSensitivity;    //0x0001为低灵敏度/0x0002为中灵敏度/0x0003为高灵敏度
    uint16_t usVacantTime;     //0x0000~0xffff，单位S
    uint16_t usReportTime;     //0x0000~0xffff，单位S
  }stElement;
}unMotionSensor_t;

typedef union{
  uint16_t ausArray[6] ;
  struct{
    uint16_t usEnable;          //0无效、1使能
    uint16_t usLightVal;        //0x0000~0xffff /0xff为查询状态（主控器查询）
    uint16_t usThresholdLow;    //0x0000~0xffff
    uint16_t usThresholdHigh;   //0x0000~0xffff
    uint16_t usSamplingTime;    //0x0000~0xffff，单位S
    uint16_t usReportTime;      //0x0000~0xffff，单位S
  }stElement;
}unLightSensor_t;


/********************   全局变量声明         ********************/

#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
extern unMotionSensor_t gunMotionSensor;
extern unLightSensor_t gunLightSensor;
#endif


#endif
