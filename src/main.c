/**
 * 开发环境 Keil5
 * 烧录程序 STC-ISP
 * 单片机 STC89C52-35I
 * 外接晶振 11.0592MHz
 * 波特率 115200
 * NFC模块 PN532 (NFC Module V3) HSU 协议
 */

#include "drivers/servo.h"
#include "drivers/buzzer.h"
#include "utils/delay.h"
#include "drivers/led.h"
#include "drivers/nfc.h"
#include "drivers/uart.h"

unsigned char status = 0;
unsigned char uid[4];
unsigned char i;

// 正确卡片的UID
const unsigned char NFC_SPECIAL_CARD_UID[] = {0x7d, 0xd4, 0xb5, 0x01};

void main() {
    // ===== 自检 start =====
    // led_flash();  // LED自检
    // Servo_SetAngleTime(90, 3000); // 舵机自检
    // ===== 自检 end =======
    
    // ===== 初始化 start =====
    servo_init();  // 初始化舵机（归位）
    led_init();    // 初始化LED
    uart_init();   // 初始化串口
    nfc_init();    // 初始化NFC模块
    // ===== 初始化 end =======

    while (1) {
        led_init();  // 状态重置
        WORKING = 1;  // 工作指示灯
        status = nfc_read_uid(uid);  // 读取状态
        delay_1000ms();
        if (status) {
            WORKING = 0;
            DETECTED_CARD = 1;

            // 检测到正确的卡片
            if (uid[0] == NFC_SPECIAL_CARD_UID[0] && uid[1] == NFC_SPECIAL_CARD_UID[1] &&
                uid[2] == NFC_SPECIAL_CARD_UID[2] && uid[3] == NFC_SPECIAL_CARD_UID[3]) {
                DETECTED_TRUE_CARD = 1;
                buzzer_time(100, 1000);  // 提示音
                servo_set_angle_time(90, 3000);
                servo_set_angle_time(0, 1000);
            }
            // 检测到不正确卡片
            else {
                DETECTED_TRUE_CARD = 0;
                for (i = 0; i < 3; i++) {
                    buzzer_time(50, 1000);
                    delay(50);
                }
            }
        } else {
            DETECTED_CARD = 0;
            DETECTED_TRUE_CARD = 0;
        }
    }
}