#define _UART_C_

#include <stdio.h>
#include <stdint.h>	
#include "global.h"
#include "M051Series.h"
#include "M051.h"
#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvUART.h"
#include "Register_Bit.h"
#include "Uart.h"
#include "adc.h"
#include "Macro_SystemClock.h"

extern 	uint8_t  UART0_SendFlag,
				 UART1_SendFlag,
                 DIS_LINK_EN,                                                                                  
				 EN_SET,//display状态
				 AT_DET_EN,
				 Status_Update,
				 key_value,prev_key_value;
extern Dimmer_Step Dimmer_Slave;

extern int num4,num7;

uint8_t pwm_value=50,//0-100
		bright_low,
		bright_high;
volatile uint8_t Key_Lock,
        Sta_Ctrl=0xdf;//
static int AD_X_1[10];
extern int Dimmer[10];

/***************************************************************************************

** Function Name    ：  Init_Uart

** Descriptions     ：  串口初始化函数

** Input  parameters：  None

** OutPut parameters：  None

** Returned  value  :        

***************************************************************************************/
uint8_t UART_init()
 
{
    int8_t item;
	STR_UART_T sParam;
	STR_RS485_T sParam_RS485;

  	DrvGPIO_InitFunction(E_FUNC_UART0);
	DrvGPIO_InitFunction(E_FUNC_UART1);
	/* UART Setting */
    sParam.u32BaudRate 		= 9600;
    sParam.u8cDataBits 		= DRVUART_DATABITS_8;
    sParam.u8cStopBits 		= DRVUART_STOPBITS_1;
    sParam.u8cParity 		= DRVUART_PARITY_NONE;
    sParam.u8cRxTriggerLevel= DRVUART_FIFO_1BYTES;
	/* Set UART Configuration */
    if(DrvUART_Open(UART_PORT1,&sParam) != E_SUCCESS)
		{
			printf("UART0 open failed\n");
			return FALSE;
		}

	sParam.u32BaudRate 		= 115200;
	if(DrvUART_Open(UART_PORT0,&sParam) != E_SUCCESS)
		{
			printf("UART1 open failed\n");
			return FALSE;
		}
	/* Set RS485 Configuration */
	sParam_RS485.u8cAddrEnable = ENABLE; 
	sParam_RS485.u8cAddrValue  = 0x00;	         	/* Address */
	sParam_RS485.u8cModeSelect = MODE_RS485_AUD|MODE_RS485_AAD;
	sParam_RS485.u8cDelayTime  = 0;
	sParam_RS485.u8cRxDisable  = DISABLE;
	DrvUART_SetFnRS485(UART_PORT0,&sParam_RS485);

	DrvUART_EnableInt(UART_PORT1, DRVUART_RDAINT,UART1_INT_HANDLE);
	DrvUART_EnableInt(UART_PORT0, DRVUART_RDAINT,UART0_INT_HANDLE);
	return TRUE;
}
void UART0_SEND(uint8_t *BufferPtr, uint32_t Length)
{
	DrvUART_Write(UART_PORT0,BufferPtr,Length);  
}

void UART1_SEND(uint8_t *BufferPtr, uint32_t Length)
{
	DrvUART_Write(UART_PORT1,BufferPtr,Length);
}

//uint16_t AD_CONS(char channel)
//{
//	
//			uint16_t volatage=0;
//			DrvADC_StartConvert();
//	
//		while( DrvADC_IsConversionDone()!=TRUE );
//		volatage=DrvADC_GetConversionData(channel);
//		return volatage;
//}

// 	tim++;
// 	tim_vale+=volatage;
// 	if(tim==10)
// 	{
// 		tim=0;
// 		lvbo=tim_vale/10;
// 		tim_vale=0;
// 	}
/*****************************************************************************************

** Function Name    ：  UART_INT_HANDLE

** Descriptions     ：  UART Callback function 

** Input  parameters：  u32IntStatus

** OutPut parameters：    None

** Returned  value  :    

*****************************************************************************************/

