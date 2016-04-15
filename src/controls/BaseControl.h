/*
 * BaseControl.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef BASECONTROL_H_
#define BASECONTROL_H_
#include "WString.h"

namespace Controls {

class BaseControl {
private:
	bool _isOutput;
	String _name;
protected:
	unsigned char _pin;
public:
	BaseControl(unsigned char, bool, String);
	virtual ~BaseControl();
	void switchOn();
	void switchOff();
	unsigned char getPinValue();
	virtual String getName();
};

} /* namespace Controls */

#endif /* BASECONTROL_H_ */
