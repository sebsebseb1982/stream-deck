int pwmChannel = 0; //Choisit le canal 0
int frequence = 1000; //Fréquence PWM de 1 KHz
int resolution = 8; // Résolution de 8 bits, 256 valeurs possibles
int pwmPin = 26;

void setupScreen() {
  screen.init();

  screen.fillScreen(BACKGROUND_COLOR);
  screen.setRotation(1);
  screen.setTextColor(WHITE, BACKGROUND_COLOR);
  ledcSetup(pwmChannel, frequence, resolution);
  ledcAttachPin(pwmPin, pwmChannel);
  ledcWrite(pwmChannel, 255);
}

void loopScreen() {

  ledcWrite(
    pwmChannel,
    getJeedomVirtualValue(687).toInt()
  );

}
