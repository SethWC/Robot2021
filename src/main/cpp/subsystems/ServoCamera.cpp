/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ServoCamera.h"
#include <frc/Servo.h>
ServoCamera::ServoCamera():
    bottomServo{1},
    topServo{2}

{


}

// This method will be called once per scheduler run
void ServoCamera::Periodic() {
    //exampleServo.Set(0.5);
}

void ServoCamera::setPosition(float x){
    bottomServo.Set(x);
}

void ServoCamera::controlServoWithJoystick(){
    if(topServoPosition < 0 || topServoPositoon > 1){
        return;
    }
    if(bottomServoPosition < 0 || bottomServoPositoon > 1){
        return;
    }
    double verticlePower = (p_servoJoystick->GetRawAxis(1))/50; 
    double horizontalPower = ((p_servoJoystick->GetRawAxis(0))/50);
    double topServoPosition = topServo.GetPosition();
    double bottomServoPosition = bottomServo.GetPosition();

    topServo.Set(topServoPosition + verticlePower);
    bottomServo.Set(bottomServoPosition + horizontalPower);
    
}