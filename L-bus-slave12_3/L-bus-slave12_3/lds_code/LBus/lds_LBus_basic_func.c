/*
 * lds_LBus_func.c
 *
 *  Created on: Nov 17, 2020
 *      Author: ganxiaosheng
 *  Version     :v1.0.0
 *  Modification:Create file
 *  @par     Copyright
 *  Copyright (c) Leedarson IoT 2000-2020. All rights reserved.
 */
#include "lds_LBus_basic_func.h"
#include "lds_LBus_system.h"
#include "lds_hal_can.h"
#include "lds_lbus_system.h"
#define FRAME_DATA_MAX_SIZE     12  //4+8

/*
 * 出厂设备SN配置操作
 * SN号是15字节，分两包操作
 *IDE:0~3,Data:4~12factory configuration
 **/
eState_t LBus_basic_SN_func(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen)
{
	uint8_t i;
	//uint32_t ExtId=0;
	uint8_t ucSourceID;
	uint8_t ucDestID;
	uint8_t ucSN_CMD;
    uint8_t ucOperateType; //操作类型
    uint8_t ucSegmentNum;//SN号段�?
    static uint8_t ucfeedbackData[FRAME_MAX_SIZE];
    uint8_t ucfeedbackLen;
    uint32_t uiucfeedbackExtID;

	if(ucLen < 2)
	{
		return E_HAL_ERROR;
	}
    for(i=0;i<ucLen;i++)
    {
    	if((pcDataBuf+i) == NULL)
    	{
    		return E_HAL_ERROR;
    	}
    }

    ucSourceID = (uint8_t)(uiExtID>>22)&LBUS_OCCUPY_7BIT;
	ucDestID = (uint8_t)(uiExtID>>15)&LBUS_OCCUPY_7BIT;
	ucSN_CMD = (uint8_t)(uiExtID>>7)&LBUS_OCCUPY_8BIT;
    ucOperateType = (uint8_t)(uiExtID>>4)&LBUS_OCCUPY_3BIT;
    ucSegmentNum = (uint8_t)uiExtID & LBUS_OCCUPY_4BIT;
    lds_debug_printf("ucSourceID:%x\n",ucSourceID);
    lds_debug_printf("ucDestID:%x\n",ucDestID);
    lds_debug_printf("ucSN_CMD:%x\n",ucSN_CMD);
    lds_debug_printf("ucOperateType:%x\n",ucOperateType);
    lds_debug_printf("ucSegmentNum:%x\n",ucSegmentNum);
    memset(ucfeedbackData,0,SN_MAX_SIZE);
//    ucfeedbackData[0] = (ucDestID>>2);
//    ucfeedbackData[1] = (ucDestID<<6)|(ucSourceID>>1);
//    ucfeedbackData[2] = (ucSourceID<<7)|(ucSN_CMD>>1);
//    ucfeedbackData[3] = (ucSN_CMD<<7)|(ucOperateType<<4) | ucSNSegmentNum;
    uiucfeedbackExtID = ucDestID;
    uiucfeedbackExtID = (uiucfeedbackExtID<<7)|(ucSourceID&LBUS_OCCUPY_7BIT);
    uiucfeedbackExtID = (uiucfeedbackExtID<<8)|(ucSN_CMD);
    uiucfeedbackExtID = (uiucfeedbackExtID<<3)|(ucOperateType&LBUS_OCCUPY_3BIT);
    uiucfeedbackExtID = (uiucfeedbackExtID<<4)|(ucSegmentNum&LBUS_OCCUPY_4BIT);
    if(ucSegmentNum>(SN_MAX_SIZE-1)/SN_SEGMENT_MAX_SIZE+1)//SN最�?�?
    {
        return E_HAL_ERROR;
    }    
    if(ucOperateType == 0x01) //����
    {
        
        if((ucSegmentNum < (SN_MAX_SIZE-1)/SN_SEGMENT_MAX_SIZE+1))
        {
            memcpy(gpstSystemInfo->ucSN+SN_SEGMENT_MAX_SIZE*(ucSegmentNum-1),pcDataBuf+1,SN_SEGMENT_MAX_SIZE);
            memcpy(ucfeedbackData,pcDataBuf,8);
        }else {
        	memcpy(gpstSystemInfo->ucSN+SN_SEGMENT_MAX_SIZE*(ucSegmentNum-1),pcDataBuf+1,ucLen-1);
        	memcpy(ucfeedbackData,pcDataBuf,ucLen);
        }
        ucfeedbackLen = ucLen ;
        
    }else if(ucOperateType == 0x02){//����
        ucfeedbackData[0] = pcDataBuf[0];
  
        if((ucSegmentNum == 1)||(ucSegmentNum == 2))
        {
            memcpy(ucfeedbackData+1,gpstSystemInfo->ucSN+SN_SEGMENT_MAX_SIZE*(ucSegmentNum-1),SN_SEGMENT_MAX_SIZE);
            ucfeedbackLen = 8 ;
        }else {
        	memcpy(ucfeedbackData+1,gpstSystemInfo->ucSN+SN_SEGMENT_MAX_SIZE*(ucSegmentNum-1),SN_MAX_SIZE%SN_SEGMENT_MAX_SIZE);
        	ucfeedbackLen = SN_MAX_SIZE%SN_SEGMENT_MAX_SIZE + 1 ;
        }
    	
    }else if(ucOperateType = 0x03){//���殤
    	writeFlash_systemInfo_fun();//д��flash
    	lds_debug_printf("systemInfo save ok\n");
    	memcpy(ucfeedbackData,pcDataBuf,ucLen);
    	ucfeedbackLen = ucLen ;
    }else{
        return E_HAL_ERROR;
    }
    hal_can0_sendExtData(uiucfeedbackExtID,ucfeedbackData,ucfeedbackLen);
    /*for(i=0;i<FRAME_MAX_SIZE;i++)
    {
        lds_debug_printf("data[%d]:%x\n",i,ucfeedbackData[i]);
    }*/
}
/*
 * 出厂设备model ID配置操作
 * SN号是15字节，分两包操作
 *IDE:0~3,Data:4~12factory configuration
 **/
