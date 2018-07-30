#ifndef __TRON_COMS_COMSRECEIVER_H
#define __TRON_COMS_COMSRECEIVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/coms/Communicator.h"
#include "tron/coms/ChannelReader.h"

namespace tron
{
// ComsReceiver base class for communication receivers (servers & listeners).
// Uses multiple channel readers.
class ComsReceiver : public Communicator
{    
protected:
    std::vector<ChannelReader> listChannelReaders;
        
public:
    ComsReceiver();
    ~ComsReceiver();
       
    // add channel reader for given topic
    virtual void addChannel(std::string topic) override;
        
    // get specified channel reader
    ChannelReader* getChannel(int i);

    virtual std::string toString() override;
};

}
#endif
