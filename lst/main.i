#line 1 "USER\\main.c"
 
 
 
 
 

 
 
 
#line 1 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdio.h"
 
 
 





 






 









#line 34 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdio.h"


  
  typedef unsigned int size_t;    








 
 

 
  typedef struct __va_list __va_list;





   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 125 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 
extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 944 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdio.h"



 
#line 11 "USER\\main.c"
#line 1 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdint.h"
 
 





 









#line 25 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 196 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdint.h"

     







     










     











#line 260 "D:\\Program Files\\Keil\\ARM\\RV31\\INC\\stdint.h"



 


#line 12 "USER\\main.c"
#line 1 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"
 
 
 
 
 









 
 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  HardFault_IRQn		      = -13,     
  SVCall_IRQn                 = -5,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  BOD_IRQn                  = 0,
  WDT_IRQn                  = 1,
  EINT0_IRQn                = 2,
  EINT1_IRQn                = 3,
  GPIO_P0P1_IRQn            = 4,
  GPIO_P2P3P4_IRQn          = 5,
  PWMA_IRQn                 = 6,
  PWMB_IRQn                 = 7,
  TMR0_IRQn                 = 8,
  TMR1_IRQn                 = 9,
  TMR2_IRQn                 = 10,
  TMR3_IRQn                 = 11,
  UART0_IRQn                = 12,
  UART1_IRQn                = 13,
  SPI0_IRQn                 = 14,
  SPI1_IRQn                 = 15,
  I2C0_IRQn                 = 18,
  I2C1_IRQn                 = 19,
  CAN0_IRQn                 = 20,
  CAN1_IRQn                 = 21,
  SD_IRQn                   = 22,
  USBD_IRQn                 = 23,
  PS2_IRQn                  = 24,
  ACMP_IRQn                 = 25,
  PDMA_IRQn                 = 26,
  I2S_IRQn                  = 27,
  PWRWU_IRQn                = 28,
  ADC_IRQn                  = 29,
  DAC_IRQn                  = 30,
  RTC_IRQn                  = 31
         
                                         
} IRQn_Type;






 

 





#line 1 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"
 




















 











 








 











#line 56 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"

















 

#line 82 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[1];                       
       uint32_t RESERVED0[31];
  volatile uint32_t ICER[1];                       
       uint32_t RSERVED1[31];
  volatile uint32_t ISPR[1];                       
       uint32_t RESERVED2[31];
  volatile uint32_t ICPR[1];                       
       uint32_t RESERVED3[31];
       uint32_t RESERVED4[64];
  volatile uint32_t IPR[8];                        
}  NVIC_Type;
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
       uint32_t RESERVED0;                                      
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
       uint32_t RESERVED1;                                      
  volatile uint32_t SHP[2];                        
  volatile uint32_t SHCSR;                         
       uint32_t RESERVED2[2];                                   
  volatile uint32_t DFSR;                          
} SCB_Type;                                                

 















 



























 















 









 






 



 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 

































 






 








   


 











   




 





#line 377 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"


 


 




#line 395 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"


 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 500 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"








 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 770 ".\\Library\\CM0\\CoreSupport\\core_cm0.h"







 
 

 

 
 












 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[0] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[0] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] = (((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) | 
        (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 )); }
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] = (((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] & ~(0xFF << ( (((uint32_t)(IRQn) ) & 0x03) * 8 ))) |
        (((priority << (8 - 2)) & 0xFF) << ( (((uint32_t)(IRQn) ) & 0x03) * 8 )); }
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)((((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[( ((((uint32_t)(IRQn) & 0x0F)-8) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) >> (8 - 2)));  }  
  else {
    return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IPR[( ((uint32_t)(IRQn) >> 2) )] >> ( (((uint32_t)(IRQn) ) & 0x03) * 8 ) ) >> (8 - 2)));  }  
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<2) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (1ul << 2));
  __dsb(0);                                                                                            
  while(1);                                                                             
}

   





   



 
#line 75 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"
#line 1 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\system_M051Series.h"
 
 
 
 
 









 





extern uint32_t SystemCoreClock;                    
extern uint32_t CyclesPerUs;                        









 
extern void SystemInit(void);










 
extern void SystemCoreClockUpdate (void);







#line 76 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"
#line 1 ".\\Library\\Include\\System\\SysInfra.h"
 
 
 
 
 





 
 
 
#line 1 ".\\Library\\Include\\System\\ModuleID.h"
 
 
 
 
 





typedef enum
{
	 
	
	 
	MODULE_ID_DRVPROTECT		= 0,		 

	MODULE_ID_DRVADC			= 2,		 
	MODULE_ID_DRVAIC			= 4,		 
	MODULE_ID_DRVAPU			= 6,		 
	MODULE_ID_DRVAUDIOADC		= 8,		 
	MODULE_ID_DRVCACHE			= 10,		 
	MODULE_ID_DRVCAN			= 11,		 
	MODULE_ID_DRVEBI			= 12,		 
	MODULE_ID_DRVEDMA			= 13,		 
	MODULE_ID_DRVGDMA			= 14,		 
	MODULE_ID_DRVFSC			= 15,		 
	MODULE_ID_DRVGE				= 16,		 
	MODULE_ID_DRVFMC			= 17,		 
	MODULE_ID_DRVGPIO			= 18,		 
	
	MODULE_ID_DRVGPU			= 20,		 
	MODULE_ID_DRVI2C			= 22,		 
	MODULE_ID_DRVI2S			= 24,		 
	MODULE_ID_DRVI2SM			= 26,		 
	MODULE_ID_DRVMPU			= 28,		 
	MODULE_ID_DRVNAND			= 30,		 
	MODULE_ID_DRVNOR			= 32,		 
	MODULE_ID_DRVPDMA     		= 33,        
	MODULE_ID_DRVPWM			= 34,		 
	MODULE_ID_DRVPS2			= 35,		 
	MODULE_ID_DRVRTC			= 36,		 
	MODULE_ID_DRVSDCARD			= 38,		 
	MODULE_ID_DRVSIO			= 39,		 

	MODULE_ID_DRVSPI			= 40,		 
	MODULE_ID_DRVSPIMS			= 41,		 
	MODULE_ID_DRVSPIFLASH		= 42,		 
	MODULE_ID_DRVSPIM			= 43,		 
	MODULE_ID_DRVSYS			= 44,		 
	MODULE_ID_DRVSPU			= 45,		 
	MODULE_ID_DRVTIMER			= 46,		 
	MODULE_ID_DRVUART			= 48,		 
	MODULE_ID_DRVUSB			= 50,		 
	MODULE_ID_DRVUSBH			= 52,		 
	MODULE_ID_DRVVDMA			= 54,		 
	MODULE_ID_DRVVIDEOIN		= 56,		 
	MODULE_ID_DRVVPOST			= 58,		 

	MODULE_ID_DRVVRAM			= 60,		 
	MODULE_ID_DRVW55U02			= 62,		 
	MODULE_ID_DRVI2CH			= 64,		 
	MODULE_ID_DRVWDT			= 66,		 
	MODULE_ID_DRVJPEG			= 68,		 
	
	MODULE_ID_DRVZEROG			= 70,		 
	MODULE_ID_DRVSI2C			= 71,		 

	 
	MODULE_ID_AEC				= 81,		 
	MODULE_ID_BEATDET			= 82,		 
	MODULE_ID_SNDEFF			= 83,		 
	MODULE_ID_AUDIOSYN			= 84,		 
	MODULE_ID_G726ADPCM			= 85,		 
	MODULE_ID_IMAADPCM			= 86,		 
	MODULE_ID_MP3DEC			= 88,		 
	MODULE_ID_PITCHCHANGE		= 90,		 
	MODULE_ID_WAVFILEUTIL		= 92,		 
	MODULE_ID_WMADEC			= 96,		 
	MODULE_ID_WMADECDRM			= 98,		 
	MODULE_ID_AUDIOCTRL			= 100,		 
	MODULE_ID_EQ				= 106,		 
	MODULE_ID_OGGDEC			= 110,		 
	MODULE_ID_MP3ENC			= 112,		 
	MODULE_ID_UADEC				= 114,		 
	MODULE_ID_ULSPEECHDEC		= 115,		 
	MODULE_ID_USPEECHDEC		= 116,		 
	MODULE_ID_SPEECHRECOG		= 118,		 

	 
	MODULE_ID_FS				= 120,		 
	
	 
	MODULE_ID_FL				= 128,		 
	
	 
	MODULE_ID_KEYPAD			= 130,		 
	MODULE_ID_LWIP				= 132,		 
	MODULE_ID_WLANMGR			= 134,		 
	MODULE_ID_HTTPD				= 136,		 
	MODULE_ID_VIRTUALCOM		= 139,		 

	 
	MODULE_ID_GFXRESLDR			= 140,		 
	MODULE_ID_GFXLIB			= 141,		 
	MODULE_ID_IMGPROC			= 142,		 
	MODULE_ID_JPEG				= 144,		 
	MODULE_ID_PNGDEC			= 146,		 
	MODULE_ID_BARCODE2D			= 148,		 	 
	MODULE_ID_PTNRECOG			= 150,		 
	MODULE_ID_MOTIONDET			= 152,		 
	
	 
	MODULE_ID_STORIF			= 160,		 
	MODULE_ID_SDCARD			= 161,		 
	MODULE_ID_SYSNAND			= 162,		 
	MODULE_ID_SPIFLASH			= 163,		 
	MODULE_ID_WTRIF				= 164,		 
	MODULE_ID_NORFLASH			= 165,		 
	MODULE_ID_SYSNANDLITE		= 166,		 
	
	 
	MODULE_ID_INTMGR			= 180,		 
	MODULE_ID_BLKLDR			= 181,		 
	MODULE_ID_MEMMGR			= 182,		 
	MODULE_ID_EVTMGR			= 183,		 
	MODULE_ID_PROF				= 184,		 
	MODULE_ID_PROGLDR			= 186,		 
	MODULE_ID_SYSINFRA			= 188,		 
	MODULE_ID_TIMERCTRL			= 190,		 
	MODULE_ID_TIMEUTIL			= 192,		 
	MODULE_ID_CONPROGLDR		= 194,		 
	
	 
	MODULE_ID_USBCOREH			= 78,		 
	MODULE_ID_HID				= 220,		 
	MODULE_ID_MASSSTOR			= 222,		 
	MODULE_ID_MASSSTORHID		= 224,		 
	MODULE_ID_MASSSTORLITE		= 226,		 
	MODULE_ID_MTP				= 230,		 
	MODULE_ID_USBINFRA			= 232,		 
	MODULE_ID_UAC				= 234,		 
	MODULE_ID_UAVC				= 236,		 
	MODULE_ID_UVC				= 238,		 
	MODULE_ID_MASSSTORH			= 252,		 
	MODULE_ID_HIDH				= 254,		 

	 
	MODULE_ID_MSDRMPD			= 228,		 
	
	 
	MODULE_ID_AVICODEC			= 240,		 
	MODULE_ID_MJPEG				= 242,		 
	MODULE_ID_WIVICORE			= 244,		 
	MODULE_ID_WIVI				= 246,		 	
	MODULE_ID_AVCTRL			= 248,		 
	MODULE_ID_AVIUTIL			= 250,		 
	
	 
	MODULE_ID_WTCHAN			= 168,		 
	MODULE_ID_WTCMDSERV			= 170,		 
	MODULE_ID_WTDISPLAY			= 172,		 
	MODULE_ID_WTMEDIA			= 174,		 
	MODULE_ID_WTSYS				= 176,		 
	MODULE_ID_WTTRANS			= 178,		 
	
	
} E_SYSINFRA_MODULE_ID;


#line 15 ".\\Library\\Include\\System\\SysInfra.h"
#line 16 ".\\Library\\Include\\System\\SysInfra.h"
#line 17 ".\\Library\\Include\\System\\SysInfra.h"






 
 
 





 
 
 
 



 



 

 

 


 






 
 
 
 
















