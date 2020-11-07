struct ReceiverCommands {
  int Throttle;
  double YawAngleChange;
  double PitchAngle;
  double RollAngle;
  bool Error;
};
struct Orientation {
  double YawAngle;
  double PitchAngle;
  double RollAngle;
};
struct IMU_Values {
  bool IMU_CommunicationError;
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
