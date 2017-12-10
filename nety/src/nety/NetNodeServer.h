#ifndef __NETY_NETNODESERVER_H
#define __NETY_NETNODESERVER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNode.h"
#include "comy/zero/ComyZeroServer.h"
//#include "comy/file/ComyFileServer.h"

namespace nety
{
// Class used for client network nodes.
class NetNodeServer : public NetNode
{    
private:
    comy::ComyZeroServer oComyServer;      // communications server for topic-category
        
public:
    NetNodeServer();
    //~NetNodeServer();

    // connect node to proper link
    virtual void connect();
    // sends info out to network (OUTPUT NODE)
    virtual bool flush();
    // absorb info from network (INPUT NODE)
    virtual bool absorb() ;
    
};

}
#endif