#line 77 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"










 
extern void SystemInit (void);				  


 
 
 

 
typedef struct
{
    volatile uint32_t 	PMD0:2;
    volatile uint32_t 	PMD1:2;
    volatile uint32_t 	PMD2:2;
    volatile uint32_t 	PMD3:2;
    volatile uint32_t 	PMD4:2;
    volatile uint32_t 	PMD5:2;
    volatile uint32_t 	PMD6:2;
    volatile uint32_t 	PMD7:2;
    volatile const  uint32_t  	RESERVE:16;    
} GPIO_PMD_T;

typedef volatile uint32_t GPIO_SCH_T;

typedef volatile uint32_t GPIO_DOUT_T;

typedef volatile uint32_t GPIO_DMASK_T;

typedef volatile uint32_t GPIO_PIN_T;

typedef volatile uint32_t GPIO_DBEN_T;

typedef volatile uint32_t GPIO_IMD_T;

typedef volatile uint32_t GPIO_IEN_T;

typedef volatile uint32_t GPIO_ISRC_T;

typedef struct
{
    volatile uint32_t  DBCLKSEL:4;
    volatile uint32_t  DBCLKSRC:1;
    volatile uint32_t  ICLK_ON:1;
    volatile const  uint32_t  RESERVE:26;    
} GPIO_DBNCECON_T;

typedef struct
{
    GPIO_PMD_T      PMD;
    GPIO_SCH_T      SCH;
    GPIO_DOUT_T     DOUT;
    GPIO_DMASK_T    DMASK;
    GPIO_PIN_T      PIN;
    GPIO_DBEN_T     DBEN;
    GPIO_IMD_T      IMD;
    GPIO_IEN_T      IEN;
    GPIO_ISRC_T     ISRC;
} GPIO_T;

 

typedef volatile uint32_t UART_DATA_T;


typedef struct
{
    volatile uint32_t  RDA_IEN:1;
    volatile uint32_t  THRE_IEN:1;
    volatile uint32_t  RLS_IEN:1;
    volatile uint32_t  MODEM_IEN:1;
    volatile uint32_t  RTO_IEN:1;	  
    volatile uint32_t  BUF_ERR_IEN:1;
    volatile uint32_t  WAKE_IEN:1;
    volatile const  uint32_t  RESERVE0:1;
	volatile uint32_t  LIN_RX_BRK_IEN:1;
    volatile const  uint32_t  RESERVE1:2;
    volatile uint32_t  TIME_OUT_EN:1;       
    volatile uint32_t  AUTO_RTS_EN:1;
    volatile uint32_t  AUTO_CTS_EN:1;
    volatile uint32_t  DMA_TX_EN:1;
    volatile uint32_t  DMA_RX_EN:1;
    volatile const  uint32_t  RESERVE2:16;    
    
} UART_IER_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  RFR:1;
    volatile uint32_t  TFR:1;
    volatile const  uint32_t  RESERVE1:1;
    volatile uint32_t  RFITL:4;              
	volatile uint32_t  RX_DIS:1;
    volatile const  uint32_t  RESERVE2:7;
    volatile uint32_t  RTS_TRI_LEV:4;
    volatile const  uint32_t  RESERVE3:12;
} UART_FCR_T;

typedef struct
{
    volatile uint32_t  WLS:2;                
    volatile uint32_t  NSB:1;                
    volatile uint32_t  PBE:1;                
    volatile uint32_t  EPE:1;                
    volatile uint32_t  SPE:1;                
    volatile uint32_t  BCB:1;                
    volatile const  uint32_t  RESERVE:25;
} UART_LCR_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  RTS:1;
    volatile const  uint32_t  RESERVE1:2;
    volatile uint32_t  LBME:1;
    volatile const  uint32_t  RESERVE2:4;
    volatile uint32_t  LEV_RTS:1;
    volatile const  uint32_t  RESERVE3:3;
    volatile const  uint32_t  RTS_ST:1;                
    volatile const  uint32_t  RESERVE4:18;
} UART_MCR_T;

typedef struct
{
    volatile uint32_t  DCTSF:1;
    volatile const  uint32_t  RESERVE0:3;
    volatile const  uint32_t  CTS_ST:1;                
    volatile const  uint32_t  RESERVE1:3;
    volatile uint32_t  LEV_CTS:1;
    volatile const  uint32_t  RESERVE2:23;
} UART_MSR_T;

typedef struct
{
    volatile uint32_t  RX_OVER_IF:1;
    volatile const  uint32_t  RESERVE0:2;
	volatile uint32_t  RS485_ADD_DETF:1;
    volatile uint32_t  PEF:1;
    volatile uint32_t  FEF:1;
    volatile uint32_t  BIF:1;
    volatile const  uint32_t  RESERVE1:1;
    volatile const  uint32_t  RX_POINTER:6;
    volatile const  uint32_t  RX_EMPTY:1;
    volatile const  uint32_t  RX_FULL:1;
    volatile const  uint32_t  TX_POINTER:6;
    volatile const  uint32_t  TX_EMPTY:1;
    volatile const  uint32_t  TX_FULL:1;
    volatile uint32_t  TX_OVER_IF:1;
    volatile const  uint32_t  RESERVE2:3;
    volatile const  uint32_t  TE_FLAG:1;                 
    volatile const  uint32_t  RESERVE3:3;
} UART_FSR_T;

typedef struct
{
    volatile uint32_t  RDA_IF:1;
    volatile uint32_t  THRE_IF:1;
    volatile uint32_t  RLS_IF:1;
    volatile uint32_t  MODEM_IF:1;
    volatile uint32_t  TOUT_IF:1;
    volatile uint32_t  BUF_ERR_IF:1;
    volatile const  uint32_t  RESERVE0:2;

    volatile uint32_t  RDA_INT:1;
    volatile uint32_t  THRE_INT:1;
    volatile uint32_t  RLS_INT:1;
    volatile uint32_t  MODEM_INT:1;
    volatile uint32_t  TOUT_INT:1;
    volatile uint32_t  BUF_ERR_INT:1;
    volatile const  uint32_t  RESERVE1:18;
} UART_ISR_T;



typedef struct
{
   volatile uint32_t  TOIC:7;
   volatile const  uint32_t  RESERVE0:1;
   volatile uint32_t  DLY:8;
   volatile const  uint32_t  RESERVE1:16;

}UART_TOR_T;


typedef struct
{
    volatile uint32_t  BRD:16;
    volatile const  uint32_t  RESERVE0:8;
    volatile uint32_t  DIVIDER_X:4;
    volatile uint32_t  DIV_X_ONE:1;            
    volatile uint32_t  DIV_X_EN:1;            
    volatile const  uint32_t  RESERVE1:2;
} UART_BAUD_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  TX_SELECT:1;
	volatile const  uint32_t  RESERVE1:3;         
    volatile uint32_t  INV_TX:1;            
    volatile uint32_t  INV_RX:1;
    volatile const  uint32_t  RESERVE2:25;
} UART_IRCR_T;


typedef struct
{
	volatile const  uint32_t  RESERVE0:8;
    volatile uint32_t  RS485_NMM:1;
	volatile uint32_t  RS485_AAD:1;
	volatile uint32_t  RS485_AUD:1;
	volatile const  uint32_t  RESERVE1:4;
	volatile uint32_t  RS485_ADD_EN:1;
	volatile const  uint32_t  RESERVE2:8;
	volatile uint32_t  ADDR_MATCH:8;
} UART_ALTCON_T;

typedef struct
{
    volatile uint32_t  FUN_SEL:2;
	volatile const  uint32_t  RESERVE0:30;

} UART_FUNSEL_T;

typedef struct
{
    UART_DATA_T     DATA;
    UART_IER_T      IER;
    UART_FCR_T      FCR;
    UART_LCR_T      LCR;
    UART_MCR_T      MCR;
    UART_MSR_T      MSR;
    UART_FSR_T      FSR;
    UART_ISR_T      ISR;
    UART_TOR_T      TOR;
    UART_BAUD_T     BAUD;
    UART_IRCR_T     IRCR;   
    UART_ALTCON_T   ALTCON;    
	UART_FUNSEL_T   FUNSEL;    
} UART_T;

 
typedef struct
{
    volatile uint32_t  PRESCALE:8;
    volatile const  uint32_t  RESERVE0:8;
    volatile uint32_t  TDR_EN:1;
    volatile const  uint32_t  RESERVE1:8;
    volatile uint32_t  CACT:1;
    volatile uint32_t  CRST:1;
    volatile uint32_t  MODE:2;
    volatile uint32_t  IE:1;
    volatile uint32_t  CEN:1;
    volatile uint32_t  nDBGACK_EN:1;
} TIMER_TCSR_T;

typedef volatile uint32_t TIMER_TCMPR_T;

typedef volatile uint32_t TIMER_TDR_T;

typedef struct
{
    volatile uint32_t  TIF:1;
    volatile const  uint32_t  RESERVE:31;
} TIMER_TISR_T;

typedef struct
{
    TIMER_TCSR_T     TCSR;
    TIMER_TCMPR_T    TCMPR;
    TIMER_TISR_T     TISR;    
    TIMER_TDR_T      TDR;
 } TIMER_T;

 
typedef struct
{
    volatile uint32_t  WTR:1;
	volatile uint32_t  WTRE:1;
	volatile uint32_t  WTRF:1;
	volatile uint32_t  WTIF:1;
	volatile uint32_t  WTWKE:1;
	volatile const  uint32_t  WTWKF:1;
	volatile uint32_t  WTIE:1;
	volatile uint32_t  WTE:1;
	volatile uint32_t  WTIS:3;
    volatile const  uint32_t  RESERVE1:21;
} WDT_WTCR_T;

typedef struct
{
    WDT_WTCR_T     WTCR;
    
 } WDT_T;

 
typedef struct
{
    volatile uint32_t  GO_BUSY:1;
    volatile uint32_t  RX_NEG:1;
    volatile uint32_t  TX_NEG:1;
    volatile uint32_t  TX_BIT_LEN:5;
    volatile uint32_t  TX_NUM:2;
    volatile uint32_t  LSB:1;
    volatile uint32_t  CLKP:1;
    volatile uint32_t  SP_CYCLE:4;
    volatile uint32_t  IF:1;
    volatile uint32_t  IE:1;
    volatile uint32_t  SLAVE:1;
    volatile uint32_t  REORDER:2;
    volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  VARCLK_EN:1;
    volatile const  uint32_t  RESERVE1:8;
} SPI_CNTRL_T;

typedef struct
{
    volatile uint32_t  DIVIDER:16;
    volatile uint32_t  DIVIDER2:16;
} SPI_DIVIDER_T;

typedef struct
{
    volatile uint32_t  SSR:1;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  SS_LVL:1;
    volatile uint32_t  AUTOSS:1;
    volatile uint32_t  SS_LTRIG:1;
    volatile uint32_t  LTRIG_FLAG:1;
    volatile const  uint32_t  RESERVE:26;
} SPI_SSR_T;

typedef volatile const  uint32_t   SPI_RX_T;
typedef volatile  uint32_t   SPI_TX_T;

typedef volatile uint32_t SPI_VARCLK_T;

typedef struct
{
    SPI_CNTRL_T     CNTRL;
    SPI_DIVIDER_T   DIVIDER;
    SPI_SSR_T       SSR;
    uint32_t        RESERVE0;
    SPI_RX_T        RX[2];
    uint32_t        RESERVE1;
    uint32_t        RESERVE2;
    SPI_TX_T        TX[2];
    uint32_t        RESERVE3;
    uint32_t        RESERVE4;
    uint32_t        RESERVE5;
    SPI_VARCLK_T    VARCLK;
    uint32_t        RESERVE6;
} SPI_T;

 
typedef struct
{
    volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  AA:1;
    volatile uint32_t  SI:1;
    volatile uint32_t  STO:1;
    volatile uint32_t  STA:1;
    volatile uint32_t  ENSI:1;
   	volatile uint32_t  EI:1;
    volatile const  uint32_t  RESERVE1:24;
} I2C_CON_T;

