double getControlSignal(double error, double kp, double ki, double kd, double& pid_i, double& last_error, double integral_limit, double integral_activation_threshold) {
  pid_i += error * delta_time;
  pid_i = constrain(pid_i, -integral_limit, integral_limit);
  if ((error<0. && last_error>0.) || (error>0. && last_error<0.)){
    pid_i = 0; // fix integral wind-up isuue by resetting integral to zero in order to prevent unnecessary overshoots)
  }
  if (abs(error) > integral_activation_threshold){
    pid_i = 0; // don't start counting integral early
  }
  
  double pid_p = error;
  
  double pid_d = (error - last_error) / delta_time;
  if ((error > 0. && (error - last_error) > 0.) || (error < 0. && (error - last_error) < 0.)){
    pid_d = 0; // prevent derivative kicks
  }
  
  double control_signal = (kp*pid_p) + (kd*pid_d) + (ki*pid_i);
  last_error = error;
  return control_signal;
}
