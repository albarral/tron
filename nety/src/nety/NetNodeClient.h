#ifndef __NETY_NETNODECLIENT_H
#define __NETY_NETNODECLIENT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNode.h"
#include "comy/file/ComyFileClient.h"

namespace nety
{
// Class used for client network nodes.
class NetNodeClient : public NetNode
{    
private:
    comy::ComyFileClient oComyClient;      // communications client for topic-category
        
public:
    NetNodeClient();
    //~NetNodeClient();

    // connect node to proper link
    virtual void connect();
    // sends info out to network (OUTPUT NODE)
    virtual bool flush();
    // absorb info from network (INPUT NODE)
    virtual bool absorb() ;
    
};

}
#endif
