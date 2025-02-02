// Led.h

#ifndef _LED_h
#define _LED_h

#include "arduino.h"
#include <Ticker.h>

class Led
{
protected:
    static uint8_t io;
    static uint8_t light;
    static Ticker *ledTicker;
    static Ticker *ledTicker2;
    static uint8_t ledType;

public:
    static void init(uint8_t _io, uint8_t _light);
    static void loop();
    static void led(int ms = 200);
    static void blinkLED(int duration, int n);
};

#endif
