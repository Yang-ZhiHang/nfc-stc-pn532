#include "uart.h"
#include <REGX52.H>

// UART初始化，波特率115200
void UART_Init(void) {
    SCON = 0x50;  // 8位数据,可变波特率

    // 使用定时器2作为波特率发生器
    RCAP2H = 0xFF;  // 115200波特率对应的重装值
    RCAP2L = 0xFD;
    TH2 = 0xFF;  // 定时器2初值
    TL2 = 0xFD;

    // 定时器2控制位
    T2CON = 0x34;  // RCLK=1,TCLK=1,TR2=1

    // 清除标志位
    TI = 0;
    RI = 0;
}

// 发送一个字节
void UART_SendByte(unsigned char dat) {
    SBUF = dat;
    while (!TI);    // 等待发送完成
    TI = 0;         // 清除发送完成标志
}

// 接收一个字节
unsigned char UART_ReceiveByte(void) {
    unsigned char dat;
    while (!RI);    // 等待接收完成
    RI = 0;         // 清除接收完成标志
    dat = SBUF;
    return dat;
}

void UART_ClearBuffer(void) {
    while (RI) {
        RI = 0;
        SBUF;  // 读取并丢弃数据
    }
}
