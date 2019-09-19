void printRawReceiverValues() {
  Serial.print("throttleRaw=");
  Serial.print(throttleRaw);
  Serial.print("\t");
  Serial.print("yawRaw=");
  Serial.print(yawRaw);
  Serial.print("\t");
  Serial.print("rollRaw=");
  Serial.print(rollRaw);
  Serial.print("\t");
  Serial.print("pitchRaw=");
  Serial.print(pitchRaw);
  Serial.println();
}

void printMotorPowers() {
  Serial.print("frontLeftMotorPower=   ");
  Serial.println(frontLeftMotorPower);
  Serial.print("frontRightMotorPower=  ");
  Serial.println(frontRightMotorPower);
  Serial.print("rearLeftMotorPower=    ");
  Serial.println(rearLeftMotorPower);
  Serial.print("rearRightMotorPower=   ");
  Serial.println(rearRightMotorPower);
}

void printMotorPowersGraph() {
  Serial.print(frontLeftMotorPower);
  Serial.print("\t");
  Serial.print(frontRightMotorPower);
  Serial.println();
}

void printDesiredValues() {
  Serial.print("throttle:");
  Serial.print(throttle);
  Serial.print("\t");
  Serial.print("desired_pitch_angle:");
  Serial.print(desired_pitch_angle);
  Serial.print("\t");
  Serial.print("desired_roll_angle: ");
  Serial.print(desired_roll_angle);
  Serial.print("\t");
  Serial.print("desired_yaw_angle: ");
  Serial.print(desired_yaw_angle);
  Serial.println();
}

void printGyroValues() {
  Serial.print("pitchAngleº: ");
  Serial.print(pitchAngle);
  Serial.print("   |   ");
  Serial.print("rollAngleº: ");
  Serial.print(rollAngle);
  Serial.println(" ");
}

long _lastTime = millis();
void printGraphGyroValues() {
  long _currentTime = millis();
  if(_currentTime - _lastTime < 20)
    return;
  _lastTime = _currentTime;
  Serial.print(pitchAngle);
  Serial.print("\t");
  Serial.print(rollAngle);
  //Serial.print("\t");
  //Serial.print(yawAngle);
  Serial.println();
}
