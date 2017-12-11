#ifndef __MATY_MATH_TRIANGULAR_SIGNAL2_H
#define __MATY_MATH_TRIANGULAR_SIGNAL2_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "maty/math/Signal.h"

namespace maty
{
// Class that produces a periodic triangular signal between -1 and 1 at a given frequency.
// It's a Signal with 4 sectors, each with a specific function:
// sector 0: positive slope, yo = 0
// sector 1: negative slope, yo = 1
// sector 2: negative slope, yo = 0
// sector 3: positive slope, yo = -1
class TriangularSignal : public Signal
{
private:
    // logic        
    float slope[4];   // signal slopes in each sector
    float y0[4];       // signal start position (yo) in each sector
    float signal;     // the oscillating value [-1, 1]

public:
    TriangularSignal();

    // sets the signal frequency
    virtual void setFrequency(float value);
    
    // starts the signal
    void start(Clock& oClock);
    // updates the signal (senses evolved signal and returns its value)
    float update(Clock& oClock);
    // gets the present signal value
    float getSignal() {return signal;}

    std::string toString();
private:
    // computes the signal's slopes
    void computeSlopes();
};
}
#endif
