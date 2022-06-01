#include <Arduino.h>
#include <TFT_eSPI.h>

#include "widget.h"
#include "weather-forecast.h"
#include "widget-weather-forecast-callback.h"

class WidgetWeatherForecast : public Widget {
  private:
    WeatherForecast weatherForecast;
    WeatherForecast previousWeatherForecast;
    WidgetWeatherForecastCallback callback;
  public:
    WidgetWeatherForecast(
      unsigned int column,
      unsigned int row,
      String label,
      TFT_eSPI *screen,
      unsigned long refreshPeriodInMs,
      WidgetWeatherForecastCallback callback
    );
    void draw();
    void refreshValue();
    boolean isValueChanged();
    void manageTouch();
    void manageTouchUp();
    void manageTouchDown();
};
