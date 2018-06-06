/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com   *
 ***************************************************************************/

#include "ZeroServer.h"

namespace tron 
{
    ZeroServer::ZeroServer():
        contextServer_(1),
        socketServer_(contextServer_, ZMQ_REP),
        port_(0),
        timeout_(0)  
    {
        socketServer_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
        socketServer_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));
        //socketClient.setsockopt(ZMQ_REQ_CORRELATE,1);
        //socketClient.setsockopt(ZMQ_REQ_RELAXED,1);
    }
    
    ZeroServer::ZeroServer(int port, int timeout):
        contextServer_(1),
        socketServer_(contextServer_, ZMQ_REP),
        port_(port),
        timeout_(timeout)  
    {
        create();
    }
    
    ZeroServer::~ZeroServer() {
        socketServer_.close();
    }
    
    bool ZeroServer::create(){
        
        std::string addr = "tcp://*:" + std::to_string(port_);
        
        try{
            socketServer_.bind(addr.c_str());

            socketServer_.setsockopt(ZMQ_RCVTIMEO, &timeout_, sizeof(timeout_));
            socketServer_.setsockopt(ZMQ_SNDTIMEO, &timeout_, sizeof(timeout_));

            isCreated_ = true;
        }catch(zmq::error_t& e) {
            isCreated_ = false;
        }
        
        return isCreated_;
    }
    
    std::vector<std::string> ZeroServer::receive(){
        std::vector<std::string> listLines;
        
        try{
                int more = 0;
                size_t more_size = sizeof(more);
            do{
                zmq::message_t request;
                //  Wait for next request from client
                socketServer_.recv (&request);
                socketServer_.getsockopt(ZMQ_RCVMORE, &more, &more_size);
                std::string msg = std::string(static_cast<char*>(request.data()), request.size());
                listLines.push_back(std::move(msg));
                
            }while(more != 0);
            
        }catch(zmq::error_t& e) {

            listLines.clear();
        }
        return listLines;
    }
}

