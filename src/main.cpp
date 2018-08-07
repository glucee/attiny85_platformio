#include "../lib/rgbled/rgbled.h"
#include <Arduino.h>

int blinkPin = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(blinkPin, OUTPUT);
    /*auto calabriation when start to use the device*/
}

void loop()
{
    digitalWrite(blinkPin, HIGH);
    delay(500);
    digitalWrite(blinkPin, LOW);
    delay(500);
}
