#define _IIC_C_

#include "M051Series.h"
#include "DrvSYS.h"
#include "DrvI2C.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvUART.H"
#include "DrvADC.h"
#include "DrvTIMER.h"
#include "IIC.H"

void IO_config_delay(unsigned int uSec0268)
{
  do
  {
  }
  while(--uSec0268);
}
void I2C_init(void )
{
	/* Disable I2C interrupt and clear corresponding NVIC bit */
	DrvI2C_DisableInt();
	
	/* Close I2C */
	DrvI2C_Close();

    /* Set I2C I/O */
    DrvGPIO_InitFunction(E_FUNC_I2C);

	DrvI2C_Open(I2C_CLK);

	DrvI2C_SetAddress(0, EDP_I2C_add, 0);
	DrvI2C_SetAddress(1, EDP_I2C_add, 0);
	DrvI2C_SetAddress(2, EDP_I2C_add, 0);
	DrvI2C_SetAddress(3, EDP_I2C_add, 0);

	/* Install I2C call back function for write data to slave */
	DrvI2C_InstallCallback(I2CFUNC, I2C_Callback_Tx);
	/* Enable I2C interrupt and set corresponding NVIC bit */
	DrvI2C_EnableInt();
}
void I2c_Normal_init(void )
{

}
/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Tx Callback Function									                    		               */
/*---------------------------------------------------------------------------------------------------------*/
void I2C_Callback_Tx(uint32_t status)
{
	if (status == 0x08)						/* START has been transmitted */
	{
		DrvI2C_WriteData(EDP_I2C_add<<1);
		DrvI2C_Ctrl(0, 0, 1, 0);
	}	
	else if (status == 0x18)				/* SLA+W has been transmitted and ACK has been received */
	{
		DrvI2C_WriteData(EDP_data[EDP_data_p++]);
		DrvI2C_Ctrl(0, 0, 1, 0);		
	}
	else if (status == 0x20)				/* SLA+W has been transmitted and NACK has been received */
	{	
		I2C_err = WNACK;	
		DrvI2C_Ctrl(0, 1, 1, 0);
	}	
	else if (status == 0x28)				/* DATA has been transmitted and ACK has been received */
	{
		if(EDP_data_p >= Commands)
		{
			EDP_data_p = 0;
			EDP_trans_flag =1;
			DrvI2C_Ctrl(0, 1, 1, 0);
		}else
		{
			if(!(EDP_data_p%2))
			{
//				 DrvI2C_WriteData(EDP_data[EDP_data_p++]);
				 DrvI2C_Ctrl(1, 1, 1, 0);
//				 DrvI2C_Ctrl(1, 0, 1, 0);
			}else
			{
				 DrvI2C_WriteData(EDP_data[EDP_data_p++]);
				 IO_config_delay(1000);
				 DrvI2C_Ctrl(0, 0, 1, 0);	 				 	
			}
		}				
	}
	else								/* DATA has been transmitted and NACK has been received */
	{
		I2C_err = WNACK;
		DrvI2C_WriteData(EDP_data[EDP_data_p++]);
		DrvI2C_Ctrl(1, 1, 1, 0);
		//printf("Status 0x%x is NOT processed\n", status);
	}		
}



void I2c_init_read(void )
{
	/* Disable I2C interrupt and clear corresponding NVIC bit */
	DrvI2C_DisableInt();
	
	/* Close I2C */
	DrvI2C_Close();

    /* Set I2C I/O */
    DrvGPIO_InitFunction(E_FUNC_I2C);

	DrvI2C_Open(I2C_CLK);

	DrvI2C_SetAddress(0, EDP_I2C_add, 0);
	DrvI2C_SetAddress(1, EDP_I2C_add, 0);
	DrvI2C_SetAddress(2, EDP_I2C_add, 0);
	DrvI2C_SetAddress(3, EDP_I2C_add, 0);

	/* Install I2C call back function for write data to slave */
	DrvI2C_InstallCallback(I2CFUNC, I2C_Callback_Rx);
	/* Enable I2C interrupt and set corresponding NVIC bit */
	DrvI2C_EnableInt();
}

