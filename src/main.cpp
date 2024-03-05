#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <LiquidCrystal_I2C.h>
#include "Adafruit_SHT31.h"

#define LCD_ADDRESS 0x27
#define SHT31_ADDRESS 0x44

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
Adafruit_SHT31 sht31 = Adafruit_SHT31();

int initDisplay() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Helloooo");
  return 1;
}

int initSHT31() {
  if (!sht31.begin(SHT31_ADDRESS)) {
    Serial.println("Couldn't find SHT31");
    return -1;
  } else {
    Serial.println("SHT31 Found!");
  }

  Serial.print("Heater Enabled State: ");
  if (sht31.isHeaterEnabled())
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");

  return 1;
}

void setup()
{
  Serial.begin(9600);
  delay(2);

  while (!Serial)
    delay(10);

  initDisplay();
  if (initSHT31() == -1) {
    Serial.println("Could not find SHT31 - Program aborting");
    while (1) delay(10000);
  }
}

void loop()
{
  float temperature = sht31.readTemperature();
  Serial.println("Temperature: " + String(temperature));
  delay(10000);
}