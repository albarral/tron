/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/BodyTopics.h"

namespace tron
{    
const std::string BodyTopics::BODY_COMFORTABLE = "comfort";
const std::string BodyTopics::BODY_EXPRESSIVE = "express";
const std::string BodyTopics::BODY_ARTISTIC = "art";
const std::string BodyTopics::BODY_EXTRA = "extra";    

BodyTopics::BodyTopics()
{
    // build topics map
    oTopicsMap.addCode(eBODY_COMFORTABLE, BODY_COMFORTABLE);
    oTopicsMap.addCode(eBODY_EXPRESSIVE, BODY_EXPRESSIVE);
    oTopicsMap.addCode(eBODY_ARTISTIC, BODY_ARTISTIC);
    oTopicsMap.addCode(eBODY_EXTRA, BODY_EXTRA);
}

std::string BodyTopics::getName4Topic(int topic)
{
    std::string name;
    if (oTopicsMap.getName4Code(topic, name))
        return name;
    // return empty name if unknown topic
    else
        return ""; 
}

int BodyTopics::getCode4Topic(std::string topicName)
{
    int code;
    if (oTopicsMap.getCode4Name(topicName, code))
        return code;
    // return -1 if unknown topic
    else 
        return -1;
}

}