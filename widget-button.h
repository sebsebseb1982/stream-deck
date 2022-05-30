#include <Arduino.h>
#include <TFT_eSPI.h>

#include "jeedom.h"
#include "widget.h"
#include "widget-button-callback.h"

class WidgetButton : public Widget {
  private:
    unsigned int virtualId;
    ButtonStatus buttonStatus;
    WidgetButtonCallback callback;
  public:
    WidgetButton(
      unsigned int column,
      unsigned int row,
      String label,
      TFT_eSPI *screen,
      unsigned long refreshPeriodInMs,
      WidgetButtonCallback callback,
      unsigned int virtualId
    );
    void draw();
    void refreshValue();
    boolean isValueChanged();
    void manageTouch();
    void manageTouchUp();
    void manageTouchDown();
};
