// average flight time is 13 minutes
//-----------EXECUTION MODES---------------
#define TELEMETRY_ENABLED false
#define REMOTE_PID_CONFIG_ENABLED false

//----------- HARDWARE CONFIGURATION-----------
#define MIN_THROTTLE 0
#define MAX_THROTTLE 175
#define THROTTLE_START_POINT 15
#define THROTTLE_LIMIT_POINT 140

#define MIN_RAW_RECEIVER_VALUE 300
#define MAX_RAW_RECEIVER_VALUE 1700

#define FRONT_LEFT_MOTOR_PIN 4
#define FRONT_RIGHT_MOTOR_PIN 6
#define REAR_LEFT_MOTOR_PIN 5
#define REAR_RIGHT_MOTOR_PIN 7

#define MIN_MOTOR_PULSE_WIDTH 1000
#define MAX_MOTOR_PULSE_WIDTH 2000

#define LED_PIN 13
#define BUZZER_PIN 12

//----------- PID CONFIGURATION-----------
double KP_roll_pitch = 0.25;
double KI_roll_pitch = 0.00005;
double KD_roll_pitch = 70.00;

double KP_yaw = 1.50;
double KI_yaw = 0.10;
double KD_yaw = 0.00;

double YAW_INTEGRAL_LIMIT = 10.00;
double MAX_YAW_CONTROL_GAIN = 20.00;

double ROLL_PITCH_INTEGRAL_LIMIT = 2.00;
double MAX_ROLL_PITCH_CONTROL_GAIN = 30.00;

double ANGLE_DEGREE_LIMIT_PITCH_ROLL = 20.00;
double ANGLE_DEGREE_LIMIT_YAW = 5.00;

//-----------GLOBAL VARIABLES-----------
int frontLeftMotorPower, frontRightMotorPower, rearLeftMotorPower, rearRightMotorPower;
double pitchAngle, rollAngle, yawAngle;
double prev_pitchAngle, prev_rollAngle, prev_yawAngle;
int throttle;
double desired_roll_angle, desired_pitch_angle, desired_yaw_angle_change;
int throttleRaw, yawRaw, rollRaw, pitchRaw;
bool receiverYawIsOnCenter;
bool receiver_failure = false;
bool imu_failure = false;
double roll_control_signal, pitch_control_signal, yaw_control_signal;
int delta_time;
