#ifndef Sensor_h
#define Sensor_h
#include <Arduino.h>

class Sensor {
  public:
    String nombre;
    String unidad;
    virtual float medir() = 0;
};
#endif