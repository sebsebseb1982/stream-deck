void drawDateTimeButton(unsigned int x, unsigned int y) {
  drawButton(
    x,
    y,
    UNAVAILABLE
  );
  int lineHeight = 6;
  drawCenteredText(
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 - lineHeight,
    getJeedomVirtualValue(678)
  );
  drawCenteredText(
    x + BUTTON_SIZE / 2,
    y + BUTTON_SIZE / 2 + lineHeight,
    getJeedomVirtualValue(679)
  );
}

void drawImageButton(unsigned int x, unsigned int y, String text) {
  drawToggleButton(
    x,
    y,
    getJeedomVirtualValue(683) == "1" ? ACTIVATED : DESACTIVATED
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

void drawTemperatureButton(unsigned int x, unsigned int y, String text, int virtualId) {
  drawButton(
    x,
    y,
    UNAVAILABLE
  );
  display.setTextSize(2);
  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 25,
    getJeedomVirtualValue(virtualId)
  );
  display.setTextSize(1);
  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 51,
    text
  );
}

void drawWindowsButton(unsigned int x, unsigned int y) {
  drawButton(
    x,
    y,
    UNAVAILABLE
  );
  if (getJeedomVirtualValue(565) == "1") {
    display.drawBitmap(
      x + 16,
      y + 10,
      windowOpened,
      32,
      32,
      LIGHT_BLUE
    );
  } else {
    display.drawBitmap(
      x + 16,
      y + 10,
      windowClosed,
      32,
      32,
      RED
    );
  }

  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 51,
    "Aeration"
  );
}
