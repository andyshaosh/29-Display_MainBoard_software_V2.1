/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include "M051Series.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvI2C.h"
#include "Driver\DrvSYS.h"
#include "EEPROM_24LC64.h"

void Write_24LC64(uint32_t address, uint8_t data)
{
    uint32_t i;
    SystemCoreClock = DrvSYS_GetHCLKFreq();
    //Open I2C1 and set clock = 50Kbps
    DrvI2C_Open(100000);

    //send i2c start
    DrvI2C_Ctrl(1, 0, 0, 0);    //set start
    while (I2C->CON.SI == 0);           //poll si flag
    //send writer command
    I2C->DATA = 0XA0;                   //send writer command
    DrvI2C_Ctrl(0, 0, 1, 0); //clr si flag
    while (I2C->CON.SI == 0);            //poll si flag
    //send address high
    I2C->DATA = (address >> 8) & 0XFF;
    DrvI2C_Ctrl(0, 0, 1, 1); //clr si and set ack
    while (I2C->CON.SI == 0);           //poll si flag
    //send address low
    I2C->DATA = address & 0XFF;
    DrvI2C_Ctrl(0, 0, 1, 1); //clr si and set ack
    while (I2C->CON.SI == 0);           //poll si flag
    //send data
    I2C->DATA = data;                   //write data to
    DrvI2C_Ctrl(0, 0, 1, 1); //clr si and set ack
    while (I2C->CON.SI == 0);           //poll si flag
    //send i2c stop
    DrvI2C_Ctrl(0, 1, 1, 0); //send stop
    while (I2C->CON.STO == 1);
    DrvI2C_Close();

    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
    for (i = 0;i < 6000;i++);
}

uint8_t Read_24LC64(uint32_t address)
{

    uint8_t TEMP;
    //Open I2C1 and set clock = 50Kbps
    SystemCoreClock = DrvSYS_GetHCLKFreq();
    DrvI2C_Open(100000);
    //send i2c start
    DrvI2C_Ctrl(1, 0, 1, 0);        //set start
    while (I2C->CON.SI == 0);               //poll si flag

    //send writer command
    I2C->DATA = 0XA0;
    DrvI2C_Ctrl(0, 0, 1, 0);       //clr si
    while (I2C->CON.SI == 0);               //poll si flag

    //send address high
    I2C->DATA = (address >> 8) & 0XFF;
    DrvI2C_Ctrl(0, 0, 1, 1);    //clr si and set ack
    while (I2C->CON.SI == 0);               //poll si flag

    //send address low
    I2C->DATA = address & 0XFF;
    DrvI2C_Ctrl(0, 0, 1, 0);    //clr si    and set ack
    while (I2C->CON.SI == 0);               //poll si flag


    DrvI2C_Ctrl(0, 1, 1, 0); //send stop
    while (I2C->CON.STO == 1);


    //send i2c start
    DrvI2C_Ctrl(1, 0, 1, 0);        //set start
    while (I2C->CON.SI == 0);               //poll si flag

    //send start flag
    //DrvI2C_Ctrl(1, 0, 1, 0);    //clr si and send start
    //while( I2C->CON.SI == 0 );               //poll si flag

    //send read command
    I2C->DATA = 0XA1;
    DrvI2C_Ctrl(0, 0, 1, 1);    //clr si
    while (I2C->CON.SI == 0);               //poll si flag

    //resive data
    I2C->DATA = 0XFF;
    DrvI2C_Ctrl(0, 0, 1, 0);    //clr si
    while (I2C->CON.SI == 0);               //poll si flag
    TEMP = I2C->DATA;
    //send i2c stop
    DrvI2C_Ctrl(0, 1, 1, 0);    //clr si and set stop
    while (I2C->CON.STO == 1);
    DrvI2C_Close();


    return TEMP;
}

