/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2009 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------*/
/* Include related header files                                                                            */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include "M051Series.h"
#include "M051.h"
#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvUART.h"
#include "DrvTIMER.h"
#include "Register_Bit.h"
#include "Uart.h"
#include "Macro_SystemClock.h"
#include "global.h"
#include "adc.h"
//#include "IIC.H"
#define WDT_ENABLE 1

#define TIME_HZ     1 
/*时间段一*/

#define LCD_TIME    8
#define BL_ADJ_TIME 2
/*时间段二*/
#define TOUCH_TIME  2
#define USB_TIME    2 

extern uint8_t pwm_value,
               Sta_Ctrl,
			   DIS_LINK_EN,
			   AT_DET_EN;
volatile uint8_t  UART0_RecvFlag=0;
volatile uint8_t  UART1_RecvFlag=0;
volatile uint8_t  UART0_SendFlag=0;
volatile uint8_t  UART1_SendFlag=0; 
volatile uint8_t  Status_Update=0;

 int num4=0,num7=0;

uint8_t  UART_STOH_Buffer[30];
uint8_t  Led_Test_FLASHING = 1;
uint16_t  WDT_FeedFlag=1,
          uTicks=0,
		  uTicks_Touch=0;
Struct_param Slave;
Dimmer_Step  Dimmer_Slave;
void Time_Callback();
#if(WDT_ENABLE)
void WDT_CallBack()
{
 if(WDT_FeedFlag!=0)
 {
 	UNLOCKREG();
	DrvWDT_Ioctl(E_WDT_IOC_RESET_TIMER,0);
	LOCKREG();
	WDT_FeedFlag--;	
 } 
}
#endif
#if(WDT_ENABLE)
void WDT_Init()
{
	UNLOCKREG();
	DrvSYS_SetIPClock(E_SYS_WDT_CLK,1);
	DrvSYS_SelectIPClockSource(E_SYS_WDT_CLKSRC,2);	 // HCLK/2048
	DrvWDT_Open(E_WDT_LEVEL7);//2的18次方
	DrvWDT_InstallISR((WDT_CALLBACK)WDT_CallBack);
   	DrvWDT_Ioctl(E_WDT_IOC_ENABLE_INT,0);
	DrvWDT_Ioctl(E_WDT_IOC_START_TIMER,0);	
    DrvWDT_Ioctl(E_WDT_IOC_ENABLE_RESET_FUNC,0);
    LOCKREG();
}
#endif



void Init_MCU()
{
	UNLOCKREG();
	DrvSYS_SetOscCtrl(E_SYS_OSC22M,1);
    LOCKREG();

	PWM_init();
	UART_init();
	GPIO_init();
	ADC_init();
//	I2C_init();
//	Sta_Ctrl=0xFF;
//	printf("20160817\r\n");
//	Init_Timer0();
	Init_Timer2();
}

void main(void)
{
//	uint16_t temp;
    Init_MCU();
//	init_data();
//	Sta_Ctrl =Slave.Configuration;
//	bright_low=Slave.BL_MIN;
//	bright_high=Slave.BL_MAX;
//	EN_SET=Slave.BL_Mode;
//	pwm_value=Slave.BL_Value;
//
//	Status_Update=0;
//	Init_Timer0(TIME_HZ);

//	ADDR_485 = 0XF0|(~DrvGPIO_GetBit(Address0_485)&0x01)|(~DrvGPIO_GetBit(Address1_485)<<1&0x02);
	ADDR_485 = 0XF0;

//	#if(WDT_ENABLE)	
//	   WDT_Init();
//	#endif
/******************TEST AREA***************************************/	
//	AD_BRD_ON();
////	AD_BRD_OFF();
//	Video_Equalizer_POWER_ON();
//	Video_Equalizer_EN_ON();
//	TFT_12_ON();
//	TFT_12_OFF();
	Led_Test_ON();
	Led_Test_FLASHING = 1;
//	EN_BL_OFF();
	EN_BL_ON();
//	PWM(100);
	SetBL_PWM(270);
//123121312132123132																									
	EN_12V_ON();
//	EN_12V_OFF();
	EN_1V8_ON();
//	EN_1V8_OFF();
	EN_3V3_ON();
//	EN_3V3_OFF();
//
//	DrvGPIO_ClrBit(PI3HDX412BD_MS);			//MS Hight level, I2C Control Mode Selection
	DrvGPIO_SetBit(PI3HDX412BD_MS);			//MS Low level, Pin Control Mode Selection
	DrvGPIO_ClrBit(PI3HDX412BD_OE);			//OE Hight level, Output Port Enable
//	DrvGPIO_SetBit(PI3HDX412BD_OE);			//OE Low level, Turn off Rout and Rt(termination resistor). TMDS Receiver and TMDS Output Drivers are "OFF" state. 
	DrvGPIO_ClrBit(PI3HDX412BD_DR);			//DR Hight level, All ports are Active at same time
//	DrvGPIO_SetBit(PI3HDX412BD_DR);			//DR Low level, Output Ports are controlled by SEL1 (Pin#55) control
//	DrvGPIO_ClrBit(PI3HDX412BD_SEL1);		//SEL1 Hight level, Enable Output Port 2
	DrvGPIO_SetBit(PI3HDX412BD_SEL1);		//SEL1 Low level, Enable Output Port 1

	DrvGPIO_ClrBit(PI3HDX412BD_EQ2);
//	DrvGPIO_SetBit(PI3HDX412BD_EQ2);
	DrvGPIO_SetBit(PI3HDX412BD_EQ1);
//	DrvGPIO_ClrBit(PI3HDX412BD_EQ1);
/******************************************************************/
    while (1)
	{
//	#if(WDT_ENABLE)
//		WDT_FeedFlag=2;	           
//		UNLOCKREG();
//		DrvWDT_Ioctl(E_WDT_IOC_RESET_TIMER,0);
//		LOCKREG();
//	#endif

	Uart0_Handle();
	Uart1_Handle();
	if(ADC_Flag==1)
	{
		ADC_HANDLE();
	}
	  		
//	Event_Generator();
//	Event_Handler(); 
	}
}

