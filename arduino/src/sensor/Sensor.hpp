#include <DHT.h>
#include "ArduinoJson.h"

#ifndef sensor_file
#define sensor_file

class Sensor {
  public:
    Sensor(DHT &dht);
    void setTemperature();
    void setHumidity();
    void setTimeInfo();
    void begin();
    tm getTimeInfo();
    bool isHighHumidity();
    bool isNormalHumidity();
    bool isLowHumidity();
    bool isHighTemperature();
    bool isNormalTemperature();
    bool isLowTemperature();
    float getTemperature();
    float getHumidity();
    char* toJSON();

  private:
    struct tm timeInfo;
    float temperature = 0.0;
    float humidity = 0.0;
    char jsonBuffer[512];
    DHT &dht;
};
#endif