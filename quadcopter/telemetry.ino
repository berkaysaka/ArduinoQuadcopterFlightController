unsigned long _lastTime = millis();

void initializeTelemetry(){
  if (REMOTE_PID_CONFIG_ENABLED == false) 
    return;

  if (Serial2) //if Serial2 already ready, do nothing
    return;
   
  Serial2.begin(9600);
  while(!Serial2){} // wait for Serial2 port to be ready
}

void sendTelemetryData(struct ReceiverCommands receiverCommands, struct Orientation orientation) {
  if (TELEMETRY_ENABLED == false)
    return;
    
  unsigned long _currentTime = millis();
  if (_currentTime - _lastTime < 100)
    return;
  _lastTime = _currentTime;

  Serial2.println(
    String(_currentTime)
    + "\t" + orientation.PitchAngle
    + "\t" + orientation.RollAngle
    + "\t" + orientation.YawAngle
    + "\t" + receiverCommands.Throttle
    + "\t" + receiverCommands.PitchAngle
    + "\t" + receiverCommands.RollAngle
    + "\t" + receiverCommands.YawAngleChange
    + "\t" + pitch_control_signal
    + "\t" + roll_control_signal
    + "\t" + yaw_control_signal
  );
}
