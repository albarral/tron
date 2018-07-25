#ifndef __TRON_COMS_COMMUNICATOR_H
#define __TRON_COMS_COMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <ignition/transport.hh>

#include "tron/coms/ChannelReader.h"
#include "tron/coms/ChannelWriter.h"

namespace tron
{
// Communicator class holding channel readers and writers
// Based in ignition transport lib.
class Communicator
{    
private:
    ignition::transport::Node oNode;    
    ChannelReader* pChannelReader;
    ChannelWriter* pChannelWriter;
        
public:
    Communicator();
    ~Communicator();
    
    void setChannelReader(std::string topic);
    void setChannelWriter(std::string topic);

    ChannelReader* getChannelReader() {return pChannelReader;};
    ChannelWriter* getChannelWriter() {return pChannelWriter;};
};

}
#endif
