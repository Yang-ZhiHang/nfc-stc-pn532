#include "drivers/servo.h"
#include <REGX52.H>
#include "utils/delay.h"

// 驱动舵机需要 PWM 信号，周期为 20ms，周期内高电平 0.5-2.5ms 表示转动 0-180°
void servo_set_angle_time(servo_angle_t angle, unsigned int duration) {
    unsigned int pwm_count = duration / 20;
    if (angle == SERVO_ANGLE_0) {
        while (pwm_count) {
            SERVO = 1;
            delay_500us();
            SERVO = 0;
            delay_19500us();
            --pwm_count;
        }
    } else if (angle == SERVO_ANGLE_45) {
        while (pwm_count) {
            SERVO = 1;
            delay_1000us();
            SERVO = 0;
            delay_19000us();
            --pwm_count;
        }
    } else if (angle == SERVO_ANGLE_90) {
        while (pwm_count) {
            SERVO = 1;
            delay_1500us();
            SERVO = 0;
            delay_18500us();
            --pwm_count;
        }
    } else if (angle == SERVO_ANGLE_135) {
        while (pwm_count) {
            SERVO = 1;
            delay_2000us();
            SERVO = 0;
            delay_18000us();
            --pwm_count;
        }
    } else if (angle == SERVO_ANGLE_180) {
        while (pwm_count) {
            SERVO = 1;
            delay_2500us();
            SERVO = 0;
            delay_17500us();
            --pwm_count;
        }
    }
}

void servo_init(void) {
    servo_set_angle_time(0, 1000);
}