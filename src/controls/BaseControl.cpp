/*
 * BaseControl.cpp
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#include "BaseControl.h"
#include "Arduino.h"
namespace Controls {

unsigned char _pin;
bool _isOutput;
String _name;
BaseControl::BaseControl(unsigned char pin, bool isOutput, String name) {
	// TODO Auto-generated constructor stub
	_pin = pin;
	_isOutput = isOutput;
	_name = name;
	if (isOutput){
		pinMode(_pin, OUTPUT);
	}
}

BaseControl::~BaseControl() {
	// TODO Auto-generated destructor stub

}

void switchOn(){
	digitalWrite(_pin, HIGH);
}

void switchOff(){
	digitalWrite(_pin, LOW);
}

unsigned char getPinValue() {
	return digitalRead(_pin);
}

String name(){
	return "BaseControl";
}
} /* namespace Controls */
