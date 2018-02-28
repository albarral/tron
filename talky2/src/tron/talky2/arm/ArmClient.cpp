/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmClient.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopic.h"

using namespace log4cxx;

namespace tron
{
ArmClient::ArmClient()
{    
}

//ArmClient::~ArmClient()
//{    
//}

bool ArmClient::setHS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: send HS > " << std::to_string(value));
    if (oJointTalker.buildMessage(JointTalker::eJOINT_HS_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}

bool ArmClient::setVS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: send VS > " << std::to_string(value));
    if (oJointTalker.buildMessage(JointTalker::eJOINT_VS_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}

bool ArmClient::setELB(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: send ELB > " << std::to_string(value));
    if (oJointTalker.buildMessage(JointTalker::eJOINT_ELB_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}

bool ArmClient::setHWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: send HWRI > " << std::to_string(value));
    if (oJointTalker.buildMessage(JointTalker::eJOINT_HWRI_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}

bool ArmClient::setVWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: send VWRI > " << std::to_string(value));
    if (oJointTalker.buildMessage(JointTalker::eJOINT_VWRI_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}
}