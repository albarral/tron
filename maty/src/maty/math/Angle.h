#ifndef __MATY_MATH_ANGLE_H
#define __MATY_MATH_ANGLE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace maty
{
// Class used to treat angles.
class Angle
{    
public:  
    // return the equivalent of the given angle in the [0,360) range
    static float inLimits(float angle);
};
}
#endif