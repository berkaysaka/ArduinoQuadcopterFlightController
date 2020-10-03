#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void initializeMotor(){
  leftMotor.attach(4, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  rightMotor.attach(5, MIN_MOTOR_PULSE_WIDTH, MAX_MOTOR_PULSE_WIDTH);
  stopMotors();
}

void spinMotors(struct MotorPowers motorPowers){
  leftMotor.write(motorPowers.LeftMotorPower);
  rightMotor.write(motorPowers.RightMotorPower);
}

void stopMotors(){
  leftMotor.write(0);
  rightMotor.write(0);
}
