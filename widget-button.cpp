#include "widget-button.h"
#include "gui.h"
#include "colors.h"
#include "images.h"
#include "widget-button-callback.h"

WidgetButton::WidgetButton(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs,
  WidgetButtonCallback callback,
  unsigned int virtualId
) : Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {
  this->virtualId = virtualId;
  this->callback = callback;
  buttonStatus = DESACTIVATED;
}

void WidgetButton::draw() {
  gui.drawButton(
    x,
    y,
    label,
    buttonStatus
  );
  screen->drawBitmap(
    x + 16,
    y + 10,
    bulb,
    32,
    32,
    WHITE
  );
}

void WidgetButton::refreshValue() {}

boolean WidgetButton::isValueChanged() {
  return false;
}

void WidgetButton::manageTouch() {
  Serial.println("WidgetButton::manageTouch()");
}

void WidgetButton::manageTouchDown() {
  (*callback) (virtualId);
  buttonStatus = ACTIVATED;
  draw();
  Serial.println("WidgetButton::manageTouchDown()");
}

void WidgetButton::manageTouchUp() {
  buttonStatus = DESACTIVATED;
  draw();
  Serial.println("WidgetButton::manageTouchUp()");
}
