#include <Arduino.h>
#include <TFT_eSPI.h>

#include "jeedom.h"
#include "widget.h"

class WidgetDatetime : public Widget {
  private:
    String date;
    String time;
    String previousDate;
    String previousTime;
    Jeedom jeedomDate;
    Jeedom jeedomTime;
  public:
    WidgetDatetime(
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
