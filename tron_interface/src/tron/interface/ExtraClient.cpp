/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/ExtraClient.h"
#include "tron/topics/channels/ExtraSection.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ExtraClient::logger2(Logger::getLogger("tron.interface"));

ExtraClient::ExtraClient()
{    
    pStopChannel = 0;
    pEndChannel = 0;
}

//ExtraClient::~ExtraClient()
//{    
//}

bool ExtraClient::init(Node& oNode, int section)
{
    // set topics for control of given node extra section
    tron::SectionClient::tune4Node(oNode, section);

    if (isTuned())
    {
        // store channel pointers for faster access
        pStopChannel = oComsSender.getChannel(ExtraSection::eEXTRA_STOP);
        pEndChannel = oComsSender.getChannel(ExtraSection::eEXTRA_END);
    }
    
    return btuned;
}

bool ExtraClient::stopNode()
{    
    LOG4CXX_DEBUG(logger2, "ExtraClient: stop node  > " << pStopChannel->getTopic());
    return pStopChannel->sendMessage("1");
}

bool ExtraClient::endNode()
{    
    LOG4CXX_DEBUG(logger2, "ExtraClient: end node > " << pEndChannel->getTopic());
    return pEndChannel->sendMessage("1");
}

}