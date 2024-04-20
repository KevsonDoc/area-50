#line 1 "/home/kevson/Desktop/www/github/area-50/arduino/Sensor.cpp"
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

bool Sensor::isHighHumidity()
{
  if (this->getHumidity() > 70.00)
  {
    return true;
  }

  return false;
}

bool Sensor::isNormalHumidity()
{
  if (this->getHumidity() >= 30.00 && this->getHumidity() <= 70.00)
  {
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
  return temperature;
}

float Sensor::getHumidity()
{
  return humidity;
}