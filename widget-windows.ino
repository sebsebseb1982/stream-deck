void drawWindowsWidget(unsigned int column, unsigned int row) {
    unsigned int x = column * BUTTON_SIZE;
  unsigned int y = row * BUTTON_SIZE;
  boolean isWindowOpened = false /*getJeedomVirtualValue(565) == "1"*/;
 /* drawButton(
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
  }*/
}
