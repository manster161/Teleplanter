/*
 * Display.cpp
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */
#include <SoftwareSerial.h>
#include "Display.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

namespace Outputs {

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



Display::Display() {
	// TODO Auto-generated constructor stub
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
}

Display::~Display() {
	// TODO Auto-generated destructor stub
}




void Display::debugPrint(String message){
  Serial.println(message);
}


void Display::print(String message, byte row = 0){
  debugPrint(message);
 lcd.clear();
  if (row > 0){
    row = 1;
  }
  lcd.setCursor(0, row);
  lcd.print(message);
}

void Display::on(){
  debugPrint("Backlight");
  lcd.backlight();
}
void Display::off(){
  debugPrint("No backlight");
  lcd.noBacklight();
}

} /* namespace Outputs */
