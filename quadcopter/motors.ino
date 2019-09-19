void initializeMotors() {
  frontLeftMotor.attach(FRONT_LEFT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  frontLeftMotor.write(0);
  frontRightMotor.attach(FRONT_RIGHT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  frontRightMotor.write(0);
  rearLeftMotor.attach(REAR_LEFT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  rearLeftMotor.write(0);
  rearRightMotor.attach(REAR_RIGHT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  rearRightMotor.write(0);
}

void spinMotors() {
  frontLeftMotor.write(frontLeftMotorPower);
  frontRightMotor.write(frontRightMotorPower);
  rearLeftMotor.write(rearLeftMotorPower);
  rearRightMotor.write(rearRightMotorPower);
}

void updateMotorsWithStaticThrottle() {
  frontLeftMotor.write(throttle);
  frontRightMotor.write(throttle);
  rearLeftMotor.write(throttle);
  rearRightMotor.write(throttle);
}