uint8_t UART0_INT_HANDLE(uint32_t u32IntStatus)
{							 	 
     uint8_t CMD_Uart;
     uint8_t ADDRESS_485;
	 uint8_t checksum=0;
	 uint8_t i;

	 UA0_IER &= ~RDA_IEN;
	 				   
//	 DrvUART_Write(UART_PORT0,"Andy.shao.uart0\r\n",17);  //Andy_test
	 
     if(UA0_ISR& RDA_IF) //查询接收可用数据标志位 当FIFO达到限制 则RDA_IF置位 
     {    //---------------- 关闭接收中断,后续数据采用查询接收 ------------------------- 
//		ADDR_485 = 0XF0|(~DrvGPIO_GetBit(Address0_485)&0x01)|(~DrvGPIO_GetBit(Address1_485)<<1&0x02);
//		ADDR_485 = 0XF0;
		if(DrvGPIO_GetBit(RX_DET)==1)
		{
			if(DrvGPIO_GetBit(HPD2_DET)==1)
			{
				ADDR_485 = 0XF5;
				Led_Test_ON();
				Led_Test_FLASHING=0;
			}
			else
			{
				ADDR_485 = 0XF0;
				Led_Test_OFF();
				Led_Test_FLASHING=0;
			}
		}
		else
		{
			ADDR_485 = 0XF2;
			Led_Test_FLASHING=1;
		}
		DrvUART_Read(UART_PORT0,&CMD_Uart,1);
		if(CMD_Uart != 0xAA)
		{
			UA0_IER |= RDA_IEN;
			return 0;
		}
		DrvUART_Read(UART_PORT0,&ADDRESS_485,1);             
		if(CMD_Uart==0xAA&&ADDRESS_485==ADDR_485)
		{	
		    DrvUART_Read(UART_PORT0,UART0_Buffer,4);
			DrvUART_Read(UART_PORT0,UART0_Buffer+4,UART0_Buffer[2]);
			for(i=0;i<UART0_Buffer[2]+3;i++)
			{
				checksum += UART0_Buffer[i]; 						 //check sum
			}
			if(checksum==UART0_Buffer[(UART0_Buffer[2]+3)])
			{
				UART0_RecvFlag=1;									//检测接收到完整数据包并校核正确后，置接收标志
			}
			else
			{
				UART0_RecvFlag=0;
				//接收错误 请求重发
				UART0_Send_Buffer[0] = 0xAA;
				UART0_Send_Buffer[1] = 0xFF;
				UART0_Send_Buffer[2] = ADDR_485;
				UART0_Send_Buffer[3] = 0x03;
				UART0_Send_Buffer[4] = 'N';
				UART0_Send_Buffer[5] =	UART0_Buffer[0];
				UART0_Send_Buffer[6] = 'E';
				UART0_Send_Buffer[7] = 0;
				for(i=1;i<7;i++)
				{
					UART0_Send_Buffer[7] += UART0_Send_Buffer[i];
				}
				DrvUART_Write(UART_PORT0,UART0_Send_Buffer,8);				
			}														
		}	
	}
    UA0_IER |= RDA_IEN;
}
uint8_t UART1_INT_HANDLE(uint32_t u32IntStatus)
{							 	 
	uint8_t CMD_Uart;
	uint8_t checksum=0;
	uint8_t i;
	
	UA1_IER &= ~RDA_IEN;
//	 printf("Andy.shao.uart1\r\n");				   //Andy_test
//	 AD_CONS(5);
    if(UA1_ISR& RDA_IF) //查询接收可用数据标志位 当FIFO达到限制 则RDA_IF置位 
	{    //---------------- 关闭接收中断,后续数据采用查询接收 ------------------------- 
		DrvUART_Read(UART_PORT1,&CMD_Uart,1);             
		if(CMD_Uart=='#')//0x23
		{	
		    DrvUART_Read(UART_PORT1,UART1_Buffer,7);
			for(i=0;i<6;i++)
			{
				checksum += UART1_Buffer[i]; 							//check sum
			}
			if((checksum) ==UART1_Buffer[6])
			{
				UART1_RecvFlag=1;
			}
			else
			{
				UART1_RecvFlag=0;	
			}	 	 																
		}	
	}
    UA1_IER |= RDA_IEN;
}

