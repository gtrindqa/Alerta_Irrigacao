#include "GerenciadorIrrigacao.h"
#include <Arduino.h>

GerenciadorIrrigacao::GerenciadorIrrigacao(SensorUmidade& s, AtuadorLED& l, int lmiar)
  : sensor(s), led(l), limiar(lmiar) {}

void GerenciadorIrrigacao::atualizar() {
  int valor = sensor.ler();
  Serial.print("Umidade: ");
  Serial.println(valor);

  if (valor > limiar) {
    led.ligar();
  } else {
    led.desligar();
  }
}
