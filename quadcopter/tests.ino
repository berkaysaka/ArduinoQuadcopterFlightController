void reset_test_parameters(){
  throttle = 0;
  receiver_failure = false;
  desired_roll_angle = 0;
  desired_pitch_angle = 0;
  desired_yaw_angle = 0;
  rollAngle = 0;
  pitchAngle = 0;
  yawAngle = 0;
  roll_pid_i = 0; roll_last_error = 0; pitch_pid_i = 0; pitch_last_error = 0; yaw_pid_i = 0; yaw_last_error = 0;
  last_time = millis()-1;
}
void run_tests(){
  Serial.println("----------------RUNNING TESTS--------------");
  test_calculate_motor_powers();
  Serial.println("----------------FINISHED--------------");
}

void test_calculate_motor_powers(){
  test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged();
  test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero();
  test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum();
  test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward();
  test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards();
  test_calculate_motor_powers_should_run_right_motors_faster_to_go_left();
  test_calculate_motor_powers_should_run_left_motors_faster_to_go_right();
}

void test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged(){
  reset_test_parameters();
  throttle = 20;
  receiver_failure = true;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower == 0 && frontRightMotorPower == 0 && rearLeftMotorPower == 0 && rearRightMotorPower == 0);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged");
}

void test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero(){
  reset_test_parameters();
  throttle = 0;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower == 0 && frontRightMotorPower == 0 && rearLeftMotorPower == 0 && rearRightMotorPower == 0);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero");
}

void test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum(){
  reset_test_parameters();
  throttle = 20;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower > 0 && frontRightMotorPower > 0 && rearLeftMotorPower > 0 && rearRightMotorPower > 0);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum");
}

void test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward(){
  reset_test_parameters();
  throttle = 20;
  desired_pitch_angle = -5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == frontRightMotorPower) && (rearLeftMotorPower == rearRightMotorPower) && (frontLeftMotorPower < rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward");
  printCurrentMotorPowers();
}

void test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards(){
  reset_test_parameters();
  throttle = 20;
  desired_pitch_angle = 5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == frontRightMotorPower) && (rearLeftMotorPower == rearRightMotorPower) && (frontLeftMotorPower > rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards");
  printCurrentMotorPowers();
}

void test_calculate_motor_powers_should_run_right_motors_faster_to_go_left(){
  reset_test_parameters();
  throttle = 20;
  desired_roll_angle = -5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == rearLeftMotorPower) && (frontRightMotorPower == rearRightMotorPower) && (rearRightMotorPower > rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_right_motors_faster_to_go_left");
  printCurrentMotorPowers();
}

void test_calculate_motor_powers_should_run_left_motors_faster_to_go_right(){
  reset_test_parameters();
  throttle = 20;
  desired_roll_angle = 5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == rearLeftMotorPower) && (frontRightMotorPower == rearRightMotorPower) && (rearRightMotorPower < rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_left_motors_faster_to_go_right");
  printCurrentMotorPowers();
}

void printCurrentMotorPowers(){
  Serial.println("frontLeftMotorPower=" + String(frontLeftMotorPower));
  Serial.println("rearLeftMotorPower=" + String(rearLeftMotorPower));
  Serial.println("frontRightMotorPower=" + String(frontRightMotorPower));
  Serial.println("rearRightMotorPower=" + String(rearRightMotorPower));
}