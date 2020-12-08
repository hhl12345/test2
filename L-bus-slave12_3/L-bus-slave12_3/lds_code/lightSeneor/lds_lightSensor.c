#include "lds_lightSensor.h"
#include "lds_timerApp.h"
#include "lds_hal_i2c.h"


static stLightPara_t sstLightPara;


void lightSensor_initConfig(void){
  uint8_t caBuf[2];

  caBuf[0] = (uint8_t)(SENSOR_INIT_CONFIG_VAL>>8);
  caBuf[1] = (uint8_t)SENSOR_INIT_CONFIG_VAL;
  hal_i2c0_masterWrite(LIGHT_SENSOR_ADDR, SENSOR_CMDCODE_CONFIG, caBuf, 2);

  timerApp_register(lightSensor_readLightVal, READ_LIGHT_SENSOR_TMR, TIMEOUT_1S, TIMERAPP_INFINITE_LOOP);
}

void lightSensor_getVal(void){
  //lds_debug_printf("light sensor 照度值为:  %#X  %#X \r\n",sstLightPara.cDataBuf[0], sstLightPara.cDataBuf[1]);
  sstLightPara.bFlag = true;
}


void lightSensor_readLightVal(void){
  hal_i2c0_masterRead(LIGHT_SENSOR_ADDR, SENSOR_CMDCODE_LIGHTVAL, sstLightPara.cDataBuf, 2);
}

void lightSensor_task(void){
  uint16_t usLightVal;

  if(true == sstLightPara.bFlag){
    sstLightPara.bFlag = false;
    usLightVal = (((uint16_t)sstLightPara.cDataBuf[0])<<8) | ((uint16_t)sstLightPara.cDataBuf[1]);
    lds_debug_printf("light sensor 照度值为: %d \r\n",usLightVal);
  }
}



