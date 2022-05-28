#define LED_MARGIN 10

void drawButton(
  unsigned int x,
  unsigned int y,
  String label,
  ButtonStatus buttonStatus
) {
  if (buttonStatus == ACTIVATED) {
    screen.fillRoundRect(
      x,
      y,
      BUTTON_SIZE,
      BUTTON_SIZE,
      LED_MARGIN,
      BLACK
    );
    unsigned int delta = 3;
    screen.fillRoundRect(
      x + delta,
      y + delta,
      BUTTON_SIZE - delta,
      BUTTON_SIZE - delta,
      LED_MARGIN,
      DARK_GRAY
    );
  } else {
    screen.fillRoundRect(
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

  screen.drawRoundRect(
    x,
    y,
    BUTTON_SIZE,
    BUTTON_SIZE,
    LED_MARGIN,
    buttonBorderColor
  );

  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 51,
    label
  );
}

void drawToggleButton(
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

  if (buttonStatus == ACTIVATED) {
    screen.fillCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      LED_GREEN_COLOR
    );
  } else {
    screen.fillCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      LIGHT_GRAY
    );
  }

}
