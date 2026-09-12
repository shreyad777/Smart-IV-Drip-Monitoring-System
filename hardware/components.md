# Hardware Components

## 1. ESP32
The ESP32 acts as the main controller of the system. It receives weight data from the HX711 module, processes the measured IV fluid level, and controls the LCD and buzzer.

## 2. Load Cell
The load cell measures the weight of the IV fluid bag. As the fluid is consumed, the weight of the bag decreases.

## 3. HX711 Load Cell Amplifier
The HX711 amplifies and converts the small electrical signal from the load cell into digital data that can be read by the ESP32.

## 4. 20×4 I2C LCD
The LCD displays the current IV fluid weight and system status.

Example messages:
- IV LEVEL NORMAL
- LOW FLUID ALERT
- REPLACE IV BOTTLE

## 5. Buzzer
The buzzer provides an audible warning when the IV fluid level falls below the predefined threshold.

## 6. IV Fluid Bag
The IV bag is suspended from the load cell so that its changing weight can be continuously monitored.

---

# Basic Working

The system works by continuously measuring the weight of the IV fluid bag.

1. The load cell detects the weight.
2. The HX711 converts the load-cell signal into digital data.
3. The ESP32 processes the measured weight.
4. The current weight is displayed on the 20×4 LCD.
5. If the weight is above the predefined threshold, the system displays a normal status.
6. If the weight falls below the threshold, the LCD displays a low-fluid warning and the buzzer is activated.

# System Flow

IV Bag
↓
Load Cell
↓
HX711
↓
ESP32
↙      ↘
LCD    Buzzer
---

# Pin Connections

## HX711 to ESP32

| HX711 Pin | ESP32 Pin |
|---|---|
| VCC | 3.3V |
| GND | GND |
| DT / DOUT | GPIO 4 |
| SCK | GPIO 5 |

## Buzzer to ESP32

| Buzzer Pin | ESP32 Pin |
|---|---|
| Positive (+) | GPIO 18 |
| Negative (-) | GND |

## 20×4 I2C LCD to ESP32

| LCD Pin | ESP32 |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Load Cell to HX711

The load cell is connected directly to the HX711 module through its load-cell input terminals. The exact wire colors may vary depending on the load-cell model, so the manufacturer's wiring diagram should be followed.

---

# ESP32 Pin Summary

| Function | ESP32 GPIO |
|---|---:|
| HX711 DOUT | GPIO 4 |
| HX711 SCK | GPIO 5 |
| Buzzer | GPIO 18 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |