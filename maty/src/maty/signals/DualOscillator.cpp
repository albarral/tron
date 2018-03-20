/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/signals/DualOscillator.h"

namespace maty
{
DualOscillator::DualOscillator()
{
    x = y = 0.0;
}

void  DualOscillator::setPrimaryFreq(float value)
{
    oOscillator1.setFrequency(value);
}

void  DualOscillator::setPrimaryAngle(float value)
{
    oOscillator1.setAngle(value);
}

void  DualOscillator::setPrimaryAmp(float value)
{
    oOscillator1.setAmplitude(value);
}

void  DualOscillator::setPrimaryPhase(int value)
{
    oOscillator1.setPhase(value);
}

void  DualOscillator::setSecondaryFreq(float value)
{
    oOscillator2.setFrequency(value);
}

void  DualOscillator::setSecondaryAngle(float value)
{
    oOscillator2.setAngle(value);
}

void  DualOscillator::setSecondaryAmp(float value)
{
    oOscillator2.setAmplitude(value);
}

void  DualOscillator::setSecondaryPhase(int value)
{
    oOscillator2.setPhase(value);
}

void DualOscillator::reset()
{
    oOscillator1.reset();
    oOscillator2.reset();
    x = y = 0.0;
}
                    
void DualOscillator::update()
{
    oOscillator1.update();
    oOscillator2.update();
    // contributions of both oscillators
    x = oOscillator1.getX() + oOscillator2.getX();
    y = oOscillator1.getY() + oOscillator2.getY();
}

std::string DualOscillator::toString()
{
    std::string desc = "DualOscillator:[ primary: " + oOscillator1.toString() + "\nsecondary: " + oOscillator2.toString() + "]";                        
    return desc;
}

}