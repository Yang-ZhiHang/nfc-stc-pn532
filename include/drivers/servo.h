#ifndef SERVO_H
#define SERVO_H

#include <REGX52.H>

// 舵机引脚定义
sbit SERVO = P1 ^ 4;

/**
 * @brief 持续输出特定角度的PWM信号
 * @param angle: 角度（0/45/90/135/180）
 * @param duration: 持续时间，单位ms
 */
void servo_set_angle_time(unsigned char angle, unsigned int duration);

/**
 * @brief 初始化舵机角度
 */
void servo_init(void);

#endif // SERVO_H
