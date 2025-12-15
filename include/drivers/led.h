#ifndef LED_H
#define LED_H

#include <REGX52.H>

// LED引脚定义
sbit WORKING = P1 ^ 0;        // 正常工作
sbit DETECTED_CARD = P1 ^ 1;  // 检测到卡
sbit DETECTED_TRUE_CARD = P1 ^ 2; // 检测到正确卡

/**
 * @brief 初始化LED，熄灭所有LED
 */
void led_init(void);

/**
 * @brief 闪烁所有LED，用于自检（持续2s，每秒闪烁10次）
 */
void led_flash(void);

#endif // LED_H
