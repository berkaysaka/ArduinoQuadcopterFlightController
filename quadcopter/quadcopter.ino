// average flight time is 13 minutes with 10x5 props, 3000 mAh 3S lipo battery
//-----------EXECUTION MODES---------------
#define TELEMETRY_ENABLED false
#define REMOTE_PID_CONFIG_ENABLED false

//----------- HARDWARE CONFIGURATION-----------
#define MIN_THROTTLE 0
#define MAX_THROTTLE 180
#define THROTTLE_START_POINT 15
#define THROTTLE_LIMIT_POINT 150

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
double KI_roll_pitch = 0.00001;
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
double roll_control_signal, pitch_control_signal, yaw_control_signal;
double roll_pid_i, roll_last_error, pitch_pid_i, pitch_last_error, yaw_pid_i, yaw_last_error;
