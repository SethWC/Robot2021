/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

//motor controllers
int constexpr kTopLeftMotor = 0;
int constexpr kTopRightMotor = 1;
int constexpr kBottomLeftMotor = 2;
int constexpr kBottomRightMotor = 3;
int constexpr kControlPanelMotor = 4;


//OI Indexes (joysticks/buttons)
int constexpr kDriverJoystick = 0;
int constexpr kOperatorJoystick = 1;

//Analog Inputs
int constexpr kAnalogLeft = 0;
int constexpr kAnalogRight = 1;