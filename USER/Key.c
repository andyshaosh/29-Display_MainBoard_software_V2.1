#include <stdio.h>
#include <stdint.h>
#include "M051Series.h"
#include "M051.h"
#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvUART.h"
#include "Register_Bit.h"
#include "Uart.h"
#include "Macro_SystemClock.h"
#include "global.h"

uint8_t  Key1,Key2;
uint32_t Key1_Cnt,Key2_Cnt;
uint8_t  Flag_Key=0;
uint8_t  Flag_Key_Handle=0;
uint8_t  Key_Status;
uint8_t  Key1_Enable=1;
uint8_t  Key2_Enable=1;
uint8_t  KeyScan_Enable=1;
uint8_t  KeyScan_Enable2=1;
void	Dimmer_Increase();
void	Dimmer_Decrease();

uint32_t LongpressKey1_Cnt=20000;
uint32_t LongpressKey2_Cnt=20000;
uint32_t LongpressKey1_Cnt_Threshold=10000;
uint32_t LongpressKey2_Cnt_Threshold=10000;
/* ------------- Function read Keyboard ---------------- */
void Get_KeyValue()
{
	Key1=DrvGPIO_GetBit(E_PORT3, E_PIN2);
	Key2=DrvGPIO_GetBit(E_PORT3, E_PIN3);
	if((Key1==1)&&(Key2==1))
	{
		KeyScan_Enable=1;
		Key1_Enable=1;
		Key2_Enable=1;	
	}
	if(KeyScan_Enable==1)
	{
		if(((Key2==0)||(Key1==0))&&(Key1_Cnt<LongpressKey1_Cnt)&&(Key2_Cnt<LongpressKey2_Cnt))
		{
			Flag_Key=1;
	
			if((Key1==0)&&(Key1_Cnt<LongpressKey1_Cnt))
				Key1_Cnt++;
			if((Key2==0)&&(Key2_Cnt<LongpressKey2_Cnt))
				Key2_Cnt++;
			
		    if((Key1_Cnt>=200)&&Key1_Enable)
			{
				Key1_Enable=0;
				
				Slave.BL_Mode=0;
				if(Slave.BL_Mode==0)
				Dimmer_Increase();
//				if(PowerON_Flag==1)
//				{
//				BL_EN=1;
//				Backlight_EN();
//				}
			SetKeyEvent(ShortPress_Plus);	
			}
			if((Key2_Cnt>=200)&&Key2_Enable)
			{
				Key2_Enable=0;
			
				Slave.BL_Mode=0;
				if(Slave.BL_Mode==0)
				Dimmer_Decrease();
//				if(PowerON_Flag==1)
//				{
//				BL_EN=1;
//				Backlight_EN();
//				}
			SetKeyEvent(ShortPress_Minus);	
			}
			
	
	
				
		}
		else
		{
			
			if(Flag_Key==1)
			{
				Flag_Key=0;
				Flag_Key_Handle=1;
			}
		}
	}
	

}
void Key_Handle()
{
	int break_cnt=0;
	if(Flag_Key_Handle==1)
	{	
		KeyScan_Enable=0;
		Key_Status=0;

//		if((Key1_Cnt>=200)&&(Key1_Cnt<20000)&&(Key2_Cnt<200))
//		{
//			Key_Status=1;
//		}
//		if((Key2_Cnt>=200)&&(Key2_Cnt<20000)&&(Key1_Cnt<200))
//		{
//			Key_Status=2;
//		}
		if((Key1_Cnt==LongpressKey1_Cnt)&&(Key2_Cnt<LongpressKey2_Cnt_Threshold))
		{
			Key_Status=3;
		}
		if((Key2_Cnt==LongpressKey2_Cnt)&&(Key1_Cnt<LongpressKey1_Cnt_Threshold))
		{
			Key_Status=4;
		}
		if(((Key1_Cnt==LongpressKey1_Cnt)&&(Key2_Cnt>=LongpressKey2_Cnt_Threshold))||((Key1_Cnt>=LongpressKey1_Cnt_Threshold)&&(Key2_Cnt==LongpressKey2_Cnt)))
		{
			Key_Status=5;
		}
		switch(Key_Status)
		{
			case 1:
//			Slave.BL_Mode=0;
//			if(Slave.BL_Mode==0)
//			Dimmer_Increase();
//			if(PowerON_Flag==1)
//			{
//			BL_EN=1;
//			Backlight_EN();
//			}
			break;
			case 2:
//			Slave.BL_Mode=0;
//			if(Slave.BL_Mode==0)
//			Dimmer_Decrease();
//			if(PowerON_Flag==1)
//			{
//			BL_EN=1;
//			Backlight_EN();
//			}
			break;
			case 3:
//				BL_EN=1;
//				Backlight_EN();
//				if(Slave.BL_Mode==1)
//				{
//				Auto_Adj_Bright();
//				}
//				else
//				{
//					if(Flag_LED==1)
//					PWMA->CMR1=1500+Slave.KeyLED_Step*7000;
//					else
//					PWMA->CMR1=0;
//				}
			SetKeyEvent(longPress_Plus);
			break;
			case 4:
//				BL_EN=0;
//				Backlight_EN();
//				if(Slave.BL_Mode==1)
//				{
//				Auto_Adj_Bright();
//				}
//				else
//				{
//					if(Flag_LED==1)
//					PWMA->CMR1=1500+Slave.KeyLED_Step*7000;
//					else
//					PWMA->CMR1=0;
//				}
			SetKeyEvent(longPress_Minus);
			break;
			case 5:
				if(Slave.BL_Mode==0)
			{
				Slave.BL_Mode=1;
			}
			else
				Slave.BL_Mode=0;
			
			break;
			
			default:
			break;
		}
		save_data();
		Key1_Cnt=0;
		Key2_Cnt=0;
		Flag_Key_Handle=0;
		
//		while((Key1==0)||(Key2==0))
//		{
//		break_cnt++;
//		if(break_cnt>1000000)
//		break;
//		Key1=DrvGPIO_GetBit(E_PORT3, E_PIN2);
//		Key2=DrvGPIO_GetBit(E_PORT3, E_PIN3);
//		}
	}
}

void Dimmer_Increase()
{

	if(Flag_LED==1)	;;
//	Slave.KeyLED_Step=Slave.BL_Step;	
}

void Dimmer_Decrease()
{

}