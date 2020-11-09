#include <avr/wdt.h>

void setup() {
  wdt_enable(PROGRAM_STARTUP_TIMEOUT);

  initializeMotors();
  initializeOutputSignals();
  initializeTelemetry();
  initializeRemotePidConfiguration();
  initializeReceiver();
  initializeIMU();

  wdt_disable();
  wdt_enable(PROGRAM_LOOP_TIMEOUT);

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

  if (imu_values.DataAvailable) {
    MotorPowers motorPowers = calculateMotorPowers(receiverCommands, imu_values);
    spinMotors(motorPowers);
  }

  sendTelemetryData(receiverCommands, imu_values);
  readRemotePidConfigurationCommand();
}
