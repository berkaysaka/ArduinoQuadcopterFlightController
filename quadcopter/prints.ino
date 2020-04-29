void printRawReceiverValues() {
  Serial.print("throttleRaw=");
  Serial.print(throttleRaw);
  Serial.print("\t");
  Serial.print("yawRaw=");
  Serial.print(yawRaw);
  Serial.print("\t");
  Serial.print("rollRaw=");
  Serial.print(rollRaw);
  Serial.print("\t");
  Serial.print("pitchRaw=");
  Serial.print(pitchRaw);
  Serial.println();
}

void printMotorPowers() {
  Serial.print("frontLeftMotorPower=   ");
  Serial.println(frontLeftMotorPower);
  Serial.print("frontRightMotorPower=  ");
  Serial.println(frontRightMotorPower);
  Serial.print("rearLeftMotorPower=    ");
  Serial.println(rearLeftMotorPower);
  Serial.print("rearRightMotorPower=   ");
  Serial.println(rearRightMotorPower);
}

void printMotorPowersGraph() {
  Serial.print(frontLeftMotorPower);
  Serial.print("\t");
  Serial.print(frontRightMotorPower);
  Serial.println();
}

void printDesiredValues() {
  Serial.print("throttle:");
  Serial.print(throttle);
  Serial.print("\t");
  Serial.print("desired_pitch_angle:");
  Serial.print(desired_pitch_angle);
  Serial.print("\t");
  Serial.print("desired_roll_angle: ");
  Serial.print(desired_roll_angle);
  Serial.print("\t");
  Serial.print("desired_yaw_angle: ");
  Serial.print(desired_yaw_angle);
  Serial.println();
}

void printGyroValues() {
  Serial.print("pitchAngleº: ");
  Serial.print(pitchAngle);
  Serial.print("   |   ");
  Serial.print("rollAngleº: ");
  Serial.print(rollAngle);
  Serial.println(" ");
}

unsigned long _lastTime = millis();
void printGraphGyroValues() {
  long _currentTime = millis();
  if (_currentTime - _lastTime < 10)
    return;
  _lastTime = _currentTime;
  //Serial.print(pitchAngle);
  //Serial.print("\t");
  //Serial.print(rollAngle);
  //Serial.print("\t");
  Serial.print(yawAngle);
  Serial.println();
}

void sendTelemetryInfo() {
  unsigned long _currentTime = millis();
  if (_currentTime - _lastTime < 100)
    return;
  _lastTime = _currentTime;

  Serial2.println(
    String(_currentTime)
    + "\t" + pitchAngle
    + "\t" + rollAngle
    + "\t" + yawAngle
    + "\t" + throttle
    + "\t" + desired_pitch_angle
    + "\t" + desired_roll_angle
    + "\t" + desired_yaw_angle
    + "\t" + pitch_control_signal
    + "\t" + roll_control_signal
    + "\t" + yaw_control_signal
  );
}
#include <avr/wdt.h>
void receivePidCommand()
   {
  if (Serial2.available()) {
    wdt_disable();
    String cmd = "";
    while (Serial2.available()) {
      cmd += Serial2.readString();
    }
    if (cmd.startsWith("<setpid>") && cmd.endsWith("</setpid>")) {
      cmd.replace("<setpid>", "");
      cmd.replace("</setpid>", "");
      double r = 0;
      int t = 0;
      double pidValues[13];
      for (int i = 0; i < cmd.length(); i++)
      {
        if (cmd.charAt(i) == '\t' || i == cmd.length()-1)
        {
          if(i == cmd.length()-1){
            i++;
          }
          double x = cmd.substring(r, i).toDouble();
          pidValues[t] = x;
          r = (i + 1);
          t++;
        }
      }
      KP_roll_pitch = pidValues[0];
      KI_roll_pitch = pidValues[1];
      KD_roll_pitch = pidValues[2];
      KP_yaw = pidValues[3];
      KI_yaw = pidValues[4];
      KD_yaw = pidValues[5];
      YAW_INTEGRAL_LIMIT = pidValues[6];
      ROLL_PITCH_INTEGRAL_LIMIT = pidValues[7];
      MAX_ROLL_PITCH_CONTROL_GAIN = pidValues[8];
      MAX_YAW_CONTROL_GAIN = pidValues[9];
      ANGLE_DEGREE_LIMIT_PITCH_ROLL = pidValues[10];
      ANGLE_DEGREE_LIMIT_YAW = pidValues[11];
      YAW_ANGLE_BOOSTER = pidValues[12];
      
      Serial2.print("<pidconfighasbeenset></pidconfighasbeenset>");
      Serial.println("<pidconfighasbeenset>");
    } else if (cmd.startsWith("<sendmepid>") && cmd.endsWith("</sendmepid>")) {
      Serial2.print(
        String("<pidconfig>")
        + String(KP_roll_pitch)
        + "\t" + String(KI_roll_pitch)
        + "\t" + String(KD_roll_pitch)
        + "\t" + String(KP_yaw)
        + "\t" + String(KI_yaw)
        + "\t" + String(KD_yaw)
        + "\t" + String(YAW_INTEGRAL_LIMIT)
        + "\t" + String(ROLL_PITCH_INTEGRAL_LIMIT)
        + "\t" + String(MAX_ROLL_PITCH_CONTROL_GAIN)
        + "\t" + String(MAX_YAW_CONTROL_GAIN)
        + "\t" + String(ANGLE_DEGREE_LIMIT_PITCH_ROLL)
        + "\t" + String(ANGLE_DEGREE_LIMIT_YAW)
        + "\t" + String(YAW_ANGLE_BOOSTER)
        + String("</pidconfig>")
      );
      Serial.println("<pidconfig>");
    } else {
      Serial.println("unknown pid command:" + cmd);
    }
    wdt_enable(WDTO_60MS);
  }
}
