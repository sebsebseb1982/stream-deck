#ifndef WIDGET_DOORBELL_H
#define WIDGET_DOORBELL_H

#include <Arduino.h>
#include "jeedom.h"
#include "widget.h"

class WidgetDoorBell : public Widget {
  private:
    boolean value;
    boolean previousValue;
    int iconAnimationXDelta;
    Jeedom jeedomDoorBell;
    Jeedom jeedomTime;
  public:
    WidgetDoorBell(
      unsigned int column,
      unsigned int row,
      String label,
      TFT_eSPI *screen,
      unsigned long refreshPeriodInMs
    );
    void draw();
    void refreshValue();
    boolean isValueChanged();
    void manageTouch();
    void manageTouchUp();
    void manageTouchDown();
};

#endif
