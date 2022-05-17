#include <Adafruit_GFX.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <LCDWIKI_GUI.h>

#include "SSD1283A.h"
#include "display.h"
#include "secret.h"
#include "images.h"
#include "buttons.h"

#define SCREEN_WIDTH 130 // OLED display width, in pixels
#define SCREEN_HEIGHT 130 // OLED display height, in pixels

#define BUTTON_SIZE 64
#define TIME_BUTTON_X 0
#define TIME_BUTTON_Y 0
#define HTTP_RETRY 10

SSD1283A_GUI screen(/*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*LED=*/ 4); //hardware spi,cs,cd,reset,led

GFXcanvas16T<SCREEN_WIDTH, SCREEN_HEIGHT> display;

void setup() {
  Serial.begin(115200);
  setupDisplay();
  setupWifi();
  setupButtons();
}

void loop() {
  loopButtons();
  loopDisplay();
  display.fillScreen(BACKGROUND_COLOR);
  drawWindowsButton(
    TIME_BUTTON_X,
    TIME_BUTTON_Y
  );
  drawTemperatureButton(
    TIME_BUTTON_X,
    TIME_BUTTON_Y + BUTTON_SIZE + 1,
    "Exterieur",
    320
  );
  drawTemperatureButton(
    TIME_BUTTON_X + BUTTON_SIZE + 1,
    TIME_BUTTON_Y,
    "Interieur",
    305
  );
  drawImageButton(
    TIME_BUTTON_X + BUTTON_SIZE + 1,
    TIME_BUTTON_Y + BUTTON_SIZE + 1,
    "Bureau"
  );
  screen.drawRGBBitmap(
    0,
    0,
    display.getBuffer(),
    display.width(),
    display.height()
  );
}
