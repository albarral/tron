#ifndef ZEROSERVERCHANNEL_H
#define ZEROSERVERCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire3/ZeroCommunicator.h"
#include "tron/wire/channel/ServerChannel.h"
#include "tron/tools/ZeroServer.h"

namespace tron {
    
class ZeroServerChannel  : public ServerChannel, public ZeroCommunicator {
    
    private:
        ZeroServer* oZeroServer;
        
    public:
        ZeroServerChannel(int node, int channel);
        ~ZeroServerChannel();
        virtual bool open();
        virtual bool close();
        virtual bool receivedMessages(std::vector<std::string>& listMessages);

};
}


#endif /* ZEROSERVERCHANNEL_H */

