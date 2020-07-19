double roll_pid_i, roll_last_error, pitch_pid_i, pitch_last_error, yaw_pid_i, yaw_last_error;
double roll_control_signal, pitch_control_signal, yaw_control_signal;

void resetPidVariables() {
  roll_pid_i = 0;
  roll_last_error = 0;
  pitch_pid_i = 0;
  pitch_last_error = 0;
  yaw_pid_i = 0;
  yaw_last_error = 0;
}

struct MotorPowers calculateMotorPowers(struct ReceiverCommands receiverCommands, struct IMU_Values imu_values) {
  // calculate orientation errors (error: difference between desired orientation and actual orientation)
  double rollError = receiverCommands.RollAngle - imu_values.CurrentOrientation.RollAngle;
  double pitchError = receiverCommands.PitchAngle - imu_values.CurrentOrientation.PitchAngle;
  double yawError = receiverCommands.YawAngleChange - (imu_values.CurrentOrientation.YawAngle - imu_values.PreviousOrientation.YawAngle);

  // prevent sudden changes on yaw. huge yaw difference causes altitude gain
  yawError = constrain(yawError, -ANGLE_DEGREE_LIMIT_YAW, ANGLE_DEGREE_LIMIT_YAW);

  // calculate control gains based on errors
  roll_control_signal = getControlSignal(rollError, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, roll_pid_i, roll_last_error, ROLL_PITCH_INTEGRAL_LIMIT, imu_values.DeltaTime);
  pitch_control_signal = getControlSignal(pitchError, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, pitch_pid_i, pitch_last_error, ROLL_PITCH_INTEGRAL_LIMIT, imu_values.DeltaTime);
  yaw_control_signal = getControlSignal(yawError, KP_yaw, KI_yaw, KD_yaw, yaw_pid_i, yaw_last_error, YAW_INTEGRAL_LIMIT, imu_values.DeltaTime);

  // limit control gains
  roll_control_signal = constrain(roll_control_signal, -MAX_ROLL_PITCH_CONTROL_GAIN, MAX_ROLL_PITCH_CONTROL_GAIN);
  pitch_control_signal = constrain(pitch_control_signal, -MAX_ROLL_PITCH_CONTROL_GAIN, MAX_ROLL_PITCH_CONTROL_GAIN);
  yaw_control_signal = constrain(yaw_control_signal, -MAX_YAW_CONTROL_GAIN, MAX_YAW_CONTROL_GAIN);

  // calculate power for each motor
  struct MotorPowers motorPowers;
  motorPowers.frontLeftMotorPower = round(receiverCommands.Throttle + roll_control_signal + pitch_control_signal - yaw_control_signal);
  motorPowers.frontRightMotorPower = round(receiverCommands.Throttle - roll_control_signal + pitch_control_signal + yaw_control_signal);
  motorPowers.rearLeftMotorPower = round(receiverCommands.Throttle + roll_control_signal - pitch_control_signal + yaw_control_signal);
  motorPowers.rearRightMotorPower = round(receiverCommands.Throttle - roll_control_signal - pitch_control_signal - yaw_control_signal);

  motorPowers = reduceMotorPowers(motorPowers);
  motorPowers = keepMotorsAlwaysRunning(motorPowers);

  return motorPowers;
}

struct MotorPowers reduceMotorPowers(MotorPowers motorPowers) { // to preserve balance if MAX_THROTTLE limit exceeds)
  int maxMotorPower = max(max(motorPowers.frontLeftMotorPower, motorPowers.frontRightMotorPower), max(motorPowers.rearLeftMotorPower, motorPowers.rearRightMotorPower));
  if (maxMotorPower > 180) {
    double power_reduction_rate = (double)maxMotorPower / (double)180;
    motorPowers.frontLeftMotorPower = round((double)motorPowers.frontLeftMotorPower / power_reduction_rate);
    motorPowers.frontRightMotorPower = round((double)motorPowers.frontRightMotorPower / power_reduction_rate);
    motorPowers.rearLeftMotorPower = round((double)motorPowers.rearLeftMotorPower / power_reduction_rate);
    motorPowers.rearRightMotorPower = round((double)motorPowers.rearRightMotorPower / power_reduction_rate);
  }
  return motorPowers;
}

struct MotorPowers keepMotorsAlwaysRunning(MotorPowers motorPowers){ // because it takes much more time to spin a stopped motor
  motorPowers.frontLeftMotorPower = max(motorPowers.frontLeftMotorPower, THROTTLE_START_POINT);
  motorPowers.frontRightMotorPower = max(motorPowers.frontRightMotorPower, THROTTLE_START_POINT);
  motorPowers.rearLeftMotorPower = max(motorPowers.rearLeftMotorPower, THROTTLE_START_POINT);
  motorPowers.rearRightMotorPower = max(motorPowers.rearRightMotorPower, THROTTLE_START_POINT);
  return motorPowers;
}
