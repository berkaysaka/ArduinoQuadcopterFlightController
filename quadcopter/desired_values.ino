void calculateDesiredValuesWithSafetyChecks(){
  calculateDesiredValues();
  applySafetyRules();
}

void calculateDesiredValues() {
  throttle = map(throttleRaw, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, MIN_THROTTLE, THROTTLE_LIMIT_POINT);
  desired_pitch_angle = calculateDesiredAngle(pitchRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_roll_angle = calculateDesiredAngle(rollRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_yaw_angle = calculateDesiredYawAngle(desired_yaw_angle, calculateDesiredAngle(yawRaw, ANGLE_DEGREE_LIMIT_YAW));
}

void applySafetyRules(){
  if (throttle < THROTTLE_START_POINT || receiver_failure == true){
    throttle = MIN_THROTTLE;
    desired_yaw_angle = yawAngle;  
  }
}

double calculateDesiredAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}

double calculateDesiredYawAngle(double previouslyAskedYawAngle, double askedYawAngle){
  //170 - 3 =167
  //167 - 173= -6
  double tmpDesiredYawAngle = fixYaw360degrees(previouslyAskedYawAngle + askedYawAngle);
  double yawError = calculateErrorForYaw(tmpDesiredYawAngle, yawAngle);
  if(yawError < -ANGLE_DEGREE_LIMIT_YAW){
    return fixYaw360degrees(tmpDesiredYawAngle - (yawError+ANGLE_DEGREE_LIMIT_YAW));
  }else if(yawError > ANGLE_DEGREE_LIMIT_YAW){
    return fixYaw360degrees(tmpDesiredYawAngle - (yawError-ANGLE_DEGREE_LIMIT_YAW));
  }else{
    return tmpDesiredYawAngle;
  }
}
