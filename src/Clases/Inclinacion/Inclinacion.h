#ifndef Inclinacion_h
#define Inclinacion_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"
#include "MPU6050.h"

class Inclinacion : public Sensor {
  public:    
    int pinA1;
    int pinA2;
    int pinInt;
    MPU6050 mpuSensor;
    int16_t ax, ay, az;

    Inclinacion(const String& nombre, const String& unidad , int pinA1, int pinA2, int pinInt);
    void setupSensor();
    float medir() override;  
};

#endif