#ifndef __AMY_MATH_LINEARCYCLER_H
#define __AMY_MATH_LINEARCYCLER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "amy/math/TriangularSignal.h"
#include "amy/math/Vector.h"

namespace amy
{
// Class used to perform cyclic linear movements.
// The class inputs are: the frequency, the movement amplitude and the orientation angle.
// A triangular signal is used to generate the cyclic movements.
// The output is a speed vector.
class LinearCycler
{
private:
    float freq;             // movement frequency (Hz))
    float angle;             // movement frequency (Hz))
    float amplitude;     // movement amplitude (degrees)
    float movSpeed;     // max speed for the movement (depends on amplitude & frequency)
    TriangularSignal oTriangularSignal;     // triangular signal used to achieve cyclic output
    // output
    Vector oSpeedVector;
    
public:
    LinearCycler();
    //~LinearCycler();                

    void setFreq(float value);
    void setAngle(float value);
    void setAmp(float value);
    float getFreq() {return freq;}; 
    float getAngle() {return angle;}; 
    float getAmp() {return amplitude;}; 

    // trigger the movement
    void trigger();
    // update the movement (perform it)
    void update();
    // get movement xy speeds
    float getXSpeed() {return oSpeedVector.getXComponent();}; 
    float getYSpeed() {return oSpeedVector.getYComponent();}; 
    
private:    
    // define movement's max speed
    void redefine();
};
}
#endif
