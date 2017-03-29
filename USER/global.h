#define WDT_ENABLE  0

//
//#define MIGN (1<<0)
//#define SIGN (1<<1)
//#define PowerSwitch (1<<2)
//#define ShortPress_Plus (1<<3)
//#define longPress_Plus (1<<4)
//#define ShortPress_Minus (1<<5)
//#define longPress_Minus (1<<6)
//#define IGNControl (1<<7)

//#define MASTER_ON  1
//#define LCD_BL_ON  2
//#define LCD_ON     4
//#define TFT_ON     4
//#define TOUCH_ON   8
//#define USB_ON	   16
//#define AT_STATUS  32

#define K0                   E_PORT2, E_PIN0
#define K1					 E_PORT2, E_PIN1
#define K2					 E_PORT2, E_PIN2
#define K3 					 E_PORT2, E_PIN3
#define K4 					 E_PORT2, E_PIN4
#define K5					 E_PORT2, E_PIN5
#define LED_G				 E_PORT2, E_PIN6
#define LED_R				 E_PORT2, E_PIN7

//#define BL_EN_IN_IO		E_PORT1, E_PIN1
//#define AT_DET			E_PORT3, E_PIN6
//#define BL_DETECT		E_PORT4, E_PIN5

//#define Address0_485	E_PORT0, E_PIN6
//#define Address1_485	E_PORT0, E_PIN5
#define HPD2_DET			E_PORT0, E_PIN1
#define RX_DET				E_PORT0, E_PIN2
#define PI3HDX412BD_MS		E_PORT0, E_PIN0
#define PI3HDX412BD_OE		E_PORT3, E_PIN7
#define PI3HDX412BD_SEL1	E_PORT3, E_PIN6
#define PI3HDX412BD_DR		E_PORT3, E_PIN3
#define PI3HDX412BD_EQ2		E_PORT3, E_PIN5
#define PI3HDX412BD_EQ1		E_PORT3, E_PIN4
#define EN_BL			E_PORT3, E_PIN7
#define EN_BL_ON()		DrvGPIO_SetBit(EN_BL)
#define EN_BL_OFF()		DrvGPIO_ClrBit(EN_BL)
#define Video_Equalizer_SD			E_PORT4, E_PIN5
#define EN_Video_Equalizer_POWER	E_PORT3, E_PIN3
#define Video_Equalizer_POWER_ON()	DrvGPIO_ClrBit(EN_Video_Equalizer_POWER)
#define Video_Equalizer_POWER_OFF()	DrvGPIO_SetBit(EN_Video_Equalizer_POWER)
#define Video_Equalizer_EN			E_PORT4, E_PIN4
#define Video_Equalizer_EN_ON()		DrvGPIO_SetBit(Video_Equalizer_EN)
#define Video_Equalizer_EN_OFF()	DrvGPIO_ClrBit(Video_Equalizer_EN)
#define EN_AD_BRD	    E_PORT4, E_PIN2
#define AD_BRD_ON()		DrvGPIO_ClrBit(EN_AD_BRD)
#define AD_BRD_OFF()	DrvGPIO_SetBit(EN_AD_BRD)

#define EN_TFT_12	    E_PORT0, E_PIN5
#define TFT_12_ON()		DrvGPIO_ClrBit(EN_TFT_12)
#define TFT_12_OFF()	DrvGPIO_SetBit(EN_TFT_12)
#define	LED_TEST		E_PORT3, E_PIN2
#define Led_Test_ON()   DrvGPIO_SetBit(LED_TEST)
#define Led_Test_OFF()	DrvGPIO_ClrBit(LED_TEST)
#define EN_12V	    	E_PORT0, E_PIN5
#define EN_12V_ON()		DrvGPIO_ClrBit(EN_12V)
#define EN_12V_OFF()	DrvGPIO_SetBit(EN_12V)
#define EN_3V3	    	E_PORT4, E_PIN5
#define EN_3V3_ON()		DrvGPIO_ClrBit(EN_3V3)
#define EN_3V3_OFF()	DrvGPIO_SetBit(EN_3V3)
#define EN_1V8	    	E_PORT4, E_PIN4
#define EN_1V8_ON()		DrvGPIO_ClrBit(EN_1V8)
#define EN_1V8_OFF()	DrvGPIO_SetBit(EN_1V8)

#define TFT_CURR_CHANNEL    0 
#define BL_CURR_CHANNEL 	1
#define IN_VOLTAGE_CHANNEL  4
#define SENSOR_CHANNEL		5
#define SYS_TEMP_CHANNEL	7
#define BACK_TEMP_CHANNEL	6

//#define EN_USB_1		E_PORT3, E_PIN5
//#define EN_USB_2		E_PORT4, E_PIN3
									 
#define PWM_MIN 20.0
#define PWM_MAX 275.0	//5500/20k
#define PWM_STEP 100.0
#define PWM_PER  ((PWM_MAX-PWM_MIN)/PWM_STEP)
#define PWM(x)   (uint16_t)(PWM_MIN+PWM_PER*x)

//#define PWM(x)   0x1250-x*520
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
//extern  volatile uint8_t  UART1_SendFlag;

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

#define Address_I2C_P13HDX412BD		0X50