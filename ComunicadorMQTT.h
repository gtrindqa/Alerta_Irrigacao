#ifndef COMUNICADOR_MQTT_H
#define COMUNICADOR_MQTT_H

#include <PubSubClient.h>
#include <WiFi.h>

class ComunicadorMQTT {
  WiFiClient& wifiClient;
  PubSubClient mqttClient;
  const char* server;
  const char* topicoPublicacao;
public:
  ComunicadorMQTT(WiFiClient& client, const char* broker, const char* pubTopic);
  void iniciar();
  void manterConexao();
  void publicarUmidade(int valor);
  void publicarEstadoLED(bool ligado, const char* topico); // <-- Adicionado aqui
  void loop();
};

#endif
