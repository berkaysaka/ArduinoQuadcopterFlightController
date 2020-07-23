#include <FUTABA_SBUS.h>

FUTABA_SBUS sbus;

unsigned long last_receiver_communication_time = 0;
int previousRoll;
int previousPitch;
int previousThrottle;
int previousYaw;

void initializeReceiver() {
  sbus.begin();
}

struct RawReceiverValues readReceiverValues() {
  struct RawReceiverValues r;
  
  sbus.FeedLine();
  if (sbus.toChannels != 1){
    if((millis() - last_receiver_communication_time) > RECEIVER_COMMUNICATION_TIMEOUT_IN_MILLISECONDS){
      r.ReceiverCommunicationError = true; //receiver communication failure  
    }else{
      r.ReceiverCommunicationError = false;
      r.Roll = previousRoll;
      r.Pitch = previousPitch;
      r.Throttle = previousThrottle;
      r.Yaw = previousYaw;
    }
    return r;
  }
  sbus.UpdateServos();
  sbus.UpdateChannels();
  if (sbus.failsafe_status != 0){
    r.ReceiverCommunicationError = true; //transmitter signal lost
    return r;
  }
  sbus.toChannels = 0;
  
  last_receiver_communication_time = millis();
  r.ReceiverCommunicationError = false;

  r.Roll = constrain(sbus.channels[0], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Pitch = constrain(sbus.channels[1], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Throttle = constrain(sbus.channels[2], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  r.Yaw = centralize(constrain(sbus.channels[3], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE));

  previousRoll = r.Roll;
  previousPitch = r.Pitch;
  previousThrottle = r.Throttle;
  previousYaw = r.Yaw;
    
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
