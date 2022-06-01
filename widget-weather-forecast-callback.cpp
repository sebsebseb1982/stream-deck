#include "widget-weather-forecast-callback.h"
#include "weather-forecast.h"

WeatherForecast getTodayForecast() {
  return WeatherForecastClient().getWeatherForecasts().today;
}

WeatherForecast getTomorrowForecast() {
  return WeatherForecastClient().getWeatherForecasts().tomorrow;
}
