#ifndef SensorGps_h
#define SensorGps_h
#include <Arduino.h>

class SensorGps {
  public:
    String nombre;
    String unidad;
    virtual String medir() = 0;
};
#endif
