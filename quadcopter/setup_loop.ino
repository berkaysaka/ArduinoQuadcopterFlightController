#include <avr/wdt.h>

void setup() {
  wdt_enable(PROGRAM_TIMEOUT_IN_MILLISECONDS);

  initializeMotors();
  initializeOutputSignals();
  initializeTelemetry();
  initializeRemotePidConfiguration();
  initializeReceiver();
  initializeIMU();
  
  quadcopter_initialization_completed();
}

void loop() {
  wdt_reset();
  syncOutputSignals();
  
  struct ReceiverCommands receiverCommands = GetReceiverCommands();
  struct IMU_Values imu_values = readIMUvalues();

  if (receiverCommands.Error || receiverCommands.Throttle < THROTTLE_START_POINT || !receiverCommands.Armed || imu_values.Error)
  {
    stopMotors();
    resetPidVariables();
    return;
  }

  if (imu_values.NewDataAvailable) {
    MotorPowers motorPowers = calculateMotorPowers(receiverCommands, imu_values);
    spinMotors(motorPowers);
  }

  sendTelemetryData(receiverCommands, imu_values);
  readRemotePidConfigurationCommand();
}
