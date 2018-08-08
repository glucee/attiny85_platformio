# Attiny85 Platformio Implementation

## Prepare

1. Attiny85
2. Tiny AVR Programmer

### Getting Started

1. You could connect Attiny85 to a Tiny AVR Programmer according to [this website](https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/)

2. You need to install [platformio](https://platformio.org/) before using the code. However, it is easier to change the code to compatiable with Arduino IDE. The configuration for Attiny85 is:

```
[env:attiny]
platform = atmelavr
framework = arduino
upload_protocol = usbtiny
board = attiny85
```

3. You can use:
```
make (all): to compile the firmware
make upload: to upload to your device
make clean: clean the project
make update: to update all the libraries
```
Or you could use Visual Studio Code to compile and upload it.

## Licence

MIT
