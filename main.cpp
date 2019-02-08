#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Program Variables                                     */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates variables to be used in program
//arm speed variable
int armSpeedPCT = 50;
int autonDriveMotorSpeedPCT = 55;
int autonPuncherMotorSpeedPCT = 200;
//int spinnerSpeedPCT = 50;

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: User Functions                                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/

void clearEncoders_func(){
    //reset motor encoders to zero
    FLmotor.resetRotation();
    BLmotor.resetRotation();
    FRmotor.resetRotation();
    BRmotor.resetRotation();
    }

void autonSetMotorVelocity_func(){
    //Set the velocity of the left and right motors to 55% power. 
    //This command will not make the motor spin.
    FLmotor.setVelocity(autonDriveMotorSpeedPCT, velocityUnits::pct);
    BLmotor.setVelocity(autonDriveMotorSpeedPCT, velocityUnits::pct);
    FRmotor.setVelocity(autonDriveMotorSpeedPCT, velocityUnits::pct);
    BRmotor.setVelocity(autonDriveMotorSpeedPCT, velocityUnits::pct);
    }

void autonPuncher_func(){
    if(Controller1.ButtonL1.pressing()){
        Puncher.spin(vex::directionType::fwd,autonPuncherMotorSpeedPCT, vex::velocityUnits::pct);
    }
    else{Puncher.stop(vex::brakeType::brake);}
    }

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  clearEncoders_func();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
    autonSetMotorVelocity_func();
    //---- RED TILE #1: R1 SHORT--SHOOT & PARK
    
    //Display that the program has started to the screen
    Brain.Screen.print("AutonR1 SHORT--SHOOT & PARK HAS STARTED");
    
    //shoot ball 
    
    //go forward into flag
    FLmotor.startRotateFor(4.2,rotationUnits::rev);
    BLmotor.startRotateFor(4.2,rotationUnits::rev);
    FRmotor.startRotateFor(-4.2,rotationUnits::rev);
    BRmotor.startRotateFor(-4.2,rotationUnits::rev);
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {}
    
    FLmotor.stop(brakeType::brake);
    BLmotor.stop(brakeType::brake);
    FRmotor.stop(brakeType::brake);
    BRmotor.stop(brakeType::brake);
    
    vex::task::sleep(1000); 
    
    //back up to gray tile in front of red platform
    FLmotor.startRotateFor(-5.6,rotationUnits::rev);
    BLmotor.startRotateFor(-5.6,rotationUnits::rev);
    FRmotor.startRotateFor(5.6,rotationUnits::rev);
    BRmotor.startRotateFor(5.6,rotationUnits::rev);
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {}
    
    FLmotor.stop(brakeType::brake);
    BLmotor.stop(brakeType::brake);
    FRmotor.stop(brakeType::brake);
    BRmotor.stop(brakeType::brake); 
    
    vex::task::sleep(1000); 
    
    
    //turn right
    FLmotor.startRotateFor(-1.5,rotationUnits::rev);
    BLmotor.startRotateFor(-1.5,rotationUnits::rev);
    while(FLmotor.isSpinning()||BLmotor.isSpinning())
    {}
    
    //go forward up on red platform
    FLmotor.startRotateFor(-2,rotationUnits::rev);
    BLmotor.startRotateFor(-2,rotationUnits::rev);
    FRmotor.startRotateFor(-2,rotationUnits::rev);
    BLmotor.startRotateFor(-2,rotationUnits::rev);
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {}
  }

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1)
  {
    //Display that the program has started to the screen
    Brain.Screen.print("User Control Has Started");

    //Drive Controls
    //Set the left and right motor to spin fwd/rev using the controller Axis as values as teh velocity value
    BLmotor.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    BRmotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    FLmotor.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    FRmotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);

    //arm motor commands
    if(Controller1.ButtonR1.pressing())
    {
      Arm.spin(vex::directionType::rev, armSpeedPCT, vex::velocityUnits::pct);
    }

    else if(Controller1.ButtonR2.pressing())
    {
      Arm.spin(vex::directionType::fwd, armSpeedPCT, vex::velocityUnits::pct);
    }
    else
    {
      Arm.stop(vex::brakeType::brake);
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

    //Run the pre-autonomous function.
    pre_auton();

    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
}
