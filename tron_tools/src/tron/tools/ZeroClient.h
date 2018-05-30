#ifndef ZEROCLIENT_H
#define ZEROCLIENT_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "zmq.hpp"

namespace tron 
{

class ZeroClient {
    
    private:
        int port_;
        
    public:
        ZeroClient();
        ~ZeroClient();

        // open socket
        bool connectTo(int port);
        bool isConnected();
        int getPort() {return port_;}
        bool disconnect();

        // writes the given string into the file (delayed writing, done at file closing)
        void send(std::string, int last = true);

};
}
#endif /* ZEROCLIENT_H */

