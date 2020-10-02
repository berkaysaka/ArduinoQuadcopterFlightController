#include <Servo.h>

Servo leftMotor;
Servo rightMotor;

void setup() {
  Serial.begin(115200);
  Serial.println("started");

  leftMotor.attach(4, 1000, 2000);
  rightMotor.attach(5, 1000, 2000);

  delay(8000);
  for(int i=0; i<10000; i++){
    leftMotor.write(180);
    rightMotor.write(180);
  }
  delay(2000);
  
  
  leftMotor.write(0);
  rightMotor.write(0);
  delay(7000);
  leftMotor.write(30);
  rightMotor.write(30);
  delay(1000);
  leftMotor.write(0);
  rightMotor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
