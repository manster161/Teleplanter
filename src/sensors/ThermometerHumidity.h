#ifndef THERMOMETERHUMIDITY_H_
#define TTHERMOMETERHUMIDITY_H_
#include "BaseSensor.h"
#include "WString.h"

namespace Sensors {

    class ThermometerHumidity : public BaseSensor {
      public:
        virtual ~ThermometerHumidity();
        ThermometerHumidity(unsigned char);
        virtual String getName();
      	virtual int getValue();
        virtual void updateCalibrationValues();
        int getTemp();
        int getHumidity();
        void readSensorValues();
      private:
        unsigned char readData();
    };
}

#endif
