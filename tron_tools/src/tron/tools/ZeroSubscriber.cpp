/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/


#include "ZeroSubscriber.h"

namespace tron 
{

    ZeroSubscriber::ZeroSubscriber(int port, int timeout):
        contextSubscriber_(1),
        socketSubscriber_(contextSubscriber_,ZMQ_SUB),
        port_(port),
        timeout_(timeout) 
    {
        socketSubscriber_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));
        socketSubscriber_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
    }

    ZeroSubscriber::~ZeroSubscriber() {
        socketSubscriber_.close();
    }
    
    bool ZeroSubscriber::subscribe(){
        
        std::string addr = "tcp://localhost:" + std::to_string(port_);
        
        try{
            socketSubscriber_.connect(addr.c_str());
            isSubscribed_ = true;

        }catch(zmq::error_t& e) {
            isSubscribed_ = false;
        }      
    }
    
    void ZeroSubscriber::disconnect(){
        
        isSubscribed_ = false;
        socketSubscriber_.close();
        
    }
    
    bool ZeroSubscriber::getMessages(std::vector<std::string>& listMessages){
        bool bread = false;
    
        std::string rawMessage = "";
        bool more = false;
        
        try{
            {
            //  Read message contents
            zmq::message_t message;
            more = socketSubscriber_.recv(&message);
            rawMessage = std::string(static_cast<char*>(message.data()), message.size());
            listMessages.push_back(std::move(rawMessage));
            }while(more != 0);
            
            bread = true;
            
        }catch(zmq::error_t& e) {
            return false;
        }

        return bread;
    }

}