typedef struct
{
    volatile uint32_t  GC:1;
    volatile uint32_t  ADDR:7;
    volatile const  uint32_t  RESERVE:24;
} I2C_ADDR_T;

typedef volatile uint32_t I2C_DATA_T;

typedef volatile const  uint32_t I2C_STATUS_T;

typedef volatile uint32_t I2C_CLK_T;

typedef struct
{
    volatile uint32_t  TIF:1;
    volatile uint32_t  DIV4:1;
    volatile uint32_t  ENTI:1;
    volatile const  uint32_t  RESERVE:29;
} I2C_TOC_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  ADM:7;
    volatile const  uint32_t  RESERVE1:24;
} I2C_ADRM_T;

typedef struct
{
    I2C_CON_T       CON;
    I2C_ADDR_T      ADDR0;
    I2C_DATA_T      DATA;
    I2C_STATUS_T    STATUS;
    I2C_CLK_T       CLK;
    I2C_TOC_T       TOC;
	I2C_ADDR_T	    ADDR1;
	I2C_ADDR_T	    ADDR2;
	I2C_ADDR_T	    ADDR3;
	I2C_ADRM_T		ADRM0;
	I2C_ADRM_T		ADRM1;
	I2C_ADRM_T		ADRM2;
	I2C_ADRM_T	    ADRM3;        
} I2C_T;

 
typedef struct
{
    volatile uint32_t  RSLT:16;
    volatile uint32_t  OVERRUN:1;
    volatile uint32_t  VALID:1;
    volatile const  uint32_t  RESERVE1:14;
} ADC_ADDR_T;

typedef struct
{
    volatile uint32_t  ADEN:1;
    volatile uint32_t  ADIE:1;
    volatile uint32_t  ADMD:2;
    volatile uint32_t  TRGS:2;
    volatile uint32_t  TRGCOND:2;
    volatile uint32_t  TRGEN:1;
    volatile uint32_t  RESERVE0:1;
    volatile uint32_t  DIFFEN:1;
    volatile uint32_t  ADST:1;
    volatile const  uint32_t  RESERVE1:20;
} ADC_ADCR_T;

typedef struct
{
    volatile uint32_t  CHEN:8;
    volatile uint32_t  PRESEL:2;
    volatile const  uint32_t  RESERVE:22;
} ADC_ADCHER_T;

typedef struct
{
    volatile uint32_t  CMPEN:1;
    volatile uint32_t  CMPIE:1;
    volatile uint32_t  CMPCOND:1;
    volatile uint32_t  CMPCH:3;
    volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  CMPMATCNT:4;
    volatile const  uint32_t  RESERVE1:4;
    volatile uint32_t  CMPD:12;
    volatile const  uint32_t  RESERVE2:4;
} ADC_ADCMPR_T;

typedef struct
{
    volatile uint32_t  ADF:1;
    volatile uint32_t  CMPF0:1;
    volatile uint32_t  CMPF1:1;
    volatile uint32_t  BUSY:1;
    volatile uint32_t  CHANNEL:3;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  VALID:8;
    volatile uint32_t  OVERRUN:8;
    volatile const  uint32_t  RESERVE1:8;
} ADC_ADSR_T;

typedef struct
{
    volatile uint32_t  CALEN:1;
    volatile uint32_t  CALDONE:1;
    volatile const  uint32_t  RESERVE:30;
} ADC_ADCALR_T;

typedef struct
{
    ADC_ADDR_T      ADDR[8];
    ADC_ADCR_T      ADCR;
    ADC_ADCHER_T    ADCHER;
    ADC_ADCMPR_T    ADCMPR[2];
    ADC_ADSR_T      ADSR;
    ADC_ADCALR_T    ADCALR;
} ADC_T;


 
typedef struct
{
    volatile uint32_t  XTL12M_EN:1;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  OSC22M_EN:1;
    volatile uint32_t  OSC10K_EN:1;
    volatile uint32_t  PD_WU_DLY:1;
    volatile uint32_t  PD_WU_INT_EN:1;
    volatile uint32_t  PD_WU_STS:1;
    volatile uint32_t  PWR_DOWN:1;
    volatile uint32_t  PD_WAIT_CPU:1;
    volatile const  uint32_t  RESERVE1:23;
} SYSCLK_PWRCON_T;

typedef struct
{
    
	volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  ISP_EN:1;
	volatile uint32_t  EBI_EN:1;
    volatile const  uint32_t  RESERVE1:28;
} SYSCLK_AHBCLK_T;

typedef struct
{
    volatile uint32_t  WDT_EN:1;
	volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  TMR0_EN:1;
    volatile uint32_t  TMR1_EN:1;
    volatile uint32_t  TMR2_EN:1;
    volatile uint32_t  TMR3_EN:1;
    volatile uint32_t  FDIV_EN:1;
	volatile const  uint32_t  RESERVE1:1;
    volatile uint32_t  I2C_EN:1;
    volatile const  uint32_t  RESERVE2:3;
    volatile uint32_t  SPI0_EN:1;
    volatile uint32_t  SPI1_EN:1;
    volatile const  uint32_t  RESERVE3:2;
    volatile uint32_t  UART0_EN:1;
    volatile uint32_t  UART1_EN:1;
    volatile const  uint32_t  RESERVE4:2;
    volatile uint32_t  PWM01_EN:1;
    volatile uint32_t  PWM23_EN:1;
	volatile uint32_t  PWM45_EN:1;
    volatile uint32_t  PWM67_EN:1;
    volatile const  uint32_t  RESERVE5:4;
    volatile uint32_t  ADC_EN:1;
    volatile const  uint32_t  RESERVE6:3;
} SYSCLK_APBCLK_T;

typedef struct
{
    volatile const  uint32_t  XTL12M_STB:1;
	volatile const  uint32_t  RESERVE0:1;
    volatile const  uint32_t  PLL_STB:1;
	volatile const  uint32_t  OSC10K_STB:1;
	volatile const  uint32_t  OSC22M_STB:1;
    volatile const  uint32_t  RESERVE1:2;
	volatile uint32_t  CLK_SW_FAIL:1;
    volatile const  uint32_t  RESERVE2:24;
} SYSCLK_CLKSTATUS_T;


typedef struct
{
    volatile uint32_t  HCLK_S:3;
    volatile uint32_t  STCLK_S:3;
    volatile const  uint32_t  RESERVE:26;
} SYSCLK_CLKSEL0_T;

typedef struct
{
    volatile uint32_t  WDT_S:2;
    volatile uint32_t  ADC_S:2;
    volatile const  uint32_t  RESERVE1:4;
    volatile uint32_t  TMR0_S:3;
    volatile const  uint32_t  RESERVE2:1;
    volatile uint32_t  TMR1_S:3;
    volatile const  uint32_t  RESERVE3:1;
    volatile uint32_t  TMR2_S:3;
    volatile const  uint32_t  RESERVE4:1;
    volatile uint32_t  TMR3_S:3;
    volatile const  uint32_t  RESERVE5:1;
    volatile uint32_t  UART_S:2;
    volatile const  uint32_t  RESERVE6:2;
	volatile uint32_t  PWM01_S:2;
    volatile uint32_t  PWM23_S:2;
} SYSCLK_CLKSEL1_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:2;
	volatile uint32_t  FRQDIV_S:2;
	volatile uint32_t  PWM45_S:2;
    volatile uint32_t  PWM67_S:2;
    volatile const  uint32_t  RESERVE1:24;
} SYSCLK_CLKSEL2_T;

typedef struct
{
    volatile uint32_t  HCLK_N:4;
    volatile const  uint32_t  RESERVE0:4;
	volatile uint32_t  UART_N:4;
    volatile const  uint32_t  RESERVE1:4;
	volatile uint32_t  ADC_N:8;
    volatile const  uint32_t  RESERVE2:8;
} SYSCLK_CLKDIV_T;

typedef struct
{
    volatile uint32_t  FB_DV:9;
    volatile uint32_t  IN_DV:5;
    volatile uint32_t  OUT_DV:2;
    volatile uint32_t  PD:1;
    volatile uint32_t  BP:1;
    volatile uint32_t  OE:1;
    volatile uint32_t  PLL_SRC:1;
    volatile const  uint32_t  RESERVE:12;
} SYSCLK_PLLCON_T;

typedef struct
{    
    volatile uint32_t  FSEL:4;
	volatile uint32_t  FDIV_EN:1;
    volatile const  uint32_t  RESERVE:27;
} SYSCLK_FRQDIV_T;

typedef struct
{
    SYSCLK_PWRCON_T    PWRCON;
    SYSCLK_AHBCLK_T    AHBCLK;
    SYSCLK_APBCLK_T    APBCLK;
    SYSCLK_CLKSTATUS_T CLKSTATUS;
    SYSCLK_CLKSEL0_T   CLKSEL0;
    SYSCLK_CLKSEL1_T   CLKSEL1;
    SYSCLK_CLKDIV_T    CLKDIV;
    SYSCLK_CLKSEL2_T   CLKSEL2;
	SYSCLK_PLLCON_T    PLLCON;
	SYSCLK_FRQDIV_T    FRQDIV;
} SYSCLK_T;

 
typedef volatile const uint32_t GCR_PDID_T;  

typedef struct
{
	volatile uint32_t  RSTS_POR:1;
	volatile uint32_t  RSTS_RESET:1;
	volatile uint32_t  RSTS_WDT:1;
	volatile uint32_t  RSTS_LVR:1;
	volatile uint32_t  RSTS_BOD:1;
	volatile uint32_t  RSTS_MCU:1;
	volatile const  uint32_t  RESERVE0:1;
	volatile uint32_t  RSTS_CPU:1;    
	volatile const  uint32_t  RESERVE1:24;
} GCR_RSTSRC_T;

typedef struct
{
    volatile uint32_t  CHIP_RST:1;
    volatile uint32_t  CPU_RST:1;
    volatile const  uint32_t  RESERVE0:1;
	volatile uint32_t  EBI_RST:1;
    volatile const  uint32_t  RESERVE1:28;
} GCR_IPRSTC1_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  GPIO_RST:1;
    volatile uint32_t  TMR0_RST:1;
    volatile uint32_t  TMR1_RST:1;
    volatile uint32_t  TMR2_RST:1;
    volatile uint32_t  TMR3_RST:1;
    volatile const  uint32_t  RESERVE1:2;
    volatile uint32_t  I2C_RST:1;
    volatile const  uint32_t  RESERVE2:3;
    volatile uint32_t  SPI0_RST:1;
    volatile uint32_t  SPI1_RST:1;
    volatile const  uint32_t  RESERVE3:2;
	volatile uint32_t  UART0_RST:1;
    volatile uint32_t  UART1_RST:1;
    volatile const  uint32_t  RESERVE4:2;
    volatile uint32_t  PWM03_RST:1;
    volatile uint32_t  PWM47_RST:1;
    volatile const  uint32_t  RESERVE5:6;
    volatile uint32_t  ADC_RST:1;
    volatile const  uint32_t  RESERVE6:3;
} GCR_IPRSTC2_T;

typedef struct
{
    volatile uint32_t  BOD_EN:1;
    volatile uint32_t  BOD_VL:2;
    volatile uint32_t  BOD_RSTEN:1;
    volatile uint32_t  BOD_INTF:1;
    volatile uint32_t  BOD_LPM:1;
    volatile uint32_t  BOD_OUT:1;
	volatile uint32_t  LVR_EN:1;
    volatile const  uint32_t  RESERVE1:24;
} GCR_BODCR_T;

typedef volatile uint32_t GCR_PORCR_T;

