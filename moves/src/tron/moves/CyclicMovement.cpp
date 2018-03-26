/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/moves/CyclicMovement.h"
#include "maty/math/Angle.h"

namespace tron
{
CyclicMovement::CyclicMovement()
{
    bdual = false;
}

//CyclicMovement::~CyclicMovement()
//{
//}


void CyclicMovement::updateFreq(float freq)
{
    // if two components
    if (bdual)
    {
        if (oCyclicComponent1.getFreq() != 0.0 && oCyclicComponent2.getFreq() != 0.0)
        {
            // keep relative frequency
            float relFreq = oCyclicComponent2.getFreq() / oCyclicComponent1.getFreq();
            oCyclicComponent1.setFreq(freq);
            oCyclicComponent2.setFreq(freq * relFreq);
        }
    }
    else          
        oCyclicComponent1.setFreq(freq);
}

void CyclicMovement::updateAmplitude(float amplitude)
{
    // if two components
    if (bdual)
    {
        if (oCyclicComponent1.getAmp() != 0.0 && oCyclicComponent2.getAmp() != 0.0)
        {
            // keep relative factor
            float relFactor = oCyclicComponent2.getAmp() / oCyclicComponent1.getAmp();
            oCyclicComponent1.setAmp(amplitude);
            oCyclicComponent2.setAmp(amplitude * relFactor);
        }
    }
    else
        oCyclicComponent1.setAmp(amplitude);
}

void CyclicMovement::updateAngle(float angle)
{
    // if two components
    if (bdual)
    {
        // keep relative angle
        float relAngle = oCyclicComponent2.getAngle() - oCyclicComponent1.getAngle();
        oCyclicComponent1.setAngle(angle);
        // keep angles inside limits [0, 360)    
        float angle2 = maty::Angle::inLimits(angle + relAngle);
        oCyclicComponent2.setAngle(angle2);       
    }
    else        
        oCyclicComponent1.setAngle(angle);
}

void CyclicMovement::updateRelFactor(float factor)
{
    // if two components
    if (bdual)
        oCyclicComponent2.setAmp(oCyclicComponent1.getAmp() * factor);
}
}
