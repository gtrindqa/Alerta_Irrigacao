#include "ComunicadorMQTT.h"

ComunicadorMQTT::ComunicadorMQTT(WiFiClient& client, const char* broker, const char* pubTopic)
  : wifiClient(client), mqttClient(client), server(broker), topicoPublicacao(pubTopic) {}

void ComunicadorMQTT::iniciar() {
  mqttClient.setServer(server, 1883);
}

void ComunicadorMQTT::manterConexao() {
  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP32_Irrigador")) {
      // Não há mais subscribe
    } else {
      delay(5000);
    }
  }
}

void ComunicadorMQTT::publicarUmidade(int valor) {
  mqttClient.publish(topicoPublicacao, String(valor).c_str());
}

// Implementação para publicar estado do LED
void ComunicadorMQTT::publicarEstadoLED(bool ligado, const char* topico) {
  mqttClient.publish(topico, ligado ? "ON" : "OFF");
}

void ComunicadorMQTT::loop() {
  mqttClient.loop();
}
