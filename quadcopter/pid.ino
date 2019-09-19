double getControlSignal(double current_angle, double desired_angle, double kp, double ki, double kd, double& pid_i, double& last_error, double integral_limit) {
  double error = desired_angle - current_angle;
  double pid_p = kp * error;
  pid_i += ki * error;
  pid_i = constrain(pid_i, (-1 * integral_limit), integral_limit);
  double pid_d = kd * ((error - last_error) / delta_time);
  double control_signal = pid_p + pid_d + pid_i;
  last_error = error;
  return control_signal;
}
