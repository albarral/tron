/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/MessageQueue.h"

namespace tron
{
MessageQueue::MessageQueue()
{    
}
    
MessageQueue::~MessageQueue()
{
    clean();
}

void MessageQueue::clean()
{
    std::lock_guard<std::mutex> locker(mutex);    
    listMessages.clear();
}

void MessageQueue::add(std::string message)
{  
    std::lock_guard<std::mutex> locker(mutex);    
    listMessages.push_back(message);
}

std::string MessageQueue::fetch()
{
    std::lock_guard<std::mutex> locker(mutex);
    // skip if empty queue
    if (listMessages.empty())
       return "";
    
    // get head message
    std::string message = listMessages.front();    
    // and remove it from list
    listMessages.pop_front();
    
    return message;    
}

bool MessageQueue::isFilled()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return (!listMessages.empty());    
}

int MessageQueue::getSize()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return listMessages.size();
}
}