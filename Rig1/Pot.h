#ifndef Pot_h
#define Pot_h

#include <MBR_Pot.h>

uint8_t potPin = 7;
float potVcc = 5.0;
MBR_Pot pot1(potPin, potVcc);


#endif