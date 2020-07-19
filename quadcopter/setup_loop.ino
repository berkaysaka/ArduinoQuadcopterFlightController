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
  wdt_reset();

  syncOutputSignals();
  
  struct RawReceiverValues rawReceiverValues = readReceiverValues();
  struct ReceiverCommands receiverCommands = convertToReceiverCommands(rawReceiverValues);
  struct IMU_Values imu_values = readIMUvalues();
  
  if(rawReceiverValues.ReceiverError || receiverCommands.Throttle < THROTTLE_START_POINT || imu_values.IMU_Error)
  {
    runSafetyProtocol();
    return;
  }
  
  if (imu_values.DataAvailable){
    MotorPowers motorPowers = calculateMotorPowers(receiverCommands, imu_values);
    spinMotors(motorPowers);
  }
    
  sendTelemetryData(receiverCommands, imu_values);
  readRemotePidConfigurationCommand(); 
}

void runSafetyProtocol(){
    struct MotorPowers motorPowers;
    motorPowers.frontLeftMotorPower = MIN_THROTTLE;
    motorPowers.frontRightMotorPower = MIN_THROTTLE;
    motorPowers.rearLeftMotorPower = MIN_THROTTLE;
    motorPowers.rearRightMotorPower = MIN_THROTTLE;
    spinMotors(motorPowers);
   
    roll_pid_i = 0; 
    roll_last_error = 0;
    pitch_pid_i = 0; 
    pitch_last_error = 0;
    yaw_pid_i = 0;
    yaw_last_error = 0;
}
