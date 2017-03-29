#define _ADC_C_

#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "global.h"
#include "adc.h"
#include "TempCodeDef.H"
uint32_t u32AdcData;
uint32_t  Cnt_ForAD=0;
uint32_t  Cnt_ForBL=0;
uint16_t Dimmer_Auto1=0;
uint8_t  PowerInput[10];
uint8_t  Flag_PowerInput_Initial=1;
uint16_t PowerInputAver;

//uint8_t  Flag_ADC_Initial=1;

void ADC_init(void) 
{
	uint8_t i;
/************ADC_GPIO_INIT*********************/
//	DrvGPIO_Open(AD0,E_IO_INPUT);
//	DrvGPIO_Open(AD1,E_IO_INPUT);
//	DrvGPIO_Open(AD4,E_IO_INPUT);
//	DrvGPIO_Open(AD5,E_IO_INPUT);
//	DrvGPIO_Open(AD6,E_IO_INPUT);
//	DrvGPIO_Open(AD7,E_IO_INPUT);	
	DrvGPIO_InitFunction(E_FUNC_ADC0);
	DrvGPIO_InitFunction(E_FUNC_ADC1);
	DrvGPIO_InitFunction(E_FUNC_ADC4);
	DrvGPIO_InitFunction(E_FUNC_ADC5);
	DrvGPIO_InitFunction(E_FUNC_ADC6);
//	DrvGPIO_InitFunction(E_FUNC_ADC7);
/*********************************************/

/************ADC_OPEN*************************/	 																					
	DrvADC_Open(ADC_SINGLE_END, ADC_SINGLE_CYCLE_OP, 0xF3, INTERNAL_RC22MHZ, 1);// Single ended, single operation, F3=11110011b, Oscillator 22MHz, OSC/2
/*********************************************/

/************Set ADC**************************/
	VTEMPCR = 1;				 //TEMPCR:0--VTEMP_EN=1
//	outpw(0x5000001CUL, 0X00000001UL);
//	ADCHER|=0x200; 				//set AD_CH7 to temperature sensor
	ADC->ADCHER.PRESEL = 2;	//set AD_CH7 to temperature sensor
/*********************************************/

/************ADC_BUFFER_INIT******************/
	for(i=0;i<AD_BUFFER_NUM;i++)
	{
		TFT_CURR[i]=GetADC(TFT_CURR_CHANNEL);
		SENSOR[i]=GetADC(SENSOR_CHANNEL);
		BACK_TEMP[i]=GetADC(BACK_TEMP_CHANNEL);
		IN_VOLTAGE[i]=GetADC(IN_VOLTAGE_CHANNEL);
		BL_CURR[i]=GetADC(BL_CURR_CHANNEL);
		SYS_TEMP[i]=GetADC(SYS_TEMP_CHANNEL);
	}
/*********************************************/
//	printf("%x\r\n",TFT_CURR_AVERAGE);				 //Andy_test
//	printf("%x\r\n",SENSOR_AVERAGE);
//	printf("%x\r\n",BACK_TEMP_AVERAGE);
//	printf("%x\r\n",IN_VOLTAGE_AVERAGE);
//	printf("%x\r\n",BL_CURR_AVERAGE);
//	printf("%x\r\n",SYS_TEMP_AVERAGE);
}

