#ifndef __LDS_MOTIONSENSOR_H__
#define __LDS_MOTIONSENSOR_H__  

#include <stdint.h>
#include <stdbool.h>
/*
typedef struct{
  bool bFlag; 

}stMotionPara_t;
*/

void motionSensor_task(void);
void motionSensor_getPirPulse(void);

#endif
