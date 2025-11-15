#include <DHT.h>

// -------------------- PINAGEM --------------------
#define TRIGGER_PIN  17
#define ECHO_PIN     35

#define DHTPIN       16
#define DHTTYPE      DHT22

// -------------------- OBJETOS --------------------
DHT dht(DHTPIN, DHTTYPE);

// -------------------- MQTT --------------------
const char* default_BROKER_MQTT = "44.223.43.74"; // IP do Broker MQTT
const int default_BROKER_PORT = 1883; // Porta do Broker MQTT
const int default_D4 = 2; // Pino do LED onboard

// Configurações - Dispositivo
const char* default_TOPICO_SUBSCRIBE = "/TEF/device002/cmd"; // Tópico MQTT de escuta
const char* default_TOPICO_PUBLISH_1 = "/TEF/device002/attrs"; // Tópico MQTT de envio de informações para Broker
const char* default_TOPICO_PUBLISH_2 = "/TEF/device002/attrs/p"; // Tópico MQTT de envio de informações para Broker
const char* default_ID_MQTT = "fiware_002"; // ID MQTT
const char* topicPrefix = "device002";   // Declaração da variável para o prefixo do tópico

// Variáveis para configurações editáveis

char* BROKER_MQTT = const_cast<char*>(default_BROKER_MQTT);
int BROKER_PORT = default_BROKER_PORT;
char* TOPICO_SUBSCRIBE = const_cast<char*>(default_TOPICO_SUBSCRIBE);
char* TOPICO_PUBLISH_1 = const_cast<char*>(default_TOPICO_PUBLISH_1);
char* TOPICO_PUBLISH_2 = const_cast<char*>(default_TOPICO_PUBLISH_2);
char* ID_MQTT = const_cast<char*>(default_ID_MQTT);

// -------------------- CONFIG ---------------------
long medirDistancia() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH, 30000);  
  long distancia = duracao * 0.034 / 2; // velocidade do som ~ 0.034 cm/us

  return distancia; // em cm
}

// -------------------- SETUP ----------------------
void setup() {
  Serial.begin(115200);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  dht.begin();
}

// -------------------- LOOP -----------------------
void loop() {
  // ----- DISTÂNCIA -----
  long distancia = medirDistancia();

  // ----- TEMPERATURA / UMIDADE -----
  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  // ----- CHECAGEM DE ERRO -----
  if (isnan(temp) || isnan(umid)) {
    Serial.println("Erro ao ler o DHT22");
  }

  // ----- "MOVIMENTO" pelo HC-SR04 (variação brusca) -----
  // Exemplo de simples detecção:
  static long ultimaDist = distancia;
  bool movimento = abs(distancia - ultimaDist) > 5; // diferença de 5 cm
  ultimaDist = distancia;

  // ----- OUTPUT -----
  Serial.println("------ LEITURAS ------");
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Umidade: ");
  Serial.print(umid);
  Serial.println(" %");

  Serial.print("Movimento detectado: ");
  Serial.println(movimento ? "SIM" : "NAO");

  Serial.println("------------------------\n");

  delay(1000);
}
