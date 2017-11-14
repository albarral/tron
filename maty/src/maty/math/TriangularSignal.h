#ifndef __MATY_MATH_TRIANGULAR_SIGNAL_H
#define __MATY_MATH_TRIANGULAR_SIGNAL_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Click.h"

namespace maty
{
// Class that produces a periodic triangular signal between -1 and 1 at a requested frequency.
// On start the signal is reset to 0 & the periodic cycle started.
class TriangularSignal
{
private:
    // parameter
    float frequency;     // oscillation frequency (Hz))
    // logic
    float absSlope;     // absolute signal slope (1/ms)
    float slope;          // real signal slope (depends on the up/down cycle)
    float signal;     // the oscillating value [-1, 1]
    Click oClick;     // clock utility to measure times

public:
    TriangularSignal();

    // sets the oscillator frequency
    void setFrequency(float freq);
    float getFrequency() {return frequency;};
    
    // restarts the oscillator
    void start();
    // senses the signal (updating its value after the elapsed time)
    float sense();
    // gets the present signal value
    float getSignal() {return signal;}
        
};
}
#endif
