/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/moves/CircularMovement.h"
#include "maty/math/Angle.h"

namespace maty
{
CircularMovement::CircularMovement()
{
    bdual = true;
}

//CircularMovement::~CircularMovement()
//{
//}

void CircularMovement::createCircle(float freq, float amplitude, float angle, bool brotation)
{
    // a circle is an ellipse with relative factor 1.0  ... 
    createEllipse(freq, amplitude, 1.0, angle, brotation);
}

void CircularMovement::createEllipse(float freq, float amplitude, float relFactor, float angle, bool brotation)
{
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
    
    computePhases(brotation, angle);
}

void CircularMovement::computePhases(bool brotation, float orientation)
{
    float xphase, yphase;
    // if positive rotation (anticlockwise)
    if (brotation)
    {
        xphase = orientation;
        // keep inside limits [0, 360)    
        yphase = xphase - 90.0;
        yphase = Angle::inLimits(yphase);        
    }
    // if negative rotation (clockwise)
    else
    {
        // keep inside limits [0, 360)    
        xphase = Angle::inLimits(-orientation);                
        // keep inside limits [0, 360)    
        yphase = Angle::inLimits(xphase + 90.0);                
    }
    oCyclicComponent1.setPhase(xphase);
    oCyclicComponent2.setPhase(yphase);
}
}
