void setup() {
  //Serial.begin(115200);
  Serial2.begin(38400);
  initializeMotors();
  initializeReceiver();
  initializeIMU();
}

void loop() {
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

  spinMotors();

  sendTelemetryInfo();
}
