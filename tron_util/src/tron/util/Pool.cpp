/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/Pool.h"

namespace tron
{
Pool::Pool()
{          
    refill(10);
}

Pool::~Pool ()
{
    // first, clear list
    while (!sequence.empty())
        sequence.pop();
}


void Pool::refill(int num)
{	
    MAX_ELEMENTS = num;
    
    // first, clear list
    while (!sequence.empty())
        sequence.pop();
    
    // fill list with all elements
    for (int i=1; i<=MAX_ELEMENTS; i++) 
        sequence.push(i);
}


int Pool::takeElement()
{
    // take only if elements available
    if (sequence.size() > 0)
    {
        int element = sequence.front();
        sequence.pop();
        return element;
    }
    else
        return -1;
}
													  

void Pool::freeElement(int element)
{
    sequence.push(element);
}

}




