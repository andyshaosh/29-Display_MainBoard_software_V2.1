#ifndef __FLASH_H__
#define __FLASH_H__

#include <stdio.h>
#include <M051Series.h>


#include "DrvUART.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "DrvFMC.h"

//#define 	FLASH_PAGE_SIZE		 512

//extern int FLASH_Erase_Sector(unsigned int StartAddr,unsigned int Length);
extern int FLASH_Write_Word(unsigned int Address,unsigned int Data);
extern unsigned int FLASH_Read_Word(unsigned int Address);

#endif
