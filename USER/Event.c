#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvTIMER.h"
#include "global.h"
extern uint8_t DIS_LINK_EN,
			   EN_SET,
			   AT_DET_EN,
			   Sta_Ctrl,
			   pwm_value,
			   Status_Update,
			   key_value,prev_key_value,
			   UART0_SendFlag;


uint8_t                 SlaveIGNRefresh=0;
char                    SlaveIGN[6]={1,1,1,1,1,1};
Struct_Config           Config,Event;
Struct_DefaultParameter Default;
Serial_STR              serial;

void SetEventOn(char EventItem)
{
	Event.LCD_TP_On|=EventItem;
	Event.LCD_TP_On&=Config.LCD_TP_On;
	Event.KeyLED_On|=EventItem;
	Event.KeyLED_On&=Config.KeyLED_On;
		
}
void SetEventOff(char EventItem)
{
	Event.LCD_TP_Off|=EventItem;
	Event.LCD_TP_Off&=Config.LCD_TP_Off;
	Event.KeyLED_Off|=EventItem;
	Event.KeyLED_Off&=Config.KeyLED_Off;	
}
void SetKeyEvent(char EventItem)
{
	
	Event.LCD_TP_On|=EventItem;
	Event.LCD_TP_On&=Config.LCD_TP_On;
	Event.LCD_TP_Off|=EventItem;
	Event.LCD_TP_Off&=Config.LCD_TP_Off;
	Event.KeyLED_On|=EventItem;
	Event.KeyLED_On&=Config.KeyLED_On;
	Event.KeyLED_Off|=EventItem;
	Event.KeyLED_Off&=Config.KeyLED_Off;
}
void Event_Generator()
{
	IGN_Scan();
}
void Event_Handler()
{
    uint16_t temp;
	if(Status_Update==1)
	  {
		  if(MASTER_ON & Sta_Ctrl)//最低位1	全开	  
		  	 {			  
			   	if(LCD_BL_ON & Sta_Ctrl) //为1
					{  						
						DrvGPIO_SetBit(EN_24V_1);
						DrvGPIO_ClrBit(EN_TFT_12);
						if(uTicks_Touch==60*10)
						   {  
						     DrvGPIO_ClrBit(EN_AD_BRD); 	//十分钟自动检测
						   }
						Sta_Ctrl=0XFF;
					}
			   }		  
		   else	 //最低位为0 控制位控制
		     {	    
			    if(LCD_BL_ON & Sta_Ctrl)
						{
							DrvGPIO_SetBit(EN_24V_1);
						}				    
					else 
						{	
							DrvGPIO_ClrBit(EN_24V_1);
						}					  
					
			  	if(LCD_ON & Sta_Ctrl)
						{	
							DrvGPIO_ClrBit(EN_TFT_12);
						}	 				   
					else 
						{	
							DrvGPIO_SetBit(EN_TFT_12);
						}	 					  				  

					if(USB_ON & Sta_Ctrl)
				   	{
							if(uTicks_Touch==60*10)
							{
								DrvGPIO_ClrBit(EN_AD_BRD);
							}
					  }	 						  					
					else 					  					 
					  {
							DrvGPIO_SetBit(EN_AD_BRD);
					  }
					
			    }
// 					if(pwm_value<bright_low)
// 						 {
// 							 pwm_value=bright_low;
// 						 }
// 					if(pwm_value>bright_high)
// 						 {
// 							 pwm_value=bright_high;
// 						 }

		Slave.BL_MIN=bright_low;
		Slave.BL_MAX=bright_high;
		Slave.BL_Value =pwm_value;
		Slave.BL_Mode  =EN_SET;
		Slave.Configuration =Sta_Ctrl;
		save_data(); 			

	 }//end Status_Update==1
/************************************************************/
    if(DIS_LINK_EN!=EN_SET)		//=0 未检查到图像
		{ 
		  PWMA->CMR2=0;	
		  uTicks_Touch=0;
	    }
	else
	   {  
								         
	 	  if(LCD_BL_ON & Sta_Ctrl) //BL_ON使能 
		  	{				     	       		   	   
			     PWMA->CMR2=PWM(pwm_value);
		  	}
		  else
		    {
				PWMA->CMR2=0;
			}
	   }
/************************************************************/
// 	if((key_value != prev_key_value))
// 	{																	
// 		UART0_Buffer[0]=0x8b ;
// 		UART0_Buffer[1]=0x00 ;
// 		UART0_Buffer[2]=0x00 ;
// 		UART0_Buffer[3]=0x8b ;
// 	    UART0_RecvFlag=1;
// 	}
// 	Status_Update=0;	   			
}