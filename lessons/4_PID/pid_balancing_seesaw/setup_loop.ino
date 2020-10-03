void setup() {
  initializeMotor();
  initializeReceiver();
  initializeIMU();
  Serial.begin(115200);
}

void loop() {
  struct ReceiverCommands receiverCommands = GetReceiverCommands();
  struct IMU_Values imuValues = GetIMU_Values();
  if(receiverCommands.Error || imuValues.Error || receiverCommands.Throttle < 20){
    stopMotors();
    resetPidVariables();
    return;
  }

  if(imuValues.NewDataAvailable == false){
    return;
  }

  struct MotorPowers motorPowers = calculateMotorPowers(receiverCommands, imuValues);
  spinMotors(motorPowers);
}
