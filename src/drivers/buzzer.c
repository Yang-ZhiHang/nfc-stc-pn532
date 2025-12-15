#include "drivers/buzzer.h"
#include "utils/delay.h"

void buzzer_time(unsigned int ms, unsigned int frequency)
{
    unsigned long i;
    unsigned long period;
    unsigned long halfPeriod;

    // 限制频率范围
    if (frequency < BUZZER_MIN_FREQUENCY) frequency = BUZZER_MIN_FREQUENCY;
    if (frequency > BUZZER_MAX_FREQUENCY) frequency = BUZZER_MAX_FREQUENCY;

    period = 1000 / frequency;
    halfPeriod = period / 2;

    for (i = 0; i < ms; i += period)
    {
        BUZZER = !BUZZER;
        delay(halfPeriod);
        BUZZER = !BUZZER;
        delay(halfPeriod);
    }
}