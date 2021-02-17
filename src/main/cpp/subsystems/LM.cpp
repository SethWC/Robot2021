/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LMYawToTarget.h"
#include "subsystems/LM.h"

// This method will be called when started, it initializes values.
LM::LM() : 
    m_LimelightHasTarget(false)
{
    Kp = -0.1f;
    min_command = 0.05f;
    table->PutNumber("ledMode", 3);
    table->PutNumber("pipeline", 0);
}

// This method will be called continuously until Limelight rotated to target.
bool LM::CheckR(){
    if (-1.0 < tx && tx < 1.0)
    {
      return true;
    }
    return false;
}

// This method will be called once per scheduler run
void LM::Periodic() {
  printf ("LMPeriodic**********\n");
  tx = table->GetNumber("tx",0.0);
  ty = table->GetNumber("ty",0.0);
  ta = table->GetNumber("ta",0.0);
  tv = table->GetNumber("tv",0.0);

  if (m_LimelightHasTarget == true)  {
    heading_error = -tx;
    steering_adjust = 0.0f;
    if (tx > 0.5) {
      //steering_adjust = Kp*heading_error - min_command;
      steering_adjust = 0.2;
    }
    else if (tx < 0.5)  {
      //steering_adjust = Kp*heading_error + min_command;
      steering_adjust = -0.2;
    }
    left_command = steering_adjust;
    right_command = -steering_adjust;
    
    //left_command = steering_adjust / 27.0f;
    //right_command = -steering_adjust / 27.0f;
    
    //left_command = steering_adjust / 27.0f * 4;
    //right_command = -steering_adjust / 27.0f * 4;
    printf("ValuesYawleft********** %f, ValuesYawRight********** %f\n", left_command, right_command);
  }

// If the Limelight has any valid targets sets LimelightHasTarget to true.
  if (tv < 1.0) {
    m_LimelightHasTarget = false;
  }
  else  {
    m_LimelightHasTarget = true;
  }
}
