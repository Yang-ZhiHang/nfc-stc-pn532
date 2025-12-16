#ifndef BUZZER_H
#define BUZZER_H

#include <REGX52.H>
#include "intelli.h"

// 蜂鸣器引脚定义
sbit BUZZER = P1 ^ 3;

// 频率范围常量
#define BUZZER_MIN_FREQUENCY 1
#define BUZZER_MAX_FREQUENCY 500

/**
 * @brief 蜂鸣器以一定频率响指定时间（单位：毫秒）
 * @param ms 毫秒
 * @param frequency 频率
 */
void buzzer_time(unsigned int ms, unsigned int frequency);

#endif // BUZZER_H