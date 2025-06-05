#include "AtuadorLED.h"
#include <Arduino.h>

// Construtor da classe AtuadorLED
// Inicializa o pino do LED como saída e garante que ele inicia desligado
AtuadorLED::AtuadorLED(int p) : pino(p) {
  pinMode(pino, OUTPUT); // Configura o pino como saída
  desligar();            // Garante que o LED começa desligado
}

// Liga o LED (coloca o pino em nível alto)
void AtuadorLED::ligar() {
  digitalWrite(pino, HIGH);
}

// Desliga o LED (coloca o pino em nível baixo)
void AtuadorLED::desligar() {
  digitalWrite(pino, LOW);
}
