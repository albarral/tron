/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>

#include "tron/topics/Node.h"
#include "tron/topics/RobotNodes.h"

namespace tron
{    
Node::Node(int id)
{
    ID = id;
}

Node::~Node()
{    
    listNodeSections.clear();
}

std::string Node::getName4Section(int section)
{
    std::string name;
    if (oSectionsMap.getName4Code(section, name))
        return name;
    // return empty name if unknown code
    else
        return ""; 
}

int Node::getSection4Name(std::string name)
{
    int code;
    if (oSectionsMap.getCode4Name(name, code))
        return code;
    // return invalid code if unknown name
    else 
        return -1;
}

NodeSection* Node::getSection(int sectionCode)
{
    try 
    {
        return &(listNodeSections.at(sectionCode));
    }
    //  return null pointer if section not found
    catch (const std::out_of_range& oor) 
    {
        return nullptr;
    }	    
}

bool Node::buildTopicName(tron::Topic & oTopic)
{
    tron::RobotNodes oRobotNodes;
    // get node name
    oTopic.setNodeName(oRobotNodes.getName4Node(oTopic.getNode()));
    // get section name
    oTopic.setSectionName(getName4Section(oTopic.getSection()));    
    // get channel name
    try 
    {
        NodeSection& oNodeSection = listNodeSections.at(oTopic.getSection());
        oTopic.setChannelName(oNodeSection.getName4Channel(oTopic.getChannel())); 
        oTopic.buildName();                
        return oTopic.isBuilt();
    }
    //  return false if section not found
    catch (const std::out_of_range& oor) 
    {
        return false;
    }	    
}

std::string Node::toString()
{
    return "Node: " + std::to_string(ID) + ", sections:\n" + oSectionsMap.toString();
}

}