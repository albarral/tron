/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionListener.h"
#include "tron/topics/Topic.h"

namespace tron
{
SectionListener::SectionListener() : SectionCommunicator(tron::Topic::eTYPE_SENSOR)
{    
}

//SectionListener::~SectionListener()
//{    
//}

void SectionListener::addChannel(std::string topic)
{
    oComsReceiver.addChannel(topic);        
}
    
void SectionListener::connect()
{
    // connect all readers
    oComsReceiver.connect();
}

}