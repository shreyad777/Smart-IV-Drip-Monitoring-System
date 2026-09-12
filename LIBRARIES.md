# Libraries and Software Requirements

## Development Environment

- Arduino IDE
- ESP32 Board Package

## Arduino Libraries

### HX711

Used to interface the load cell with the ESP32 through the HX711 amplifier module.

```cpp
#include "HX711.h"
LiquidCrystal I2C

Used to control the 20×4 I2C LCD.

#include <LiquidCrystal_I2C.h>
Wire

Used for I2C communication between the ESP32 and LCD.

#include <Wire.h>
Installation

Install the required libraries through the Arduino IDE Library Manager.

HX711

Search for:

HX711
LiquidCrystal I2C

Search for:

LiquidCrystal I2C
ESP32 Board Setup

In Arduino IDE, install the ESP32 board package and select the appropriate ESP32 board under:

Tools → Board → ESP32 Arduino
