#ifndef Comunicacion_h
#define Comunicacion_h
#include <Arduino.h>
#include "Sensor.h"

class Comunicacion{
  public:
    void medirYSerializar(Sensor* sensor ,int sensorId) {
      float valor = sensor->medir();
      if(sensorId <= 9){
        Serial.println(sensor->nombre + "*" + sensor->unidad + "*" + "0" + sensorId + "*" + valor);
      }else{
        Serial.println(sensor->nombre + "*" + sensor->unidad + "*" + sensorId + "*" + valor);
      }
}
};
#endif