typedef struct
{
	volatile uint32_t 	MFP0_AD0_CTS1:1;
	volatile uint32_t 	MFP1_AD1_RTS1:1;
	volatile uint32_t 	MFP2_AD2_CTS0:1;
	volatile uint32_t 	MFP3_AD3_RTS0:1;
	volatile uint32_t 	MFP4_AD4_SS1:1;
	volatile uint32_t 	MFP5_AD5_MOSI1:1;
	volatile uint32_t 	MFP6_AD6_MISO1:1;
	volatile uint32_t 	MFP7_AD7_SCLK1:1;
	volatile uint32_t 	ALT0_AD0_CTS1:1;
	volatile uint32_t 	ALT1_AD1_RTS1:1;
	volatile uint32_t 	ALT2_AD2_CTS0:1;
	volatile uint32_t 	ALT3_AD3_RTS0:1;
	volatile uint32_t 	ALT4_AD4_SS1:1;
	volatile uint32_t 	ALT5_AD5_MOSI1:1;
	volatile uint32_t 	ALT6_AD6_MISO1:1;
	volatile uint32_t 	ALT7_AD7_SCLK1:1;
	volatile uint32_t 	SCHMITT:8;
	volatile const  uint32_t 	RESERVE:8;    
} GCR_P0_MFP_T;

typedef struct
{
	volatile uint32_t 	MFP0_AIN0_T2:1;
	volatile uint32_t 	MFP1_AIN1_T3:1;
	volatile uint32_t 	MFP2_AIN2_RXD1:1;
	volatile uint32_t 	MFP3_AIN3_TXD1:1;
	volatile uint32_t 	MFP4_AIN4_SS0:1;
	volatile uint32_t 	MFP5_AIN5_MOSI0:1;
	volatile uint32_t 	MFP6_AIN6_MISO0:1;
	volatile uint32_t 	MFP7_AIN7_SCLK0:1;
	volatile uint32_t 	ALT0_AIN0_T2:1;
	volatile uint32_t 	ALT1_AIN1_T3:1;
	volatile uint32_t 	ALT2_AIN2_RXD1:1;
	volatile uint32_t 	ALT3_AIN3_TXD1:1;
	volatile uint32_t 	ALT4_AIN4_SS0:1;
	volatile uint32_t 	ALT5_AIN5_MOSI0:1;
	volatile uint32_t 	ALT6_AIN6_MISO0:1;
	volatile uint32_t 	ALT7_AIN7_SCLK0:1;
	volatile uint32_t 	SCHMITT:8;
	volatile const  uint32_t 	RESERVE:8;    
} GCR_P1_MFP_T;

typedef struct
{
	volatile uint32_t 	MFP0_AD8_PWM0:1;
	volatile uint32_t 	MFP1_AD9_PWM1:1;
	volatile uint32_t 	MFP2_AD10_PWM2:1;
	volatile uint32_t 	MFP3_AD11_PWM3:1;
	volatile uint32_t 	MFP4_AD12_PWM4:1;
	volatile uint32_t 	MFP5_AD13_PWM5:1;
	volatile uint32_t 	MFP6_AD14_PWM6:1;
	volatile uint32_t 	MFP7_AD15_PWM7:1;
	volatile uint32_t 	ALT0_AD8_PWM0:1;
	volatile uint32_t 	ALT1_AD9_PWM1:1;
	volatile uint32_t 	ALT2_AD10_PWM2:1;
	volatile uint32_t 	ALT3_AD11_PWM3:1;
	volatile uint32_t 	ALT4_AD12_PWM4:1;
	volatile uint32_t 	ALT5_AD13_PWM5:1;
	volatile uint32_t 	ALT6_AD14_PWM6:1;
	volatile uint32_t 	ALT7_AD15_PWM7:1;
	volatile uint32_t 	SCHMITT:8;
	volatile const  uint32_t 	RESERVE:8;    
} GCR_P2_MFP_T;

typedef struct
{
	volatile uint32_t 	MFP0_RXD0:1;
	volatile uint32_t 	MFP1_TXD0:1;
	volatile uint32_t 	MFP2_INT0:1;
	volatile uint32_t 	MFP3_INT1_MCLK:1;
	volatile uint32_t 	MFP4_T0_SDA:1;
	volatile uint32_t 	MFP5_T1_SCL:1;
	volatile uint32_t 	MFP6_WR_CKO:1;
	volatile uint32_t 	MFP7_RD:1;
	volatile uint32_t 	ALT0_RXD0:1;
	volatile uint32_t 	ALT1_TXD0:1;
	volatile uint32_t 	ALT2_INT0:1;
	volatile uint32_t 	ALT3_INT1_MCLK:1;
	volatile uint32_t 	ALT4_T0_SDA:1;
	volatile uint32_t 	ALT5_T1_SCL:1;
	volatile uint32_t 	ALT6_WR_CKO:1;
	volatile uint32_t 	ALT7_RD:1;
	volatile uint32_t 	SCHMITT:8;
	volatile const  uint32_t 	RESERVE:8;    
} GCR_P3_MFP_T;

typedef struct
{
	volatile uint32_t 	MFP0_PWM0:1;
	volatile uint32_t 	MFP1_PWM1:1;
	volatile uint32_t 	MFP2_PWM2:1;
	volatile uint32_t 	MFP3_PWM3:1;
	volatile uint32_t 	MFP4_CS:1;
	volatile uint32_t 	MFP5_ALE:1;
	volatile uint32_t 	MFP6_ICE_CLK:1;
	volatile uint32_t 	MFP7_ICE_DAT:1;
	volatile uint32_t 	ALT0_PWM0:1;
	volatile uint32_t 	ALT1_PWM1:1;
	volatile uint32_t 	ALT2_PWM2:1;
	volatile uint32_t 	ALT3_PWM3:1;
	volatile uint32_t 	ALT4_CS:1;
	volatile uint32_t 	ALT5_ALE:1;
	volatile uint32_t 	ALT6_ICE_CLK:1;
	volatile uint32_t 	ALT7_ICE_DAT:1;
	volatile uint32_t 	SCHMITT:8;
	volatile const  uint32_t 	RESERVE:8;    
} GCR_P4_MFP_T;

typedef volatile uint32_t GCR_REGWRPROT_T;

typedef struct
{
    volatile uint32_t  INTSRC:4;
    volatile const  uint32_t  RESERVE:28;
} GCR_INTSRC_T;

typedef struct
{
    volatile uint32_t  NMISEL:5;
    volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  INT_TEST:1;
    volatile const  uint32_t  RESERVE1:24;
} GCR_NMISEL_T;

typedef volatile uint32_t GCR_MCUIRQ_T;

typedef struct
{
	GCR_PDID_T      PDID;   
	GCR_RSTSRC_T    RSTSRC;
	GCR_IPRSTC1_T   IPRSTC1;
	GCR_IPRSTC2_T   IPRSTC2;
	uint32_t        RESERVE0[2];
	GCR_BODCR_T     BODCR;
	uint32_t        RESERVE1[2];
	GCR_PORCR_T		PORCR;
	uint32_t        RESERVE2[2];
	GCR_P0_MFP_T    P0_MFP;
	GCR_P1_MFP_T    P1_MFP;
	GCR_P2_MFP_T    P2_MFP;
	GCR_P3_MFP_T    P3_MFP;
	GCR_P4_MFP_T    P4_MFP;
	uint32_t        RESERVE3[47];
	GCR_REGWRPROT_T REGWRPROT;
} GCR_T;

typedef struct
{
    GCR_INTSRC_T    INTSRC[32];
    GCR_NMISEL_T    NMISEL;
    GCR_MCUIRQ_T    MCUIRQ;   
} GCR_INT_T;

 
typedef struct
{
    volatile uint32_t  ISPEN:1;
    volatile uint32_t  BS:1;
	volatile const  uint32_t  RESERVE0:2;
    volatile uint32_t  CFGUEN:1;
	volatile uint32_t  LDUEN:1;
    volatile uint32_t  ISPFF:1;
    volatile uint32_t  SWRST:1;
    volatile uint32_t  PT:3;
	volatile const  uint32_t  RESERVE1:1;
	volatile uint32_t  ET:3;
    volatile const  uint32_t  RESERVE2:17;

} FMC_ISPCON_T;

typedef volatile uint32_t FMC_ISPADR_T;
typedef volatile uint32_t FMC_ISPDAT_T;

typedef struct
{
    volatile uint32_t  FCTRL:4;
    volatile uint32_t  FCEN:1;
    volatile uint32_t  FOEN:1;
    volatile const  uint32_t  RESERVE:26;
} FMC_ISPCMD_T;

typedef struct
{
    volatile uint32_t  ISPGO:1;
    volatile const  uint32_t  RESERVE:31;
} FMC_ISPTRG_T;

typedef volatile const uint32_t FMC_DFBADR_T;

typedef struct
{
    volatile uint32_t  FPSEN:1;
    volatile uint32_t  FATS:3;
    volatile uint32_t  L_SPEED:1;
	volatile const  uint32_t  RESERVE:27;
} FMC_FATCON_T;

typedef struct
{
    FMC_ISPCON_T ISPCON;
    FMC_ISPADR_T ISPADR;
    FMC_ISPDAT_T ISPDAT;
    FMC_ISPCMD_T ISPCMD;
    FMC_ISPTRG_T ISPTRG;
    FMC_DFBADR_T DFBADR;
    FMC_FATCON_T FATCON;
} FMC_T;

 
typedef struct
{
    volatile uint32_t  CP01:8;
    volatile uint32_t  CP23:8;
    volatile uint32_t  DZI01:8;
    volatile uint32_t  DZI23:8;
} PWM_PPR_T;

typedef struct
{
    volatile uint32_t  CSR0:3;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  CSR1:3;
    volatile const  uint32_t  RESERVE1:1;
    volatile uint32_t  CSR2:3;
    volatile const  uint32_t  RESERVE2:1;
    volatile uint32_t  CSR3:3;
    volatile const  uint32_t  RESERVE3:17;
} PWM_CSR_T;

typedef struct
{
    volatile uint32_t  CH0EN:1;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  CH0INV:1;
    volatile uint32_t  CH0MOD:1;
    volatile uint32_t  DZEN01:1;
    volatile uint32_t  DZEN23:1;
    volatile const  uint32_t  RESERVE1:2;
    volatile uint32_t  CH1EN:1;
    volatile const  uint32_t  RESERVE2:1;
    volatile uint32_t  CH1INV:1;
    volatile uint32_t  CH1MOD:1;
    volatile const  uint32_t  RESERVE3:4;
    volatile uint32_t  CH2EN:1;
    volatile const  uint32_t  RESERVE4:1;
    volatile uint32_t  CH2INV:1;
    volatile uint32_t  CH2MOD:1;
    volatile const  uint32_t  RESERVE5:4;
    volatile uint32_t  CH3EN:1;
    volatile const  uint32_t  RESERVE6:1;
    volatile uint32_t  CH3INV:1;
    volatile uint32_t  CH3MOD:1;
    volatile const  uint32_t  RESERVE7:4;   
} PWM_PCR_T;

typedef volatile uint32_t PWM_CNR_T;

typedef volatile uint32_t PWM_CMR_T;

typedef volatile uint32_t PWM_PDR_T;

typedef struct
{
    volatile uint32_t  PWMIE0:1;
    volatile uint32_t  PWMIE1:1;
    volatile uint32_t  PWMIE2:1;
    volatile uint32_t  PWMIE3:1;
	volatile const  uint32_t  RESERVE:28;
} PWM_PIER_T;

typedef struct
{
    volatile uint32_t  PWMIF0:1;
    volatile uint32_t  PWMIF1:1;
    volatile uint32_t  PWMIF2:1;
    volatile uint32_t  PWMIF3:1;
	volatile const  uint32_t  RESERVE:28;
} PWM_PIIR_T;

