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
    bool benabled;    
    std::string rawMessage;
        
public:
    ComySubscriber();

   virtual void init() = 0;
   bool isEnabled() {return benabled;};
       
   // info reading method 
    virtual bool readInfo() = 0;
};
}
#endif
