#include "widget-clock.h"
#include "gui.h"

WidgetClock::WidgetClock(
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
  //this->jeedomDate = (678);
  //this->jeedomTime = (679);
}

void WidgetClock::draw() {
  gui.drawButton(
    x,
    y,
    1,
    1,
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

void WidgetClock::refreshValue() {
  date = Clock::date;
  time = Clock::time;
}

boolean WidgetClock::isValueChanged() {
  return previousDate != date || previousTime != time;
}

void WidgetClock::manageTouch() {}

void WidgetClock::manageTouchDown() {}

void WidgetClock::manageTouchUp() {}
