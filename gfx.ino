void drawCenteredText(unsigned int x, unsigned int y, String text) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(
    text,
    0,
    0,
    &x1,
    &y1,
    &w,
    &h
  );
  display.setCursor(
    x - w / 2,
    y - h / 2
  );
  display.print(text);
}
