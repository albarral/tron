/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNodePublisher.h"

namespace nety
{

NetNodePublisher::NetNodePublisher()
{    
   // output node
   btypeOut = true;
}

//NetNodePublisher::~NetNodePublisher()
//{
//}

void NetNodePublisher::connect()
{    
    // if not tuned, can't connect
    if (!btuned)
    {
        LOG4CXX_WARN(logger, "NetNodePublisher: node not tuned, can't connect to link");           
        return;
    }
    
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    
    // connect if valid topic-category names
    if (!topicName.empty() && !categoryName.empty())
        oComyPublisher.connect(topicName, categoryName);        

    // if client connected
    if (oComyPublisher.isConnected())
    {
        bconnected = true;
        LOG4CXX_INFO(logger, "Nety Publisher connected - " + topicName + ":" + categoryName);                                
    }
    else
        LOG4CXX_ERROR(logger, "Nety Publisher NOT connected - " + topicName + ":" + categoryName);       
}


bool NetNodePublisher::flush()
{
    // if no messages to send, return all ok
    if (!oMessageQueue.isFilled())
        return true;
        
    int failed = 0;
    // start new publishing (overwrite previous published info)
    oComyPublisher.newPublishing();
    // consume the whole messages queue    
    while (oMessageQueue.isFilled())
    {
        // send message 
        if (!oComyPublisher.publishMessage(oMessageQueue.fetch()))
        {
            failed++;
        }    
    }        
   
    if (failed != 0)
    {
        LOG4CXX_ERROR(logger, "NetNodePublisher: flush failed, messages not sent = " << failed);
    }        
    
    // return true if all messages could be sent
    return (failed == 0);
}

bool NetNodePublisher::absorb()
{
    LOG4CXX_WARN(logger, "NetNodePublisher: invalid call to absorb(), not an input node");               
    return false;
}
}