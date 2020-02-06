/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>

class IntakeMechanism : public frc2::SubsystemBase {
 public:
  IntakeMechanism();
  


  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();


 void lowerIntakeArm();
 void  StartROllers();
 
 private:
  
  WPI_TalonSRX m_IntakeArmMotor;
  WPI_TalonSRX m_IntakeRollerMotor;

 

};