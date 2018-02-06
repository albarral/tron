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

    // returns analog angle difference for a cyclic angle 
    static float cyclicDifference(float angleDif);
    
    // Updates an angle average (float) with a new sample (int) causing the given new weight.
    static void updateAverage (float& average, const int& new_value, int new_weight);
    
    // Updates an angle average (float) with a new sample (float) causing the given new weight.
    static void updateAverage (float& average, const float& new_value, int new_weight);
    
    // Updates an angle average (float) with a new value (float) caused by a set of samples.
    static void updateWeightedAverage (float& average, const float& new_value, int new_samples, int new_weight);    
};
}
#endif
