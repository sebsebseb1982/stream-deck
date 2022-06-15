#include <Arduino.h>
#include <TFT_eSPI.h>

#include "widget.h"

class WidgetStatus : public Widget {
  private:
    boolean refreshedValued;
  public:
    WidgetStatus(
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
