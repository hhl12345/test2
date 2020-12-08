/*
 * lds_LBus_para.c
 *
 *  Created on: 2020Äê11ÔÂ21ÈÕ
 *      Author: zhangtao2
 */
#include "lds_LBus_para.h"


#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)

unMotionSensor_t gunMotionSensor;
unLightSensor_t gunLightSensor;

void LBus_para_init(){
  gunMotionSensor.stElement.usEnable = 1;
  gunMotionSensor.stElement.usMotionVal = 0;
  gunMotionSensor.stElement.usSensitivity = 3;
  gunMotionSensor.stElement.usVacantTime = 0;
  gunMotionSensor.stElement.usReportTime = 0;

  gunLightSensor.stElement.usEnable = 1;
  gunLightSensor.stElement.usLightVal = 0;
  gunLightSensor.stElement.usThresholdLow = 0;
  gunLightSensor.stElement.usThresholdHigh = 0xFFFF;
  gunLightSensor.stElement.usSamplingTime = 0;
  gunLightSensor.stElement.usSamplingTime = 0;
}

#endif

