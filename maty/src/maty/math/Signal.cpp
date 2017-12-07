/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Signal.h"

namespace maty
{
Signal::Signal()
{    
    freq = 1.0;    
    sectors = 1;
}

void Signal::tune(float freq, int sectors)
{
    if (freq > 0.0 && sectors > 0)
    {        
        this->freq = freq;
        this->sectors = sectors;
        // the signal will advance a sector on each clock period
        int period = 1000/(freq*sectors);
        oClock.setPeriod(period);
    }
}

void Signal::reset()
{
    // start signal
    sector = 0;
    completion = 0.0;
    oClock.reset();
    lastTic = 0;
}

int Signal::sense()
{
    // get clock tics
    int tic = oClock.update();
    // update sector completion
    completion = oClock.getPeriodFraction();
    
    // if new tic, change sector
    if (tic != lastTic)
    {
        // elapsed tics
        int tics = tic - lastTic;
        lastTic = tic;
        // protect against clock roof overstepping
        if (tics < 0)
            tics += oClock.getTicsRoof();
        
        // update sector and completion
        sector += tics;
        // watch sectors limit
        while (sector >= sectors)
            sector -= sectors;        
    }

    return sector;
}
}