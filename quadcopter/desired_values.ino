void calculateDesiredValues() {
  throttle = map(throttleRaw, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, MIN_THROTTLE, THROTTLE_LIMIT_POINT);
  if (throttle < THROTTLE_START_POINT){
    throttle = MIN_THROTTLE;
    desired_yaw_angle = yawAngle;  
  }

  desired_pitch_angle = calculateDesiredAngle(pitchRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_roll_angle = calculateDesiredAngle(rollRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  
  double tmpDesired = desired_yaw_angle + calculateDesiredAngle(yawRaw, ANGLE_DEGREE_LIMIT_YAW);
  double diff = abs(tmpDesired - yawAngle);
  if (diff > 180)
    diff -= 360;
  else if (diff < -180)
    diff += 360;
  if(diff < (ANGLE_DEGREE_LIMIT_YAW*2))
    desired_yaw_angle = tmpDesired;
}

double calculateDesiredAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}
