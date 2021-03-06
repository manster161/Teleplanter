/*
 * BaseSensor.h
 *
 *  Created on: 4 Apr 2016
 *      Author: manshaegert
 */

#ifndef BASESENSOR_H_
#define BASESENSOR_H_
#include "WString.h"

namespace Sensors {

class BaseSensor {
public:
	virtual ~BaseSensor();
	BaseSensor(unsigned char, String);
  virtual String getName();
	virtual int getValue() = 0;
  virtual void updateCalibrationValues() = 0;
	unsigned int _pin, _minValue, _maxValue ;
	unsigned char getPin();
protected:


private:
	String _name;
};

} /* namespace Devices */

#endif /* BASESENSOR_H_ */
