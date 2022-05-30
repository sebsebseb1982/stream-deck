#include "widget-temperature.h"
#include "gui.h"

WidgetTemperature::WidgetTemperature(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs,
  unsigned int virtualId
): Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {
  this->jeedom = (virtualId);
}

void WidgetTemperature::draw() {
  gui.drawButton(
    x,
    y,
    label,
    UNAVAILABLE
  );

  screen->drawString(
    temperature,
    x + (BUTTON_SIZE / 2),
    y + 35,
    2
  );
  previousTemperature = temperature;
  Serial.println("WidgetTemperature::draw() " + label);
}

void WidgetTemperature::refreshValue() {
  temperature = jeedom.getValue();
}

boolean WidgetTemperature::isValueChanged() {
  return previousTemperature != temperature;
}

void WidgetTemperature::manageTouch() {
  Serial.println("WidgetTemperature::manageTouch()");
}

void WidgetTemperature::manageTouchDown() {
  Serial.println("WidgetTemperature::manageTouchDown()");
}

void WidgetTemperature::manageTouchUp() {
  Serial.println("WidgetTemperature::manageTouchUp()");
}
