#include <FUTABA_SBUS.h>

FUTABA_SBUS sBus;

struct ReceiverCommands prevReceiverCommands;
bool armed = false;
unsigned long receiver_last_communication_time = millis();

void initializeReceiver() {
  sBus.begin();
}

struct ReceiverCommands GetReceiverCommands() {
  struct ReceiverRawValues receiverRawValues = getReceiverRawValues();
  if (receiverRawValues.TransmitterCommunicationFailure) {
    return getFailureReceiverCommand();
  }

  if (receiverRawValues.NewDataAvailable) {
    receiver_last_communication_time = millis();

    struct ReceiverCommands cmd;
    cmd.RollAngle = map_double(receiverRawValues.ChannelValues[0], TRANSMITTER_JOYSTICK_MIN_VALUE, TRANSMITTER_JOYSTICK_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.PitchAngle = map_double(receiverRawValues.ChannelValues[1], TRANSMITTER_JOYSTICK_MIN_VALUE, TRANSMITTER_JOYSTICK_MAX_VALUE, -QUADCOPTER_MAX_TILT_ANGLE, QUADCOPTER_MAX_TILT_ANGLE);
    cmd.Throttle = map_double(receiverRawValues.ChannelValues[2], TRANSMITTER_JOYSTICK_MIN_VALUE, TRANSMITTER_JOYSTICK_MAX_VALUE, 0, THROTTLE_LIMIT_POINT);
    cmd.YawAngleChange = map_double(ignoreDeadBand(receiverRawValues.ChannelValues[3]), TRANSMITTER_JOYSTICK_MIN_VALUE, TRANSMITTER_JOYSTICK_MAX_VALUE, -QUADCOPTER_MAX_YAW_ANGLE_CHANGE_PER_SECOND, QUADCOPTER_MAX_YAW_ANGLE_CHANGE_PER_SECOND);
    cmd.Armed = getArmStatus(receiverRawValues);
    cmd.Error = false;

    prevReceiverCommands = cmd;
    return cmd;
  } else if (millis() - RECEIVER_COMMUNICATION_TIMEOUT_IN_MILLISECONDS > receiver_last_communication_time) {
    return getFailureReceiverCommand();
  } else {
    return prevReceiverCommands;
  }
}

struct ReceiverCommands getFailureReceiverCommand() {
  struct ReceiverCommands cmd;
  cmd.Error = true;
  return cmd;
}

//prevent small receiver value changes to affect yaw while joystick is on the center
int ignoreDeadBand(int val) {
  int center = (TRANSMITTER_JOYSTICK_MIN_VALUE + TRANSMITTER_JOYSTICK_MAX_VALUE) / 2;
  if (abs(val - center) <= TRANSMITTER_JOYSTICK_DEAD_BAND)
    return center;
  else
    return val;
}


struct ReceiverRawValues getReceiverRawValues() {
  struct ReceiverRawValues v;
  v.NewDataAvailable = false;
  v.TransmitterCommunicationFailure = false;

  sBus.FeedLine();
  if (sBus.toChannels == 1) {
    sBus.UpdateServos();
    sBus.UpdateChannels();

    v.NewDataAvailable = true;
    if (sBus.Failsafe() != 0) {
      v.TransmitterCommunicationFailure = true;
      return v;
    }

    sBus.toChannels = 0;
    int i = 0;
    for (int16_t channelValue : sBus.channels) {
      v.ChannelValues[i] = channelValue;
      i++;
    }
  }

  return v;
}

bool hasArmingStarted = false;
bool hasDisarmingStarted = false;
unsigned long armingStartTime;
unsigned long disarmingStartTime;

bool getArmStatus(ReceiverRawValues rawValues) {
  if (!rawValues.NewDataAvailable || rawValues.TransmitterCommunicationFailure) {
    return armed;
  }

  if (isArming(rawValues) && !armed) {
    hasDisarmingStarted = false;
    if (!hasArmingStarted) {
      armingStartTime = millis();
      hasArmingStarted = true;
    } else {
      if (millis() - armingStartTime >= TRANSMITTER_ARMING_DURATION_IN_MILLISECONDS) {
        armed = true;
        quadcopter_armed();
      }
    }
  } else if (isDisarming(rawValues) && armed) {
    hasArmingStarted = false;
    if (!hasDisarmingStarted) {
      disarmingStartTime = millis();
      hasDisarmingStarted = true;
    } else {
      if (millis() - disarmingStartTime >= TRANSMITTER_ARMING_DURATION_IN_MILLISECONDS) {
        armed = false;
        quadcopter_disarmed();
      }
    }
  } else {
    hasArmingStarted = false;
    hasDisarmingStarted = false;
  }

  return armed;
}

bool isArming(ReceiverRawValues rawValues) {
  if (isThrottleStickPositonAtFullDown(rawValues) && isYawStickPositionAtFullRight(rawValues)) {
    return true;
  }
  return false;
}

bool isDisarming(ReceiverRawValues rawValues) {
  if (isThrottleStickPositonAtFullDown(rawValues) && isYawStickPositionAtFullLeft(rawValues)) {
    return true;
  }
  return false;
}

bool isThrottleStickPositonAtFullDown(ReceiverRawValues rawValues) {
  if (abs(rawValues.ChannelValues[2] - TRANSMITTER_JOYSTICK_MIN_VALUE) < TRANSMITTER_ARMING_JOYSTICK_TOLERANCE) {
    return true;
  }
  return false;
}

bool isYawStickPositionAtFullLeft(ReceiverRawValues rawValues) {
  if (abs(rawValues.ChannelValues[3] - TRANSMITTER_JOYSTICK_MIN_VALUE) < TRANSMITTER_ARMING_JOYSTICK_TOLERANCE) {
    return true;
  }
  return false;
}

bool isYawStickPositionAtFullRight(ReceiverRawValues rawValues) {
  if (abs(rawValues.ChannelValues[3] - TRANSMITTER_JOYSTICK_MAX_VALUE) < TRANSMITTER_ARMING_JOYSTICK_TOLERANCE) {
    return true;
  }
  return false;
}

double map_double(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
