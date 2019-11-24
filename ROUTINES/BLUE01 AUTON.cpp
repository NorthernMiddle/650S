#include "robot-config.h"

/*++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++
NMS PROGRAM TEAM  2018-19 VRC TURNING POINT
650S -- Blue 01 AUTONOMOUS

Robot Configuration:
[Smart Port]    [Name]          [Type]              [Description]                   [Reversed]
Smart Port 20   FRmotor         V5 Smart Motor      Right Front Drive Motor         false
Smart Port 11   BRmotor         V5 Smart Motor      Right Back Drive Motor          false
Smart Port 1    FLmotor         V5 Smart Motor      Left Front Drive Motor          false
Smart Port 3    BLmotor         V5 Smart Motor      Left Back Drive Motor           false
Smart Port 5    ARMmotor        V5 Smart Motor      Arm Motor                       false
Smart Port 2    Spinnermotor    V5 Smart Motor      Spinner Ball Collector Motor    false
Smart Port 6    Punchermotor    V5 Smart Motor      Puncher (Shooter) Motor         false
Smart Port 21   Wireless Radio  V5 Wireless Radio   V5 Wireless Radio

-----------------------------------------------------------------------------------------------*/


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



//Creates variables to be used in PID drive control
int wheelCirc = 4.0;


//Creates variables to be used in autonomous program
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

//-------------------------------------------------------------------------------------------------------- UTILITY FUNCTIONS

void driveMotors_ClearEncoders(){
    //reset motor encoders to zero
    FLmotor.resetRotation();
    BLmotor.resetRotation();
    FRmotor.resetRotation();
    BRmotor.resetRotation();
    }

void driveMotors_Timeout(int timeout){
    FLmotor.setTimeout(timeout,timeUnits::msec);
    BLmotor.setTimeout(timeout,timeUnits::msec);
    FRmotor.setTimeout(timeout,timeUnits::msec);
    BRmotor.setTimeout(timeout,timeUnits::msec);
}

void driveMotors_Stop(){
    //stop all drive motors
    FLmotor.stop(brakeType::coast);
    BLmotor.stop(brakeType::coast);
    FRmotor.stop(brakeType::coast);
    BRmotor.stop(brakeType::coast);
}

//-------------------------------------------------------------------------------------------------------- AUTONOMOUS FUNCTIONS

void auton_ArmControl(int rotateDegrees, int armSpeed){
    ARMmotor.rotateTo(rotateDegrees,rotationUnits::deg,armSpeed, velocityUnits::pct);
    ARMmotor.stop(brakeType::hold);
}

void auton_puncherMotorControl(int rotateDegrees, int speed){
    Punchermotor.rotateFor(rotateDegrees,rotationUnits::deg, speed, velocityUnits::pct);
}

void auton_driveForward(float rotateUnits, int speed){
        FLmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
        BLmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
        FRmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
        BRmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
}

void auton_driveBackwards(float rotateUnits, int speed){
    FLmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BLmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    FRmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BRmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
}

void auton_turnRight(float rotateUnits, int speed){
    FLmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BLmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    FRmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BRmotor.startRotateFor(rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
}

void auton_turnLeft(float rotateUnits, int speed){
    FLmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BLmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    FRmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
    BRmotor.startRotateFor(-rotateUnits,rotationUnits::rev,speed,velocityUnits::rpm);
}

//-------------------------------------------------------------------------------------------------------- DRIVER FUNCTIONS

void driver_driveMotorsControl(){
    //Drive Controls
    //Set the left and right motor to spin fwd/rev using the controller Axis as values as teh velocity value
    
    //left drive motor commands
    BLmotor.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::rpm);
    FLmotor.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::rpm);
     
    //right drive motor commands
    FRmotor.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::rpm);
    BRmotor.spin(directionType::rev, Controller1.Axis2.value(), velocityUnits::rpm);
    
    
}

void driver_armControl(){
     //arm motor commands
    if(Controller1.ButtonR1.pressing())
    {
      ARMmotor.spin(directionType::rev, driverArmSpeedPCT, velocityUnits::pct);
    }

    else if(Controller1.ButtonR2.pressing())
    {
      ARMmotor.spin(directionType::fwd, driverArmSpeedPCT, velocityUnits::pct);
    }
    else
    {
      ARMmotor.stop(brakeType::brake);
    }
}

