/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "nety/NetNodeSubscriber.h"

namespace nety
{

NetNodeSubscriber::NetNodeSubscriber()
{    
    // input node
    btypeOut = false;
}

//NetNodeSubscriber::~NetNodeSubscriber()
//{
//}

void NetNodeSubscriber::connect()
{    
    // if not tuned, can't connect
    if (!btuned)
    {
        LOG4CXX_WARN(logger, "NetNodeSubscriber: node not tuned, can't connect to link");           
        return;
    }
    
    std::string topicName = oInterpreter.getTopicName(topic);
    std::string categoryName = oInterpreter.getCategoryName(topic, category);
    
    if (topicName.empty() && categoryName.empty())
        oComySubscriber.connect(topicName, categoryName);        

    // if client connected
    if (oComySubscriber.isConnected())
    {
        bconnected = true;
        LOG4CXX_INFO(logger, "NetNodeSubscriber connected");                                
    }
    else
        LOG4CXX_ERROR(logger, "NetNodeSubscriber NOT connected!");       
}


bool NetNodeSubscriber::flush()
{
    LOG4CXX_WARN(logger, "NetNodeSubscriber: invalid call to flush(), not an output node");               
    return false;
}

bool NetNodeSubscriber::absorb()
{
    // read received messages
    oComySubscriber.readMessages();
    
    // if no messages received, return all ok    
    if (!oComySubscriber.hasMessages())
        return true;
    
    int count = 0;
    // absorb all server messages into our message's queue
    while (oComySubscriber.hasMessages())
    {
        oMessageQueue.add(oComySubscriber.fetchMessage());
        count++;
    }            
      
    LOG4CXX_INFO(logger, "NetNodeSubscriber: absorbed messages " << count);
    
    // return true if some messages read
    return (count > 0);
}
}