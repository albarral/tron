#ifndef __COMY_PUBLISHER_H
#define __COMY_PUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
// Base class used to publish communication messages
class ComyPublisher
{    
protected:
    bool bconnected;        // connected to amy interface
        
public:
    ComyPublisher();

    bool isConnected() {return bconnected;};
   
    virtual void connect() = 0;
   // info publishing method (specific for each ComyPublisher implementation)
    virtual bool publishMessage(std::string rawMessage) = 0;
};
}
#endif
