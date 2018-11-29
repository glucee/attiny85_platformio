#include "../lib/capsense/capsense.h"
//#include "../lib/tilt/tilt.h"

void setup()
{
  setup_capsense();
  //setup_tilt();
}

void loop()
{
  run_capsense();
  //run_tilt();
  delay(100);
}