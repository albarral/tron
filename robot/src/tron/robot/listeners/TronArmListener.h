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
    virtual JointsData& getJointPositions() = 0;
    // sense joint states
//    virtual JointsData& getJointStates() = 0;
//
    // axis topic ...
    // sense axes positions 
    virtual AxesData& getAxesPositions() = 0;
    // sense axes speeds 
    virtual AxesData& getAxesSpeeds() = 0;
    
};
}
#endif
