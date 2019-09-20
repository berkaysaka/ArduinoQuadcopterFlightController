FUTABA_SBUS sbus;

void initializeReceiver() {
  sbus.begin();
}

void readReceiverValues() {
  sbus.FeedLine();
  if (sbus.toChannels != 1)
    return;

  sbus.UpdateServos();
  sbus.UpdateChannels();
  sbus.toChannels = 0;

  rollRaw = constrain(sbus.channels[0], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  pitchRaw = constrain(sbus.channels[1], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  throttleRaw = constrain(sbus.channels[2], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE);
  yawRaw = centralize(constrain(sbus.channels[3], MIN_RAW_RECEIVER_VALUE, MAX_RAW_RECEIVER_VALUE));  //prevent small moves while in center to change yaw
}

int centralize(int val){
  int center = (MAX_RAW_RECEIVER_VALUE + MIN_RAW_RECEIVER_VALUE) / 2;
  int tolerance = 6;
  if(abs(val - center) <= tolerance)
    return center;
  else
    return val;
}