eState_t LBus_basic_modelIDFunc(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen)
{
	uint8_t i;
	//uint32_t ExtId=0;
	uint8_t ucSourceID;
	uint8_t ucDestID;
	uint8_t ucSN_CMD;
    uint8_t ucOperateType; //操作类型
    uint8_t ucSegmentNum;//SN号段�?
    uint8_t ucfeedbackData[FRAME_MAX_SIZE],ucfeedbackLen;
    uint32_t uiucfeedbackExtID;

	if(ucLen < 2)
	{
		return E_HAL_ERROR;
	}
    for(i=0;i<ucLen;i++)
    {
    	if((pcDataBuf+i) == NULL)
    	{
    		return E_HAL_ERROR;
    	}
    }

    ucSourceID = (uint8_t)(uiExtID>>22)&LBUS_OCCUPY_7BIT;
	ucDestID = (uint8_t)(uiExtID>>15)&LBUS_OCCUPY_7BIT;
	ucSN_CMD = (uint8_t)(uiExtID>>7)&LBUS_OCCUPY_8BIT;
    ucOperateType = (uint8_t)(uiExtID>>4)&LBUS_OCCUPY_3BIT;
    ucSegmentNum = (uint8_t)uiExtID & LBUS_OCCUPY_4BIT;
//    printf("ucSourceID:%x\n",ucSourceID);
//    printf("ucDestID:%x\n",ucDestID);
//    printf("ucSN_CMD:%x\n",ucSN_CMD);
//    printf("ucOperateType:%x\n",ucOperateType);
//    printf("ucSNSegmentNum:%x\n",ucSNSegmentNum);
    memset(ucfeedbackData,0,MODE_ID_MAX_SIZE);
//    ucfeedbackData[0] = (ucDestID>>2);
//    ucfeedbackData[1] = (ucDestID<<6)|(ucSourceID>>1);
//    ucfeedbackData[2] = (ucSourceID<<7)|(ucSN_CMD>>1);
//    ucfeedbackData[3] = (ucSN_CMD<<7)|(ucOperateType<<4) | ucSNSegmentNum;
    uiucfeedbackExtID = ucDestID;
    uiucfeedbackExtID = (uiucfeedbackExtID<<7)|(ucSourceID&LBUS_OCCUPY_7BIT);
    uiucfeedbackExtID = (uiucfeedbackExtID<<8)|(ucSN_CMD);
    uiucfeedbackExtID = (uiucfeedbackExtID<<3)|(ucOperateType&LBUS_OCCUPY_3BIT);
    uiucfeedbackExtID = (uiucfeedbackExtID<<4)|(ucSegmentNum&LBUS_OCCUPY_4BIT);
    if(ucSegmentNum>(MODE_ID_MAX_SIZE-1)/MODE_ID_SEGMENT_MAX_SIZE+1)//SN最�?�?
    {
        return E_HAL_ERROR;
    }    
    if(ucOperateType == 0x01) //����
    {
        
        if(ucSegmentNum< (MODE_ID_MAX_SIZE-1)/MODE_ID_SEGMENT_MAX_SIZE+1)
        {
            memcpy(gpstSystemInfo->ucDeviceModeID+MODE_ID_SEGMENT_MAX_SIZE*(ucSegmentNum-1),pcDataBuf+1,MODE_ID_SEGMENT_MAX_SIZE);
            memcpy(ucfeedbackData,pcDataBuf,8);
        }else {
        	memcpy(gpstSystemInfo->ucDeviceModeID+MODE_ID_SEGMENT_MAX_SIZE*(ucSegmentNum-1),pcDataBuf+1,ucLen-1);
        	memcpy(ucfeedbackData,pcDataBuf,ucLen);
        }
        ucfeedbackLen = ucLen ;
        
    }else if(ucOperateType == 0x02){//��ѯ
        ucfeedbackData[0] = pcDataBuf[0];
  
        if((ucSegmentNum == 1)||(ucSegmentNum == 2))
        {
            memcpy(ucfeedbackData+1,gpstSystemInfo->ucDeviceModeID+MODE_ID_SEGMENT_MAX_SIZE*(ucSegmentNum-1),MODE_ID_SEGMENT_MAX_SIZE);
            ucfeedbackLen = 8 ;
        }else {
        	memcpy(ucfeedbackData+1,gpstSystemInfo->ucDeviceModeID+MODE_ID_SEGMENT_MAX_SIZE*(ucSegmentNum-1),MODE_ID_MAX_SIZE%MODE_ID_SEGMENT_MAX_SIZE);
        	ucfeedbackLen = MODE_ID_MAX_SIZE%MODE_ID_SEGMENT_MAX_SIZE + 1 ;
        }
    	
    }else if(ucOperateType = 0x03){//����
    	writeFlash_systemInfo_fun();//���浽flash
    	memcpy(ucfeedbackData,pcDataBuf,ucLen);
    	ucfeedbackLen = ucLen ;
    }else{
        return E_HAL_ERROR;
    }
    hal_can0_sendExtData(uiucfeedbackExtID,ucfeedbackData,ucfeedbackLen);
    /*for(i=0;i<FRAME_MAX_SIZE;i++)
    {
        lds_debug_printf("data[%d]:%x\n",i,ucfeedbackData[i]);
    }*/
}


