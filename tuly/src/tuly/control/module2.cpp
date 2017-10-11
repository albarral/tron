/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "tuly/control/module2.h"


namespace tuly
{
// Constructor
Module2::Module2 ()
{    
    state = Module2::state_OFF;
    setFrequency(0.1);  // low default frequency
}

void Module2::on()
{
    if (getState() == Module2::state_OFF)
    {      
      setState(Module2::state_ON);
      t = std::thread(&Module2::run, this);              
    }           
}

void Module2::off()
{        
    setNextState(Module2::state_OFF);
}

void Module2::wait()
{
    t.join();
}

bool Module2::isOn()
{
    return (getState() != Module2::state_OFF);        
}

void Module2::setFrequency(float cps)
{
    std::lock_guard<std::mutex> locker(mutex);
    if (cps > 0.0)
    {
        period = 1000000/cps;    // in microseconds
        frequency = cps;
    }
}

float Module2::getFrequency()
{
    std::lock_guard<std::mutex> locker(mutex);
    return frequency;        
}

void Module2::run ()
{
    first();
    while (!offRequested())
    {
        loop();
        usleep(period);
    }
    
    // final state OFF
    setState(Module2::state_OFF);
}

bool Module2::offRequested()
{
    return (getNextState() == Module2::state_OFF);        
}

int Module2::getState()
{
    std::lock_guard<std::mutex> locker(mutex);
    return (state);        
}

void Module2::setState(int state)
{
    std::lock_guard<std::mutex> locker(mutex);
    this->state = state;    
}

int Module2::getNextState()
{
    std::lock_guard<std::mutex> locker(mutex);
    return (nextState);        
}

void Module2::setNextState(int state)
{
    std::lock_guard<std::mutex> locker(mutex);
    // if OFF is already set, the change is ignored
    if (this->nextState != Module2::state_OFF);                
        this->nextState = state;    
}

// restricted to be used just here
void Module2::forceNextState(int state) 
{
    std::lock_guard<std::mutex> locker(mutex);
    this->nextState = state;    
}

bool Module2::updateState()
{
    std::lock_guard<std::mutex> locker(mutex);
    if (state != nextState)
    {
        state = nextState;    
        return true;
    }
    else
        return false;
}


}


