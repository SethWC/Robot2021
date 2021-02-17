/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"

class LM : public frc2::SubsystemBase {
 public:
  LM();
  bool limeLightHasTarget() {return m_LimelightHasTarget;}
  
  float left_command; // +steering_adjust
  float right_command; // -steering_adjust
  
  std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  void Periodic(); // Constantly gets network table values and calculates for left_command and right_command
  bool CheckR(); // Checks if robot needs to yaw, if not, tx is greater than -1 and less than 1

 private:
  bool m_LimelightHasTarget; // True if acquired target
  
  double tx; // Horizontal Offset From Crosshair To Target
  double ty; // Vertical Offset From Crosshair To Target
  double ta; // % of The Target Area to Screen Ratio
  bool tv; // True if acquired target

  float heading_error; // Horizontal Offset From Crosshair To Target
  float steering_adjust = 0.0f; // Multiplied by Kp, subtracted by min_command if +tx, added by min_command if -tx

  float Kp; // If  error > threshhold, this is a constant * motor command
  float min_command; // If  error > threshhold, this is a constant + motor command if -tx or - motor command if +tx
};
