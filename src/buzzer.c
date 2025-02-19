#include "buzzer.h"
#include "delay.h"

// 定义频率范围常量
#define MIN_FREQUENCY 1
#define MAX_FREQUENCY 500

void BuzzerTime(unsigned int ms, unsigned int frequency)
{
    unsigned long i;
    unsigned long period;
    unsigned long halfPeriod;
    
    // 限制频率范围
    if (frequency < MIN_FREQUENCY) frequency = MIN_FREQUENCY;
    if (frequency > MAX_FREQUENCY) frequency = MAX_FREQUENCY;
    
    period = 1000 / frequency;
    halfPeriod = period / 2;
    
    for (i = 0; i < ms; i += period)
    {
        BUZZER = !BUZZER;
        Delay(halfPeriod);
        BUZZER = !BUZZER;
        Delay(halfPeriod);
    }
}