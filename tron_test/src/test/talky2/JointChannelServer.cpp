/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "test/talky2/JointChannelServer.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
JointChannelServer::JointChannelServer() : ChannelServer(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT)
{    
}

//JointListener::~JointListener()
//{    
//}

void JointChannelServer::processCommands()
{    
    int code;
    float value;
    
    if (btuned)    
    {        
        // process received messages
        for (std::string message : listMessages)
        {
            LOG4CXX_TRACE(logger, "JointChannelServer: check msg " << message);
            // if message interpreted, inform joints data
            if (pTalker->interpretMessage(message, code, value))
            {
                switch (code)
                {
                    case JointTalker::eJOINT_HS_POS:
                        LOG4CXX_INFO(logger, "JointChannelServer: command < hs " << std::to_string(value));
                        break;

                    case JointTalker::eJOINT_VS_POS:
                        LOG4CXX_INFO(logger, "JointChannelServer: command < vs " << std::to_string(value));
                        break;

                    case JointTalker::eJOINT_ELB_POS:
                        LOG4CXX_INFO(logger, "JointChannelServer: command < elb " << std::to_string(value));
                        break;

                    case JointTalker::eJOINT_HWRI_POS:
                        LOG4CXX_INFO(logger, "JointChannelServer: command < hwri " << std::to_string(value));
                        break;

                    case JointTalker::eJOINT_VWRI_POS:
                        LOG4CXX_INFO(logger, "JointChannelServer: command < vwri " << std::to_string(value));
                        break;
                }    
            }
            else
            {
                LOG4CXX_WARN(logger, "JointChannelServer: joint command not interpreted");
            }
        }
    }
    else
    {
        LOG4CXX_ERROR(logger, "JointChannelServer: can't process data, communicator not tuned");
        return;
    }        
}

}