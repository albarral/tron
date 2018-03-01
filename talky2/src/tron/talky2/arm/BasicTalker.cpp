/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/BasicTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopic.h"

namespace tron
{

BasicTalker::BasicTalker() : Talker(RobotNodes::eNODE_ARM, ArmTopic::eARM_EXTRA)
{
    // complete name with topic word
    completeName();
    
    // build talker knowledge
    buildKnowledge();    
}

void BasicTalker::completeName()
{
    ArmTopic oArmTopic;
    name += oArmTopic.getTopicName(topic);    
}

void BasicTalker::buildKnowledge()
{
    addConcept(eEXTRA_ARM_STOP, EXTRA_ARM_STOP);
    addConcept(eEXTRA_KEEP_TILT, EXTRA_KEEP_TILT);                         
    addConcept(eEXTRA_ARM_END, EXTRA_AMY_END);                      
}
}