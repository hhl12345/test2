/*
 * lds_app.c
 *
 *  Created on: 2020Äê11ÔÂ19ÈÕ
 *      Author: zhangtao2
 */
#if 0
#include <lds_hal_debugPrintf.h>
#include "lds_app.h"
#include "lds_hal_can.h"
#include "lds_LBus_func.h"

///
void app_rstButton(uint8_t cButtonNum, eButtonState_t eButtonState){
  uint8_t caArry[2];

  if(RST_BUTTON == cButtonNum){
    if(E_BUTTON_PRESS == eButtonState){
    //  lds_debug_printf("press! \r\n");
     printf("jvdkfdfnjdfngbjdfnmvgblfd");
      caArry[0] = 0x00;
      caArry[1] = 0x01;
    /*
      caArry[2] = 0x22;
      caArry[3] = 0x33;
      caArry[4] = 0x44;
      caArry[5] = 0x55;
      caArry[6] = 0x66;
      caArry[7] = 0x77;
      
      hal_can0_sendExtData(0x1FFFFFFF, caArry, 8);
      */
      LBus_func_encode(SUBDEVICE_ID,
                      MASTER_ID,
                      REPLY_TO_MASTER,
                      0,
                      0,
                      107,
                      0,
                      2,
                      0,
                      caArry,
                      2);
    }
    else{
      lds_debug_printf("release! \r\n");
    }
  }
}
#endif
