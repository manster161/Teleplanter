/*
 * Display.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "WString.h"
#include <LiquidCrystal_I2C.h>

namespace Outputs {

class Display {
public:
	Display();
	virtual ~Display();

	virtual void print(String message, byte row);
	virtual void on();
	virtual void off();
private:
	virtual void debugPrint(String message);
};

} /* namespace Outputs */

#endif /* DISPLAY_H_ */
