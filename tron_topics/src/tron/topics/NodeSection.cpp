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

std::string NodeSection::toString()
{
    return "NodeSection: " + std::to_string(ID) + ", channels:\n" + oChannelsMap.toString();
}

}