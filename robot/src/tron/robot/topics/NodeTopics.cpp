/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/NodeTopics.h"

namespace tron
{    
//NodeTopics::NodeTopics()
//{
//}

std::string NodeTopics::getName4Topic(int topic)
{
    std::string name;
    if (oTopicsMap.getName4Code(topic, name))
        return name;
    // return empty name if unknown topic
    else
        return ""; 
}

int NodeTopics::getCode4Topic(std::string topicName)
{
    int code;
    if (oTopicsMap.getCode4Name(topicName, code))
        return code;
    // return -1 if unknown topic
    else 
        return -1;
}

std::string NodeTopics::getMapDescription()
{
    return oTopicsMap.toString();
}

}