# BNO055 Platformio Implementation

bno055 library used in platformio, the library is highly inspired by Adafruit_BNO055 library and contains automatically calibration method.

It has been tested on adafruit bno055 connecting to ESP8266/ESP32 via I2C

you could easily config the platform to your chip in platformio.ini

## Getting Started

1. You could connect BNO055 to the MCU according to [this website](https://learn.adafruit.com/adafruit-bno055-absolute-orientation-sensor/overview)

2. You need to install [platformio](https://platformio.org/) before using the code. However, it is easier to change the code to compatiable with Arduino IDE.

Remeber it will automatically download Adafruit_BNO055 lib into .piolibdeps/Adafruit BNO055_ID506

3. You can use:
```
make (all): to compile the firmware
make upload: to upload to your device
make clean: clean the project
make update: to update all the libraries
```
4. Move the device and enjoy it

5. This code is tested on ESP8266 and Arduino Nano Pro, if you want to use a different MCU, you could easily config it in platformio.ini

For example, the configuration for ESP8266 is:
```
[env:featheresp8266]
platform = espressif8266
framework = arduino
board=huzzah
```

The configuration for Arduino Nano Pro is:
```
[env:nanoatmega328]
platform = atmelavr
board = nanoatmega328
framework = arduino
```

## API Functions
```

//setup bno055, if the device is not setup successfully, it will enter forever loop
bool setup_bno055();

//option functions:
//get the yaw, roll and pitch (degrees) from BNO055

ORI_DATA getori_bno055();

//Data structure
typedef struct {
   float yaw; 
   float roll; 
   float pitch; 
} ORI_DATA; //measured by degrees
```
For all other functions, please refer to .piolibdeps/Adafruit BNO055_ID506.

## Calibration

The bno055 library contains a way to calibrate device in setup_bno055(): 
* A pre-defined calibration data containg offsets is stored in newcalib array, and then is loaded to bno055 chip by calling bno.setSensorOffsets(newCalib). 
* After that, user still needs to move the device slowly to make sure the device is fully calibrated. There will be a while loop for calibration. 
* When the bno.isFullycalibrated() returns true, the device will generate a new set of Calibration data, which can used to update the newCalib array next time.
* Please note the newcalib structure when you upload the array

## Licence

MIT
