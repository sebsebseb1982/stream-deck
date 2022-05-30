#include "widget.h"
#include "screen.h"

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
  if(previousTouchStatus != touchStatus && touchStatus) {
    manageTouchDown();
  }
  if(touchStatus) {
    manageTouch();
  }
  if(previousTouchStatus != touchStatus && !touchStatus) {
    manageTouchUp();
  }
  previousTouchStatus = touchStatus;
}

boolean Widget::isTouched() {
  uint16_t xTouch, yTouch;
  boolean isTouched = screen->getTouch(&xTouch, &yTouch);
  xTouch = SCREEN_WIDTH - xTouch;
  yTouch = SCREEN_HEIGHT - yTouch;
  return isTouched
         && xTouch >= x
         && xTouch < x + BUTTON_SIZE
         && yTouch >= y
         && yTouch < y + BUTTON_SIZE;
}
