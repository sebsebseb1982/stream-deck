#ifndef WEATHER_FORECAST_H
#define WEATHER_FORECAST_H

#include <Arduino.h>

#define HTTP_RETRY 10

struct WeatherForecast {
  int date;
  String icon;
  float min;
  float max;
};

struct TwoDaysWeatherForecasts {
  WeatherForecast today;
  WeatherForecast tomorrow;
};

class WeatherForecastClient {
  public:
    WeatherForecastClient();
    TwoDaysWeatherForecasts getWeatherForecasts();
};

#endif
