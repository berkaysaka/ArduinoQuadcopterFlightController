#include <avr/wdt.h>

void initializeRemotePidConfiguration(){
  if (REMOTE_PID_CONFIG_ENABLED == false) 
    return;

  if (Serial2) //if Serial2 already ready, do nothing
    return;
   
  Serial2.begin(9600);
  while(!Serial2){} // wait for Serial2 port to be ready
}

void readRemotePidConfigurationCommand()
{
  if (REMOTE_PID_CONFIG_ENABLED == false)
    return;
    
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
      double pidValues[12];
      for (int i = 0; i < cmd.length(); i++)
      {
        if (cmd.charAt(i) == '\t' || i == cmd.length() - 1)
        {
          if (i == cmd.length() - 1) {
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

      Serial2.print("<pidconfighasbeenset></pidconfighasbeenset>");
      Serial.println("<pidconfighasbeenset>");
    } else if (cmd.startsWith("<sendmepid>") && cmd.endsWith("</sendmepid>")) {
      Serial2.print(
        String("<pidconfig>")
        + String(KP_roll_pitch)
        + "\t" + String(KI_roll_pitch, 6)
        + "\t" + String(KD_roll_pitch)
        + "\t" + String(KP_yaw)
        + "\t" + String(KI_yaw, 6)
        + "\t" + String(KD_yaw)
        + "\t" + String(YAW_INTEGRAL_LIMIT)
        + "\t" + String(ROLL_PITCH_INTEGRAL_LIMIT)
        + "\t" + String(MAX_ROLL_PITCH_CONTROL_GAIN)
        + "\t" + String(MAX_YAW_CONTROL_GAIN)
        + "\t" + String(ANGLE_DEGREE_LIMIT_PITCH_ROLL)
        + "\t" + String(ANGLE_DEGREE_LIMIT_YAW)
        + String("</pidconfig>")
      );
      Serial.println("<pidconfig>");
    } else {
      Serial.println("unknown pid command:" + cmd);
    }
    wdt_enable(PROGRAM_LOOP_TIMEOUT);
  }
}
