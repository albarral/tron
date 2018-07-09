#ifndef ZEROWIRE_H
#define ZEROWIRE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

#include "tron/wire/Wire.h"
#include "tron/wire/channel/InputChannel.h"
#include "tron/wire/channel/OutputChannel.h"

namespace tron{
    
class ZeroWire :public Wire {
     public:
         ZeroWire();
         ~ZeroWire();
     private:
         virtual OutputChannel* createClientChannel(int node, int channel);
         virtual InputChannel* createServerChannel(int node, int channel);
         
         virtual OutputChannel* createPublishChannel(int node, int channel);
         virtual InputChannel* createSubscriberChannel(int node, int channel);

}; 
}


#endif /* ZEROWIRE_H */

