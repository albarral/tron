#ifndef __MATY_MOVES_CYCLICMOVE_H
#define __MATY_MOVES_CYCLICMOVE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace maty
{
// Class used to represent a cyclic movement. 
class CyclicMove
{
private:
    float freq;   // movement frequency (Hz)
    float angle;  // movement frontal angle (degrees)
    float amp;   // movement amplitude (degress)
    float phase;   // phase difference between both cyclic components
    
public:  
    CyclicMove();
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
