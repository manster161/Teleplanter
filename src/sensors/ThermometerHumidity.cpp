#include "ThermometerHumidity.h"
#include "../Core/Constants.h"
#include "WString.h"
#include "Arduino.h"

namespace Sensors {

  unsigned char data[5];

  ThermometerHumidity::ThermometerHumidity(unsigned char pin) : BaseSensor(pin, "ThermometerHumidity"){
    pinMode (Pins::THERMOMETER_SENSOR_PIN, OUTPUT);
  }

  ThermometerHumidity::~ThermometerHumidity(){

  }

  void ThermometerHumidity::updateCalibrationValues(   ){

    }

  String ThermometerHumidity::getName(){
    return BaseSensor::getName();
  }

  int ThermometerHumidity::getValue(){
    //unsigned int val = analogRead(Pins::THERMOMETER_SENSOR_PIN);
  	//return val;
    return 0;
  }

  unsigned char ThermometerHumidity::readData() {
    byte data;
    for (int i = 0; i < 8; i ++) {
      if (digitalRead (Pins::THERMOMETER_SENSOR_PIN) == LOW) {
          while (digitalRead (Pins::THERMOMETER_SENSOR_PIN) == LOW); // wait for 50us
          delayMicroseconds (30); // determine the duration of the high level to determine the data is '0 'or '1'
          if (digitalRead (Pins::THERMOMETER_SENSOR_PIN) == HIGH)
            data |= (1 << (7-i)); // high front and low in the post
        while (digitalRead (Pins::THERMOMETER_SENSOR_PIN) == HIGH); // data '1 ', wait for the next one receiver
        }
      }
      return data;
  }

  void ThermometerHumidity::readSensorValues(){
    digitalWrite(Pins::THERMOMETER_SENSOR_PIN,LOW);
    delay(30);
    digitalWrite(Pins::THERMOMETER_SENSOR_PIN, HIGH);
    delayMicroseconds(40);

    pinMode(Pins::THERMOMETER_SENSOR_PIN, INPUT);

    while(digitalRead(Pins::THERMOMETER_SENSOR_PIN) == HIGH);
    delayMicroseconds(80);

    if (digitalRead(Pins::THERMOMETER_SENSOR_PIN) == LOW);
    delayMicroseconds(80);

    for (int i = 0; i < 4; i++){
      data[i] = readData();
    }
    pinMode(Pins::THERMOMETER_SENSOR_PIN,OUTPUT);
    digitalWrite(Pins::THERMOMETER_SENSOR_PIN, HIGH);
  }

  int ThermometerHumidity::getTemp(){
    return data[2];
  }
  int ThermometerHumidity::getHumidity(){
    return data[0];
  }
}
