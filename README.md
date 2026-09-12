<div align="center">

# Smart IV Drip Monitoring and Alert System

### Weight-Based IV Fluid Level Monitoring and Alert System

</div>

---

# Smart IV Drip Monitoring and Alert System

A smart healthcare assistance system designed to continuously monitor the fluid level of an IV drip by measuring the weight of the IV fluid bag and providing an immediate alert when the fluid level becomes critically low.

## Overview

During IV fluid administration, healthcare staff need to periodically check the remaining fluid in an IV bottle or bag. Manual monitoring can be difficult, especially when multiple patients require attention.

The Smart IV Drip Monitoring and Alert System addresses this problem by continuously monitoring the weight of the IV fluid bag. A load cell measures the weight, while the HX711 module processes the load-cell signal and sends the data to an ESP32. The ESP32 evaluates the measured weight and displays the current status on a 20×4 I2C LCD. When the fluid level falls below a predefined threshold, an audible buzzer alert is activated.

The system is designed as a simple, low-cost and non-invasive monitoring solution that can help healthcare staff identify low IV fluid levels promptly.

## Project Highlights

- 🏥 Designed for healthcare assistance and IV fluid monitoring
- ⚖️ Monitors IV bag weight continuously
- 🔔 Provides an immediate audible warning for low fluid levels
- 📟 Displays real-time status on a 20×4 LCD
- 🔧 Built using commonly available hardware components
- 💡 Designed as a simple, low-cost prototype

## Key Features

- Continuous monitoring of IV fluid bag weight
- Automatic detection of low fluid levels
- Real-time status displayed on a 20×4 LCD
- Audible buzzer alert for low fluid conditions
- ESP32-based control system
- Load cell-based measurement
- HX711 signal amplification and conversion
- Non-invasive monitoring
- Simple and cost-effective hardware implementation

## How It Works

```text
IV Fluid Bag
     ↓
  Load Cell
     ↓
    HX711
     ↓
   ESP32
   ↙   ↘
 LCD   Buzzer
The IV fluid bag is suspended from the load cell.
The load cell measures the weight of the bag.
The HX711 amplifies and converts the load-cell signal.
The ESP32 receives and processes the weight data.
The measured weight is displayed on the LCD.
The ESP32 compares the measured weight with the predefined threshold.
If the weight is above the threshold, the system displays a normal status.
If the weight falls below the threshold, the LCD displays a low-fluid warning and the buzzer is activated.
Hardware Components
Component	Purpose
ESP32	Main controller
Load Cell	Measures IV bag weight
HX711	Amplifies and converts load-cell signal
20×4 I2C LCD	Displays weight and system status
Buzzer	Provides audible warning
IV Fluid Bag	Fluid container being monitored
Alert Conditions
Normal Condition

The system displays:

IV LEVEL NORMAL
Monitoring...

The buzzer remains OFF.

Low Fluid Condition

When the measured weight falls below the predefined threshold, the system displays:

LOW FLUID ALERT
REPLACE IV BOTTLE

The buzzer is activated to notify the healthcare staff.

Software
Arduino IDE
C/C++
ESP32
HX711 Library
LiquidCrystal_I2C Library
Repository Structure
Smart-IV-Drip-Monitoring-System/
│
├── README.md
│
├── src/
│   └── smart_iv_drip_monitoring.ino
│
├── hardware/
│   └── components.md
│
├── images/
│
└── documentation/
Applications
Hospitals
Clinics
Patient wards
Home-based IV monitoring
Healthcare assistance systems
Advantages
Reduces the need for frequent manual checking
Provides an immediate local warning
Helps prevent the IV bag from becoming completely empty
Reduces monitoring effort for healthcare staff
Uses commonly available electronic components
Provides a simple and scalable prototype for healthcare applications
Future Enhancements
More accurate load-cell calibration
Adjustable fluid-level thresholds
Battery-powered operation
Mobile or web-based monitoring
Multiple IV bag monitoring
Data logging and historical monitoring
Integration with hospital notification systems
Project Status

Prototype completed and documented for further testing and enhancement.

Disclaimer

This project is an academic prototype intended for demonstration and educational purposes. It is not a certified medical device and should not replace professional medical monitoring or clinical equipment.