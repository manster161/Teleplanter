#include "Thermometer.h"
#include "../Core/Constants.h"
#include "WString.h"
#include "Arduino.h"

namespace Sensors {

  Thermometer::Thermometer(unsigned char pin) : BaseSensor(pin, "Thermometer"){

  }

  Thermometer::~Thermometer(){

  }

  void Thermometer::updateCalibrationValues(){

    }

  String Thermometer::getName(){
    return BaseSensor::getName();
  }

  int Thermometer::getValue(){
    unsigned int val = analogRead(Pins::THERMOMETER_SENSOR_PIN);
  	return val;
  }
}
