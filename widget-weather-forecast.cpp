#include <TimeLib.h>
#include "widget-weather-forecast.h"
#include "widget-weather-forecast-callback.h"
#include "gui.h"
#include "colors.h"
#include "images.h"

WidgetWeatherForecast::WidgetWeatherForecast(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs,
  WidgetWeatherForecastCallback callback
) : Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {
  this->callback = callback;
}

void WidgetWeatherForecast::draw() {
  gui.drawDoubleButton(
    x,
    y,
    label,
    UNAVAILABLE
  );
  screen->drawBitmap(
    x + 16,
    y + 10,
    clearSky,
    50,
    50,
    WHITE
  );

  String date;
  int dateDay = day(weatherForecast.date);
  if (dateDay < 10) {
    date += "0";
  }
  date += String(dateDay);
  date += F("/");
  int dateMonth = month(weatherForecast.date);
  if (dateMonth < 10) {
    date += "0";
  }
  date += String(dateMonth);

  screen->drawString(
    date,
    x + BUTTON_SIZE / 2,
    y + 70,
    2
  );
  screen->drawString(
    "Min " + String((int)round(weatherForecast.min)),
    x + BUTTON_SIZE / 2,
    y + 100,
    2
  );
  screen->drawString(
    "Max " + String((int)round(weatherForecast.max)),
    x + BUTTON_SIZE / 2,
    y + 120,
    2
  );

  previousWeatherForecast = weatherForecast;
}

void WidgetWeatherForecast::refreshValue() {
  weatherForecast = (*callback) ();
}

boolean WidgetWeatherForecast::isValueChanged() {
  return weatherForecast.date != previousWeatherForecast.date
         || weatherForecast.icon != previousWeatherForecast.icon
         || weatherForecast.min != previousWeatherForecast.min
         || weatherForecast.max != previousWeatherForecast.max;
}

void WidgetWeatherForecast::manageTouch() {
  //Serial.println("WidgetWeatherForecast::manageTouch()");
}

void WidgetWeatherForecast::manageTouchDown() {
  //Serial.println("WidgetWeatherForecast::manageTouchDown()");
}

void WidgetWeatherForecast::manageTouchUp() {
  //Serial.println("WidgetWeatherForecast::manageTouchUp()");
}
