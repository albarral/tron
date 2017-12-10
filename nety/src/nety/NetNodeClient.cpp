/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNodeClient.h"

namespace nety
{

NetNodeClient::NetNodeClient()
{    
    // output node
    btypeOut = true;
}

//NetNodeClient::~NetNodeClient()
//{
//}

void NetNodeClient::connect()
{    
    // if not tuned, can't connect
    if (!btuned)
    {
        LOG4CXX_WARN(logger, "NetNodeClient: node not tuned, can't connect to link");           
        return;
    }
    
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    int prePort = oInterpreter.getPortBeforeChannelType(topic, category);
    // connect if valid topic-category names
    if (!topicName.empty() && !categoryName.empty())
        oComyClient.connectZero(topicName, categoryName, prePort);        

    // if client connected
    if (oComyClient.isConnected())
    {
        bconnected = true;
        LOG4CXX_INFO(logger, "Nety Client connected - " + topicName + ":" + categoryName);                                
    }
    else
        LOG4CXX_ERROR(logger, "Nety Client NOT connected - " + topicName + ":" + categoryName);       
}


bool NetNodeClient::flush()
{
    // if no messages to send, return all ok
    if (!oMessageQueue.isFilled())
        return true;
        
    int failed = 0;
    // consume the whole messages queue
    while (oMessageQueue.isFilled())
    {
        // send message 
        if (!oComyClient.sendMessage(oMessageQueue.fetch()))
        {
            failed++;
        }    
    }        
   
    if (failed != 0)
    {
        LOG4CXX_WARN(logger, "NetNodeClient: flush failed, messages not sent = " << failed);
    }        
    
    // return true if all messages could be sent
    return (failed == 0);
}

bool NetNodeClient::absorb()
{
    LOG4CXX_WARN(logger, "NetNodeClient: invalid call to absorb(), not an input node");               
    return false;
}
}