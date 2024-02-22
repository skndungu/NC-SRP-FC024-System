#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <Arduino.h>
#include "main.h"

extern float setTemperature;
extern float newTemperature;
extern bool isTemperatureEditMode;

void setupTemp();
void readTemperature();
void setNewTemperature();

#endif