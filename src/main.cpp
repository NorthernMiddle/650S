/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Reece Turner                                              */
/*    Created:      Sun Oct 20 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]              [Port(s)]
// LBmotor              Green Motor         20              
// LFmotor              Green Motor         19              
// RBmotor              Green Motor         12              
// RFmotor              Green Motor         11              
// RackLift             Red Motor           18              
// ArmLift              Red Motor            9               
// L_Intake             Red Motor            1               
// R_Intake             Red Motor           10              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "tankDrive.h"
#include "arcadeDrive.h"
#include "intakeMotors.h"
#include "armLift.h"
#include "rackLift.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  while(true){
    vexcodeInit();
    //tankDrive();
    arcadeDrive();
    intakeFunc();
    rackLift();
    armLift();
  }
}
