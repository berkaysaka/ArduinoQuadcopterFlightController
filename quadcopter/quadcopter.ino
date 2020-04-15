//-----------EXECUTION---------------
#define TEST_MODE false
#define DEBUG_MODE false
#define TELEMETRY_ENABLED false

//-----------CONFIGURATION-----------
#define ANGLE_DEGREE_LIMIT_PITCH_ROLL 20
#define ANGLE_DEGREE_LIMIT_YAW 5.0

#define YAW_ANGLE_BOOSTER 2.0

#define MIN_THROTTLE 0
#define MAX_THROTTLE 175
#define THROTTLE_START_POINT 15
#define THROTTLE_LIMIT_POINT 140

#define KP_roll_pitch 0.3
#define KI_roll_pitch 0.001
#define KD_roll_pitch 40.00

#define KP_yaw 2.00
#define KI_yaw 0.05
#define KD_yaw 800.00

#define YAW_INTEGRAL_LIMIT 1.00
#define ROLL_PITCH_INTEGRAL_LIMIT 0.50

#define MAX_ROLL_PITCH_CONTROL_GAIN 30.00
#define MAX_YAW_CONTROL_GAIN 25.00

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

//-----------GLOBAL VARIABLES-----------
int frontLeftMotorPower, frontRightMotorPower, rearLeftMotorPower, rearRightMotorPower;
double pitchAngle, rollAngle, yawAngle;
double prev_pitchAngle, prev_rollAngle, prev_yawAngle;
int throttle;
double desired_roll_angle, desired_pitch_angle, desired_yaw_angle;
int throttleRaw, yawRaw, rollRaw, pitchRaw;
bool receiver_failure = false;
bool fresh_imu_data_available = false;
double roll_control_signal, pitch_control_signal, yaw_control_signal;
