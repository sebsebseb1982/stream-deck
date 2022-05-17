#define LED_MARGIN 10

void drawButton(
  unsigned int x,
  unsigned int y,
  ButtonStatus buttonStatus
) {

  if (buttonStatus == ACTIVATED) {
    display.fillRoundRect(
      x,
      y,
      BUTTON_SIZE,
      BUTTON_SIZE,
      LED_MARGIN,
      BLACK
    );
    unsigned int delta = 3;
    display.fillRoundRect(
      x + delta,
      y + delta,
      BUTTON_SIZE - delta,
      BUTTON_SIZE - delta,
      LED_MARGIN,
      DARK_GRAY
    );
  } else {
    display.fillRoundRect(
      x,
      y,
      BUTTON_SIZE,
      BUTTON_SIZE,
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

  display.drawRoundRect(
    x,
    y,
    BUTTON_SIZE,
    BUTTON_SIZE,
    LED_MARGIN,
    buttonBorderColor
  );
}

void drawToggleButton(
  unsigned int x,
  unsigned int y,
  ButtonStatus buttonStatus
) {
  drawButton(x, y, buttonStatus);

  if (buttonStatus == ACTIVATED) {
    display.fillCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      LED_GREEN_COLOR
    );
  } else {
    display.fillCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      LIGHT_GRAY
    );
  }

}