/*
 * 固件升级包处�?
 * */
eState_t LBus_basic_firewmareUpdata(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen)
{
	uint8_t i;
	//uint32_t ExtId=0;
	uint8_t ucUpdataFlag = 0;
	uint8_t ucSourceID;
	uint8_t ucDestID;
	uint8_t ucSN_CMD;
    uint8_t ucUpdataType; //操作类型
    uint8_t ucDataType;//包类�?
    uint32_t uifirewmareVer;
    uint16_t usdeviceType;
    //uint16_t usPackageAmount;
    uint8_t acDataBuf[8];
    uint16_t usCurVerify;

    uint8_t ucfeedbackData[SN_MAX_SIZE],ucfeedbackLen;
    static uint8_t UcUpdataPacketStamp=0;
    static uint32_t uiUpdataNum=0,uiUpdataAllSize=0;
    static uint16_t usAllUpdataVerify;
    static uint8_t timeOutFlag=0;
    static uint32_t tick_time;


	if(ucLen > FRAME_DATA_MAX_SIZE)
	{
		return E_HAL_ERROR;
	}
    for(i=0;i<ucLen;i++)
    {
    	if((pcDataBuf+i) == NULL)
    	{
    		return E_HAL_ERROR;
    	}
    }

    if((HAL_GetTick() > (tick_time+FIREWMARE_UPDATA_TIMEOUT))&&(ucUpdataFlag == 1))//超时
    {
    	timeOutFlag = 1;
    	ucUpdataFlag = 0;
    	uiUpdataNum = 0;
    }

    ucSourceID = (uint8_t)(uiExtID>>22)&LBUS_OCCUPY_7BIT;
	ucDestID = (uint8_t)(uiExtID>>15)&LBUS_OCCUPY_7BIT;
	ucSN_CMD = (uint8_t)(uiExtID>>7)&LBUS_OCCUPY_8BIT;
    ucUpdataType = (uint8_t)(uiExtID>>6)&LBUS_OCCUPY_1BIT; //操作类型
    ucDataType = (uint8_t)(uiExtID>>4)&LBUS_OCCUPY_2BIT;//包类�?
    if(ucUpdataType == 1)//处在或进入升级模�?
    {
        timeOutFlag = 0;
    	if(ucDataType == 1)//头部
    	{

    		uifirewmareVer = pcDataBuf[0];
    		uifirewmareVer = (uifirewmareVer<<8) | pcDataBuf[1];
    		uifirewmareVer = (uifirewmareVer<<8) | pcDataBuf[2];
    		uifirewmareVer = (uifirewmareVer<<4) | (pcDataBuf[3]>>4);
    		uifirewmareVer = ((uiExtID & 0x0000000F)<<28) |(uifirewmareVer);
    		ucDataType = pcDataBuf[3]&0x0f;//设备类型
    		ucDataType = (ucDataType << 8) |pcDataBuf[4];
    		uiUpdataAllSize = (pcDataBuf[5] << 16) | (pcDataBuf[6] << 8) | (pcDataBuf[7]);//固件包总数�?
    		if((LBUS_DEVICE_TYPE == ucDataType)&&(uifirewmareVer>FW_VERSION))
    		{
    			ucUpdataFlag = 1;
    			uiUpdataNum = 0;
    			hal_flash_erasePage(FLASH_APP_FIRMWARE_UPDATA_ADDR,FLASH_APP_FIRMWARE_PAGE_NUM); //擦除APP缓存�?
    		}
    	}else if((ucDataType == 2)&&(ucUpdataFlag == 1)){//中部
    		if((uiExtID & 0x0f) == UcUpdataPacketStamp)
    		{
    			if(UcUpdataPacketStamp>=15){
    				UcUpdataPacketStamp = 0;
    			}else{
    				UcUpdataPacketStamp ++;
    			}
    			for(i=0;i<ucLen;i++)
    			{
    				usCurVerify = usCurVerify + pcDataBuf[i];
    			}

    			hal_flash_write(FLASH_APP_FIRMWARE_UPDATA_ADDR+uiUpdataNum,pcDataBuf,ucLen);//�?
    			uiUpdataNum = uiUpdataNum + ucLen;
    		}

    	}else if((ucDataType == 3)&&(ucUpdataFlag == 1)){//尾部

    		uifirewmareVer = pcDataBuf[0];
    		uifirewmareVer = (uifirewmareVer<<8) | pcDataBuf[1];
    		uifirewmareVer = (uifirewmareVer<<8) | pcDataBuf[2];
    		uifirewmareVer = (uifirewmareVer<<4) | (pcDataBuf[3]>>4);
    		uifirewmareVer = ((uiExtID & 0x0000000F)<<28) |(uifirewmareVer);
    		ucDataType = pcDataBuf[3]&0x0f;//设备类型
    		ucDataType = (ucDataType << 8) |pcDataBuf[4];
    		usAllUpdataVerify = (pcDataBuf[5]<<8) | (pcDataBuf[6]);
    		if((LBUS_DEVICE_TYPE == ucDataType)&&(uifirewmareVer>FW_VERSION)&&(uiUpdataNum == uiUpdataAllSize)&&(usAllUpdataVerify == usCurVerify))//校验成功，固件可�?
    		{
    			gpstSystemInfo->ucAppTransferFlag == APP_TRANSFER_FLAG_SWITCH_TEMP;//临时版本
				gpstSystemInfo->uiApp2Crc16 = usAllUpdataVerify;
				gpstSystemInfo->uiApp2Size = uiUpdataAllSize;
				gpstSystemInfo->uiApp2Ver = uifirewmareVer;
				writeFlash_systemInfo_fun();

    		}else{//校验失败，退出升�?

    	    	timeOutFlag = 1;
    	    	ucUpdataFlag = 0;
    		}
    	}else{
    		return E_HAL_ERROR;
    	}
    	tick_time = HAL_GetTick();


    }else{
    	timeOutFlag = 1;
    	ucUpdataFlag = 0;
    }

}

