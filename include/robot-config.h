using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LBmotor;
extern motor LFmotor;
extern motor RBmotor;
extern motor RFmotor;
extern motor RackLift;
extern motor ArmLift;
extern motor L_Intake;
extern motor R_Intake;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
