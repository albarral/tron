#ifndef COMYZEROCLIENT_H
#define COMYZEROCLIENT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComyClient.h"
#include "zmq.hpp"
#include "zhelpers.hpp"

namespace comy
{
    class ComyZeroClient : public ComyClient
    {    
        private:
        static log4cxx::LoggerPtr logger;    
        const char delimiter = '\n'; // newline used as delimiter for strings (default used by std::getline())
        zmq::context_t contextClient;
        zmq::socket_t socketClient;

    public:
        ComyZeroClient();
        ~ComyZeroClient();
        
        virtual void connect(std::string topic, std::string category) override;
        virtual void connectZero(std::string topic, std::string category, int port) override;
       // send message to server, returns false if nothing sent
        virtual bool sendMessage(std::string text) override;

    };
}


#endif /* COMYZEROCLIENT_H */

