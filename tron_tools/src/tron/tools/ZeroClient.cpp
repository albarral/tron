/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/
#include "ZeroClient.h"

namespace tron 
{

    ZeroClient::ZeroClient():
        contextClient_(1),
        socketClient_(contextClient_, ZMQ_REQ),
        port_(0),
        timeout_(0)
    {
        connectTo(port_);
    }
    ZeroClient::ZeroClient(int port, int timeout):
        contextClient_(1),
        socketClient_(contextClient_, ZMQ_REQ),
        port_(port),
        timeout_(timeout)
    {
        
    }
    
    ZeroClient::~ZeroClient(){
    
        socketClient_.close();
    }

    bool ZeroClient::connectTo(int port){
        
        setPort(port);
        std::string addr = "tcp://localhost:" + std::to_string(port_);
        
        try{
            socketClient_.connect(addr.c_str());
            
            socketClient_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
            //socketClient_.setsockopt(ZMQ_SNDTIMEO, &timeout, sizeof(timeout_));
            //socketClient_.setsockopt(ZMQ_REQ_CORRELATE,1);
            //socketClient_.setsockopt(ZMQ_REQ_RELAXED,1);
            
            isConnected_ = true;
        }catch(zmq::error_t& e) {
            
            isConnected_ = false;
        }
        
        return isConnected_;
    }
    
    bool ZeroClient::disconnect(){
        socketClient_.close();
        isConnected_ = false;
    }

    std::string ZeroClient::send(std::vector<std::string> messages){
        
         try{
             int count = 1;
             
             for(std::string msg : messages){
                //Send Command
                zmq::message_t request (msg.length());
                memcpy (request.data (), msg.c_str(), msg.length());
                if(count == messages.size())
                    socketClient_.send (request, 0);
                else if(count < messages.size())
                    socketClient_.send (request, ZMQ_SNDMORE);
                count++;

             }
             
            //  Get the reply.
            zmq::message_t reply;
            socketClient_.recv (&reply);
            return std::string(static_cast<char*>(reply.data()), reply.size());

        }catch(zmq::error_t& e) {
            return NULL;
        }   
    }

}

