/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/TriangularSignal.h"

namespace maty
{
TriangularSignal::TriangularSignal()
{    
    // tune 4 sectors signal
    tune(1.0, 4);
    // set start positions of sectors
    y0[0] = 0.0;
    y0[1] = 1.0;
    y0[2] = 0.0;
    y0[3] = -1.0;
    
    signal = 0.0;
}

void TriangularSignal::setFrequency(float freq)
{
    if (freq > 0.0)
    {                
        // tune 4 sectors signal with given frequency
        tune(freq, 4);
        // and recompute sector slopes
        computeSlopes();
    }
}

void TriangularSignal::computeSlopes()
{
    // y = kx + yo
    // signal must change 1 in each period sector
    float k = 1.0;
    slope[0] = slope[3] = k;
    slope[1] = slope[2] = -k;    
}

void TriangularSignal::start()
{
    // reset signal
    signal = 0.0;
    reset();
}

float TriangularSignal::update()
{
    // sense base signal
    sense();
    // and compute triangular function
    // y = kx + yo
    signal = slope[sector]*completion + y0[sector];
    return signal;
}

std::string TriangularSignal::toString()
{
    std::string text = "[TriangularSignal2]: "; 
    for (int i=0; i<sectors; i++)
    {
        text += "sector " + std::to_string(i) + ": slope = " + std::to_string(slope[i]) + ": yo = " + std::to_string(y0[i]) + "\n"; 
    }
    return text;    
}

}