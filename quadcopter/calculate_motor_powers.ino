unsigned long last_time = millis(); 
unsigned long current_time = millis();

struct MotorPowers calculateMotorPowers(struct ReceiverCommands receiverCommands, struct Orientation previousOrientation, struct Orientation actualOrientation) { 
  updateCurrentTimeVariables();

  // calculate orientation errors (error: difference between desired orientation and actual orientation)
  double rollError = receiverCommands.RollAngle - actualOrientation.RollAngle;
  double pitchError = receiverCommands.PitchAngle - actualOrientation.PitchAngle;
  double yawError = receiverCommands.YawAngleChange - (actualOrientation.YawAngle - previousOrientation.YawAngle);
    
  // calculate control gains based on errors
  roll_control_signal = getControlSignal(rollError, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, roll_pid_i, roll_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  pitch_control_signal = getControlSignal(pitchError, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, pitch_pid_i, pitch_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  yaw_control_signal = getControlSignal(yawError, KP_yaw, KI_yaw, KD_yaw, yaw_pid_i, yaw_last_error, YAW_INTEGRAL_LIMIT);

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
  motorPowers = ensureMotorsAlwaysRun(motorPowers);
 
  updateLastTimeVariables();
  
  return motorPowers;
}

struct MotorPowers reduceMotorPowers(MotorPowers motorPowers){ // to preserve balance if MAX_THROTTLE limit exceeds)
  int maxMotorPower = max(max(motorPowers.frontLeftMotorPower, motorPowers.frontRightMotorPower), max(motorPowers.rearLeftMotorPower, motorPowers.rearRightMotorPower));
  if (maxMotorPower > MAX_THROTTLE){
    double power_reduction_rate = (double)maxMotorPower / (double)MAX_THROTTLE;
    motorPowers.frontLeftMotorPower = round((double)motorPowers.frontLeftMotorPower / power_reduction_rate);
    motorPowers.frontRightMotorPower = round((double)motorPowers.frontRightMotorPower / power_reduction_rate);
    motorPowers.rearLeftMotorPower = round((double)motorPowers.rearLeftMotorPower / power_reduction_rate);
    motorPowers.rearRightMotorPower = round((double)motorPowers.rearRightMotorPower / power_reduction_rate);
  }
  return motorPowers;
}

struct MotorPowers ensureMotorsAlwaysRun(MotorPowers motorPowers){ // because it takes much more time to spin a stopped motor
  motorPowers.frontLeftMotorPower = max(motorPowers.frontLeftMotorPower, THROTTLE_START_POINT);
  motorPowers.frontRightMotorPower = max(motorPowers.frontRightMotorPower, THROTTLE_START_POINT);
  motorPowers.rearLeftMotorPower = max(motorPowers.rearLeftMotorPower, THROTTLE_START_POINT);
  motorPowers.rearRightMotorPower = max(motorPowers.rearRightMotorPower, THROTTLE_START_POINT);
  return motorPowers;
}

void updateCurrentTimeVariables() {
  current_time = millis();
  delta_time = (current_time - last_time);
}

void updateLastTimeVariables() {
  last_time = current_time;
}