void driver_puncherMotorControl(){
    if(Controller1.ButtonA.pressing()){
        Punchermotor.spin(directionType::rev,driverPuncherMotorSpeedPCT, velocityUnits::pct);
    }
    else{Punchermotor.stop(brakeType::brake);}
    }

void driver_spinnersMotorControl(){
    if(Controller1.ButtonL2.pressing()){
        Spinnermotor.spin(directionType::rev,driverSpinnerSpeedPCT, velocityUnits::pct);
    }
    else if(Controller1.ButtonL1.pressing()){
        Spinnermotor.spin(directionType::fwd,driverSpinnerSpeedPCT, velocityUnits::pct);
    }
    else{Spinnermotor.stop(brakeType::coast);}
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
  driveMotors_ClearEncoders(); //resets all individual drive motor encoder counts to zero
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

void autonomous( void ) { //---- BLUE01 --SHOOT, TOGGLE FLAG, & PARK
    
    //Display that the program has started to the screen
    Brain.Screen.print("AutonRED01 -- SHOOT, TOOGLE, & PARK HAS STARTED");
    
     
    auton_puncherMotorControl(-360, 50);//spins puncher motor for 360 degrees at 200% of puncher motor power
    Punchermotor.stop(); //stop power to puncher motor

    //turn Right to line up for cap bump
    driveMotors_ClearEncoders(); //clear individual drive motor encoder count
    auton_turnRight(0.6, 40); //run drive motors to turn left for 0.6 revolutions at 40% of drive motors power
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {}//while loop ensures that all motors stay spinning until all motors have reached intended revolution count
    driveMotors_Stop(); //stop power to all drive motors
    driveMotors_Timeout(700); //timeout drive motors to ensure commands seperation & momentum recapture
    
    //go Backwards to line up for cap bump
    driveMotors_ClearEncoders(); //clear individual drive motor encoder count
    auton_driveBackwards(2.8, 60); //drive forward for 3.5 revolutions at 80% of drive motors power
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {} //while loop ensures that all motors stay spinning until all motors have reached intended revolution count
    driveMotors_Stop(); //stop power to all drive motors
    driveMotors_Timeout(700); //timeout drive motors to ensure commands seperation & momentum recapture
    
    //raise arm
    auton_ArmControl(-90, 50); //raise arm to 90 degrees at 50% of arm motor power
    
    //go forwards to line up for platform climb
    driveMotors_ClearEncoders(); //clear individual drive motor encoder count
    auton_driveForward(0.5, 70); //drive forward for 3.5 revolutions at 80% of drive motors power
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {} //while loop ensures that all motors stay spinning until all motors have reached intended revolution count
    driveMotors_Stop(); //stop power to all drive motors
    driveMotors_Timeout(700); //timeout drive motors to ensure commands seperation & momentum recapture
    
    //turn left to line up for platform climb
    driveMotors.ClearEncoders(); //clear individual drive motor encoder count
    auton_turnLeft(0.6, 40); //run drive motors to turn left for 0.6 revolutions at 40% of drive motors power
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {}//while loop ensures that all motors stay spinning until all motors have reached intended revolution count
    driveMotors_Stop(); //stop power to all drive motors
    driveMotors_Timeout(700); //timeout drive motors to ensure commands seperation & momentum recapture
    
    //go Backwards to line up for cap bump
    driveMotors_ClearEncoders(); //clear individual drive motor encoder count
    auton_driveBackwards(3.0, 100); //drive forward for 3.5 revolutions at 80% of drive motors power
    while(FLmotor.isSpinning()||BLmotor.isSpinning()||FRmotor.isSpinning()||BRmotor.isSpinning())
    {} //while loop ensures that all motors stay spinning until all motors have reached intended revolution count
    driveMotors_Stop(); //stop power to all drive motors
    driveMotors_Timeout(700); //timeout drive motors to ensure commands seperation & momentum recapture

  }

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1)
  {
    Brain.Screen.print("User Control Has Started");//Display that the program has started to the screen
    //driver_setDriveMotorsVelocity(80);           //set driver drive motors speed
    driver_driveMotorsControl();                 //drive motor controls  
    driver_armControl();                         //arm motor control
    driver_puncherMotorControl();                //puncher motor control
    driver_spinnersMotorControl();               //spinner motor control
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
