void drawDateTimeButton(unsigned int x, unsigned int y) {
  drawButton(
    x,
    y,
    "",
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

void drawImageButton(unsigned int x, unsigned int y, String label) {
  drawToggleButton(
    x,
    y,
    label,
    getJeedomVirtualValue(683) == "1" ? ACTIVATED : DESACTIVATED
  );
  screen.drawBitmap(
    x + 16,
    y + 10,
    bulb,
    32,
    32,
    WHITE
  );
}

void drawTemperatureButton(unsigned int x, unsigned int y, String label, int virtualId) {
  String temperature = getJeedomVirtualValue(virtualId);
  drawButton(
    x,
    y,
    label,
    UNAVAILABLE
  );
  screen.setTextSize(2);
  drawCenteredText(
    x + (BUTTON_SIZE / 2),
    y + 25,
    temperature
  );
  screen.setTextSize(1);
}

void drawWindowsButton(unsigned int x, unsigned int y) {
  boolean isWindowOpened = getJeedomVirtualValue(565) == "1";
  drawButton(
    x,
    y,
    "Aeration",
    UNAVAILABLE
  );
  if (isWindowOpened) {
    screen.drawBitmap(
      x + (BUTTON_SIZE - ICON_SIZE) / 2,
      y + 10,
      windowOpened,
      ICON_SIZE,
      ICON_SIZE,
      LIGHT_BLUE
    );
  } else {
    screen.drawBitmap(
      x + (BUTTON_SIZE - 32) / 2,
      y + 10,
      windowClosed,
      ICON_SIZE,
      ICON_SIZE,
      RED
    );
  }
}

void drawMeteoWidget(unsigned int x, unsigned int y, WeatherForecast weatherForecast, String label) {
  drawButton(
    x,
    y,
    label,
    UNAVAILABLE
  );

  /*screen.drawBitmap(
    x + 7,
    y + 2,
    clearSky,
    ICON_SIZE,
    ICON_SIZE,
    WHITE
  );*/
}
