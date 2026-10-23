#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"

//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
//liftAuto (int deg, int speed, bool brake);
//chainbarAuto (int deg, int speed, bool brake);
//clawAuto (bool state);

void auton1() {
    // declare initial conditions
    liftL.resetPosition();
    liftR.resetPosition();
    chainbar.resetPosition();
    chainbar.setStopping(hold);
    chainbar.setMaxTorque(100,percent);
    Gyro.calibrate();
    PIDDataSet DrivePara={0,0,0};
    PIDDataSet TurnPara={0,0,0};

    MoveEncoderPID(DrivePara, 100, 8, 0.1 , 0, true);
    TurnMaxTimePID(TurnPara, 100, 0.3, 0.1, 70, true);
    MoveEncoderPID(DrivePara, 100, 8, 0.1, 70, true);


    }
        
   
    

    




void auton2(){  
   
}