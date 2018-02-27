/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/ArmTopic.h"

namespace tron
{    
const std::string ArmTopic::ARM_JOINT = "joint";
const std::string ArmTopic::ARM_AXIS = "axis";
const std::string ArmTopic::ARM_CYCLIC = "cyclic";
const std::string ArmTopic::ARM_EXTRA = "extra";    

std::string ArmTopic::getTopicName(int topicId)
{
    switch (topicId)
    {
        case eARM_JOINT:
            return ARM_JOINT;
            break;
            
        case eARM_AXIS:
            return ARM_AXIS;
            break;

        case eARM_CYCLIC:
            return ARM_CYCLIC;
            break;

        case eARM_EXTRA:
            return ARM_EXTRA;
            break;

        default:
            // return empty name for undefined topic
            return "";
    }    
}
}