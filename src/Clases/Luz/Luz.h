#ifndef Luz_h
#define Luz_h
#include "../src/Clases/Sensor.h"

class Luz : public Sensor{
   public :
   int pin;

   Luz(const String& nombre , const String& unidad ,int pin);
   float medir() override;
};


#endif