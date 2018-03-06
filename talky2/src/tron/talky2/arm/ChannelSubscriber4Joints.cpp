/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ChannelSubscriber4Joints.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
ChannelSubscriber4Joints::ChannelSubscriber4Joints() : ChannelSubscriber(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT)
{    
}

//JointListener::~JointListener()
//{    
//}

void ChannelSubscriber4Joints::processData()
{    
    int code;
    float value;
    
    if (btuned)    
    {        
        // process received messages
        for (std::string message : listMessages)
        {
            LOG4CXX_TRACE(logger, "ChannelSubscriber4Joints: check msg " << message);
            // if message interpreted, inform joints data
            if (pTalker->interpretMessage(message, code, value))
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
            else
            {
                LOG4CXX_WARN(logger, "ChannelSubscriber4Joints: joint position not interpreted");
            }
        }
    }
    else
    {
        LOG4CXX_ERROR(logger, "ChannelSubscriber4Joints: can't process data, communicator not tuned");
        return;
    }        
}

}