/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cmath>

#include "amy/math/Vector.h"
#include "amy/math/MathDefines.h"

namespace amy
{
Vector::Vector()
{
    angle = 0.0;
    cosA = 1.0;
    sinA = 0.0;
    x = y = 0.0;
}

void Vector::setAngle(float value)
{
    // convert to radians
    angle = value;
    float radians = angle * KPI_DIV_180;
    sinA = sin(radians);
    cosA = cos(radians);    
}

void Vector::compute(float magnitude)
{
    // x = A cos(a)
    // v = A sin(a);
    x = magnitude*cosA;    
    y = magnitude*sinA;  
}
}
