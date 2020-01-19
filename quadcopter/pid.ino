double getControlSignal(double error, double kp, double ki, double kd, double& pid_i, double& last_error, double integral_limit) {
  pid_i += error * delta_time;
  double pid_p = error;
  double pid_d = (error - last_error) / delta_time;
  
  double control_signal = (kp*pid_p) + constrain(ki*pid_i, -integral_limit, integral_limit) + (kd*pid_d);
  last_error = error;
  return control_signal;
}
