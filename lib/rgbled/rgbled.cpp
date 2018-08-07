#include "rgbled.h"

const int redPin = 2; 
const int grnPin = 1; 
const int bluPin = 0;
const int sensor = 3;

void setup_rgbled()
{
  pinMode(redPin, OUTPUT);    
  pinMode(grnPin, OUTPUT);    
  pinMode(bluPin, OUTPUT);
  pinMode(sensor, INPUT);
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
