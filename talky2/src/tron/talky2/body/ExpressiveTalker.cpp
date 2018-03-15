/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/body/ExpressiveTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/BodyTopics.h"

namespace tron
{
ExpressiveTalker::ExpressiveTalker() : Talker(RobotNodes::eNODE_BODYROLE, BodyTopics::eBODY_EXPRESSIVE)
{
    // complete name with topic word
    completeName();
    
    // build talker knowledge
    buildKnowledge();    
}

void ExpressiveTalker::completeName()
{
    BodyTopics oBodyTopics;
    name += oBodyTopics.getName4Topic(topic);    
}

void ExpressiveTalker::buildKnowledge()
{
    addConcept(eEXPRESS_FEELING, EXPRESS_FEELING);                        
    addConcept(eEXPRESS_HALT, EXPRESS_HALT);                        
}
}