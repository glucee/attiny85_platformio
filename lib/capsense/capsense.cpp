
#include "capsense.h"

int cap_pin_out = 1;
int cap_pin_in = 2;
int lowcap = 300;  // just above reading when noting is near
int highcap = 1800; // cap reading when almost touching
CapacitiveSensor   capsense = CapacitiveSensor(cap_pin_out, cap_pin_in);  // 10M resistor between pins 1 & 2, pin 2 is sensor pin, add a wire and or foil if desired
int ledPin = 0;
int dur = 10; //duration is 10 loops
int brightness;
bool isOn = 0;

/* smoothing */
const int numReadings = 5;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;                  // the index of the current reading
long total = 0;                  // the running total
int average = 0;                // the average

/*toESP pin and ESPtoPin*/
int toESPPin = 4;
int ESPtoPin = 3;

//Threshold
int Threshold = 64;

void setup_capsense()
{
  pinMode(ledPin, OUTPUT); // output pin
  pinMode(cap_pin_in, INPUT); // output pin
  pinMode(cap_pin_out, OUTPUT); // output pin

  pinMode(toESPPin, OUTPUT);
  pinMode(ESPtoPin, INPUT);

  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void run_capsense()
{
     // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = capsense.capacitiveSensor(30);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits

  brightness = map(average, lowcap, highcap, 0, 255);
  brightness = constrain(brightness, 0, 255);

  if (isOn == true && brightness < Threshold) {
    isOn = false;
    //delay(500);
  } else if (isOn == false && brightness > Threshold) {
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
    analogWrite(ledPin, 255);

  } else {
    analogWrite(ledPin, 0);
  }

  delay(10);
}