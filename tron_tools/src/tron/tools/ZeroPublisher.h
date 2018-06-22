#ifndef ZEROPUBLISHER_H
#define ZEROPUBLISHER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include "zmq.hpp"

namespace tron 
{

class ZeroPublisher {
public:
    
    ZeroPublisher(int port, int timeout);
    ~ZeroPublisher();
       
    int getPort(){return port_;}
    bool isCreated(){return isStarted_;}
    
    bool start();
    void stop();
    
   // info publishing method (writes data)
    bool publish(std::string text);
    
private:
    
    zmq::context_t contextPublisher_; //creates the context 
    zmq::socket_t socketPublisher_; //creates the socket
    int port_, timeout_;
    bool isStarted_ = false;
    

};
}
#endif /* ZEROPUBLISHER_H */

