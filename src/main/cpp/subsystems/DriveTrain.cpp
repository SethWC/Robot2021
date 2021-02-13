/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Constants.h"


DriveTrain::DriveTrain():
    mDriveLeft1{kTopLeftMotor}, 
    mDriveLeft2{kBottomLeftMotor}, 
    mDriveRight1{kTopRightMotor}, 
    mDriveRight2{kBottomRightMotor},
    mIndexerConveyer{kIndexerMotor},
    mIntakeRoller{kIntakeRoller}
 {

}

// This method will be called once per scheduler run
void DriveTrain::Periodic() {



}

void DriveTrain::driveWithXboxController(){
    
    double leftSpeed = mpDriverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rightSpeed = mpDriverJoystick->GetRawAxis(5); //Cap: 697rpm
    
    mDrive.TankDrive(-leftSpeed,-rightSpeed,true);
    printf("Driving: %f, %f\n", leftSpeed, rightSpeed);

}

void DriveTrain::driveWithPixy() {
    double leftSpeed = (mAnalogLeft.GetVoltage() - 2.5) / 2.5;
    double rightSpeed = (mAnalogRight.GetVoltage() - 2.5) / 2.5;
    
    mDrive.TankDrive(-leftSpeed, -rightSpeed, false);
    printf("Driving: %f, %f\n", leftSpeed, rightSpeed);

    if (mTopSensor.Get()) {
        mIndexerConveyer.Set(0.25);
    }
    mIntakeRoller.Set(-0.5);
}

void DriveTrain::arcadeDrive(){
    double speed = mpDriverJoystick->GetRawAxis(1); //Cap: 690rpm
    double rotation = mpDriverJoystick->GetRawAxis(0); //Cap: 697rpm

    mDrive.ArcadeDrive(-speed,rotation);
}

void DriveTrain::slowlyDriveForwards(){
    mDrive.TankDrive(0.2, 0.2, false);
}

void DriveTrain::stop(){
    mDrive.TankDrive(0, 0, false);
}

void DriveTrain::toggleDrive(){
    printf("On: %d\n", on);
    if (on == true) {
        mDrive.TankDrive(-1, -1, true);
        if (mpDriverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = false;
        }
    }
    else {
        mDrive.TankDrive(0, 0, true);
        if (mpDriverJoystick->GetRawButton(1) == 1) {
            //while (p_driverJoystick->GetRawButton(1) == 1);
            on = true;
        }
    }
}