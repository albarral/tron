/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include "ZeroPublisher.h"

namespace tron 
{

    ZeroPublisher::ZeroPublisher(int port, int timeout):
    contextPublisher_(1),
    socketPublisher_(contextPublisher_, ZMQ_PUB),
    port_(port),
    timeout_(timeout){
        
        socketPublisher_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
        socketPublisher_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));
    }

    ZeroPublisher::~ZeroPublisher()
    {
        socketPublisher_.close();
    }
    
    bool ZeroPublisher::start(){
        std::string addr = "tcp://*:" + std::to_string(port_);
        
        try{
            socketPublisher_.bind(addr.c_str());

            isStarted_ = true;
        }catch(zmq::error_t& e) {
            isStarted_ = false;
        }
        
        return isStarted_;
    }
    
    void ZeroPublisher::stop(){
        
        isStarted_ = false;
        socketPublisher_.close();
        
    }
   
   // info publishing method (writes data)
    bool ZeroPublisher::publish(std::string text){
        
        try{
            zmq::message_t message(text.size());
            memcpy (message.data(), text.data(), text.size());
            return socketPublisher_.send(message);

        }catch(zmq::error_t& e) {
            return false;
        }
    }
}
