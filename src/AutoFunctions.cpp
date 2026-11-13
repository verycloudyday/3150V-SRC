#include <math.h>
#include "vex.h"
#include "movement.hpp"
#include "helper_functions.hpp"

// PID parameters for drive motor: {Kp, Ki, Kd}
PIDDataSet DrivePara={0, 0, 0};

void LiftAuto (int inches, int speed, bool braking)
{
  liftL.setMaxTorque(100,percent);
  liftR.setMaxTorque(100,percent);
  liftL.spinToPosition(inches * 360 / (2 * 3.14159), degrees, speed, velocityUnits::pct);
  liftR.spinToPosition(inches * 360 / (2 * 3.14159), degrees, speed, velocityUnits::pct);
  if(braking){
    liftL.setStopping(brake);
    liftR.setStopping(brake);
    wait(120,msec);
  }
  else{
    liftL.setStopping(brake);
    liftR.setStopping(brake);
  }
}

void ChainbarAuto (int deg, int speed, bool braking)
{
  chainbarL.setMaxTorque(100,percent);
  chainbarR.setMaxTorque(100,percent);
  chainbarL.spinToPosition(-deg, degrees, speed, velocityUnits::pct);
  chainbarR.spinToPosition(deg, degrees, speed, velocityUnits::pct);
  chainbar.spinToPosition(0, degrees, speed, velocityUnits::pct);
  if(braking){
    chainbar.setStopping(hold);
  }
  else{
    chainbar.setStopping(hold);
  }
}

void ClawAuto (bool state)
{
  Claw.set(state);
  wait(120,msec);
}


void zeroLift (int speed, int torque, bool brake) {
  liftL.setMaxTorque(torque,percent);
  liftR.setMaxTorque(torque,percent);
  if(brake){
    liftL.setStopping(hold);
    liftR.setStopping(hold);
  }
  else{
    liftL.setStopping(coast);
    liftR.setStopping(coast);
  }
  liftL.spinToPosition(0, degrees, speed, velocityUnits::pct);
  liftR.spinToPosition(0, degrees, speed, velocityUnits::pct);
}

void spinToggle (int speed, int torque, int time, bool brake) {
  Toggle.spin(reverse, speed, percentUnits::pct);
  wait(time, msec);
  Toggle.stop();
}

