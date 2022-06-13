#include "widget-doorbell.h"
#include "gui.h"
#include "colors.h"
#include "images.h"
#include "buzzer.h"
#include "clock.h"

WidgetDoorBell::WidgetDoorBell(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs
): Widget(
    column,
    row,
    label,
    screen,
    refreshPeriodInMs
  ) {
  this->jeedom = (310);
  this->iconAnimationXDelta = 2;
}

void WidgetDoorBell::draw() {
  gui.drawButton(
    x,
    y,
    label,
    UNAVAILABLE
  );
  if (value) {
    iconAnimationXDelta = -iconAnimationXDelta;
    screen->drawBitmap(
      x + iconAnimationXDelta + (BUTTON_SIZE - ICON_SIZE) / 2,
      y + 10,
      windowOpened,
      ICON_SIZE,
      ICON_SIZE,
      RED
    );
  } else {
    screen->drawBitmap(
      x + (BUTTON_SIZE - ICON_SIZE) / 2,
      y + 10,
      windowOpened,
      ICON_SIZE,
      ICON_SIZE,
      WHITE
    );
  }
  previousValue = value;
}

void WidgetDoorBell::refreshValue() {
  value = jeedom.getValue() == "1";
}

boolean WidgetDoorBell::isValueChanged() {
  if (value) {
    Buzzer::beep(5*1000);
    label = Clock::time;
    draw();
  }
  return previousValue != value;
}

void WidgetDoorBell::manageTouch() {}

void WidgetDoorBell::manageTouchDown() {}

void WidgetDoorBell::manageTouchUp() {}
