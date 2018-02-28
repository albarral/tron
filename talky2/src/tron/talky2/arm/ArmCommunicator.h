#ifndef __TALKY2_ARMCOMMUNICATOR_H
#define __TALKY2_ARMCOMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/wire2/FileWire.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
#include "tron/talky2/arm/BasicTalker.h"

namespace tron
{
// Base class for arm communication classes (client & listener)
class ArmCommunicator 
{    
protected:
    static log4cxx::LoggerPtr logger;
    FileWire oWire;                                     // communications wire   
    JointTalker oJointTalker;
    AxisTalker oAxisTalker;
    CyclicTalker oCyclicTalker;
    BasicTalker oBasicTalker;
        
public:
    ArmCommunicator();
    //~ArmCommunicator();
};

}
#endif
