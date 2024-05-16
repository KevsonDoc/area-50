#include "Sensor.hpp"

Sensor::Sensor(DHT &f) : dht(f) {
}

void Sensor::setHumidity() {
  this->humidity = dht.readHumidity();
}

void Sensor::setTemperature() {
  this->temperature = dht.readTemperature();
}

void Sensor::begin() {
  configTime(3600, 3600, "pool.ntp.org");
}

void Sensor::setTimeInfo() {
  if(!getLocalTime(&this->timeInfo)){
    Serial.println("Falha ao obter hora");
  }
}

tm Sensor::getTimeInfo() {
  return this->timeInfo;
}

bool Sensor::isHighHumidity() {
  if (this->getHumidity() > 70.00) {
    return true;
  }

  return false;
}

bool Sensor::isNormalHumidity() {
  if (this->getHumidity() >= 30.00 && this->getHumidity() <= 70.00) {
    return true;
  }

  return false;
}

bool Sensor::isLowHumidity()
{
  if (this->getHumidity() < 30.00)
  {
    return true;
  }

  return false;
}

bool Sensor::isHighTemperature()
{
  if (this->getTemperature() > 30.00)
  {
    return true;
  }

  return false;
}

bool Sensor::isNormalTemperature()
{
  if (this->getTemperature() >= 18.00 && this->getTemperature() <= 30.00)
  {
    return true;
  }

  return false;
}

bool Sensor::isLowTemperature()
{
  if (this->getTemperature() < 18.00)
  {
    return true;
  }

  return false;
}

float Sensor::getTemperature()
{
  return this->temperature;
}

float Sensor::getHumidity()
{
  return this->humidity;
}

char* Sensor::toJSON() {
  StaticJsonDocument<200> doc;
  char timeStringBuff[50]; //50 chars should be enough
  strftime(timeStringBuff, sizeof(timeStringBuff), "%Y-%m-%dT%H:%M:%S", &this->timeInfo);

  doc["temperature"] = this->getTemperature();
  doc["humidity"] = this->getHumidity();
  doc["datetime"] = timeStringBuff;

  serializeJson(doc, this->jsonBuffer);
  return this->jsonBuffer;
}
