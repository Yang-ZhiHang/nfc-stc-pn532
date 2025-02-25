#ifndef __UART_H__
#define __UART_H__

/**
 * @brief  初始化微处理机的串口配置，波特率为115200
 */
void UART_Init();

/**
 * @brief  发送一个字节；data 是关键字，所以使用 data 作为变量名
 */
void UART_SendByte(unsigned char dat);

/**
 * @brief  接受一个字节
 */
unsigned char UART_ReceiveByte();

/**
 * @brief  清楚缓存区
 */
void UART_ClearBuffer();

#endif
