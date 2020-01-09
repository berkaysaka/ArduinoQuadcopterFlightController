void reset_test_parameters(){
  throttle = 0;
  receiver_failure = false;
  desired_roll_angle = 0;
  desired_pitch_angle = 0;
  desired_yaw_angle = 0;
  rollAngle = 0;
  pitchAngle = 0;
  yawAngle = 0;
}
void run_tests(){
  Serial.println("----------------RUNNING TESTS--------------");
  test_calculate_motor_powers();
  Serial.println("----------------FINISHED--------------");
}

void test_calculate_motor_powers(){
  test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged();
  test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero();
}

void test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged(){
  reset_test_parameters();
  throttle = 20;
  receiver_failure = true;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower == 0 && frontRightMotorPower == 0 && rearLeftMotorPower == 0 && rearRightMotorPower == 0);
  Serial.println(passed + " => test_calculate_motor_powers_should_set_turn_off_motors_if_receiver_is_unplugged");
}

void test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero(){
  reset_test_parameters();
  throttle = 0;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower == 0 && frontRightMotorPower == 0 && rearLeftMotorPower == 0 && rearRightMotorPower == 0);
  Serial.println(passed + " => test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero");
}

void test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum(){
  reset_test_parameters();
  throttle = 20;
  calculateMotorPowers();
  bool passed = (frontLeftMotorPower > 0 && frontRightMotorPower > 0 && rearLeftMotorPower > 0 && rearRightMotorPower > 0);
  Serial.println(passed + " => test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum");
}
