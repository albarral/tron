#include "ZeroClientChannel.h"

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/


namespace tron
{
    ZeroClientChannel::ZeroClientChannel(int node, int channel) : ClientChannel(node, channel)
    {
        setPort(node, channel);
    }

    ZeroClientChannel::~ZeroClientChannel()
    {
        oZeroClient->disconnect();
    }

    bool ZeroClientChannel::open()
    {
        oZeroClient = new ZeroClient(getPort(),0);
        return oZeroClient->connect();
    }

    bool ZeroClientChannel::close()
    {        
        oZeroClient->disconnect();
        return true;
    }

    bool ZeroClientChannel::sendMsg(std::string message)
    {
        std::vector<std::string> messages;
        messages.push_back(message);
        return oZeroClient->send(messages);
    }

    bool ZeroClientChannel::sendMessages(std::vector<std::string>& listMessages)
    {
        return oZeroClient->send(listMessages);
    }
}

