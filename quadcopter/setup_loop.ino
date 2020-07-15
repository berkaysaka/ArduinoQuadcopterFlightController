#include <avr/wdt.h>

void setup() {
  wdt_enable(WDTO_1S);
  
  initializeMotors();
  initializeOutputSignals();
  initializeTelemetry();
  initializeRemotePidConfiguration();
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
    roll_pid_i = 0; 
    roll_last_error = 0;
    pitch_pid_i = 0; 
    pitch_last_error = 0;
    yaw_pid_i = 0;
    yaw_last_error = 0;
  }
}
