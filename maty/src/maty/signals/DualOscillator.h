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
// Class implementing a dual oscillator. It's composed of two orthogonal vectorial oscillators working synchronously.
// The x y output is the sum of both oscillators outputs.
class DualOscillator
{
private:
    // params for oscillators relation
    float relFreq;                 // relative frequency between oscillators (secondary = relative * primary)
    float relFactor;              // relative factor between oscillators amplitudes (secondary = relative * primary)
    int phaseGap;               // phase gap between oscillators (secondary = primary + gap)    
    // logic
    maty::VectorialOscillator oOscillator1;     // primary oscillator
    maty::VectorialOscillator oOscillator2;     // secondary oscillator
    float x; 
    float y;
    
public:
    DualOscillator();
    //~DualOscillator();                

    void setMainFreq(float value);
    void setMainAngle(float value);
    void setMainAmp(float value);
    void setMainPhase(int value);
    
    float getMainFreq() {oOscillator1.getFrequency();}; 
    float getMainAngle() {oOscillator1.getAngle();};
    float getMainAmp() {oOscillator1.getAmplitude();};
    int getMainPhase() {oOscillator1.getPhase();};

    void setRelativeFreq(float value);
    void setRelativeFactor(float value);
    void setPhaseGap(int value);
    
    float getRelativeFreq() {return relFreq;}; 
    float getRelativeFactor() {return relFactor;}; 
    int getPhaseGap() {return phaseGap;};
    
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
