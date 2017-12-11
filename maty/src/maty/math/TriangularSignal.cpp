/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/TriangularSignal.h"

namespace maty
{
TriangularSignal::TriangularSignal()
{    
    // set 4 sectors signal
    setSectors(4);
    // set start positions of sectors
    y0[0] = 0.0;
    y0[1] = 1.0;
    y0[2] = 0.0;
    y0[3] = -1.0;
    
    signal = 0.0;
}

void TriangularSignal::setFrequency(float value)
{
    Signal::setFrequency(value);
    // recompute sector slopes
    if (value > 0.0)        
        computeSlopes();
}

void TriangularSignal::computeSlopes()
{
    // y = kx + yo
    // signal must change 1 in each period sector
    float k = 1.0;
    slope[0] = slope[3] = k;
    slope[1] = slope[2] = -k;    
}

void TriangularSignal::start(Clock& oClock)
{
    // reset signal
    reset(oClock);
    signal = 0.0;
}

float TriangularSignal::update(Clock& oClock)
{
    // sense base signal
    sense(oClock);
    // and compute triangular function
    // y = kx + yo
    // caution (protect against signals with initial negative phase)
    if (sector >= 0)
        signal = slope[sector]*completion + y0[sector];
    return signal;
}

std::string TriangularSignal::toString()
{
    std::string text = "[TriangularSignal]: "; 
    int numSectors = getSectors();
    for (int i=0; i<numSectors; i++)
    {
        text += "sector " + std::to_string(i) + ": slope = " + std::to_string(slope[i]) + ": yo = " + std::to_string(y0[i]) + "\n"; 
    }
    return text;    
}

}