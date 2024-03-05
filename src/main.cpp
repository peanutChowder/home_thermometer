#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

#include <LiquidCrystal_I2C.h>
#include "Adafruit_SHT31.h"

#define LCD_ADDRESS 0x27

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup()
{
  Serial.begin(9600);

  // Delay Serial
  while (!Serial)
    delay(10);

  if (!sht31.begin(0x44))
  { // Set to 0x45 for alternate i2c addr
    Serial.println("Couldn't find SHT31");
    while (1)
      delay(1);
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
}