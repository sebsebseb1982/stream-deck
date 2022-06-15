#include <WiFi.h>

#include "widget-status.h"
#include "gui.h"

WidgetStatus::WidgetStatus(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs
) : Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {

}

void WidgetStatus::draw() {
  gui.drawButton(
    x,
    y,
    2,
    1,
    label,
    UNAVAILABLE
  );

  /*  screen->drawString(
      date,
      x + BUTTON_SIZE / 2,
      y + 70,
      2
    );
  */
  int spaceBetweenLines = 15;

  screen->setTextDatum(0);

  String memoryStatus;
  memoryStatus += "Mem. : ";
  memoryStatus += String(ESP.getFreeHeap()/1024);
  memoryStatus += " Mb";
  screen->drawString(
    memoryStatus,
    x + spaceBetweenLines,
    y + spaceBetweenLines,
    1
  );

  String wifiStatus;
  wifiStatus += "WiFi : ";
  wifiStatus += String(WiFi.RSSI());
  wifiStatus += " db";
  screen->drawString(
    wifiStatus,
    x + spaceBetweenLines,
    y + 2 * spaceBetweenLines,
    1
  );

  screen->setTextDatum(4);

  refreshedValued = false;
}

void WidgetStatus::refreshValue() {
  refreshedValued = true;
}

boolean WidgetStatus::isValueChanged() {
  return refreshedValued;
}

void WidgetStatus::manageTouch() {
  //Serial.println("WidgetWeatherForecast::manageTouch()");
}

void WidgetStatus::manageTouchDown() {
  //Serial.println("WidgetWeatherForecast::manageTouchDown()");
}

void WidgetStatus::manageTouchUp() {
  //Serial.println("WidgetWeatherForecast::manageTouchUp()");
}
