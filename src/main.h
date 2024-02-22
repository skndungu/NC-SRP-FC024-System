#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <Preferences.h>
#include "temperature.h"
#include "voltage.h"
#include "relay.h"
#include "leds.h"

#define VOLT_SENSE_1_PIN 33
#define VOLT_SENSE_2_PIN 25
#define VOLT_SENSE_3_PIN 26
#define VOLT_SENSE_4_PIN 27

#define TEMP_SENSE_PIN 4

#define TEMP_UP_BUTTON_PIN 34
#define TEMP_DOWN_BUTTON_PIN 35
#define TEMP_SET_BUTTON_PIN 32

#define RELAY_TRIGGER_PIN 5

#define DEFAULT_TEMPERATURE 45.0
#define TEMPERATURE_OFFSET 1.0

extern Preferences preferences;

#endif