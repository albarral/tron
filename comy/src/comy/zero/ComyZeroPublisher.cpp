/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/


#include <sys/stat.h>

#include "comy/zero/ComyZeroPublisher.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyZeroPublisher::logger(log4cxx::Logger::getLogger("comy"));

ComyZeroPublisher::ComyZeroPublisher():
    contextPublisher(1),
    socketPublisher(contextPublisher, ZMQ_PUB)
{    
    
    //socketPublisher.setsockopt(ZMQ_RCVTIMEO, 500);
    //socketPublisher.setsockopt(ZMQ_SNDTIMEO,500);
}

ComyZeroPublisher::~ComyZeroPublisher()
{
    socketPublisher.close();    
}

void ComyZeroPublisher::connect(std::string topic, std::string category) {}

void ComyZeroPublisher::connectZero(std::string topic, std::string category, int prePort){
        
    int port = prePort + (100*channelType);
        
    socketPublisher.bind("tcp://*:" + std::to_string(port)); //and binds it
    LOG4CXX_INFO(logger, "Publisher ZMQ connecting...");
    topicName = getChannel().getName();
    // set communications channel
    setChannel(channelType, topic, category);
    
    if (oChannel.isInformed()){
        
        // open coms zero for writing
        if (!socketPublisher.connected())                
            bconnected = true;  
        
        else{
            LOG4CXX_WARN(logger, "ComyZeroPublisher: connection failed");
            bconnected = false; 
        }
    }else{
        bconnected = false;
        LOG4CXX_WARN(logger, "ComyZeroPublisher: connection failed, coms channel needs to be defined");
    }
    
}
#warning Has meaning in zerocoms?
bool ComyZeroPublisher::newPublishing()
{
//    if (oFileWriter.isOpen())        
//    {
//        // overwrite any previous info
//        oFileWriter.goTop();
//        return true;
//    }
//    else
//    {
//        LOG4CXX_ERROR(logger, "ComyFilePublisher: can't publish info, coms file not open");                
//        return false;
//    }   
}

bool ComyZeroPublisher::publishMessage(std::string text)
{
    if (socketPublisher.connected()){ 
        
        try{
            zmq::message_t topic(topicName.size());
            memcpy (topic.data(), topicName.data(), topicName.size());

            if(socketPublisher.send(topic, ZMQ_SNDMORE)){
                zmq::message_t message(text.size());
                memcpy (message.data(), text.data(), text.size());
                return socketPublisher.send(message);

            }else {
                LOG4CXX_ERROR(logger, "ComyZeroPublisher: can't publish info");
                return false;
            }
        }catch(zmq::error_t& e) {
            LOG4CXX_ERROR(logger, "ComyZeroPublisher: can't read message: " << e.what());
        }
            
    }else
    {
        LOG4CXX_ERROR(logger, "ComyZeroPublisher: can't publish info, coms zero not open");                
        return false;
    }
}


}