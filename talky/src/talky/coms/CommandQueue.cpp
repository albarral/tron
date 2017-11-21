/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/CommandQueue.h"

namespace talky
{
CommandQueue::CommandQueue()
{    
}
    
CommandQueue::~CommandQueue()
{
    clean();
}

void CommandQueue::clean()
{
    std::lock_guard<std::mutex> locker(mutex);    
    listElements.clear();
}

void CommandQueue::add(Command& oCommand)
{  
    std::lock_guard<std::mutex> locker(mutex);    
    listElements.push_back(oCommand);
}

bool CommandQueue::fetch(Command& oCommand)
{
    std::lock_guard<std::mutex> locker(mutex);
    // skip if empty queue
    if (listElements.empty())
       return false;
    
    // get head element
    oCommand = listElements.front();    
    // and remove it from list
    listElements.pop_front();
    
    return true;    
}

bool CommandQueue::isFilled()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return (!listElements.empty());    
}

int CommandQueue::getSize()
{
    std::lock_guard<std::mutex> locker(mutex);    
    return listElements.size();
}
}