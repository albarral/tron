/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/signals/DualOscillator.h"

namespace maty
{
DualOscillator::DualOscillator()
{
    relFreq = 0.0;
    relFactor = 0.0;
    phaseGap = 0;
    x = y = 0.0;
}

void  DualOscillator::setMainFreq(float value)
{
    oOscillator1.setFrequency(value);
    // tune second oscillator to keep the frequency relation
    oOscillator2.setFrequency(relFreq*value);
}

void  DualOscillator::setMainAngle(float value)
{
    // oscillators are orthogonal
    oOscillator1.setAngle(value);
    // tune second oscillator to keep the orthogonal orientation relation
    oOscillator2.setAngle(value + 90);
}

void  DualOscillator::setMainAmp(float value)
{
    oOscillator1.setAmplitude(value);
    // tune second oscillator to keep the amplitude relation
    oOscillator2.setAmplitude(relFactor*value);
}

void  DualOscillator::setMainPhase(int value)
{
    oOscillator1.setPhase(value);
    // tune second oscillator to keep the phase relation
    oOscillator2.setPhase(value + phaseGap);
}

void  DualOscillator::setRelativeFreq(float value)
{
    if (value >= 0.0)
    {
        relFreq = value;
        oOscillator2.setFrequency(relFreq*oOscillator1.getFrequency());        
    }    
}

void  DualOscillator::setRelativeFactor(float value)
{
    if (value >= 0.0)
    {
        relFactor = value;
        oOscillator2.setAmplitude(relFactor*oOscillator1.getAmplitude());        
    }    
}

void  DualOscillator::setPhaseGap(int value)
{
    phaseGap = value;
    oOscillator2.setPhase(oOscillator1.getPhase() + phaseGap);        
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