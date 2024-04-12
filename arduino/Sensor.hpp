#include <DHT.h>

#ifndef sensor_file
#define sensor_file

class Sensor
{

public:
  Sensor(DHT &dht);
  void setTemperature();
  void setHumidity();
  bool isHighHumidity();
  bool isNormalHumidity();
  bool isLowHumidity();
  bool isHighTemperature();
  bool isNormalTemperature();
  bool isLowTemperature();
  float getTemperature();
  float getHumidity();

private:
  float temperature = 0.0;
  float humidity = 0.0;
  DHT &dht;
};
#endif