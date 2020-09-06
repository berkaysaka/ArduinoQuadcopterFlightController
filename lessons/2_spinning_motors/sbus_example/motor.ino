#include <Servo.h>

Servo motor;

void initializeMotor(){
  motor.attach(4, 1000, 2000);
}

void spinMotor(int speed){
  motor.write(speed); 
}
