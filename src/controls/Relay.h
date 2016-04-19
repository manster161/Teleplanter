#ifndef RELAY_H
#define RELAY_H

#include "BaseControl.h"

namespace Controls {

  class Relay : public BaseControl {
  public:
    Relay(unsigned char);
    virtual ~Relay();

  };

}

#endif
