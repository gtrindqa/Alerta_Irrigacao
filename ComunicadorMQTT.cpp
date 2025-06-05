#include "ComunicadorMQTT.h"

// Construtor da classe ComunicadorMQTT
// Inicializa as variáveis do objeto MQTT
ComunicadorMQTT::ComunicadorMQTT(WiFiClient& client, const char* broker, const char* pubTopic)
  : wifiClient(client), mqttClient(client), server(broker), topicoPublicacao(pubTopic) {}

// Inicializa o cliente MQTT definindo o broker e a porta
void ComunicadorMQTT::iniciar() {
  mqttClient.setServer(server, 1883);
}

// Garante que o dispositivo está conectado ao broker MQTT, tentando reconectar se necessário
void ComunicadorMQTT::manterConexao() {
  while (!mqttClient.connected()) {
    if (mqttClient.connect("ESP32_Irrigador")) {
      // Conectado ao broker MQTT (sem inscrição em tópicos aqui)
    } else {
      delay(5000); // Aguarda antes de tentar conectar novamente
    }
  }
}

// Publica o valor da umidade no tópico definido
void ComunicadorMQTT::publicarUmidade(int valor) {
  mqttClient.publish(topicoPublicacao, String(valor).c_str());
}

// Publica o estado do LED (ligado/desligado) em um tópico específico
void ComunicadorMQTT::publicarEstadoLED(bool ligado, const char* topico) {
  mqttClient.publish(topico, ligado ? "ON" : "OFF");
}

// Mantém o cliente MQTT funcionando (processa mensagens e reconexões)
void ComunicadorMQTT::loop() {
  mqttClient.loop();
}
