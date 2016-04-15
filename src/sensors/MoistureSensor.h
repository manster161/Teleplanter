/*
 * MoustureSensor.h
 *
 *  Created on: 4 Apr 2016
 *      Author: manshaegert
 */

#ifndef MOISTURESENSOR_H_
#define MOISTURESENSOR_H_
#include "BaseSensor.h"

namespace Sensors {

class MoustureSensor : public  BaseSensor {

public:
	MoustureSensor(unsigned int pin);
	virtual ~MoustureSensor();

	bool isCalibrationPushed();
	virtual void updateCalibrationValues();
  virtual String getName();

};

} /* namespace Sensors */

#endif /* MOISTURESENSOR_H_ */
