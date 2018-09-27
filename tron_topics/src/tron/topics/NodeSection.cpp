/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/NodeSection.h"

namespace tron
{        
NodeSection::NodeSection(int id)
{
    ID = id;
}

std::string NodeSection::getName4Channel(int channel)
{
    std::string name;
    if (oChannelsMap.getName4Code(channel, name))
        return name;
    // return empty name if unknown code
    else
        return ""; 
}

int NodeSection::getChannel4Name(std::string name)
{
    int code;
    if (oChannelsMap.getCode4Name(name, code))
        return code;
    // return invalid code if unknown name
    else 
        return -1;
}

void NodeSection::addChannel(int code, std::string name)
{
    oChannelsMap.addCode(code, name);
}

std::string NodeSection::toString()
{
    return "NodeSection: " + std::to_string(ID) + ", channels:\n" + oChannelsMap.toString();
}

}