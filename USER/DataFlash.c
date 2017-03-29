#include <stdio.h>
#include <stdint.h>
#include "M051Series.h"
#include "DrvFMC.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "DrvUART.h"
#include "global.h"	
const uint8_t Version_Code=0x37 ;
extern uint8_t pwm_value, Sta_Ctrl;
#define DATAFLASH_BASE      0x0001F000		  

int FLASH_Write_Word(unsigned int Address,unsigned int Data)
{
    volatile int FLASHStatus;
    
    FLASHStatus = DrvFMC_Write(Address, Data);
    
    return FLASHStatus;
}
	
unsigned int FLASH_Read_Word(unsigned int Address)
{
	unsigned int Data;
    
	DrvFMC_Read(Address, &Data);
	
	return Data;
} 

void save_data()
{
	uint32_t Version,CRC_Sum,temp;
	Version=Version_Code;		 		 
	CRC_Sum=(Version^Slave.BL_Mode^Slave.BL_Value^Slave.Configuration^Slave.BL_MIN^Slave.BL_MAX^
			serial.inch_H^serial.inch_L^serial.year^serial.month^serial.day^serial.numH^
			serial.numL^serial.HW_V^serial.SW_V^Default.KeyLED_Step_P^Default.IGN_Delay);
	UNLOCKREG();
    DrvFMC_EnableISP();	
        DrvFMC_Erase(DATAFLASH_BASE);
		DrvFMC_Write(DATAFLASH_BASE , Version);	
		DrvFMC_Write(DATAFLASH_BASE +4, Slave.BL_Mode);
	  	DrvFMC_Write(DATAFLASH_BASE +8, Slave.BL_Value);
   		DrvFMC_Write(DATAFLASH_BASE +12, Slave.Configuration);
		DrvFMC_Write(DATAFLASH_BASE +16, Slave.BL_MIN);
		DrvFMC_Write(DATAFLASH_BASE +20, Slave.BL_MAX);

		DrvFMC_Write(DATAFLASH_BASE +24,serial.inch_H);
		DrvFMC_Write(DATAFLASH_BASE +28,serial.inch_L);
		DrvFMC_Write(DATAFLASH_BASE +32,serial.year);
		DrvFMC_Write(DATAFLASH_BASE +36,serial.month);
		DrvFMC_Write(DATAFLASH_BASE +40,serial.day);
		DrvFMC_Write(DATAFLASH_BASE +44,serial.numH);
		DrvFMC_Write(DATAFLASH_BASE +48,serial.numL);
		DrvFMC_Write(DATAFLASH_BASE +52,serial.HW_V);
		DrvFMC_Write(DATAFLASH_BASE +56,serial.SW_V);

		DrvFMC_Write(DATAFLASH_BASE +60,Default.KeyLED_Step_P);
		DrvFMC_Write(DATAFLASH_BASE +64, Default.IGN_Delay);
		DrvFMC_Write(DATAFLASH_BASE +68, CRC_Sum);
		delay(3000);
	DrvFMC_DisableISP();
	LOCKREG();
	return;
}

