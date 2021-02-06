/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drive/DriveWithXbox.h"
#include "subsystems/DriveTrain.h"
#include "RobotContainer.h"
#include "Robot.h"

DriveWithXbox::DriveWithXbox(DriveTrain* pTankDrive): mpTankDrive(pTankDrive)
 {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pTankDrive);

}

// Called when the command is initially scheduled.
void DriveWithXbox::Initialize() {}


// Called repeatedly when this Command is scheduled to run
void DriveWithXbox::Execute() {

  mpTankDrive->tankDrive();
  //printf("running drive!");

}

// Called once the command ends or is interrupted.
void DriveWithXbox::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveWithXbox::IsFinished() { return false; }
