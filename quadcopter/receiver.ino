#include <FUTABA_SBUS.h>

FUTABA_SBUS sbus;

void initializeReceiver() {
  sbus.begin();
}

unsigned long last_receiver_communication_time = millis();

void readReceiverValues() {
  sbus.FeedLine();
  if (sbus.toChannels != 1){
    if(millis() - last_receiver_communication_time > 1000){
      receiver_failure = true;
    }
    return;
  }else{
    last_receiver_communication_time = millis();
    receiver_failure = false;
  }

  sbus.UpdateServos();
  sbus.UpdateChannels();
  sbus.toChannels = 0;

  rollRaw = constrain(sbus.channels[0], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  pitchRaw = constrain(sbus.channels[1], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  throttleRaw = constrain(sbus.channels[2], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  yawRaw = centralize(constrain(sbus.channels[3], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE));
}

//prevent small receiver value changes to affect yaw while joystick is in the center
int centralize(int val) {
  int center = (MAX_RAW_RECEIVER_VALUE + MIN_RAW_RECEIVER_VALUE) / 2;
  int tolerance = 10;
  if (abs(val - center) <= tolerance)
    return center;
  else
    return val;
}
