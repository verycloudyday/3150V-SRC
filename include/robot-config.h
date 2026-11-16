using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LF;
extern motor RF;
extern motor LB;
extern motor RB;
extern motor Roller;
extern motor liftL;
extern motor liftR;

extern motor chainbar;

extern motor Toggle;

extern digital_out Claw;
extern motor intake;

extern digital_out pToggle;

extern digital_out Pistake;
extern motor PU;
extern inertial Gyro;
extern rotation odomWheel;

extern distance intakeSensor;
extern distance backSensor;

extern optical colourToggleRed;
extern optical colourToggleBlue;

extern const double wheelDiam;
extern const double wheelToMotorRatio;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );