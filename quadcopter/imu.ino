#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif
MPU6050 mpu;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

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

struct Orientation previousOrientation;
unsigned long last_time = 0; 

void initializeIMU() {
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(100, true);
  #endif
  
  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);

  if(!mpu.testConnection()){
    Serial.println("*imu test connection failed!");
  }
  devStatus = mpu.dmpInitialize();
  mpu.setXGyroOffset(91);
  mpu.setYGyroOffset(-92);
  mpu.setZGyroOffset(38);
  mpu.setXAccelOffset(182);
  mpu.setYAccelOffset(1620);
  mpu.setZAccelOffset(397);

  if (devStatus == 0) {
    mpu.setDMPEnabled(true);
    attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady = true;

    packetSize = mpu.dmpGetFIFOPacketSize();
  }
}

struct IMU_Values readIMUvalues() {
  struct IMU_Values o;
  o.DataAvailable = false;
  if (!dmpReady || last_time == 0) 
    return o;

  unsigned long current_time = millis();
  unsigned long delta_time = current_time - last_time;
    
  if (mpu.dmpGetCurrentFIFOPacket(fifoBuffer)) { // Get the Latest packet 
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    
    // normally the order of the orientation that we receive from ypr[] is yaw, pitch, roll.
    // but since the IMU placed 90 degrees to the right, we need to make the adjustments below. (roll-pitch swap and *-1)
    o.CurrentOrientation.YawAngle = ypr[0] * 180 / M_PI;
    o.CurrentOrientation.RollAngle = ypr[1] * 180 / M_PI;
    o.CurrentOrientation.PitchAngle = ypr[2] * 180 / M_PI * -1; //-1 for changing rotation
    o.PreviousOrientation = previousOrientation;
    o.DataAvailable = true;
    o.DeltaTime = delta_time;
    
    previousOrientation = o.CurrentOrientation;
    last_time = current_time;
  }
  
  if(delta_time > IMU_COMMUNICATION_TIMEOUT_IN_MILLISECONDS){
      o.IMU_CommunicationError = true;
  }else{
      o.IMU_CommunicationError = false;
  }

  return o;
}