typedef struct
{
    volatile uint32_t  INV0:1;
    volatile uint32_t  CRL_IE0:1;
    volatile uint32_t  CFL_IE0:1;
    volatile uint32_t  CAPCH0EN:1;
    volatile uint32_t  CAPIF0:1;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  CRLRI0:1;
    volatile uint32_t  CFLRI0:1;
    volatile const  uint32_t  RESERVE1:8;
    volatile uint32_t  INV1:1;
    volatile uint32_t  CRL_IE1:1;
    volatile uint32_t  CFL_IE1:1;
    volatile uint32_t  CAPCH1EN:1;
    volatile uint32_t  CAPIF1:1;
    volatile const  uint32_t  RESERVE2:1;
    volatile uint32_t  CRLRI1:1;
    volatile uint32_t  CFLRI1:1;
    volatile const  uint32_t  RESERVE3:8;
} PWM_CCR0_T;

typedef struct
{
    volatile uint32_t  INV2:1;
    volatile uint32_t  CRL_IE2:1;
    volatile uint32_t  CFL_IE2:1;
    volatile uint32_t  CAPCH2EN:1;
    volatile uint32_t  CAPIF2:1;
    volatile const  uint32_t  RESERVE0:1;
    volatile uint32_t  CRLRI2:1;
    volatile uint32_t  CFLRI2:1;
    volatile const  uint32_t  RESERVE1:8;
    volatile uint32_t  INV3:1;
    volatile uint32_t  CRL_IE3:1;
    volatile uint32_t  CFL_IE3:1;
    volatile uint32_t  CAPCH3EN:1;
    volatile uint32_t  CAPIF3:1;
    volatile const  uint32_t  RESERVE2:1;
    volatile uint32_t  CRLRI3:1;
    volatile uint32_t  CFLRI3:1;
    volatile const  uint32_t  RESERVE3:8;
} PWM_CCR2_T;

typedef volatile uint32_t PWM_CRLR_T;

typedef volatile uint32_t PWM_CFLR_T;

typedef volatile uint32_t PWM_CAPENR_T;

typedef struct
{
    volatile uint32_t  PWM0:1;
    volatile uint32_t  PWM1:1;
    volatile uint32_t  PWM2:1;
    volatile uint32_t  PWM3:1;
	volatile const  uint32_t  RESERVE:28;
} PWM_POE_T;

typedef struct
{
    PWM_PPR_T       PPR;
    PWM_CSR_T       CSR;
    PWM_PCR_T       PCR;
    PWM_CNR_T       CNR0;
    PWM_CMR_T       CMR0;
    PWM_PDR_T       PDR0;
    PWM_CNR_T       CNR1;
    PWM_CMR_T       CMR1;
    PWM_PDR_T       PDR1;
    PWM_CNR_T       CNR2;
    PWM_CMR_T       CMR2;
    PWM_PDR_T       PDR2;
    PWM_CNR_T       CNR3;
    PWM_CMR_T       CMR3;
    PWM_PDR_T       PDR3;
    volatile const uint32_t    RESERVE0;
    PWM_PIER_T      PIER;
    PWM_PIIR_T      PIIR;
    volatile const uint32_t    RESERVE1[2];
    PWM_CCR0_T      CCR0;
    PWM_CCR2_T      CCR2;
    PWM_CRLR_T      CRLR0;
    PWM_CFLR_T      CFLR0;
    PWM_CRLR_T      CRLR1;
    PWM_CFLR_T      CFLR1;
    PWM_CRLR_T      CRLR2;
    PWM_CFLR_T      CFLR2;
    PWM_CRLR_T      CRLR3;
    PWM_CFLR_T      CFLR3;
    PWM_CAPENR_T    CAPENR;
    PWM_POE_T       POE;    
        
} PWM_T;

 
typedef struct
{
    volatile uint32_t  ExtEN:1;
    volatile uint32_t  ExtBW16:1;
    volatile const  uint32_t  RESERVE0:6;
    volatile uint32_t  MCLKDIV:3;
    volatile const  uint32_t  RESERVE1:5;
    volatile uint32_t  ExttALE:3;
    volatile const  uint32_t  RESERVE2:5;
    volatile const  uint32_t  RESERVE3:8;
} EBI_CON_T;

typedef struct
{
    volatile const  uint32_t  RESERVE0:3;
    volatile uint32_t  ExttACC:5;
    volatile uint32_t  ExttAHD:3;
    volatile const  uint32_t  RESERVE1:1;
	volatile uint32_t  ExtIW2X:4;
	volatile uint32_t  ExtIR2W:4;
    volatile const  uint32_t  RESERVE2:4;
	volatile uint32_t  ExtIR2R:4;
    volatile const  uint32_t  RESERVE3:4;
} EBI_TIME_T;

typedef struct
{
    EBI_CON_T       CON;
    EBI_TIME_T      TIME;
} EBI_T;




 
 
 
 






 
#line 1208 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"

































 
 
 
#line 1251 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"






































typedef volatile unsigned char  vu8;
typedef volatile unsigned long  vu32;
typedef volatile unsigned short vu16;




#line 1302 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"

#line 1309 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"













#line 1354 ".\\Library\\CM0\\DeviceSupport\\Nuvoton\\M051Series\\M051Series.h"


                                                                                                 

#line 13 "USER\\main.c"
#line 1 "USER\\M051.h"
 
 
 
 
 



#line 29 "USER\\M051.h"

 
#line 45 "USER\\M051.h"

 
 



 
#line 64 "USER\\M051.h"
 






 
#line 82 "USER\\M051.h"

 
#line 93 "USER\\M051.h"
						
#line 103 "USER\\M051.h"

#line 113 "USER\\M051.h"

#line 123 "USER\\M051.h"
						 
#line 133 "USER\\M051.h"
						


#line 176 "USER\\M051.h"
						
 
#line 185 "USER\\M051.h"

 
#line 216 "USER\\M051.h"

 
#line 247 "USER\\M051.h"

 
#line 257 "USER\\M051.h"

 
#line 267 "USER\\M051.h"

 










 










 


 
#line 308 "USER\\M051.h"

 
#line 324 "USER\\M051.h"

 
#line 340 "USER\\M051.h"

 



 
#line 353 "USER\\M051.h"

#line 14 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvADC.h"
 
 
 
 
 




 
 
 
#line 14 ".\\Library\\Include\\Driver\\DrvADC.h"
#line 15 ".\\Library\\Include\\Driver\\DrvADC.h"

 


 
 
 
 





 


typedef enum {ADC_SINGLE_END, ADC_DIFFERENTIAL} E_ADC_INPUT_MODE;
typedef enum {ADC_SINGLE_OP, ADC_BURST_OP, ADC_SINGLE_CYCLE_OP, ADC_CONTINUOUS_OP} E_ADC_OPERATION_MODE;
typedef enum {EXTERNAL_12MHZ=0, INTERNAL_PLL=1, INTERNAL_RC22MHZ=2} E_ADC_CLK_SRC;
typedef enum {LOW_LEVEL=0, HIGH_LEVEL=1, FALLING_EDGE=2, RISING_EDGE=3} E_ADC_EXT_TRI_COND;
typedef enum {EXTERNAL_INPUT_SIGNAL, INTERNAL_BANDGAP} E_ADC_CH7_SRC;
typedef enum {LESS_THAN, GREATER_OR_EQUAL} E_ADC_CMP_CONDITION;

typedef void (DRVADC_ADC_CALLBACK)(uint32_t u32UserData);
typedef void (DRVADC_ADCMP0_CALLBACK)(uint32_t u32UserData);
typedef void (DRVADC_ADCMP1_CALLBACK)(uint32_t u32UserData);

#line 49 ".\\Library\\Include\\Driver\\DrvADC.h"

 
 
 
void DrvADC_Open(E_ADC_INPUT_MODE InputMode, E_ADC_OPERATION_MODE OpMode, uint8_t u8ChannelSelBitwise, E_ADC_CLK_SRC ClockSrc, uint8_t u8AdcDivisor);
void DrvADC_Close(void);
void DrvADC_SetADCChannel(uint8_t u8ChannelSelBitwise);
void DrvADC_ConfigADCChannel7(E_ADC_CH7_SRC Ch7Src);
void DrvADC_SetADCInputMode(E_ADC_INPUT_MODE InputMode);
void DrvADC_SetADCOperationMode(E_ADC_OPERATION_MODE OpMode);
void DrvADC_SetADCClkSrc(E_ADC_CLK_SRC ClockSrc);
void DrvADC_SetADCDivisor(uint8_t u8AdcDivisor);
void DrvADC_EnableADCInt(DRVADC_ADC_CALLBACK callback, uint32_t u32UserData);
void DrvADC_DisableADCInt(void);
void DrvADC_EnableADCCmp0Int(DRVADC_ADCMP0_CALLBACK callback, uint32_t u32UserData);
void DrvADC_DisableADCCmp0Int(void);
void DrvADC_EnableADCCmp1Int(DRVADC_ADCMP1_CALLBACK callback, uint32_t u32UserData);
void DrvADC_DisableADCCmp1Int(void);
uint32_t DrvADC_GetConversionRate(void);
void DrvADC_EnableExtTrigger(E_ADC_EXT_TRI_COND TriggerCondition);
void DrvADC_DisableExtTrigger(void);
void DrvADC_StartConvert(void);
void DrvADC_StopConvert(void);
uint32_t DrvADC_IsConversionDone(void);
int32_t DrvADC_GetConversionData(uint8_t u8ChannelNum);
uint32_t DrvADC_IsDataValid(uint8_t u8ChannelNum);
uint32_t DrvADC_IsDataOverrun(uint8_t u8ChannelNum);
int32_t DrvADC_EnableADCCmp0(uint8_t u8CmpChannelNum, E_ADC_CMP_CONDITION CmpCondition, uint16_t u16CmpData, uint8_t CmpMatchCount);
int32_t DrvADC_EnableADCCmp1(uint8_t u8CmpChannelNum, E_ADC_CMP_CONDITION CmpCondition, uint16_t u16CmpData, uint8_t CmpMatchCount);
void DrvADC_DisableADCCmp0(void);
void DrvADC_DisableADCCmp1(void);
void DrvADC_EnableSelfCalibration(void);
uint32_t DrvADC_IsCalibrationDone(void);
void DrvADC_DisableSelfCalibration(void);
uint32_t DrvADC_GetVersion (void);

#line 15 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvPWM.h"
 
 
 
 
 



 
 
 

#line 14 ".\\Library\\Include\\Driver\\DrvPWM.h"






 
 
 




 
 
 

							   
 
 
 





 
 
 
#line 51 ".\\Library\\Include\\Driver\\DrvPWM.h"

 
 
 
#line 63 ".\\Library\\Include\\Driver\\DrvPWM.h"

 
 
 




 
 
 



 
 
 






 
 
 





 
 
 



 
 
 
typedef struct
{
	uint8_t	  u8Mode;
	uint8_t	  u8HighPulseRatio;
	uint8_t	  u8ClockSelector;
	uint8_t	  u8PreScale;
	uint32_t  u32Frequency;	
	uint32_t  u32Duty;
 	int32_t	  i32Inverter;
}S_DRVPWM_TIME_DATA_T;

 
 
 
typedef void (*PFN_DRVPWM_CALLBACK)(void);

 
 
 
typedef struct
{
    PFN_DRVPWM_CALLBACK pfnPWM0CallBack;    
    PFN_DRVPWM_CALLBACK pfnCAP0CallBack;
   
    PFN_DRVPWM_CALLBACK pfnPWM1CallBack;    
    PFN_DRVPWM_CALLBACK pfnCAP1CallBack;
    
    PFN_DRVPWM_CALLBACK pfnPWM2CallBack;    
    PFN_DRVPWM_CALLBACK pfnCAP2CallBack;
    
    PFN_DRVPWM_CALLBACK pfnPWM3CallBack;    
    PFN_DRVPWM_CALLBACK pfnCAP3CallBack;        
   
}S_DRVPWM_CALLBACK_T;

 
 
 
void	 DrvPWM_ClearCaptureIntStatus(uint8_t u8Capture, uint8_t u8IntType);
void	 DrvPWM_ClearInt(uint8_t u8Timer);
void	 DrvPWM_Close(void);

