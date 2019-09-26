void calculateDesiredValues() {
  throttle = map(throttleRaw, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, MIN_THROTTLE, MAX_THROTTLE);
  if (throttle < THROTTLE_START_POINT)
    throttle = MIN_THROTTLE;

  desired_pitch_angle = calculateDesiredAngle(pitchRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_roll_angle = calculateDesiredAngle(rollRaw, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  desired_yaw_angle = yawAngle + calculateDesiredAngle(yawRaw, ANGLE_DEGREE_LIMIT_YAW);
}

double calculateDesiredAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}
