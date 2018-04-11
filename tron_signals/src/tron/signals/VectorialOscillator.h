#ifndef __TRON_SIGNALS_VECTORIAL_OSCILLATOR_H
#define __TRON_SIGNALS_VECTORIAL_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/signals/Oscillator.h"
#include "tron/signals/Vector.h"

namespace tron
{
// Class implementing a vectorial oscillator. 
// It internally works as a symmetric linear oscillator that evolves the magnitude of a 2D vector with a given angle. The x and y coordinates of the vector oscillate accordingly.
class VectorialOscillator : public Oscillator
{
private:
    float amplitude;        // vector maximum amplitude
    Vector o2DVector;     // oscillating vector
    
public:
    VectorialOscillator();
    //~VectorialOscillator();                

    void setAngle(float value);
    void setAmplitude(float value);
    float getAngle() {return o2DVector.getAngle();}; 
    float getAmplitude() {return amplitude;}; 

    virtual void reset(); 
    virtual void update();
    
    // get x & y outputs
    float getX() {return o2DVector.getX();}; 
    float getY() {return o2DVector.getY();}; 

    // get description
    virtual std::string toString();
};
}
#endif
