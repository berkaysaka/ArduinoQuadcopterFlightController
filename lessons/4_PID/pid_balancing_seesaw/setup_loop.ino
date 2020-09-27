void setup() {
  initializeMotor();
  initializeReceiver();
  initializeIMU();
  Serial.begin(115200);
}

void loop() {
  struct ReceiverCommands receiverCommands = GetReceiverCommands();
  struct IMU_Values imuValues = getIMUOrientation();
  if(receiverCommands.Error || imuValues.Error || receiverCommands.Throttle < 20){
    stopMotors();
    return;
  }

  if(imuValues.NewDataAvailable == false){
    return;
  }

  struct MotorPowers motorPowers = calculateMotorPowers(receiverCommands, imuValues);
  spinMotors(motorPowers);
}
