void calculateDesiredOrientation() {
  throttle = map(throttleRaw, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, MIN_THROTTLE, THROTTLE_LIMIT_POINT);
  desired_pitch_angle = calculateAskedAngle(pitchRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_roll_angle = calculateAskedAngle(rollRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_yaw_angle = calculateDesiredYawAngle(desired_yaw_angle, calculateAskedAngle(yawRaw, ANGLE_DEGREE_LIMIT_YAW));
}

double calculateAskedAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}

double calculateDesiredYawAngle(double prev_desired_yaw_angle, double askedYawAngleChange){
  if(askedYawAngleChange == 0){
    return prev_desired_yaw_angle;
  }
  double tmpDesiredYawAngle = fixYaw360degrees(yawAngle + askedYawAngleChange);
  return tmpDesiredYawAngle;
}
