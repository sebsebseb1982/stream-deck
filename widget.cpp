#include "widget.h"
#include "screen.h"
#include "touch-screen.h"

Widget::Widget(
  unsigned int column,
  unsigned int row,
  String label,
  TFT_eSPI *screen,
  unsigned long refreshPeriodInMs
) {
  this->x = column * BUTTON_SIZE;
  this->y = row * BUTTON_SIZE;
  this->label = label;
  this->screen = screen;
  this->refreshPeriodInMs = refreshPeriodInMs;
  this->gui = (screen);
  this->startMillis = millis();
}

void Widget::init() {
  refreshValue();
  draw();
}

void Widget::refresh() {
  currentMillis = millis();
  if (currentMillis - startMillis >= refreshPeriodInMs) {
    refreshValue();
    startMillis = currentMillis;
  }

  if (isValueChanged()) {
    draw();
  }

  touchStatus = isTouched();
  if (previousTouchStatus != touchStatus && touchStatus) {
    manageTouchDown();
  }
  /*if (touchStatus) {
    manageTouch();
  }*/
  if (previousTouchStatus != touchStatus && !touchStatus) {
    manageTouchUp();
  }
  previousTouchStatus = touchStatus;
  Serial.println("Widget::refresh() " + label + "(time=" + String(millis() - currentMillis) + "ms )");
}

boolean Widget::isTouched() {
  return TouchScreen::isTouched
         && TouchScreen::x >= x
         && TouchScreen::x < x + BUTTON_SIZE
         && TouchScreen::y >= y
         && TouchScreen::y < y + BUTTON_SIZE;
}
