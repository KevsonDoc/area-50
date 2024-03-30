#include <DHT.h>

#ifndef sensor
#define sensor

class Sensor
{

public:
  Sensor(DHT &dht);

  void setTemperature();
  float getTemperature();
  void setHumidity();
  float getHumidity();

private:
  float temperature = 0.0;
  float humidity = 0.0;
  DHT &dht;
};
#endif