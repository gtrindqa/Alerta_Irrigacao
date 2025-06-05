#include "AtuadorLED.h"
#include <Arduino.h>

AtuadorLED::AtuadorLED(int p) : pino(p) {
  pinMode(pino, OUTPUT);
  desligar();
}

void AtuadorLED::ligar() {
  digitalWrite(pino, HIGH);
}

void AtuadorLED::desligar() {
  digitalWrite(pino, LOW);
}
