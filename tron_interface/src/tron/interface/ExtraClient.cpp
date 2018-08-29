/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/ExtraClient.h"
#include "tron/topics/Topic.h"
#include "tron/topics/channels/ExtraSection.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ExtraClient::logger(Logger::getLogger("tron.interface"));

ExtraClient::ExtraClient()
{    
    btuned = false;
    pStopChannel = 0;
    pEndChannel = 0;
}

//ExtraClient::~ExtraClient()
//{    
//}

bool ExtraClient::tune4Node(Node& oNode, int section)
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
        // and add a channel writer for it
        if (oNode.buildTopicName(oTopic))
        {
            oComsSender.addChannel(oTopic.getTopicName());      
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
        // store channel pointers for faster access
        pStopChannel = oComsSender.getChannel(ExtraSection::eEXTRA_STOP);
        pEndChannel = oComsSender.getChannel(ExtraSection::eEXTRA_END);
    }
    
    return btuned;
}

bool ExtraClient::stopNode()
{    
    LOG4CXX_DEBUG(logger, "ExtraClient: stop node  > " << pStopChannel->getTopic());
    return pStopChannel->sendMessage("1");
}

bool ExtraClient::endNode()
{    
    LOG4CXX_DEBUG(logger, "ExtraClient: end node > " << pEndChannel->getTopic());
    return pEndChannel->sendMessage("1");
}

}