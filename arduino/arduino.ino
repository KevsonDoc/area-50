#include <DHT.h>
#include "Sensor.hpp"
#include "src/led/Led.hpp"

#define DHT_PIN 15
#define DHT_TYPE DHT11
#define LCD_PIN 17

DHT dht(DHT_PIN, DHT_TYPE);
Sensor sensor(dht);

Led lowTemperatureAlert = Led(16);
Led normalTemperatureAlert = Led(4);
Led highTemperatureAlert = Led(2);

Led lowHumidityAlert = Led(23);
Led normalHumidityAlert = Led(22);
Led highHumidityAlert = Led(21);

void setup()
{
  Serial.begin(115200);
  dht.begin();
  highHumidityAlert.begin();
  normalHumidityAlert.begin();
  lowHumidityAlert.begin();
  highTemperatureAlert.begin();
  normalTemperatureAlert.begin();
  lowTemperatureAlert.begin();
}

void loop()
{
  delay(1000);
  sensor.setHumidity();
  sensor.setTemperature();

  if (sensor.isHighHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Alta");
    highHumidityAlert.lightUp();
  } else {
    highHumidityAlert.turnOff();
  }

  if (sensor.isNormalHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Normal");
    normalHumidityAlert.lightUp();
  } else {
    normalHumidityAlert.turnOff();
  }

  if (sensor.isLowHumidity()) {
    Serial.print(sensor.getHumidity());
    Serial.print(" % ");
    Serial.println("|| Humidade Baixa");
    lowHumidityAlert.lightUp();
  } else {
    lowHumidityAlert.turnOff();
  }

  if (sensor.isHighTemperature()) {
    highTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print("°C ");
    Serial.println("|| Temperatura Alta");
  } else {
    highTemperatureAlert.turnOff();
  }

  if (sensor.isNormalTemperature()) {
    normalTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print(F("°C "));
    Serial.println("|| Temperatura Normal");
  } else {
    normalTemperatureAlert.turnOff();
  }

  if (sensor.isLowTemperature()) {
    lowTemperatureAlert.lightUp();

    Serial.print(sensor.getTemperature());
    Serial.print("°C ");
    Serial.println("|| Temperatura Baixa");
  } else {
    lowTemperatureAlert.turnOff();
  }
}