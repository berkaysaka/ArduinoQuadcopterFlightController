struct RawReceiverValues {
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
struct IMUvalues {
   bool IMU_Error;
   bool DataAvailable;
   Orientation Orientation;
};
