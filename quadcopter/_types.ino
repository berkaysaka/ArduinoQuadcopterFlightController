struct ReceiverRawValues {
  bool NewDataAvailable;
  bool TransmitterCommunicationFailure;
  int ChannelValues[4];
};
struct ReceiverCommands {
  bool Armed;
  bool Error;
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
  bool Error;
  bool NewDataAvailable;
  double DeltaTimeInSeconds;
  struct Orientation CurrentOrientation;
  struct Orientation PreviousOrientation;
};
struct MotorPowers {
  int frontLeftMotorPower;
  int frontRightMotorPower;
  int rearLeftMotorPower;
  int rearRightMotorPower;
};
