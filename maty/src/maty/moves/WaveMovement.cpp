/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/moves/WaveMovement.h"
#include "maty/math/Angle.h"

namespace maty
{
WaveMovement::WaveMovement()
{
}

//WaveMovement::~WaveMovement()
//{
//}

void WaveMovement::createLine(float freq, float amplitude, float angle)
{
    bdual = false;
    oCyclicComponent1.setFreq(freq);
    oCyclicComponent1.setAmp(amplitude);
    // orthogonal orientation
    angle = Angle::inLimits(angle);
    oCyclicComponent1.setAngle(angle);
}

void WaveMovement::createWave(float freq, float amplitude, float relFactor, float angle)
{
    bdual = true;
    // same freq
    oCyclicComponent1.setFreq(freq);
    oCyclicComponent2.setFreq(freq);
    // relative factor
    oCyclicComponent1.setAmp(amplitude);
    oCyclicComponent2.setAmp(amplitude * relFactor);
    // orthogonal orientation
    // keep inside limits [0, 360)    
    angle = Angle::inLimits(angle);
    float angle2 = Angle::inLimits(angle + 90.0);
    oCyclicComponent1.setAngle(angle);
    oCyclicComponent2.setAngle(angle2);
    
    // no phase difference
}

}
