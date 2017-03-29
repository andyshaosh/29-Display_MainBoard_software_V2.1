#include "flash.h"


  /* Erase the FLASH pages */
/*int FLASH_Erase_Sector(unsigned int StartAddr,unsigned int Length)
{
    __IO uint32_t NbrOfPage;
    uint32_t EraseCounter ;
    volatile int FLASHStatus = E_DRVFMC_ERR_ISP_FAIL;
    
    NbrOfPage = Length / FLASH_PAGE_SIZE;
    
    for(EraseCounter = 0; (EraseCounter < NbrOfPage) && (FLASHStatus == 0); EraseCounter++)
    {
        FLASHStatus = DrvFMC_Erase(StartAddr + (FLASH_PAGE_SIZE * EraseCounter));
    }
    
    return FLASHStatus;
}	*/

int FLASH_Write_Word(unsigned int Address,unsigned int Data)
{
    volatile int FLASHStatus;
    
    FLASHStatus = DrvFMC_Write(Address, Data);
    
    return FLASHStatus;
}
	
unsigned int FLASH_Read_Word(unsigned int Address)
{
	unsigned int Data;
    
	DrvFMC_Read(Address, &Data);
	
	return Data;
}
