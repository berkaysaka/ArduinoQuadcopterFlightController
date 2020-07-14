unsigned long _lastTime = millis();

void sendTelemetryInfo() {
  unsigned long _currentTime = millis();
  if (_currentTime - _lastTime < 100)
    return;
  _lastTime = _currentTime;

  Serial2.println(
    String(_currentTime)
    + "\t" + pitchAngle
    + "\t" + rollAngle
    + "\t" + yawAngle
    + "\t" + throttle
    + "\t" + desired_pitch_angle
    + "\t" + desired_roll_angle
    + "\t" + desired_yaw_angle_change
    + "\t" + pitch_control_signal
    + "\t" + roll_control_signal
    + "\t" + yaw_control_signal
  );
}
