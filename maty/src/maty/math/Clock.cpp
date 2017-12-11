/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Clock.h"

namespace maty
{
Clock::Clock()
{    
    setFrequency(10.0); // default frequency 10Hz
    tics = 0;
}

void Clock::setFrequency(float value)
{
    if (value >= 0.0)
    {
        freq = value;
        period = 1000.0/freq;
    }
}

void Clock::reset()
{
    // reset clock values
    tics = 0;
    t = 0.0;
    // and start chronometer
    oClick.start();
}

int Clock::update()
{
    // compute elapsed time 
    oClick.read();
    oClick.start();        
    // update advanced time
    t += oClick.getMillis();

    // on each elapsed period a new tic is generated (use while for long update cases)
    while (t >= period)
    {
        t -= period;
        tics++;
        
        // a roof is set to tics counter (overflow protection)
        if (tics == 10000)
            tics = 0;
    }
    
    return tics;
}
}