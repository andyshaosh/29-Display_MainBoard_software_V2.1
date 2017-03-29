/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/
#include "M051Series.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvSPI.h"
#include "Driver\DrvGPIO.h"
#include "LCD_Driver.h"

extern  SPI_T * SPI_PORT[2] = {SPI0, SPI1};
extern  char Ascii[];

void Initial_pannel(void)
{
    DrvGPIO_InitFunction(E_FUNC_SPI0);
    DrvSPI_Open(eDRVSPI_PORT0, eDRVSPI_MASTER, eDRVSPI_TYPE5, 9);
    DrvSPI_SetClockFreq(eDRVSPI_PORT0, 12000000, 0);

    // Set BR
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0xEB;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;

    // Set PM
    //outp32(SPI3_Tx0, 0x81);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0x81;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0xa0;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;

    //outp32(SPI3_Tx0, 0xC0);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0xc0;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;

    // Set Display Enable
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0XAF;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;
}

//*******************************
//this function to wrtie data to panel
//*******************************
void WriteData(unsigned char data)
{
    // Write Data
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;    //chip select
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0x100 | data;      //write data
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);   //check data out?
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;
}

//*******************************
//this function to initial start address
//*******************************
void SetPACA(unsigned char PA, unsigned char CA)
{
    // Set PA
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0xB0 | PA;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);       //check data out?
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;

    // Set CA MSB
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0x10 | (CA >> 4) & 0xF;
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);        //check data out?
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;

    // Set CA LSB
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 1;
    SPI_PORT[eDRVSPI_PORT0]->TX[0] = 0x00 | (CA & 0xF);
    SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY = 1;
    while (SPI_PORT[eDRVSPI_PORT0]->CNTRL.GO_BUSY == 1);        //check data out?
    SPI_PORT[eDRVSPI_PORT0]->SSR.SSR = 0;
}


void Show_Word(unsigned char x, unsigned char y, unsigned char ascii_word)
{
    int i = 0, k = 0;
    unsigned char temp;
    k = (ascii_word - 32) * 16;

    for (i = 0;i < 8;i++)
    {
        SetPACA((x*2), (129 - (y*8) - i));
        temp = Ascii[k+i];
        WriteData(temp);
    }

    for (i = 0;i < 8;i++)
    {
        SetPACA((x*2) + 1, (129 - (y*8) - i));
        temp = Ascii[k+i+8];
        WriteData(temp);
    }
}

void TurnOnBackgroundLCD(void)
{
    PORT1->DOUT &= 0xFFFD;
}
void TurnOffBackgroundLCD(void)
{
    PORT1->DOUT |= 0x0002;
}

void print_lcd(unsigned char line, char *str)
{
    int i = 0;
    do
    {
        Show_Word(line, i, *str++);
        i++;
        if (i > 15)
            break;
    }
    while (*str != '\0');
}



void clr_all_pannal(void)
{
    int i = 0;
    /*CLEAR ALL PANNAL*/
    SetPACA(0x0, 0x0);

    for (i = 0; i < 132 *8; i++)
    {
        WriteData(0x00);
    }
    WriteData(0x0f);
}

