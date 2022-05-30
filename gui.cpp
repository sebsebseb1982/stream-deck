#include "gui.h"
#include "colors.h"

GUI::GUI() {}

GUI::GUI(TFT_eSPI *screen) {
  this->screen = screen;
}

void GUI::drawButton(
  unsigned int x,
  unsigned int y,
  String label,
  ButtonStatus buttonStatus
) {
  if (buttonStatus == ACTIVATED) {
    screen->fillRoundRect(
      x + BUTTON_MARGIN,
      y + BUTTON_MARGIN,
      BUTTON_SIZE - (2 * BUTTON_MARGIN),
      BUTTON_SIZE - (2 * BUTTON_MARGIN),
      LED_MARGIN,
      BLACK
    );
    unsigned int delta = 3;
    screen->fillRoundRect(
      x + delta,
      y + delta,
      BUTTON_SIZE - delta,
      BUTTON_SIZE - delta,
      LED_MARGIN,
      DARK_GRAY
    );
  } else {
    screen->fillRoundRect(
      x + BUTTON_MARGIN,
      y + BUTTON_MARGIN,
      BUTTON_SIZE - (2 * BUTTON_MARGIN),
      BUTTON_SIZE - (2 * BUTTON_MARGIN),
      LED_MARGIN,
      BACKGROUND_COLOR
    );
  }

  uint16_t buttonBorderColor;
  if (buttonStatus == UNAVAILABLE) {
    buttonBorderColor = DARK_GRAY;
  } else {
    buttonBorderColor = WHITE;
  }

  screen->drawRoundRect(
    x + BUTTON_MARGIN,
    y + BUTTON_MARGIN,
    BUTTON_SIZE - (2 * BUTTON_MARGIN),
    BUTTON_SIZE - (2 * BUTTON_MARGIN),
    LED_MARGIN,
    buttonBorderColor
  );

  screen->drawString(
    label,
    x + (BUTTON_SIZE / 2) + BUTTON_MARGIN,
    y + 63,
    1
  );
}

void GUI::drawToggleButton(
  unsigned int x,
  unsigned int y,
  String label,
  ButtonStatus buttonStatus
) {
  drawButton(
    x,
    y,
    label,
    buttonStatus
  );
  int delta = 2;
  if (buttonStatus == ACTIVATED) {
    screen->fillCircle(
      x + BUTTON_SIZE - BUTTON_MARGIN - LED_MARGIN - delta,
      y + BUTTON_MARGIN + LED_MARGIN + delta,
      LED_SIZE,
      LED_GREEN_COLOR
    );
  } else {
    screen->fillCircle(
      x + BUTTON_SIZE - BUTTON_MARGIN - LED_MARGIN - delta,
      y + BUTTON_MARGIN + LED_MARGIN + delta,
      LED_SIZE,
      LIGHT_GRAY
    );
  }
}