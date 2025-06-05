#ifndef GERENCIADOR_IRRIGACAO_H
#define GERENCIADOR_IRRIGACAO_H

#include "SensorUmidade.h"
#include "AtuadorLED.h"

class GerenciadorIrrigacao {
  SensorUmidade& sensor;
  AtuadorLED& led;
  int limiar;

public:
  GerenciadorIrrigacao(SensorUmidade& s, AtuadorLED& l, int lmiar);
  void atualizar();
};

#endif
