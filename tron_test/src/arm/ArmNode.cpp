/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include "amy/interface/ArmNode.h"
#include "ArmNode.h"
#include "tron/topics/RobotNodes.h"
#include "tron/topics/ExtraSection.h"
//#include "amy/interface/topics/JointsSection.h"
#include "arm/JointsSection.h"
//#include "amy/interface/topics/AxesSection.h"
#include "arm/AxesSection.h"
//#include "amy/interface/topics/CyclerSection.h"
#include "arm/CyclerSection.h"

namespace amy
{    

ArmNode::ArmNode() : tron::Node(tron::RobotNodes::eNODE_ARM)
{
    oSectionsMap.addCode(ArmNode::eSECTION_JOINTS, ArmNode::SECTION_JOINTS);
    oSectionsMap.addCode(ArmNode::eSECTION_AXES, ArmNode::SECTION_AXES);
    oSectionsMap.addCode(ArmNode::eSECTION_CYCLER1, ArmNode::SECTION_CYCLER1);
    oSectionsMap.addCode(ArmNode::eSECTION_CYCLER2, ArmNode::SECTION_CYCLER2);
    oSectionsMap.addCode(ArmNode::eSECTION_EXTRA, tron::ExtraSection::EXTRA_SECTION);
}

tron::NodeSection* ArmNode::getSection(int sectionCode)
{
    switch (sectionCode)
    {
        case ArmNode::eSECTION_JOINTS:
            return new JointsSection();

        case ArmNode::eSECTION_AXES:
            return new AxesSection();
            
        case ArmNode::eSECTION_CYCLER1:
        case ArmNode::eSECTION_CYCLER2:
            return new CyclerSection();
        
        case ArmNode::eSECTION_EXTRA: 
            return new tron::ExtraSection();

        default:
            return nullptr;
    }            
}

tron::Topic ArmNode::getTopic(int node, int section, int channel, int type)
{
    tron::Topic oTopic;
    oTopic.set(node, section, channel, type);
    
    oTopic.setNodeName(tron::RobotNodes::getName4Node(node));
    oTopic.setSectionName(getName4Section(section));    
    tron::NodeSection* pNodeSection = getSection(section);
    if (pNodeSection != nullptr)
    {
        oTopic.setChannelName(pNodeSection->getName4Channel(channel)); 
        oTopic.build();
        delete (pNodeSection);
    }
    
    return oTopic;
}

std::string ArmNode::toString()
{
    return "ArmNode\n" + tron::Node::toString();
}
}