#include <WiFi.h>

#ifndef wifi_file
#define wifi_file

class WifiEsp {
  public:
    WifiEsp(char* ssid, char* password);
    void begin();
    bool isConnected();
    WiFiClient instance();

  private: 
    char* ssid;
    char* password;
};
#endif