#include <FUTABA_SBUS.h>

FUTABA_SBUS sBus;

int prevRollAngle = 0;
int prevPitchAngle = 0;
int prevThrottle = 0;
int prevYawAngle = 0;

unsigned long receiver_last_communication_time = millis();

void initializeReceiver(){
  sBus.begin();
}

struct ReceiverCommands GetReceiverCommands(){
  struct ReceiverCommands cmd;
  cmd.RollAngle = prevRollAngle;
  cmd.PitchAngle = prevPitchAngle;
  cmd.Throttle = prevThrottle;
  cmd.YawAngle = prevYawAngle;
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
    cmd.Throttle = map(sBus.channels[2], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, 0, 180);
    cmd.YawAngle = map(sBus.channels[3], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);

    prevRollAngle = cmd.RollAngle;
    prevPitchAngle = cmd.PitchAngle;
    prevThrottle = cmd.Throttle;
    prevYawAngle = cmd.YawAngle;
  }else if(millis() - RECEIVER_COMMUNICATION_TIMEOUT > receiver_last_communication_time){
    cmd.Error = true;
  }

  return cmd;
}
