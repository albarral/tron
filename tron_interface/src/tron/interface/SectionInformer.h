#ifndef __TRON_INTERFACE_SECTION_INFORMER_H
#define __TRON_INTERFACE_SECTION_INFORMER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionCommunicator.h"
#include "tron/coms/ComsSender.h"

namespace tron
{
// Base communication informer class oriented to node sections.
// Broadcasts info of a given node section through sensor topics.
class SectionInformer : public SectionCommunicator
{            
protected:    
    tron::ComsSender oComsSender;  // communications object     

public:
    SectionInformer();
    //~SectionInformer();

private:    
    // add channel for specified topic
    virtual void addChannel(std::string topic) override;
    // get all channels connected
    virtual void connect() override;
    
};

}
#endif
