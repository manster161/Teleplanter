#include "Arduino.h"
//#include "controls/WaterControl.h"
#include "core/Constants.h"
#include "sensors/MoistureSensor.h"
//#include "sensors/thermometer.h"
#include "core/buttons.h"
#include "io/Leds.h"
#include <Time.h>
#include <TimeAlarms.h>
#include "sensors/ThermometerHumidity.h"
#include "core/Configuration.h"
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here:
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>


//LiquidCrystal_I2C lcd(0x3F);
//Controls::WaterControl* _waterControl;
Sensors::MoustureSensor* _moistureSensor;
Sensors::ThermometerHumidity* _thermometer;
//Sensors::Thermometer* _tempSensor;
Inputs::Buttons* _buttons;
Outputs::Leds* _leds;
//LiquidCrystal_I2C lcd(0x3F);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void printValues() {
  Serial.print("Moisture : ");
  Serial.println(_moistureSensor->getValue());
  Serial.println("");
  _thermometer->readSensorValues();
  Serial.print("Temp:");
  Serial.println(_thermometer->getTemp(), DEC);
  Serial.println("");
  Serial.print("Humidity: ");
  Serial.println(_thermometer->getHumidity(), DEC);
  Serial.println("");
}

void setup()
{
  Serial.begin(9600);
  // initialize LED digital pin as an output.
  //_waterControl = new Controls::WaterControl(Pins::WATER_CONTROL_PIN);
  _moistureSensor = new Sensors::MoustureSensor(Pins::MOISTURE_SENSOR_PIN);
  _thermometer = new Sensors::ThermometerHumidity(Pins::THERMOMETER_SENSOR_PIN);
  _leds = new Outputs::Leds();

  lcd.begin(16,2);

  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on

  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, im TP-101");

  delay(3000);
}

void printValuesToLCD(){
  char buffer[16];

  lcd.clear();
  sprintf(buffer, "Moisture: %d%%",_moistureSensor->getValue());
  lcd.setCursor(0,0);
  lcd.print(buffer);

  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  sprintf(buffer, "Temp: %dc",_thermometer->getTemp());
  lcd.print(buffer);

  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  sprintf(buffer, "Humidity: %d%%",_thermometer->getHumidity());
  lcd.print(buffer);
  delay(2000);
  lcd.clear();
}
void loop()
{
  printValues();
  printValuesToLCD();
  delay(2000);

}
