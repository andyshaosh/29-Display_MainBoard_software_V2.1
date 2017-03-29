#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvADC.h"
#include "global.h"
#include "adc.h"
extern volatile uint8_t Sta_Ctrl;
char Flag_LED=0;
uint8_t key_value=0xff,prev_key_value=0xff;
uint8_t BL_EN=1;
uint8_t IGN_S1,IGN_S2,DIS_LINK_EN=0,AT_DET_EN=0,EN_SET=1;

void delay_ms(uint16_t q)
{
   uint16_t m,n;
   for(m=0;m<q;m++)
    for(n=0;n<4000;n++);
}

void GPIO_init()
{
	DrvGPIO_Open(K0, E_IO_QUASI);
	DrvGPIO_Open(K1, E_IO_QUASI);
	DrvGPIO_Open(K1, E_IO_QUASI);
	DrvGPIO_Open(K2, E_IO_QUASI);	 
	DrvGPIO_Open(K3, E_IO_QUASI);
	DrvGPIO_Open(K4, E_IO_QUASI);
	DrvGPIO_Open(K5, E_IO_QUASI);
	DrvGPIO_Open(LED_G, E_IO_OUTPUT);	
	DrvGPIO_Open(LED_R, E_IO_OUTPUT);

//	DrvGPIO_Open(Address0_485, E_IO_INPUT);
//	DrvGPIO_Open(Address1_485, E_IO_INPUT);
//	DrvGPIO_Open(EN_BL, E_IO_OUTPUT);
//	DrvGPIO_Open(EN_Video_Equalizer_POWER, E_IO_OUTPUT);
//	DrvGPIO_Open(Video_Equalizer_SD, E_IO_INPUT);
//	DrvGPIO_Open(Video_Equalizer_EN, E_IO_OUTPUT);
//	DrvGPIO_Open(EN_AD_BRD, E_IO_OUTPUT);
//	DrvGPIO_Open(EN_TFT_12, E_IO_OUTPUT);
//	DrvGPIO_Open(LED_TEST, E_IO_OUTPUT);

	DrvGPIO_Open(EN_12V, E_IO_QUASI);
	DrvGPIO_Open(EN_1V8, E_IO_QUASI);
	DrvGPIO_Open(EN_3V3, E_IO_QUASI);

	DrvGPIO_Open(HPD2_DET, E_IO_INPUT);
	DrvGPIO_Open(RX_DET, E_IO_INPUT);
	DrvGPIO_Open(PI3HDX412BD_MS, E_IO_OUTPUT);
	DrvGPIO_Open(PI3HDX412BD_OE, E_IO_OUTPUT);
	DrvGPIO_Open(PI3HDX412BD_SEL1, E_IO_OUTPUT);
	DrvGPIO_Open(PI3HDX412BD_DR, E_IO_OUTPUT);

	DrvGPIO_Open(PI3HDX412BD_EQ2, E_IO_QUASI);
	DrvGPIO_Open(PI3HDX412BD_EQ1, E_IO_QUASI);

//DrvGPIO_Open(EN_USB_1   , E_IO_OUTPUT);	
//DrvGPIO_Open(EN_USB_2   , E_IO_OUTPUT);	
//DrvGPIO_ClrBit(EN_USB_1);
//DrvGPIO_ClrBit(EN_USB_2);
}

/*
void IGN_Scan()
{	
    uint8_t temp;
	
    temp=GPIO_Read();
	delay_ms(100);
	if(temp==GPIO_Read())
	 key_value=GPIO_Read();

    DIS_LINK_EN=DrvGPIO_GetBit(BL_EN_IN_IO);
	AT_DET_EN  =DrvGPIO_GetBit(AT_DET);//ÓÐÐ§
}

uint8_t GPIO_Read()
{
	char IO_read[8];
	uint8_t i;
	IO_read[0]= DrvGPIO_GetBit(E_PORT2, E_PIN0);
	IO_read[1]= DrvGPIO_GetBit(E_PORT2, E_PIN1);
	IO_read[2]= DrvGPIO_GetBit(E_PORT2, E_PIN2);
	IO_read[3]= DrvGPIO_GetBit(E_PORT2, E_PIN3);
	IO_read[4]= DrvGPIO_GetBit(E_PORT2, E_PIN4);
	IO_read[5]= DrvGPIO_GetBit(E_PORT2, E_PIN5);
	IO_read[6]= 1;//DrvGPIO_GetBit(E_PORT2, E_PIN1);
	IO_read[7]= 1;//DrvGPIO_GetBit(E_PORT2, E_PIN0);

 	i=((IO_read[7]<<7)|(IO_read[6]<<6)|(IO_read[5]<<5)|(IO_read[4]<<4)|(IO_read[3]<<3)|(IO_read[2]<<2)|(IO_read[1]<<1)|(IO_read[0]));
	return i;		
}
void Init_GPIOInt()
{
	DrvGPIO_Open(AT_DET, E_IO_INPUT);
	DrvGPIO_EnableInt(AT_DET,E_IO_BOTH_EDGE,E_MODE_EDGE);
	DrvGPIO_SetIntCallback(0,GPIO_Int_Func);
}
void GPIO_Int_Func()
{
   char temp[8],i=0,sum=0;
   DrvGPIO_DisableInt(AT_DET);
   if(DrvGPIO_GetBit(AT_DET)==0)
   	  {
	    Sta_Ctrl|=AT_STATUS;
	  }
   else
  	  {
	    Sta_Ctrl&=~AT_STATUS;
	  }
	  temp[0]=0xAA;temp[1]=0xFF;temp[2]=0x00;temp[3]=0x03;
	  temp[4]=0x41;temp[5]=0x0d;temp[6]=Sta_Ctrl;
	  for(i=1;i<7;i++)
	   { 
	     sum+=temp[i]; 
	   }
   temp[7]=sum&0x00ff;
   UART0_SEND(temp,8);
   DrvGPIO_EnableInt(AT_DET,E_IO_BOTH_EDGE,E_MODE_EDGE);

}
*/   
    




