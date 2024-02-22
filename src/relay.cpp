#include <Arduino.h>
#include "main.h"

void setupRelay()
{
  // initialize pin types
  pinMode(RELAY_TRIGGER_PIN, OUTPUT);
}

void changeRelayStatus(int state)
{
  digitalWrite(RELAY_TRIGGER_PIN, state);
  Serial.println("Turning relay state to " + String(state));
}
