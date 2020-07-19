double getControlSignal(double error, double kp, double ki, double kd, double& pid_i, double& last_error, double integral_limit, int delta_time) {
  double pid_p = error;
  
  double pid_d = (error - last_error) / delta_time;

  pid_i += error * delta_time;
  double integral_signal = constrain(ki*pid_i, -integral_limit, integral_limit);
  pid_i = integral_signal / ki; 
  
  double control_signal = (kp*pid_p) + integral_signal + (kd*pid_d);
  last_error = error;
  return control_signal;
}

/*double getControlSignal(double error, double point_diff, double kp, double ki, double kd, double& pid_i, double& last_error, double integral_limit) {
  double pid_p = error;

  double pid_d = point_diff / delta_time;
  if(abs(error) < 4.0)
    pid_d*=3.0;
  else if(abs(error) < 8.0)
    pid_d*=2.0;

  pid_i += error * delta_time;
  double integral_signal = constrain(ki*pid_i, -integral_limit, integral_limit);
  pid_i = integral_signal / ki; 
  
  double control_signal = (kp*pid_p) + integral_signal - (kd*pid_d);
  last_error = error;
  return control_signal;
}
*/
