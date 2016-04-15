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
  virtual void updateCalibrationValues() = 0;
protected:
	unsigned int _pin, _minValue, _maxValue ;

private:
	String _name;
};

} /* namespace Devices */

#endif /* BASESENSOR_H_ */
