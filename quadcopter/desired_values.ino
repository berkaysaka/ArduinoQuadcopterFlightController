void calculateDesiredValues() {
  throttle = map(throttleRaw, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, MIN_THROTTLE, THROTTLE_LIMIT_POINT);
  if (throttle < THROTTLE_START_POINT){
    throttle = MIN_THROTTLE;
    desired_yaw_angle = yawAngle;  
  }

  desired_pitch_angle = calculateDesiredAngle(pitchRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_roll_angle = calculateDesiredAngle(rollRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  //170 - 3 =167
  //167 - 173= -6
  double tmpDesiredYawAngle = fixYaw360degrees(desired_yaw_angle + calculateDesiredAngle(yawRaw, ANGLE_DEGREE_LIMIT_YAW));
  double yawError = calculateErrorForYaw(tmpDesiredYawAngle, yawAngle);
  if(yawError < -ANGLE_DEGREE_LIMIT_YAW){
    desired_yaw_angle = fixYaw360degrees(tmpDesiredYawAngle - (yawError+ANGLE_DEGREE_LIMIT_YAW));
  }else if(yawError > ANGLE_DEGREE_LIMIT_YAW){
    desired_yaw_angle = fixYaw360degrees(tmpDesiredYawAngle - (yawError-ANGLE_DEGREE_LIMIT_YAW));
  }else{
    desired_yaw_angle = tmpDesiredYawAngle;
  }

}

double calculateDesiredAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}
