/*
 * Display.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_
#include "WString.h"

namespace Outputs {

class Display {
public:
	Display();
	virtual ~Display();
	void displayMessage(String message);
};

} /* namespace Outputs */

#endif /* DISPLAY_H_ */
