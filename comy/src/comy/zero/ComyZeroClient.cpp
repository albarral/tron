/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/


#include <string>

#include "comy/zero/ComyZeroClient.h"


namespace comy
{
    log4cxx::LoggerPtr ComyZeroClient::logger(log4cxx::Logger::getLogger("comy"));

    //  Prepare our context and socket
//    zmq::context_t contextClient (1);
//    zmq::socket_t socketClient (contextClient, ZMQ_REQ);
    
    
    
    ComyZeroClient::ComyZeroClient():
        contextClient(1),
        socketClient(contextClient, ZMQ_REQ)    
    {    
        socketClient.setsockopt(ZMQ_RCVTIMEO, 250);
        socketClient.setsockopt(ZMQ_SNDTIMEO, 250);
        //socketClient.setsockopt(ZMQ_REQ_CORRELATE,1);
        //socketClient.setsockopt(ZMQ_REQ_RELAXED,1);
    }

    ComyZeroClient::~ComyZeroClient()
    {
        if(socketClient.connected())
            socketClient.close();
        
        LOG4CXX_INFO(logger, "Client ZMQ closing...");
    }
    void ComyZeroClient::connect(std::string topic, std::string category) {}
    
    void ComyZeroClient::connectZero(std::string topic, std::string category, int prePort){
        
        int port = prePort + (100*channelType);
        
        socketClient.connect("tcp://localhost:" + std::to_string(port));
        LOG4CXX_INFO(logger, "Client ZMQ connecting...");
        
        // set communications channel
        setChannel(channelType, topic, category);

        if (oChannel.isInformed())
        {
            // open coms zero for writing
            if (socketClient.connected())
                bconnected = true;  
            
            else
                bconnected = false;    
        }
        else
        {
            bconnected = false;        
            LOG4CXX_WARN(logger, "ComyZeroClient: connection failed, coms channel needs to be defined");                        
        }
    }
    
    bool ComyZeroClient::sendMessage(std::string text)
    {
       
        if(socketClient.connected()){
            try{
                //Send Command
                zmq::message_t request (text.length());
                memcpy (request.data (), text.c_str(), text.length());
                bool isSent = socketClient.send (request);
                LOG4CXX_INFO(logger, "Client ZMQ sent: " + text);
                
                //  Get the reply.
                zmq::message_t reply;
                socketClient.recv (&reply);
                std::string rpl = std::string(static_cast<char*>(reply.data()), reply.size());
                LOG4CXX_INFO(logger, "Client ZMQ received: " + rpl);
                return true;

            }catch(zmq::error_t& e) {
                LOG4CXX_ERROR(logger, "ComyZeroClient: send failed!: " << e.what());
            }   
        }else{
            LOG4CXX_ERROR(logger, "ComyZeroClient: coms zero not open");
            return false;
        }
    }
}