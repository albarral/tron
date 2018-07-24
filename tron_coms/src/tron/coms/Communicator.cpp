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

void Communicator::setChannelReader(std::string node, std::string section, std::string channel, int type)
{
    pChannelReader = new ChannelReader();
    pChannelReader->setChannel(node, section, channel, type);
    pChannelReader->connect(oNode);
}
    
void Communicator::setChannelWriter(std::string node, std::string section, std::string channel, int type)
{
    pChannelWriter = new ChannelWriter();
    pChannelWriter->setChannel(node, section, channel, type);
    pChannelWriter->connect(oNode);
}

}