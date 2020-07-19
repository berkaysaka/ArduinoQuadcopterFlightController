struct RawReceiverValues {
  bool ReceiverError;
  int Throttle;
  int Yaw;
  int Pitch;
  int Roll;
};
struct ReceiverCommands {
  int Throttle;
  double YawAngleChange;
  double PitchAngle;
  double RollAngle;
};
struct Orientation {
  double YawAngle;
  double PitchAngle;
  double RollAngle;
};
struct IMU_Values {
  bool IMU_Error;
  bool DataAvailable;
  int DeltaTime;
  struct Orientation CurrentOrientation;
  struct Orientation PreviousOrientation;
};
struct MotorPowers {
  int frontLeftMotorPower;
  int frontRightMotorPower;
  int rearLeftMotorPower;
  int rearRightMotorPower;
};