void	 DrvPWM_DisableInt(uint8_t u8Timer);

void	 DrvPWM_Enable(uint8_t u8Timer, int32_t i32Enable);
void	 DrvPWM_EnableDeadZone(uint8_t u8Timer, uint8_t u8Length, int32_t i32EnableDeadZone);
void	 DrvPWM_EnableInt(uint8_t u8Timer, uint8_t u8Int, PFN_DRVPWM_CALLBACK pfncallback);

int32_t	 DrvPWM_GetCaptureIntStatus(uint8_t u8Capture, uint8_t u8IntType);

uint16_t DrvPWM_GetFallingCounter(uint8_t u8Capture);
int32_t	 DrvPWM_GetIntFlag(uint8_t u8Timer);
uint16_t DrvPWM_GetRisingCounter(uint8_t u8Capture);
uint32_t DrvPWM_GetTimerCounter(uint8_t u8Timer);
uint32_t DrvPWM_GetVersion (void);

int32_t	 DrvPWM_IsTimerEnabled(uint8_t u8Timer);

void	 DrvPWM_Open(void);
int32_t  DrvPWM_SelectClearLatchFlagOption(int32_t i32option);
void 	 DrvPWM_SelectClockSource(uint8_t u8Timer, uint8_t u8ClockSourceSelector);
uint32_t DrvPWM_SetTimerClk(uint8_t u8Timer, S_DRVPWM_TIME_DATA_T *sPt);
void	 DrvPWM_SetTimerCounter(uint8_t u8Timer, uint16_t u16Counter);
void	 DrvPWM_SetTimerIO(uint8_t u8Timer, int32_t i32Enable);









#line 16 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvGPIO.h"
 
 
 
 
 



#line 10 ".\\Library\\Include\\Driver\\DrvGPIO.h"

 
 
 




 
 
 

							   
 
 
 
 




 
#line 73 ".\\Library\\Include\\Driver\\DrvGPIO.h"

typedef void (*P0P1_CALLBACK)(uint32_t u32P0Status, uint32_t u32P1Status);
typedef void (*P2P3P4_CALLBACK)(uint32_t u32P2Status, uint32_t u32P3Status, uint32_t u32P4Status);
typedef void (*EINT_CALLBACK)(void);

typedef enum 
{
	E_PORT0	= 0,
	E_PORT1, 
	E_PORT2, 
	E_PORT3, 
	E_PORT4
} E_DRVGPIO_PORT;

typedef enum 
{
	E_PIN0 	= 0,
	E_PIN1,
	E_PIN2,
	E_PIN3,
	E_PIN4,
	E_PIN5,
	E_PIN6,
	E_PIN7
} E_DRVGPIO_PIN;

typedef enum 
{
    E_EINT0_PIN = 2,
    E_EINT1_PIN = 3
} E_DRVGPIO_EXT_INT_PIN;	   

typedef enum 
{
    E_IO_INPUT,
    E_IO_OUTPUT,
    E_IO_OPENDRAIN,
    E_IO_QUASI
} E_DRVGPIO_IO;

typedef enum 
{
    E_IO_RISING,
    E_IO_FALLING,
    E_IO_BOTH_EDGE
} E_DRVGPIO_INT_TYPE;

typedef enum
{
    E_MODE_EDGE,
    E_MODE_LEVEL
} E_DRVGPIO_INT_MODE;

