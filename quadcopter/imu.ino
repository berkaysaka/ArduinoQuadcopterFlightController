//Gyro Variables
float elapsedTime, time, timePrev;        //Variables for time control
int gyro_error = 0;                       //We use this variable to only calculate once the gyro data error
float Gyr_rawX, Gyr_rawY, Gyr_rawZ;       //Here we store the raw data read
float Gyro_angle_x, Gyro_angle_y, Gyro_angle_z;             //Here we store the angle value obtained with Gyro data
float Gyro_raw_error_x, Gyro_raw_error_y, Gyro_raw_error_z; //Here we store the initial gyro data error

//Acc Variables
int acc_error = 0;                          //We use this variable to only calculate once the Acc data error
float rad_to_deg = 180 / 3.141592654;       //This value is for pasing from radians to degrees values
float Acc_rawX, Acc_rawY, Acc_rawZ;         //Here we store the raw data read
float Acc_angle_x, Acc_angle_y;             //Here we store the angle value obtained with Acc data
float Acc_angle_error_x, Acc_angle_error_y; //Here we store the initial Acc data error

void initializeIMU() {
  ConfigureIMU();
  delay(5000);    // give some time to IMU to warm up
  CalibrateIMU();
}

void readIMUvalues() {
  timePrev = time;                          // the previous time is stored before the actual time read
  time = millis();                          // actual time read
  elapsedTime = (time - timePrev) / 1000;   // divide by 1000 in order to obtain seconds

  ReadGyroValues();
  ReadAccValues();
  CalculateYawPitchRoll();
}

void CalculateYawPitchRoll() {
  pitchAngle = (1 - ACCELEROMETER_TRUSTABILITY) * (pitchAngle + Gyro_angle_x) + ACCELEROMETER_TRUSTABILITY * Acc_angle_x;
  rollAngle = (1 - ACCELEROMETER_TRUSTABILITY) * (rollAngle + Gyro_angle_y) + ACCELEROMETER_TRUSTABILITY * Acc_angle_y;
  yawAngle += Gyro_angle_z;
}

void ConfigureIMU() {
  Wire.begin();                           //begin the wire comunication

  Wire.beginTransmission(0x68);           //begin, Send the slave adress (in this case 68)
  Wire.write(0x6B);                       //make the reset (place a 0 into the 6B register)
  Wire.write(0x00);
  Wire.endTransmission(true);             //end the transmission
  //Gyro config
  Wire.beginTransmission(0x68);           //begin, Send the slave adress (in this case 68)
  Wire.write(0x1B);                       //We want to write to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                       //Set the register bits as 00010000 (1000dps full scale)
  Wire.endTransmission(true);             //End the transmission with the gyro
  //Acc config
  Wire.beginTransmission(0x68);           //Start communication with the address found during search.
  Wire.write(0x1C);                       //We want to write to the ACCEL_CONFIG register
  Wire.write(0x10);                       //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);

  Wire.beginTransmission(0x68);           //Start communication with the address found during search
  Wire.write(0x1A);                       //We want to write to the CONFIG register (1A hex)
  Wire.write(0x03);                       //Set the register bits as 00000011 (Set Digital Low Pass Filter to ~43Hz)
  Wire.endTransmission();                 //End the transmission with the gyro
}

