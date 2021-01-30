/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DropLift.h"

DropLift::DropLift(Pneumatics* pPneumatics) : mpPneumatics{pPneumatics} {
  AddRequirements(pPneumatics);
}

// Called when the command is initially scheduled.
void DropLift::Initialize() {
  mpPneumatics->dropLift();
}

// Called repeatedly when this Command is scheduled to run
void DropLift::Execute() {}

// Called once the command ends or is interrupted.
void DropLift::End(bool interrupted) {}

// Returns true when the command should end.
bool DropLift::IsFinished() { return true; }
