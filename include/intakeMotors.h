/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       intakeMotors.h                                            */
/*    Author:       Reece Turner                                              */
/*    Created:      Thur Oct 24 2019                                          */
/*    Description:  Intake Spinner Motor Function File                        */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "robot-config.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// L_Intake             Green Motor   1               
// R_Intake             Green Motor   8                                   
// ---- END VEXCODE CONFIGURED DEVICES ----

int intakeSpeedPCT = 100; 

void intakeFunc(){
  if(Controller1. ButtonR1.pressing()){
    L_Intake.spin(directionType::fwd, intakeSpeedPCT, velocityUnits::pct);
    R_Intake.spin(directionType::rev, intakeSpeedPCT, velocityUnits::pct);
  }
  else if(Controller1.ButtonR2.pressing()){
    L_Intake.spin(directionType::rev, intakeSpeedPCT, velocityUnits::pct);
    R_Intake.spin(directionType::fwd, intakeSpeedPCT, velocityUnits::pct);
    }
  else{
    L_Intake.stop(brakeType::brake);
    R_Intake.stop(brakeType::brake);
  }
}
