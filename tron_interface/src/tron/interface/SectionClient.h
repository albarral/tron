#ifndef __TRON_INTERFACE_SECTION_CLIENT_H
#define __TRON_INTERFACE_SECTION_CLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionCommunicator.h"
#include "tron/coms/ComsSender.h"

namespace tron
{
// Base communication client class oriented to node sections.
// Sends requests through control topics.
class SectionClient : public SectionCommunicator
{            
protected:    
    tron::ComsSender oComsSender;  // communications object     

public:
    SectionClient();
    //~SectionClient();

private:    
    // add channel for specified topic
    virtual void addChannel(std::string topic) override;
    // get all channels connected
    virtual void connect() override;
    
};

}
#endif