typedef enum
{
    E_DBCLKSRC_HCLK = 0, 
    E_DBCLKSRC_10K = 1
} E_DRVGPIO_DBCLKSRC;	   

 
 
 
typedef enum
{
	E_FUNC_GPIO,    E_FUNC_CLKO,    E_FUNC_I2C,     E_FUNC_SPI0,    E_FUNC_SPI1,	
    E_FUNC_ADC0,    E_FUNC_ADC1,    E_FUNC_ADC2,    E_FUNC_ADC3,    E_FUNC_ADC4,    
    E_FUNC_ADC5,    E_FUNC_ADC6,	E_FUNC_ADC7,    E_FUNC_EXTINT0, E_FUNC_EXTINT1, 
    E_FUNC_TMR0,    E_FUNC_TMR1,    E_FUNC_TMR2,    E_FUNC_TMR3,    E_FUNC_UART0,   
    E_FUNC_UART1,   E_FUNC_PWM01,   E_FUNC_PWM23,   E_FUNC_PWM45,   E_FUNC_PWM67,   
    E_FUNC_PWM01_P4,E_FUNC_PWM23_P4,E_FUNC_EBI_8B,  E_FUNC_EBI_16B, E_FUNC_ICE     
} E_DRVGPIO_FUNC;
			  
 
 
 
void DrvGPIO_Open(E_DRVGPIO_PORT port, uint32_t pin, E_DRVGPIO_IO mode);
void DrvGPIO_Close(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_SetBit(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_GetBit(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_ClrBit(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_SetPortBits(E_DRVGPIO_PORT port, int32_t i32PortValue);
int32_t DrvGPIO_GetPortBits(E_DRVGPIO_PORT port);
int32_t DrvGPIO_GetDoutBit(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_GetPortDoutBits(E_DRVGPIO_PORT port);
int32_t DrvGPIO_SetBitMask(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_GetBitMask(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_ClrBitMask(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_SetPortMask(E_DRVGPIO_PORT port, int32_t i32PortValue);
int32_t DrvGPIO_GetPortMask(E_DRVGPIO_PORT port);
int32_t DrvGPIO_ClrPortMask(E_DRVGPIO_PORT port, int32_t i32PortValue);
int32_t DrvGPIO_EnableDebounce(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_DisableDebounce(E_DRVGPIO_PORT port, uint32_t pin);
int32_t DrvGPIO_SetDebounceTime(uint32_t u32CycleSelection, E_DRVGPIO_DBCLKSRC ClockSource);
int32_t DrvGPIO_GetDebounceSampleCycle(void);
int32_t DrvGPIO_EnableInt(E_DRVGPIO_PORT port, uint32_t pin, E_DRVGPIO_INT_TYPE Type, E_DRVGPIO_INT_MODE Mode);
int32_t DrvGPIO_DisableInt(E_DRVGPIO_PORT port, uint32_t pin);
void DrvGPIO_SetIntCallback(P0P1_CALLBACK pfP0P1Callback, P2P3P4_CALLBACK pfP2P3P4Callback);
int32_t DrvGPIO_EnableEINT(E_DRVGPIO_EXT_INT_PIN pin, E_DRVGPIO_INT_TYPE Type, E_DRVGPIO_INT_MODE Mode, EINT_CALLBACK pfEINTCallback);
int32_t DrvGPIO_DisableEINT(E_DRVGPIO_EXT_INT_PIN pin);
int32_t DrvGPIO_GetIntStatus(E_DRVGPIO_PORT port);
int32_t DrvGPIO_InitFunction(E_DRVGPIO_FUNC function);
int32_t DrvGPIO_GetVersion(void);










#line 17 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvSYS.h"
 
 
 
 
 



#line 10 ".\\Library\\Include\\Driver\\DrvSYS.h"


 
 
 













#line 35 ".\\Library\\Include\\Driver\\DrvSYS.h"

 
 
 
typedef enum 
{
	E_SYS_EXTERNAL_12M = 0,
	E_SYS_INTERNAL_22M = 1,	
}E_SYS_PLL_CLKSRC;


 
 
 
typedef enum 
{
	E_SYS_GPIO_RST  = 1,
	E_SYS_TMR0_RST  = 2,
	E_SYS_TMR1_RST  = 3,
	E_SYS_TMR2_RST  = 4,
	E_SYS_TMR3_RST  = 5,
	E_SYS_I2C_RST   = 8,
	E_SYS_SPI0_RST  = 12,
	E_SYS_SPI1_RST  = 13,
	E_SYS_UART0_RST = 16,
	E_SYS_UART1_RST = 17,
	E_SYS_PWM03_RST = 20,
	E_SYS_PWM47_RST = 21,
	E_SYS_ACMP_RST  = 22,
	E_SYS_ADC_RST   = 28,
	E_SYS_EBI_RST   = 32
}E_SYS_IP_RST;

 
 
 

typedef enum 
{
	E_SYS_WDT_CLK   = 0,
	E_SYS_TMR0_CLK  = 2,
	E_SYS_TMR1_CLK  = 3,
	E_SYS_TMR2_CLK  = 4,
	E_SYS_TMR3_CLK  = 5,
	E_SYS_FDIV_CLK  = 6,
	E_SYS_I2C_CLK   = 8,
	E_SYS_SPI0_CLK  = 12,
	E_SYS_SPI1_CLK  = 13,
	E_SYS_UART0_CLK = 16,
	E_SYS_UART1_CLK = 17,
	E_SYS_PWM01_CLK = 20,
	E_SYS_PWM23_CLK = 21,
	E_SYS_PWM45_CLK = 22,
	E_SYS_PWM67_CLK = 23,
	E_SYS_ADC_CLK   = 28,
	E_SYS_ACMP_CLK  = 30,
	E_SYS_ISP_CLK   = 34,
	E_SYS_EBI_CLK   = 35
}E_SYS_IP_CLK;


 
 
 
typedef enum 
{
	E_SYS_ADC_DIV,
	E_SYS_UART_DIV,
	E_SYS_HCLK_DIV

}E_SYS_IP_DIV;


 
 
 
typedef enum 
{	
	E_SYS_WDT_CLKSRC,
	E_SYS_ADC_CLKSRC,
	E_SYS_TMR0_CLKSRC,
	E_SYS_TMR1_CLKSRC,
	E_SYS_TMR2_CLKSRC,
	E_SYS_TMR3_CLKSRC,
	E_SYS_UART_CLKSRC,
	E_SYS_PWM01_CLKSRC,
	E_SYS_PWM23_CLKSRC,
	E_SYS_FRQDIV_CLKSRC,
	E_SYS_PWM45_CLKSRC,
	E_SYS_PWM67_CLKSRC

}E_SYS_IP_CLKSRC;


 
 
 
typedef enum 
{
	E_SYS_XTL12M,
	E_SYS_OSC22M,
	E_SYS_OSC10K,
	E_SYS_PLL,
}E_SYS_CHIP_CLKSRC;


 
 
 
typedef enum 
{
	E_SYS_IMMEDIATE, 
	E_SYS_WAIT_FOR_CPU
}E_SYS_PD_TYPE;


typedef void (*BOD_CALLBACK)(void);
typedef void (*PWRWU_CALLBACK)(void);

 
 
 
void 	 DrvSYS_ClearClockSwitchStatus(void);
uint32_t DrvSYS_ClearResetSource(uint32_t u32Src);

void 	 DrvSYS_Delay(uint32_t us);
void 	 DrvSYS_DisableBODLowPowerMode(void);
void 	 DrvSYS_DisableLowVoltReset(void);
void 	 DrvSYS_DisablePOR(void);

void 	 DrvSYS_EnableBODLowPowerMode(void);
void 	 DrvSYS_EnableLowVoltReset(void);
void 	 DrvSYS_EnablePOR(void);
void 	 DrvSYS_EnterPowerDown(E_SYS_PD_TYPE ePDType);

uint32_t DrvSYS_GetBODState(void);
int32_t  DrvSYS_GetChipClockSourceStatus(E_SYS_CHIP_CLKSRC eClkSrc);
uint32_t DrvSYS_GetClockSwitchStatus(void);
uint32_t DrvSYS_GetExtClockFreq(void);
uint32_t DrvSYS_GetHCLKFreq(void);
uint32_t DrvSYS_GetPLLClockFreq(void);
uint32_t DrvSYS_GetPLLContent(E_SYS_PLL_CLKSRC ePllSrc, uint32_t u32PllClk);
uint32_t DrvSYS_GetResetSource(void);
uint32_t DrvSYS_GetVersion(void);

int32_t  DrvSYS_IsProtectedRegLocked(void);

int32_t  DrvSYS_LockProtectedReg(void);

int32_t  DrvSYS_Open(uint32_t u32Hclk);

uint32_t DrvSYS_ReadProductID(void);
void 	 DrvSYS_ResetChip(void);
void 	 DrvSYS_ResetCPU(void);
void 	 DrvSYS_ResetIP(E_SYS_IP_RST eIpRst);

void 	 DrvSYS_SelectBODVolt(uint8_t u8Volt);
int32_t  DrvSYS_SelectHCLKSource(uint8_t u8ClkSrcSel);
int32_t  DrvSYS_SelectIPClockSource(E_SYS_IP_CLKSRC eIpClkSrc, uint8_t u8ClkSrcSel);
void 	 DrvSYS_SelectPLLSource(E_SYS_PLL_CLKSRC ePllSrc);
int32_t  DrvSYS_SelectSysTickSource(uint8_t u8ClkSrcSel);
void 	 DrvSYS_SetBODFunction(int32_t i32Enable, int32_t i32Mode, BOD_CALLBACK bodcallbackFn);
int32_t  DrvSYS_SetClockDivider(E_SYS_IP_DIV eIpDiv , int32_t i32value);
int32_t  DrvSYS_SetFreqDividerOutput(int32_t i32Flag, uint8_t u8Divider);
void 	 DrvSYS_SetIPClock(E_SYS_IP_CLK eIpClk, int32_t i32Enable);
int32_t  DrvSYS_SetOscCtrl(E_SYS_CHIP_CLKSRC eClkSrc, int32_t i32Enable);
void     DrvSYS_SetPLLContent(uint32_t u32PllContent);
void 	 DrvSYS_SetPLLMode(int32_t i32Flag);
void     DrvSYS_SetPowerDownWakeUpInt(int32_t i32Enable, PWRWU_CALLBACK pdwucallbackFn, int32_t i32enWUDelay);

int32_t  DrvSYS_UnlockProtectedReg(void);



#line 18 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvUART.h"
 
 
 
 
 



#line 10 ".\\Library\\Include\\Driver\\DrvUART.h"






 
 
 




 
 
 

							   
 
 
 







#line 45 ".\\Library\\Include\\Driver\\DrvUART.h"



 
 
 







typedef void (PFN_DRVUART_CALLBACK)(uint32_t userData);
 
 
 



 
 
 

typedef enum 
{
	UART_PORT0 = 0x000, 
	UART_PORT1 = 0x100000,
	UART_PORT2 = 0x104000
} E_UART_PORT;


 
 
 
typedef enum 
{
	 DRVUART_LININT   	=    0x00000100,	     
	 DRVUART_WAKEUPINT	=	 0x00000040,		 
     DRVUART_BUFERRINT  =	 0x00000020,		 
     DRVUART_TOUTINT   	=	 0x00000010,	     
	 DRVUART_MOSINT   	=	 0x00000008,	     
	 DRVUART_RLSINT   	=	 0x00000004,	     
	 DRVUART_THREINT   	=	 0x00000002,	     
	 DRVUART_RDAINT   	=	 0x00000001		 
} E_INT_SOURCE;


 
 
 
typedef enum 
{
	 DRVUART_DATABITS_5   =    0x0,
	 DRVUART_DATABITS_6	  =	   0x1,
     DRVUART_DATABITS_7   =	   0x2,
     DRVUART_DATABITS_8   =	   0x3

} E_DATABITS_SETTINS;

 
 
 

typedef enum 
{
	 DRVUART_PARITY_NONE   =    0x0,
	 DRVUART_PARITY_ODD	   =	0x1,
     DRVUART_PARITY_EVEN   =	0x3,
     DRVUART_PARITY_MARK   =	0x5,
     DRVUART_PARITY_SPACE  =	0x7
} E_PARITY_SETTINS;

 
 
 

typedef enum 
{
	 DRVUART_STOPBITS_1  	=   0x0,
	 DRVUART_STOPBITS_1_5	=   0x1,
     DRVUART_STOPBITS_2   	=   0x1
} E_STOPBITS_SETTINS;


 
 
 
typedef enum 
{
	DRVUART_FIFO_1BYTES 	= 0x0, 
	DRVUART_FIFO_4BYTES 	= 0x1,
	DRVUART_FIFO_8BYTES 	= 0x2,
	DRVUART_FIFO_14BYTES 	= 0x3,
	DRVUART_FIFO_30BYTES 	= 0x4,
	DRVUART_FIFO_46BYTES 	= 0x5,
	DRVUART_FIFO_62BYTES 	= 0x6
} E_FIFO_SETTINGS;




 
 
 

typedef enum 
{
	FUN_UART 	= 0, 
	FUN_LIN 	= 1,
	FUN_IRCR 	= 2,
	FUN_RS485 	= 3
} E_UART_FUNC;

 
 
 

typedef enum 
{
	MODE_RS485_NMM = 1, 
	MODE_RS485_AAD = 2,
	MODE_RS485_AUD = 4
} E_MODE_RS485;
									


 
 
 

typedef struct DRVUART_STRUCT
{
    uint32_t            u32BaudRate;
    E_DATABITS_SETTINS  u8cDataBits;
    E_STOPBITS_SETTINS  u8cStopBits;
    E_PARITY_SETTINS 	u8cParity;
    E_FIFO_SETTINGS     u8cRxTriggerLevel;
    uint8_t             u8TimeOut ;
}STR_UART_T;

 
 
 

typedef struct IRCR_STRUCT
{
    uint8_t   	    u8cTXSelect;
    uint8_t			u8cInvTX;
    uint8_t	        u8cInvRX;
}STR_IRCR_T;

 
 
 
typedef struct RS485_STRUCT
{
    uint8_t   	    u8cModeSelect;
    uint8_t			u8cAddrEnable;
    uint8_t	        u8cAddrValue;
	uint8_t	        u8cDelayTime;
	uint8_t	        u8cRxDisable;
}STR_RS485_T;




 
 
 
 
void DrvUART_Close(E_UART_PORT u32Port);
void DrvUART_DisableInt(E_UART_PORT u32Port,uint32_t u32InterruptFlag);
void DrvUART_GetCTS(E_UART_PORT u32Port,uint8_t *pu8CTSValue,uint8_t *pu8CTSChangeState);
void DrvUART_SetClcok(uint8_t u8ClcokSrc, uint8_t u8ClcokDiv);
void DrvUART_SetRTS(E_UART_PORT u32Port,uint8_t u8Value,uint16_t u16TriggerLevel);
void DrvUART_SetFnIRDA(E_UART_PORT u32Port,STR_IRCR_T *str_IRCR );
void DrvUART_SetFnRS485(E_UART_PORT u32Port,STR_RS485_T *str_RS485);
void DrvUART_EnableInt(E_UART_PORT u32Port,uint32_t u32InterruptFlag,PFN_DRVUART_CALLBACK pfncallback);

int32_t DrvUART_GetIntStatus(E_UART_PORT u32Port,uint32_t u32InterruptFlag);
int32_t DrvUART_Read(E_UART_PORT u32Port,uint8_t *pu8RxBuf,uint32_t	u32ReadBytes);
int32_t DrvUART_Open(E_UART_PORT u32Port, STR_UART_T *sParam);
int32_t DrvUART_Write(E_UART_PORT u32Port,uint8_t *pu8TxBuf,uint32_t u32WriteBytes);
int32_t DrvUART_GetVersion(void);
int32_t DrvUART_kbhit(void);
uint32_t DrvUART_IsIntEnabled(E_UART_PORT u32Port,uint32_t u32InterruptFlag);
uint32_t DrvUART_ClearIntFlag(E_UART_PORT u32Port,uint32_t u32InterruptFlag);



















#line 19 "USER\\main.c"
#line 1 ".\\Library\\Include\\Driver\\DrvTIMER.h"
 
 
 
 
 



#line 10 ".\\Library\\Include\\Driver\\DrvTIMER.h"

 
 
 

 
 
 





 
 
 






 
                                                                             
 
typedef void (*TIMER_CALLBACK)(uint32_t data);	 
typedef void (*WDT_CALLBACK)(uint32_t data);	 

 
 
 
typedef struct timeEvent_t
{
    int32_t              active;
    int32_t              initTick;
    int32_t              curTick;
    TIMER_CALLBACK       funPtr;
    uint32_t             transParam;
} TIMER_EVENT_T;

 
 
 
typedef enum {
    E_TMR0  =   0 ,
    E_TMR1  =   1 ,
	E_TMR2  =   2 ,
	E_TMR3  =   3        
} E_TIMER_CHANNEL;

 
 
 
typedef enum{                   
    E_ONESHOT_MODE      = 0,
    E_PERIODIC_MODE   	= 1,
    E_TOGGLE_MODE     	= 2, 
} E_TIMER_OPMODE ;

 
 
 
typedef enum {
    E_WDT_IOC_START_TIMER       = 0,
    E_WDT_IOC_STOP_TIMER        = 1,
    E_WDT_IOC_ENABLE_INT        = 2,
    E_WDT_IOC_DISABLE_INT       = 3,
    E_WDT_IOC_ENABLE_WAKEUP     = 4, 
    E_WDT_IOC_DISABLE_WAKEUP    = 5, 
    E_WDT_IOC_RESET_TIMER       = 6,
    E_WDT_IOC_ENABLE_RESET_FUNC = 7,
    E_WDT_IOC_DISABLE_RESET_FUNC= 8,
	E_WDT_IOC_SET_INTERVAL      = 9
} E_WDT_CMD; 

 
 
 
typedef enum{
    E_WDT_LEVEL0      = 0,          
    E_WDT_LEVEL1      = 1,          
    E_WDT_LEVEL2      = 2,           
    E_WDT_LEVEL3      = 3,          
	E_WDT_LEVEL4      = 4,          
	E_WDT_LEVEL5      = 5,          
	E_WDT_LEVEL6      = 6,          
	E_WDT_LEVEL7      = 7           
} E_WDT_INTERVAL;

 
 
 
void DrvTIMER_Init(void);
int32_t DrvTIMER_Open(E_TIMER_CHANNEL ch, uint32_t uTicksPerSecond, E_TIMER_OPMODE op_mode);
int32_t DrvTIMER_Close(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_SetTimerEvent(E_TIMER_CHANNEL ch, uint32_t uInterruptTicks, TIMER_CALLBACK pTimerCallback, uint32_t parameter);
void DrvTIMER_ClearTimerEvent(E_TIMER_CHANNEL ch, uint32_t uTimerEventNo);
int32_t DrvTIMER_EnableInt(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_DisableInt(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_GetIntFlag(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_ClearIntFlag(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_Start(E_TIMER_CHANNEL ch);
uint32_t DrvTIMER_GetIntTicks(E_TIMER_CHANNEL ch);
int32_t DrvTIMER_ResetIntTicks(E_TIMER_CHANNEL ch);
void DrvTIMER_Delay(E_TIMER_CHANNEL ch, uint32_t uTicks);
void DrvTIMER_SetEXTClockFreq(uint32_t u32ClockFreq);
uint32_t DrvTIMER_GetVersion(void);

void DrvWDT_Open(E_WDT_INTERVAL WDTlevel);
void DrvWDT_Close(void);
void DrvWDT_InstallISR(WDT_CALLBACK pvWDTISR);
int32_t DrvWDT_Ioctl(E_WDT_CMD uWDTCmd, uint32_t uArgument);





#line 20 "USER\\main.c"
#line 1 "USER\\Register_Bit.h"
 
 
 
 
 



 
#line 17 "USER\\Register_Bit.h"

 




 
#line 37 "USER\\Register_Bit.h"

 














 
#line 94 "USER\\Register_Bit.h"
                                                
 
#line 136 "USER\\Register_Bit.h"

 
#line 178 "USER\\Register_Bit.h"

 
#line 216 "USER\\Register_Bit.h"

 
#line 242 "USER\\Register_Bit.h"

 






 
 
 
 
#line 273 "USER\\Register_Bit.h"

  












  






  
























  
























  
























  
























  
#line 402 "USER\\Register_Bit.h"

 




  






  












 
#line 437 "USER\\Register_Bit.h"

 



 
#line 459 "USER\\Register_Bit.h"

 






 












 

















































 















 






 


 
















































 
#line 614 "USER\\Register_Bit.h"

 
#line 624 "USER\\Register_Bit.h"

 
#line 634 "USER\\Register_Bit.h"

 
























 
#line 677 "USER\\Register_Bit.h"

 




#line 700 "USER\\Register_Bit.h"

 
#line 708 "USER\\Register_Bit.h"

 




 


 
#line 724 "USER\\Register_Bit.h"

#line 731 "USER\\Register_Bit.h"

#line 738 "USER\\Register_Bit.h"

#line 745 "USER\\Register_Bit.h"

 
#line 753 "USER\\Register_Bit.h"

#line 760 "USER\\Register_Bit.h"

#line 767 "USER\\Register_Bit.h"

#line 774 "USER\\Register_Bit.h"

 
#line 794 "USER\\Register_Bit.h"

 
#line 814 "USER\\Register_Bit.h"

 





 





 





 





 





 





 
#line 866 "USER\\Register_Bit.h"

 
#line 882 "USER\\Register_Bit.h"

 
#line 898 "USER\\Register_Bit.h"

 
#line 914 "USER\\Register_Bit.h"

 





 





 
#line 934 "USER\\Register_Bit.h"











#line 962 "USER\\Register_Bit.h"






#line 1001 "USER\\Register_Bit.h"





 
#line 1013 "USER\\Register_Bit.h"

 












 


 
#line 1040 "USER\\Register_Bit.h"

#line 1049 "USER\\Register_Bit.h"

 
#line 1061 "USER\\Register_Bit.h"

 
#line 1071 "USER\\Register_Bit.h"



#line 1082 "USER\\Register_Bit.h"




 
#line 1093 "USER\\Register_Bit.h"







 




 

















 
#line 1136 "USER\\Register_Bit.h"

 



 






 





 





 



 






















 




#line 1200 "USER\\Register_Bit.h"

 
#line 1211 "USER\\Register_Bit.h"






 





 



 
#line 1235 "USER\\Register_Bit.h"





 
#line 1250 "USER\\Register_Bit.h"

#line 1260 "USER\\Register_Bit.h"

#line 1268 "USER\\Register_Bit.h"

 
#line 1277 "USER\\Register_Bit.h"

 


 


#line 1292 "USER\\Register_Bit.h"



#line 21 "USER\\main.c"
#line 1 "USER\\Uart.h"
 
 
 
 
 










typedef struct
{
	char AD_Board_BL_Mode_Status;
	char AD_Board_BL_Level_Status;
	char AD_Board_BL_EN_Status;
	char AD_Board_Channel_Status;
	char AD_Board_Monitor_Status;
}Struct_DATA;
extern Struct_DATA AD_Board_Data;

extern  uint8_t  UART0_Buffer[20];
extern  uint8_t  UART0_Send_Buffer[20];
extern  uint8_t  UART1_Buffer[20];
extern  uint8_t  UART1_Send_Buffer[20];

extern  uint8_t  AD_BOARD_BL_FLAG;
extern  uint8_t  AD_BOARD_CHANNAL_FLAG;
extern  uint8_t  AD_BOARD_BL_STATUS_FLAG;
extern  uint8_t  BL_MODE_Status;
extern  uint8_t  BL_LEVEL_Status;
extern  uint8_t  BL_EN_Status;
extern  uint8_t  AD_BOARD_CHANNAL_Stasus;
extern  uint8_t  ADDR_485;

extern void UART_Init(void);
extern void UART0_SEND(uint8_t *BufferPtr, uint32_t Length);
extern void UART1_SEND(uint8_t *BufferPtr, uint32_t Length);
extern uint8_t UART0_INT_HANDLE(uint32_t u32IntStatus);
extern uint8_t UART1_INT_HANDLE(uint32_t u32IntStatus);
extern void Uart0_Handle();
extern void Uart1_Handle();
extern void Send_Data_To_PC (uint8_t c);
extern uint8_t Receive_Data_From_PC(void);
extern void Show_Pass(void);
extern void Show_Fail(void);

extern uint16_t Table_lookup(uint16_t x_AD);
extern int MUX_filter(int AD);
extern uint16_t AD_CONS(char channel);





#line 22 "USER\\main.c"
#line 1 "USER\\Macro_SystemClock.h"
 
 
 
 
 



#line 21 "USER\\Macro_SystemClock.h"



                           


	









                               	


                               	


                               



	








                             

#line 66 "USER\\Macro_SystemClock.h"

#line 74 "USER\\Macro_SystemClock.h"

#line 23 "USER\\main.c"
#line 1 "USER\\global.h"




















#line 29 "USER\\global.h"







#line 57 "USER\\global.h"

#line 73 "USER\\global.h"

#line 80 "USER\\global.h"



									 







typedef struct 
{
char BL_Mode;
char BL_Value;
char IO_Input;
char Configuration;
char Status;
char LightSensor_Value;
char BL_MIN;
char BL_MAX;
char Threshold3;
char Cnt_ForAD;
char Cnt_ForBL;
char KeyLED_Step;
}Struct_param;
extern Struct_param Slave;

typedef struct
{
uint16_t	Dstep1;
uint16_t	Dstep2;
uint16_t	Dstep3;
uint16_t	Dstep4;
uint16_t	Dstep5;
uint16_t	Dstep6;
uint16_t	Dstep7;
uint16_t	Dstep8;
uint16_t	Dstep9;
uint16_t	Dstep10;

}Dimmer_Step;

typedef struct 
{
char LCD_TP_On;
char LCD_TP_Off;
char KeyLED_On;
char KeyLED_Off;
}Struct_Config;
extern Struct_Config Config,Event;
typedef struct 
{

char KeyLED_Step_IGN;
char KeyLED_Step_P;
char Power_Delay;
char IGN_Delay;
char BL_Mode;
char BL_Step;
}Struct_DefaultParameter;
typedef struct
{
  char inch_H;
  char inch_L;
  char year;
  char month;
  char day;
  char numH;
  char numL;
  char HW_V;
  char SW_V;
}Serial_STR;


extern const uint8_t Version_Code;
extern Struct_DefaultParameter Default;
extern Serial_STR  serial;
extern Dimmer_Step Dimmer_Slave;
extern 	uint16_t wPWM_CMR0_Num;
extern  volatile uint8_t  UART0_RecvFlag,UART1_RecvFlag;


extern  uint8_t  UART_STOH_Buffer[];
extern  uint8_t  BL_EN_PC,
				 bright_high,
				 bright_low;

extern  uint8_t  EN_SET,DIS_LINK_EN;
extern  uint8_t  Flag_BrightAdj_Initial;
extern  uint8_t  Bright_Auto[10];
extern  uint16_t  Bright_Aver;
extern  uint16_t  Dimmer_Auto2;
extern  uint8_t   Led_Test_FLASHING;
extern  char Flag_LED;
extern  char PowerON_Flag;
extern  char PowerOff_Flag;
extern uint8_t SlaveIGNRefresh;
extern uint8_t PowerInputValue;
extern uint16_t IGNDelay,PowerDelay;
extern uint16_t uTicks_Touch;

extern  char CMD_Received;
extern  char CMD[8];
extern void delay(uint32_t uSec);
extern uint8_t GPIO_Read();
extern void save_data();
extern void init_data();
extern void RS485Send(uint8_t *BufferPtr, uint32_t Length);
extern void Backlight_EN();
extern void Event_Generator();
extern void Event_Handler();
void GPIO_Int_Func();

#line 24 "USER\\main.c"
#line 1 "USER\\adc.h"



#line 11 "USER\\adc.h"

#line 18 "USER\\adc.h"




 
#line 30 "USER\\adc.h"

extern uint32_t TFT_CURR[6];
extern uint32_t SENSOR[6];
extern uint32_t BACK_TEMP[6];
extern uint32_t IN_VOLTAGE[6];
extern uint32_t BL_CURR[6];
extern uint32_t SYS_TEMP[6];
extern uint8_t  TFT_CURR_VALUE;
extern uint8_t  SENSOR_VALUE; 
extern uint8_t  BACK_TEMP_VALUE;
extern uint8_t  IN_VOLTAGE_VALUE;
extern uint8_t  BL_CURR_VALUE;
extern uint8_t  SYS_TEMP_VALUE;
extern uint8_t  ADC_Flag;

extern void ADC_init(void);
extern uint32_t GetADC(uint8_t ChannelNum);
extern void ADC_HANDLE(void);
extern uint8_t PowerInputCheck(void);
 

#line 25 "USER\\main.c"




 



 



extern uint8_t pwm_value,
               Sta_Ctrl,
			   DIS_LINK_EN,
			   AT_DET_EN;
volatile uint8_t  UART0_RecvFlag=0;
volatile uint8_t  UART1_RecvFlag=0;
volatile uint8_t  UART0_SendFlag=0;
volatile uint8_t  UART1_SendFlag=0; 
volatile uint8_t  Status_Update=0;

 int num4=0,num7=0;

uint8_t  UART_STOH_Buffer[30];
uint8_t  Led_Test_FLASHING = 1;
uint16_t  WDT_FeedFlag=1,
          uTicks=0,
		  uTicks_Touch=0;
Struct_param Slave;
Dimmer_Step  Dimmer_Slave;
void Time_Callback();

void WDT_CallBack()
{
 if(WDT_FeedFlag!=0)
 {
 	*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x59;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x16;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x88;
	DrvWDT_Ioctl(E_WDT_IOC_RESET_TIMER,0);
	*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x00;;
	WDT_FeedFlag--;	
 } 
}


void WDT_Init()
{
	*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x59;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x16;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x88;
	DrvSYS_SetIPClock(E_SYS_WDT_CLK,1);
	DrvSYS_SelectIPClockSource(E_SYS_WDT_CLKSRC,2);	 
	DrvWDT_Open(E_WDT_LEVEL7);
	DrvWDT_InstallISR((WDT_CALLBACK)WDT_CallBack);
   	DrvWDT_Ioctl(E_WDT_IOC_ENABLE_INT,0);
	DrvWDT_Ioctl(E_WDT_IOC_START_TIMER,0);	
    DrvWDT_Ioctl(E_WDT_IOC_ENABLE_RESET_FUNC,0);
    *((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x00;;
}




void Init_MCU()
{
	*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x59;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x16;*((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x88;
	DrvSYS_SetOscCtrl(E_SYS_OSC22M,1);
    *((volatile uint32_t *)(((( uint32_t)0x50000000) + 0x00000) + 0x100)) = 0x00;;

	PWM_init();
	UART_init();
	GPIO_init();
	ADC_init();




	Init_Timer2();
}

void main(void)
{

    Init_MCU();











	ADDR_485 = 0XF0;




 	






	DrvGPIO_SetBit(E_PORT3, E_PIN2);
	Led_Test_FLASHING = 1;

	DrvGPIO_SetBit(E_PORT3, E_PIN7);

	SetBL_PWM(270);

	DrvGPIO_ClrBit(E_PORT0, E_PIN5);

	DrvGPIO_ClrBit(E_PORT4, E_PIN4);

	DrvGPIO_ClrBit(E_PORT4, E_PIN5);



	DrvGPIO_SetBit(E_PORT0, E_PIN0);			
	DrvGPIO_ClrBit(E_PORT3, E_PIN7);			

	DrvGPIO_ClrBit(E_PORT3, E_PIN3);			


	DrvGPIO_SetBit(E_PORT3, E_PIN6);		

	DrvGPIO_ClrBit(E_PORT3, E_PIN5);

	DrvGPIO_SetBit(E_PORT3, E_PIN4);

 
    while (1)
	{







	Uart0_Handle();
	Uart1_Handle();
	if(ADC_Flag==1)
	{
		ADC_HANDLE();
	}
	  		


	}
}

