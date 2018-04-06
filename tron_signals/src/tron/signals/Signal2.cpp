/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/signals/Signal2.h"

namespace tron
{
Signal2::Signal2()
{    
    reset();
}

void Signal2::reset() 
{
    t = 0.0;
    at = 0.0;
    value = 0.0;
    oClick.start();
}

void Signal2::update()
{
    // compute elapsed time 
    oClick.read();
    oClick.start();        
    // update advanced time
    at = oClick.getMillis();    
    t += at;    
    // protect limit
    if (t > tmax)
        t = t - tmax;
}
}