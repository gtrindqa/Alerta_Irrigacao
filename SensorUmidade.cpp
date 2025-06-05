#include "SensorUmidade.h"
#include <Arduino.h>

// Construtor da classe SensorUmidade
// Inicializa o pino como entrada
SensorUmidade::SensorUmidade(int p) : pino(p) {
  pinMode(pino, INPUT); // Configura o pino como entrada analógica
}

// Lê o valor atual do sensor de umidade (0 a 4095 para ESP32)
int SensorUmidade::ler() {
  return analogRead(pino);
}
