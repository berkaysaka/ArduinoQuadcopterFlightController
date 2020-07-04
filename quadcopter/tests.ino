double center = (MIN_RAW_RECEIVER_VALUE + MAX_RAW_RECEIVER_VALUE) / 2;

void reset_test_parameters(){
  throttle = 0;
  receiver_failure = false;
  imu_failure = false;
  rollRaw = center; pitchRaw = center; yawRaw = center;
  desired_roll_angle = 0; desired_pitch_angle = 0;desired_yaw_angle_change = 0;
  rollAngle = 0; pitchAngle = 0; yawAngle = 0;
  roll_pid_i = 0; roll_last_error = 0; pitch_pid_i = 0; pitch_last_error = 0; yaw_pid_i = 0; yaw_last_error = 0;
  last_time = millis() - 1;
  frontLeftMotorPower = 0; rearRightMotorPower = 0; frontRightMotorPower = 0; rearLeftMotorPower = 0;
  fresh_imu_data_available = true;
}
void run_tests(){
  Serial.println("----------------RUNNING TESTS--------------");
  test_calculate_motor_powers();
  test_reduceMotorPowers();
  test_calculateDesiredValuesWithSafetyChecks();
  Serial.println("----------------FINISHED--------------");
}

void test_calculate_motor_powers(){
  test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero();
  test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum();
  test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward();
  test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards();
  test_calculate_motor_powers_should_run_right_motors_faster_to_go_left();
  test_calculate_motor_powers_should_run_left_motors_faster_to_go_right();
  test_calculate_motor_powers_should_run_right_turning_motors_faster_to_turn_left();
  test_calculate_motor_powers_should_run_left_turning_motors_faster_to_turn_right();
  test_calculate_motor_powers_total_motor_powers_should_be_equal_to_4_times_throttle();
}

void test_reduceMotorPowers(){
  test_reduceMotorPowers_should_reduce_motor_powers_if_max_throttle_exceeds();
}

void test_calculateDesiredValuesWithSafetyChecks(){
  test_applySafetyRules_should_throttle_stay_as_is_if_greater_or_equal_than_THROTTLE_START_POINT();
  test_calculateDesiredValues_should_set_desired_roll_pitch_yaw_angles_to_0_if_transmitter_sticks_are_centered();
  test_calculateDesiredYawAngle_should_return_prev_desired_yaw_angle_if_0_angle_change_asked();
  test_calculateDesiredYawAngle_should_return_desired_angle_based_on_yaw_angle();
  test_calculateDesiredYawAngle_should_handle_360_degrees_properly();
}

void test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero(){
  reset_test_parameters();
  throttle = 0;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower == 0 && frontRightMotorPower == 0 && rearLeftMotorPower == 0 && rearRightMotorPower == 0);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_turn_off_motors_if_throttle_is_zero");
}

void test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum(){
  reset_test_parameters();
  throttle = 100;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower > 0 && frontRightMotorPower > 0 && rearLeftMotorPower > 0 && rearRightMotorPower > 0);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_send_power_to_the_motors_if_throttle_is_not_minimum");
}

void test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward(){
  reset_test_parameters();
  throttle = 100;
  desired_pitch_angle = -5;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower == frontRightMotorPower) && (rearLeftMotorPower == rearRightMotorPower) && (frontLeftMotorPower < rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_rear_motors_faster_to_go_forward");
}

void test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards(){
  reset_test_parameters();
  throttle = 100;
  desired_pitch_angle = 5;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower == frontRightMotorPower) && (rearLeftMotorPower == rearRightMotorPower) && (frontLeftMotorPower > rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_front_motors_faster_to_go_backwards");
}

void test_calculate_motor_powers_should_run_right_motors_faster_to_go_left(){
  reset_test_parameters();
  throttle = 100;
  desired_roll_angle = -5;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower == rearLeftMotorPower) && (frontRightMotorPower == rearRightMotorPower) && (rearRightMotorPower > rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_right_motors_faster_to_go_left");
}