void CalibrateIMU() {
  time = millis();                        //Start counting time in milliseconds

  /*Here we calculate the acc data error before we start the loop
     I make the mean of 'x' values, that should be enough*/
  int loopCount = 2000;
  if (acc_error == 0)
  {
    for (int a = 0; a < loopCount; a++)
    {
      Wire.beginTransmission(0x68);
      Wire.write(0x3B);                       //Ask for the 0x3B register- correspond to AcX
      Wire.endTransmission(false);
      Wire.requestFrom(0x68, 6, true);

      Acc_rawX = (Wire.read() << 8 | Wire.read()) / 4096.0 ; //each value needs two registres
      Acc_rawY = (Wire.read() << 8 | Wire.read()) / 4096.0 ;
      Acc_rawZ = (Wire.read() << 8 | Wire.read()) / 4096.0 ;

      Acc_angle_error_x = Acc_angle_error_x + ((atan((Acc_rawY) / sqrt(pow((Acc_rawX), 2) + pow((Acc_rawZ), 2))) * rad_to_deg));
      Acc_angle_error_y = Acc_angle_error_y + ((atan(-1 * (Acc_rawX) / sqrt(pow((Acc_rawY), 2) + pow((Acc_rawZ), 2))) * rad_to_deg));
    }
    Acc_angle_error_x = Acc_angle_error_x / loopCount;
    Acc_angle_error_y = Acc_angle_error_y / loopCount;
    acc_error = 1;
  }//end of acc error calculation


  /*Here we calculate the gyro data error before we start the loop
     I make the mean of 'x' values, that should be enough*/
  if (gyro_error == 0)
  {
    for (int i = 0; i < loopCount; i++)
    {
      Wire.beginTransmission(0x68);            //begin, Send the slave adress (in this case 68)
      Wire.write(0x43);                        //First adress of the Gyro data
      Wire.endTransmission(false);
      Wire.requestFrom(0x68, 6, true);         //We ask for just 4 registers

      Gyr_rawX = Wire.read() << 8 | Wire.read();
      Gyr_rawY = Wire.read() << 8 | Wire.read();
      Gyr_rawZ = Wire.read() << 8 | Wire.read();

      Gyro_raw_error_x = Gyro_raw_error_x + (Gyr_rawX / 32.8);
      Gyro_raw_error_y = Gyro_raw_error_y + (Gyr_rawY / 32.8);
      Gyro_raw_error_z = Gyro_raw_error_z + (Gyr_rawZ / 32.8);
    }
    Gyro_raw_error_x = Gyro_raw_error_x / loopCount;
    Gyro_raw_error_y = Gyro_raw_error_y / loopCount;
    Gyro_raw_error_z = Gyro_raw_error_z / loopCount;
    gyro_error = 1;
  }//end of gyro error calculation
}

void ReadGyroValues() {
  Wire.beginTransmission(0x68);            //begin, Send the slave adress (in this case 68)
  Wire.write(0x43);                        //First adress of the Gyro data
  Wire.endTransmission(false);
  Wire.requestFrom(0x68, 6, true);         //We ask for just 4 registers

  Gyr_rawX = Wire.read() << 8 | Wire.read(); //Once again we shif and sum
  Gyr_rawY = Wire.read() << 8 | Wire.read();
  Gyr_rawZ = Wire.read() << 8 | Wire.read();
  /*Now in order to obtain the gyro data in degrees/seconds we have to divide first
    the raw value by 32.8 because that's the value that the datasheet gives us for a 1000dps range*/
  Gyr_rawX = (Gyr_rawX / 32.8) - Gyro_raw_error_x;
  Gyr_rawY = (Gyr_rawY / 32.8) - Gyro_raw_error_y;
  Gyr_rawZ = (Gyr_rawZ / 32.8) - Gyro_raw_error_z;

  /*Now we integrate the raw value in degrees per seconds in order to obtain the angle
    If you multiply degrees/seconds by seconds you obtain degrees */
  Gyro_angle_x = Gyr_rawX * elapsedTime;
  Gyro_angle_y = Gyr_rawY * elapsedTime;
  Gyro_angle_z = Gyr_rawZ * elapsedTime;
}

void ReadAccValues() {
  Wire.beginTransmission(0x68);     //begin, Send the slave adress (in this case 68)
  Wire.write(0x3B);                 //Ask for the 0x3B register- correspond to AcX
  Wire.endTransmission(false);      //keep the transmission and next
  Wire.requestFrom(0x68, 6, true);  //We ask for next 6 registers starting withj the 3B
  /*We have asked for the 0x3B register. The IMU will send a brust of register.
    The amount of register to read is specify in the requestFrom function.
    In this case we request 6 registers. Each value of acceleration is made out of
    two 8bits registers, low values and high values. For that we request the 6 of them
    and just make then sum of each pair. For that we shift to the left the high values
    register (<<) and make an or (|) operation to add the low values.
    If we read the datasheet, for a range of+-8g, we have to divide the raw values by 4096*/
  Acc_rawX = (Wire.read() << 8 | Wire.read()) / 4096.0 ; //each value needs two registres
  Acc_rawY = (Wire.read() << 8 | Wire.read()) / 4096.0 ;
  Acc_rawZ = (Wire.read() << 8 | Wire.read()) / 4096.0 ;
  /*Now in order to obtain the Acc angles we use euler formula with acceleration values
    after that we substract the error value found before*/
  Acc_angle_x = (atan((Acc_rawY) / sqrt(pow((Acc_rawX), 2) + pow((Acc_rawZ), 2))) * rad_to_deg) - Acc_angle_error_x;
  Acc_angle_y = (atan(-1 * (Acc_rawX) / sqrt(pow((Acc_rawY), 2) + pow((Acc_rawZ), 2))) * rad_to_deg) - Acc_angle_error_y;
}
