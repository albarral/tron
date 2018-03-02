/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmListener.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ArmListener::logger(Logger::getLogger("tron.talky2"));

ArmListener::ArmListener()
{    
}

//ArmListener::~ArmListener()
//{    
//}

bool ArmListener::getJointPositions(JointsData& jointsData)
{    
    int code;
    float value;
    // hear messages in joints channel
    if (oWire.hearMessages(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT, listMessages))
    {
        // process received messages
        for (std::string message : listMessages)
        {
            LOG4CXX_TRACE(logger, "ArmListener: check msg " << message);
            // if message interpreted, inform joints data
            if (oJointTalker.interpretMessage(message, code, value))
            {
                informJointsData(jointsData, code, value);
            }
            else
            {
                LOG4CXX_WARN(logger, "ArmListener: joint position not interpreted");
            }
        }
        return true;
    }
    // if no messages could be read
    else
        return false;
}

void ArmListener::informJointsData(JointsData& jointsData, int code, float value)
{
    switch (code)
    {
        case JointTalker::eJOINT_HS_POS:
            jointsData.hs = value;
            break;

        case JointTalker::eJOINT_VS_POS:
            jointsData.vs = value;
            break;

        case JointTalker::eJOINT_ELB_POS:
            jointsData.elb = value;
            break;

        case JointTalker::eJOINT_HWRI_POS:
            jointsData.hwri = value;
            break;

        case JointTalker::eJOINT_VWRI_POS:
            jointsData.vwri = value;
            break;
    }    
}

}