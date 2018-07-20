/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ComsChannel.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ComsChannel::logger(Logger::getLogger("tron.com"));

const std::string ComsChannel::CONTROL_CHANNEL = "co";     
const std::string ComsChannel::SENSOR_CHANNEL = "so";       
const std::string ComsChannel::PARAM_CHANNEL = "par";         

ComsChannel::ComsChannel()
{    
    type = ComsChannel::eCHANNEL_UNDEFINED;
    bconnected = false;
}

//ComsChannel::~ComsChannel()
//{    
//}

void ComsChannel::setChannel(std::string node, std::string section, std::string channel, int type)
{
    nodeName = node;
    sectionName = section;
    channelName = channel;
    if (type > ComsChannel::eCHANNEL_UNDEFINED && type < ComsChannel::eCHANNEL_DIM)
    {
        this->type = type;
        topic = nodeName + "/" + sectionName + "/" + ComsChannel::getTypeName(type) + "/" + channelName;
    }
}
    
std::string ComsChannel::getTypeName(int type)
{
    switch (type)
    {
        case ComsChannel::eCHANNEL_CONTROL:
            return ComsChannel::CONTROL_CHANNEL;
            
        case ComsChannel::eCHANNEL_SENSOR:
            return ComsChannel::SENSOR_CHANNEL;

        case ComsChannel::eCHANNEL_PARAM:
            return ComsChannel::PARAM_CHANNEL;

        default: 
            return "undefined";
    }
}

}