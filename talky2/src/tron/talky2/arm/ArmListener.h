#ifndef __TALKY2_ARMLISTENER_H
#define __TALKY2_ARMLISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/talky2/arm/JointChannelListener.h"
#include "tron/robot/listeners/TronArmListener.h"
#include "tron/robot/sensors/ArmSensors.h"

namespace tron
{
// Arm client class (implementing TronArmListener interface) to sense a robot arm.
class ArmListener : public TronArmListener
{    
private:
    static log4cxx::LoggerPtr logger;
    JointChannelListener oJointChannelListener;
        
public:
    ArmListener();
    //~ArmListener();

    // joint topic ...
    // sense joints positions 
    virtual bool getJointPositions(JointsData& jointsData);
//    // sense joint states
//    virtual bool getJointStates(JointsStates& jointsStates);
//
//    // axis topic ...
//    // sense axes positions 
//    virtual bool getAxesPositions(AxesData& axesData);
//    // sense axes speeds 
//    virtual bool getAxesSpeeds(AxesSpeeds& axesSpeeds);
};

}
#endif
