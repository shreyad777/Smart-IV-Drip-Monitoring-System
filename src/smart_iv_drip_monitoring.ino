#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "HX711.h"

// ================= PIN CONFIGURATION =================
#define HX711_DOUT 4
#define HX711_SCK  5
#define BUZZER_PIN 18

// ================= LCD CONFIGURATION =================
#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

// ================= MONITORING SETTINGS =================
// Replace this value after calibrating the load cell.
float calibration_factor = -7050.0;

// Minimum acceptable measured weight in grams.
float lowLevelThreshold = 100.0;

// ================= OBJECTS =================
HX711 scale;
LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

// ================= SETUP =================
void setup() {

  Serial.begin(115200);

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Initialize LCD
  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SMART IV DRIP");
  lcd.setCursor(0, 1);
  lcd.print("MONITORING SYSTEM");
  delay(2000);

  // Initialize HX711
  scale.begin(HX711_DOUT, HX711_SCK);

  scale.set_scale(calibration_factor);
  scale.tare();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM READY");
  delay(1500);
}

// ================= MAIN LOOP =================
void loop() {

  // Read average of 5 measurements
  float weight = scale.get_units(5);

  // Prevent negative readings
  if (weight < 0) {
    weight = 0;
  }

  // Display reading in Serial Monitor
  Serial.print("IV Weight: ");
  Serial.print(weight, 1);
  Serial.println(" g");

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("IV FLUID MONITOR");

  lcd.setCursor(0, 1);
  lcd.print("Weight: ");
  lcd.print(weight, 1);
  lcd.print(" g");

  // ================= NORMAL CONDITION =================
  if (weight > lowLevelThreshold) {

    digitalWrite(BUZZER_PIN, LOW);

    lcd.setCursor(0, 2);
    lcd.print("IV LEVEL NORMAL");

    lcd.setCursor(0, 3);
    lcd.print("Monitoring...");

  }

  // ================= LOW FLUID CONDITION =================
  else {

    digitalWrite(BUZZER_PIN, HIGH);

    lcd.setCursor(0, 2);
    lcd.print("LOW FLUID ALERT");

    lcd.setCursor(0, 3);
    lcd.print("REPLACE IV BOTTLE");
  }

  delay(1000);
}