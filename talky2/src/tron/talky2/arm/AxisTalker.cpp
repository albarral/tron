/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/AxisTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

namespace tron
{

AxisTalker::AxisTalker() : Talker(RobotNodes::eNODE_ARM, ArmTopics::eARM_AXIS)
{
    // complete name with topic word
    completeName();
    
    // build talker knowledge
    buildKnowledge();    
}

void AxisTalker::completeName()
{
    ArmTopics oArmTopic;
    name += oArmTopic.getName4Topic(topic);    
}

void AxisTalker::buildKnowledge()
{
    addConcept(eAXIS_PAN_POS, AXIS_PAN_POS);
    addConcept(eAXIS_TILT_POS, AXIS_TILT_POS);                         
    addConcept(eAXIS_RAD_POS, AXIS_RAD_POS);                      
    addConcept(eAXIS_PAN_SPEED, AXIS_PAN_SPEED);                   
    addConcept(eAXIS_TILT_SPEED, AXIS_TILT_SPEED);                        
    addConcept(eAXIS_RAD_SPEED, AXIS_RAD_SPEED);                        
    addConcept(eAXIS_KEEP_TILT, AXIS_KEEP_TILT);                         
}
}