/*
 * BaseSensor.cpp
 *
 *  Created on: 4 Apr 2016
 *      Author: manshaegert
 */
#include "Arduino.h"
#include "BaseSensor.h"
#include "WString.h"

namespace Sensors {

unsigned char _pin;
String _name;


BaseSensor::BaseSensor(unsigned char pin, String name)  {
	_pin = pin;
	_name = name;

};
	// TODO Auto-generated constructor stub

BaseSensor::~BaseSensor() {
	// TODO Auto-generated destructor stub
}

String BaseSensor::getName(){
	return _name;
}

unsigned char BaseSensor::getPin(){
	return _pin;
}








} /* namespace Devices */
