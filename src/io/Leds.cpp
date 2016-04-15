#include "../core/Buttons.h"
#include "arduino.h"
#include "../core/constants.h"
#include "Leds.h"
namespace Outputs {

Leds::Leds(){}

Leds::~Leds(){}

  void indicateInputRecieved(){
      digitalWrite(Pins::STANDARD_LED_PIN, HIGH);
  }
  void indicateNoInputRecieved(){
      digitalWrite(Pins::STANDARD_LED_PIN, LOW);
  }

}