uint32_t GetADC(uint8_t ChannelNum)
{
	DrvADC_StartConvert();
	while (DrvADC_IsConversionDone() == FALSE);
	u32AdcData= DrvADC_GetConversionData(ChannelNum);
	return u32AdcData;
}
void ADC_HANDLE(void)
{
	short int i;
	double SYS_TEMP_BUF,BACK_TEMP_BUF;
	ADC_Flag = 0;
	for(i=1;i<AD_BUFFER_NUM-1;i++)
	{
		TFT_CURR[i]   = TFT_CURR[i+1];
		SENSOR[i]     = SENSOR[i+1];
		BACK_TEMP[i]  = BACK_TEMP[i+1];
		IN_VOLTAGE[i] = IN_VOLTAGE[i+1];
		BL_CURR[i]    = BL_CURR[i+1];
		SYS_TEMP[i]   = SYS_TEMP[i+1];
	}
	TFT_CURR[AD_BUFFER_NUM-1]=GetADC(TFT_CURR_CHANNEL);
	SENSOR[AD_BUFFER_NUM-1]=GetADC(SENSOR_CHANNEL);
	BACK_TEMP[AD_BUFFER_NUM-1]=GetADC(BACK_TEMP_CHANNEL);
	IN_VOLTAGE[AD_BUFFER_NUM-1]=GetADC(IN_VOLTAGE_CHANNEL);
	BL_CURR[AD_BUFFER_NUM-1]=GetADC(BL_CURR_CHANNEL);
	SYS_TEMP[AD_BUFFER_NUM-1]=GetADC(SYS_TEMP_CHANNEL);
	for(i=1;i<AD_BUFFER_NUM;i++)
	{
		TFT_CURR_AVERAGE     += TFT_CURR[i];
		SENSOR_AVERAGE       += SENSOR[i]; 
		BACK_TEMP_AVERAGE    += BACK_TEMP[i];
		IN_VOLTAGE_AVERAGE   += IN_VOLTAGE[i];
		BL_CURR_AVERAGE      += BL_CURR[i];
		SYS_TEMP_AVERAGE     += SYS_TEMP[i];
	}
	TFT_CURR_AVERAGE     /= AD_BUFFER_NUM;
	SENSOR_AVERAGE       /= AD_BUFFER_NUM; 
	BACK_TEMP_AVERAGE    /= AD_BUFFER_NUM;
	IN_VOLTAGE_AVERAGE   /= AD_BUFFER_NUM;
	BL_CURR_AVERAGE      /= AD_BUFFER_NUM;
	SYS_TEMP_AVERAGE     /= AD_BUFFER_NUM;

	TFT_CURR_VALUE = (2.5-(double)TFT_CURR_AVERAGE*4.8/4095)*10/0.94;						  
//	SENSOR_VALUE = (SENSOR_AVERAGE-PHOTO_SENSOR_ADVALUE_MIN)*10/(PHOTO_SENSOR_ADVALUE_MAX-PHOTO_SENSOR_ADVALUE_MIN); 
	if(SENSOR_AVERAGE > PHOTO_SENSOR_ADVALUE_MAX) SENSOR_AVERAGE = PHOTO_SENSOR_ADVALUE_MAX;
	if(SENSOR_AVERAGE < PHOTO_SENSOR_ADVALUE_MIN) SENSOR_AVERAGE = PHOTO_SENSOR_ADVALUE_MIN;
	SENSOR_VALUE = (PHOTO_SENSOR_ADVALUE_MAX-SENSOR_AVERAGE)*10/(PHOTO_SENSOR_ADVALUE_MAX-PHOTO_SENSOR_ADVALUE_MIN); 
//	IN_VOLTAGE_VALUE = (double)IN_VOLTAGE_AVERAGE*4.8/4095*13;
	IN_VOLTAGE_VALUE = (double)IN_VOLTAGE_AVERAGE*4.8/4095*11+0.5;
	BL_CURR_VALUE = (2.5-(double)BL_CURR_AVERAGE*4.8/4095)*10/0.3392;						  

//	BACK_TEMP_BUF =	(0.724-(double)BACK_TEMP_AVERAGE*4.8/4095)*1000/1.85;
//	BACK_TEMP_VALUE = BACK_TEMP_BUF+40;
	BACK_TEMP_BUF = (double)BACK_TEMP_AVERAGE*10/(4095-(double)BACK_TEMP_AVERAGE);
	for(i=0;i<sizeof(Temperature_Res_Tbl)/2;i++)
	{
		if(BACK_TEMP_BUF<Temperature_Res_Tbl[i*2+1]&&BACK_TEMP_BUF>Temperature_Res_Tbl[i*2+3])
		{
			BACK_TEMP_VALUE=i;//此处所求得温度值比实际温度值高Temperature_Res_Tbl[0]
			break;
		}
	}

	SYS_TEMP_BUF =	(0.724-(double)SYS_TEMP_AVERAGE*4.8/4095)*1000/1.85;
	SYS_TEMP_VALUE = SYS_TEMP_BUF+40;
//	SYS_TEMP_BUF = (double)SYS_TEMP_AVERAGE*10/(4095-(double)SYS_TEMP_AVERAGE);
//	for(i=0;i<sizeof(Temperature_Res_Tbl)/2;i++)
//	{
//		if(SYS_TEMP_BUF<Temperature_Res_Tbl[i*2+1]&&SYS_TEMP_BUF>Temperature_Res_Tbl[i*2+3])
//		{
//			SYS_TEMP_VALUE=i;//此处所求得温度值比实际温度值高Temperature_Res_Tbl[0]
//			break;									 
//		}
//	}
}

