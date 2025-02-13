#ifndef __SERVO_H__
#define __SERVO_H__

/**
 * @brief  持续输出特定角度的PWM信号
 * @param  angle: 角度（0/90/180）
 * @param  duration: 持续时间，单位ms
 */
void Servo_SetAngleTime(unsigned char angle, unsigned int duration);

/**
 * @brief  初始化舵机角度
 */
void Servo_Init();

#endif
