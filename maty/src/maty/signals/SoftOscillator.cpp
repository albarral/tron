/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cmath>

#include "maty/signals/SoftOscillator.h"
#include "maty/math/MathDefines.h"

namespace maty
{
SoftOscillator::SoftOscillator()
{    
    // absolute oscillator from 0 to 360 degrees (2*PI radians)
    oOscillator.setSpan(2*PI);
    oOscillator.setSymmetry(false);
}

void SoftOscillator::setFrequency(float value)
{
    oOscillator.setFrequency(value);
}

void SoftOscillator::reset()
{
    // reset internal oscillator
    oOscillator.reset();
    output = 0.0;
}

void SoftOscillator::update()
{
    // update oscillator
    oOscillator.update();
    
    // compute angle sinus
    output = sin(oOscillator.getValue());
}

std::string SoftOscillator::toString()
{
    std::string text = "[SoftOscillator]: " + oOscillator.toString(); 
    return text;    
}

}