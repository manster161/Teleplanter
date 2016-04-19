#ifndef THERMOMETER_H_
#define THERMOMETER_H_
#include "BaseSensor.h"
#include "WString.h"

namespace Sensors {

    class Thermometer : public BaseSensor {
      public:
        virtual ~Thermometer();
        Thermometer(unsigned char);
        virtual String getName();
      	virtual int getValue();
        virtual void updateCalibrationValues();
    };
}

#endif
