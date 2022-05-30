#include "screen.h"
#include "colors.h"


#define pwmChannel 0 //Choisit le canal 0
#define frequence 1000 //Fréquence PWM de 1 KHz
#define resolution 8 // Résolution de 8 bits, 256 valeurs possibles
#define pwmPin 26

Screen::Screen(TFT_eSPI *screen) {
  this->screen = screen;
}

void Screen::init() {
  screen->init();
  screen->fillScreen(BACKGROUND_COLOR);
  screen->setRotation(1);
  screen->setTextColor(WHITE, BACKGROUND_COLOR);
  screen->setTextDatum(4);
  ledcSetup(pwmChannel, frequence, resolution);
  ledcAttachPin(pwmPin, pwmChannel);
  ledcWrite(pwmChannel, 255);
}

void Screen::loop() {
  ledcWrite(
    pwmChannel,
    255 /*getJeedomVirtualValue(687).toInt()*/
  );
}
