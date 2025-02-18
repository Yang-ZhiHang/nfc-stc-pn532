#include "delay.h"
#include <INTRINS.H>

void Delay500us()  //@11.0592MHz
{
    unsigned char i;

    _nop_();
    i = 227;
    while (--i)
        ;
}
void Delay1000us()  //@11.0592MHz
{
    unsigned char i, j;

    _nop_();
    i = 2;
    j = 199;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay1240us()		//@11.0592MHz
{
	unsigned char i, j;

	i = 3;
	j = 53;
	do
	{
		while (--j);
	} while (--i);
}

void Delay1500us()  //@11.0592MHz
{
    unsigned char i, j;

    i = 3;
    j = 173;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay2000us()  //@11.0592MHz
{
    unsigned char i, j;

    _nop_();
    i = 4;
    j = 146;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay2500us()  //@11.0592MHz
{
    unsigned char i, j;

    i = 5;
    j = 120;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay17500us()  //@11.0592MHz
{
    unsigned char i, j;

    i = 32;
    j = 93;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay18000us()  //@11.0592MHz
{
    unsigned char i, j;

    i = 33;
    j = 66;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay18500us()  //@11.0592MHz
{
    unsigned char i, j;

    _nop_();
    i = 34;
    j = 39;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay18760us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 34;
	j = 159;
	do
	{
		while (--j);
	} while (--i);
}

void Delay19000us()  //@11.0592MHz
{
    unsigned char i, j;

    i = 35;
    j = 13;
    do {
        while (--j)
            ;
    } while (--i);
}
void Delay19500us()  //@11.0592MHz
{
    unsigned char i, j;

    _nop_();
    i = 35;
    j = 243;
    do {
        while (--j)
            ;
    } while (--i);
}

void Delay(unsigned int ms)  //@11.0592MHz
{
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

void Delay50ms()  //@11.0592MHz
{
    unsigned char i, j;

    i = 90;
    j = 163;
    do {
        while (--j)
            ;
    } while (--i);
}

void Delay125ms()  //@11.0592MHz
{
    unsigned char i, j;

    i = 225;
    j = 28;
    do {
        while (--j)
            ;
    } while (--i);
}

void Delay1000ms()  //@11.0592MHz
{
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

void Delay2000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 15;
	j = 2;
	k = 235;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

