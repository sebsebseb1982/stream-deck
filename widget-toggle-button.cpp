#include "widget-toggle-button.h"
#include "gui.h"
#include "colors.h"
#include "images.h"

WidgetToggleButton::WidgetToggleButton(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs,
  unsigned int virtualId,
  const unsigned char *icon
) : Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {
  this->jeedom = (virtualId);
  this->icon = icon;
}

void WidgetToggleButton::draw() {
  gui.drawToggleButton(
    x,
    y,
    label,
    buttonStatus
  );
  screen->drawBitmap(
    x + (BUTTON_SIZE - ICON_SIZE) / 2,
    y + ((BUTTON_SIZE - ICON_SIZE) / 2) - 8,
    icon,
    32,
    32,
    WHITE
  );
  previousValue = value;
}

void WidgetToggleButton::refreshValue() {
  value = jeedom.getValue() == "1";
  if (!isTouched()) {
    buttonStatus = value ? ACTIVATED : DESACTIVATED;
  }
}

boolean WidgetToggleButton::isValueChanged() {
  return value != previousValue;
}

void WidgetToggleButton::manageTouch() {
  //Serial.println("WidgetToggleButton::manageTouch()");
}

void WidgetToggleButton::manageTouchDown() {
  //Serial.println("WidgetToggleButton::manageTouchDown()");
}

void WidgetToggleButton::manageTouchUp() {
  jeedom.updateValue(value ? "0" : "1");
  value = !value;
  buttonStatus = value ? ACTIVATED : DESACTIVATED;
  draw();

  //Serial.println("WidgetToggleButton::manageTouchUp()");
}
