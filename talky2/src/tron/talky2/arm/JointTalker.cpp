/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/JointTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

namespace tron
{

JointTalker::JointTalker() : Talker(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT)
{
    // complete name with topic word
    completeName();
    
    // build talker knowledge
    buildKnowledge();    
}

void JointTalker::completeName()
{
    ArmTopics oArmTopic;
    name += oArmTopic.getName4Topic(topic);    
}

void JointTalker::buildKnowledge()
{
    addConcept(eJOINT_HS_POS, JOINT_HS_POS);
    addConcept(eJOINT_VS_POS, JOINT_VS_POS);                         
    addConcept(eJOINT_ELB_POS, JOINT_ELB_POS);                      
    addConcept(eJOINT_HWRI_POS, JOINT_HWRI_POS);                   
    addConcept(eJOINT_VWRI_POS, JOINT_VWRI_POS);                        
}
}