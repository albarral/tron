#ifndef __TRON_COMS_COMSCHANNEL_H
#define __TRON_COMS_COMSCHANNEL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>
#include <ignition/transport.hh>

namespace tron
{
// Base class for communication channel classes.
// A channel has an associated topic (an ignition transport concept) of the form: node/section/type/channel.
class ComsChannel 
{    
protected:
    static log4cxx::LoggerPtr logger;
    std::string topic;              // topic name
    bool bconnected;            // channel is connected (has a registered publisher or subscriber) 
        
public:
    ComsChannel();
    //~ComsChannel();
    
    std::string getTopic() {return topic;};
    void setTopic(std::string value) {topic = value;}

    // connect channel
    virtual bool connect(ignition::transport::Node& oNode) = 0;
    bool isConnected() {return bconnected;};
};

}
#endif
