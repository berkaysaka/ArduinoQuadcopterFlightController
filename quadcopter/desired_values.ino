struct ReceiverCommands convertToReceiverCommands(struct RawReceiverValues r) {
  struct ReceiverCommands o;
  o.Throttle = map(r.Throttle, MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE, 0, THROTTLE_LIMIT_POINT);
  o.PitchAngle = calculateAskedAngle(r.Pitch, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  o.RollAngle = calculateAskedAngle(r.Roll, ANGLE_DEGREE_LIMIT_PITCH_ROLL);
  o.YawAngleChange = calculateAskedAngle(r.Yaw, ANGLE_DEGREE_LIMIT_YAW);
  return o;
}

double calculateAskedAngle(int rawReceiverValue, int angleDegreeLimit) {
  double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;
  double range = MAX_RAW_RECEIVER_VALUE - MIN_RAW_RECEIVER_VALUE;
  double half_range = range / 2;
  double desired_angle = angleDegreeLimit * (rawReceiverValue - center) / half_range;
  return desired_angle;
}
