#ifndef UART_H
#define UART_H

/**
 * @brief 初始化微处理机的串口配置，波特率为115200
 */
void uart_init(void);

/**
 * @brief 发送一个字节
 */
void uart_send_byte(unsigned char dat);

/**
 * @brief 接收一个字节
 */
unsigned char uart_receive_byte(void);

/**
 * @brief 清除缓存区
 */
void uart_clear_buffer(void);

#endif // UART_H
