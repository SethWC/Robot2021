/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "frc/XboxController.h"
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer()
{
  // Initialize all of your commands and subsystems here
  //drive
  // Configure the button bindings
  ConfigureButtonBindings();

  mTankDrive.SetDefaultCommand(std::move(mPixyDrive));
  mTankDrive.setDriverJoystick(&mDriverController);


}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}


frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
 // return &m_autonomousCommand;

}
