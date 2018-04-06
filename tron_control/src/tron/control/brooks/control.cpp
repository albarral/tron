/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/control.h"

namespace tron 
{
// Constructor
Control::Control ()
{    
    brequested = false;
    priority = 0;
}

bool Control::request(int vpriority)
{
    std::lock_guard<std::mutex> locker(mutex1);
    
    // raise flag if down or if up but new request with more (or same) priority
    if (!brequested || vpriority >= priority)
    {
        brequested = true;
        priority = vpriority;        
        return true;        
    }
    else 
        return false;          
}

bool Control::checkRequested()
{
    std::lock_guard<std::mutex> locker(mutex1);
    
    if (brequested)
    {
        brequested = false;
        return true;
    }
    else
        return false;
}
}


