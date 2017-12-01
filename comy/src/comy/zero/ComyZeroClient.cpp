/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/


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
        //socketClient.setsockopt(ZMQ_RCVTIMEO, 500);
        //socketClient.setsockopt(ZMQ_SNDTIMEO,500);
        //socketClient.setsockopt(ZMQ_REQ_CORRELATE,1);
        //socketClient.setsockopt(ZMQ_REQ_RELAXED,1);
    }

    ComyZeroClient::~ComyZeroClient()
    {
        if(socketClient.connected())
            socketClient.close();
        
        LOG4CXX_INFO(logger, "Client ZMQ closing...");
    }

    void ComyZeroClient::connectZero(std::string topic, std::string category, int port){
        
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
                //std::cout << "Sending request... " << text << std::endl;
                socketClient.send (request);

                //  Get the reply.
                zmq::message_t reply;
                socketClient.recv (&reply);
                std::string rpl = std::string(static_cast<char*>(reply.data()), reply.size());
                //std::cout << "Received-> " << rpl << std::endl;
                return true;

            }catch(zmq::error_t& e) {
                //std::cout << "ERROR: Client -> Sending before receiving a request." << std::endl;
                LOG4CXX_ERROR(logger, "ComyFileClient: send failed!");
                return false;
            }   
        }else{
            LOG4CXX_ERROR(logger, "ComyZeroClient: coms zero not open");
            return false;
        }
    }
}