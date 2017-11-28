#ifndef __TALKY_COMMAND_QUEUE_H
#define __TALKY_COMMAND_QUEUE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>
#include <mutex>

#include "talky/coms/Command.h"

namespace talky
{
// Class that provides commands queue functionality.
// The queue can be feed and consumed by different threads safely.
// Commands are consumed in fifo order. 
class CommandQueue
{    
private:
    std::mutex mutex;
    std::deque<Command> listElements;    // fifo list of elements
        
public:
    CommandQueue();
    ~CommandQueue();
    
    // add element to end of queue
    void add(Command& oCommand);   
    // fetch element from head of queue (removing it)
    bool fetch(Command& oCommand);
    // checks if queue is filled
    bool isFilled(); 
    // get number of elements in the queue
    int getSize();
    // clean queue of elements
    void clean();
};
}
#endif
