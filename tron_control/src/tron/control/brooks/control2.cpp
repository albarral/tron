/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/control2.h"

namespace tron 
{
// Constructor
Control2::Control2()
{      
    value = 0;
}
    
bool Control2::request(int val, int vpriority)
{  
    std::lock_guard<std::mutex> locker(mutex2);
    
    // if a new request can be made (due to winner priority), the control value is updated
    if (Control::request(vpriority))
    {
        value = val;    
        return true;
    }
    else 
        return false;          
}

int Control2::getValue()
{
    std::lock_guard<std::mutex> locker(mutex2);    
    return value;
}
}


