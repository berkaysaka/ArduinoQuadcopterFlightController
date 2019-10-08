unsigned long last_time;
float current_time, delta_time;
double roll_pid_i, roll_last_error, pitch_pid_i, pitch_last_error, yaw_pid_i, yaw_last_error;

void calculateMotorPowers() {
  if (millis() - last_time < PID_SAMPLING_FREQUENCY)
    return;

  updateCurrentTimeVariables();
  double roll_control_signal = getControlSignal(desired_roll_angle - rollAngle, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, roll_pid_i, roll_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  double pitch_control_signal = getControlSignal(desired_pitch_angle - pitchAngle, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, pitch_pid_i, pitch_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  double yaw_control_signal = getControlSignal(calculateErrorForYaw(desired_yaw_angle, yawAngle), KP_yaw, KI_yaw, KD_yaw, yaw_pid_i, yaw_last_error, YAW_INTEGRAL_LIMIT);

  frontLeftMotorPower = throttle + roll_control_signal + pitch_control_signal - yaw_control_signal;
  frontRightMotorPower = throttle - roll_control_signal + pitch_control_signal + yaw_control_signal;
  rearLeftMotorPower = throttle + roll_control_signal - pitch_control_signal + yaw_control_signal;
  rearRightMotorPower = throttle - roll_control_signal - pitch_control_signal - yaw_control_signal;

  if (throttle == MIN_THROTTLE) {
    frontLeftMotorPower = MIN_THROTTLE;
    frontRightMotorPower = MIN_THROTTLE;
    rearLeftMotorPower = MIN_THROTTLE;
    rearRightMotorPower = MIN_THROTTLE;
  }
  updateLastTimeVariables();
}

double calculateErrorForYaw(double desired, double actual) {
  double error = desired - actual;
  if (error > 180)
    error -= 360;
  else if (error < -180)
    error += 360;
  return error;
}

void updateCurrentTimeVariables() {
  current_time = millis();
  delta_time = (current_time - last_time) / 1000;
}

void updateLastTimeVariables() {
  last_time = current_time;
}
