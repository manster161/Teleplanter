#ifndef THERMOMETER_H_
#define THERMOMETER_H_
#include "BaseSensor.h"
#include "WString.h"

namespace Sensors {
    class Thermometer : public BaseSensor {
      public:
        virtual ~Thermometer();
        Thermometer(unsigned char);
    };
}

#endif
