#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "secret.h"
#include "images.h"
#include "buttons.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)

#define BUTTON_SIZE 64
#define TIME_BUTTON_X 0
#define TIME_BUTTON_Y 0
#define HTTP_RETRY 10

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
  setupDisplay();
  setupWifi();
  setupButtons();
}

void loop() {
  loopButtons();
  display.clearDisplay();
  /*drawDateTimeButton(
    TIME_BUTTON_X,
    TIME_BUTTON_Y
    );*/
  drawTemperatureButton(
    TIME_BUTTON_X,
    TIME_BUTTON_Y,
    "Exterieur",
    320
  );
  drawTemperatureButton(
    TIME_BUTTON_X + BUTTON_SIZE,
    TIME_BUTTON_Y,
    "Interieur",
    305
  );
  /*drawImageButton(
    TIME_BUTTON_X + BUTTON_SIZE,
    TIME_BUTTON_Y,
    "Bureau"
    );*/
  display.display();
}
