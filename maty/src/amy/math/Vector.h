#ifndef __AMY_MATH_VECTOR_H
#define __AMY_MATH_VECTOR_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace amy
{
// Class used to manage 2D vectors.
class Vector
{
private:
    float angle;  // vector angle (degrees)
    float cosA;   // cosinus(angle)
    float sinA;   // sinus(angle)
    // components
    float x;   // x component
    float y;   // y component
    
public:  
    Vector();
    //~Vector();

    // parameters
    void setAngle(float value);
    // compute the vector components for the given magnitude value (keeping vector's angle)
    void compute(float magnitude);

    // read vector components
    float getXComponent() {return x;}; 
    float getYComponent() {return y;}; 
};
}
#endif
