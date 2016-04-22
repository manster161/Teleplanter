/*
 * Constants.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include "arduino.h"

namespace Pins {
	const unsigned char WATER_CONTROL_PIN = 11;
	const unsigned char MOISTURE_SENSOR_PIN = A0;
	const unsigned char LIGHT_CONTROL_PIN = 3;
	const unsigned char FAN_CONTROL_PIN = 4;
	const unsigned char THERMOMETER_SENSOR_PIN = 2;
	const unsigned char PH_SENSOR_PIN = 5;

	const unsigned char MOISTURE_SENSOR_CALIBRATION_PIN = 10;
	const unsigned char STANDARD_LED_PIN = 13;
	const unsigned char USE_HEATER_PIN = 6;
	const unsigned char USE_24H_MODE = 7;
}


#endif /* CONSTANTS_H_ */
