#ifndef COMYZEROSERVER_H
#define COMYZEROSERVER_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   oriol@migtron.com (Oriol Orra)   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "comy/ComyServer.h"
#include <zmq.hpp>



namespace comy
{
    struct Responses{
        const std::string valid = "ACK";
        const std::string invalid = "NACK";
    };   
    
    class ComyZeroServer : public ComyServer
    {    
        private:
            static log4cxx::LoggerPtr logger;
            zmq::context_t contextServer;   //creates the context 
            zmq::socket_t socketServer;     //creates the socket
            Responses responses;
            
        public:


            ComyZeroServer();
            ~ComyZeroServer();

            virtual void connectZero(std::string topic, std::string category, int port);
            // read message from client, returns empty if nothing read
            virtual std::string readSingleMessage();    
            // get all new messages received
            virtual bool getNewMessages(std::vector<std::string>& listMessages); 
    };
}


#endif /* COMYZEROSERVER_H */

