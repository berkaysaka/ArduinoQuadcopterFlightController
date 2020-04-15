#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 mpu;
#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards

unsigned long lastImuDataAvailableTime = millis();

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high

void dmpDataReady() {
  mpuInterrupt = true;
}

void initializeIMU() {
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
  Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif
  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);
  devStatus = mpu.dmpInitialize();

  mpu.setXGyroOffset(91);
  mpu.setYGyroOffset(-92);
  mpu.setZGyroOffset(38);
  mpu.setXAccelOffset(182);
  mpu.setYAccelOffset(1620);
  mpu.setZAccelOffset(397);

  // make sure it worked (returns 0 if so)
  if (devStatus == 0) {
    /*mpu.CalibrateAccel(6);
    mpu.CalibrateGyro(6);
    mpu.PrintActiveOffsets();
    syncOutputSignals();*/
    
    mpu.setDMPEnabled(true);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;

    packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
    // ERROR!
    // 1 = initial memory load failed
    // 2 = DMP configuration updates failed
    // (if it's going to break, usually the code will be 1)
  }
}

void readIMUvalues() {
  if (!dmpReady) return;
  
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    // pitch-roll swapped somehow, investigate.
    double newYawAngle = ypr[0] * 180 / M_PI;
    double newRollAngle = ypr[1] * 180 / M_PI;
    double newPitchAngle = ypr[2] * 180 / M_PI * -1; //-1 for changing rotation

    prev_yawAngle = yawAngle;
    prev_rollAngle = rollAngle;
    prev_pitchAngle = pitchAngle;
    
    yawAngle = newYawAngle;
    rollAngle = newRollAngle;
    pitchAngle = newPitchAngle;

    fresh_imu_data_available = true;
    lastImuDataAvailableTime = millis();
  }

  unsigned long imuDataUnavailableTime = millis() - lastImuDataAvailableTime;
  if(imuDataUnavailableTime > 30){
      imu_failure = true;
  }else{
      imu_failure = false;
  }
}
