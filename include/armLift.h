/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       armlift.h                                                 */
/*    Author:       Reece Turner                                              */
/*    Created:      Thurs Oct 31 2019                                         */
/*    Description:  Arm Lift Function File for Tower Takeover 2019            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "robot-config.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ArmLift              Red Motor      9                                       
// ---- END VEXCODE CONFIGURED DEVICES ----

int armSpeedPCT = 80;

void armLift(){
  if(Controller1.ButtonL1.pressing()){
    ArmLift.spin(directionType::fwd, armSpeedPCT, velocityUnits::pct);
  }
  else if(Controller1.ButtonL2.pressing()){
    ArmLift.spin(directionType::rev, armSpeedPCT, velocityUnits::pct);
  }
  else{
    ArmLift.stop(brakeType::brake);
  }
}
