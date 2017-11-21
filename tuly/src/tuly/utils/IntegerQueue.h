#ifndef __TULY_INTEGER_QUEUE_H
#define __TULY_INTEGER_QUEUE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>
#include <mutex>

namespace tuly
{
// Class that provides integer queue funcionality.
// The queue can be feed and consumed by different threads safely.
// Elements are consumed in fifo order. 
class IntegerQueue
{    
private:
    std::mutex mutex;
    std::deque<int> listElements;    // fifo list of elements
        
public:
    IntegerQueue();
    ~IntegerQueue();
    
    // add element to end of queue
    void add(int value);   
    // fetch element from head of queue (removing it)
    bool fetch(int& reference);
    // checks if queue is filled
    bool isFilled(); 
    // get number of elements in the queue
    int getSize();
    // clean queue of elements
    void clean();
};
}
#endif
