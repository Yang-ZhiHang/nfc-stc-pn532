#include "drivers/led.h"
#include "utils/delay.h"

void led_init(void) {
    DETECTED_CARD = 0;
    DETECTED_TRUE_CARD = 0;
    WORKING = 0;
}

void led_flash(void) {
    unsigned char i;
    for (i = 0; i < 20; i++) {
        DETECTED_CARD = 1;
        DETECTED_TRUE_CARD = 1;
        WORKING = 1;
        delay_50ms();
        DETECTED_CARD = 0;
        DETECTED_TRUE_CARD = 0;
        WORKING = 0;
        delay_50ms();
    }
}
