/*
 * WaterControl.h
 *
 *  Created on: 5 Apr 2016
 *      Author: manshaegert
 */

#ifndef LEDS_H_
#define LEDS_H_
namespace Outputs
{
  class Leds{
  public:
    Leds();
    ~Leds();
    void indicateInputRecieved();
    void indicateNoInputRecieved();
  };
}


#endif
