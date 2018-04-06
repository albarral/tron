#ifndef __TRON_UTIL_MESSAGEQUEUE_H
#define __TRON_UTIL_MESSAGEQUEUE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>
#include <mutex>
#include <string>

namespace tron
{
// Class that provides messages queue funcionality.
// The queue can be feed and consumed by different threads safely.
// Messages are consumed in fifo order. 
class MessageQueue
{    
private:
    std::mutex mutex;
    std::deque<std::string> listMessages;    // fifo list of messages
        
public:
    MessageQueue();
    ~MessageQueue();
    
    // add message to end of queue
    void add(std::string message);   
    // fetch message from head of queue (removing it)
    std::string fetch();
    // checks if queue is filled
    bool isFilled(); 
    // get number of messages in the queue
    int getSize();
    // clean queue of messages
    void clean();
};
}
#endif
