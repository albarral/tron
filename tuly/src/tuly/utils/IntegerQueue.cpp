/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/IntegerQueue.h"

namespace tuly
{
IntegerQueue::IntegerQueue()
{    
}
    
IntegerQueue::~IntegerQueue()
{
    clean();
}

void IntegerQueue::clean()
{
    std::lock_guard<std::mutex> locker(mutex);    
    listElements.clear();
}

void IntegerQueue::add(int value)
{  
    std::lock_guard<std::mutex> locker(mutex);    
    listElements.push_back(value);
}

bool IntegerQueue::fetch(int& reference)
{
    std::lock_guard<std::mutex> locker(mutex);
    // skip if empty queue
    if (listElements.empty())
       return false;
    
    // get head element
    reference = listElements.front();    
    // and remove it from list
    listElements.pop_front();
    
    return true;    
}

bool IntegerQueue::isFilled()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return (!listElements.empty());    
}

int IntegerQueue::getSize()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return listElements.size();
}
}