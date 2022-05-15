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

  display.fillCircle(
    x + BUTTON_SIZE - 1 - LED_MARGIN,
    y + LED_MARGIN,
    3,
    WHITE
  );
}
