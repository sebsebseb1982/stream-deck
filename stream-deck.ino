#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <TimeLib.h>

#include "secret.h"
#include "time.h"
#include "images.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

#define BUTTON_SIZE 64
#define TIME_BUTTON_X 0
#define TIME_BUTTON_Y 0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "fr.pool.ntp.org", 3600, 60000);

void setup() {
  Serial.begin(115200);
  setupDisplay();
  setupWifi();
  setupTime();
}

void loop() {
  display.clearDisplay();
  Serial.print(timeClient.getFormattedTime());
  Serial.print(" ");
  Serial.println(getFormattedDateDDMM(getDateTime()));
  drawDateTimeButton(
    TIME_BUTTON_X,
    TIME_BUTTON_Y
  );
  drawImageButton(
    TIME_BUTTON_X + BUTTON_SIZE,
    TIME_BUTTON_Y,
    "Bureau"
  );
  display.display();
}
