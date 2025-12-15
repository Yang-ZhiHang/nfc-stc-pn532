#include "drivers/uart.h"
#include <REGX52.H>

void uart_init(void) {
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

void uart_send_byte(unsigned char dat) {
    SBUF = dat;
    while (!TI);    // 等待发送完成
    TI = 0;         // 清除发送完成标志
}

unsigned char uart_receive_byte(void) {
    unsigned char dat;
    while (!RI);    // 等待接收完成
    RI = 0;         // 清除接收完成标志
    dat = SBUF;
    return dat;
}

void uart_clear_buffer(void) {
    while (RI) {
        RI = 0;
        SBUF;  // 读取并丢弃数据
    }
}
