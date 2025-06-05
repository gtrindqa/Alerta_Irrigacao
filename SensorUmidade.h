#ifndef SENSOR_UMIDADE_H
#define SENSOR_UMIDADE_H

// Classe responsável pela leitura do sensor de umidade
class SensorUmidade {
  int pino; // Pino do sensor de umidade

public:
  SensorUmidade(int p); // Construtor, recebe o pino a ser utilizado
  int ler();            // Lê e retorna o valor do sensor
};

#endif
