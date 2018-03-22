#ifndef __MATY_MOVES_CYCLIC_COMPONENT_H
#define __MATY_MOVES_CYCLIC_COMPONENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace maty
{
// Class used to represent a cyclic component.
class CyclicComponent
{
private:
    float freq;   // movement frequency (Hz)
    float angle;  // movement angle (degrees)
    float amp;   // movement amplitude (degress)
    float phase;   // movement phase (degrees)
    
public:  
    CyclicComponent();
    //~CyclicMove();
    
    void setFreq(float value) {freq = value;}
    void setAngle(float value) {angle = value;}
    void setAmp(float value) {amp = value;}
    void setPhase(float value) {phase = value;}
    float getFreq() {return freq;}; 
    float getAngle() {return angle;}; 
    float getAmp() {return amp;}; 
    float getPhase() {return phase;};
};
}
#endif
