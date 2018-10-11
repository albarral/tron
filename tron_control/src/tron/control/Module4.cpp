/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "tron/control/Module4.h"

namespace tron
{
// Constructor
Module4::Module4 ()
{    
    setFrequency(1.0);  // default frequency
    bON = false;
    boffRequested = false;
    pBehaviour = 0;    
}

float Module4::getFrequency()
{
    std::lock_guard<std::mutex> locker(mutex);
    return frequency;        
}

int Module4::getPeriod()
{
    std::lock_guard<std::mutex> locker(mutex);
    return period;        
}

bool Module4::isOn()
{
    return bON;
}

bool Module4::isOffRequested()
{
    std::lock_guard<std::mutex> locker(mutex);
    if (boffRequested)
    {
        // reset flag when checked
        boffRequested = false;
        return true;
    }
    else
        return (false);        
}

void Module4::setFrequency(float cps)
{
    std::lock_guard<std::mutex> locker(mutex);
    if (cps > 0.0)
    {
        period = 1000000/cps;    // in microseconds
        frequency = cps;
    }
}

void Module4::setBehaviour(Behaviour& oBehaviour)
{
    std::lock_guard<std::mutex> locker(mutex);
    pBehaviour = &oBehaviour;
}

void Module4::on()
{
    // only launch thread if in OFF state
    if (!bON)
    {
      t = std::thread(&Module4::run, this);              
    }           
}

void Module4::off()
{        
    std::lock_guard<std::mutex> locker(mutex);
    boffRequested = true;
}

void Module4::wait()
{
    t.join();
}

void Module4::run ()
{    
    // check that a behaviour is defined
    if (pBehaviour == 0)
        return;
    
    bON = true; 
    pBehaviour->start();
    while (!isOffRequested())
    {
        pBehaviour->sense();
        pBehaviour->think();
        pBehaviour->actuate();
        pBehaviour->postLoop();
        
        usleep(period);
    }
    
    pBehaviour->end();
    
    bON = false;
}

}


