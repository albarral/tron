/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNodeServer.h"

namespace nety
{

NetNodeServer::NetNodeServer()
{    
    // input node
    btypeOut = false;
}

//NetNodeServer::~NetNodeServer()
//{
//}

void NetNodeServer::connect()
{    
    // if not tuned, can't connect
    if (!btuned)
    {
        LOG4CXX_WARN(logger, "NetNodeServer: node not tuned, can't connect to link");           
        return;
    }
    
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    
    if (topicName.empty() && categoryName.empty())
        oComyServer.connect(topicName, categoryName);        

    // if client connected
    if (oComyServer.isConnected())
    {
        bconnected = true;
        LOG4CXX_INFO(logger, "NetNodeServer connected");                                
    }
    else
        LOG4CXX_ERROR(logger, "NetNodeServer NOT connected!");       
}


bool NetNodeServer::flush()
{
    LOG4CXX_WARN(logger, "NetNodeServer: invalid call to flush(), not an output node");               
    return false;
}

bool NetNodeServer::absorb()
{
    // read received messages
    oComyServer.readMessages();
    
    // if no messages received, return all ok    
    if (!oComyServer.hasMessages())
        return true;
    
    int count = 0;
    // absorb all server messages into our message's queue
    while (oComyServer.hasMessages())
    {
        oMessageQueue.add(oComyServer.fetchMessage());
        count++;
    }            
      
    LOG4CXX_INFO(logger, "NetNodeServer: absorbed messages " << count);
    
    // return true if some messages read
    return (count > 0);
}
}