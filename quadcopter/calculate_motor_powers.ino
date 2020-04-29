unsigned long last_time = millis(); 
unsigned long current_time = millis();
int delta_time;
double roll_pid_i, roll_last_error, pitch_pid_i, pitch_last_error, yaw_pid_i, yaw_last_error;
bool fresh_imu_data_available = false;

void calculateMotorPowers() {
  if (imu_failure == true){
    last_time = millis();
    return;
  }
  
  if (fresh_imu_data_available == false)
    return;
  
  fresh_imu_data_available = false;
  
  updateCurrentTimeVariables();

  roll_control_signal = getControlSignal(desired_roll_angle - rollAngle, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, roll_pid_i, roll_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  pitch_control_signal = getControlSignal(desired_pitch_angle - pitchAngle, KP_roll_pitch, KI_roll_pitch, KD_roll_pitch, pitch_pid_i, pitch_last_error, ROLL_PITCH_INTEGRAL_LIMIT);
  
  yaw_control_signal = getControlSignal(calculateErrorForYaw(desired_yaw_angle, yawAngle), KP_yaw, KI_yaw, KD_yaw, yaw_pid_i, yaw_last_error, YAW_INTEGRAL_LIMIT);

  // limit control gains
  roll_control_signal = constrain(roll_control_signal, -MAX_ROLL_PITCH_CONTROL_GAIN, MAX_ROLL_PITCH_CONTROL_GAIN);
  pitch_control_signal = constrain(pitch_control_signal, -MAX_ROLL_PITCH_CONTROL_GAIN, MAX_ROLL_PITCH_CONTROL_GAIN);
  yaw_control_signal = constrain(yaw_control_signal, -MAX_YAW_CONTROL_GAIN, MAX_YAW_CONTROL_GAIN);
  
  frontLeftMotorPower = round(throttle + roll_control_signal + pitch_control_signal - yaw_control_signal);
  frontRightMotorPower = round(throttle - roll_control_signal + pitch_control_signal + yaw_control_signal);
  rearLeftMotorPower = round(throttle + roll_control_signal - pitch_control_signal + yaw_control_signal);
  rearRightMotorPower = round(throttle - roll_control_signal - pitch_control_signal - yaw_control_signal);

  reduceMotorPowers();

  ensureMotorsAlwaysRun();
 
  updateLastTimeVariables();
}

double calculateErrorForYaw(double desired, double actual) {
  double error = (desired+360) - (actual+360);
  return fixYaw360degrees(error);
}

double fixYaw360degrees(double angle){
  if (angle > 180)
    angle -= 360;
  else if (angle < -180)
    angle += 360;
  return angle;
}

void reduceMotorPowers(){ // to preserve balance if MAX_THROTTLE limit exceeds)
  int maxMotorPower = max(max(frontLeftMotorPower, frontRightMotorPower), max(rearLeftMotorPower, rearRightMotorPower));
  if (maxMotorPower > MAX_THROTTLE){
    double power_reduction_rate = (double)maxMotorPower / (double)MAX_THROTTLE;
    frontLeftMotorPower = round((double)frontLeftMotorPower / power_reduction_rate);
    frontRightMotorPower = round((double)frontRightMotorPower / power_reduction_rate);
    rearLeftMotorPower = round((double)rearLeftMotorPower / power_reduction_rate);
    rearRightMotorPower = round((double)rearRightMotorPower / power_reduction_rate);
  }
}

void ensureMotorsAlwaysRun(){
  frontLeftMotorPower = max(frontLeftMotorPower, THROTTLE_START_POINT);
  frontRightMotorPower = max(frontRightMotorPower, THROTTLE_START_POINT);
  rearLeftMotorPower = max(rearLeftMotorPower, THROTTLE_START_POINT);
  rearRightMotorPower = max(rearRightMotorPower, THROTTLE_START_POINT);
}

void updateCurrentTimeVariables() {
  current_time = millis();
  delta_time = (current_time - last_time);
}

void updateLastTimeVariables() {
  last_time = current_time;
}
