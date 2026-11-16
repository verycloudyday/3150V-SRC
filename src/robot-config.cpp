#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

//A global instance of brain used for printing to the V5 Brain screen
brain Brain;

//VEXcode device constructors
controller Controller1 = controller(primary);

//drivetrain
motor LF = motor(PORT12, ratio6_1, false);
motor LM = motor(PORT4, ratio6_1, true);
motor RF = motor(PORT19, ratio6_1, true);
motor RM = motor(PORT17, ratio6_1, true);
motor LB = motor(PORT11, ratio6_1, false);
motor RB = motor(PORT20, ratio6_1, true);

//lift
motor liftL = motor(PORT13, ratio6_1, true);
motor liftR = motor(PORT18, ratio6_1, true);

//chainbar
motor chainbar = motor(PORT2, ratio18_1, false);

//toggle 
motor Toggle = motor(PORT16, ratio18_1, false);

digital_out Claw = digital_out(Brain.ThreeWirePort.A);

inertial Gyro = inertial(PORT14);

rotation odomWheel = rotation(PORT17);

distance intakeSensor = distance(PORT15); //change later

optical colourToggleRed = optical(PORT1);
optical colourToggleBlue = optical(PORT10);

//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}