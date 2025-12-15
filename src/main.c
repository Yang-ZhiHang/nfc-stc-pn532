/**
 * 开发环境 Keil5
 * 烧录程序 STC-ISP
 * 单片机 STC89C52-35I
 * 外接晶振 11.0592MHz
 * 波特率 115200
 * NFC模块 PN532 (NFC Module V3) HSU 协议
 */

#include "drivers/buzzer.h"
#include "drivers/led.h"
#include "drivers/nfc.h"
#include "drivers/servo.h"
#include "drivers/uart.h"
#include "utils/delay.h"

typedef enum { STATE_IDLE, STATE_READING, STATE_SUCCESS, STATE_FAIL } SystemState;

unsigned char status = 0;
unsigned char uid[4];
unsigned char i;

// 正确卡片的UID
const unsigned char NFC_SPECIAL_CARD_UID[] = {0x7d, 0xd4, 0xb5, 0x01};

// 检查 UID 是否匹配
unsigned char check_uid_match(unsigned char* uid1, const unsigned char* uid2, unsigned char len) {
    unsigned char j;
    for (j = 0; j < len; j++) {
        if (uid1[j] != uid2[j])
            return 0;
    }
    return 1;
}

void handle_success() {
    DETECTED_TRUE_CARD = 1;
    buzzer_time(100, 1000);
    servo_set_angle_time(90, 3000);
    servo_set_angle_time(0, 1000);
}

void handle_fail() {
    DETECTED_TRUE_CARD = 0;
    for (i = 0; i < 3; i++) {
        buzzer_time(50, 1000);
        delay(50);
    }
}

void main() {
    SystemState current_state = STATE_IDLE;

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
        switch (current_state) {
            case STATE_IDLE:
                WORKING = 1;
                status = nfc_read_uid(uid);
                if (status) {
                    WORKING = 0;
                    DETECTED_CARD = 1;
                    current_state = STATE_READING;
                } else {
                    DETECTED_CARD = 0;
                    DETECTED_TRUE_CARD = 0;
                }
                delay_1000ms();
                break;

            case STATE_READING:
                if (check_uid_match(uid, NFC_SPECIAL_CARD_UID, 4)) {
                    current_state = STATE_SUCCESS;
                } else {
                    current_state = STATE_FAIL;
                }
                break;

            case STATE_SUCCESS:
                handle_success();
                current_state = STATE_IDLE;
                break;

            case STATE_FAIL:
                handle_fail();
                current_state = STATE_IDLE;
                break;
        }
    }
}