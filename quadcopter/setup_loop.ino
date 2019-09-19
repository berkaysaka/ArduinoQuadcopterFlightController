void setup() {
  //initializeMotors();
  initializeReceiver();
  initializeGyro();

  Serial.begin(115200);
}

void loop() {
  readReceiverValues();
  //printRawReceiverValues();

  calculateDesiredValues();
  //printDesiredValues();

  readGyroValues();
  //printGyroValues();
  printGraphGyroValues();

  calculateMotorPowers();
  //printMotorPowers();
  //printMotorPowersGraph();
  //spinMotors();
}
