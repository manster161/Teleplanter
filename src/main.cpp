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
#include <LiquidCrystal_I2C.h>
#include "core/Initialization.h"
#include "io/Display.h"

//LiquidCrystal_I2C lcd(0x3F);
//Controls::WaterControl* _waterControl;
Sensors::MoustureSensor* _moistureSensor;
Sensors::ThermometerHumidity* _thermometer;
//Sensors::Thermometer* _tempSensor;
Inputs::Buttons* _buttons;
Outputs::Leds* _leds;
Core::Initialization* _bootstrap;
Outputs::Display* _display;
//LiquidCrystal_I2C lcd(0x3F);
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


int buttonState =0;
void printValues() {
  Serial.print("Moisture : ");
  Serial.println(_moistureSensor->getValue());
  Serial.println("");
  Serial.println("Reading sensor values:");
  _thermometer->readSensorValues();
  Serial.print("Temp:");
  Serial.println(_thermometer->getTemp(), DEC);
  Serial.println("");
  Serial.print("Humidity: ");
  Serial.println(_thermometer->getHumidity(), DEC);
  Serial.println("");
}

void printValuesToLCD(){
  char buffer[16];


  lcd.backlight();
  lcd.clear();
  sprintf(buffer, "Moisture: %d%%",_moistureSensor->getValue());

  lcd.setCursor(0,0);
  lcd.print(buffer);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0,0);
  sprintf(buffer, "Temp: %dc",_thermometer->getTemp());
  lcd.print(buffer);

  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  _thermometer->readSensorValues();
  sprintf(buffer, "Humidity: %d%%",_thermometer->getHumidity());
  lcd.print(buffer);

  delay(1000);
  lcd.clear();
  lcd.noBacklight();
}

void mainLoop(/* arguments */) {
  /* code */
  /* get soil humidity
  */

  /* get temp */
  /* get lamp status */
  printValuesToLCD();
  Serial.println("Main loop");

}

void setup()
{
  Serial.begin(115200);
  _bootstrap = new  Core::Initialization();
  // initialize LED digital pin as an output.
  //_waterControl = new Controls::WaterControl(Pins::WATER_CONTROL_PIN);
  _moistureSensor = new Sensors::MoustureSensor(Pins::MOISTURE_SENSOR_PIN);
  _thermometer = new Sensors::ThermometerHumidity(Pins::THERMOMETER_SENSOR_PIN);
  _leds = new Outputs::Leds();
  _display = new Outputs::Display();

  _bootstrap->init2(_display);

 Alarm.timerRepeat(10, mainLoop);

}




void loop()
{
  //printValues();
  //printValuesToLCD();
  //delay(2000);


  //printValues();

  Alarm.delay(1000);
}
