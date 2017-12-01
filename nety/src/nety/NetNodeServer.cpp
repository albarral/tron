/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNodeServer.h"

namespace nety
{

NetNodeServer::NetNodeServer()
{    
    nodeName = "nety Server";
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
        LOG4CXX_WARN(logger, nodeName + ": node not tuned, can't connect to link");           
        return;
    }
    
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    
    // connect if valid topic-category names
    if (!topicName.empty() && !categoryName.empty())
        oComyServer.connect(topicName, categoryName);        

    // if client connected
    if (oComyServer.isConnected())
    {
        bconnected = true;
        LOG4CXX_INFO(logger, nodeName + " connected - " + topicName + ":" + categoryName);                                
    }
    else
        LOG4CXX_ERROR(logger, nodeName + " NOT connected - " + topicName + ":" + categoryName);       
}


bool NetNodeServer::flush()
{
    LOG4CXX_WARN(logger, nodeName + ": invalid call to flush(), not an output node");               
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
      
    //LOG4CXX_INFO(logger, nodeName + ": absorbed messages " << count);
    
    // return true if some messages read
    return (count > 0);
}
}