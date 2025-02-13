#ifndef __LED_H__
#define __LED_H__

#include <REGX52.H>

sbit WORKING = P1 ^ 0; // 正常工作
sbit DETECTED_CARD = P1 ^ 1; // 检测到卡
sbit DETECTED_TRUE_CARD = P1 ^ 2; // 检测到正确卡

void led_init();
void led_flash();

#endif
