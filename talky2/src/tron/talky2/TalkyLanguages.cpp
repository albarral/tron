/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/TalkyLanguages.h"
// nodes and topics
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"
#include "tron/robot/topics/BodyTopics.h"
// common talkers
#include "tron/talky2/BasicTalker.h"
// arm talkers
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
// body talkers
#include "tron/talky2/body/ExpressiveTalker.h"
#include "tron/talky2/body/ArtisticTalker.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr TalkyLanguages::logger(Logger::getLogger("tron.talky2"));

Talker* TalkyLanguages::createTalker(int node, int topic)
{
    switch (node)
    {
        case RobotNodes::eNODE_ARM:
            return createTalker4ArmTopic(topic);
            break;

        case RobotNodes::eNODE_BODYROLE:
            return createTalker4BodyTopic(topic);
            break;

        default:
            LOG4CXX_WARN(logger, "TalkyLanguages: can't create talker, unknown node " << std::to_string(node));                                      
            return 0;
    }
}

Talker* TalkyLanguages::createTalker4ArmTopic(int topic)
{
    // create proper talker for arm node topic
    switch (topic)
    {
        case ArmTopics::eARM_JOINT: 
            return new JointTalker();
            break;
            
        case ArmTopics::eARM_AXIS: 
            return new AxisTalker();
            break;
            
        case ArmTopics::eARM_CYCLIC: 
            return new CyclicTalker();
            break;
            
        case ArmTopics::eARM_EXTRA: 
            return new BasicTalker(RobotNodes::eNODE_ARM, ArmTopics::eARM_EXTRA);
            break;
            
        default:
            LOG4CXX_WARN(logger, "TalkyLanguages: can't create talker, unknown arm topic " << std::to_string(topic));                                      
            return 0;
    }    
}

Talker* TalkyLanguages::createTalker4BodyTopic(int topic)
{
    // create proper talker for body node topic
    switch (topic)
    {
        case BodyTopics::eBODY_EXPRESSIVE: 
            return new ExpressiveTalker();
            break;
            
        case BodyTopics::eBODY_ARTISTIC: 
            return new ArtisticTalker();
            break;
                        
        case BodyTopics::eBODY_EXTRA: 
            return new BasicTalker(RobotNodes::eNODE_BODYROLE, BodyTopics::eBODY_EXTRA);
            break;
            
        default:
            LOG4CXX_WARN(logger, "TalkyLanguages: can't create talker, unknown body topic " << std::to_string(topic));                                      
            return 0;
    }    
}
}