#define LED_MARGIN 10

void drawButton(unsigned int x, unsigned int y) {
  display.drawRoundRect(
    x,
    y,
    BUTTON_SIZE,
    BUTTON_SIZE,
    LED_MARGIN,
    WHITE
  );
}

void drawToggleButton(unsigned int x, unsigned int y, boolean status) {
  drawButton(x, y);

  if (status) {
    display.fillCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      WHITE
    );
  } else {
    display.drawCircle(
      x + BUTTON_SIZE - 1 - LED_MARGIN,
      y + LED_MARGIN,
      3,
      WHITE
    );
  }

}
