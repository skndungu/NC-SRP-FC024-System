#include <Arduino.h>
#include "main.h"

void setupVoltage()
{
  pinMode(VOLT_SENSE_1_PIN, INPUT_PULLDOWN);
  pinMode(VOLT_SENSE_2_PIN, INPUT_PULLDOWN);
  pinMode(VOLT_SENSE_3_PIN, INPUT_PULLDOWN);
  pinMode(VOLT_SENSE_4_PIN, INPUT_PULLDOWN);
}

void is18VoltsDetected(int voltagePin)
{
  bool is18Volts = digitalRead(voltagePin);

  if (is18Volts)
  {
    changeRelayStatus(1);

    // turn on default led, to indicate relay is on
    if (!isTemperatureEditMode)
      turnOnLED(DEFAULT_TEMPERATURE);
  }
  else
  {
    changeRelayStatus(0);

    if (!isTemperatureEditMode)
      turnOffAllLEDs();
  }
}
