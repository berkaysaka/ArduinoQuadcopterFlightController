double getControlSignal(double error, double kp, double ki, double kd, double& pid_i, double& last_error, double delta_time_in_seconds) {
  double pid_p = error;
  double pid_d = (error - last_error) / delta_time_in_seconds;
  pid_i += error * delta_time_in_seconds;

  double control_signal = (kp * pid_p) + (ki * pid_i) + (kd * pid_d);
  last_error = error;
  return control_signal;
}
