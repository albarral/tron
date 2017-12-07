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
// The period is divided in a number of sectors and a clock is used to advance the sectors counter in a cyclic way (in analogy to electronic circuits).
// The signal is started on reset() call, and sensed on sense() calls.
class Signal
{
protected:
    // parameter
    float freq;     // oscillation frequency (Hz))
    int sectors;           // the sectors in which the signal's period is divided
    // logic
    int sector;         // the signal's present sector
    float completion;  // completion of present sector (values in [0,1])    
    Clock oClock;     // clock utility to measure tics
    int lastTic;         // last clock tic   
public:
    Signal();

    // get signal frequency
    float getFrequency() {return freq;};
    // get num sectors in signal
    int getSectors() {return sectors;};
    // get the present sector
    int getSector() {return sector;}
    // get the present sector completion
    float getCompletion() {return completion;};        
    
protected:    
    // sets the signal parameters
    void tune(float freq, int sectors);
    // reset signal (and internal clock)
    void reset();
    // senses the signal (updating its sector after the elapsed time)
    int sense();    
};
}
#endif
