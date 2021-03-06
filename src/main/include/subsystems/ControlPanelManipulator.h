/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

class ControlPanelManipulator : public frc2::SubsystemBase {
 public:
  ControlPanelManipulator();
//  void turnControlPanel(char currentColor, char targetColor);
  void rotationControl();
  void positionControl(char targetColor);
  void printColor();
  bool getFinished();
  void resetFinished();
  void stopMotor();
  void runMotor();
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  char getReadColor(); //Returns R for red, G for green, B for blue, Y for yellow, or X for other
  bool hasMovedColors();
  WPI_TalonSRX mControlMotor;
  char previousColor;
  char prevColors[5] = { 0 };
  char currentColor;
  int turnCounter;
  rev::ColorSensorV3 mColorSensor;
  rev::ColorMatch mMatching;
  frc::Color blue;
  frc::Color red;
  frc::Color yellow;
  frc::Color green;
  frc::Color rawColor;
  double confidence;
  bool finished;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
