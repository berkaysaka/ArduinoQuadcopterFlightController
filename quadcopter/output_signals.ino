void initializeOutputSignals(){
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);
}

void syncOutputSignals(){
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN,1000);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
  delay(500);
}
