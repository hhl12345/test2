/*
 * lds_hal_debugPrintf.h
 *  Created on: 2020年11月18日
 *      Author: zhangtao2
 */
#ifndef __LDS_HAL_H__
#define __LDS_HAL_H__  
#include <stdio.h>
//#include "lds_config.h"
/*
typedef enum{
 E_HAL_OK       = 0x00U,
 E_HAL_ERROR    = 0x01U,
 E_HAL_BUSY     = 0x02U,
 E_HAL_TIMEOUT  = 0x03U
}eState_t;
*/
/*此处设置debug开或关*/
#define  LDS_DEBU

#ifdef LDS_DEBU
/*
#define lds_debug_printf(fmt, args...) \
  do\
  {\
    printf("<<File:%s Line:%d Function:%s>> ", __FILE__, __LINE__, __FUNCTION__); 
    printf(fmt, ##args);\
  }while(0)
  */
#define lds_debug_printf(fmt, args...) \
  do\
  {\
    printf(fmt, ##args);\
  }while(0)
#else
  #define lds_debug_printf(fmt, args...)   
#endif



#endif

