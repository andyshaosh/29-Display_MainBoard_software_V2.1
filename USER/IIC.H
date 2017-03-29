#ifndef _IIC_H_
#define _IIC_H_

//#include "global.h"
//#include "DrvSYS.h"

#define WNACK 				1
#define RNACK 				1

#define I2C_CLK			1
#define EDP_I2C_add         0x0
//#define Address_I2C_P13HDX412BD		0X50
#define MMA8452_I2C_add     0x1D


unsigned char I2C_err = 0;
unsigned char EDP_data_p=0;
unsigned char EDP_trans_flag=0;
unsigned char EDP_read_flag=0; 
unsigned char EDP_read_data=0;
//const unsigned char EDP_I2C_add=0x70;
/*const*/ unsigned char EDP_I2C_red=0x2c; 
const unsigned char Commands = 44;   
const unsigned char EDP_data[Commands]={0x09,0x01,0x4b,0x04,0x11,0x20,0x13,0x73,0x14,0x07,
										0x15,0x80,0x16,0x04,0x17,0x58,0x19,0x1d,0x1a,0x04,
										0x1b,0x38,0x1c,0x00,0x1d,0x0A,0x1e,0x01,0x1f,0x02,
										0x35,0xc1,0x3e,0x16,0x0c,0x00,0x30,0xb0,0x30,0xb1,  
										0x00,0x0a,0x09,0x00};
void IO_config_delay(unsigned int uSec0268);
void I2c_init(void );
void I2C_Callback_Tx(uint32_t status) ;
unsigned char I2C_Callback_Rx(uint32_t status);
uint8_t readonebyte(uint8_t per_add,uint32_t address);
void EDP_delay();
void Init_MMA8452();
void MMA8452_SHOW();

#endif