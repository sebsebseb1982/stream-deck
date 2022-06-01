#include "screen.h"
#include "colors.h"
#include "touch-screen.h"
#include "buzzer.h"
#include "duration.h"

#define pwmChannel 0 //Choisit le canal 0
#define frequence 1000 //Fréquence PWM de 1 KHz
#define resolution 8 // Résolution de 8 bits, 256 valeurs possibles
#define pwmPin 26

#define SCREEN_STANDBY_DELAY_MS FIVE_MINUTES

Screen::Screen(TFT_eSPI *screen) {
  this->screen = screen;
  this->lastTouchedMillis = millis();
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
  if (TouchScreen::isTouched) {
    Buzzer::beep(50);
    lastTouchedMillis = millis();
  }

  if (millis() - lastTouchedMillis > SCREEN_STANDBY_DELAY_MS) {
    long backlightValue = 255-(millis() - lastTouchedMillis - SCREEN_STANDBY_DELAY_MS)/10;
    long minimumBacklightValue = 10;
    ledcWrite(
      pwmChannel,
      max(minimumBacklightValue, backlightValue)
    );
  } else {
    ledcWrite(
      pwmChannel,
      255
    );
  }


}
