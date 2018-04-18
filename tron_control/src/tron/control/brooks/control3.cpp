/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/control3.h"

namespace tron 
{
// Constructor
Control3::Control3()
{      
    value = 0.0;
}
    
bool Control3::request(float val, int vpriority)
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

float Control3::getValue()
{
    std::lock_guard<std::mutex> locker(mutex2);    
    return value;
}
}


