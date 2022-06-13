#include <Adafruit_GFX.h>

#include <moonPhase.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <WiFi.h>

#include "wifi-connection.h"
#include "screen.h"
#include "buzzer.h"
#include "clock.h"
#include "widget.h"
#include "widget-temperature.h"
#include "widget-clock.h"
#include "widget-doorbell.h"
#include "widget-weather-forecast.h"
#include "widget-toggle-button.h"
#include "widget-button.h"
#include "widget-windows.h"
#include "jeedom.h"
#include "touch-screen.h"
#include "duration.h"

#include "weather-forecast.h"
#include "images.h"

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

static TFT_eSPI screen = TFT_eSPI();
Clock ntpClock = Clock();
Screen screenSetup(&screen);

WidgetClock             datetime     (0, 0, "",               &screen, ONE_MINUTE);
WidgetWeatherForecast   today        (1, 0, "Ajd",            &screen, THREE_HOURS,       getTodayForecast);
WidgetWeatherForecast   tomorrow     (2, 0, "Demain",         &screen, THREE_HOURS,       getTomorrowForecast);
WidgetTemperature       etage        (5, 0, "Etage",          &screen, FIVE_MINUTES,      315);
WidgetTemperature       rdc          (5, 1, "RDC",            &screen, FIVE_MINUTES,      314);
WidgetTemperature       exterieur    (5, 2, "Exterieur",      &screen, FIVE_MINUTES,      320);
WidgetTemperature       setPoint     (4, 1, "Chauffage",      &screen, FIVE_SECONDS,      291);
WidgetButton            setPointPlus (4, 2, "Consigne +",     &screen, ONE_HOUR,          increment, 291);
WidgetButton            setPointMinus(4, 3, "Consigne -",     &screen, ONE_HOUR,          decrement, 291);
WidgetToggleButton      office       (3, 0, "Bureau",         &screen, THIRTHY_MINUTES,   683);
WidgetButton            gate         (0, 1, "Portail",        &screen, THREE_HOURS,       setToOne,  338);
WidgetWindows           windows      (4, 0, "Aeration",       &screen, ONE_MINUTE);
WidgetDoorBell          doorBell     (0, 3, "Sonnette",       &screen, FIVE_SECONDS);
WidgetToggleButton      fan          (5, 3, "Ventilateur",    &screen, THIRTHY_MINUTES,   696);

#define widgetNumbers 14
Widget *widgets[widgetNumbers];

void setup() {
  Serial.begin(115200);
  Buzzer::setup();
  WiFiConnection().init();
  screenSetup.init();
  ntpClock.setup();
   
  widgets[0] = &datetime;
  widgets[1] = &etage;
  widgets[2] = &rdc;
  widgets[3] = &exterieur;
  widgets[4] = &setPoint;
  widgets[5] = &setPointPlus;
  widgets[6] = &setPointMinus;
  widgets[7] = &office;
  widgets[8] = &gate;
  widgets[9] = &windows;
  widgets[10] = &doorBell;
  widgets[11] = &today;
  widgets[12] = &tomorrow;
  widgets[13] = &fan;

  for (int i = 0; i < widgetNumbers; i++) {
    widgets[i]->init();
  }
}

void loop() {
  TouchScreen::refresh(&screen);
  screenSetup.loop();
  Buzzer::refresh();
  Clock::loop();

  for (int i = 0; i < widgetNumbers; i++) {
    widgets[i]->refresh();
  }

  screen.drawString(
    "         ",
    200,
    300,
    1
  );
  screen.drawString(
    String(ESP.getFreeHeap()),
    200,
    300,
    1
  );

  screen.drawString(
    "         ",
    200,
    280,
    1
  );
  screen.drawString(
    String(WiFi.RSSI()),
    200,
    280,
    1
  );
}
