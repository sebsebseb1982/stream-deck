#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_WIDTH 480 // OLED display width, in pixels
#define SCREEN_HEIGHT 320 // OLED display height, in pixels

#include <Arduino.h>
#include <TFT_eSPI.h>

class Screen {
  private:
    TFT_eSPI *screen;
  public:
    Screen(TFT_eSPI *screen);
    void init();
    void loop();
};

#endif
