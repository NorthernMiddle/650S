/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       arcadeDrive.h                                             */
/*    Author:       Reece Turner                                              */
/*    Created:      Thurs Oct 13 2019                                         */
/*    Description:  Arcade Drive Function File                                */
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

void arcadeDrive(){
  //left drive arcade motors
  LBmotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
  LFmotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
  RBmotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3+Axis4)/2;
  RFmotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value())/2, velocityUnits::pct);//(Axis3-Axis4)/2;
}