/*
uint8_t PowerInputCheck()
{
		
		uint8_t cnt;
		PowerInputAver=0;
		if(Flag_PowerInput_Initial==1)
		{
			Flag_PowerInput_Initial=0;
			PowerInput[0]=(GetADC(1)>>4);
			PowerInput[1]=PowerInput[0];
			PowerInput[2]=PowerInput[0];
			PowerInput[3]=PowerInput[0];
			PowerInput[4]=PowerInput[0];
	//	PowerInput[5]=PowerInput[0];
	//	PowerInput[6]=PowerInput[0];
	//	PowerInput[7]=PowerInput[0];
	//	PowerInput[8]=PowerInput[0];
	//	PowerInput[9]=PowerInput[0];
		}
		else
		{
			PowerInput[0]=(GetADC(1)>>4);
			PowerInput[1]=PowerInput[0];
			PowerInput[2]=PowerInput[1];
			PowerInput[3]=PowerInput[2];
			PowerInput[4]=PowerInput[3];
		//PowerInput[5]=PowerInput[4];
		//PowerInput[6]=PowerInput[5];
		//PowerInput[7]=PowerInput[6];
		//PowerInput[8]=PowerInput[7];
		//PowerInput[9]=PowerInput[8];
		}
		for(cnt=0;cnt<5;cnt++)
		{	
			PowerInputAver+=PowerInput[cnt];								// Bright_Aver = Bright_Aver + Bright_Auto[cnt]
		}
	
		PowerInputAver=PowerInputAver/5;
		if(PowerInputAver>0xff)
			PowerInputAver=0xff;	
		return PowerInputAver;
}
*/

