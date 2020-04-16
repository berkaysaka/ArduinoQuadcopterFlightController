#include <avr/wdt.h>

void setup() {
  wdt_enable(WDTO_1S);
  if (TEST_MODE == true) {
    Serial.begin(115200);
    run_tests();
    return;
  } else if (DEBUG_MODE == true) {
    Serial.begin(2000000);
  }
  if (TELEMETRY_ENABLED == true) {
    Serial2.begin(38400);
  }
  //Serial.begin(115200);
  initializeOutputSignals();
  initializeMotors();
  initializeReceiver();
  initializeIMU();

  wdt_disable();
  wdt_enable(WDTO_30MS);
}


void loop() {
  if (TEST_MODE == true) {
    return;
  } else if (DEBUG_MODE == true) {
    debug_loop();
  } else {
    release_loop();
  }
}

void release_loop() {
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
  wdt_reset();
}

void applySafetyRules(){
  if (throttle < THROTTLE_START_POINT || receiver_failure == true || imu_failure == true){
    frontLeftMotorPower = MIN_THROTTLE;
    frontRightMotorPower = MIN_THROTTLE;
    rearLeftMotorPower = MIN_THROTTLE;
    rearRightMotorPower = MIN_THROTTLE;
    desired_yaw_angle = yawAngle;
    desired_pitch_angle = 0;
    desired_roll_angle = 0;
  }
  if(imu_failure == true){
    Serial.println("imu_failure");
  }
}


long diff;
unsigned long currentMicros;
unsigned long looptime = micros();
long totallooptime = 0; long minlooptime = 99999999; long maxlooptime = 0;
long totalreadReceiverValues = 0; long minreadReceiverValues = 99999999; long maxreadReceiverValues = 0;
long totalcalculateDesiredValuesWithSafetyChecks = 0; long mincalculateDesiredValuesWithSafetyChecks = 99999999; long maxcalculateDesiredValuesWithSafetyChecks = 0;
long totalreadIMUvalues = 0; long minreadIMUvalues = 99999999; long maxreadIMUvalues = 0;
long totalcalculateMotorPowers = 0; long mincalculateMotorPowers = 99999999; long maxcalculateMotorPowers = 0;
long totalspinMotors = 0; long minspinMotors = 99999999; long maxspinMotors = 0;
long totalsendTelemetryInfo = 0; long minsendTelemetryInfo = 99999999; long maxsendTelemetryInfo = 0;
int counter = 0;

void debug_loop() {
  counter++;

  currentMicros = micros();
  diff = currentMicros - looptime;
  totallooptime += diff;
  if (diff != 0 && diff < minlooptime)
    minlooptime = diff;
  if (diff != 0 && diff > maxlooptime)
    maxlooptime = diff;

  looptime = currentMicros;
  unsigned long debugtime = currentMicros;

  readReceiverValues();
  currentMicros = micros();
  diff = currentMicros - debugtime;
  if (diff != 0 && diff < minreadReceiverValues)
    minreadReceiverValues = diff;
  if (diff != 0 && diff > maxreadReceiverValues)
    maxreadReceiverValues = diff;
  totalreadReceiverValues += diff;
  debugtime = currentMicros;

  calculateDesiredOrientation();
  currentMicros = micros();
  diff = currentMicros - debugtime;
  if (diff != 0 && diff < mincalculateDesiredValuesWithSafetyChecks)
    mincalculateDesiredValuesWithSafetyChecks = diff;
  if (diff != 0 && diff > maxcalculateDesiredValuesWithSafetyChecks)
    maxcalculateDesiredValuesWithSafetyChecks = diff;
  totalcalculateDesiredValuesWithSafetyChecks += diff;
  debugtime = currentMicros;

  readIMUvalues();
  currentMicros = micros();
  diff = currentMicros - debugtime;
  if (diff != 0 && diff < minreadIMUvalues)
    minreadIMUvalues = diff;
  if (diff != 0 && diff > maxreadIMUvalues)
    maxreadIMUvalues = diff;
  totalreadIMUvalues += diff;
  debugtime = currentMicros;

  calculateMotorPowers();
  currentMicros = micros();
  diff = currentMicros - debugtime;
  if (diff != 0 && diff < mincalculateMotorPowers)
    mincalculateMotorPowers = diff;
  if (diff != 0 && diff > maxcalculateMotorPowers)
    maxcalculateMotorPowers = diff;
  totalcalculateMotorPowers += diff;

  debugtime = currentMicros;
  applySafetyRules();
  spinMotors();
  currentMicros = micros();
  diff = currentMicros - debugtime;
  if (diff != 0 && diff < minspinMotors)
    minspinMotors = diff;
  if (diff != 0 && diff > maxspinMotors)
    maxspinMotors = diff;
  totalspinMotors += diff;
  debugtime = currentMicros;

  if (TELEMETRY_ENABLED == true) {
    sendTelemetryInfo();
    currentMicros = micros();
    diff = currentMicros - debugtime;
    if (diff != 0 && diff < minsendTelemetryInfo)
      minsendTelemetryInfo = diff;
    if (diff != 0 && diff > maxsendTelemetryInfo)
      maxsendTelemetryInfo = diff;
    totalsendTelemetryInfo += diff;
  }

  if (counter < 1001)
    return;

  Serial.println("-readReceiverValues-" + String(totalreadReceiverValues / counter) + "-" + String(minreadReceiverValues) + "-" + String(maxreadReceiverValues));
  Serial.println("-calculateDesiredValuesWithSafetyChecks-" + String(totalcalculateDesiredValuesWithSafetyChecks / counter) + "-" + String(mincalculateDesiredValuesWithSafetyChecks) + "-" + String(maxcalculateDesiredValuesWithSafetyChecks));
  Serial.println("-readIMUvalues-" + String(totalreadIMUvalues / counter) + "-" + String(minreadIMUvalues) + "-" + String(maxreadIMUvalues));
  Serial.println("-calculateMotorPowers-" + String(totalcalculateMotorPowers / counter) + "-" + String(mincalculateMotorPowers) + "-" + String(maxcalculateMotorPowers));
  Serial.println("-spinMotors-" + String(totalspinMotors / counter) + "-" + String(minspinMotors) + "-" + String(maxspinMotors));
  Serial.println("-sendTelemetryInfo-" + String(totalsendTelemetryInfo / counter) + "-" + String(minsendTelemetryInfo) + "-" + String(maxsendTelemetryInfo));
  Serial.println("----------looptime-" + String(totallooptime / counter) + "-" + String(minlooptime) + "-" + String(maxlooptime));

  counter = 0;
  totallooptime = 0; minlooptime = 99999999; maxlooptime = 0;
  totalreadReceiverValues = 0; minreadReceiverValues = 99999999; maxreadReceiverValues = 0;
  totalcalculateDesiredValuesWithSafetyChecks = 0; mincalculateDesiredValuesWithSafetyChecks = 99999999; maxcalculateDesiredValuesWithSafetyChecks = 0;
  totalreadIMUvalues = 0; minreadIMUvalues = 99999999; maxreadIMUvalues = 0;
  totalcalculateMotorPowers = 0; mincalculateMotorPowers = 99999999; maxcalculateMotorPowers = 0;
  totalspinMotors = 0; minspinMotors = 99999999; maxspinMotors = 0;
  totalsendTelemetryInfo = 0; minsendTelemetryInfo = 99999999; maxsendTelemetryInfo = 0;
}
