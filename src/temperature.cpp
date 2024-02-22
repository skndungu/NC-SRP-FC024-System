#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "main.h"

float setTemperature;
float newTemperature;
bool isTemperatureEditMode;

// Setup a OneWire instance to communicate with any OneWire devices
OneWire oneWire(TEMP_SENSE_PIN);
// Pass our OneWire reference to Dallas Temperature sensor
DallasTemperature sensor(&oneWire);

void setupTemp()
{
  // initialize pin types
  pinMode(TEMP_UP_BUTTON_PIN, INPUT);
  pinMode(TEMP_DOWN_BUTTON_PIN, INPUT);
  pinMode(TEMP_SET_BUTTON_PIN, INPUT);

  // read set temperature from prefs
  preferences.begin("prefs", false);
  setTemperature = preferences.getFloat("setTemperature", DEFAULT_TEMPERATURE);
  newTemperature = setTemperature;
  preferences.end();
}

void readTemperature()
{
  sensor.requestTemperatures();
  // get temp in degrees celcius
  float temperature = sensor.getTempCByIndex(0);
  Serial.print("Read temperature is ");
  Serial.print(temperature);
  Serial.println(" ºC");

  // if temperature is greater than setTemperature and if difference is greater than offset
  if (temperature > setTemperature && (temperature - setTemperature) > TEMPERATURE_OFFSET)
  {
    changeRelayStatus(1);

    // turn on default led, to indicate relay is on
    if (!isTemperatureEditMode)
      turnOnLED(DEFAULT_TEMPERATURE);
  }

  // if temperature is less than setTemperature and if difference is greater than offset
  if (temperature < setTemperature && (setTemperature - temperature) >= TEMPERATURE_OFFSET)
  {
    changeRelayStatus(0);

    if (!isTemperatureEditMode)
      turnOffAllLEDs();
  }
}

void setNewTemperature()
{
  // increase temperature button press
  if (!digitalRead(TEMP_UP_BUTTON_PIN))
  {
    if (!isTemperatureEditMode)
    {
      turnOffAllLEDs();
      isTemperatureEditMode = true;
    }

    if (newTemperature < 65)
    {
      newTemperature = newTemperature + 5;
      turnOnLED(newTemperature);
    }
  }
  // decrease temperature button press
  if (!digitalRead(TEMP_DOWN_BUTTON_PIN))
  {
    if (!isTemperatureEditMode)
    {
      turnOffAllLEDs();
      isTemperatureEditMode = true;
    }

    if (newTemperature > 30)
    {
      newTemperature = newTemperature - 5;
      turnOnLED(newTemperature);
    }
  }
  // set temperature button press
  if (!digitalRead(TEMP_SET_BUTTON_PIN))
  {
    isTemperatureEditMode = false;

    setTemperature = newTemperature;
    turnOnLED(setTemperature);

    // save set temperature to prefs
    preferences.begin("prefs", false);
    setTemperature = preferences.putFloat("setTemperature", setTemperature);
    preferences.end();

    // a delay to show saved temperature setpoint led
    delay(2000);
    turnOffAllLEDs();
  }
}
