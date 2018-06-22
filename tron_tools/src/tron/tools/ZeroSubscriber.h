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
    
    ZeroSubscriber(int port, int timeout);
    virtual ~ZeroSubscriber();
    
    bool subscribe();
    
    bool isSubscribed(){return isSubscribed_;}

    void disconnect();
    
    bool getMessages(std::vector<std::string>& listMessages);
    
private:
    zmq::context_t contextSubscriber_; //creates the context 
    zmq::socket_t socketSubscriber_; //creates the socket
    int port_, timeout_;
    bool isSubscribed_ = false;
    

};
}
#endif /* ZEROSUBSCRIBER_H */

