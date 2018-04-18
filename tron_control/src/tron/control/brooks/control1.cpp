/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/control1.h"

namespace tron 
{
// Constructor
Control1::Control1()
{      
    value = false;
}
    
bool Control1::request(bool val, int vpriority)
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

bool Control1::getValue()
{
    std::lock_guard<std::mutex> locker(mutex2);    
    return value;
}
}


