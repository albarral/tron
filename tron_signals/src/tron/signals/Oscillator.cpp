/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/signals/Oscillator.h"

namespace tron
{
Oscillator::Oscillator()
{    
    freq = 0.0;    
    span = 1.0;
    phase = 0.0;
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

void Oscillator::setPhase(int angle)
{
    // phase must be in [0, 360) range
    if (angle >= 0 && angle < 360)
    {
        phase = angle;
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
    k = 2.0 * span * freq * 0.001;
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
    
    // if phase defined
    if (phase != 0.0)
    {
        // advance the oscillator to the corresponding period position
        float dif = 2.0 * span * (float)phase/360.0;
        while (dif != 0.0)
            dif = advance(dif);
    }
}

void Oscillator::update()
{
    // signal update
    Signal2::update();
    
    // compute signal change
    float dif = k*at;    
    // and apply change to signal (considering overflows)
    while (dif != 0.0)
    {
        dif = advance(dif);
    }
}

float Oscillator::advance(float quantity)
{
    // if positive direction, increase value
    if (bup)
    {
        value += quantity;
        // if limit passed: compute excess, stay in limit and change direction
        if (value > max)
        {
            quantity = value - max;
            value = max;
            bup = !bup;
        }
        else 
            quantity = 0.0;
    }
    // if negative direction, decrease value
    else
    {
        value -= quantity;
        // if limit passed: compute excess, stay in limit and change direction
        if (value < min)
        {
            quantity = min - value;
            value = min;
            bup = !bup;
        }            
        else 
            quantity = 0.0;
    }               
    
    // return excess
    return quantity;
}

std::string Oscillator::toString()
{
    std::string text = "[Oscillator]: freq = " + std::to_string(freq) + ", span = " + std::to_string(span) + ", symmetric = " + std::to_string(bsymmetric) + "\n"; 
    return text;    
}

}