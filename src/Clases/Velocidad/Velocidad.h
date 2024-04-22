#ifndef Velocidad_h
#define Velocidad_h
#include "../src/Clases/Sensor.h"

class Velocidad : public Sensor{
   public: 
   int pint1;

   Velocidad(const String& nombre , const String& unidad ,int pint1);
   float medir() override;
};
#endif