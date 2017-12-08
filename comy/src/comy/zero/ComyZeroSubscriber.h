/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/

#ifndef COMYZEROSUBSCRIBER_H
#define COMYZEROSUBSCRIBER_H

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComySubscriber.h"
#include "zmq.hpp"

namespace comy
{
// Implementation of the ComyPublisher class based in broadcasting messages through a shared file.
class ComyZeroSubscriber : public ComySubscriber
{    
private:
    static log4cxx::LoggerPtr logger; 
    zmq::context_t contextSubscriber; //creates the context 
    zmq::socket_t socketSubscriber; //creates the socket
    std::string topicName;
    
public:
    ComyZeroSubscriber();
    ~ComyZeroSubscriber();

        
    virtual void connectZero(std::string topic, std::string category, int port);
    virtual void connect(std::string topic, std::string category);
   // read message from client, returns empty if nothing read
    virtual std::string readSingleMessage();    
    // get all new messages received
    virtual bool getNewMessages(std::vector<std::string>& listMessages);
};
}

#endif /* COMYZEROSUBSCRIBER_H */

