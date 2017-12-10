#ifndef __NETY_NETNODEPUBLISHER_H
#define __NETY_NETNODEPUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNode.h"
#include "comy/zero/ComyZeroPublisher.h"

namespace nety
{
// Class used for client network nodes.
class NetNodePublisher : public NetNode
{    
private:
    comy::ComyZeroPublisher oComyPublisher;      // communications publisher for topic-category
        
public:
    NetNodePublisher();
    //~NetNodePublisher();

    // connect node to proper link
    virtual void connect();
    // sends info out to network (OUTPUT NODE)
    virtual bool flush();
    // absorb info from network (INPUT NODE)
    virtual bool absorb() ;
    
};

}
#endif
