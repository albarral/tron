/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "tuly/control/module3.h"


namespace tuly
{
// Constructor
Module3::Module3 ()
{    
    modName = "module3";
    bON = false;
    prevState = state = Module3::state_UNKNOWN;
    boffRequested = false;
    level = -1;
    setFrequency(0.1);  // low default frequency
}

void Module3::on()
{
    // only launch thread if in OFF state
    if (!bON)
    {
      t = std::thread(&Module3::run, this);              
    }           
}

void Module3::off()
{        
    std::lock_guard<std::mutex> locker(mutex);
    boffRequested = true;
}

bool Module3::offRequested()
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

void Module3::wait()
{
    t.join();
}

bool Module3::isOn()
{
    return bON;
}

void Module3::setFrequency(float cps)
{
    std::lock_guard<std::mutex> locker(mutex);
    if (cps > 0.0)
    {
        period = 1000000/cps;    // in microseconds
        frequency = cps;
    }
}

float Module3::getFrequency()
{
    std::lock_guard<std::mutex> locker(mutex);
    return frequency;        
}

void Module3::run ()
{    
    bON = true; 
    first();
    while (!offRequested())
    {
        preLoop();
        loop();
        postLoop();
        
        usleep(period);
    }
    bON = false;
}


int Module3::getState()
{
    std::lock_guard<std::mutex> locker(mutex);
    return (state);        
}

int Module3::getPrevState()
{
    std::lock_guard<std::mutex> locker(mutex);
    return (prevState);        
}

void Module3::setState(int state)
{
    std::lock_guard<std::mutex> locker(mutex);
    this->state = state;    
    bstateChanged = (state != prevState);        
}

void Module3::preLoop()
{
    std::lock_guard<std::mutex> locker(mutex);
    // store prev state
    prevState = state;
}

void Module3::postLoop()
{
    std::lock_guard<std::mutex> locker(mutex);
    // reset changed flag if no changes in last loop
    if (bstateChanged && (state == prevState))
        bstateChanged = false;
}

bool Module3::isStateChanged()
{
    std::lock_guard<std::mutex> locker(mutex);
    return bstateChanged;        
}

}


