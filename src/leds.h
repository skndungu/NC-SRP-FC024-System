#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include "main.h"

void setupLeds();
void turnOnLED(int temp);
void turnOffAllLEDs();

#endif