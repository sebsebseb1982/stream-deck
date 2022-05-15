#include <WiFi.h>
#include <NTPClient.h>
#include <TimeLib.h>

#include "secret.h"
#include "time.h"

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "fr.pool.ntp.org", 3600, 60000);

void setup() {
  Serial.begin(115200);
  setupWifi();
  timeClient.begin();
  timeClient.update();
}

void loop() {
  Serial.print(timeClient.getFormattedTime());
  Serial.print(" ");
  Serial.println(getFormattedDate(getDateTime()));
}
