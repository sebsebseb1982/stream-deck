void drawDateTimeButton(unsigned int x, unsigned int y) {
  drawButton(
    x,
    y
  );
  int lineHeight = 6;
  drawCenteredText(
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 - lineHeight,
    getFormattedDateDDMM(getDateTime())
  );
  drawCenteredText(
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 + lineHeight,
    getFormattedTime(getDateTime())
  );
}

void drawImageButton(unsigned int x, unsigned int y, String text) {
  drawToggleButton(
    x,
    y,
    getJeedomVirtualValue(533) == "1"
  );
  display.drawBitmap(
    x + 16,
    y + 10,
    bulb,
    32,
    32,
    WHITE
  );
  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 51,
    text
  );
}