void test_calculate_motor_powers_should_run_left_motors_faster_to_go_right(){
  reset_test_parameters();
  throttle = 100;
  desired_roll_angle = 5;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = (frontLeftMotorPower == rearLeftMotorPower) && (frontRightMotorPower == rearRightMotorPower) && (rearRightMotorPower < rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_left_motors_faster_to_go_right");
}

void test_calculate_motor_powers_should_run_right_turning_motors_faster_to_turn_left(){
  /*reset_test_parameters();
  throttle = 100;
  desired_yaw_angle = -5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == rearRightMotorPower) && (frontRightMotorPower == rearLeftMotorPower) && (rearRightMotorPower > rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_right_turning_motors_faster_to_turn_left");*/
}

void test_calculate_motor_powers_should_run_left_turning_motors_faster_to_turn_right(){
  /*reset_test_parameters();
  throttle = 100;
  desired_yaw_angle = 5;
  calculateMotorPowers();
  
  bool passed = (frontLeftMotorPower == rearRightMotorPower) && (frontRightMotorPower == rearLeftMotorPower) && (rearRightMotorPower < rearLeftMotorPower);
  Serial.println(String(passed) + " => test_calculate_motor_powers_should_run_left_turning_motors_faster_to_turn_right");*/
}

void test_calculate_motor_powers_total_motor_powers_should_be_equal_to_4_times_throttle(){
  /*reset_test_parameters();
  throttle = 100;
  desired_yaw_angle = -5;
  calculateMotorPowers();
  applySafetyRules();
  bool passed = frontLeftMotorPower + rearRightMotorPower + frontRightMotorPower + rearLeftMotorPower == throttle * 4;
  Serial.println(String(passed) + " => test_calculate_motor_powers_total_motor_powers_should_be_equal_to_4_times_throttle");*/
}

void test_reduceMotorPowers_should_reduce_motor_powers_if_max_throttle_exceeds(){
  reset_test_parameters();
  throttle = 100;
  frontLeftMotorPower = 350;
  frontRightMotorPower = 200;
  rearLeftMotorPower = 100;
  rearRightMotorPower = 50;
  reduceMotorPowers();
  
  bool passed = frontLeftMotorPower == 175 && frontRightMotorPower == 100 && rearLeftMotorPower == 50 && rearRightMotorPower == 25;
  Serial.println(String(passed) + " => test_reduceMotorPowers_should_reduce_motor_powers_if_max_throttle_exceeds");
}

void test_applySafetyRules_should_throttle_stay_as_is_if_greater_or_equal_than_THROTTLE_START_POINT(){
  reset_test_parameters();
  throttle = THROTTLE_START_POINT;
  applySafetyRules();
  
  bool passed = throttle == THROTTLE_START_POINT;
  Serial.println(String(passed) + " => test_applySafetyRules_should_throttle_stay_as_is_if_greater_or_equal_than_THROTTLE_START_POINT");
}

void test_calculateDesiredValues_should_set_desired_roll_pitch_yaw_angles_to_0_if_transmitter_sticks_are_centered(){
  /*reset_test_parameters();
  pitchRaw = center;
  rollRaw = center;
  yawRaw = center;
  calculateDesiredOrientation();
  bool passed = desired_pitch_angle == 0 && desired_roll_angle == 0 && desired_yaw_angle == 0;
  Serial.println(String(passed) + " => test_calculateDesiredValues_should_set_desired_roll_pitch_yaw_angles_to_0_if_transmitter_sticks_are_centered");*/
}

void test_calculateDesiredYawAngle_should_return_prev_desired_yaw_angle_if_0_angle_change_asked(){
  /*reset_test_parameters();
  bool passed = calculateDesiredYawAngle(-3, 0) == -3 && calculateDesiredYawAngle(1, 0) == 1;
  Serial.println(String(passed) + " => test_calculateDesiredYawAngle_should_return_prev_desired_yaw_angle_if_0_angle_change_asked");
  */
}

void test_calculateDesiredYawAngle_should_return_desired_angle_based_on_yaw_angle(){
  /*reset_test_parameters();
  yawAngle = 0;
  bool passed = calculateDesiredYawAngle(3, -2) == -2
             && calculateDesiredYawAngle(3, 2) == 2;
  Serial.println(String(passed) + " => test_calculateDesiredYawAngle_should_return_desired_angle_based_on_yaw_angle");*/
}

void test_calculateDesiredYawAngle_should_handle_360_degrees_properly(){
  /*
  reset_test_parameters();
  yawAngle = 179;
  bool passed1 = calculateDesiredYawAngle(yawAngle, 2) == -179
             && calculateDesiredYawAngle(yawAngle, -360) == yawAngle
             && calculateDesiredYawAngle(yawAngle,  360) == yawAngle;
  reset_test_parameters();
  yawAngle = -179;
  bool passed2 = calculateDesiredYawAngle(yawAngle, -2) == 179
             && calculateDesiredYawAngle(yawAngle, -360) == yawAngle
             && calculateDesiredYawAngle(yawAngle,  360) == yawAngle;
             
  Serial.println(String(passed1 && passed2) + " => test_calculateDesiredYawAngle_should_handle_360_degrees_properly");
  */
}


void printCurrentMotorPowers(){
  Serial.println("frontLeftMotorPower=" + String(frontLeftMotorPower));
  Serial.println("rearLeftMotorPower=" + String(rearLeftMotorPower));
  Serial.println("frontRightMotorPower=" + String(frontRightMotorPower));
  Serial.println("rearRightMotorPower=" + String(rearRightMotorPower));
}