void Data_Init()
{
    UNLOCKREG();
    DrvFMC_EnableISP();	
        Slave.BL_Mode=FLASH_Read_Word(DATAFLASH_BASE +4);
		Slave.BL_Value=FLASH_Read_Word(DATAFLASH_BASE +8);
		Slave.Configuration=FLASH_Read_Word(DATAFLASH_BASE +12);
		Slave.BL_MIN=FLASH_Read_Word(DATAFLASH_BASE +16);
		Slave.BL_MAX=FLASH_Read_Word(DATAFLASH_BASE +20);

   		serial.inch_H=FLASH_Read_Word(DATAFLASH_BASE +24);
		serial.inch_L=FLASH_Read_Word(DATAFLASH_BASE +28);
		serial.year=FLASH_Read_Word(DATAFLASH_BASE +32);
		serial.month=FLASH_Read_Word(DATAFLASH_BASE +36);
		serial.day=FLASH_Read_Word(DATAFLASH_BASE +40);
		serial.numH=FLASH_Read_Word(DATAFLASH_BASE +44);
		serial.numL=FLASH_Read_Word(DATAFLASH_BASE +48);
		serial.HW_V=FLASH_Read_Word(DATAFLASH_BASE +52);
		serial.SW_V=FLASH_Read_Word(DATAFLASH_BASE +56);
	delay(3000);
	LOCKREG();
	DrvFMC_DisableISP();

}
void SetDefaultData()
{
       uint32_t Version,CRC_Sum;
			Slave.BL_Mode=1;		
			Slave.BL_Value=50;
			Slave.Configuration=0xff;
			Slave.BL_MIN=20;
			Slave.BL_MAX=80;

			serial.inch_H=0xA1;
			serial.inch_L=0x50;
			serial.year=0x16;
			serial.month=0x06;
			serial.day=0x01;
			serial.numH=0x00;
			serial.numL=0x00;
			serial.HW_V=0x34;
			serial.SW_V=Version_Code;

			Default.KeyLED_Step_P=0;
			Default.IGN_Delay=0;
			CRC_Sum=(Version^Slave.BL_Mode^Slave.BL_Value^Slave.Configuration^Slave.BL_MIN^Slave.BL_MAX^
					serial.inch_H^serial.inch_L^serial.year^serial.month^serial.day^serial.numH^
					serial.numL^serial.HW_V^serial.SW_V^Default.KeyLED_Step_P^Default.IGN_Delay);
			save_data();
}
 
void init_data()
{
  uint32_t Version,CRC_Sum;	 
	
	UNLOCKREG();
	DrvFMC_EnableISP();
		Version=FLASH_Read_Word(DATAFLASH_BASE);
		if(Version!=Version_Code)	//初次上電未輸入任何配置
		{
			SetDefaultData();
			save_data();			
		 }  
		 else //導出上次配置項
		 {	
			Slave.BL_Mode=FLASH_Read_Word(DATAFLASH_BASE +4);
			Slave.BL_Value=FLASH_Read_Word(DATAFLASH_BASE +8);
			Slave.Configuration=FLASH_Read_Word(DATAFLASH_BASE +12);
			Slave.BL_MIN=FLASH_Read_Word(DATAFLASH_BASE +16);
			Slave.BL_MAX=FLASH_Read_Word(DATAFLASH_BASE +20);
            
			serial.inch_H=FLASH_Read_Word(DATAFLASH_BASE +24);
			serial.inch_L=FLASH_Read_Word(DATAFLASH_BASE +28);
			serial.year=FLASH_Read_Word(DATAFLASH_BASE +32);
			serial.month=FLASH_Read_Word(DATAFLASH_BASE +36);
			serial.day=FLASH_Read_Word(DATAFLASH_BASE +40);
			serial.numH=FLASH_Read_Word(DATAFLASH_BASE +44);
			serial.numL=FLASH_Read_Word(DATAFLASH_BASE +48);
			serial.HW_V=FLASH_Read_Word(DATAFLASH_BASE +52);
			serial.SW_V=FLASH_Read_Word(DATAFLASH_BASE +56);

			Default.KeyLED_Step_P=FLASH_Read_Word(DATAFLASH_BASE +60);
			Default.IGN_Delay=FLASH_Read_Word(DATAFLASH_BASE +64);
			CRC_Sum=FLASH_Read_Word(DATAFLASH_BASE +68);

			delay(3000);

			if(CRC_Sum!=(Version^Slave.BL_Mode^Slave.BL_Value^Slave.Configuration^Slave.BL_MIN^Slave.BL_MAX^
						serial.inch_H^serial.inch_L^	serial.year^serial.month^serial.day^serial.numH^
						serial.numL^serial.HW_V^serial.SW_V^Default.KeyLED_Step_P^Default.IGN_Delay	))
			{
			 SetDefaultData();
			 save_data();
			}
	 }
	DrvFMC_DisableISP();
	LOCKREG();
	Data_Init();

	return;
}