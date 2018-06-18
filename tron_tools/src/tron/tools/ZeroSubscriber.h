#ifndef ZEROSUBSCRIBER_H
#define ZEROSUBSCRIBER_H


/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include "zmq.hpp"

namespace tron 
{

class ZeroSubscriber {
public:
    ZeroSubscriber();
    ZeroSubscriber(int port, int timeout);
    virtual ~ZeroSubscriber();
    
private:
    zmq::context_t contextSubscriber_; //creates the context 
    zmq::socket_t socketSubscriber_; //creates the socket
    int port_, timeout_;
    bool isConnected_ = false;
    
    bool connectTo();
    
    bool isConnected(){return isConnected_;}

    int getPort() {return port_;}

    bool disconnect();
    
    bool getMessages(std::vector<std::string>& listMessages);

};
}
#endif /* ZEROSUBSCRIBER_H */

