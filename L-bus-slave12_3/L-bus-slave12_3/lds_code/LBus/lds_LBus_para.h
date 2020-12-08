/*
 * lds_LBus_para.h
 *
 *  Created on: 2020��11��18��
 *      Author: zhangtao2
 */
#ifndef __LDS_LBUS_PARA_H__
#define __LDS_LBUS_PARA_H__

#include "lds_config.h"

/********************   �������Խṹ�嶨��         ********************/

typedef union{
  uint16_t ausArray[5] ;
  struct{
    uint16_t usEnable;         //0��Ч��1ʹ��
    uint16_t usMotionVal;      //0x0000����/0x0001����/0xffΪ��ѯ״̬����������ѯ��
    uint16_t usSensitivity;    //0x0001Ϊ��������/0x0002Ϊ��������/0x0003Ϊ��������
    uint16_t usVacantTime;     //0x0000~0xffff����λS
    uint16_t usReportTime;     //0x0000~0xffff����λS
  }stElement;
}unMotionSensor_t;

typedef union{
  uint16_t ausArray[6] ;
  struct{
    uint16_t usEnable;          //0��Ч��1ʹ��
    uint16_t usLightVal;        //0x0000~0xffff /0xffΪ��ѯ״̬����������ѯ��
    uint16_t usThresholdLow;    //0x0000~0xffff
    uint16_t usThresholdHigh;   //0x0000~0xffff
    uint16_t usSamplingTime;    //0x0000~0xffff����λS
    uint16_t usReportTime;      //0x0000~0xffff����λS
  }stElement;
}unLightSensor_t;


/********************   ȫ�ֱ�������         ********************/

#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
extern unMotionSensor_t gunMotionSensor;
extern unLightSensor_t gunLightSensor;
#endif


#endif
