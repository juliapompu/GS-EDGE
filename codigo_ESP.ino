#include <DHT.h>

// -------------------- PINAGEM --------------------
#define TRIGGER_PIN  17
#define ECHO_PIN     35

#define DHTPIN       16
#define DHTTYPE      DHT22 //ou DHT11

// -------------------- OBJETOS --------------------
DHT dht(DHTPIN, DHTTYPE);

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
