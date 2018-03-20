#ifndef __MATY_SIGNALS_DUAL_OSCILLATOR_H
#define __MATY_SIGNALS_DUAL_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "maty/signals/VectorialOscillator.h"

namespace maty
{
// Class implementing a dual oscillator. It's composed of two vectorial oscillators working synchronously.
// The x y output is the sum of both oscillators outputs.
class DualOscillator
{
private:
    // logic
    maty::VectorialOscillator oOscillator1;     // primary oscillator
    maty::VectorialOscillator oOscillator2;     // secondary oscillator
    float x; 
    float y;
    
public:
    DualOscillator();
    //~DualOscillator();                

    void setPrimaryFreq(float value);
    void setPrimaryAngle(float value);
    void setPrimaryAmp(float value);
    void setPrimaryPhase(int value);
    
    float getPrimaryFreq() {return oOscillator1.getFrequency();}; 
    float getPrimaryAngle() {return oOscillator1.getAngle();};
    float getPrimaryAmp() {return oOscillator1.getAmplitude();};
    int getPrimaryPhase() {return oOscillator1.getPhase();};

    void setSecondaryFreq(float value);
    void setSecondaryAngle(float value);
    void setSecondaryAmp(float value);
    void setSecondaryPhase(int value);
    
    float getSecondaryFreq() {return oOscillator2.getFrequency();}; 
    float getSecondaryAngle() {return oOscillator2.getAngle();};
    float getSecondaryAmp() {return oOscillator2.getAmplitude();};
    int getSecondaryPhase() {return oOscillator2.getPhase();};

    float getX() {return x;}; 
    float getY() {return y;}; 

    // reset the dual oscillator
    void reset();
    // update output
    void update();
    
    // get description
    std::string toString();
};
}
#endif
