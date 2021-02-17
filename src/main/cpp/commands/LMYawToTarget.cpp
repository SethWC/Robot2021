/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LMYawToTarget.h"

// Subsystem dependencies.
LMYawToTarget::LMYawToTarget(LM* pLM, DriveTrain* pDriveTrain): mpLM{pLM}, mpDriveTrain{pDriveTrain} {
  AddRequirements(pLM);
  AddRequirements(pDriveTrain);
}

// Called when the command is initially scheduled.
void LMYawToTarget::Initialize() {
  printf("BeginYaw**********\n");
}

// Called repeatedly when this Command is scheduled to run.
void LMYawToTarget::Execute() {
  printf("MotorYawLeft********** %f MotorYawRight********** %f\n", mpLM->left_command, mpLM->right_command);
  mpDriveTrain->move(mpLM->left_command, mpLM->right_command);
}

// Called once the command ends or is interrupted.
void LMYawToTarget::End(bool interrupted) {
  mpDriveTrain->stop();
}

// Returns true when the command should end.
bool LMYawToTarget::IsFinished() {
    return mpLM->CheckR();
    //return false;
}
