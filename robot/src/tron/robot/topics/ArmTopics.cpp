/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/ArmTopics.h"

namespace tron
{    
const std::string ArmTopics::ARM_JOINT = "joint";
const std::string ArmTopics::ARM_AXIS = "axis";
const std::string ArmTopics::ARM_CYCLIC = "cyclic";
const std::string ArmTopics::ARM_EXTRA = "extra";    

ArmTopics::ArmTopics()
{
    fillMap();
}

void ArmTopics::fillMap()
{
    // build topics map
    oTopicsMap.addCode(eARM_JOINT, ARM_JOINT);
    oTopicsMap.addCode(eARM_AXIS, ARM_AXIS);
    oTopicsMap.addCode(eARM_CYCLIC, ARM_CYCLIC);
    oTopicsMap.addCode(eARM_EXTRA, ARM_EXTRA);
}

}