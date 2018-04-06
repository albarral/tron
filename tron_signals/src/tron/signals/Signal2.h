#ifndef __TRON_SIGNALS_SIGNAL2_H
#define __TRON_SIGNALS_SIGNAL2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/Click.h"

namespace tron
{
// Base class used to produce signals.
class Signal2
{
protected:
    int t;            // time (ms)
    int at;          // time elapsed since last update (ms)  
    float value;

private: 
    const int tmax = 1000;      // time limit 
    Click oClick;     // clock utility to measure times    

public:
    Signal2();

    float getValue() {return value;};
    virtual void reset(); 
    virtual void update();
};
}
#endif
