//ATtiny85 RGB color fading Mood Light NOW WITH LIGHT SENSING CAPABILITIES!!!
#include <Arduino.h>
#include "../lib/rgbled/rgbled.h"

#define BATTERY_MAX (4.1*BATTERY_SCALE) 

#define BATTERY_MIN (3.1*BATTERY_SCALE) 

#define BATTERY_SCALE (204.8/7.17) 

const int sensor = A2;

void setup()
{
  setup_rgbled();
}

int status, pre_status = 0;
void loop() {
  int value = analogRead(sensor); 
  int percentage = (value - BATTERY_MIN) * 100 / (BATTERY_MAX - BATTERY_MIN);   
  if (percentage > 90) status = 3;
  else if (percentage > 20) status = 2;
  else if (percentage >= 0) status = 1;
  else status = 0; 
  if(status != pre_status)
  {
    switch(status)
    {
      case 3: green(); break;
      case 2: yellow(); break;
      case 1: red(); break;
      case 0: off(); break;
    }
  }
  pre_status = status;
}