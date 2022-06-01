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
  gui.drawButton(
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
  previousWeatherForecast = weatherForecast;
}

void WidgetWeatherForecast::refreshValue() {
  weatherForecast = (*callback) ();

  String date;
  date += String(day(weatherForecast.date));
  date += F("/");
  date += String(month(weatherForecast.date));
  date += F(" ");
  date += String((int)round(weatherForecast.min));
  date += F("/");
  date += String((int)round(weatherForecast.max));
  label = date;
}

boolean WidgetWeatherForecast::isValueChanged() {
  return weatherForecast.date != previousWeatherForecast.date
         || weatherForecast.icon != previousWeatherForecast.icon
         || weatherForecast.min != previousWeatherForecast.min
         || weatherForecast.max != previousWeatherForecast.max;
}

void WidgetWeatherForecast::manageTouch() {
  Serial.println("WidgetButton::manageTouch()");
}

void WidgetWeatherForecast::manageTouchDown() {
  Serial.println("WidgetButton::manageTouchDown()");
}

void WidgetWeatherForecast::manageTouchUp() {
  Serial.println("WidgetButton::manageTouchUp()");
}
