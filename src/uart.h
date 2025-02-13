#ifndef __UART_H__
#define __UART_H__

void UART_Init();
void UART_SendByte(unsigned char dat);
unsigned char UART_ReceiveByte();
void UART_ClearBuffer();

#endif
