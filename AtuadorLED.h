#ifndef ATUADOR_LED_H
#define ATUADOR_LED_H

class AtuadorLED {
  int pino;
public:
  AtuadorLED(int p);
  void ligar();
  void desligar();
  // bool estaLigado(); // Implemente se quiser monitorar o estado
};

#endif
