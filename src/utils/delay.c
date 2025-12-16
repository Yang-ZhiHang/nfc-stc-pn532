#include "utils/delay.h"
#include <INTRINS.H>

// 均仅适用 @11.0592MHz

void delay_500us(void) {
    unsigned char i;

    _nop_();
    i = 227;
    while (--i)
        ;
}

void delay_1000us(void) {
    unsigned char i, j;

    _nop_();
    i = 2;
    j = 199;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_1500us(void) {
    unsigned char i, j;

    i = 3;
    j = 173;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_2000us(void) {
    unsigned char i, j;

    _nop_();
    i = 4;
    j = 146;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_2500us(void) {
    unsigned char i, j;

    i = 5;
    j = 120;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_17500us(void) {
    unsigned char i, j;

    i = 32;
    j = 93;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_18000us(void) {
    unsigned char i, j;

    i = 33;
    j = 66;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_18500us(void) {
    unsigned char i, j;

    _nop_();
    i = 34;
    j = 39;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_19000us(void) {
    unsigned char i, j;

    i = 35;
    j = 13;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_19500us(void) {
    unsigned char i, j;

    _nop_();
    i = 35;
    j = 243;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay(unsigned int ms) {
    unsigned char i, j;

    while (ms) {
        _nop_();
        i = 2;
        j = 199;
        do {
            while (--j)
                ;
        } while (--i);
        --ms;
    }
}

void delay_50ms(void) {
    unsigned char i, j;

    i = 90;
    j = 163;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_125ms(void) {
    unsigned char i, j;

    i = 225;
    j = 28;
    do {
        while (--j)
            ;
    } while (--i);
}

void delay_1000ms(void) {
    unsigned char i, j, k;

    _nop_();
    i = 8;
    j = 1;
    k = 243;
    do {
        do {
            while (--k)
                ;
        } while (--j);
    } while (--i);
}