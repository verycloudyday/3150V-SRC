#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
#include "../AutoFunctions.hpp"

// PID Straight and turn arguments:
//  MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
//  TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
//  MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// liftAuto (int deg, int speed, bool brake);
// chainbarAuto (int deg, int speed, bool brake);
// clawAuto (bool state);

void auton1()
{ // close
    // declare initial conditions
    PIDDataSet DrivePara = {0.3, 0.1, 0};
    PIDDataSet TurnPara = {0.5, 0.1, 0.225};
    PIDDataSet TestPara = {0.1, 0, 0};
    PIDDataSet Test1Para = {0.25, 0.1, 0};

    Gyro.calibrate();

    while (Gyro.isCalibrating())
    {
        wait(10, msec);
    }

    liftL.resetPosition();
    liftR.resetPosition();

    chainbar.resetPosition();

    chainbar.setStopping(hold);

    chainbar.setMaxTorque(100, percent);

    //MoveEncoderPID(DrivePara, 100, 2.5, 0.1, 0, true);

    //chainbarL.spinToPosition(-750, rotationUnits::deg, 75, velocityUnits::pct, false);
    //chainbarR.spinToPosition(750, rotationUnits::deg, 75, velocityUnits::pct, false);
    //chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    wait(250, msec);

    // swing chainbar back before toggle to avoid hitting the wall

    //MoveEncoderPID(DrivePara, -95, 8, 0.1, 0, true);

    wait(250, msec);

    spinToggle(-60, 100, 900, true); // toggle number should always be negative -2

   

    //chainbarL.spinToPosition(-730, rotationUnits::deg, 75, velocityUnits::pct, false);
    //chainbarR.spinToPosition(730, rotationUnits::deg, 75, velocityUnits::pct, false);
    //chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    //MoveEncoderPID(DrivePara, 100, 8, 0.1, 0, true);

    //TurnMaxTimePID(TurnPara, -90, 0.5, true);

    // MoveEncoderPID(DrivePara, 100, 8, 0.1, -90, true);

    // Move(40, 40);
    // wait(550, msec);

    // chainbarL.spinToPosition(-740, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbarR.spinToPosition(740, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    // wait(100, msec);

    // clawAuto(true);

    //uncomment from here ^^^

    // chainbarL.spinToPosition(700, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbarR.spinToPosition(-700, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    // wait(250, msec);

    // MoveEncoderPID(DrivePara, -95, 3.5, 0.1, -90, true);

    // TurnMaxTimePID(TurnPara, 15, 0.7, true);

    // MoveEncoderPID(TestPara, -95, 12, 0.1, -180, true);

    // TurnMaxTimePID(TurnPara, -170, 0.65, true);

    // Move(15, 80);

    // clawAuto(false);

    // Move(50, 50);
    // wait(250, msec);
}

void auton2()
{ // far
    // PIDDataSet DrivePara = {0.3, 0.1, 0};
    // PIDDataSet TurnPara = {0.5, 0.1, 0.225};
    // PIDDataSet TestPara = {0.1, 0, 0};
    // PIDDataSet Test1Para = {0.25, 0.1, 0};

    // Gyro.calibrate();

    // while (Gyro.isCalibrating())
    // {
    //     wait(10, msec);
    // }

    // liftL.resetPosition();
    // liftR.resetPosition();

    // chainbar.resetPosition();
    // chainbarR.resetPosition();
    // chainbarL.resetPosition();

    // chainbar.setStopping(hold);
    // chainbarR.setStopping(hold);
    // chainbarL.setStopping(hold);

    // chainbar.setMaxTorque(100, percent);
    // chainbarR.setMaxTorque(100, percent);
    // chainbarL.setMaxTorque(100, percent);

    // MoveEncoderPID(DrivePara, 100, 2.5, 0.1, 0, true);

    // chainbarL.spinToPosition(-750, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbarR.spinToPosition(750, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    // wait(250, msec);

    // // swing chainbar back before toggle to avoid hitting the wall

    // MoveEncoderPID(DrivePara, -95, 7, 0.1, 0, true);

    // spinToggle(-100, 100, 500, true); // toggle number should always be negative -2

   

    // chainbarL.spinToPosition(-730, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbarR.spinToPosition(730, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    // MoveEncoderPID(DrivePara, 100, 8, 0.1, 0, true);

    // TurnMaxTimePID(TurnPara, 90, 0.5, true);

    // MoveEncoderPID(DrivePara, 100, 8, 0.1, 90, true);

    // Move(40, 40);
    // wait(550, msec);

    // chainbarL.spinToPosition(-740, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbarR.spinToPosition(740, rotationUnits::deg, 75, velocityUnits::pct, false);
    // chainbar.spinToPosition(0, rotationUnits::deg, 100, velocityUnits::pct, true);

    // wait(100, msec);

    // clawAuto(true);


}

void auton3()
{
}