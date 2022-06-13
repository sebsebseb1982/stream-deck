#include <Arduino.h>
#include <TFT_eSPI.h>

#include "clock.h"
#include "widget.h"

class WidgetClock : public Widget {
  private:
    String date;
    String time;
    String previousDate;
    String previousTime;
  public:
    WidgetClock(
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
