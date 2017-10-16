#ifndef __COMY_SERVER_H
#define __COMY_SERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
// Base class used to listen to messages from clients.
class ComyServer
{    
protected:
    bool bconnected;        // connected to client
    std::string rawMessage;     // received message
    
public:
    ComyServer();

   bool isConnected() {return bconnected;};               
   // return obtained text
    std::string getRawMessage() {return rawMessage;};

   virtual void connect() = 0;
   // read message from client, returns false if nothing read
    virtual bool readMessage() = 0; 
};
}
#endif
