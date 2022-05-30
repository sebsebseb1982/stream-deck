#include <Arduino.h>
#include <TFT_eSPI.h>

#include "jeedom.h"
#include "widget.h"

class WidgetTemperature : public Widget {
  private:
    String temperature;
    String previousTemperature;
    Jeedom jeedom;
  public:
    WidgetTemperature(
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
