#include "rgbled.h"

const int redPin = 2; 
const int grnPin = 1; 
const int bluPin = 0;

void setup_rgbled()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
}

void red()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, LOW);
  digitalWrite(bluPin, LOW);
}

void yellow()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(grnPin, HIGH);
  digitalWrite(bluPin, LOW);
}

void green()
{
  digitalWrite(grnPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
}

void off()
{
  digitalWrite(grnPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(bluPin, LOW);
}
