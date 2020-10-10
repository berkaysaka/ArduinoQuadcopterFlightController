#define RECEIVER_COMMUNICATION_TIMEOUT 200
#define RECEIVER_MIN_VALUE 306 
#define RECEIVER_MAX_VALUE 1693
#define QUADCOPTER_MAX_TILT_ANGLE 30
#define INTERRUPT_PIN 2
#define IMU_COMMUNICATION_TIMEOUT 200

#define ACCEL_OFFSET_X 126
#define ACCEL_OFFSET_Y 1637
#define ACCEL_OFFSET_Z 414
#define GYRO_OFFSET_X 74
#define GYRO_OFFSET_Y -91
#define GYRO_OFFSET_Z 39

#define MIN_MOTOR_PULSE_WIDTH 1000
#define MAX_MOTOR_PULSE_WIDTH 2000

#define KP_roll 1.00
#define KI_roll 0.0005
#define KD_roll 400.00

struct ReceiverCommands {
  int YawAngle;
  int RollAngle;
  int PitchAngle;
  int Throttle;
  int Error;
};

struct Orientation {
  double YawAngle;
  double PitchAngle;
  double RollAngle;
};

struct IMU_Values {
  bool Error;
  bool NewDataAvailable;
  unsigned long DeltaTime;
  struct Orientation CurrentOrientation;
};

struct MotorPowers {
  int LeftMotorPower;
  int RightMotorPower;
};
