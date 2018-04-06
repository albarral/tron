/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/signals/VectorialOscillator.h"

namespace tron
{
VectorialOscillator::VectorialOscillator()
{
    // internally it's a symmetric linear oscillator with range [-1, 1]
    setSpan(2.0);
    setSymmetry(true);
    amplitude = 0.0;
}

void  VectorialOscillator::setAngle(float value)
{
    // reorient vector
    o2DVector.setAngle(value);
}

void  VectorialOscillator::setAmplitude(float value)
{
    if (value >= 0)
        amplitude = value;
}

void VectorialOscillator::reset()
{
    Oscillator::reset();
    o2DVector.updateMagnitude(0.0);    
}

void VectorialOscillator::update()
{
    Oscillator::update();
    
    // modulate the vector magnitude with the oscillator signal
    o2DVector.updateMagnitude(amplitude * value);
}

std::string VectorialOscillator::toString()
{
    std::string desc = "VectorialOscillator: [angle = " + std::to_string(o2DVector.getAngle()) + ", amplitude = " + std::to_string(amplitude) + " - " + Oscillator::toString() + "]";                        
    return desc;
}

}