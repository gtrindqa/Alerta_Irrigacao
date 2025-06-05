#include "GerenciadorIrrigacao.h"
#include <Arduino.h>

// Construtor da classe GerenciadorIrrigacao
// Recebe referências ao sensor de umidade, ao LED e ao valor do limiar de umidade
GerenciadorIrrigacao::GerenciadorIrrigacao(SensorUmidade& s, AtuadorLED& l, int lmiar)
  : sensor(s), led(l), limiar(lmiar) {}

// Método principal que deve ser chamado repetidamente (loop)
// Lê o valor do sensor e aciona/desliga o LED conforme o limiar configurado
void GerenciadorIrrigacao::atualizar() {
  int valor = sensor.ler();
  Serial.print("Umidade: ");
  Serial.println(valor);

  if (valor > limiar) {    // Se a umidade for maior que o limiar, liga o LED
    led.ligar();
  } else {                 // Caso contrário, desliga o LED
    led.desligar();
  }
}
