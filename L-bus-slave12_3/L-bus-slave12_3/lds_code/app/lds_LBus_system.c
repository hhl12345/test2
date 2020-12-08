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
	gpstSystemInfo->ucAppTransferFlag = 0;    //�̼�����־λ��x00Ϊ�����ˣ�x01Ϊ��Ҫ���ˣ�0xffΪ�����ˣ�
	gpstSystemInfo->ucCurrentTransferPage = 0; //��ǰ���˵�ҳ��
	gpstSystemInfo->ucAppCrc16Flag = 0; //bit1����APP1�̼��洢�ռ��У��λ��bit2����APP2�̼��洢�ռ�߱�ʾ��У�飬0ΪδУ�����У��ûޙ
	gpstSystemInfo->uiApp1Crc16 = 0;     //APP1�̼��洢�ռ�ĳ���CRC16У�邞
	gpstSystemInfo->uiApp1Size = 0;       //APP1�̼��洢�ռ�ĳ������
	gpstSystemInfo->uiApp1Ver = 0;        //APP1�̼��洢�ռ�ĳ���汾��
	gpstSystemInfo->uiApp2Crc16 = 0;
	gpstSystemInfo->uiApp2Size = 0;
	gpstSystemInfo->uiApp2Ver = 0;
	//gpstSystemInfo->ucSN[SN_MAX_SIZE];           //SN�ŵ�����
	memset(gpstSystemInfo->ucSN,0,SN_MAX_SIZE);
	gpstSystemInfo->ucSNSetState = 0;   //SN�ŵ�����״��
	gpstSystemInfo->ucBootToTempAppNum = 0;      //Boot���ж���������ʱ��
	gpstSystemInfo->uiSystemInfoCrcFlag = 0;        //���ñ��Crc16У�邞
}
/*
 * ????1stSystemInfo
 * */
void readFlash_systemInfo_fun(void)
{
	memcpy(gpstSystemInfo,(__IO uint8_t*)(FLASH_SYSTEM_DATA_ADDR),sizeof(ST_SYSTEM_INFO));
}
/*
 * ��???1
 * */
void writeFlash_systemInfo_fun(void)
{
	hal_flash_erasePage(FLASH_SYSTEM_DATA_ADDR,1);
	hal_flash_write(FLASH_SYSTEM_DATA_ADDR,gpstSystemInfo,FLASH_SYSTEM_DATA_SECTOR_SIZE);
}


void devicePra_factory(void)
{
	gpstDevicePra->ucNetState = 0;                       //����״̬�����������Z
	gpstDevicePra->ucCanId = 127;                            //CAN����ID
	gpstDevicePra->uiDevicePraCrcFlag = 0;        //���ñ��Crc16У�邞
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
 * ��???2
 * */
void writeFlash_devicePro_fun(void)
{
	hal_flash_erasePage(FLASH_DEVICE_PRO_ADDR,1);
	hal_flash_write(FLASH_DEVICE_PRO_ADDR,gpstDevicePra,FLASH_DEVICE_PRO_SECTOR_SIZE);
}
