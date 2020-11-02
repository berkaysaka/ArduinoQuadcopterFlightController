#include <Servo.h>

Servo frontLeftMotor;
Servo frontRightMotor;
Servo rearLeftMotor;
Servo rearRightMotor;

void setup() {
  Serial.begin(9600);
  Serial.println("press enter to start calibration");
  
  while(!Serial.available()){
    // wait for command
  }

  Serial.println("attaching motors");
  frontLeftMotor.attach(4, 1000, 2000);
  frontRightMotor.attach(6, 1000, 2000);
  rearLeftMotor.attach(5, 1000, 2000);
  rearRightMotor.attach(7, 1000, 2000);

  if(!rearRightMotor.attached()){
    Serial.println("a problem occured while attaching to the motor 1(rear right)");
    return;
  }
  if(!frontRightMotor.attached()){
    Serial.println("a problem occured while attaching to the motor 2(front right)");
    return;
  }
  if(!rearLeftMotor.attached()){
    Serial.println("a problem occured while attaching to the motor 3(rear left)");
    return;
  }
  if(!frontLeftMotor.attached()){
    Serial.println("a problem occured while attaching to the motor 4(front left)");
    return;
  }

  Serial.println("ESC calibration started");
  Serial.println("setting high value...");
  frontLeftMotor.write(180);
  frontRightMotor.write(180);
  rearLeftMotor.write(180);
  rearRightMotor.write(180);
  delay(3000);
  Serial.println("setting low value...");
  frontLeftMotor.write(0);
  frontRightMotor.write(0);
  rearLeftMotor.write(0);
  rearRightMotor.write(0);
  delay(5000);
  Serial.println("ESC calibration completed");

  Serial.println("testing motor1(rear right)");
  delay(1000);
  rearRightMotor.write(30);
  delay(1000);
  rearRightMotor.write(0);

  Serial.println("testing motor2(front right)");
  delay(1000);
  frontRightMotor.write(30);
  delay(1000);
  frontRightMotor.write(0);

  Serial.println("testing motor3(rear left)");
  delay(1000);
  rearLeftMotor.write(30);
  delay(1000);
  rearLeftMotor.write(0);

  Serial.println("testing motor4(front left)");
  delay(1000);
  frontLeftMotor.write(30);
  delay(1000);
  frontLeftMotor.write(0);

  Serial.println("motor test completed");
}

void loop() {
  // put your main code here, to run repeatedly:

}
