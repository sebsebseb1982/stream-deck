#include "widget-windows.h"
#include "gui.h"
#include "colors.h"
#include "images.h"

WidgetWindows::WidgetWindows(
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
  this->jeedom = (565);
}

void WidgetWindows::draw() {
  gui.drawButton(
    x,
    y,
    "Aeration",
    UNAVAILABLE
  );
  if (value) {
    screen->drawBitmap(
      x + (BUTTON_SIZE - ICON_SIZE) / 2,
      y + 10,
      windowOpened,
      ICON_SIZE,
      ICON_SIZE,
      LIGHT_BLUE
    );
  } else {
    screen->drawBitmap(
      x + (BUTTON_SIZE - ICON_SIZE) / 2,
      y + 10,
      windowClosed,
      ICON_SIZE,
      ICON_SIZE,
      RED
    );
  }
  previousValue = value;
}

void WidgetWindows::refreshValue() {
  value = jeedom.getValue() == "1";
}

boolean WidgetWindows::isValueChanged() {
  return value != previousValue;
}

void WidgetWindows::manageTouch() {
  //Serial.println("WidgetWindows::manageTouch()");
}

void WidgetWindows::manageTouchDown() {
  //Serial.println("WidgetWindows::manageTouchDown()");
}

void WidgetWindows::manageTouchUp() {
  //Serial.println("WidgetWindows::manageTouchUp()");
}
