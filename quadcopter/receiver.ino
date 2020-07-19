#include <FUTABA_SBUS.h>

FUTABA_SBUS sbus;
unsigned long last_receiver_communication_time = millis();

void initializeReceiver() {
  sbus.begin();
}

struct RawReceiverValues readReceiverValues() {
  struct RawReceiverValues r;
  
  sbus.FeedLine();
  if (sbus.toChannels != 1){
    if(millis() - last_receiver_communication_time > RECEIVER_COMMUNICATION_TIMEOUT_IN_MILLISECONDS){
      r.ReceiverError = true;
    }
    return;
  }else{
    last_receiver_communication_time = millis();
    r.ReceiverError = false;
  }

  sbus.UpdateServos();
  sbus.UpdateChannels();
  sbus.toChannels = 0;
  
  r.Roll = constrain(sbus.channels[0], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Pitch = constrain(sbus.channels[1], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Throttle = constrain(sbus.channels[2], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Yaw = centralize(constrain(sbus.channels[3], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE));
  return r;
}

//prevent small receiver value changes to affect yaw while joystick is on the center
int centralize(int val) {
  int center = (MAX_RAW_RECEIVER_VALUE + MIN_RAW_RECEIVER_VALUE) / 2;
  if (abs(val - center) <= RECEIVER_DEAD_BAND)
    return center;
  else
    return val;
}
