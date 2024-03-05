#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <LiquidCrystal_I2C.h>
#include "Adafruit_SHT31.h"

#define LCD_ADDRESS 0x27
#define SHT31_ADDRESS 0x44

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup()
{
  Serial.begin(9600);

  delay(2);

  // Delay Serial
  while (!Serial)
    delay(10);

  if (!sht31.begin(SHT31_ADDRESS)) {
    Serial.println("Couldn't find SHT31");
  } else {
    Serial.println("SHT31 Found!");
  }

  Serial.print("Heater Enabled State: ");
  if (sht31.isHeaterEnabled())
    Serial.println("ENABLED");
  else
    Serial.println("DISABLED");

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Helloooo");
}

void loop()
{
  // put your main code here, to run repeatedly:
  float temperature = sht31.readTemperature();
  Serial.println("Temperature: " + String(temperature));
  delay(10000);
}