#ifndef __COMY_CLIENT_H
#define __COMY_CLIENT_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
// Base class used to transmit messages to a server.
class ComyClient
{        
protected:
    bool bconnected;        // connected to server
    
public:
    ComyClient();

    bool isConnected() {return bconnected;};
    //virtual void connect() = 0;

    // send message to server (specific for each ComyClient implementation)
    virtual void sendMessage(std::string text) = 0;
};
}
#endif
