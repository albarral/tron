/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/ControlS.h"

namespace tron 
{
// Constructor
ControlS::ControlS()
{      
    value = "";
}
    
bool ControlS::request(std::string val, int vpriority)
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

std::string ControlS::getValue()
{
    std::lock_guard<std::mutex> locker(mutex2);    
    return value;
}
}


