void setup() {
  initializeMotors();
  initializeReceiver();
  initializeIMU();

  Serial.begin(115200);
}

void loop() {
  readReceiverValues();
  //printRawReceiverValues();

  calculateDesiredValues();
  //printDesiredValues();

  readIMUvalues();
  //printGyroValues();
  printGraphGyroValues();

  calculateMotorPowers();
  //printMotorPowers();
  //printMotorPowersGraph();

  spinMotors();
}