void Uart0_Handle()
{
//	uint8_t Num_to_Send=0,i=0,check=0,temp,error_flag=0;
//	uint16_t j=0,channel_value,temp2;
	uint8_t i;

	if(UART0_RecvFlag==1)
	{
	    UART0_RecvFlag=0;
		for(i=0;i<20;i++)				   //clear buffer
		{
			UART0_Send_Buffer[i]=0;	 
		}
		UART0_Send_Buffer[0] = 0xAA;		//Header
		UART0_Send_Buffer[1] = 0xFF;		//Command
		UART0_Send_Buffer[2] = ADDR_485;	//ID

	 	switch (UART0_Buffer[0])//命令参数
		{
			case 0x01://Serial number control				   //AA F0 01 00 00 01
				UART0_Send_Buffer[3] = 11;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] =	UART0_Buffer[0];	   //R-CMD
				UART0_Send_Buffer[6] = 'I';					   //Data
				UART0_Send_Buffer[7] = 'n';
				UART0_Send_Buffer[8] = 'e';
				UART0_Send_Buffer[9] = 'l';
				UART0_Send_Buffer[10] = 'm';
				UART0_Send_Buffer[11] = 'a';
				UART0_Send_Buffer[12] = 't';
				UART0_Send_Buffer[13] = 'i';
				UART0_Send_Buffer[14] = 'c';
				break;
			case 0x02://photo-sensor(dimmer level)			   //AA F0 02 00 00 02
				UART0_Send_Buffer[3] = 3;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
//				if(SENSOR_VALUE>0)SENSOR_VALUE = 1;
				UART0_Send_Buffer[6] = SENSOR_VALUE;		   //Data
				break;
			case 0x03://TFT_Current							   //AA F0 03 00 00 03
				UART0_Send_Buffer[3] = 3;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				UART0_Send_Buffer[6] = TFT_CURR_VALUE;		   //Data
				break;
			case 0x04://BL_Current							   //AA F0 04 00 00 04
				UART0_Send_Buffer[3] = 3;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				UART0_Send_Buffer[6] = BL_CURR_VALUE;		   //Data
				break;
			case 0x05://SYS_Temperature						   //AA F0 05 00 00 05
				UART0_Send_Buffer[3] = 4;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				if(SYS_TEMP_VALUE<TempZero)
				{
					UART0_Send_Buffer[6] = '-';
					UART0_Send_Buffer[7] = TempZero-SYS_TEMP_VALUE;	//Data
				}
				else
				{
					UART0_Send_Buffer[6] = '+';
					UART0_Send_Buffer[7] = SYS_TEMP_VALUE-TempZero;	//Data
				}
				break;
			case 0x06://BackLight_Temperature				   //AA F0 06 00 00 06
				UART0_Send_Buffer[3] = 4;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				if(BACK_TEMP_VALUE<TempZero)
				{
					UART0_Send_Buffer[6] = '-';
					UART0_Send_Buffer[7] = TempZero-BACK_TEMP_VALUE;	//Data
				}
				else
				{
					UART0_Send_Buffer[6] = '+';
					UART0_Send_Buffer[7] = BACK_TEMP_VALUE-TempZero;	//Data
				}
				break;
			case 0x07://Input voltage						   //AA F0 07 00 00 07
				UART0_Send_Buffer[3] = 3;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				UART0_Send_Buffer[6] = IN_VOLTAGE_VALUE;	   //Data
				break;

			case 0x08://AD board EN				
				if(UART0_Buffer[2]==0)							   //AA F0 08 00 00 08
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
					if(DrvGPIO_GetBit(EN_3V3)==0 && DrvGPIO_GetBit(EN_1V8)==0)
					{
						UART0_Send_Buffer[6] = 1;				   //Data
					}
					else
					{
						UART0_Send_Buffer[6] = 0;				  //Data
					}	
				}
				else if(UART0_Buffer[2]==1)						  //AA F0 08 00 01 01 0A //AA F0 08 00 01 00 09
				{
					if(UART0_Buffer[3]==1)
					{
						EN_3V3_ON();
						EN_1V8_ON();
					}
					else
					{
						EN_3V3_OFF();
						EN_1V8_OFF();
					}
					UART0_Send_Buffer[3] = 5;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
					if(DrvGPIO_GetBit(EN_3V3)!=UART0_Buffer[3] && DrvGPIO_GetBit(EN_1V8)!=UART0_Buffer[3])
					{
						UART0_Send_Buffer[6] = 'O';				   //Data
						UART0_Send_Buffer[7] = 'K';				   //Data
						UART0_Send_Buffer[8] = ' ';				   //Data
					}
					else
					{
						UART0_Send_Buffer[6] = 'E';				  //Data
						UART0_Send_Buffer[7] = 'R';				  //Data
						UART0_Send_Buffer[8] = 'R';				  //Data
					}
				} 
				break;
			case 0x09://TFT POWER EN
				if(UART0_Buffer[2]==0)							   //AA F0 09 00 00 09
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
					if(DrvGPIO_GetBit(EN_TFT_12)==0)
					{
						UART0_Send_Buffer[6] = 1;				   //Data
					}
					else
					{
						UART0_Send_Buffer[6] = 0;				  //Data
					}	
				}
				else if(UART0_Buffer[2]==1)						  //AA F0 09 00 01 01 0B //AA F0 09 00 01 00 0A
				{
					if(UART0_Buffer[3]==1)
					{
						TFT_12_ON();
					}
					else
					{
						TFT_12_OFF();
					}
					UART0_Send_Buffer[3] = 5;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
					if(DrvGPIO_GetBit(EN_TFT_12)!=UART0_Buffer[3])
					{
						UART0_Send_Buffer[6] = 'O';				   //Data
						UART0_Send_Buffer[7] = 'K';				   //Data
						UART0_Send_Buffer[8] = ' ';				   //Data
					}
					else
					{
						UART0_Send_Buffer[6] = 'E';				  //Data
						UART0_Send_Buffer[7] = 'R';				  //Data
						UART0_Send_Buffer[8] = 'R';				  //Data
					}
				} 
				break;
			case 0x0A://BL POWER EN
				if(UART0_Buffer[2]==0)							   //AA F0 0A 00 00 0A
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
//					UART1_RecvFlag=0;
//					while(UART1_RecvFlag==0);
					UART0_Send_Buffer[6] = AD_Board_Data.AD_Board_BL_EN_Status;	   	   //Data
				}
				else if(UART0_Buffer[2]==1)						  //AA F0 0A 00 01 01 0C  //AA F0 0A 00 01 00 0B
				{
					AD_BOARD_BL_STATUS_FLAG = 1;
					BL_EN_Status = UART0_Buffer[3];

					UART0_Send_Buffer[3] = 5;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD

					UART0_Send_Buffer[6] = 'O';				   //Data
					UART0_Send_Buffer[7] = 'K';				   //Data
					UART0_Send_Buffer[8] = ' ';				   //Data

				}														
				break;
			case 0x0B://Test LED
				if(UART0_Buffer[2]==0)							   //AA F0 0B 00 00 0B
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
					if(DrvGPIO_GetBit(LED_TEST)==0)
					{
						UART0_Send_Buffer[6] = 1;				   //Data
					}
					else
					{
						UART0_Send_Buffer[6] = 0;				  //Data
					}	
				}
				else if(UART0_Buffer[2]==1)						  //AA F0 0B 00 01 00 0C //AA F0 0B 00 01 01 0D //AA F0 0B 00 01 02 0E
				{
					if(UART0_Buffer[3]==1)
					{
						Led_Test_ON();
						Led_Test_FLASHING=0;
					}
					else if(UART0_Buffer[3]==0)
					{
						Led_Test_OFF();
						Led_Test_FLASHING=0;
					}
					else
					{
						Led_Test_FLASHING=1;
					}
					UART0_Send_Buffer[3] = 2;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
				}
				break;
			case 0x0C://Back Light MODE(Auto/Manual)
				if(UART0_Buffer[2]==0)							   //AA F0 0C 00 00 0C
				{
					UART0_Send_Buffer[3] = 4;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
//					UART1_RecvFlag=0;
//					while(UART1_RecvFlag==0);
					UART0_Send_Buffer[6] = AD_Board_Data.AD_Board_BL_Mode_Status;	   	   //Data
					UART0_Send_Buffer[7] = AD_Board_Data.AD_Board_BL_Level_Status;	
				}
				else if(UART0_Buffer[2]==2)						   //Set Dimmer: (manual, 80%) AA F0 0C 00 02 01 08 17

				{				
					AD_BOARD_BL_FLAG = 1;
					BL_MODE_Status = UART0_Buffer[3];
					BL_LEVEL_Status = UART0_Buffer[4];

//					SetBL_PWM(UART0_Buffer[4]);
					PWM(UART0_Buffer[4]);

					UART0_Send_Buffer[3] = 2;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD				 
				}
				break;
			case 0x0d://Channel
				if(UART0_Buffer[2]==0)							   //AA F0 0D 00 00 0D
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
//					UART1_RecvFlag=0;
//					while(UART1_RecvFlag==0);
					UART0_Send_Buffer[6] = AD_Board_Data.AD_Board_Channel_Status;	   	   //Data
				}
				else if(UART0_Buffer[2]==1)						   //AA F0 0D 00 01 02 10
				{				
					AD_BOARD_CHANNAL_FLAG = 1;
					AD_BOARD_CHANNAL_Stasus = UART0_Buffer[3];

					UART0_Send_Buffer[3] = 2;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD				 
				}
				break;
			case 0x0e://monitor status							   
				if(UART0_Buffer[2]==0)							   //AA F0 0E 00 00 0E
				{
					UART0_Send_Buffer[3] = 3;				  	   //Data length
					UART0_Send_Buffer[4] = 'A';					   //Ack
					UART0_Send_Buffer[5] = UART0_Buffer[0];	       //R-CMD
//					UART1_RecvFlag=0;
//					while(UART1_RecvFlag==0);
					UART0_Send_Buffer[6] = AD_Board_Data.AD_Board_Monitor_Status;	   	   //Data
				}
				break;
			default:
				UART0_Send_Buffer[3] = 10;				  	   //Data length
				UART0_Send_Buffer[4] = 'A';					   //Ack
				UART0_Send_Buffer[5] =	UART0_Buffer[0];	   //R-CMD
				UART0_Send_Buffer[6] = 'R';					   //Data
				UART0_Send_Buffer[7] = 'e';
				UART0_Send_Buffer[8] = 's';
				UART0_Send_Buffer[9] = 'e';
				UART0_Send_Buffer[10] = 'r';
				UART0_Send_Buffer[11] = 'v';
				UART0_Send_Buffer[12] = 'e';
				UART0_Send_Buffer[13] = 'd';
		}
		for(i=1;i<UART0_Send_Buffer[3]+4;i++)			 //CheckSum
		{
			UART0_Send_Buffer[UART0_Send_Buffer[3]+4] += UART0_Send_Buffer[i];
		}
		delay_ms(1);
		DrvUART_Write(UART_PORT0,UART0_Send_Buffer,UART0_Send_Buffer[3]+5);	//send to uart0
