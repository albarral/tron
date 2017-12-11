#ifndef __MATY_MATH_CLOCK_H
#define __MATY_MATH_CLOCK_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Click.h"

namespace maty
{
// Class that produces a clock signal (periodic signal of specified frequency which gives a tic every new period)
// On reset the tics are set to 0 and timer is reset. On click the tics are updated according to the elapsed time.
class Clock
{
private:
    // parameter
    float freq;
    // logic
    int period;     // oscillation period (ms)
    int tics;     // clock tics
    float t;      // advanced time in present period (ms)
    Click oClick;     // clock utility to measure times

public:
    Clock();

    // sets the clock period
    void setFrequency(float value);
    float getFrequency() {return freq;};
    
    // resets the clock
    void reset();
    // updates the clock values (measuring the elapsed time)
    int update();
    // get tics value
    int getTics() {return tics;}
    
    // get tics roof
    int getTicsRoof() {return 10000;};
        
};
}
#endif
