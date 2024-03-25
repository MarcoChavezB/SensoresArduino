#ifndef Temp_h
#define Temp_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"

class Temp: public Sensor{
  public:
    int pin1;

    Temp(const String& nombre ,int pin1);
    float medir() override;
};
#endif