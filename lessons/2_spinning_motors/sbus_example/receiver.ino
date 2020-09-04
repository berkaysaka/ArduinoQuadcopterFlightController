#include <FUTABA_SBUS.h>

FUTABA_SBUS sBus;

struct ReceiverCommands {
  int Roll;
  int Pitch;
  int Throttle;
  int Yaw;
  int Error;
};

int prevRoll = 0;
int prevPitch = 0;
int prevThrottle = 0;
int prevYaw = 0;

unsigned long receiver_last_communication_time = millis();

void initializeReceiver(){
  sBus.begin();
}

struct ReceiverCommands GetReceiverCommands(){
  struct ReceiverCommands cmd;
  cmd.Roll = prevRoll;
  cmd.Pitch = prevPitch;
  cmd.Throttle = prevThrottle;
  cmd.Yaw = prevYaw;
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

    cmd.Roll = map(sBus.channels[0], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.Pitch = map(sBus.channels[1], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.Throttle = map(sBus.channels[2], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, 0, 180);
    cmd.Yaw = map(sBus.channels[3], RECEIVER_MIN_VALUE, RECEIVER_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);

    prevRoll = cmd.Roll;
    prevPitch = cmd.Pitch;
    prevThrottle = cmd.Throttle;
    prevYaw = cmd.Yaw;
  }else if(millis() - RECEIVER_COMMUNICATION_TIMEOUT > receiver_last_communication_time){
    cmd.Error = true;
  }

  return cmd;
}
