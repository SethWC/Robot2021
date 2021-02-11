/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "Constants.h"
#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <ctre/Phoenix.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/AnalogInput.h>
#include <frc/Relay.h>
#include <frc/DigitalInput.h>

class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
  void slowlyDriveForwards();
  void stop();
  void driveWithXboxController();
  void arcadeDrive();
  void toggleDrive();
  void driveWithPixy();
  void setDriverJoystick(frc::XboxController* pDriverJoystick){
    mpDriverJoystick = pDriverJoystick;
  };

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();



 private:

  frc::AnalogInput mAnalogLeft{kAnalogLeft};
  frc::AnalogInput mAnalogRight{kAnalogRight};
  frc::DigitalInput mTopSensor{2};

  frc::XboxController* mpDriverJoystick;

  WPI_TalonSRX mDriveLeft1;
  WPI_TalonSRX mDriveLeft2;
  WPI_TalonSRX mDriveRight1;
  WPI_TalonSRX mDriveRight2;

  WPI_TalonSRX mIndexerConveyer;
  WPI_TalonSRX mIntakeRoller;

  frc::SpeedControllerGroup mLeft{mDriveLeft1, mDriveLeft2};
  frc::SpeedControllerGroup mRight{mDriveRight1, mDriveRight2};

  frc::DifferentialDrive mDrive{mLeft, mRight};
 
  bool on = false;


  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
