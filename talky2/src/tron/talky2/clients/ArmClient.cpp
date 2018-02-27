/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/clients/ArmClient.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopic.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ArmClient::logger(Logger::getLogger("tron.talky2"));

ArmClient::ArmClient()
{    
}

//ArmClient::~ArmClient()
//{    
//}

bool ArmClient::setHS(float value)
{    
    if (oJointTalker.buildMessage(JointTalker::eJOINT_HS_POS, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopic::eARM_JOINT, message);
    }
    else
        return false;
}

}