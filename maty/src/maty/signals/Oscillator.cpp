/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/signals/Oscillator.h"

namespace maty
{
Oscillator::Oscillator()
{    
    freq = 1.0;    
    span = 10.0;
    bsymmetric = true;
    tune();
}

void Oscillator::setFrequency(float value)
{
    if (value >= 0.0)
    {
        freq = value;
        tune();
    }    
}

void Oscillator::setSpan(float value)
{
    if (value > 0)
    {
        span = value;
        tune();
    }            
}

void Oscillator::setSymmetry(bool value)
{
    bsymmetric = value;
    tune();
}

void Oscillator::tune()
{
    // the oscillator signal should walk the span twice in each period
    k = 2 * span * freq;
     // if symmetric oscillation, the signal range will be [span/2, span/2]
    if (bsymmetric)
    {
        float semi = 0.5*span;
        min = -semi;
        max = semi;
    }
    // otherwise the signal range will be [0, span]
    else
    {
        min = 0.0;
        max = span;
    }
}

void Oscillator::reset()
{
    // reset signal
    Signal2::reset();
    // and direction
    bup = true;
}

void Oscillator::update()
{
    // signal update
    Signal2::update();
    
    // compute signal change
    float dif = k*at;    
    float v0;
    // and apply change to signal (considering overflows)
    while (dif != 0.0)
    {
        v0 = value;
        // if positive direction, increase value
        if (bup)
        {
            value += dif;
            // if overflow: protect, change direction and compute remaining change
            if (value > max)
            {
                value = max;
                bup = !bup;
                dif -= max - v0;
            }
        }
        // if negative direction, decrease value
        else
        {
            value -= dif;
            // if overflow: protect, change direction and compute remaining change
            if (value < min)
            {
                value = min;
                bup = !bup;
                dif -= v0 - min;
            }            
        }        
    }
}

std::string Oscillator::toString()
{
    std::string text = "[Oscillator]: freq = " + std::to_string(freq) + ", span = " + std::to_string(span) + ", symmetric = " + std::to_string(bsymmetric) + "\n"; 
    return text;    
}

}