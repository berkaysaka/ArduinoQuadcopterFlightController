double pitch_angle_error, roll_angle_error;
double accTrust = 0.02;
void initializeGyro() {
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets();
  int iter = 2000;
  for(int i=0;i<iter;i++){
    pitch_angle_error = mpu6050.getGyroAngleX() * (1-0.002) + mpu6050.getAccAngleX() * 0.002;
    roll_angle_error = mpu6050.getGyroAngleY() * (1-0.002) + mpu6050.getAccAngleY() * 0.002;
  }
  pitch_angle_error /= iter;
  roll_angle_error /= iter;
}

void readGyroValues() {
  mpu6050.update();
  //pitchAngle = mpu6050.getAngleX() - pitch_angle_error;
  //rollAngle = mpu6050.getAngleY() - roll_angle_error;
  pitchAngle = ((mpu6050.getGyroAngleX() * (1-accTrust)) + (((pitchAngle * 99 + (mpu6050.getAccAngleX() * 1)) / 100) * accTrust));
  rollAngle = ((mpu6050.getGyroAngleY() * (1-accTrust)) + (((rollAngle * 99 + (mpu6050.getAccAngleY() * 1)) / 100) * accTrust));
  pitchAngle -= pitch_angle_error;
  rollAngle -= roll_angle_error;
  yawAngle = mpu6050.getAngleZ();
}
