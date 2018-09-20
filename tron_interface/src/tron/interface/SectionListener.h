#ifndef __TRON_INTERFACE_SECTION_LISTENER_H
#define __TRON_INTERFACE_SECTION_LISTENER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "tron/interface/SectionCommunicator.h"
#include "tron/coms/ComsReceiver.h"

namespace tron
{
// Base communication listener class oriented to node sections.
// Listens to info of a given node section through sensor topics.
class SectionListener : public SectionCommunicator
{            
protected:    
    tron::ComsReceiver oComsReceiver;  // communications object     

public:
    SectionListener();
    //~SectionListener();

private:    
    // add channel for specified topic
    virtual void addChannel(std::string topic) override;
    // get all channels connected
    virtual void connect() override;
    
};

}
#endif
