#ifndef GERENCIADOR_IRRIGACAO_H
#define GERENCIADOR_IRRIGACAO_H

#include "SensorUmidade.h"
#include "AtuadorLED.h"

// Classe que gerencia o sistema de irrigação automática
class GerenciadorIrrigacao {
  SensorUmidade& sensor;  // Referência ao sensor de umidade
  AtuadorLED& led;        // Referência ao LED atuador
  int limiar;             // Limiar de umidade para acionar o LED

public:
  GerenciadorIrrigacao(SensorUmidade& s, AtuadorLED& l, int lmiar); // Construtor
  void atualizar();      // Atualiza o estado da irrigação (liga/desliga o LED)
};

#endif
