//-----------CONFIGURATION-----------
#define ACCELEROMETER_TRUSTABILITY  0.002
#define ANGLE_DEGREE_LIMIT_PITCH_ROLL 15
#define ANGLE_DEGREE_LIMIT_YAW 2

#define MIN_THROTTLE 0
#define MAX_THROTTLE 140
#define THROTTLE_START_POINT 10

#define KP_roll_pitch 0.50
#define KI_roll_pitch 0.05
#define KD_roll_pitch 0.25

#define KP_yaw 15.0
#define KI_yaw 0.0
#define KD_yaw 0.0

#define YAW_INTEGRAL_LIMIT 2
#define ROLL_PITCH_INTEGRAL_LIMIT 4

#define PID_SAMPLING_FREQUENCY 10 //milliseconds

#define MIN_RAW_RECEIVER_VALUE 300
#define MAX_RAW_RECEIVER_VALUE 1700

#define FRONT_LEFT_MOTOR_PIN 5
#define FRONT_RIGHT_MOTOR_PIN 4
#define REAR_LEFT_MOTOR_PIN 6
#define REAR_RIGHT_MOTOR_PIN 7

#define MIN_MOTOR_PULSE_WIDTH 800
#define MAX_MOTOR_PULSE_WIDTH 2200

//-----------GLOBAL VARIABLES-----------
int frontLeftMotorPower, frontRightMotorPower, rearLeftMotorPower, rearRightMotorPower;
double pitchAngle, rollAngle, yawAngle, yawAnglePrevious;
int throttle;
double desired_roll_angle, desired_pitch_angle, desired_yaw_angle;
int throttleRaw, yawRaw, rollRaw, pitchRaw;
long IMUcalibrationTime;
bool IMUhasBeenCalibrated = false;
