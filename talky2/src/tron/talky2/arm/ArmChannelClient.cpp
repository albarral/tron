/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmChannelClient.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
#include "tron/talky2/arm/BasicTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
ArmChannelClient::ArmChannelClient(int topic) : ChannelClient(RobotNodes::eNODE_ARM, topic)
{    
    createTalker4ArmTopic(topic);
}

//ArmChannelClient::~ArmChannelClient()
//{    
//}

void ArmChannelClient::createTalker4ArmTopic(int topic)
{
    // create proper talker for arm node topic
    switch (topic)
    {
        case ArmTopics::eARM_JOINT: 
            pTalker = new JointTalker();
            break;
            
        case ArmTopics::eARM_AXIS: 
            pTalker = new AxisTalker();
            break;
            
        case ArmTopics::eARM_CYCLIC: 
            pTalker = new CyclicTalker();
            break;
            
        case ArmTopics::eARM_EXTRA: 
            pTalker = new BasicTalker();
            break;
            
        default:
            pTalker = 0;
            LOG4CXX_WARN(logger, identity + ": can't create talker for arm topic, unknown topic " << std::to_string(topic));                                      
            break;
    }    
}

}