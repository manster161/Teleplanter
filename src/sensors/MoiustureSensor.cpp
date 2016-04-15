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

	// TODO Auto-generated constructor stub

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


String MoustureSensor::getName(){
	return BaseSensor::getName();
}

}
