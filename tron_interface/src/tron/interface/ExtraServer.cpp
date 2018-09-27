/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/ExtraServer.h"
#include "tron/topics/channels/ExtraSection.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ExtraServer::logger2(Logger::getLogger("tron.interface"));

ExtraServer::ExtraServer()
{    
    pStopChannel = 0;
    pEndChannel = 0;
}

//ExtraServer::~ExtraServer()
//{    
//}

bool ExtraServer::init(Node& oNode, int section)
{
    // set topics for control of given node extra section
    tron::SectionServer::tune4Node(oNode, section);

    if (isTuned())
    {
        // store channel pointers for faster access
        pStopChannel = oComsReceiver.getChannel(ExtraSection::eEXTRA_STOP);
        pEndChannel = oComsReceiver.getChannel(ExtraSection::eEXTRA_END);
    }
    
    return btuned;
}

bool ExtraServer::getStop()
{    
    // if stop command received, get it
    if (pStopChannel->hasNew())
    {
        pStopChannel->clear();
        LOG4CXX_DEBUG(logger2, "ExtraServer: stop received >");
        return true;
    }
    else
        return false;
}

bool ExtraServer::getEnd()
{    
    // if end command received, get it
    if (pEndChannel->hasNew())
    {
        pEndChannel->clear();
        LOG4CXX_DEBUG(logger2, "ExtraServer: end received >");
        return true;
    }
    else
        return false;
}

}