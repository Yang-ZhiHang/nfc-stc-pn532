#include "servo.h"
#include <REGX52.H>
#include "Delay.h"

sbit SERVO = P1 ^ 4;  // 舵机信号线连接到P1.4

// 这里涉及到一个知识点：驱动舵机需要PWM信号，0.5-2.5ms 表示转动 0-180°
void Servo_SetAngleTime(unsigned char angle, unsigned int duration) {
    unsigned int pwm_count = duration / 20;
    while (pwm_count--) {
        if (angle == 0) {
            SERVO = 1;
            Delay500us();
            SERVO = 0;
            Delay19500us();
        } else if (angle == 45) {
            SERVO = 1;
            Delay1000us();
            SERVO = 0;
            Delay19000us();
        } else if (angle == 90) {
            SERVO = 1;
            Delay1500us();
            SERVO = 0;
            Delay18500us();
        } else if (angle == 135) {
            SERVO = 1;
            Delay2000us();
            SERVO = 0;
            Delay18000us();
        } else if (angle == 180) {
            SERVO = 1;
            Delay2500us();
            SERVO = 0;
            Delay17500us();
        }
    }
}

void Servo_Init() {
    Servo_SetAngleTime(180, 1000);
}