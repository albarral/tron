/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/coms/Communicator.h"

using namespace log4cxx;

namespace tron
{
Communicator::Communicator()
{    
    pChannelReader = 0;
    pChannelWriter = 0;
}

Communicator::~Communicator()
{
    if (pChannelReader != 0)
        delete(pChannelReader);

    if (pChannelWriter != 0)
        delete(pChannelWriter);    
}

void Communicator::setChannelReader(std::string topic)
{
    pChannelReader = new ChannelReader();
    pChannelReader->setTopic(topic);
    pChannelReader->connect(oNode);
}
    
void Communicator::setChannelWriter(std::string topic)
{
    pChannelWriter = new ChannelWriter();
    pChannelWriter->setTopic(topic);
    pChannelWriter->connect(oNode);
}

}