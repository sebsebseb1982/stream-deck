#include <Adafruit_GFX.h>

#include <moonPhase.h>
#include <SPI.h>
#include <TFT_eSPI.h>

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
#include "widget-status.h"
#include "jeedom.h"
#include "touch-screen.h"
#include "duration.h"
#include "icons-32x32.h"

#include "weather-forecast.h"
#include "images.h"

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

static TFT_eSPI screen = TFT_eSPI();
Clock ntpClock = Clock();
Screen screenSetup(&screen);

WidgetClock datetime(0, 0, "", &screen, ONE_MINUTE);
WidgetWeatherForecast today(1, 0, "Ajd", &screen, THREE_HOURS, getTodayForecast);
WidgetWeatherForecast tomorrow(2, 0, "Demain", &screen, THREE_HOURS, getTomorrowForecast);
WidgetTemperature etage(5, 0, "Etage", &screen, FIVE_MINUTES, 315);
WidgetTemperature rdc(5, 1, "RDC", &screen, FIVE_MINUTES, 314);
WidgetTemperature exterieur(5, 2, "Exterieur", &screen, FIVE_MINUTES, 320);
WidgetTemperature setPoint(4, 1, "Chauffage", &screen, FIVE_SECONDS, 291);
WidgetButton setPointPlus(4, 2, "Consigne +", &screen, ONE_HOUR, increment, 291, arrowUp32x32);
WidgetButton setPointMinus(4, 3, "Consigne -", &screen, ONE_HOUR, decrement, 291, arrowDown32x32);
WidgetToggleButton office(3, 0, "Bureau", &screen, THIRTHY_MINUTES, 683, bulb32x32);
WidgetButton gate(0, 1, "Portail", &screen, THREE_HOURS, setToOne, 338, gate32x32);
WidgetWindows windows(4, 0, "Aeration", &screen, ONE_MINUTE);
WidgetDoorBell doorBell(0, 3, "Sonnette", &screen, FIVE_SECONDS);
WidgetToggleButton fan(5, 3, "Ventilateur", &screen, THIRTHY_MINUTES, 696, outlet32x32);
WidgetStatus status(0, 2, "Status", &screen, FIVE_SECONDS);

#define widgetNumbers 15
Widget *widgets[widgetNumbers];

TaskHandle_t taskUI;
TaskHandle_t taskBackground;

void setup() {
  Serial.begin(115200);
  Buzzer::setup();
  WiFiConnection::connect();
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
  widgets[14] = &status;

  for (int i = 0; i < widgetNumbers; i++) {
    widgets[i]->init();
  }

  xTaskCreatePinnedToCore(
    loopUI,   /* Task function. */
    "loopUI", /* name of task. */
    10000,    /* Stack size of task */
    NULL,     /* parameter of the task */
    1,        /* priority of the task */
    &taskUI,  /* Task handle to keep track of created task */
    0);

  xTaskCreatePinnedToCore(
    loopBackground,   /* Task function. */
    "loopBackground", /* name of task. */
    10000,            /* Stack size of task */
    NULL,             /* parameter of the task */
    1,                /* priority of the task */
    &taskBackground,  /* Task handle to keep track of created task */
    1);
}

void loop() {
}

void loopUI(void *pvParameters) {
  for (;;) {
    TouchScreen::refresh(&screen);
    screenSetup.loop();

    for (int i = 0; i < widgetNumbers; i++) {
      widgets[i]->refresh();
    }
  }
}

void loopBackground(void *pvParameters) {
  for (;;) {
    WiFiConnection::loop();
    Buzzer::refresh();
    Clock::loop();
  }
}
