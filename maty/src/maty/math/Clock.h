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
// On reset the tics are set to 0 and timer is reset. On click the tics are updated according to the ellapsed time.
class Clock
{
private:
    // parameter
    int period;     // oscillation period (ms)
    // logic
    int tics;     // clock tics
    float t;      // advanced time in present period (ms)
    Click oClick;     // clock utility to measure times

public:
    Clock();

    // sets the clock period
    void setPeriod(int period);
    float getPeriod() {return period;};
    
    // resets the clock
    void reset();
    // updates the clock values (measuring the elapsed time)
    int update();
    // get tics value
    int getTics() {return tics;}
    // gets consumed fraction of present period
    float getPeriodFraction() {return (float)t/period;};
        
};
}
#endif
