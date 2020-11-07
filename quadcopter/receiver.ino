#include <FUTABA_SBUS.h>

FUTABA_SBUS sBus;

double prevRollAngle = 0;
double prevPitchAngle = 0;
double prevThrottle = 0;
double prevYawAngleChange = 0;

unsigned long receiver_last_communication_time = millis();

void initializeReceiver(){
  sBus.begin();
}

struct ReceiverCommands GetReceiverCommands(){
  struct ReceiverCommands cmd;
  cmd.RollAngle = prevRollAngle;
  cmd.PitchAngle = prevPitchAngle;
  cmd.Throttle = prevThrottle;
  cmd.YawAngleChange = prevYawAngleChange;
  cmd.Error = false;

  sBus.FeedLine();
  if (sBus.toChannels == 1){
    sBus.UpdateServos();
    sBus.UpdateChannels();

    if(sBus.Failsafe() != 0){
      cmd.Error = true;
      return cmd;
    }

    receiver_last_communication_time = millis();
    sBus.toChannels = 0;

    cmd.RollAngle = map(sBus.channels[0], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.PitchAngle = map(sBus.channels[1], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.Throttle = map(sBus.channels[2], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, 0, THROTTLE_LIMIT_POINT);
    cmd.YawAngleChange = map(sBus.channels[3], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);

    prevRollAngle = cmd.RollAngle;
    prevPitchAngle = cmd.PitchAngle;
    prevThrottle = cmd.Throttle;
    prevYawAngleChange = cmd.YawAngleChange;
  }else if(millis() - RECEIVER_COMMUNICATION_TIMEOUT_IN_MILLISECONDS > receiver_last_communication_time){
    cmd.Error = true;
  }

  return cmd;
}

//prevent small receiver value changes to affect yaw while joystick is on the center
int centralize(int val) {
  int center = (RECEIVER_MAX_VALUE + RECEIVER_MIN_VALUE) / 2;
  if (abs(val - center) <= RECEIVER_DEAD_BAND)
    return center;
  else
    return val;
}
