#include "ArduinoJson.h"
#include <PubSubClient.h>

#ifndef mqtt_file
#define mqtt_file

class Mqtt {
  public:
    Mqtt(PubSubClient &mqttClient, char* mqttHost, uint16_t port);
    Mqtt(PubSubClient &mqttClient, char* mqttHost, uint16_t port, char* mqttUsername, char* mqttPassword);

    void setServer();
    void connect();
    bool isConnected();
    void publish(char* topic, char* payload);
    void loop();
    
  private:
    char* mqttHost;
    uint16_t mqttPort;
    char* mqttUsername;
    char* mqttPassword;
    PubSubClient &mqttClient;
};
#endif