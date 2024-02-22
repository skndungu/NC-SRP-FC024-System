#include <Arduino.h>
#include "PCF8574.h"
#include "main.h"

// Set i2c address
PCF8574 pcf8574(0x20);

void setupLeds()
{
  Serial.println("Initializing pcf8574...");

  while (!pcf8574.begin())
  {
    Serial.println("Re-initializing pcf8574...");
  }

  pcf8574.pinMode(P0, OUTPUT);
  pcf8574.pinMode(P1, OUTPUT);
  pcf8574.pinMode(P2, OUTPUT);
  pcf8574.pinMode(P3, OUTPUT);
  pcf8574.pinMode(P4, OUTPUT);
  pcf8574.pinMode(P5, OUTPUT);
  pcf8574.pinMode(P6, OUTPUT);
  pcf8574.pinMode(P7, OUTPUT);
}

void turnOnLED(int temp)
{
  turnOffAllLEDs();

  switch (temp)
  {
  case 30:
    pcf8574.digitalWrite(P0, HIGH);
    break;
  case 35:
    pcf8574.digitalWrite(P1, HIGH);
    break;
  case 40:
    pcf8574.digitalWrite(P2, HIGH);
    break;
  case 45:
    pcf8574.digitalWrite(P3, HIGH);
    break;
  case 50:
    pcf8574.digitalWrite(P4, HIGH);
    break;
  case 55:
    pcf8574.digitalWrite(P5, HIGH);
    break;
  case 60:
    pcf8574.digitalWrite(P6, HIGH);
    break;
  case 65:
    pcf8574.digitalWrite(P7, HIGH);
    break;

  default:
    break;
  }
}

void turnOffAllLEDs()
{
  pcf8574.digitalWrite(P0, LOW);
  pcf8574.digitalWrite(P1, LOW);
  pcf8574.digitalWrite(P2, LOW);
  pcf8574.digitalWrite(P3, LOW);
  pcf8574.digitalWrite(P4, LOW);
  pcf8574.digitalWrite(P5, LOW);
  pcf8574.digitalWrite(P6, LOW);
  pcf8574.digitalWrite(P7, LOW);
}