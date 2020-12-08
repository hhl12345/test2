#ifndef __LDS_LIGHTSENSOR_H__
#define __LDS_LIGHTSENSOR_H__  

#include <stdint.h>
#include <stdbool.h>

#define LIGHT_SENSOR_ADDR 0x20
#define SENSOR_CMDCODE_CONFIG 0x00
#define SENSOR_INIT_CONFIG_VAL (uint16_t)0x0000
#define SENSOR_CMDCODE_LIGHTVAL 0x04


typedef struct{
  uint8_t cDataBuf[2];
  bool bFlag; 

}stLightPara_t;


void lightSensor_initConfig(void);
void lightSensor_getVal(void);
void lightSensor_readLightVal(void);
void lightSensor_task(void);


#endif

