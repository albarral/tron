#ifndef __COMY_PUBLISHER_H
#define __COMY_PUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "comy/ComyNode.h"

namespace comy
{
// Base class used to publish communication messages
class ComyPublisher : public ComyNode
{            
public:
    ComyPublisher();
   
   // info publishing method (specific for each ComyPublisher implementation)
    virtual bool publishMessage(std::string rawMessage) = 0;
};
}
#endif
