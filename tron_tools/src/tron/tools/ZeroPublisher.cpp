/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include "ZeroPublisher.h"

namespace tron 
{

    ZeroPublisher::ZeroPublisher():
    contextPublisher_(1),
    socketPublisher_(contextPublisher_, ZMQ_PUB),
    port_(0),
    timeout_(0){
        
        socketPublisher_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
        socketPublisher_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));
    }

    ZeroPublisher::~ZeroPublisher() {
        create();
    }
    
    bool ZeroPublisher::create(){
        std::string addr = "tcp://*:" + std::to_string(port_);
        
        try{
            socketPublisher_.bind(addr.c_str());

            socketPublisher_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
            socketPublisher_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));

            isCreated_ = true;
        }catch(zmq::error_t& e) {
            isCreated_ = false;
        }
        
        return isCreated_;
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
