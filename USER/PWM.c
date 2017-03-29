#define _PWM_C_

#include <stdio.h>
#include "M051Series.h"
#include "DrvADC.h"
#include "DrvPWM.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "global.h"
#include "pwm.h"
extern uint16_t wPWM_CMR0_Num,wPWM_CMR1_Num;

#define _PWM_C_
void PWM_init()

 {
 	/* Step 1. GPIO initial */
	DrvGPIO_InitFunction(E_FUNC_PWM01_P4);  
//	DrvGPIO_InitFunction(E_FUNC_PWM23_P4); 
	//SYS->GPAMFP.PWM2=1;				
	/* Step 2. Enable and Select PWM clock source*/
	//Enable PWM clock	
	SYSCLK->APBCLK.PWM01_EN = 1;
	SYSCLK->APBCLK.PWM23_EN = 1;
	//Select 22.1184Mhz for PWM clock source
	SYSCLK->CLKSEL1.PWM01_S = 3;
	SYSCLK->CLKSEL1.PWM23_S = 3;
	// PWM clock = clock source/(Prescaler + 1)/divider	
	//Prescaler 0~255, Setting 0 to stop output clock
	PWMA->PPR.CP01=1;
	PWMA->PPR.CP23=1;
	//clock divider->0:/2, 1:/4, 2:/8, 3:/16, 4:/1
	PWMA->CSR.CSR1=0;
	PWMA->CSR.CSR2=0;					 									         
	/* Step 3. Select PWM Operation mode */
	//0:One-shot mode, 1:Auto-load mode
	//CNR and CMR will be auto-cleared after setting CH0MOD form 0 to 1.
    PWMA->PCR.CH0MOD=1;
	PWMA->PCR.CH1MOD=1;
	PWMA->PCR.CH2MOD=1;
	PWMA->PCR.CH3MOD=1;
		//Inverter->0:off, 1:on
	PWMA->PCR.CH0INV=1;
	PWMA->PCR.CH1INV=0;
	PWMA->PCR.CH2INV=0;
	PWMA->PCR.CH3INV=0;
	 //Dead-Zone->0:Disable, 1:Enable
	PWMA->PCR.DZEN01=0;
    PWMA->PCR.DZEN23=0;
	 /* Step 4. Select PWM frequency and duty */
	//Set CNR and CMR		
	PWMA->CNR0=5500/20;	//20khz
	PWMA->CMR0=100;

	PWMA->CNR1=5500/20;	//20khz
	PWMA->CMR1=100;

	PWMA->CNR2=5500/20;//275
	PWMA->CMR2=100;

	PWMA->CNR3=5500/20;	//20khz
	PWMA->CMR3=100;
	/* Step 5. Enable PWM output */
	//PWM function->0:Disable, 1:Enable 	
	PWMA->PCR.CH0EN=1;
//	PWMA->PCR.CH1EN=1;
//	PWMA->PCR.CH2EN=1;
//	PWMA->PCR.CH3EN=1;
		
	//Output to pin->0:Diasble, 1:Enable
	PWMA->POE.PWM0=1;
//	PWMA->POE.PWM1=1;
//	PWMA->POE.PWM2=1;
//	PWMA->POE.PWM3=1;


//   S_DRVPWM_TIME_DATA_T sPt;
//   uint8_t volatile g_u8PWMCount = 100;
//
///* Enable PWM clock */
//	DrvPWM_Open();		
//	/* Set PWM pins */
//	DrvGPIO_InitFunction(E_FUNC_PWM01);	
//	/* PWM Timer property */ 
//	sPt.u8Mode = DRVPWM_AUTO_RELOAD_MODE;;																																																													                                                                                                                           
//	sPt.u32Frequency =250;
//	/* High Pulse peroid : Total Pulse peroid = 33 : 100 */
//	sPt.u8HighPulseRatio = 33;	
//	sPt.i32Inverter = 0;					
//	/* Select PWM engine clock */
//	DrvPWM_SelectClockSource(DRVPWM_TIMER0, DRVPWM_HCLK);	
//	/* Set PWM Timer0 Configuration */
//	DrvPWM_SetTimerClk(DRVPWM_TIMER0, &sPt);
//	/* Enable Output for PWM Timer0 */
//	DrvPWM_SetTimerIO(DRVPWM_TIMER0, 1);
//	/* Enable Interrupt Sources of PWM Timer0 and install call back function */
//	DrvPWM_EnableInt(DRVPWM_TIMER0, 0, DRVPWM_PwmIRQHandler);	
//	/* Enable the PWM Timer 0 */
//	DrvPWM_Enable(DRVPWM_TIMER0, 1);	
//	while (g_u8PWMCount);			
//	/* Disable the PWM Timer 0 */
//	DrvPWM_Enable(DRVPWM_TIMER0, 0);
}
void SetBL_PWM(uint8_t PWMvalue)
{
 	PWMA->CMR0=PWMvalue;
//	PWMA->CMR0=Slave.BL_MIN+(Slave.BL_MAX-Slave.BL_MIN)*PWMvalue/100;
//	printf("PWMA->CMR0:%d\r\n",PWMA->CMR0);
}