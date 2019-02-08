#include "robot-config.h"

/*++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++
NMS PROGRAM TEAM  2018-19 VRC TURNING POINT
650S -- RED 01 AUTONOMOUS

Robot Configuration:
[Smart Port]    [Name]          [Type]              [Description]                   [Reversed]
Motor Port 20   FRmotor         V5 Smart Motor      Right Front Drive Motor         false
Motor Port 11   BRmotor         V5 Smart Motor      Right Back Drive Motor          false
Motor Port 1    FLmotor         V5 Smart Motor      Left Front Drive Motor          false
Motor Port 3    BLmotor         V5 Smart Motor      Left Back Drive Motor           false
Motor Port 5    ARMmotor        V5 Smart Motor      Arm Motor                       false
Motor Port 2    Spinnermotor    V5 Smart Motor      Spinner Ball Collector Motor    false
Motor Port 6    Punchermotor    V5 Smart Motor      Puncher (Shooter) Motor         false
-----------------------------------------------------------------------------------------------*/

//spinner on L2

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

//Creates variables to be used in autonomous program
int autonArmSpeedPCT = 50;
int autonDriveMotorSpeedPCT = 55;
int autonPuncherMotorSpeedPCT = 200;
int autonSpinnerSpeedPCT = 40;

//Creates variables to be used in driver program
int driverArmSpeedPCT = 50;
int driverPuncherMotorSpeedPCT = 100;
int driverSpinnerSpeedPCT = 40;

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

void arm_func(){
     //arm motor commands
    if(Controller1.ButtonR1.pressing())
    {
      ARMmotor.spin(vex::directionType::rev, autonArmSpeedPCT, vex::velocityUnits::pct);
    }

    else if(Controller1.ButtonR2.pressing())
    {
      ARMmotor.spin(vex::directionType::fwd, autonArmSpeedPCT, vex::velocityUnits::pct);
    }
    else
    {
      ARMmotor.stop(vex::brakeType::brake);
    }
}

void drive_func(){
    //Drive Controls
    //Set the left and right motor to spin fwd/rev using the controller Axis as values as teh velocity value
    BLmotor.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    BRmotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    FLmotor.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    FRmotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
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
    Punchermotor.startRotateFor(-4.2,rotationUnits::rev);
}

void driverPuncher_func(){
    if(Controller1.ButtonL1.pressing()){
        Punchermotor.spin(vex::directionType::rev,driverPuncherMotorSpeedPCT, vex::velocityUnits::pct);
    }
    else{Punchermotor.stop(vex::brakeType::brake);}
    }

void driverSpinner_func(){
    if(Controller1.ButtonL2.pressing()){
        Spinnermotor.spin(vex::directionType::rev,driverSpinnerSpeedPCT, vex::velocityUnits::pct);
    }
    else{Spinnermotor.stop(vex::brakeType::coast);}
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
    Brain.Screen.print("User Control Has Started");//Display that the program has started to the screen
    drive_func(); //drive motor controls  
    arm_func();//arm motor control
    driverPuncher_func();//puncher motor control
    driverSpinner_func();//spinner motor control
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


    










