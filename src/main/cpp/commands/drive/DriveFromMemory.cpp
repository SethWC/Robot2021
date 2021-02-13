/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/drive/DriveFromMemory.h"

DriveFromMemory::DriveFromMemory(DriveTrain* pDriveTrain): mpDriveTrain{pDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(pDriveTrain);
}

// Called when the command is initially scheduled.
void DriveFromMemory::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveFromMemory::Execute() {
  mpDriveTrain->driveFromMemory();
}

// Called once the command ends or is interrupted.
void DriveFromMemory::End(bool interrupted) {}

// Returns true when the command should end.
bool DriveFromMemory::IsFinished() { return false; }
