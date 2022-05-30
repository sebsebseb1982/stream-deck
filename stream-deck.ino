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

#include "gui.h"
#include "weather-forecast.h"
#include "images.h"

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

static TFT_eSPI screen = TFT_eSPI();
Screen screenSetup(&screen);

TwoDaysWeatherForecasts twoDaysWeatherForecasts;

unsigned long temperatureWidgetsRefreshPeriodInMs = 1 /* minutes */ * 60 * 1000;

WidgetTemperature etage(
  5,
  0,
  "Etage",
  &screen,
  temperatureWidgetsRefreshPeriodInMs,
  315
);

WidgetTemperature rdc(
  5,
  1,
  "RDC",
  &screen,
  temperatureWidgetsRefreshPeriodInMs,
  314
);

WidgetTemperature exterieur(
  5,
  2,
  "Exterieur",
  &screen,
  temperatureWidgetsRefreshPeriodInMs,
  320
);

WidgetTemperature setPoint(
  4,
  1,
  "Chauffage",
  &screen,
  temperatureWidgetsRefreshPeriodInMs,
  291
);

WidgetButton setPointPlus(
  4,
  2,
  "Consigne +",
  &screen,
  1,
  increment,
  291
);

WidgetButton setPointMinus(
  4,
  3,
  "Consigne -",
  &screen,
  1,
  decrement,
  291
);

WidgetToggleButton office(
  1,
  1,
  "Bureau",
  &screen,
  1,
  683
);

WidgetButton gate(
  0,
  1,
  "Portail",
  &screen,
  1,
  setToOne,
  338
);

WidgetDatetime datetime(
  0,
  0,
  "",
  &screen,
  5 * 1000
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
}

void loop() {
  screenSetup.loop();
  datetime.refresh();
  drawWindowsWidget(4, 0);

  office.refresh();
  gate.refresh();

  drawWeatherForecastsWidgets();

  refreshHeaterWidgets();
  refreshTemperatureWidgets();
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
