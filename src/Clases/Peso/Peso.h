#ifndef Peso_h
#define peso_h
#include <Arduino.h>
#include "HX711.h"
#include "../src/Clases/Sensor.h"

class Peso : public Sensor {
  public:
    int pin1;
    int pin2;
    HX711 escala;

    Peso(const String& nombre ,int pin1, int pin2);
    void setupSensor();
    float medir() override;
};

#endif