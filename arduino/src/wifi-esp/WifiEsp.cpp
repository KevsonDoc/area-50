#include "WifiEsp.hpp"

WifiEsp::WifiEsp(char* ssid, char* password) {
  this->ssid = ssid;
  this->password = password;
};

void WifiEsp::begin() {
  WiFi.begin(this->ssid, this->password);

  while (!this->isConnected()) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  Serial.println("Conectado ao Wi-Fi!");
  Serial.print("Seu IP local: ");
  Serial.println(WiFi.localIP());
};



bool WifiEsp::isConnected() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }

  return false;
};

WiFiClient WifiEsp::instance() {
  WiFiClient wiFiClient;
  return wiFiClient;
}