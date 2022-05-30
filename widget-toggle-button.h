#include <Arduino.h>
#include <TFT_eSPI.h>

#include "jeedom.h"
#include "widget.h"

class WidgetToggleButton : public Widget {
  private:
    Jeedom jeedom;
    boolean value;
    boolean previousValue;
    ButtonStatus buttonStatus;
    ButtonStatus previousButtonStatus;
  public:
    WidgetToggleButton(
      unsigned int column,
      unsigned int row,
      String label,
      TFT_eSPI *screen,
      unsigned long refreshPeriodInMs,
      unsigned int virtualId
    );
    void draw();
    void refreshValue();
    boolean isValueChanged();
    void manageTouch();
    void manageTouchUp();
    void manageTouchDown();
};
