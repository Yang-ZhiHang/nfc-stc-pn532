#ifndef SERVO_H
#define SERVO_H

#include <REGX52.H>
#include "intelli.h"

// 舵机引脚定义
sbit SERVO = P1 ^ 4;

// 舵机可用角度
typedef enum {
    SERVO_ANGLE_0 = 0,
    SERVO_ANGLE_45 = 45,
    SERVO_ANGLE_90 = 90,
    SERVO_ANGLE_135 = 135,
    SERVO_ANGLE_180 = 180
} servo_angle_t;

/**
 * @brief 持续输出特定角度的PWM信号
 * @param angle 角度
 * @param duration 持续时间，单位毫秒
 */
void servo_set_angle_time(servo_angle_t angle, unsigned int duration);

/**
 * @brief 初始化舵机，归位到 0 度
 */
void servo_init(void);

#endif  // SERVO_H
