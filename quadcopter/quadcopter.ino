//-----------EXECUTION---------------
#define TEST_MODE false

//-----------CONFIGURATION-----------
#define ANGLE_DEGREE_LIMIT_PITCH_ROLL 20
#define ANGLE_DEGREE_LIMIT_YAW 5.0

#define MIN_THROTTLE 0
#define MAX_THROTTLE 175
#define THROTTLE_START_POINT 15
#define THROTTLE_LIMIT_POINT 140

#define KP_roll_pitch 0.3
#define KI_roll_pitch 0.05
#define KD_roll_pitch 90.00

#define KP_yaw 5.00
#define KI_yaw 0.1
#define KD_yaw 800.00

#define YAW_INTEGRAL_ACTIVATION_THRESHOLD 6.00
#define ROLL_PITCH_INTEGRAL_ACTIVATION_THRESHOLD 5.00

#define YAW_INTEGRAL_LIMIT 20.00
#define ROLL_PITCH_INTEGRAL_LIMIT 0.50

#define MAX_ROLL_PITCH_CONTROL_GAIN 30.00
#define MAX_YAW_CONTROL_GAIN 30.00

#define PID_SAMPLING_FREQUENCY 1 //milliseconds

#define MIN_RAW_RECEIVER_VALUE 300
#define MAX_RAW_RECEIVER_VALUE 1700

#define FRONT_LEFT_MOTOR_PIN 7
#define FRONT_RIGHT_MOTOR_PIN 5
#define REAR_LEFT_MOTOR_PIN 6
#define REAR_RIGHT_MOTOR_PIN 4

#define MIN_MOTOR_PULSE_WIDTH 1000
#define MAX_MOTOR_PULSE_WIDTH 2000

#define LED_PIN 13
#define BUZZER_PIN 12

//-----------GLOBAL VARIABLES-----------
int frontLeftMotorPower, frontRightMotorPower, rearLeftMotorPower, rearRightMotorPower;
double pitchAngle, rollAngle, yawAngle;
int throttle;
double desired_roll_angle, desired_pitch_angle, desired_yaw_angle;
int throttleRaw, yawRaw, rollRaw, pitchRaw;
bool receiver_failure = false;
bool fresh_imu_data_available = false;
