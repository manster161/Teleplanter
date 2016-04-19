#include "Arduino.h"
//#include "controls/WaterControl.h"
#include "core/Constants.h"
#include "sensors/MoistureSensor.h"
//#include "sensors/thermometer.h"
#include "core/buttons.h"
#include "io/Leds.h"
#include "lib/time/Time.h"
#include "lib/time/TimeAlarms.h"
#include "sensors/ThermometerHumidity.h"
//Controls::WaterControl* _waterControl;
Sensors::MoustureSensor* _moistureSensor;
Sensors::ThermometerHumidity* _thermometer;
//Sensors::Thermometer* _tempSensor;
Inputs::Buttons* _buttons;
Outputs::Leds* _leds;


const unsigned char _setup = Configurations::TP101;

void setup()
{
  Serial.begin(9600);
  // initialize LED digital pin as an output.
  //_waterControl = new Controls::WaterControl(Pins::WATER_CONTROL_PIN);
  _moistureSensor = new Sensors::MoustureSensor(Pins::MOISTURE_SENSOR_PIN);
  _thermometer = new Sensors::ThermometerHumidity(Pins::THERMOMETER_SENSOR_PIN);
  _leds = new Outputs::Leds();
  //_tempSensor = new Sensors::Thermometer(Pins::THERMOMETER_SENSOR_PIN, 15, 25);
}

void loop()
{
    while (_buttons->isMoistureCalibrationPushed()){

      _moistureSensor->updateCalibrationValues();
    }


    Serial.print("Moisture : ");
    Serial.println(_moistureSensor->getValue());
    Serial.println("");

    _thermometer->readSensorValues();
    Serial.print("Temp:");
    Serial.println(_thermometer->getTemp(), DEC);
    Serial.println("");
    Serial.print("Humidity: ");
    Serial.println(_thermometer->getHumidity(), DEC);
    Serial.println("");
    delay(5000);
}
