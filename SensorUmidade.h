#ifndef SENSOR_UMIDADE_H
#define SENSOR_UMIDADE_H

class SensorUmidade {
  int pino;
public:
  SensorUmidade(int p);
  int ler();
};

#endif
