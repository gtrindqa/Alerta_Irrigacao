#ifndef ATUADOR_LED_H
#define ATUADOR_LED_H

// Classe responsável por controlar um LED via GPIO
class AtuadorLED {
  int pino; // Pino onde o LED está conectado

public:
  AtuadorLED(int p);  // Construtor, recebe o pino a ser utilizado
  void ligar();       // Liga o LED
  void desligar();    // Desliga o LED
  // bool estaLigado(); // Implemente se quiser monitorar o estado do LED
};

#endif
