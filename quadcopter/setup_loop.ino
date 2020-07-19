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

struct Orientation previousOrientation;
struct Orientation actualOrientation;
unsigned long last_time; 

void loop() {
  wdt_reset();
  
  unsigned long current_time = millis();
  int delta_time = current_time - last_time;
  
  syncOutputSignals();
  
  struct RawReceiverValues rawReceiverValues = readReceiverValues();
  struct ReceiverCommands receiverCommands = convertToReceiverCommands(rawReceiverValues);
  struct IMU_Values imu_values = readIMUvalues();
  
  if(rawReceiverValues.ReceiverError || receiverCommands.Throttle < THROTTLE_START_POINT || imu_values.IMU_Error)
  {
    runSafetyProtocol(current_time);
    return;
  }
  
  if (imu_values.DataAvailable){
    previousOrientation = actualOrientation;
    actualOrientation = imu_values.Orientation;
    MotorPowers motorPowers = calculateMotorPowers(receiverCommands, previousOrientation, actualOrientation, delta_time);
    spinMotors(motorPowers);
  }
  
  sendTelemetryData(receiverCommands, actualOrientation);
  readRemotePidConfigurationCommand();

  last_time = current_time;
}

void runSafetyProtocol(unsigned long current_time){
    struct MotorPowers motorPowers;
    motorPowers.frontLeftMotorPower = MIN_THROTTLE;
    motorPowers.frontRightMotorPower = MIN_THROTTLE;
    motorPowers.rearLeftMotorPower = MIN_THROTTLE;
    motorPowers.rearRightMotorPower = MIN_THROTTLE;
    spinMotors(motorPowers);

    last_time = current_time;
    
    roll_pid_i = 0; 
    roll_last_error = 0;
    pitch_pid_i = 0; 
    pitch_last_error = 0;
    yaw_pid_i = 0;
    yaw_last_error = 0;
}
