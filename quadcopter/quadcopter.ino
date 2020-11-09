// average flight time is 13 minutes with 10x5 props, 3000 mAh 3S lipo battery
//----------- ADDITIONAL MODES ---------------
#define TELEMETRY_ENABLED false
#define REMOTE_PID_CONFIG_ENABLED false

//----------- PINS -----------
#define FRONT_LEFT_MOTOR_PIN 4
#define FRONT_RIGHT_MOTOR_PIN 6
#define REAR_LEFT_MOTOR_PIN 5
#define REAR_RIGHT_MOTOR_PIN 7
#define LED_PIN 13
#define BUZZER_PIN 12
#define INTERRUPT_PIN 2

//----------- IMU CALIBRATION -----------
#define GYRO_OFFSET_X 91
#define GYRO_OFFSET_Y -92
#define GYRO_OFFSET_Z 38
#define ACCEL_OFFSET_X 182
#define ACCEL_OFFSET_Y 1620
#define ACCEL_OFFSET_Z 397

//----------- RECEIVER & TRANSMITTER -----------
#define RECEIVER_MIN_VALUE 306
#define RECEIVER_MAX_VALUE 1693
#define TRANSMITTER_JOYSTICK_DEAD_BAND 10
#define TRANSMITTER_ARMING_DURATION_IN_MILLISECONDS 1000
#define TRANSMITTER_ARMING_JOYSTICK_TOLERANCE 30

//----------- ESC's -----------
#define MIN_MOTOR_PULSE_WIDTH 1000
#define MAX_MOTOR_PULSE_WIDTH 2000

//----------- TIMEOUTS -----------
#define IMU_COMMUNICATION_TIMEOUT_IN_MILLISECONDS 100
#define RECEIVER_COMMUNICATION_TIMEOUT_IN_MILLISECONDS 500
#define PROGRAM_STARTUP_TIMEOUT WDTO_1S // Watch Dog Timer parameter
#define PROGRAM_LOOP_TIMEOUT WDTO_120MS // Watch Dog Timer parameter

//----------- LIMITS -----------
#define THROTTLE_START_POINT 20  // between 0-180
#define THROTTLE_LIMIT_POINT 180 // between 0-180
double QUADCOPTER_MAX_TILT_ANGLE = 20.00; // roll, pitch tilt angle limit in degrees
double ANGLE_DEGREE_LIMIT_YAW = 5.00;
double MAX_YAW_CONTROL_GAIN = 20.00;
double MAX_ROLL_PITCH_CONTROL_GAIN = 30.00;

//----------- PID CONFIGURATION-----------
double KP_roll_pitch = 0.25;
double KI_roll_pitch = 0.00001;
double KD_roll_pitch = 70.00;

double KP_yaw = 1.50;
double KI_yaw = 0.10;
double KD_yaw = 0.00;

double YAW_INTEGRAL_LIMIT = 10.00;
double ROLL_PITCH_INTEGRAL_LIMIT = 2.00;
