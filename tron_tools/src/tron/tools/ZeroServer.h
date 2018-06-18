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
    bool isCreated_ = false;
    
    void setPort(int port){port_ = port;}
    bool create();
    
public:
    ZeroServer();
    ZeroServer(int port, int timeout);
    ~ZeroServer();
    
    int getPort(){return port_;}
    bool isCreated(){return isCreated_;}
    std::vector<std::string> receive();
    

};
}

#endif /* ZEROSERVER_H */

