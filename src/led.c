#include "led.h"
#include "delay.h"

void led_init() {
    DETECTED_CARD = 0;
    DETECTED_TRUE_CARD = 0;
    WORKING = 0;
}

void led_flash() {
    unsigned char i;

    for (i = 0; i < 20; i++) {
        DETECTED_CARD = 1;
        DETECTED_TRUE_CARD = 1;
        WORKING = 1;
        Delay50ms();
        DETECTED_CARD = 0;
        DETECTED_TRUE_CARD = 0;
        WORKING = 0;
        Delay50ms();
    }
}
