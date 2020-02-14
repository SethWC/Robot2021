/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "RobotContainer.h"
#include "Constants.h"
#include "subsystems/Indexer.h"


Indexer::Indexer():
    mIndexerConveyer{kIndexChannel,frc::Relay::kBothDirections},
    mIntakeSensor{kDIOIntake},
    mBottomSensor{kDIOBottom},
    mTopSensor{kDIOTop},
    mNumPowerCells{3},
    mEmptyTimer{0},
    mPowerCellWasAtIntake{false}
 {
}
//isFullIndexer - returns true if the TopSensor,
//   and IntakeSensor all see a power cell. The Indexer is
//   considered full if it can't move any balls up (they would enter
//   the shooter) and the intakeSensor has a ball (so it cannot move the 
//   conveyor at all).
bool Indexer::isFullIndexer(){
    return (isPowerCellAtTop() && isPowerCellAtIntake());
}
//isEmptyIndexer - determine if the indexer is empty. It has no power cells
//  if none of the sensors register a power cell, we could be in a state where
//  there are few balls (less than 3) in the indexer and they are traveling
//  either toward the top or the bottom. If this is the case we need to 
//  wait for the travel timer(time it takes for a ball to go the whole indexer
//  length) expires.
bool Indexer::isEmptyIndexer(){
    if (!isPowerCellAtTop() && !isPowerCellAtBottom()){
        if (isRunningOnEmpty()){
            return(true);
        }
        else {
            mEmptyTimer++;
        }
    }
    return(false);
}
//movePowerCellsToTop - move the line of power cells up to the top of
//   the indexer. This is helpful so shooting power cells can start
void Indexer::movePowerCellsToTop(){
    //if there is a ball in the top of the sensor, we are done.
    if (isPowerCellAtTop()){
        stopIndexer();
    }
    else { //try to move balls to the top of the indexer
        moveUpIndexer();
    }
}
//movePowerCellsToBottom - move all of the power cells down in
// the conveyor until the reach the Bottom Sensor
void Indexer::movePowerCellsToBottom(){
    if (isPowerCellAtBottom()){
        stopIndexer();
    } else{
        moveDownIndexer();
    }
}
//Shoot Power cell - just move the indexer 
void Indexer::shootPowerCells(){
    //start the conveyor to pass power cells to the shooter (we assume that
    //  the shooter is ready).  If there is a powercell in at the top, we
    //  reset the running on empty timer & decrement the power cell counter until
    //  it hits zero.
    moveUpIndexer();
    if (isPowerCellAtTop()){
        resetRunningOnEmpty();
        if(mNumPowerCells>0){
            mNumPowerCells--;
        }
    }
}
// This method will be called once per scheduler run
void Indexer::Periodic() {}