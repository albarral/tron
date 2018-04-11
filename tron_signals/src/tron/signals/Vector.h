#ifndef __TRON_SIGNALS_VECTOR_H
#define __TRON_SIGNALS_VECTOR_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace tron
{
// Class used to manage 2D vectors.
class Vector
{
private:
    // parameter
    float angle;  // vector angle (degrees)
    // logic
    float cosA;   // cosinus(angle)
    float sinA;   // sinus(angle)
    float x;   // x component
    float y;   // y component
    
public:  
    Vector();
    //~Vector();

    float getAngle() {return angle;};
    float getX() {return x;}; 
    float getY() {return y;}; 

    // parameters
    void setAngle(float value);
    
    // update vector x & y components to the given magnitude value
    void updateMagnitude(float magnitude);
};
}
#endif
