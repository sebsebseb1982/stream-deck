#include <WiFi.h>
#include "wifi-connection.h"
#include "wifi-connection.secret.h"

WiFiConnection::WiFiConnection() {}

void WiFiConnection::init() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connexion en cours ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connecté au WIFI avec l'adresse IP : ");
  Serial.println(WiFi.localIP());
}