/*
void Auto_Adj_Bright()
{

	
	char Flag_BrightAdj_Initial2=0;

	

	int cnt;
	uint16_t Level_Data1,Level_Data2,Level_Data3;
	Level_Data1=Slave.Threshold1;
	Level_Data2=Slave.Threshold2;
	Level_Data3=Slave.Threshold3;
	
	
	
	if(Cnt_ForAD==0)
	{

	Cnt_ForAD=10*Slave.Cnt_ForAD;
		if(Flag_BrightAdj_Initial==1)
	{
	Flag_BrightAdj_Initial2=1;
	Bright_Auto[0]=(GetADC(0)>>4);
	Bright_Auto[1]=Bright_Auto[0];
	Bright_Auto[2]=Bright_Auto[0];
	Bright_Auto[3]=Bright_Auto[0];
	Bright_Auto[4]=Bright_Auto[0];
//	Bright_Auto[5]=Bright_Auto[0];
//	Bright_Auto[6]=Bright_Auto[0];
//	Bright_Auto[7]=Bright_Auto[0];
//	Bright_Auto[8]=Bright_Auto[0];
//	Bright_Auto[9]=Bright_Auto[0];
	}
	else
	{
    Bright_Auto[0]=(GetADC(0)>>4);
	Bright_Auto[1]=Bright_Auto[0];
	Bright_Auto[2]=Bright_Auto[1];
	Bright_Auto[3]=Bright_Auto[2];
	Bright_Auto[4]=Bright_Auto[3];
	//Bright_Auto[5]=Bright_Auto[4];
//	Bright_Auto[6]=Bright_Auto[5];
	//Bright_Auto[7]=Bright_Auto[6];
	//Bright_Auto[8]=Bright_Auto[7];
//	Bright_Auto[9]=Bright_Auto[8];
	}
	for(cnt=0;cnt<5;cnt++)
	{	
		Bright_Aver+=Bright_Auto[cnt];	
	}
	
	Bright_Aver=Bright_Aver/6;
	Slave.LightSensor_Value=Bright_Aver;
	}
	else
	Cnt_ForAD--;

		if(Bright_Aver<(Level_Data1/2))
		{
				
			Dimmer_Auto1=100*Bright_Aver/(Level_Data1/2);
		}
		else if(Bright_Aver<(Level_Data1*2/3))
		{
			Dimmer_Auto1=100+(Dimmer_Slave.Dstep2-100)*(Bright_Aver-(Level_Data1/2))/((Level_Data1*2/3)-Level_Data1/2);
		}
		else if(Bright_Aver<Level_Data1)
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep2+(Dimmer_Slave.Dstep3-Dimmer_Slave.Dstep2)*(Bright_Aver-Level_Data1*2/3)/(Level_Data1-(Level_Data1*2/3));
		}
		else if(Bright_Aver<(Level_Data1+(Level_Data2-Level_Data1)/3))
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep3+(Dimmer_Slave.Dstep4-Dimmer_Slave.Dstep3)*(Bright_Aver-Level_Data1)/((Level_Data2-Level_Data1)/3);
		}
		else  if(Bright_Aver<(Level_Data1+(Level_Data2-Level_Data1)*2/3))
		{ 
			Dimmer_Auto1=Dimmer_Slave.Dstep4+(Dimmer_Slave.Dstep5-Dimmer_Slave.Dstep4)*(Bright_Aver-(Level_Data1+(Level_Data2-Level_Data1)/3))/((Level_Data2-Level_Data1)/3);
		}
		else if(Bright_Aver<Level_Data2)
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep5+(Dimmer_Slave.Dstep6-Dimmer_Slave.Dstep5)*(Bright_Aver-(Level_Data1+(Level_Data2-Level_Data1)*2/3))/((Level_Data2-Level_Data1)/3);;
		}
		else if(Bright_Aver<(Level_Data2+(Level_Data3-Level_Data2)/3))
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep6+(Dimmer_Slave.Dstep7-Dimmer_Slave.Dstep6)*(Bright_Aver-Level_Data2)/((Level_Data3-Level_Data2)/3);
		}
		else if(Bright_Aver<(Level_Data2+(Level_Data3-Level_Data2)*2/3))
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep7+(Dimmer_Slave.Dstep8-Dimmer_Slave.Dstep7)*(Bright_Aver-(Level_Data2+(Level_Data3-Level_Data2)/3))/((Level_Data3-Level_Data2)/3);
		}
		else if(Bright_Aver<Level_Data3)
		{
			Dimmer_Auto1=Dimmer_Slave.Dstep8+(Dimmer_Slave.Dstep9-Dimmer_Slave.Dstep8)*(Bright_Aver-(Level_Data2+(Level_Data3-Level_Data2)*2/3))/((Level_Data3-Level_Data2)/3);
		}
		else  
		{ 
			Dimmer_Auto1=Dimmer_Slave.Dstep10;
		}

	if((Flag_BrightAdj_Initial==1)&&(Flag_BrightAdj_Initial2==1))
	{
	Flag_BrightAdj_Initial=0;	 		 
	Dimmer_Auto2=Dimmer_Auto1;
	}



   if(Cnt_ForBL==0)
   {
   	Cnt_ForBL=6*Slave.Cnt_ForBL;
	if(Dimmer_Auto1>Dimmer_Auto2)
	Dimmer_Auto2++;
	else
	if(Dimmer_Auto1<Dimmer_Auto2)
	Dimmer_Auto2--;	
	}
	else
	Cnt_ForBL--;
	
//	Slave.BL_PWM=0x1300-48*Dimmer_Auto2/10;
//	PWMA->CMR0=Slave.BL_PWM;
	if(Flag_LED==1)
		PWMA->CMR1=1500+64*Dimmer_Auto2;
	else
		PWMA->CMR1=0;		
}
*/