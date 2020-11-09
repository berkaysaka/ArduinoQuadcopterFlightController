#include <Servo.h>

Servo frontLeftMotor;
Servo frontRightMotor;
Servo rearLeftMotor;
Servo rearRightMotor;

void initializeMotors() {
  frontLeftMotor.attach(FRONT_LEFT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  frontRightMotor.attach(FRONT_RIGHT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  rearLeftMotor.attach(REAR_LEFT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  rearRightMotor.attach(REAR_RIGHT_MOTOR_PIN, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);

  stopMotors();
}

void spinMotors(struct MotorPowers motorPowers) {
  frontLeftMotor.write(motorPowers.frontLeftMotorPower);
  frontRightMotor.write(motorPowers.frontRightMotorPower);
  rearLeftMotor.write(motorPowers.rearLeftMotorPower);
  rearRightMotor.write(motorPowers.rearRightMotorPower);
}

void stopMotors() {
  frontLeftMotor.write(0);
  frontRightMotor.write(0);
  rearLeftMotor.write(0);
  rearRightMotor.write(0);
}
