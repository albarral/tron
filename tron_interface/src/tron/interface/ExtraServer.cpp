/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/ExtraServer.h"
#include "tron/topics/Topic.h"
#include "tron/topics/channels/ExtraSection.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ExtraServer::logger(Logger::getLogger("tron.interface"));

ExtraServer::ExtraServer()
{    
    btuned = false;
    pStopChannel = 0;
    pEndChannel = 0;
}

//ExtraServer::~ExtraServer()
//{    
//}

bool ExtraServer::tune4Node(Node& oNode, int section)
{
    // set topics 
    int node = oNode.getID();
    int type = tron::Topic::eTYPE_CONTROL;
    
    Topic oTopic;
    // for each channel in section
    for (int channel=0; channel<ExtraSection::eEXTRA_DIM; channel++)
    {
        // set its topic 
        oTopic.set(node, section, channel, type);
        // and add a channel reader for it
        if (oNode.buildTopicName(oTopic))
        {
            oComsReceiver.addChannel(oTopic.getTopicName());      
            btuned = true;
        }
        // break if wrong topic
        else
        {
            btuned = false;
            break;
        }
    }
    
    if (btuned)
    {
        // connect all readers
        oComsReceiver.connect();
        
        // store channel pointers for faster access
        pStopChannel = oComsReceiver.getChannel(ExtraSection::eEXTRA_STOP);
        pEndChannel = oComsReceiver.getChannel(ExtraSection::eEXTRA_END);
    }
    
    return btuned;
}

bool ExtraServer::getStop(float& value)
{    
    std::vector<std::string> listMessages; 
    // if messages received, get last
    if (pStopChannel->getMessages(listMessages) != 0)
    {
        value = std::stof(listMessages.back());
        LOG4CXX_DEBUG(logger, "ExtraServer: get stop > " << std::to_string(value));
        return true;
    }
    else
        return false;
}

bool ExtraServer::getEnd(float& value)
{    
    std::vector<std::string> listMessages; 
    // if messages received, get last
    if (pEndChannel->getMessages(listMessages))
    {
        value = std::stof(listMessages.back());
        LOG4CXX_DEBUG(logger, "ExtraServer: get end > " << std::to_string(value));
        return true;
    }
    else
        return false;
}

}