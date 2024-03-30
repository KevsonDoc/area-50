#include "Sensor.hpp"

Sensor::Sensor(DHT &f) : dht(f)
{
}

void Sensor::setHumidity()
{
  humidity = dht.readHumidity();
}

void Sensor::setTemperature()
{
  temperature = dht.readTemperature();
}

float Sensor::getTemperature()
{
  return temperature;
}

float Sensor::getHumidity()
{
  return humidity;
}