/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/RaiseArm.h"

RaiseArm::RaiseArm() {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void RaiseArm::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RaiseArm::Execute() {
if (armup != 1)
  //Arm up 90 degrees
  armup = 0;
return
}

// Called once the command ends or is interrupted.
void RaiseArm::End(bool interrupted) {}

// Returns true when the command should end.
bool RaiseArm::IsFinished() { return false; }