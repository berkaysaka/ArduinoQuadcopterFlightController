void setup() {
  if(TEST_MODE == true){
    Serial.begin(115200);
    run_tests();
    return;
  }
  //Serial.begin(115200);
  Serial2.begin(38400);
  initializeOutputSignals();
  initializeMotors();
  initializeReceiver();
  initializeIMU();
}

void loop() {
  if(TEST_MODE == true){
    return;    
  }
  
  //syncOutputSignals();
  
  readReceiverValues();
  //printRawReceiverValues();

  calculateDesiredValuesWithSafetyChecks();
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
