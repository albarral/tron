#ifndef __MATY_MATH_SIGNAL_H
#define __MATY_MATH_SIGNAL_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Clock.h"

namespace maty
{
// Base class used to produce periodic signals of specified frequency.     
// The signal is based in an angle [0, 360] which evolves through time, given by an external clock.
// The signal period is divided in sectors to allow for piecewise functions definition.
// The signal is started on reset() call, and sensed on sense() calls.
class Signal
{
private:
    // parameters
    float freq;     // oscillation frequency (Hz))
    float clockFreq;     // clock frequency (Hz))
    int sectors;           // the sectors in which the signal period is divided
    int phase;      // signal phase (degrees)
    // logic
    float angle;        // evolving angle [0, 360) (degrees)
    float angle4tic;   // angle evolved in a clock's tic
    float angle4sector; // angle evolved in a sector
    int lastTic;         // last clock tic   

protected:
    // logic
    int sector;         // the signal's present sector
    float completion;  // completion of present sector (values in [0,1])    

public:
    Signal();

    float getFrequency() {return freq;};
    int getSectors() {return sectors;};
    int getPhase() {return phase;};
    
    virtual void setFrequency(float value);
    void setSectors(int value);
    void setPhase(int value);
    
protected:    
    // recompute signal factors
    void tune();
    // reset signal values
    void reset(Clock& oClock);
    // senses the signal (updating its sector after the elapsed time)
    int sense(Clock& oClock);    
};
}
#endif
