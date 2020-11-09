#include <neotimer.h>

Neotimer mytimer = Neotimer(1000); // 1 second timer

void initializeOutputSignals() {
  mytimer.start();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  tone(BUZZER_PIN, 2000);
}

void syncOutputSignals() {
  if (mytimer.done()) {
    digitalWrite(LED_PIN, HIGH);
    noTone(BUZZER_PIN);
    mytimer.reset();
  }
}
