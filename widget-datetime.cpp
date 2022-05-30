#include "widget-datetime.h"
#include "gui.h"

WidgetDatetime::WidgetDatetime(
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
  this->jeedomDate = (678);
  this->jeedomTime = (679);
}

void WidgetDatetime::draw() {
  gui.drawButton(
    x,
    y,
    "",
    UNAVAILABLE
  );
  int lineHeight = 9;
  screen->drawString(
    date,
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 - lineHeight,
    2
  );
  screen->drawString(
    time,
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 + lineHeight,
    2
  );
  previousDate = date;
  previousTime = time;
}

void WidgetDatetime::refreshValue() {
  date = jeedomDate.getValue();
  time = jeedomTime.getValue();
}

boolean WidgetDatetime::isValueChanged() {
  return previousDate != date || previousTime != time;
}

void WidgetDatetime::manageTouch() {}

void WidgetDatetime::manageTouchDown() {}

void WidgetDatetime::manageTouchUp() {}
