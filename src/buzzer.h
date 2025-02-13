#ifndef __BUZZER_H__
#define __BUZZER_H__

#include <REGX52.H>

sbit BUZZER = P1 ^ 3;

/**
 * @brief 蜂鸣器以一定频率响指定时间（单位：毫秒）
 * @param ms 毫秒
 * @param frequency 频率
 */
void BuzzerTime(unsigned int ms, unsigned int frequency);

#endif