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
// Class for multi channel communications reception (communication servers & listeners).
// Uses ignition based channel readers.
// Needs to be connected once the channels are defined.
class ComsReceiver : public Communicator
{    
private:
    std::vector<ChannelReader> listChannelReaders;
        
public:
    ComsReceiver();
    ~ComsReceiver();
       
    // add channel reader for given topic
    virtual void addChannel(std::string topic) override;
    
    // connect all channel readers to their topics
    void connect();
        
    // get specified channel reader
    ChannelReader* getChannel(int i);

    virtual std::string toString() override;
};

}
#endif
