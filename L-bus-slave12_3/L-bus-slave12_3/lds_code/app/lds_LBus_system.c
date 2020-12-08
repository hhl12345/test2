/*
 * lds_lbus_system.c
 *
 *  Created on: Nov 18, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#include "lds_LBus_system.h"
ST_SYSTEM_INFO stSystemInfo;
ST_SYSTEM_INFO *gpstSystemInfo = &stSystemInfo;
ST_DEVICE_PRA stDevicePra;
ST_DEVICE_PRA *gpstDevicePra = &stDevicePra;
void systemInfo_factory(void)
{
	gpstSystemInfo->ucAppTransferFlag = 0;    //固件区标志位＿x00为不搬运＿x01为需要搬运，0xff为不搬运＿
	gpstSystemInfo->ucCurrentTransferPage = 0; //当前搬运的页叿
	gpstSystemInfo->ucAppCrc16Flag = 0; //bit1代表APP1固件存储空间的校验位；bit2代表APP2固件存储空间＿表示已校验，0为未校验或者校验没迿
	gpstSystemInfo->uiApp1Crc16 = 0;     //APP1固件存储空间的程序CRC16校验倿
	gpstSystemInfo->uiApp1Size = 0;       //APP1固件存储空间的程序大尿
	gpstSystemInfo->uiApp1Ver = 0;        //APP1固件存储空间的程序版本号
	gpstSystemInfo->uiApp2Crc16 = 0;
	gpstSystemInfo->uiApp2Size = 0;
	gpstSystemInfo->uiApp2Ver = 0;
	//gpstSystemInfo->ucSN[SN_MAX_SIZE];           //SN号的设置
	memset(gpstSystemInfo->ucSN,0,SN_MAX_SIZE);
	gpstSystemInfo->ucSNSetState = 0;   //SN号的设置状怿
	gpstSystemInfo->ucBootToTempAppNum = 0;      //Boot中判断重新启动时＿
	gpstSystemInfo->uiSystemInfoCrcFlag = 0;        //配置表的Crc16校验倿
}
/*
 * ????1stSystemInfo
 * */
void readFlash_systemInfo_fun(void)
{
	memcpy(gpstSystemInfo,(__IO uint8_t*)(FLASH_SYSTEM_DATA_ADDR),sizeof(ST_SYSTEM_INFO));
}
/*
 * д???1
 * */
void writeFlash_systemInfo_fun(void)
{
	hal_flash_erasePage(FLASH_SYSTEM_DATA_ADDR,1);
	hal_flash_write(FLASH_SYSTEM_DATA_ADDR,gpstSystemInfo,FLASH_SYSTEM_DATA_SECTOR_SIZE);
}


void devicePra_factory(void)
{
	gpstDevicePra->ucNetState = 0;                       //网络状态：入网、离罿
	gpstDevicePra->ucCanId = 127;                            //CAN总线ID
	gpstDevicePra->uiDevicePraCrcFlag = 0;        //配置表的Crc16校验倿
	writeFlash_devicePro_fun();
}
/*
 * ????2
 * */
void readFlash_devicePra_fun(void)
{
	memcpy(gpstDevicePra,(__IO uint8_t*)(FLASH_DEVICE_PRO_ADDR),sizeof(ST_DEVICE_PRA));
}
/*
 * д???2
 * */
void writeFlash_devicePro_fun(void)
{
	hal_flash_erasePage(FLASH_DEVICE_PRO_ADDR,1);
	hal_flash_write(FLASH_DEVICE_PRO_ADDR,gpstDevicePra,FLASH_DEVICE_PRO_SECTOR_SIZE);
}
