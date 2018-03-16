#ifndef __MATY_SIGNALS_VECTORIAL_OSCILLATOR_H
#define __MATY_SIGNALS_VECTORIAL_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "maty/signals/Oscillator.h"
#include "maty/math/Vector.h"

namespace maty
{
// Class implementing a vectorial oscillator. 
// It internally works as a symmetric linear oscillator that evolves the magnitude of a 2D vector with a given angle. The x and y coordinates of the vector oscillate accordingly.
class VectorialOscillator : public Oscillator
{
private:
    float amplitude;        // vector maximum amplitude
    maty::Vector o2DVector;
    
public:
    VectorialOscillator();
    //~VectorialOscillator();                

    void setAngle(float value);
    void setAmplitude(float value);
    float getAngle() {return o2DVector.getAngle();}; 
    float getAmplitude() {return amplitude;}; 

    virtual void reset(); 
    virtual void update();
    
    // get movement xy speeds
    float getXSpeed() {return o2DVector.getX();}; 
    float getYSpeed() {return o2DVector.getY();}; 

    // get description
    virtual std::string toString();
};
}
#endif
