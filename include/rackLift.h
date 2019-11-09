/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       rackLift.h                                                */
/*    Author:       Reece Turner                                              */
/*    Created:      Thur Oct 31 2019                                          */
/*    Description:  Rack Lift Function File for Tower Takeover 2019           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "robot-config.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// RackLift             Red Motor      18                                       
// ---- END VEXCODE CONFIGURED DEVICES ----

int rackLiftSpeedPCT = 100;

void rackLift(){
  if(Controller1.ButtonUp.pressing()){
    RackLift.spin(directionType::rev, rackLiftSpeedPCT, velocityUnits::pct);
  }
  else if(Controller1.ButtonDown.pressing()){
    RackLift.spin(directionType::fwd, rackLiftSpeedPCT, velocityUnits::pct);
  }
  else{
    RackLift.stop(brakeType::brake);
  }
}
