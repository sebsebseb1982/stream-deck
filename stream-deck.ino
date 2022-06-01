#include <Adafruit_GFX.h>

#include <moonPhase.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#include "wifi-connection.h"
#include "screen.h"
#include "buzzer.h"
#include "widget.h"
#include "widget-temperature.h"
#include "widget-datetime.h"
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
Screen screenSetup(&screen);

WidgetDatetime          datetime     (0, 0, "",           &screen, FIVE_SECONDS);
WidgetWeatherForecast   today        (1, 0, "Ajd",        &screen, ONE_HOUR,     getTodayForecast);
WidgetWeatherForecast   tomorrow     (2, 0, "Demain",     &screen, ONE_HOUR,     getTomorrowForecast);
WidgetTemperature       etage        (5, 0, "Etage",      &screen, ONE_MINUTE,   315);
WidgetTemperature       rdc          (5, 1, "RDC",        &screen, ONE_MINUTE,   314);
WidgetTemperature       exterieur    (5, 2, "Exterieur",  &screen, ONE_MINUTE,   320);
WidgetTemperature       setPoint     (4, 1, "Chauffage",  &screen, FIVE_SECONDS, 291);
WidgetButton            setPointPlus (4, 2, "Consigne +", &screen, ONE_MINUTE,   increment, 291);
WidgetButton            setPointMinus(4, 3, "Consigne -", &screen, ONE_MINUTE,   decrement, 291);
WidgetToggleButton      office       (1, 1, "Bureau",     &screen, FIVE_SECONDS, 683);
WidgetButton            gate         (0, 1, "Portail",    &screen, ONE_MINUTE,   setToOne,  338);
WidgetWindows           windows      (4, 0, "Aeration",   &screen, ONE_MINUTE);
WidgetDoorBell          doorBell     (0, 3, "Sonnette",   &screen, ONE_SECOND);

#define widgetNumbers 13
Widget *widgets[widgetNumbers];

void setup() {
  Serial.begin(115200);
  Buzzer::setup();
  WiFiConnection().init();
  screenSetup.init();
   
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

  for (int i = 0; i < widgetNumbers; i++) {
    widgets[i]->init();
  }
}

void loop() {
  TouchScreen::refresh(&screen);
  screenSetup.loop();
  Buzzer::refresh();

  for (int i = 0; i < widgetNumbers; i++) {
    widgets[i]->refresh();
  }
}
