void setup() {
  initializeMotor();
  initializeReceiver();
  Serial.begin(115200);
}

void loop() {
  struct ReceiverCommands cmd = GetReceiverCommands();
  if(cmd.Error){
    spinMotor(0);
    return;
  }

  spinMotor(cmd.Throttle);
}
