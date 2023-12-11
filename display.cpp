#include "display.h"


void initializeDisplay(void)
{
	const int reset=6;
	const int shiftClock=5;
	const int latchClock=4;
	const int outEnable=3;
	const int serialInput=2;

	pinMode(reset, OUTPUT);
	pinMode(shiftClock, OUTPUT);
	pinMode(latchClock, OUTPUT);
	pinMode(outEnable, OUTPUT);
	pinMode(serialInput, OUTPUT);
}


void writeByte(uint8_t number,bool last)
{
  digitalWrite(latchClock, LOW);

  uint8_t luku = ~numerolista[number];
  for(int i=0; i < 8; i++)
  {
    digitalWrite(shiftClock, LOW);
    int bitti = luku >> i;
    if(bitti & 1 == 1){
      digitalWrite(serialInput, HIGH);
    }else
      digitalWrite(serialInput, LOW);
    
    digitalWrite(shiftClock, HIGH);
  }
  if(last)
  {
    digitalWrite(latchClock, HIGH);
  }
}


void writeHighAndLowNumber(uint8_t tens,uint8_t ones)
{
  writeByte(ones, false);
  writeByte(tens, true);
}

void showResult(byte result)
{
  if(result<10){
    writeByte(result, false);
    writeByte(0, true);
  }
  else
  {
    uint8_t ykkoset = result%10;
    uint8_t kympit = (result-ykkoset)/10;
    writeHighAndLowNumber(kympit, ykkoset);
  }
}

