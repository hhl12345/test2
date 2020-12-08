/*
 * lds_lbus_system.h
 *
 *  Created on: Nov 18, 2020
 *      Author: ganxiaosheng
 */
#ifndef __LDS_LBUS_SYSTEM_H
#define __LDS_LBUS_SYSTEM_H

#ifdef __cplusplus
 extern "C" {
#endif
//------------
#include "lds_config.h"

extern ST_SYSTEM_INFO *gpstSystemInfo;
extern ST_DEVICE_PRA *gpstDevicePra;
void readFlash_systemInfo_fun(void);
void writeFlash_systemInfo_fun(void);
void DevicePra_factory(void);
void readFlash_devicePra_fun(void);
void writeFlash_devicePro_fun(void);
//------------
#ifdef __cplusplus
}
#endif

#endif /* __LDS_LBUS_SYSTEM_H */


