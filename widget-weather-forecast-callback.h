#include <Arduino.h>

#include "weather-forecast.h"

typedef WeatherForecast (*WidgetWeatherForecastCallback) ();

WeatherForecast getTodayForecast();
WeatherForecast getTomorrowForecast();
