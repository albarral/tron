/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/Topic.h"

namespace tron
{    
Topic::Topic()
{
    type = -1;
    name = "";
    built = false;
}

void Topic::set(int node, int section, int channel, int type)
{
    this->node = node;
    this->section = section;
    this->channel = channel;
    if (type >= 0 && type < Topic::eTYPE_DIM)
        this->type = type;
}

std::string Topic::build4Node(Node& oNode)
{
    std::string nodeName = oNode.getName();       
    std::string sectionName = oNode.getName4Section(section);  
    std::string typeName = getTypeName(type); 
    std::string channelName = "";  
    // get channel name from proper node section
    NodeSection* pNodeSection = oNode.getSection(section);
    if (pNodeSection != nullptr)
        channelName = pNodeSection->getName4Channel(channel);        
      
    // if all elements ok, build name
    if (!nodeName.empty() && !sectionName.empty() && !channelName.empty() && !typeName.empty())
    {
        name = nodeName + "/" + sectionName + "/" + typeName + "/" + channelName;
        built = true;
    }
    // otherwise leave empty    
    else
    {
        name = "";
        built = false;
    }
    
    return name;
}

std::string Topic::getTypeName(int type)
{
    switch (type)
    {
        case Topic::eTYPE_CONTROL:
            return Topic::CONTROL_TYPE;
            
        case Topic::eTYPE_SENSOR:
            return Topic::SENSOR_TYPE;

        default: 
            return "";
    }
}

}