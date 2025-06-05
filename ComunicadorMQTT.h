#ifndef COMUNICADOR_MQTT_H
#define COMUNICADOR_MQTT_H

#include <PubSubClient.h>
#include <WiFi.h>

// Classe responsável pela comunicação MQTT
class ComunicadorMQTT {
  WiFiClient& wifiClient;        // Referência ao cliente WiFi
  PubSubClient mqttClient;       // Cliente MQTT
  const char* server;            // Endereço do broker MQTT
  const char* topicoPublicacao;  // Tópico para publicação dos dados de umidade

public:
  ComunicadorMQTT(WiFiClient& client, const char* broker, const char* pubTopic); // Construtor
  void iniciar();                      // Inicializa o cliente MQTT
  void manterConexao();                // Mantém conexão com o broker MQTT
  void publicarUmidade(int valor);     // Publica dados de umidade
  void publicarEstadoLED(bool ligado, const char* topico); // Publica estado do LED
  void loop();                         // Mantém o cliente funcionando
};

#endif
