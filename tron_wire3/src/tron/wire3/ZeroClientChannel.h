#ifndef ZEROCLIENTCHANNEL_H
#define ZEROCLIENTCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/wire3/ZeroCommunicator.h"
#include "tron/wire/channel/ClientChannel.h"


namespace tron
{
    class ZeroClientChannel : public ClientChannel, public ZeroCommunicator {
        private:

        public:
            ZeroClientChannel();
            ZeroClientChannel(int node, int channel);
            ~ZeroClientChannel();

            // open channel
            virtual bool open();
            // close channel
            virtual bool close();
            // send message to destination, returns false if nothing sent
            virtual bool sendMsg(std::string message);
            // send messages to destination, returns false if nothing sent
            virtual bool sendMessages(std::vector<std::string>& listMessages);  

    };
}

#endif /* ZEROCLIENTCHANNEL_H */

