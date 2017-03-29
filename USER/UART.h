/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2010 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#ifndef __UART_H__
#define __UART_H__

#ifdef _UART_C_
	#define _UARTDEC_
#else
	#define _UARTDEC_ extern
#endif

typedef struct
{
	char AD_Board_BL_Mode_Status;
	char AD_Board_BL_Level_Status;
	char AD_Board_BL_EN_Status;
	char AD_Board_Channel_Status;
	char AD_Board_Monitor_Status;
}Struct_DATA;
_UARTDEC_ Struct_DATA AD_Board_Data;

_UARTDEC_  uint8_t  UART0_Buffer[20];
_UARTDEC_  uint8_t  UART0_Send_Buffer[20];
_UARTDEC_  uint8_t  UART1_Buffer[20];
_UARTDEC_  uint8_t  UART1_Send_Buffer[20];

_UARTDEC_  uint8_t  AD_BOARD_BL_FLAG;
_UARTDEC_  uint8_t  AD_BOARD_CHANNAL_FLAG;
_UARTDEC_  uint8_t  AD_BOARD_BL_STATUS_FLAG;
_UARTDEC_  uint8_t  BL_MODE_Status;
_UARTDEC_  uint8_t  BL_LEVEL_Status;
_UARTDEC_  uint8_t  BL_EN_Status;
_UARTDEC_  uint8_t  AD_BOARD_CHANNAL_Stasus;
_UARTDEC_  uint8_t  ADDR_485;

_UARTDEC_ void UART_Init(void);
_UARTDEC_ void UART0_SEND(uint8_t *BufferPtr, uint32_t Length);
_UARTDEC_ void UART1_SEND(uint8_t *BufferPtr, uint32_t Length);
_UARTDEC_ uint8_t UART0_INT_HANDLE(uint32_t u32IntStatus);
_UARTDEC_ uint8_t UART1_INT_HANDLE(uint32_t u32IntStatus);
_UARTDEC_ void Uart0_Handle();
_UARTDEC_ void Uart1_Handle();
_UARTDEC_ void Send_Data_To_PC (uint8_t c);
_UARTDEC_ uint8_t Receive_Data_From_PC(void);
_UARTDEC_ void Show_Pass(void);
_UARTDEC_ void Show_Fail(void);
//_UARTDEC_ uint8_t RS485_INT_HANDLE(uint32_t u32IntStatus);
_UARTDEC_ uint16_t Table_lookup(uint16_t x_AD);
_UARTDEC_ int MUX_filter(int AD);
_UARTDEC_ uint16_t AD_CONS(char channel);





#endif
