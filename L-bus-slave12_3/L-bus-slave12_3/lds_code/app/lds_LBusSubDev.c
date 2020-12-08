#include "lds_hal_gpio.h"
#include "lds_hal_timer.h"
#include "lds_hal_can.h"
#include "lds_hal_i2c.h"
#include "lds_hal_uart.h"
#include "lds_buttonApp.h"
#include "lds_ledApp.h"
#include "lds_timerApp.h"
#include "lds_lightSensor.h"
#include "lds_motionSensor.h"
#include "lds_LBus_func.h"
#include "lds_app.h"
#include "lds_config.h"
#include "lds_buttonApp.h"
#include "lds_hal_debugPrintf.h"



/****************** ~{3uJ<;/~} ******************/
void LBusSubDev_init(void){
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
  hal_gpio_init();
  hal_can_init();
  hal_i2c_init();
  hal_uart_init();
  hal_timer_init();
  ledApp_init();
  buttonApp_register(app_rstButton);
  lightSensor_initConfig();
#elif (LBUS_DEVICE_TYPE == LBUS_DT2_TYPE)

#elif (LBUS_DEVICE_TYPE == LBUS_DT3_TYPE)

#elif (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)

  hal_uart_init();
  hal_can_init();


  hal_timer_init();
  hal_gpio_init();
  ledApp_init();
  buttonApp_register(app_rstButton);
  printf("jjj");
    lds_debug_printf("CAN³õÊ¼»¯!\r\n");
#elif (LBUS_DEVICE_TYPE == LBUS_DT5_TYPE)

#elif (LBUS_DEVICE_TYPE == LBUS_DT6_TYPE)

#endif
}


/****************** ~{BVQ/3LPr~} ******************/
void LBusSubDev_task(void){
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
  LBus_func_decode();
  LBus_func_send();
  motionSensor_task();
  lightSensor_task();
  timerApp_task();
  ledApp_task();
#elif (LBUS_DEVICE_TYPE == LBUS_DT2_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT3_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)
  LBus_func_decode();
  LBus_func_send();

  timerApp_task();

  ledApp_task();
#elif (LBUS_DEVICE_TYPE == LBUS_DT5_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT6_TYPE)

#endif
}


/****************** ~{VP6O~} ******************/
#if (LBUS_DEVICE_TYPE == LBUS_DT1_TYPE)
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
  LBus_func_rec();
}

void HAL_I2C_MemRxCpltCallback(I2C_HandleTypeDef *hi2c){
  lightSensor_getVal();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  timerApp_ticks();
  ledApp_ticks();
  buttonApp_ticks();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
  motionSensor_getPirPulse();
}
#elif (LBUS_DEVICE_TYPE == LBUS_DT2_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT3_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT4_TYPE)
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan){
  LBus_func_rec();
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  timerApp_ticks();
  ledApp_ticks();
  buttonApp_ticks();
}

#elif (LBUS_DEVICE_TYPE == LBUS_DT5_TYPE)
  
#elif (LBUS_DEVICE_TYPE == LBUS_DT6_TYPE)

#endif


