/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionInformer.h"
#include "tron/topics/Topic.h"

namespace tron
{
SectionInformer::SectionInformer() : SectionCommunicator(tron::Topic::eTYPE_SENSOR)
{    
}

//SectionInformer::~SectionInformer()
//{    
//}

void SectionInformer::addChannel(std::string topic)
{
    oComsSender.addChannel(topic);        
}
    
void SectionInformer::connect()
{
    //nothing to do (senders don't have a callback)
    return;
}

}