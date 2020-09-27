#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void initializeMotor(){
  leftMotor.attach(4, 1000, 2000);
  rightMotor.attach(5, 1000, 2000);
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
