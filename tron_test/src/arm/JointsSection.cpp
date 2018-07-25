/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include "amy/interface/topics/JointsSection.h"
#include "arm/JointsSection.h"
//#include "amy/interface/ArmNode.h"
#include "arm/ArmNode.h"

namespace amy
{

JointsSection::JointsSection() : tron::NodeSection(ArmNode::eSECTION_JOINTS)
{    
    oChannelsMap.addCode(eJOINTS_HS, JOINTS_HS);
    oChannelsMap.addCode(eJOINTS_VS, JOINTS_VS);                         
    oChannelsMap.addCode(eJOINTS_ELB, JOINTS_ELB);                      
    oChannelsMap.addCode(eJOINTS_HWRI, JOINTS_HWRI);                   
    oChannelsMap.addCode(eJOINTS_VWRI, JOINTS_VWRI);                        
}
}