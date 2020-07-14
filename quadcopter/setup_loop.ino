#include <avr/wdt.h>

void setup() {
  wdt_enable(WDTO_1S);
  
  initializeMotors();
  initializeTelemetry();
  initializeRemotePidConfiguration();
  initializeOutputSignals();  
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
  
  sendTelemetryData();
  readRemotePidConfigurationCommand();
  
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