/****** ID配置  ******/
eState_t LBus_basic_CAN_ID_func(uint32_t uiExtID, uint8_t *pcDataBuf, uint8_t ucLen)
{
	uint8_t i;
	uint8_t ucSourceID;
	uint8_t ucDestID;
	uint8_t ucSN_CMD;
	uint8_t ucregister;
	uint32_t uiIdentification;//识别�?
    uint8_t ucfeedbackData[FRAME_MAX_SIZE],ucfeedbackLen;
    uint32_t uiucfeedbackExtID;
	if(ucLen > FRAME_DATA_MAX_SIZE)
	{
		return E_HAL_ERROR;
	}
    for(i=0;i<ucLen;i++)
    {
    	if((pcDataBuf+i) == NULL)
    	{
    		return E_HAL_ERROR;
    	}
    }
    memset(ucfeedbackData,0,SN_MAX_SIZE);
    ucSourceID = (uint8_t)(uiExtID>>22)&LBUS_OCCUPY_7BIT;
	ucDestID = (uint8_t)(uiExtID>>15)&LBUS_OCCUPY_7BIT;
	ucSN_CMD = (uint8_t)(uiExtID>>7)&LBUS_OCCUPY_8BIT;
    uiIdentification = uiExtID&0x7F;
    uiIdentification = uiIdentification<<8 | pcDataBuf[0];
    uiIdentification = uiIdentification<<8 | pcDataBuf[1];
    uiIdentification = uiIdentification<<8 | pcDataBuf[2];
    uiIdentification = uiIdentification<<1 | (pcDataBuf[3]&0x01);
    ucregister = pcDataBuf[3] & 0x7f;

    uiucfeedbackExtID = ucDestID;
    uiucfeedbackExtID = (uiucfeedbackExtID<<7)|(ucSourceID&LBUS_OCCUPY_7BIT);
    uiucfeedbackExtID = (uiucfeedbackExtID<<8)|(ucSN_CMD);
    uiucfeedbackExtID = (uiucfeedbackExtID<<7)|(uiExtID&0x0000007F);
    if(ucregister == ID_OPERATION_REGISTER)
    {
		ucfeedbackData[0] = pcDataBuf[0];
		ucfeedbackData[1] = pcDataBuf[1];
		ucfeedbackData[2] = pcDataBuf[2];
		ucfeedbackData[3] = pcDataBuf[3];
        if((ucLen==5)&&(pcDataBuf[4]==LBUS_QUERY)) //��ѯ
        {
            ucfeedbackData[4] = 0;
            ucfeedbackData[5] = gpstDevicePra->ucCanId;
            ucfeedbackLen = 6;
        }else if(ucLen == 6){
        	gpstDevicePra->ucCanId = pcDataBuf[5];
    		ucfeedbackData[4] = pcDataBuf[4];
    		ucfeedbackData[5] = pcDataBuf[5];
    		ucfeedbackLen = 6;
            writeFlash_devicePro_fun();
            lds_debug_printf("save CANID OK:%d\n",gpstDevicePra->ucCanId);
        }else{
        	ucfeedbackData[4] = LBUS_ERR;
        	ucfeedbackLen = 5;
        }
        hal_can0_sendExtData(uiucfeedbackExtID,ucfeedbackData,ucfeedbackLen);
    }

}

/****** 重启 ******/
void LBus_basic_device_reset_func(void)
{
	NVIC_SystemReset();
}
/****** 固件版本查询  ******/
uint32_t LBus_basic_get_firmware_ver_func(void)
{
	return FW_VERSION;
}
/****** 硬件版本查询  ******/
uint32_t LBus_basic_get_hardware_ver_func(void)
{
	return HW_VERSION;
}

/****** ModeID操作  ******/
uint16_t modeID_operate_func(uint16_t value)
{
	
}

/****** 手自动模式操�? ******/
uint16_t hand_Auto_operate_func(uint16_t value)
{
	
	
}
/****** 搜索网络、上报设备信�? ******/
eState_t reported_deviceInfo_func(uint8_t *FrameData,uint8_t ucLen)
{
	
	
}



