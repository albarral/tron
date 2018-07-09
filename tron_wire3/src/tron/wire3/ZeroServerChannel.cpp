#include "ZeroServerChannel.h"

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/
namespace tron{
    
ZeroServerChannel::ZeroServerChannel(int node, int channel) {
    setPort(node, channel);
}

ZeroServerChannel::~ZeroServerChannel() {
    oZeroServer->stop();
}

bool ZeroServerChannel::open(){
    oZeroServer = new ZeroServer(getPort(), 0);
    return oZeroServer->start();
}

bool ZeroServerChannel::close(){
    oZeroServer->stop();
    return oZeroServer->isStarted_;
}

bool ZeroServerChannel::receivedMessages(std::vector<std::string>& listMessages){
    listMessages = oZeroServer->receive();
    if(listMessages.size()>0)
        return true;
    else
        return false;
}

}

