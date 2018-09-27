#ifndef __TRON_INTERFACE_SECTION_SERVER_H
#define __TRON_INTERFACE_SECTION_SERVER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "tron/interface/SectionCommunicator.h"
#include "tron/coms/ComsReceiver.h"

namespace tron
{
// Base communication server class oriented to node sections.
// Serves requests received through control topics.
class SectionServer : public SectionCommunicator
{            
protected:    
    tron::ComsReceiver oComsReceiver;  // communications object     

public:
    SectionServer();
    //~SectionServer();

private:    
    // add channel for specified topic
    virtual void addChannel(std::string topic) override;
    // get all channels connected
    virtual void connect() override;
    
};

}
#endif
