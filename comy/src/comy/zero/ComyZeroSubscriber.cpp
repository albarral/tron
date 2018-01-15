/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/

#include <string>
#include <sys/stat.h>

#include "comy/zero/ComyZeroSubscriber.h"
#include "comy/ComyConfig.h"

namespace comy
{
log4cxx::LoggerPtr ComyZeroSubscriber::logger(log4cxx::Logger::getLogger("comy"));

ComyZeroSubscriber::ComyZeroSubscriber():
    contextSubscriber(1),
    socketSubscriber(contextSubscriber,ZMQ_SUB)
{    

}

ComyZeroSubscriber::~ComyZeroSubscriber()
{

}

void ComyZeroSubscriber::connect(std::string topic, std::string category) {}

void ComyZeroSubscriber::connectZero(std::string topic, std::string category, int prePort){
        
    std::string addr = "tcp://*:" + std::to_string(prePort + (100*channelType));
        
    // set communications channel
    setChannel(channelType, topic, category);
    topicName = getChannel().getName();
    
    socketSubscriber.connect(addr.c_str());
    LOG4CXX_INFO(logger, "Subscriber ZMQ connecting...");
    socketSubscriber.setsockopt(ZMQ_SUBSCRIBE, topicName.c_str(), topicName.length());
    //setsockopt( ZMQ_SUBSCRIBE, topicName);

    if (oChannel.isInformed())
    {
        // open coms zero for reading
        bconnected = true;  
        
    }
    else
    {
        bconnected = false;        
        LOG4CXX_WARN(logger, "ComyZeroSubscriber: connection failed, coms channel needs to be defined");                        
    }        
    
}

std::string ComyZeroSubscriber::readSingleMessage()
{
    std::string rawMessage = "";

    
    try{
        //  Read envelope with address
        zmq::message_t addr;
        socketSubscriber.recv(&addr);
        std::string envelope = std::string(static_cast<char*>(addr.data()), addr.size()); 

        //  Read message contents
        zmq::message_t message;
        socketSubscriber.recv(&message);
        rawMessage = std::string(static_cast<char*>(message.data()), message.size());
    }catch(zmq::error_t& e) {
        LOG4CXX_ERROR(logger, "ComyZeroSubscriber: send failed!: " << e.what());
    }
    
    
    return rawMessage;
}

bool ComyZeroSubscriber::getNewMessages(std::vector<std::string>& listMessages)
{
    bool bread = false;
    
    while(true){

        std::string rawMessage = "";
        try{
            //  Read envelope with address
            zmq::message_t addr;
            bread = socketSubscriber.recv(&addr);
            if(!bread) break;
            std::string envelope = std::string(static_cast<char*>(addr.data()), addr.size()); 

            //  Read message contents
            zmq::message_t message;
            socketSubscriber.recv(&message);
            rawMessage = std::string(static_cast<char*>(message.data()), message.size());
            listMessages.push_back(std::move(rawMessage));
        }catch(zmq::error_t& e) {
            LOG4CXX_ERROR(logger, "ComyZeroSubscriber: can't read message: " << e.what());
        }
    }
    
    return bread;
}

}