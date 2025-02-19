/**
 * 开发环境 Keil5
 * 烧录程序 STC-ISP
 * 单片机 STC89C52 35I-PDIP40 1852HVG426.X90C
 * 外接晶振 11.0592MHz
 * 波特率 115200
 * NFC模块 PN532 (NFC Module V3) HSU 协议
 */

#include "Servo.h"
#include "buzzer.h"
#include "delay.h"
#include "led.h"
#include "nfc.h"
#include "uart.h"

void open_door();

void main() {
    unsigned char status = 0;
    unsigned char uid[4];
    unsigned char i;

    // 正确卡片的UID
    const unsigned char NFC_SPECIAL_CARD_UID[] = {0x7d, 0xd4, 0xb5, 0x01};

    led_flash();  // LED自检

    // ===== 舵机自检 start =====
    Servo_SetAngleTime(45, 1000);
    Servo_SetAngleTime(67, 1000);
    // ===== 舵机自检 end =======
    
    Servo_Init();  // 初始化舵机（自检后归位）
    led_init();    // 初始化LED
    UART_Init();   // 初始化串口
    NFC_Init();    // 初始化NFC模块

    while (1) {
        led_init();  // 状态重置
        WORKING = 1;
        status = NFC_ReadUID(uid);
        Delay1000ms();
        if (status) {
            WORKING = 0;
            DETECTED_CARD = 1;

            // 检测到正确的卡片
            if (uid[0] == NFC_SPECIAL_CARD_UID[0] && uid[1] == NFC_SPECIAL_CARD_UID[1] &&
                uid[2] == NFC_SPECIAL_CARD_UID[2] && uid[3] == NFC_SPECIAL_CARD_UID[3]) {
                DETECTED_TRUE_CARD = 1;
                BuzzerTime(100, 1000);  // 提示音
                Servo_SetAngleTime(90, 3000);
                Servo_SetAngleTime(0, 1000);
            }
            // 检测到不正确卡片
            else {
                DETECTED_TRUE_CARD = 0;
                for (i = 0; i < 3; i++) {
                    BuzzerTime(50, 1000);
                    Delay(50);
                }
            }
        } else {
            DETECTED_CARD = 0;
            DETECTED_TRUE_CARD = 0;
        }
    }
}