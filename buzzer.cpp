#include "buzzer.h"

#define BUZZER_PIN 25

unsigned long Buzzer::stopBeepMillis = 0;

void Buzzer::setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void Buzzer::on() {
  digitalWrite(BUZZER_PIN, HIGH);
}

void Buzzer::off() {
  digitalWrite(BUZZER_PIN, LOW);
}

void Buzzer::beep(unsigned int durationInMs) {
  on();
  Buzzer::stopBeepMillis = millis() + durationInMs;
}

void Buzzer::refresh() {
  if (millis() > stopBeepMillis) {
    off();
  }
}
