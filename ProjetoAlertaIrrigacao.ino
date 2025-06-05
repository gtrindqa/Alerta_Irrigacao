#include <WiFi.h>                         // Biblioteca para conexão WiFi no ESP32
#include "SensorUmidade.h"                // Inclusão do arquivo do sensor de umidade (provavelmente implementado à parte)
#include "AtuadorLED.h"                   // Inclusão do arquivo para controle do LED (atuador)
#include "GerenciadorIrrigacao.h"         // Classe que gerencia a lógica da irrigação
#include "ComunicadorMQTT.h"              // Classe responsável pela comunicação via MQTT

const char* SSID = "NOME_DA_REDE_WIFI";   // Nome da rede WiFi a ser conectada
const char* SENHA = "SENHA_DA_REDE_WIFI"; // Senha da rede WiFi
const char* BROKER_MQTT = "ENDEREÇO_DO_BROKER"; // Endereço do broker MQTT
const char* topicoPublicacao = "irrigador/umidade"; // Tópico MQTT para publicar o valor da umidade
const char* topicoEstadoLED = "irrigador/estado/led"; // Tópico MQTT para publicar o estado do LED

const int pinoSensor = 34;                // Pino analógico onde o sensor de umidade está conectado
const int pinoLED = 2;                    // Pino digital onde o LED está conectado
const int limiarUmidade = 2000;           // Valor limite de umidade para acionar/desligar a irrigação

// Objetos globais
WiFiClient wifiClient;                    // Objeto que representa a conexão WiFi
SensorUmidade sensor(pinoSensor);         // Instancia o sensor de umidade no pino definido
AtuadorLED led(pinoLED);                  // Instancia o LED no pino definido
GerenciadorIrrigacao gerenciador(sensor, led, limiarUmidade); // Objeto que controla a irrigação baseado na umidade
ComunicadorMQTT comunicador(wifiClient, BROKER_MQTT, topicoPublicacao); // Objeto que gerencia a comunicação MQTT

// Controle de tempo para envio periódico
unsigned long ultimoEnvio = 0;            // Marca o último momento em que os dados foram enviados
const unsigned long intervaloEnvio = 3000; // Intervalo para envio de dados (3 segundos)

void setup() {
  Serial.begin(115200);                   // Inicializa a comunicação serial com baudrate 115200
  WiFi.begin(SSID, SENHA);                // Inicia a conexão WiFi
  while (WiFi.status() != WL_CONNECTED) { // Aguarda até conectar ao WiFi
    delay(500);                           // Espera 500 ms
    Serial.print(".");                    // Imprime um ponto a cada tentativa de conexão
  }
  Serial.println("\nWiFi conectado!");    // Informa que conectou
  Serial.print("IP: ");                   // Exibe o IP atribuído
  Serial.println(WiFi.localIP());
  comunicador.iniciar();                  // Inicializa a conexão MQTT
}
