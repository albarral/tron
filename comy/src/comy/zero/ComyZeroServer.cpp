/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/


#include "comy/zero/ComyZeroServer.h"


namespace comy
{
    log4cxx::LoggerPtr ComyZeroServer::logger(log4cxx::Logger::getLogger("comy")); 
    
    ComyZeroServer::ComyZeroServer():
        contextServer(1),
        socketServer(contextServer, ZMQ_REP)    
    {    
        socketServer.setsockopt(ZMQ_RCVTIMEO, 250);
        socketServer.setsockopt(ZMQ_SNDTIMEO, 250);
        //socketClient.setsockopt(ZMQ_REQ_CORRELATE,1);
        //socketClient.setsockopt(ZMQ_REQ_RELAXED,1);
    }

    ComyZeroServer::~ComyZeroServer()
    {
        if(socketServer.connected())
            socketServer.close();
        
        LOG4CXX_INFO(logger, "Server ZMQ closing...");
    }
    void ComyZeroServer::connect(std::string topic, std::string category) {}

    void ComyZeroServer::connectZero(std::string topic, std::string category, int prePort){
        
        int port = prePort + (100*channelType);
        socketServer.bind("tcp://*:" + std::to_string(port));
        LOG4CXX_INFO(logger, "Server ZMQ connecting...");
        
        // set communications channel
        setChannel(channelType, topic, category);

        if (oChannel.isInformed())
        {
            // open coms zero for writing
            if (socketServer.connected())
                bconnected = true;  
            
            else
                bconnected = false;    
        }
        else
        {
            bconnected = false;        
            LOG4CXX_WARN(logger, "ComyZeroServer: connection failed, coms channel needs to be defined");                        
        }
    }
    
    std::string ComyZeroServer::readSingleMessage(){
        std::string rawMessage = "";

        if (socketServer.connected())    {    
            try{
                zmq::message_t request;

                //  Wait for next request from client
                socketServer.recv (&request);
                rawMessage = std::string(static_cast<char*>(request.data()), request.size());
                LOG4CXX_INFO(logger, "Server ZMQ (readSingleMessage) received: " + rawMessage);

                //Send reply
                std::string response = responses.valid;
                zmq::message_t reply (response.length());
                memcpy (reply.data (), response.c_str(), response.length());
                socketServer.send (reply);
                LOG4CXX_INFO(logger, "Server ZMQ (readSingleMessage) sent: " + response);
            }catch(zmq::error_t& e) {
                
                LOG4CXX_ERROR(logger, "ComyServerServer: can't read message: ");
            }
            
        }else
            LOG4CXX_ERROR(logger, "ComyServerServer: can't read message, zero server not open ");
        
        return rawMessage;
    }
    
    
    
bool ComyZeroServer::getNewMessages(std::vector<std::string>& listMessages)
{
    bool bread = false;
    if (socketServer.connected()){
        while(true){
            
            std::string rawMessage = "";
            try{
                zmq::message_t request;

                //  Wait for next request from client
                bread = socketServer.recv (&request);
                if(!bread) break;
                rawMessage = std::string(static_cast<char*>(request.data()), request.size());
                listMessages.push_back(std::move(rawMessage));
                LOG4CXX_INFO(logger, "Server ZMQ (getNewMessages) received: " + listMessages[0]);

                //Send reply
                std::string response = responses.valid;
                zmq::message_t reply (response.length());
                memcpy (reply.data (), response.c_str(), response.length());
                socketServer.send (reply);
                LOG4CXX_INFO(logger, "Server ZMQ (getNewMessages) sent: " + response);
            }catch(zmq::error_t& e) {
                
                LOG4CXX_ERROR(logger, "ComyServerServer: can't read message: " << e.what());
            }
            
        }
    }        
    else
    {
        LOG4CXX_ERROR(logger, "ComyZeroServer: can't read messages, zero reader not open ");
    }
    
    return bread;
}
}