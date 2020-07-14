#include <avr/wdt.h>

void setup() {
  if (TELEMETRY_ENABLED == true || REMOTE_PID_CONFIG_ENABLED == true) {
    Serial2.begin(9600);
  }
  wdt_enable(WDTO_1S);
  initializeOutputSignals();
  initializeMotors();
  initializeReceiver();
  initializeIMU();

  wdt_disable();
  wdt_enable(WDTO_60MS);
}

void loop() {
  syncOutputSignals();
  readReceiverValues();
  calculateDesiredOrientation();
  readIMUvalues();
  calculateMotorPowers();
  applySafetyRules();
  spinMotors();
  if (TELEMETRY_ENABLED == true) {
    sendTelemetryInfo();
  }
  if (REMOTE_PID_CONFIG_ENABLED == true) {
    receivePidCommand();
  }
  wdt_reset();
}

void applySafetyRules(){
  if (throttle < THROTTLE_START_POINT || receiver_failure == true || imu_failure == true){
    frontLeftMotorPower = MIN_THROTTLE;
    frontRightMotorPower = MIN_THROTTLE;
    rearLeftMotorPower = MIN_THROTTLE;
    rearRightMotorPower = MIN_THROTTLE;
    desired_yaw_angle_change = 0;
    desired_pitch_angle = 0;
    desired_roll_angle = 0;
  }
}
