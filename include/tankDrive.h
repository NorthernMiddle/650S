/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       tankDrive.h                                               */
/*    Author:       Reece Turner                                              */
/*    Created:      Sun Oct 20 2019                                           */
/*    Description:  Tank Drive Function Header File                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "robot-config.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LBmotor              Green Motor    20              
// LFmotor              Green Motor    19              
// RBmotor              Green Motor    12              
// RFmotor              Green Motor    11                         
// ---- END VEXCODE CONFIGURED DEVICES ----

void tankDrive(){
  //left drive train motors
  LBmotor.spin(vex::directionType::fwd, Controller1.Axis3.value()/2, vex::velocityUnits::pct);
  LFmotor.spin(vex::directionType::fwd, Controller1.Axis3.value()/2, vex::velocityUnits::pct);
  //right drive train motors
  RBmotor.spin(vex::directionType::fwd, Controller1.Axis2.value()/2, vex::velocityUnits::pct);
  RFmotor.spin(vex::directionType::fwd, Controller1.Axis2.value()/2, vex::velocityUnits::pct);
}
