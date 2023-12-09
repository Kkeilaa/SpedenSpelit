#ifndef DISPLAY_H
#define DISPLAY_H
#include <arduino.h>

extern const int numerolista[10] = {1, 79, 18, 6, 76, 36, 32, 15, 0, 4};

extern const int reset=6;
extern const int shiftClock=5;
extern const int latchClock=4;
extern const int outEnable=3;
extern const int serialInput=2;

void initializeDisplay(void);

void writeByte(uint8_t number, bool last);

void writeHighAndLowNumber(uint8_t tens,uint8_t ones);

void showResult(byte result);

#endif
