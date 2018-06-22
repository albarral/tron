#ifndef ZEROSERVER_H
#define ZEROSERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include "zmq.hpp"

namespace tron 
{
class ZeroServer {

    struct Responses{
        const std::string valid = "ACK";
        const std::string invalid = "NACK";
    };
    
private:
    zmq::context_t contextServer_;   //creates the context 
    zmq::socket_t socketServer_;     //creates the socket
    Responses responses_;
    int port_, timeout_;
    bool isStarted_ = false;
    
    
public:
    ZeroServer(int port, int timeout);
    ~ZeroServer();
    
    bool start();
    void stop();
    bool isCreated(){return isStarted_;}
    std::vector<std::string> receive();
    

};
}

#endif /* ZEROSERVER_H */

