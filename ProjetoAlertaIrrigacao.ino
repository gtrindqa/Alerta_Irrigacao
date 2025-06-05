#include <WiFi.h>
#include "SensorUmidade.h"
#include "AtuadorLED.h"
#include "GerenciadorIrrigacao.h"
#include "ComunicadorMQTT.h"

const char* SSID = "NOME_DA_REDE_WIFI";
const char* SENHA = "SENHA_DA_REDE_WIFI";
const char* BROKER_MQTT = "ENDEREÇO_DO_BROKER";
const char* topicoPublicacao = "irrigador/umidade";
const char* topicoEstadoLED = "irrigador/estado/led";

const int pinoSensor = 34;
const int pinoLED = 2;
const int limiarUmidade = 2000;

// Objetos globais
WiFiClient wifiClient;
SensorUmidade sensor(pinoSensor);
AtuadorLED led(pinoLED);
GerenciadorIrrigacao gerenciador(sensor, led, limiarUmidade);
ComunicadorMQTT comunicador(wifiClient, BROKER_MQTT, topicoPublicacao);

// Controle de tempo para envio periódico
unsigned long ultimoEnvio = 0;
const unsigned long intervaloEnvio = 3000; // 3 segundos

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID, SENHA);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");

  comunicador.iniciar();
}

void loop() {
  comunicador.manterConexao();
  comunicador.loop();
  gerenciador.atualizar();

  unsigned long agora = millis();
  if (agora - ultimoEnvio >= intervaloEnvio) {
    ultimoEnvio = agora;
    int valorUmidade = sensor.ler();
    comunicador.publicarUmidade(valorUmidade);

    // Estado do LED
    bool ledLigado = digitalRead(pinoLED);
    comunicador.publicarEstadoLED(ledLigado, topicoEstadoLED);

    Serial.print("Enviado ao MQTT: ");
    Serial.println(valorUmidade);
    Serial.print("Estado LED: ");
    Serial.println(ledLigado ? "ON" : "OFF");
  }
}
