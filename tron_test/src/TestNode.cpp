/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestNode.h"
#include "tron/topics/NodeSection.h"
#include "tron/topics/RobotNodes.h"

TestNode::TestNode() : tron::Node(tron::RobotNodes::eNODE_ARM)
{
    oSectionsMap.addCode(eSECTION_JOINTS, SECTION_JOINTS);
    oSectionsMap.addCode(eSECTION_AXES, SECTION_AXES);
    
    setJointsSection();
    setAxesSection();
}

void TestNode::setJointsSection()
{
    tron::NodeSection oJointsSection(eSECTION_JOINTS);
    
    oJointsSection.addChannel(eJOINTS_HS, JOINTS_HS);
    oJointsSection.addChannel(eJOINTS_VS, JOINTS_VS);                         
    oJointsSection.addChannel(eJOINTS_ELB, JOINTS_ELB);                      
    
    listNodeSections.push_back(oJointsSection);    
}

void TestNode::setAxesSection()
{
    tron::NodeSection oAxesSection(eSECTION_AXES);
    
    oAxesSection.addChannel(eAXES_PAN, AXES_PAN);
    oAxesSection.addChannel(eAXES_TILT, AXES_TILT);                         
    oAxesSection.addChannel(eAXES_RAD, AXES_RAD);                      
    
    listNodeSections.push_back(oAxesSection);        
}

std::string TestNode::toString()
{
    return "TestNode\n" + tron::Node::toString();
}
