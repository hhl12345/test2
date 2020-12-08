#include "lds_motionSensor.h"
#include "lds_ledApp.h"

static bool sbPulseFlag;

#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
void motionSensor_task(void){
  if(true == sbPulseFlag){
    sbPulseFlag = false;
    ledApp_register(LED_GREEN,
                    GREEN_LED_PRIORITY_LOWEST,
                    1000,
                    500,
                    1,
                    ledApp_null);
  }
}

void motionSensor_getPirPulse(void){
  sbPulseFlag = true;
}
#endif
