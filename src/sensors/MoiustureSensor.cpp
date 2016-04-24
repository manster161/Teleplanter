/*
 * MoustureSensor.cpp
 *
 *  Created on: 4 Apr 2016
 *      Author: manshaegert
 */

#include "MoistureSensor.h"
#include "../Core/Constants.h"
#include "Arduino.h"

namespace Sensors {


MoustureSensor::MoustureSensor(unsigned int pin) :  BaseSensor (pin, "MoistureSensor") {



}

MoustureSensor::~MoustureSensor() {

}


void MoustureSensor::updateCalibrationValues(){
		unsigned int currentValue = analogRead(Pins::MOISTURE_SENSOR_PIN);
		if (currentValue > _maxValue){
			_maxValue = currentValue;
		}
		if (currentValue < _minValue){
			_minValue = currentValue;
		}
}

int MoustureSensor::getValue(){
	unsigned int val = analogRead(Pins::MOISTURE_SENSOR_PIN);
	val = constrain(val, 399, 1023);
	int soil = map(val, 399, 1023, 100, 0);
	Serial.println(soil);
	return (soil);
}


String MoustureSensor::getName(){
	return BaseSensor::getName();
}

}
