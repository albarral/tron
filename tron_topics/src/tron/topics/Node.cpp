/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/Node.h"

namespace tron
{    
Node::Node(int id)
{
    ID = id;
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

std::string Node::toString()
{
    return "Node: " + std::to_string(ID) + ", sections:\n" + oSectionsMap.toString();
}

}