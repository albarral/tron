/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionClient.h"
#include "tron/topics/Topic.h"

namespace tron
{
SectionClient::SectionClient() : SectionCommunicator(tron::Topic::eTYPE_CONTROL)
{    
}

//SectionClient::~SectionClient()
//{    
//}

void SectionClient::addChannel(std::string topic)
{
    oComsSender.addChannel(topic);        
}
    
void SectionClient::connect()
{
    //nothing to do (senders don't have a callback)
    return;
}

}