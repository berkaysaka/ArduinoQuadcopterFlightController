struct RawReceiverValues {
   int Throttle;
   int Yaw;
   int Pitch;
   int Roll;
};
struct DesiredOrientation {
   int Throttle;
   double YawAngleChange;
   double PitchAngle;
   double RollAngle;
};
struct Orientation {
   double YawAngle;
   double PitchAngle;
   double RollAngle;
   double PreviousYawAngle;
};
