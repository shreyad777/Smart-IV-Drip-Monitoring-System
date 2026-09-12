# Project Details

## Project Title

Smart IV Drip Monitoring and Alert System

## Problem Statement

Manual monitoring of IV fluid levels requires healthcare staff to periodically inspect IV bags. Delayed identification of a nearly empty IV bag can interrupt fluid administration and increase the monitoring workload.

## Proposed Solution

The system continuously monitors the weight of an IV fluid bag using a load cell. The measured weight is processed through an HX711 module and ESP32. The current status is displayed on a 20×4 I2C LCD, while a buzzer provides an audible warning when the measured weight falls below a predefined threshold.

## Core Technology

- ESP32 microcontroller
- Load cell
- HX711 amplifier and ADC module
- 20×4 I2C LCD
- Buzzer
- Arduino/C++

## Working Principle

The IV bag is placed on or suspended from the load cell. As the fluid is consumed, the total weight decreases. The load cell detects this change and the HX711 converts the signal into a digital reading. The ESP32 processes the reading and compares it with the configured threshold.

### Normal

If the measured weight is above the threshold:

**IV LEVEL NORMAL**

The buzzer remains inactive.

### Low Fluid

If the measured weight falls below the threshold:

**LOW FLUID ALERT**

The buzzer is activated and the LCD indicates that the IV bottle should be replaced.

## Key Benefits

- Continuous local monitoring
- Early identification of low fluid levels
- Audible warning for healthcare staff
- Reduced need for frequent manual inspection
- Simple and cost-effective prototype
- Non-invasive monitoring approach

## Limitations

- Requires proper load-cell calibration.
- Threshold values must be configured according to the intended prototype setup.
- The system is currently a local monitoring prototype.
- Hardware connections must be verified before deployment.
- This academic prototype is not a certified medical device.

## Future Scope

The system can be extended with:

- Improved measurement filtering
- Adjustable thresholds
- Battery operation
- Data logging
- Multiple IV bag monitoring
- Optional remote notifications
- Web or mobile dashboard
- Improved physical enclosure
- Extended prototype testing