/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/Topics.h"

namespace talky
{
// topic names
const std::string Topics::ARM_TOPIC = "arm";    
const std::string Topics::HAND_TOPIC = "hand";    
const std::string Topics::VISION_TOPIC = "vision";    
const std::string Topics::HEAD_TOPIC = "head";    
const std::string Topics::WHEELS_TOPIC = "wheels";     
const std::string Topics::BODYROLE_TOPIC = "body";     
// auxiliary values
const std::string Topics::EMPTY_VALUE = "";        
const std::string Topics::FIELD_SEPARATOR = "*";
const std::string Topics::MSG_SEPARATOR = "#";
const std::string Topics::BLOCK_HEADER = "BLOCK";

std::string Topics::getTopicName(int topicId)
{
    switch (topicId)
    {
        case eTOPIC_ARM:
            return ARM_TOPIC;
            break;
            
        case eTOPIC_HAND:
            return HAND_TOPIC;
            break;

        case eTOPIC_VISION:
            return VISION_TOPIC;
            break;

        case eTOPIC_HEAD:
            return HEAD_TOPIC;
            break;

        case eTOPIC_WHEELS:
            return WHEELS_TOPIC;
            break;

        case eTOPIC_BODYROLE:
            return BODYROLE_TOPIC;
            break;

        default:
            // return empty name for undefined topics
            return "";
    }    
}

}