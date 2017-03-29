#ifndef __ADC_H__
#define __ADC_H__

#ifdef _ADC_C_
	#define _ADCDEC_
#else
	#define _ADCDEC_ extern
#endif
#define GCR_BA          0x50000000UL
#define VTEMPCR			(*((volatile unsigned long *) (GCR_BA+0x0000001C)))

#define AD0   E_PORT1, E_PIN0
#define AD1   E_PORT1, E_PIN1
#define AD4   E_PORT1, E_PIN4
#define AD5   E_PORT1, E_PIN5
#define AD6   E_PORT1, E_PIN6
#define AD7   E_PORT1, E_PIN7

#define PHOTO_SENSOR_ADVALUE_MAX   4000
#define PHOTO_SENSOR_ADVALUE_MIN   100
#define TempZero 40
 
#define TFT_CURR_AVERAGE    TFT_CURR[0]
#define	SENSOR_AVERAGE      SENSOR[0] 
#define	BACK_TEMP_AVERAGE   BACK_TEMP[0]
#define	IN_VOLTAGE_AVERAGE  IN_VOLTAGE[0]
#define	BL_CURR_AVERAGE     BL_CURR[0]
#define	SYS_TEMP_AVERAGE    SYS_TEMP[0]
#define AD_BUFFER_NUM 6

_ADCDEC_ uint32_t TFT_CURR[AD_BUFFER_NUM];
_ADCDEC_ uint32_t SENSOR[AD_BUFFER_NUM];
_ADCDEC_ uint32_t BACK_TEMP[AD_BUFFER_NUM];
_ADCDEC_ uint32_t IN_VOLTAGE[AD_BUFFER_NUM];
_ADCDEC_ uint32_t BL_CURR[AD_BUFFER_NUM];
_ADCDEC_ uint32_t SYS_TEMP[AD_BUFFER_NUM];
_ADCDEC_ uint8_t  TFT_CURR_VALUE;
_ADCDEC_ uint8_t  SENSOR_VALUE; 
_ADCDEC_ uint8_t  BACK_TEMP_VALUE;
_ADCDEC_ uint8_t  IN_VOLTAGE_VALUE;
_ADCDEC_ uint8_t  BL_CURR_VALUE;
_ADCDEC_ uint8_t  SYS_TEMP_VALUE;
_ADCDEC_ uint8_t  ADC_Flag;

_ADCDEC_ void ADC_init(void);
_ADCDEC_ uint32_t GetADC(uint8_t ChannelNum);
_ADCDEC_ void ADC_HANDLE(void);
_ADCDEC_ uint8_t PowerInputCheck(void);
 

#endif