/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cmath>

#include "maty/signals/SenoidalOscillator.h"
#include "maty/math/MathDefines.h"

namespace maty
{
SenoidalOscillator::SenoidalOscillator()
{    
    // internally it's a linear oscillator not symmetric with a 180 degrees span (PI radians)
    setSpan(PI);
    setSymmetry(false);
}


void SenoidalOscillator::reset()
{
    Oscillator::reset();
    value2 = 0.0;
}

void SenoidalOscillator::update()
{
    Oscillator::update();
    
    // compute angle sinus
    value2 = sin(value);
}

std::string SenoidalOscillator::toString()
{
    std::string text = "[SenoidalOscillator]: " + Oscillator::toString(); 
    return text;    
}

}