#ifndef __TRON_SIGNALS_CYCLIC_COMPONENT_H
#define __TRON_SIGNALS_CYCLIC_COMPONENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace tron
{
// Class used to represent a cyclic component.
class CyclicComponent
{
private:
    float freq;   // movement frequency (Hz)
    float angle;  // movement angle (degrees)
    float amp;   // movement amplitude (degrees)
    float phase;   // movement phase (degrees)
    
public:  
    CyclicComponent();
    //~CyclicComponent();
    
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
