void setup() {
  //Serial.begin(115200);
  //Serial2.begin(38400);
  initializeOutputSignals();
  initializeMotors();
  initializeReceiver();
  initializeIMU();
}

void loop() {
  //syncOutputSignals();
  
  readReceiverValues();
  //printRawReceiverValues();

  calculateDesiredValues();
  //printDesiredValues();

  readIMUvalues();
  //printGyroValues();
  //printGraphGyroValues();

  calculateMotorPowers();
  //printMotorPowers();
  //printMotorPowersGraph();

  updateMotorsWithStaticThrottle();
  //spinMotors();

  //sendTelemetryInfo();
}
