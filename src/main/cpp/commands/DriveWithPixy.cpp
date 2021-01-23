/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveWithPixy.h"

DriveWithPixy::DriveWithPixy(DriveTrain* pDriveTrain) : mpDriveTrain{pDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDriveTrain);
}

// Called when the command is initially scheduled.
void DriveWithPixy::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveWithPixy::Execute() {
  mpDriveTrain->driveWithPixy();
}

// Called once the command ends or is interrupted.
void DriveWithPixy::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveWithPixy::IsFinished() { return false; }
