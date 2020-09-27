double roll_pid_i, roll_last_error;
double roll_control_signal;

void resetPidVariables() {
  roll_pid_i = 0;
  roll_last_error = 0;
}

struct MotorPowers calculateMotorPowers(struct ReceiverCommands receiverCommands, struct IMU_Values imu_values) {
  double rollError = receiverCommands.RollAngle - imu_values.CurrentOrientation.RollAngle;

  roll_control_signal = getControlSignal(rollError, KP_roll, KI_roll, KD_roll, roll_pid_i, roll_last_error, imu_values.DeltaTime);
  
  struct MotorPowers motorPowers;
  motorPowers.LeftMotorPower = receiverCommands.Throttle + roll_control_signal;
  motorPowers.RightMotorPower =receiverCommands.Throttle - roll_control_signal;
  return motorPowers;
}
