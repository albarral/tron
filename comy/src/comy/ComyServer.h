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
    std::string rawMessage;
    
public:
    ComyServer();

   bool isConnected() {return bconnected;};
   virtual void connect() = 0;
               
   // return obtained text
    std::string getRawMessage() {return rawMessage;};

   // read message from client
    virtual bool readMessage() = 0; 
};
}
#endif
