#ifndef __TRON_COMS_COMSSENDER_H
#define __TRON_COMS_COMSSENDER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/coms/Communicator.h"
#include "tron/coms/ChannelWriter.h"

namespace tron
{
// Class for multi channel communications sending (communication clients & broadcasters).
// Uses ignition based channel writers.
class ComsSender : public Communicator
{    
private:
    std::vector<ChannelWriter> listChannelWriters;  // list of channel writers
        
public:
    ComsSender();
    ~ComsSender();
    
    // add channel writer for given topic
    virtual void addChannel(std::string topic) override;
        
    // get specified channel writer
    ChannelWriter* getChannel(int i);

    virtual std::string toString() override;
};

}
#endif
