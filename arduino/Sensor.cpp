#include "Sensor.hpp"

Sensor::Sensor(DHT &f) : dht(f)
{
}

void Sensor::setHumidity()
{
  temperature = dht.readTemperature();
}

void Sensor::setTemperature()
{
  humidity = dht.readHumidity();
}

float Sensor::getTemperature()
{
  return temperature;
}

float Sensor::getHumidity()
{
  return humidity;
}