#ifndef Alarma_h
#define Alarma_h
#include <Arduino.h>
#include "../src/Clases/Sensor.h"

class Alarma : public Sensor{
    public:
        int pin;
        Alarma(const String& nombre, const String& unidad ,int pin);
        float medir() override;
};
#endif