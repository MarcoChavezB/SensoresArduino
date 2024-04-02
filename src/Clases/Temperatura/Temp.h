#ifndef Temp_h
#define Temp_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"
#include <DHT.h>

class Temp: public Sensor{
  public:
    int pin1;
    DHT dht;

    Temp(const String& nombre, const String& unidad ,int pin1);
    float medir() override;
};
#endif