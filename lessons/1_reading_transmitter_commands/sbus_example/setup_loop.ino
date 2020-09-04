void setup() {
  initializeReceiver();
  Serial.begin(115200);
}

void loop() {
  struct ReceiverCommands cmd = GetReceiverCommands();

  Serial.print(cmd.Error);
  Serial.print(",");
  Serial.print(cmd.Roll);
  Serial.print(",");
  Serial.print(cmd.Pitch);
  Serial.print(",");
  Serial.print(cmd.Throttle);
  Serial.print(",");
  Serial.print(cmd.Yaw);
  Serial.println();

}
