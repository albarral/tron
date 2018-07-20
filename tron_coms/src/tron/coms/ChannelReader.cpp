/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/ChannelReader.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ChannelReader::logger(Logger::getLogger("tron.com"));

const std::string ChannelReader::CONTROL_CHANNEL = "co";     
const std::string ChannelReader::SENSOR_CHANNEL = "so";       
const std::string ChannelReader::PARAM_CHANNEL = "par";         

ChannelReader::ChannelReader()
{    
    type = ChannelReader::eCHANNEL_UNDEFINED;
    bconnected = false;
}

//ChannelReader::~ChannelReader()
//{    
//}

void ChannelReader::setChannel(std::string node, std::string section, std::string channel, int type)
{
    nodeName = node;
    sectionName = section;
    channelName = channel;
    if (type > ChannelReader::eCHANNEL_UNDEFINED && type < ChannelReader::eCHANNEL_DIM)
    {
        this->type = type;
        topic = nodeName + "/" + sectionName + "/" + ChannelReader::getTypeName(type) + "/" + channelName;
    }
}
    
std::string ChannelReader::getTypeName(int type)
{
    switch (type)
    {
        case ChannelReader::eCHANNEL_CONTROL:
            return ChannelReader::CONTROL_CHANNEL;
            
        case ChannelReader::eCHANNEL_SENSOR:
            return ChannelReader::SENSOR_CHANNEL;

        case ChannelReader::eCHANNEL_PARAM:
            return ChannelReader::PARAM_CHANNEL;

        default: 
            return "undefined";
    }
}

}