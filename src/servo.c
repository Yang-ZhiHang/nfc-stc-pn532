#include "servo.h"
#include <REGX52.H>
#include "Delay.h"

sbit SERVO = P1 ^ 4;  // 舵机信号线连接到P1.4

// 驱动舵机需要 PWM 信号，周期为 20ms，周期内高电平 0.5-2.5ms 表示转动 0-180°
void Servo_SetAngleTime(unsigned char angle, unsigned int duration) {
    unsigned int pwm_count = duration / 20;
    if (angle == 0) {
        while (pwm_count) {
            SERVO = 1;
            Delay500us();
            SERVO = 0;
            Delay19500us();
            --pwm_count;
        }
    } else if (angle == 45) {
        while (pwm_count) {
            SERVO = 1;
            Delay1000us();
            SERVO = 0;
            Delay19000us();
            --pwm_count;
        }
    } else if (angle == 67) {
        while (pwm_count) {
            SERVO = 1;
            Delay1240us();
            SERVO = 0;
            Delay18760us();
            --pwm_count;
        }
    } else if (angle == 90) {
        while (pwm_count) {
            SERVO = 1;
            Delay1500us();
            SERVO = 0;
            Delay18500us();
            --pwm_count;
        }
    } else if (angle == 135) {
        while (pwm_count) {
            SERVO = 1;
            Delay2000us();
            SERVO = 0;
            Delay18000us();
            --pwm_count;
        }
    } else if (angle == 180) {
        while (pwm_count) {
            SERVO = 1;
            Delay2500us();
            SERVO = 0;
            Delay17500us();
            --pwm_count;
        }
    }
}

void Servo_Init() {
    Servo_SetAngleTime(0, 1000);
}