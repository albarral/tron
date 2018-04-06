#ifndef __TRON_UTIL_POOL_H
#define __TRON_UTIL_POOL_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <queue>

namespace tron
{
// Manages a pool of available elements that can be fetched and freed. 
// It works as a FIFO list, using the oldest of the unused ones.
// On refill() the list is filled with all available elements.
// On takeOne() the first available element is fetched (removed from the list).
// On freeOne() the given element is made available again (added back to the list).    
class Pool
{
private:
    int MAX_ELEMENTS;               // maximum number of available elements
    std::queue<int> sequence;  // sequence of available elements (FIFO queue)

public:
    Pool();
    ~Pool ();
    
    void refill(int num);
    
    // fetches first available element
    int takeElement();
    
    // frees the given element
    void freeElement(int element);

};

}  

#endif
