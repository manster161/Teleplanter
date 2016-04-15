/*
 * Buttons.cpp
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#include "Buttons.h"
#include "arduino.h"
#include "constants.h"
namespace Inputs {

Buttons::Buttons() {
	// TODO Auto-generated constructor stub

}

Buttons::~Buttons() {
	// TODO Auto-generated destructor stub
}

bool Buttons::isMoistureCalibrationPushed() {

	return digitalRead(Pins::MOISTURE_SENSOR_CALIBRATION_PIN);
}


} /* namespace Inputs */
