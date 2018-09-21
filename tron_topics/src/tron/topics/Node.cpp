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
    // set proper node name        
    tron::RobotNodes oRobotNodes;
    name = oRobotNodes.getName4Node(ID);
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

std::string Node::toString()
{
    return "Node: " + std::to_string(ID) + ", sections:\n" + oSectionsMap.toString();
}

}