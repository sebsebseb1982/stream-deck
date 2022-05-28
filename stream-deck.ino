#include <Adafruit_GFX.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <LCDWIKI_GUI.h>
#include <moonPhase.h>
#include <ArduinoJson.h>
#include <SPI.h>

#include <TFT_eSPI.h> // Hardware-specific library


#include "display.h"
#include "gui.h"
#include "secret.h"
#include "weather-forecast.h"
#include "images.h"
#include "buttons.h"

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

#define SCREEN_WIDTH 480 // OLED display width, in pixels
#define SCREEN_HEIGHT 320 // OLED display height, in pixels

#define TIME_BUTTON_X 0
#define TIME_BUTTON_Y 0
#define HTTP_RETRY 10

TFT_eSPI screen = TFT_eSPI();
//SSD1283A_GUI screen(/*CS=5*/ SS, /*DC=*/ 17, /*RST=*/ 16, /*LED=*/ 4); //hardware spi,cs,cd,reset,led

//GFXcanvas16T<SCREEN_WIDTH, SCREEN_HEIGHT> display;

TwoDaysWeatherForecasts twoDaysWeatherForecasts;

void setup() {
  Serial.begin(115200);
  setupScreen();
  setupWifi();
  setupButtons();

  twoDaysWeatherForecasts = getWeatherForecasts();
}

void loop() {
  loopButtons();
  //loopScreen();
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
/*
  drawMeteoWidget(
    TIME_BUTTON_X + BUTTON_SIZE + 1,
    TIME_BUTTON_Y + BUTTON_SIZE + 1,
    twoDaysWeatherForecasts.today,
    "Auj."
  );
  */
  /*tft.drawRGBBitmap(
    0,
    0,
    screen.getBuffer(),
    screen.width(),
    screen.height()
  );*/
}
