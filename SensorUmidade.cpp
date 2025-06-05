#include "SensorUmidade.h"
#include <Arduino.h>

SensorUmidade::SensorUmidade(int p) : pino(p) {
  pinMode(pino, INPUT);
}

int SensorUmidade::ler() {
  return analogRead(pino);
}
