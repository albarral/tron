/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cmath>

#include "amy/math/TriangularSignal.h"

namespace amy
{
TriangularSignal::TriangularSignal()
{    
    absSlope = slope = 0.0;
    signal = 0.0;
}

void TriangularSignal::setFrequency(float freq)
{
    if (freq > 0.0)
    {        
        // signal must go from 0 to 1 in a quarter of a period
        absSlope = 4.0*freq/1000; 
        // the slope changes but keeping its sign
        slope = (slope > 0 ? absSlope : -absSlope);
        frequency = freq;
    }
};

void TriangularSignal::start()
{
    // start new oscillation going up
    signal = 0.0;
    slope = absSlope;
    // and starts chronometer
    oClick.start();
}

float TriangularSignal::sense()
{
    // compute elapsed time 
    oClick.read();
    oClick.start();        
    // update signal 
    signal += slope * oClick.getMillis();
    
    // if signal arrives at 1 or -1, it must rebound back 
    if (fabs(signal) >= 1.0)
    {
        slope = -slope;
        // measure excess
        float excess = fabs(signal) - 1.0;
        
        // if excess is bigger than signal's amplitude transform it to direction changes
        while (excess > 2.0)
        {
            slope = -slope;
            excess -= 2.0;
        }
        // the signal excess is the rebound size
        if (slope > 0)
            signal = -1.0 + excess;
        else
            signal = 1.0 - excess;                            
    }
    return signal;
}
}