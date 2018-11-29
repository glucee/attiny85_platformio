#include "tilt.h"

int toESPPin = 4;
int ESPtoPin = 3;
//int ledPin = 0;
int sensorPin = 0;

bool isOn = false;

void setup_tilt()
{
  //pinMode(ledPin, OUTPUT); // output pin
  pinMode(sensorPin, INPUT); //input pin
  pinMode(toESPPin, OUTPUT);
  pinMode(ESPtoPin, INPUT);
}

void run_tilt(){

  bool sensorStatus = digitalRead(sensorPin);
  if (isOn == true && sensorStatus == true) {
    isOn = false;
    //delay(500);
  } else if (isOn == false && sensorStatus == false) {
    isOn = true;
    /*Pulse*/
    if(digitalRead(ESPtoPin) == LOW) /*if the ESP is not working*/
    {
      digitalWrite(toESPPin, 1);
      delay(10);
      digitalWrite(toESPPin, 0);
    }
    //delay(500);
  }

  if (isOn == true) {
    //analogWrite(ledPin, 255);

  } else {
    //analogWrite(ledPin, 0);
  }
}