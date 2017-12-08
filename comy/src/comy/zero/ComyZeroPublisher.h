/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/

#ifndef COMYZEROPUBLISHER_H
#define COMYZEROPUBLISHER_H

#include <string>
#include <log4cxx/logger.h>

#include "comy/ComyPublisher.h"
#include "zmq.hpp"

namespace comy
{
// Implementation of the ComyPublisher class based in broadcasting messages through a shared file.
class ComyZeroPublisher : public ComyPublisher
{    
private:
    static log4cxx::LoggerPtr logger; 
    zmq::context_t contextPublisher; //creates the context 
    zmq::socket_t socketPublisher; //creates the socket
    std::string topicName;
    
public:
    ComyZeroPublisher();
    ~ComyZeroPublisher();

        
    virtual void connectZero(std::string topic, std::string category, int port);
    virtual void connect(std::string topic, std::string category);
    // starts a new publishing iteration
    virtual bool newPublishing();
   // info publishing method (writes data)
    virtual bool publishMessage(std::string text);
};
}


#endif /* COMYZEROPUBLISHER_H */

