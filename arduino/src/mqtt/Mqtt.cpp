#include "Mqtt.hpp"
#include <WiFi.h>

// WiFiClient wifiClient;
// PubSubClient mqttClient(wifiClient);

Mqtt::Mqtt(PubSubClient &f, char* mqttHost, uint16_t mqttPort): mqttClient(f) {
  this->mqttHost = mqttHost;
  this->mqttPort = mqttPort;
}

Mqtt::Mqtt(PubSubClient &f, char* mqttHost, uint16_t mqttPort, char* mqttUsername, char* mqttPassword): mqttClient(f) {
  this->mqttHost = mqttHost;
  this->mqttPort = mqttPort;
  this->mqttUsername = mqttUsername;
  this->mqttPassword = mqttPassword;
}

void Mqtt::setServer() {
  mqttClient.setServer(this->mqttHost, this->mqttPort);
}

void Mqtt::connect() {
  Serial.println("Conectando ao MQTT...");
  String clientId = "ESP32-client-";
  clientId += String(random(0xffff), HEX);
  if (this->mqttClient.connect(clientId.c_str())) {
    Serial.println("Conectado!");
  } else {
    Serial.println("falhou, rc=");
    Serial.print(this->mqttClient.state());
  }
}

bool Mqtt::isConnected() {
  if (this->mqttClient.connected()) {
    return true;
  }

  return false;
}

void Mqtt::loop () {
  this->mqttClient.loop();
}

void Mqtt::publish(char* topic, char* payload) {
  if (this->isConnected()) {
    this->mqttClient.publish(topic, payload);
  } else {
    Serial.print("Falha ao publicar no tópico: ");
    Serial.println(topic);
  }
}