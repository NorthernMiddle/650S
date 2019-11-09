#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LBmotor = motor(PORT20, ratio18_1, false);
motor LFmotor = motor(PORT19, ratio18_1, false);
motor RBmotor = motor(PORT12, ratio18_1, true);
motor RFmotor = motor(PORT11, ratio18_1, true);
motor RackLift = motor(PORT18, ratio36_1, false);
motor ArmLift = motor(PORT9, ratio36_1, true);
motor L_Intake = motor(PORT1, ratio18_1, false);
motor R_Intake = motor(PORT10, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
