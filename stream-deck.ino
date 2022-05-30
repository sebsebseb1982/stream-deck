#include <Adafruit_GFX.h>

#include <moonPhase.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#include "wifi-connection.h"
#include "screen.h"
#include "widget-temperature.h"
#include "widget-datetime.h"
#include "widget-toggle-button.h"
#include "widget-button.h"
#include "jeedom.h"
#include "touch-screen.h"
#include "duration.h"

#include "weather-forecast.h"
#include "images.h"

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

static TFT_eSPI screen = TFT_eSPI();
Screen screenSetup(&screen);

TwoDaysWeatherForecasts twoDaysWeatherForecasts;

unsigned long count = 0;

WidgetTemperature etage(
  5,
  0,
  "Etage",
  &screen,
  ONE_MINUTE,
  315
);

WidgetTemperature rdc(
  5,
  1,
  "RDC",
  &screen,
  ONE_MINUTE,
  314
);

WidgetTemperature exterieur(
  5,
  2,
  "Exterieur",
  &screen,
  ONE_MINUTE,
  320
);

WidgetTemperature setPoint(
  4,
  1,
  "Chauffage",
  &screen,
  ONE_MINUTE,
  291
);

WidgetButton setPointPlus(
  4,
  2,
  "Consigne +",
  &screen,
  ONE_MINUTE,
  increment,
  291
);

WidgetButton setPointMinus(
  4,
  3,
  "Consigne -",
  &screen,
  ONE_MINUTE,
  decrement,
  291
);

WidgetToggleButton office(
  1,
  1,
  "Bureau",
  &screen,
  FIVE_SECONDS,
  683
);

WidgetButton gate(
  0,
  1,
  "Portail",
  &screen,
  ONE_MINUTE,
  setToOne,
  338
);

WidgetDatetime datetime(
  0,
  0,
  "",
  &screen,
  FIVE_SECONDS
);

void setup() {
  Serial.begin(115200);
  WiFiConnection().init();
  screenSetup.init();
  twoDaysWeatherForecasts = getWeatherForecasts();
  etage.init();
  rdc.init();
  exterieur.init();
  setPoint.init();
  setPointPlus.init();
  setPointMinus.init();
  office.init();
  gate.init();
  datetime.init();
  pinMode(25, OUTPUT);
}

void loop() {
  count++;
  TouchScreen::refresh(&screen);
  screenSetup.loop();
  datetime.refresh();
  drawWindowsWidget(4, 0);

  office.refresh();
  gate.refresh();

  drawWeatherForecastsWidgets();

  refreshHeaterWidgets();
  refreshTemperatureWidgets();
  screen.drawString(
    String(count),
    60,
    290,
    1
  );
}

void drawWeatherForecastsWidgets() {
  drawMeteoWidget(
    1,
    0,
    twoDaysWeatherForecasts.today,
    "Auj."
  );

  drawMeteoWidget(
    2,
    0,
    twoDaysWeatherForecasts.tomorrow,
    "Demain"
  );
}

void refreshHeaterWidgets() {
  setPoint.refresh();
  setPointPlus.refresh();
  setPointMinus.refresh();
}

void refreshTemperatureWidgets() {
  etage.refresh();
  rdc.refresh();
  exterieur.refresh();
}
