#ifndef __LED_H__
#define __LED_H__

#include <REGX52.H>

sbit WORKING = P1 ^ 0; // 正常工作
sbit DETECTED_CARD = P1 ^ 1; // 检测到卡
sbit DETECTED_TRUE_CARD = P1 ^ 2; // 检测到正确卡

/**
 * @brief  初始化LED，熄灭所有LED
 */
void led_init();

/**
 * @brief  闪烁所有LED，用于自检（持续2s，每秒闪烁10次）
 */
void led_flash();

#endif
