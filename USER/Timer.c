#define _TIMER_C_

//#include "M051.h"
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "M051Series.h"
#include "M051.h"
#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvTIMER.h"
#include "DrvUART.h"
#include "global.h"
#include "timer.h"
#include "adc.h"
#include "uart.h"
	
//char Data_port=1;
//char Reset_Onewire();
//uint16_t PowerOnTimer;
//uint16_t PowerOffTimer;
//uint8_t i,Total,C_L,C_H,V_L;

//void RS485Send(uint8_t *BufferPtr, uint32_t Length);
//extern volatile uint8_t    UART0_RecvFlag,UART0_SendFlag;
							  							  
		
void delay(uint32_t uSec0268)
{
  do
  {
  }
  while(--uSec0268);
}

void Init_Timer0(void)
{
	DrvTIMER_Init();
	DrvSYS_SelectIPClockSource(E_SYS_TMR0_CLKSRC,7);   //选择内部时钟为22M
	DrvTIMER_Open(E_TMR0,20,E_PERIODIC_MODE);		//配置为0.05s触发一次中断
	DrvTIMER_SetTimerEvent(E_TMR0,2,(TIMER_CALLBACK)Time_Callback0,0);
	DrvTIMER_EnableInt(E_TMR0); 
	DrvTIMER_Start(E_TMR0); 
	
}
/*每100ms进一次中断函数*/
void Time_Callback0 (void)
{						
//	Flag_BL_Update=1;
//	DrvTIMER0_ReInit();
}

void Init_Timer2(void)
{
	DrvTIMER_Init();
	DrvSYS_SelectIPClockSource(E_SYS_TMR2_CLKSRC,7);   //选择内部时钟为22M
	DrvTIMER_Open(E_TMR2,10,E_PERIODIC_MODE);		//配置为每秒10次触发
	DrvTIMER_SetTimerEvent(E_TMR2,5,(TIMER_CALLBACK)Time_Callback2,0);//每5次触发进入一次中断
	
	DrvTIMER_EnableInt(E_TMR2);
	DrvTIMER_Start(E_TMR2);
}
// 1000/10*5=500ms 进入一次中断
void Time_Callback2(void)
{
//	uint8_t a;
//	double b=34.123;
//	a=b;
//	printf("%d\r\n",a);

//	DrvTIMER2_ReInit();
	ADC_Flag = 1;
//	ADC_HANDLE();
	if(Led_Test_FLASHING==1)
	{
		if(DrvGPIO_GetBit(LED_TEST)==0)Led_Test_ON();			  //Andy test
		else Led_Test_OFF();									  //Andy test
	}
	printf("Who am I:%x\r\n",readonebyte(Address_I2C_P13HDX412BD,0x01));
//	ADDR_485 = 0XF0|(~DrvGPIO_GetBit(Address0_485)&0x01)|(~DrvGPIO_GetBit(Address1_485)<<1&0x02);
//	printf("ADDR_485=0X%X\r\n",ADDR_485);

//	printf("TFT_CUR:    %d\r\n",TFT_CURR_AVERAGE);
//	printf("PHOTO_RES:  %d\r\n",SENSOR_AVERAGE);
//	printf("BACK_TEMP:  %d\r\n",BACK_TEMP_AVERAGE);
//	printf("IN_VOLTAGE: %d\r\n",IN_VOLTAGE_AVERAGE);
//	printf("BL_CUR:     %d\r\n",BL_CURR_AVERAGE);
//	printf("SYS_TEMP:   %d\r\n",SYS_TEMP_AVERAGE);
//	printf("\r\n");

//	DrvUART_Write(UART_PORT1,"UART1\r\n",7);
//	DrvUART_Write(UART_PORT0,"UART0\r\n",7);
//	UART0_SEND("UART0\r\n",7);
//	printf("%x\r\n",GetADC(TFT_CURR_CHANNEL));
//	printf("%d\r\n",GetADC(SENSOR_CHANNEL));
//	printf("%d\r\n",GetADC(BACK_TEMP_CHANNEL));
//	printf("%x\r\n",GetADC(IN_VOLTAGE_CHANNEL));
//	printf("%x\r\n",GetADC(BL_CURR_CHANNEL));
//	printf("%x\r\n",GetADC(SYS_TEMP_CHANNEL));
//	printf("\r\n");

//	printf("%d\r\n",BACK_TEMP_VALUE);
	
}

void Time_Callback3(void)
{
		printf("Andy20160906\r\n");
}






