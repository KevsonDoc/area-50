#include <DHT.h>
#include "src/sensor/Sensor.hpp"
#include "src/wifi-esp/WifiEsp.hpp"
#include "src/mqtt/Mqtt.hpp"

#define DHT_PIN 15
#define DHT_TYPE DHT11
#define LCD_PIN 17

char* ssid = "MultilaserPRO_ZTE_2.4G_TDEDEd";
char* password = "PSRMFKfR";
char* mqttHost = "192.168.1.4"; // Change to your MQTT broker address
uint16_t mqttPort = 1883;
char* mqttUsername = "";
char* mqttPassword = "";

char* topic = "sensor";

DHT dht(DHT_PIN, DHT_TYPE);
Sensor sensor(dht);
WifiEsp wifiEsp(ssid, password);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);
Mqtt mqtt (mqttClient, mqttHost, mqttPort);

void setup()
{
  Serial.begin(115200);
  dht.begin();
  wifiEsp.begin();
  mqtt.setServer();
  sensor.begin();
}

void loop()
{
  delay(1000);
  if (!mqtt.isConnected()) {
    mqtt.connect();
  } else {
    sensor.setHumidity();
    sensor.setTemperature();
    sensor.setTimeInfo();
    Serial.println(sensor.toJSON());
    mqtt.publish(topic, sensor.toJSON());
  }
  mqttClient.loop();
}