#ifndef ZEROCLIENT_H
#define ZEROCLIENT_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include "zmq.hpp"

namespace tron 
{

class ZeroClient {
    
    private:
        int port_, timeout_;
        zmq::context_t contextClient_;
        zmq::socket_t socketClient_;
        bool isConnected_ = false;
                        
    public:
        
        ZeroClient(int port, int timeout);
        ~ZeroClient();

        // open socket
        bool connect();
        bool isConnected(){return isConnected_;}
                
        void disconnect();

        // writes the given string into the file (delayed writing, done at file closing)
        bool send(std::vector<std::string> messages);

};
}
#endif /* ZEROCLIENT_H */

