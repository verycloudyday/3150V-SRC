#ifndef AUTOFUNCTIONS_HPP
#define AUTOFUNCTIONS_HPP

#include "movement.hpp"

extern PIDDataSet DrivePara;
extern PIDDataSet TurnPara;
extern PIDDataSet TestPara;

void LiftAuto(int inches, int speed, bool braking);
void ChainbarAuto(int deg, int speed, bool braking);
void ClawAuto(bool state);
void zeroLift(int speed, int torque, bool brake);
void spinToggle(int speed, int torque, int time, bool brake);

#endif // AUTOFUNCTIONS_HPP
