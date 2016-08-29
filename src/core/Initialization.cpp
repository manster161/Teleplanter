#include "Initialization.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Constants.h"
#include "../io/Display.h"
namespace Core {


Initialization::Initialization() {


}

Initialization::~Initialization() {

}

  void Initialization::init2(Outputs::Display* display){
      display->print("String message", 0);

      display->print("TP-101", 0);
      for(int i = 0; i< 3; i++)
      {
        display->on();
        delay(250);
        display->off();
        delay(250);
      }
      display->on(); // finish with backlight on

      delay(500);

      display->print("TP-101", 0);

      display->print("Initializing", 1);


      display->print("TP-101", 0);

      display->print("Ready", 1);

      delay(1000);
      pinMode(Pins::BUTTON_1_PIN, INPUT);
      delay(500);
      pinMode(Pins::THERMOMETER_SENSOR_PIN, OUTPUT);
  }

  void Initialization::init(LiquidCrystal_I2C* lcd){
  lcd->begin(16,2);
  lcd->clear();
  lcd->setCursor(0,0); //Start at character 4 on line 0

  Serial.println("TP-101");
  lcd->print("TP-101");
  for(int i = 0; i< 3; i++)
  {
    lcd->backlight();
    delay(250);
    lcd->noBacklight();
    delay(250);
  }
  lcd->backlight(); // finish with backlight on

  delay(500);
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("TP-101");
  lcd->setCursor(0,1);
  lcd->print("Initializing");
  Serial.println("Initializing");
  for (int i = 0; i < 4; i++){
    lcd->setCursor(12 + i,1);
    lcd->print(".");
    delay(1000);
  }
  lcd->clear();
  lcd->setCursor(0,0);
  lcd->print("TP-101");
  lcd->setCursor(0,1);
  lcd->print("Ready");
  Serial.println("Ready");
  delay(1000);
  pinMode(Pins::BUTTON_1_PIN, INPUT);
  delay(500);
  pinMode(Pins::THERMOMETER_SENSOR_PIN, OUTPUT);
  //lcd.noBacklight();
}
}
