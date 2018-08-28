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
    topicName = "";
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

void Topic::buildName()
{
    if (type != -1)
    {
        topicName = nodeName + "/" + sectionName + "/" + Topic::getTypeName(type) + "/" + channelName;
        built = true;
    }
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
            return "undefined";
    }
}

}