//		delay_ms(1);
	}
}			
void Uart1_Handle()
{
//AD Board CMD e.g. 23 31 01 50 01 02 04 89
//23:Header('#') 31:CMD('1') 01:MODE 50:BL_Level 01:BL_EN 02:Channel 04:Monitor Status 88:CRC

	uint8_t i;
	if(UART1_RecvFlag==1)
	{
		UART1_RecvFlag=0;
		AD_Board_Data.AD_Board_BL_Mode_Status = UART1_Buffer[1];
		AD_Board_Data.AD_Board_BL_Level_Status = UART1_Buffer[2];
		AD_Board_Data.AD_Board_BL_EN_Status = UART1_Buffer[3];
		AD_Board_Data.AD_Board_Channel_Status = UART1_Buffer[4];
		AD_Board_Data.AD_Board_Monitor_Status = UART1_Buffer[5];
//		delay_ms(1);

		if(AD_BOARD_BL_FLAG==1)
		{
			AD_BOARD_BL_FLAG = 0;
			for(i=0;i<20;i++)				   //clear buffer
			{
				UART1_Send_Buffer[i]=0;		 
			}
			UART1_Send_Buffer[0] = 0xAA;		//Header
			UART1_Send_Buffer[1] = 0x0C;		//Command
			UART1_Send_Buffer[2] = BL_MODE_Status;		//DATA		   //
			UART1_Send_Buffer[3] = BL_LEVEL_Status;
			for(i=1;i<4;i++)			 //CheckSum
			{
				UART1_Send_Buffer[4] += UART1_Send_Buffer[i];
			}

//			DrvUART_Write(UART_PORT1,UART1_Send_Buffer+0,1);
//			delay_ms(10);
//			DrvUART_Write(UART_PORT1,UART1_Send_Buffer+1,1);
//			delay_ms(10);
//			DrvUART_Write(UART_PORT1,UART1_Send_Buffer+2,1);
//			delay_ms(10);
//			DrvUART_Write(UART_PORT1,UART1_Send_Buffer+3,1);
//			delay_ms(10);
//			DrvUART_Write(UART_PORT1,UART1_Send_Buffer+4,1);
			delay_ms(10);

			DrvUART_Write(UART_PORT1,UART1_Send_Buffer,5);	//send to uart1
		}
		if(AD_BOARD_CHANNAL_FLAG==1)
		{
			AD_BOARD_CHANNAL_FLAG = 0;
			for(i=0;i<20;i++)				   //clear buffer
			{
				UART1_Send_Buffer[i]=0;		 
			}
			UART1_Send_Buffer[0] = 0xAA;		//Header
			UART1_Send_Buffer[1] = 0x0D;		//Command
			UART1_Send_Buffer[2] = AD_BOARD_CHANNAL_Stasus;	 //DATA
			for(i=1;i<3;i++)			 //CheckSum
			{
				UART1_Send_Buffer[3] += UART1_Send_Buffer[i];
			}
			delay_ms(10);
			DrvUART_Write(UART_PORT1,UART1_Send_Buffer,4);	//send to uart1				
		}
		if(AD_BOARD_BL_STATUS_FLAG==1)
		{
			AD_BOARD_BL_STATUS_FLAG = 0;
			for(i=0;i<20;i++)				   //clear buffer
			{
				UART1_Send_Buffer[i]=0;		 
			}
			UART1_Send_Buffer[0] = 0xAA;		//Header
			UART1_Send_Buffer[1] = 0x0A;		//Command
			UART1_Send_Buffer[2] = BL_EN_Status;   //DATA
			for(i=1;i<3;i++)			 //CheckSum
			{
				UART1_Send_Buffer[3] += UART1_Send_Buffer[i];
			}
			delay_ms(10);
			DrvUART_Write(UART_PORT1,UART1_Send_Buffer,4);	//send to uart1					
		}
	}
}
//void Uart1_Handle()
//{
// uint8_t Num_to_Send=0,i=0,check=0,temp,error_flag=0,temph,templ;
//	uint16_t j=0,channel_value;
//	if(UART1_RecvFlag==1)
//	{
//	    UART1_RecvFlag=0;
//        for(i=0;i<20;i++)
//		 {
//		 	UART_STOH_Buffer[i]=0;		 
//		 }
//	 	switch (UART1_Buffer[0])//命令参数
//			{
//				
//				/*******************TFT_CURR*****************************/
//						case 0x00:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x10;
//										
//										channel_value=AD_CONS(0)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x10;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//			break;
//						
//						
//				/*******************SENSOR_A*****************************/
//						case 0x01:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x30;
//										
//										channel_value=AD_CONS(1)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x30;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//			break;
//						
//				/*******************back_temp*****************************/
//						case 0x04:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x40;
//										
//									channel_value=Table_lookup(num7)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//											
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x40;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//			break;						
//						
//				/*******************IN_Volatge*****************************/
//						case 0x05:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x50;
//										
//										channel_value=AD_CONS(5)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x50;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//			break;					
//						
//						
//				/*******************SENSOR_A*****************************/
//						case 0x06:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x60;
//										
//										channel_value=AD_CONS(6)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x60;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//			break;					
//						
///*CURR check*/
//
//             case 0x07:
//              if(UART1_Buffer[2]==0)//读取  
//								{
//									Status_Update=1;
//									check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//									if(check==UART1_Buffer[3])	 //
//										{	
//										Status_Update=1;
//										UART_STOH_Buffer[0]=0Xaa;
//										UART_STOH_Buffer[1]=0xff;
//										UART_STOH_Buffer[2]=0X00;
//										UART_STOH_Buffer[3]=0x04;
//										UART_STOH_Buffer[4]='A';
//										UART_STOH_Buffer[5]=0x20;
//										
//										//channel_value=Table_lookup(AD_CONS(7));
//										channel_value=Table_lookup(num7)>>2;
//										temph=channel_value&0X0300;//屏蔽低八位
//										temph=temph>>8;//右移八位 取高八位1111 1111 0000 0000
//										UART_STOH_Buffer[6]= temph ;  
//									
//										templ=channel_value&0XFF;		//取低八位
//										UART_STOH_Buffer[7]=templ;
//										Num_to_Send=9;check=0;
//										for(i=1;i<Num_to_Send-1;i++)
//											{
//												check+=(UART_STOH_Buffer[i]);	
//											}				
//											UART_STOH_Buffer[Num_to_Send-1]=check;
//											UART1_SendFlag=1;						
//										}
//									else//NaK
//									{
//										 error_flag=1;
//									}
//						}	  
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x04;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x20;
//								UART_STOH_Buffer[6]='E';
//								UART_STOH_Buffer[7]='E';		
//								Num_to_Send=9;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//						}
//		
//			break;
///*Display Status Control***********************************************************************************************************************/
//				case 0x0D:
//					    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]+UART1_Buffer[3]);
//					    if(check==UART1_Buffer[4])
//						{   
//						    Status_Update=1; 
//						    UART_STOH_Buffer[4]='A';
//						    Sta_Ctrl=UART1_Buffer[3];
//							UART_STOH_Buffer[6]=Sta_Ctrl;;							
//						}
//						else
//						{
//						  UART_STOH_Buffer[4]='N';
//						  UART_STOH_Buffer[6]='E';
//						}													
//						UART_STOH_Buffer[0]=0Xaa;
//						UART_STOH_Buffer[1]=0xff;
//						UART_STOH_Buffer[2]=0;
//						UART_STOH_Buffer[3]=3;						
//						UART_STOH_Buffer[5]=0x0D;	
//						Num_to_Send=8;check=0;
//						for(i=1;i<Num_to_Send-1;i++)
//					   	   {
//						     check+=(UART_STOH_Buffer[i]);
//						   }					
//					    UART_STOH_Buffer[Num_to_Send-1]=check;
//					    UART1_SendFlag=1;
//			            if(UART1_Buffer[2])//set the displaystatus
//							  {	
//							  	Status_Update=1;
//							    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]+UART1_Buffer[3]);
//							    if(check==UART1_Buffer[4])
//								{   
//								   Sta_Ctrl=UART1_Buffer[3];								 	
//								   UART1_SendFlag=1;
//								   UART_STOH_Buffer[4]='A';
//								   UART_STOH_Buffer[6]=Sta_Ctrl;
//								}
//								else
//								{
//								  UART_STOH_Buffer[4]='N';
//								  UART_STOH_Buffer[6]='E';
//								}
//							  } 
//						 else //Get the status  status
//						   {
//						    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//						    if(check==UART1_Buffer[3])
//						      {   	
//							        Status_Update=1;
//		   						   	UART_STOH_Buffer[4]='A';
//											UART_STOH_Buffer[6]=Sta_Ctrl;								
//									}
//							  else
//							    {
//							       UART_STOH_Buffer[4]='N';
//								     UART_STOH_Buffer[6]='E';								  
//							    }
//						   }
//							UART_STOH_Buffer[0]=0Xaa;
//							UART_STOH_Buffer[1]=0xff;
//							UART_STOH_Buffer[2]=0;
//							UART_STOH_Buffer[3]=3;							
//							UART_STOH_Buffer[5]=0X0D;							
//							Num_to_Send=8;check=0;
//							for(i=1;i<Num_to_Send-1;i++)
//						   	   {
//							     check+=(UART_STOH_Buffer[i]);
//							   }					
//						    UART_STOH_Buffer[Num_to_Send-1]=check;
//							UART1_SendFlag=1;	
//				 break; 
///*Manual lamp control***********************************************************************************************************************/
//// 			   case 0x58: 
//// 		              if(UART1_Buffer[2])//set the manual lamp status
//// 						  {		
//// 						    Status_Update=1;
//// 						    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]+UART1_Buffer[3]);
//// 						    if(check==UART1_Buffer[4] && UART1_Buffer[3]<101)
//// 							  {   
//// 							    pwm_value=UART1_Buffer[3];								 	
//// 							    UART1_SendFlag=1;
//// 							    UART_STOH_Buffer[4]='A';
//// 							    UART_STOH_Buffer[6]=pwm_value;
//// 							  }
//// 							else
//// 							  {
//// 							    UART_STOH_Buffer[4]='N';
//// 							    UART_STOH_Buffer[6]='E';
//// 							  }
//// 						  } 
//// 					else //Get the manual lamp status
//// 						   {
//// 						    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//// 						    if(check==UART1_Buffer[3])
//// 								{   	
//// 								   Status_Update=1;
//// 		   						   UART_STOH_Buffer[4]='A';
//// 								   UART_STOH_Buffer[6]=pwm_value;								
//// 								}
//// 							else
//// 							   {
//// 							       UART_STOH_Buffer[4]='N';
//// 								   UART_STOH_Buffer[6]='E';								  
//// 							   }
//// 						   }
//// 							UART_STOH_Buffer[0]=0Xaa;
//// 							UART_STOH_Buffer[1]=0xff;
//// 							UART_STOH_Buffer[2]=0;
//// 							UART_STOH_Buffer[3]=3;							
//// 							UART_STOH_Buffer[5]=0X58;							
//// 							Num_to_Send=8;check=0;
//// 							for(i=1;i<Num_to_Send-1;i++)
//// 						   	  {
//// 							   check+=(UART_STOH_Buffer[i]);
//// 							  }					
//// 						    UART_STOH_Buffer[Num_to_Send-1]=check;
//// 							UART1_SendFlag=1;						   
//// 			   	break;
///*Serial Number Control***********************************************************************************************************************/
//				case 0x0B:
//				      error_flag=0;
//				      if(UART0_Buffer[2]==0)//读取  
//					    {
//						    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//							if(check==UART1_Buffer[3])	 //
//							  {	
//							  	Status_Update=1;
//							    UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0X00;
//								UART_STOH_Buffer[3]=0x0C;
//								UART_STOH_Buffer[4]='A';
//								UART_STOH_Buffer[5]=0x0B;
//								UART_STOH_Buffer[6]=serial.inch_H;
//								UART_STOH_Buffer[7]=serial.inch_L;
//							    UART_STOH_Buffer[8]=serial.HW_V;
//								UART_STOH_Buffer[9]=serial.SW_V;									
//								UART_STOH_Buffer[10]=serial.year;
//								UART_STOH_Buffer[11]=serial.month;
//								UART_STOH_Buffer[12]=serial.day;
//							    UART_STOH_Buffer[13]=serial.numH;
//								UART_STOH_Buffer[14]=serial.numL  ;
//								Num_to_Send=16;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	check+=(UART_STOH_Buffer[i]);					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART0_SendFlag=1;						
//						    }
//							else//NaK
//							{
//							   error_flag=1;
//							}
//						}	  
//					  else if(UART1_Buffer[2]==0x0a)//设置	
//					    {
//						    for(i=0;i<12;i++)
//						  	 { 
//							   check+=(uint8_t)(UART1_Buffer[i]);
//							 } 					  	 					   	
//						    if(check==UART1_Buffer[12])
//							  { 
//							       	Status_Update=1;
//									serial.inch_H=UART1_Buffer[3];
//									serial.inch_L=UART1_Buffer[4];
//								    serial.HW_V=UART1_Buffer[5];
//									serial.SW_V=UART1_Buffer[6];									
//									serial.year=UART1_Buffer[7];
//								    serial.month=UART1_Buffer[8];
//									serial.day=UART1_Buffer[9];
//								    serial.numH=UART1_Buffer[10];
//									serial.numL=UART1_Buffer[11] ;
//																																															
//								 	UART_STOH_Buffer[0]=0Xaa;
//									UART_STOH_Buffer[1]=0xff;
//									UART_STOH_Buffer[2]=0X00;
//									UART_STOH_Buffer[3]=0x0C;
//									UART_STOH_Buffer[4]='A';
//									UART_STOH_Buffer[5]=0x0B;
//									UART_STOH_Buffer[6]=serial.inch_H;
//									UART_STOH_Buffer[7]=serial.inch_L;
//								    UART_STOH_Buffer[8]=serial.HW_V;
//									UART_STOH_Buffer[9]=serial.SW_V;									
//									UART_STOH_Buffer[10]=serial.year;
//									UART_STOH_Buffer[11]=serial.month;
//									UART_STOH_Buffer[12]=serial.day;
//								    UART_STOH_Buffer[13]=serial.numH;
//									UART_STOH_Buffer[14]=serial.numL  ;
//									Num_to_Send=16;check=0;
//									for(i=1;i<Num_to_Send-1;i++)
//								   	   {
//									     check+=(UART_STOH_Buffer[i]);
//									   }					
//								    UART_STOH_Buffer[Num_to_Send-1]=check;
//								    UART1_SendFlag=1;							 
//							  }
//							else//NaK
//							 {
//							 	error_flag=1;
//							 }
//						  }
//					if(error_flag==1)
//					      {
//							 	UART_STOH_Buffer[0]=0Xaa;
//								UART_STOH_Buffer[1]=0xff;
//								UART_STOH_Buffer[2]=0;
//								UART_STOH_Buffer[3]=0x03;
//								UART_STOH_Buffer[4]='N';
//								UART_STOH_Buffer[5]=0x10;
//								UART_STOH_Buffer[6]='E';
//								Num_to_Send=8;check=0;
//								for(i=1;i<Num_to_Send-1;i++)
//							   	   {
//								     check+=(UART_STOH_Buffer[i]);
//								   }					
//							    UART_STOH_Buffer[Num_to_Send-1]=check;
//							    UART1_SendFlag=1;										
//							}
//				 break; 
//
///**read keys status*************************************************************************************************/
//// 				case 0x8b:
//// 					    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//// 					    if(check==UART1_Buffer[3])
//// 						{  	
//// 						   Status_Update=1; 						    
//// 						   UART_STOH_Buffer[4]='A';
//// 						   temp=GPIO_Read();
//// 						   UART_STOH_Buffer[6]=temp;//Key status	
//// 						}
//// 						else
//// 						{
//// 						  UART_STOH_Buffer[4]='N';
//// 						  UART_STOH_Buffer[6]='E';//Key status						
//// 						}
//// 						UART_STOH_Buffer[0]=0Xaa;
//// 						UART_STOH_Buffer[1]=0xff;
//// 						UART_STOH_Buffer[2]=0;
//// 						UART_STOH_Buffer[3]=3;
//// 						
//// 						UART_STOH_Buffer[5]=0x8b;
//// 					
//// 						Num_to_Send=8;check=0;
//// 						for(i=1;i<Num_to_Send-1;i++)
//// 					   	   {
//// 						     check+=(UART_STOH_Buffer[i]);
//// 						   }					
//// 					    UART_STOH_Buffer[Num_to_Send-1]=check;
//// 						prev_key_value=temp;
//// 					    UART1_SendFlag=1;
//
//// 				 break; 
///*lamp min/max set***********************************************************************************************************************/
//// 			   case 0xFE: 
//// 			              if(UART1_Buffer[2])//set the manual lamp status
//// 							  {		
//// 							    Status_Update=1;
//// 							    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]+UART1_Buffer[3]+UART1_Buffer[4]);
//// 							    if(check==UART1_Buffer[5] && UART1_Buffer[3]<101 && UART1_Buffer[4]<101 && UART1_Buffer[3]<UART1_Buffer[4])
//// 								{   
//// 								    bright_low=UART1_Buffer[3];
//// 									bright_high=UART1_Buffer[4];							 	
//// 								    
//// 								   UART_STOH_Buffer[4]='A';
//// 								   UART_STOH_Buffer[6]=bright_low;
//// 								   UART_STOH_Buffer[7]=bright_high;
//// 								   UART1_SendFlag=1;
//// 								 }
//// 								else
//// 								{
//// 								  UART_STOH_Buffer[4]='N';
//// 								  UART_STOH_Buffer[6]='E';
//// 								}
//// 							  } 
//// 						 else //Get the manual lamp status
//// 						   {
//// 						    check=(uint8_t)(UART1_Buffer[0]+UART1_Buffer[1]+UART1_Buffer[2]);
//// 						    if(check==UART1_Buffer[3])
//// 								{     Status_Update=1;
//// 		   						   	UART_STOH_Buffer[4]='A';
//// 									UART_STOH_Buffer[6]=bright_low;
//// 									UART_STOH_Buffer[7]=bright_high;								
//// 								}
//// 							else
//// 							   {
//// 							     UART_STOH_Buffer[4]='N';
//// 								   UART_STOH_Buffer[6]='E';								  
//// 							   }
//// 						   }
//// 							UART_STOH_Buffer[0]=0Xaa;
//// 							UART_STOH_Buffer[1]=0xff;
//// 							UART_STOH_Buffer[2]=0;
//// 							UART_STOH_Buffer[3]=4;							
//// 							UART_STOH_Buffer[5]=0XFE;							
//// 							Num_to_Send=9;check=0;
//// 							for(i=1;i<Num_to_Send-1;i++)
//// 						   	   {
//// 							     check+=(UART_STOH_Buffer[i]);
//// 							   }					
//// 						    UART_STOH_Buffer[Num_to_Send-1]=check;
//// 							UART1_SendFlag=1;						   
//// 			   	break;
//		      			        			
//			}
//	if(UART1_SendFlag==1)
//	   {
//	     UART1_SEND((uint8_t *)UART_STOH_Buffer,Num_to_Send);
//	     UART1_SendFlag=0;
//	   }	
//	}
//}
//
//
///***********电压值表*************/
//
//const float TableADC[11]=
//{903, 825, 781, 716, 622, 534, 414, 306, 241, 183, 139};
//
///***********温度值表*************/
//const float Tabletem[11]=
//{-25, -15, -5, 5, 15, 25, 35, 45, 55, 65,75};
//	
//	
////二次插值法
//uint16_t Interpolation(float chx,float chx1,float chx2,float chx3,float chy1,float chy2,float chy3)
//{
//	float y;
//		y=(((uint16_t)(chx-chx2)*(uint16_t)(chx-chx3))/((uint16_t)(chx1-chx2)*(uint16_t)(chx1-chx3)))*chy1;
//			y=(((uint16_t)(chx-chx1)*(uint16_t)(chx-chx3))/((uint16_t)(chx2-chx1)*(uint16_t)(chx2-chx3)))*chy2;
//				y=(((uint16_t)(chx-chx1)*(uint16_t)(chx-chx2))/((uint16_t)(chx3-chx1)*(uint16_t)(chx3-chx2)))*chy3;
//	return y;//返回温度值
//}
//
//
////查询
//uint16_t Table_lookup(uint16_t x_AD)
//{
//	unsigned char i;
//	float x,x1,x2,x3,y1,y2,y3;
//	x=x_AD;
//	x1=TableADC[0];
//	while(x1<x)
//	{
//		i++;
//		x1=TableADC[i];
//		if(i==10)//共有个数
//			i=0;
//	}
//	i--;//确定自变量x在TableADC[]中的位置
//	x1=TableADC[i];
//		x2=TableADC[i+1];
//			x3=TableADC[i+2];
//	
//	y1=Tabletem[i];
//		y2=Tabletem[i+1];
//			y3=Tabletem[i+2];
//	return Interpolation(x,x1,x2,x3,y1,y2,y3);//调用插值函数，计算对应自变量x的因变量y并返回温度值
//}
//
//int MUX_filter(int AD)
//{
//    unsigned char i,j,k;
//    int temp=0;
//    int sum=0;
//    int lvbo_1[11]={0};
//
//         for (i=1;i<10;i++) 
//        {
//						AD_X_1[i]=AD_X_1[i-1];
//        }
//        AD_X_1[0]=AD;
//        for(i=0;i<10;i++)
//        {
//            lvbo_1[i]=AD_X_1[i];
//        }
//        for(j=0;j<9;j++)  
//        {
//            for(k=0;k<9-j;k++)
//            {
//                if(lvbo_1[k]>lvbo_1[k+1])
//                {
//                    temp=lvbo_1[k];
//                    lvbo_1[k]=lvbo_1[k+1];
//                    lvbo_1[k+1]=temp;
//                }
//            }
//        }
//        for(i=1;i<9;i++)
//        {
//            sum+=lvbo_1[i];
//        }               
//        temp=sum/9;
//    return temp; 
//}



