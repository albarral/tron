/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionServer.h"
#include "tron/topics/Topic.h"

namespace tron
{
SectionServer::SectionServer() : SectionCommunicator(tron::Topic::eTYPE_CONTROL)
{    
}

//SectionServer::~SectionServer()
//{    
//}

void SectionServer::addChannel(std::string topic)
{
    oComsReceiver.addChannel(topic);        
}
    
void SectionServer::connect()
{
    // connect all readers
    oComsReceiver.connect();
}

}