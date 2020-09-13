void setup() {
  initializeIMU();
  Serial.begin(115200);
}

void loop() {
  struct Orientation o = getIMUOrientation();

  Serial.print("Error:");
  Serial.print(o.Error);
  Serial.print(",");

  Serial.print("Yaw:");
  Serial.print(o.Yaw);
  Serial.print(",");

  Serial.print("Pitch:");
  Serial.print(o.Pitch);
  Serial.print(",");

  Serial.print("Roll:");
  Serial.print(o.Roll);
  Serial.println();

  delay(50);
}
