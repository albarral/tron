#ifndef __COMY_SUBSCRIBER_H
#define __COMY_SUBSCRIBER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
// Base class used to subscribe to communication messages.
class ComySubscriber
{    
protected:
    bool bconnected;              // connected to channel
    std::string rawMessage;     // received message
        
public:
    ComySubscriber();

   bool isConnected() {return bconnected;};
    // return obtained text
    std::string getRawMessage() {return rawMessage;};

       
   virtual void connect() = 0;
   // info reading method 
    virtual bool readMessage() = 0;
};
}
#endif
