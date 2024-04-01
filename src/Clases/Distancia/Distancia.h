#ifndef Distancia_h
#define Distancia_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"

class Distancia : public Sensor{
  public:
    int trigPin;
    int echoPin;

    Distancia(const String& nombre ,int trigPin, int echoPin);
    float medir() override;
};

#endif