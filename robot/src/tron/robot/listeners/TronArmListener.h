#ifndef __TRON_ROBOT_ARMLISTENER_H
#define __TRON_ROBOT_ARMLISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Interface class for arm listeners
class TronArmListener
{        
 public:     
    // joint topic ...
    // sense joints positions 
    virtual bool getJointPositions(JointsData& jointsData) = 0;
    // sense joint states
//    virtual bool getJointStates(JointsStates& jointsStates) = 0;
//
//    // axis topic ...
//    // sense axes positions 
//    virtual bool getAxesPositions(AxesData& axesData) = 0;
//    // sense axes speeds 
//    virtual bool getAxesSpeeds(AxesSpeeds& axesSpeeds) = 0;
    
};
}
#endif