/*---------------------------------------------------------------------------------------------------------*/
/*  I2C Rx Callback Function									                  		                   */
/*---------------------------------------------------------------------------------------------------------*/
unsigned char I2C_Callback_Rx(uint32_t status)
{
	if (status == 0x08)					   	/* START has been transmitted and prepare SLA+W */
	{
		DrvI2C_WriteData(EDP_I2C_add<<1);
		DrvI2C_Ctrl(0, 0, 1, 0);
	}	
	else if (status == 0x18)				/* SLA+W has been transmitted and ACK has been received */
	{
		DrvI2C_WriteData(EDP_I2C_red);
		DrvI2C_Ctrl(0, 0, 1, 0);
	}
	else if (status == 0x20)				/* SLA+W has been transmitted and NACK has been received */
	{
		I2C_err = RNACK;	
		DrvI2C_Ctrl(0, 1, 1, 0);
	}
	else if (status == 0x28)				/* DATA has been transmitted and ACK has been received */
	{
			DrvI2C_Ctrl(1, 0, 1, 0);		
	}
	else if (status == 0x10)				/* Repeat START has been transmitted and prepare SLA+R */
	{
		DrvI2C_WriteData(EDP_I2C_add<<1 | 0x01);
		DrvI2C_Ctrl(0, 0, 1, 0);
	}
	else if (status == 0x40)				/* SLA+R has been transmitted and ACK has been received */
	{
		DrvI2C_Ctrl(0, 0, 1, 0);
	}		
	else if (status == 0x58)				/* DATA has been received and NACK has been returned */
	{
		EDP_read_data = DrvI2C_ReadData();
		DrvI2C_Ctrl(0, 1, 1, 0);
		EDP_read_flag = 1;
	}
	else
	{
		EDP_read_flag = 1;
//		printf("Status 0x%x is NOT processed\n", status);
	}
	return EDP_read_data;			
}
//void EDP_config( int delay )
//{
//	int i=0;
// 	I2c_init();
//	DrvGPIO_ClrBit(EDP_RSET_IO);
//	IO_config_delay(100000);
//	IO_config_delay(100000);
//	DrvGPIO_SetBit(EDP_RSET_IO);
//	IO_config_delay(1000);
//	DrvI2C_Ctrl(1, 0, 0, 0);
//
//	for(i=0;i<0xff;i++)
//	{
//		IO_config_delay(0xffff);
//	}
//}
//void EDP_delay()
//{
//	int i=0;
//	for(i=0;i<0xff;i++)
//	{
//		IO_config_delay(0xffff);
//	}
//}
uint8_t readonebyte(uint8_t per_add,uint32_t address)
{
	uint8_t flash_data,time=0;
	uint16_t Break=0;
	DrvI2C_Open(I2C_CLK);
	/* send i2c start */
	DrvI2C_Ctrl( 1, 0, 0, 0);  //set start
	
	while (I2C->CON.SI == 0);  //poll si flag
	/* send slave address and write bit */
	flash_data=I2C->DATA = (per_add<<1) & 0xff;
	DrvI2C_Ctrl(0, 0, 1, 0);  //clr si
	while( I2C->CON.SI == 0 );  //poll si flag
	/* send high byte of  address */
//	I2C->DATA = (address>>8)&0xff;
//	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si
//	while( I2C->CON.SI == 0 );  //poll si flag
	/* send low byte of  address */
	flash_data=I2C->DATA = address&0xff;
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si
	while( I2C->CON.SI == 0 ); 
	/* send repeated start */
	DrvI2C_Ctrl( 1, 0, 1, 0);  //clr si and send start
	while( I2C->CON.SI == 0 );  //poll si flag
	/* send slave address and read bit */
	flash_data=I2C->DATA = ((per_add<<1) & 0xff) |0x01 ;
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si
	while( I2C->CON.SI == 0 );  //poll si flag
	/* get data from specified address */
	flash_data=I2C->DATA = 0X00;
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si and set ack
	while( I2C->CON.SI == 0 )
	 {if(Break++>0x2fff)break;};  //poll si flag
	flash_data = I2C->DATA;
	/* send i2c stop */
	DrvI2C_Ctrl( 0, 1, 1, 0);    //clr si and set stop
	DrvI2C_Close();
	return flash_data;

}

void Write_one_byte(uint8_t per_add, uint32_t address, uint8_t data)
{
    DrvI2C_Open(I2C_CLK);
	DrvI2C_Ctrl(1, 0, 0, 0);  //set start
	while (I2C->CON.SI == 0);
	/* send slave address and write bit */
	I2C->DATA = per_add<<1;  //send write command
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si flag
	while( I2C->CON.SI == 0 );  //poll si flag
	/* send low byte of  address */
	I2C->DATA = (address)&0XFF;
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si
	while( I2C->CON.SI == 0 );  //poll si flag
	/* send data, data = 0x55 here */
	I2C->DATA = data; 
	DrvI2C_Ctrl( 0, 0, 1, 0);  //clr si
	while( I2C->CON.SI == 0 );  //poll si flag
	/* send i2c stop */
	DrvI2C_Ctrl(0, 1, 1, 0);  //send stop
	DrvI2C_Close();
}


void Init_MMA8452(void)
{
//	printf("REG_2A:%x\r\n",readonebyte(MMA8452_I2C_add,0x2A));
	Write_one_byte(MMA8452_I2C_add, 0x2A, 0x01);
	Write_one_byte(MMA8452_I2C_add, 0x2B, 0x02);
//	IO_config_delay(100000);
	printf("REG_2A:%x\r\n",readonebyte(MMA8452_I2C_add,0x2A));
    printf("REG_2B:%x\r\n",readonebyte(MMA8452_I2C_add,0x2B));

}
void MMA8452_SHOW(void)
{
	uint16_t x,y,z;
	x = (readonebyte(MMA8452_I2C_add,0x01)<<8) | (readonebyte(MMA8452_I2C_add,0x02)>>4);
	y = (readonebyte(MMA8452_I2C_add,0x03)<<8) | (readonebyte(MMA8452_I2C_add,0x04)>>4);
	z = (readonebyte(MMA8452_I2C_add,0x05)<<8) | (readonebyte(MMA8452_I2C_add,0x06)>>4);
	printf("x:%x, y:%x, z:%x\r\n",x,y,z);
	IO_config_delay(3000000);	
}



