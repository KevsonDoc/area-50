#include <DHT.h>
#include "Sensor.hpp"
#include "src/led/Led.hpp"
#include <WiFi.h>
#include <PubSubClient.h>

#define DHT_PIN 15
#define DHT_TYPE DHT11
#define LCD_PIN 17

const char* ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
const char* password = "PSRMFKfR";
const char* mqttBroker = "192.168.1.9"; // Change to your MQTT broker address
const int mqttPort = 1883;
const char *topic = "sensor";

DHT dht(DHT_PIN, DHT_TYPE);
Sensor sensor(dht);

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void reconnect() {
  while (!mqttClient.connected()) {
    Serial.println("Connecting to MQTT broker...");
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    if (mqttClient.connect(client_id.c_str())) {
      Serial.println("Connected to MQTT broker!");
    } else {
      delay(1000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, password);
  mqttClient.setServer(mqttBroker, mqttPort);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  Serial.println("Conectado ao Wi-Fi!");
  Serial.println(WiFi.localIP());
}

void loop()
{
  delay(1000);
  sensor.setHumidity();
  sensor.setTemperature();
  
  if (!mqttClient.connected()) {
    reconnect();
  } else {
  mqttClient.publish(topic, "Hello WOrld");  }
  mqttClient.loop();

  // Serial.print(sensor.getHumidity());
  // Serial.print(" % ");
  // Serial.println("|| Humidade Alta");

  // Serial.print(sensor.getHumidity());
  // Serial.print(" % ");
  // Serial.println("|| Humidade Normal");

  // Serial.print(sensor.getHumidity());
  // Serial.print(" % ");
  // Serial.println("|| Humidade Baixa");

  // Serial.print(sensor.getTemperature());
  // Serial.print("°C ");
  // Serial.println("|| Temperatura Alta");

  // Serial.print(sensor.getTemperature());
  // Serial.print(F("°C "));
  // Serial.println("|| Temperatura Normal");

  // Serial.print(sensor.getTemperature());
  // Serial.print("°C ");
  // Serial.println("|| Temperatura Baixa");
}