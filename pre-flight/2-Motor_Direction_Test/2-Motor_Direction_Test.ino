#include <Servo.h>

Servo frontLeftMotor;
Servo frontRightMotor;
Servo rearLeftMotor;
Servo rearRightMotor;

void setup() {
  Serial.begin(9600);

  Serial.println("attaching motors");
  frontLeftMotor.attach(4, 1000, 2000);
  frontRightMotor.attach(6, 1000, 2000);
  rearLeftMotor.attach(5, 1000, 2000);
  rearRightMotor.attach(7, 1000, 2000);

  frontLeftMotor.write(0);
  frontRightMotor.write(0);
  rearLeftMotor.write(0);
  rearRightMotor.write(0);
  
  Serial.println("type motor number to test(1,2,3,4) then hit enter");
  Serial.println("type 0 then hit enter to stop motors");
}

void loop() {
  while(!Serial.available()){
    // wait for command
  }
  
  frontLeftMotor.write(0);
  frontRightMotor.write(0);
  rearLeftMotor.write(0);
  rearRightMotor.write(0);
  
  char motorNumber = Serial.parseInt();
  while(Serial.available()){
    Serial.read();
  }
  switch (motorNumber) {
  case 1:
    rearRightMotor.write(30);
    Serial.println("motor 1 is running (rear right)");
    break;
  case 2:
    frontRightMotor.write(30);
    Serial.println("motor 2 is running (front right)");
    break;
  case 3:
    rearLeftMotor.write(30);
    Serial.println("motor 3 is running (rear left)");
    break;
  case 4:
    frontLeftMotor.write(30);
    Serial.println("motor 4 is running (front left)");
    break;
  default:
    Serial.println("motors stopped");
  }
}
