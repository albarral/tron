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
    bool benabled;        // connected to amy interface
        
public:
    ComyPublisher();

    virtual void init() = 0;
    bool isEnabled() {return benabled;};
   
   // info publishing method (specific for each ComyPublisher implementation)
    virtual void publishInfo(std::string rawMessage) = 0;
};
}
#endif
