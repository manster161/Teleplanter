#ifndef INITIALIZATION_H_
#define INITIALIZATION_H_

#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>

namespace Core {

    class Initialization {
    public:
      Initialization();
    	virtual ~Initialization();
      virtual void init(LiquidCrystal_I2C*);
    };
}
#endif
