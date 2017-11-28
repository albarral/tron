#ifndef __NETY_NETNODESUBSCRIBER_H
#define __NETY_NETNODESUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNode.h"
#include "comy/file/ComyFileSubscriber.h"

namespace nety
{
// Class used for client network nodes.
class NetNodeSubscriber : public NetNode
{    
private:
    comy::ComyFileSubscriber oComySubscriber;      // communications subscriber for topic-category
        
public:
    NetNodeSubscriber();
    //~NetNodeSubscriber();

    // connect node to proper link
    virtual void connect();
    // sends info out to network (OUTPUT NODE)
    virtual bool flush();
    // absorb info from network (INPUT NODE)
    virtual bool absorb() ;
    
};

}
#endif
